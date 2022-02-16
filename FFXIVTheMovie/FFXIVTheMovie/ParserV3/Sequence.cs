using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    public class Sequence : IComparable<Sequence>
    {
        public int SeqNumber;
        public List<EventEntry> EntryList = new List<EventEntry>();
        public bool Ignore = false;
        public bool MarkForAlternativeQuestComplete = false;

        public Sequence(int seq)
        {
            this.SeqNumber = seq;
        }

        public bool ContainsSceneElement(LuaScene.SceneElement element)
        {
            foreach (var entry in EntryList)
            {
                if (entry.EntryScene.ContainsSceneElement(element))
                    return true;
            }
            return false;
        }

        public bool ShouldGiveEventItemAtSeqUpdate()
        {
            foreach (var entry in EntryList)
            {
                foreach (var scene in entry.EntryScene.SceneList)
                {
                    if (scene.Type == LuaScene.SceneType.NpcTrade)
                        return true;
                    if ((scene.Element & LuaScene.SceneElement.Inventory) > 0)
                        return true;
                }
            }
            return false;
        }

        public override string ToString()
        {
            return $"Seq{SeqNumber}: {EntryList.Count}";
        }

        int IComparable<Sequence>.CompareTo(Sequence other)
        {
            return this.SeqNumber.CompareTo(other.SeqNumber);
        }

        public class EventEntry
        {
            public Sequence Owner;
            public ActiveEventObject TargetObject;
            public QuestVar Var;
            public QuestFlag Flag;
            public SceneGroup EntryScene = new SceneGroup();
            public int AssignedGroupCount = 0;
            public int RequiredGroupCount = 1;
            public bool ConditionBranch = false;
            public int? EmoteBranch = null;
            public bool ChatSayBranch = false;
            public string bNpcHackCreditDest = null;

            public bool InventoryBranch = false;

            public bool CanExistWithoutScene
            {
                get
                {
                    if (this.TargetObject != null)
                        return this.TargetObject.CanExistWithoutScene && this.RequiredGroupCount <= 1;
                    return this.RequiredGroupCount <= 1;
                }
            }

            public bool ShouldCheckSeqProgress()
            {
                if (Var != null)
                    return true;
                if (this.EntryScene.ContainsSceneElement(LuaScene.SceneElement.QuestAccept))
                    return true;
                if (TargetObject is ActiveActor)
                    return false;
                return true;
            }

            public bool CanAddSceneGroup(SceneGroup group)
            {
                if (!EntryScene.IsIdentityCompatible(group.Identity))
                {
                    return false;
                }

                if (EntryScene.Identity != "unknown" && EntryScene.Identity == group.Identity) // assume one id can only exist as a single entity in one seq
                    return true;

                if (TargetObject is ActiveActor && EntryScene.SceneList.Count == 0 && group.ContainsSceneType(LuaScene.SceneType.Snipe))
                {
                    return false;
                }

                if (TargetObject is ActiveActor && EntryScene.HasValidElement() && !EntryScene.ContainsSceneElement(LuaScene.SceneElement.TargetCanMove) && group.ContainsSceneElement(LuaScene.SceneElement.TargetCanMove))
                {
                    return false;
                }

                if (group.ContainsSceneElement(LuaScene.SceneElement.QuestOffer) || group.ContainsSceneElement(LuaScene.SceneElement.QuestAccept))
                {
                    if (this.Owner.SeqNumber != 0)
                        return false;
                }

                if (group.ContainsSceneElement(LuaScene.SceneElement.QuestReward) || group.ContainsSceneElement(LuaScene.SceneElement.QuestComplete))
                {
                    if (this.Owner.SeqNumber != 255)
                        return false;
                    if (this != this.Owner.EntryList[0] && this.Owner.EntryList[0].EntryScene.SceneList.Count < 3)
                    {
                        if (!this.Owner.MarkForAlternativeQuestComplete)
                            return false;
                    }
                }

                if (TargetObject == null)
                    return EntryScene.SceneList.Count < 3;

                if (!group.HasSubScenes && group.SceneList[0].Element == LuaScene.SceneElement.CutScene && this.Owner.SeqNumber == 0 && this != this.Owner.EntryList[0])
                {
                    if (this.Owner.EntryList[0].EntryScene.SceneList.Count < 3)
                        return false;
                }

                if (!this.TargetObject.CanAssignSceneGroup(group))
                    return false;
                if (EntryScene.SceneList.Count == 0)
                    return true;

                if (TargetObject is ActiveTerritory)
                    return EntryScene.SceneList.Count < 1;
                
                var s = EntryScene.SceneList[EntryScene.SceneList.Count - 1];
                //if (((s.Element & LuaScene.SceneElement.PopBNpc) > 0 || (s.Element & LuaScene.SceneElement.CutScene) > 0 || (s.Element & LuaScene.SceneElement.FadeIn) > 0) && ((group.SceneList[0].Element & LuaScene.SceneElement.TargetCanMove) > 0 && (group.SceneList[0].Element & LuaScene.SceneElement.FadeIn) == 0))
                //    return false;

                if ((s.Element & LuaScene.SceneElement.CutScene) > 0)
                {
                    if (group.SceneList.Count == 1 && ((group.SceneList[0].Element & LuaScene.SceneElement.QuestComplete) > 0))
                        return true;
                }
                
                if (this.Var == null)
                {
                    if (group.SceneList.Count == 1 && EntryScene.SceneList.Count == 2 && group.SceneList[0].Element != LuaScene.SceneElement.None && !group.ContainsSceneElement(LuaScene.SceneElement.CutScene))
                    {
                        return this.EntryScene.Identity != "unknown" && this.EntryScene.Identity == group.Identity;
                    }
                }/*
                else
                {
                    if (group.SceneList.Count == 1 && EntryScene.SceneList.Count == 2)
                    {
                        if((group.SceneList[0].Element & LuaScene.SceneElement.CutScene) != 0)
                            return false;
                    }
                }
                */
                return EntryScene.SceneList.Count + group.SceneList.Count <= 3;
            }

            public override string ToString()
            {
                return $"SEQ_{Owner.SeqNumber}: {TargetObject}, {(Var != null ? Var.ToString() : "<No Var>")}, {(Flag != null ? Flag.ToString() : "<No Flag>")}{((ConditionBranch || EmoteBranch.HasValue) ? ", Branch" : "")}, {EntryScene}";
            }

            public string ToSimpleString()
            {
                return $"SEQ_{Owner.SeqNumber}: {TargetObject}, {(Var != null ? Var.ToString() : "<No Var>")}, {(Flag != null ? Flag.ToString() : "<No Flag>")}{((ConditionBranch || EmoteBranch.HasValue) ? ", Branch" : "")}";
            }

            public bool IsPrefferedGroup(SceneGroup sceneGroup)
            {
                if (this.TargetObject != null)
                {
                    if (this.TargetObject.IsPrefferedGroup(sceneGroup))
                        return true;
                }
                if (EntryScene.SceneList.Count == 1 && !sceneGroup.HasSubScenes && sceneGroup.SceneList[0].Element == LuaScene.SceneElement.CutScene)
                {
                    return true;
                }
                if (EntryScene.SceneList.Count == 1 && EntryScene.SceneList[0].Element == LuaScene.SceneElement.Inventory)
                {
                    return true;
                }
                if (EntryScene.SceneList.Count > 0 && EntryScene.SceneList.Count < 3)
                {
                    var s = EntryScene.SceneList[EntryScene.SceneList.Count - 1];
                    if (s.Element == LuaScene.SceneElement.None && (sceneGroup.ContainsSceneElement(LuaScene.SceneElement.Message) || sceneGroup.ContainsSceneElement(LuaScene.SceneElement.SystemTalk)))
                    {
                        return true;
                    }
                    if (s.Element == LuaScene.SceneElement.CutScene && sceneGroup.SceneList[0].Element == (LuaScene.SceneElement.FadeIn | LuaScene.SceneElement.QuestReward | LuaScene.SceneElement.QuestComplete))
                    {
                        return true;
                    }
                }
                if (this.Owner.SeqNumber == 255 && this.Owner.EntryList[0] == this && (sceneGroup.ContainsSceneElement(LuaScene.SceneElement.QuestReward) || sceneGroup.ContainsSceneElement(LuaScene.SceneElement.QuestComplete)))
                {
                    return true;
                }
                return this.Var != null && this.EntryScene.Identity != "unknown" && this.EntryScene.Identity == sceneGroup.Identity;
            }
        }

        public class SceneGroup : IComparable<SceneGroup>
        {
            public bool HasSubScenes => this.SceneList.Count > 1;
            public List<LuaScene> SceneList = new List<LuaScene>();

            public bool ContainsSceneType(LuaScene.SceneType type)
            {
                foreach (var scene in SceneList)
                {
                    if (scene.Type == type)
                        return true;
                }
                return false;
            }
            public bool ContainsSceneElement(LuaScene.SceneElement element)
            {
                foreach (var scene in SceneList)
                {
                    if ((scene.Element & element) == element)
                        return true;
                }
                return false;
            }
            public bool ContainsSceneElementInAllScenes(LuaScene.SceneElement element)
            {
                foreach (var scene in SceneList)
                {
                    if ((scene.Element & element) != element)
                        return false;
                }
                return true;
            }
            public string Identity
            {
                get
                {
                    if (SceneList.Count == 0)
                        return "unknown";
                    var result = SceneList[0].Identity;
                    for (int i = 1; i < SceneList.Count; i++)
                    {
                        var s = SceneList[i];
                        if (s.Identity != "unknown")
                        {
                            if (result == "unknown")
                                result = s.Identity;
                            else if (result != s.Identity)
                                throw new Exception("wtf");
                        }
                    }
                    return result;
                }
            }

            public bool IsIdentityCompatible(string id)
            {
                var t = this.Identity;
                return id == "unknown" || t == "unknown" || t == id;
            }

            public bool HasValidElement()
            {
                foreach (var scene in SceneList)
                {
                    if (scene.Element != LuaScene.SceneElement.None)
                        return true;
                }
                return false;
            }

            public override string ToString()
            {
                if (SceneList.Count == 0)
                    return "[EMPTY]";
                return $"[{Identity}]{SceneList[0]}{(HasSubScenes ? $" +{SceneList.Count - 1}" : "")}";
            }

            int IComparable<SceneGroup>.CompareTo(SceneGroup other)
            {
                return this.SceneList[0].SceneNumber.CompareTo(other.SceneList[0].SceneNumber);
            }
        }

        public class QuestVar
        {
            public string Name;
            public int Value;
            public int? TodoIndex = null;

            public bool ForceSetValue;

            public string ToCppExprConditionNotDone()
            {
                return Name != null ? $"quest.get{Name}() != {Value}" : "true";
            }

            public string ToCppExprConditionDone()
            {
                return Name != null ? $"quest.get{Name}() == {Value}" : "true";
            }

            public string ToCppExprOperation()
            {
                StringBuilder builder = new StringBuilder();
                builder.Append($"quest.set{Name}( ");
                if (ForceSetValue || Value == 1)
                {
                    builder.Append($"{Value}");
                }
                else
                {
                    builder.Append($"quest.get{Name}() + 1");
                }
                builder.Append(" )");
                return builder.ToString();
            }

            public string ToCppExprClear()
            {
                return Name != null ? $"quest.set{Name}( 0 )" : "";
            }

            public string ToCppEventNotice()
            {
                if (!TodoIndex.HasValue)
                    throw new Exception("[QuestVar]Trying to generate event notice on a var that is not a todo item.");
                return $"eventMgr().sendEventNotice( player, getId(), {TodoIndex}, {(Value > 1 ? "2" : "0")}, {(Value > 1 ? $"quest.get{Name}()" : "0")}, {(Value > 1 ? Value.ToString() : "0")} )";
            }

            public override string ToString()
            {
                return $"{Name} = {Value}{(TodoIndex.HasValue ? $"(Todo:{TodoIndex})" : "")}";
            }
        }

        public class QuestFlag
        {
            public string Flag;
            public int Index;
            public bool TargetValue;

            public string ToCppExprConditionNotDone()
            {
                return $"{(TargetValue ? "!" : "")}quest.getBitFlag{Flag}( {Index} )";
            }

            public string ToCppExprSet()
            {
                return $"quest.setBitFlag{Flag}( {Index}, {TargetValue.ToString().ToLower()} )";
            }

            public string ToCppExprClear()
            {
                return $"quest.setBitFlag{Flag}( {Index}, {(!TargetValue).ToString().ToLower()} )";
            }

            public override string ToString()
            {
                return $"Flag{Flag}({Index})={TargetValue}";
            }
        }
    }
}
