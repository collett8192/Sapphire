using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    public class LuaIsAnnounce
    {
        public Dictionary<int, List<ActiveObjectToEntryConditionMap>> SeqTargetConditionTable = new Dictionary<int, List<ActiveObjectToEntryConditionMap>>();
        public bool IsFake = false;

        public static LuaIsAnnounce ParseLuaCode(List<string> codeBlock)
        {
            LuaIsAnnounce result = new LuaIsAnnounce();
            if (codeBlock.Count > 0)
            {
                var argList = codeBlock[0].ExtractFuncArgsFromLuaFuncDef();
                if (argList.Count != 5)
                    throw new Exception($"[LuaIsAnnounce]Invalid arg list.");
                int i = 1;
                int currentSeq = -1;
                string varFramework = argList[0], varPlayer = argList[1], varTarget = argList[3], varTarget2 = argList[4];
                List<ActiveObjectToEntryConditionMap> currentList = null;
                while (i < codeBlock.Count)
                {
                    var s = codeBlock[i];
                    if (s.IndexOf($" == {varFramework}.SEQ_") > 0)
                    {
                        if (currentSeq >= 0 && currentList.Count > 0)
                        {
                            result.SeqTargetConditionTable.Add(currentSeq, currentList);
                        }
                        bool oneLineFlag = s.Contains(" and ");
                        if (oneLineFlag)
                            Console.WriteLine($"[LuaIsAnnounce]parsing seq and target in one line not implemented");
                        var seqStr = s.GetStringBetween($" == {varFramework}.SEQ_", oneLineFlag ? " and" : " then");
                        currentSeq = seqStr == "FINISH" ? 255 : int.Parse(seqStr);
                        currentList = new List<ActiveObjectToEntryConditionMap>();
                    }
                    else if (s.IndexOf($"if {varTarget} == {varFramework}.") >= 0 || s.IndexOf($" == {varFramework}.ENEMY") >= 0)
                    {
                        var name = s.GetStringBetween($"{varFramework}.", " then");
                        i++;
                        if (name.Contains("PLAYER"))
                            continue;
                        if (name.StartsWith("EVENTRANGE"))
                        {
                            currentList.Add(new ActiveObjectToEntryConditionMap() { ActiveObject = ActiveEventObject.CreateActiveObjectByName(name) });
                            continue;
                        }
                        var s2 = codeBlock[i];
                        if (s2.StartsWith("return true") || s2.StartsWith("return false"))
                        {
                            currentList.Add(new ActiveObjectToEntryConditionMap() { ActiveObject = ActiveEventObject.CreateActiveObjectByName(name) });
                        }
                        else if (s2.StartsWith("return ") && s2.IndexOf("GetQuestBitFlag") > 0)
                        {
                            currentList.Add(new ActiveObjectToEntryConditionMap() { ActiveObject = ActiveEventObject.CreateActiveObjectByName(name) });
                        }
                        else if (s2.StartsWith("return ") && s2.IndexOf("GetNumOfItems") > 0)
                        {
                            currentList.Add(new ActiveObjectToEntryConditionMap() { ActiveObject = ActiveEventObject.CreateActiveObjectByName(name)/*, ItemChecker = true*/ });
                        }
                        else if (s2.StartsWith("return ") && s2.IndexOf("GetQuestUI") > 0)
                        {
                            var questVar = s2.GetStringBetween($"{varPlayer}:GetQuest", "(");
                            var valueStr = s2.GetStringBetween("return ", " <");
                            int value;
                            if (valueStr == null || !int.TryParse(valueStr, out value))
                                valueStr = s2.GetStringBetween("return ", " >");
                            if (valueStr == null || !int.TryParse(valueStr, out value))
                                valueStr = s2.GetStringBetween(" < ", null);
                            if (valueStr == null || !int.TryParse(valueStr, out value))
                                valueStr = s2.GetStringBetween(" > ", null);
                            if (valueStr == null || !int.TryParse(valueStr, out value))
                                throw new Exception($"[LuaIsAnnounce]CHECK SCRIPT!!!");
                            currentList.Add(new ActiveObjectToEntryConditionMap() { QuestVar = questVar, ConditionValue = value, ActiveObject = ActiveEventObject.CreateActiveObjectByName(name) });
                        }
                        else if (s2.StartsWith("L"))
                        {
                            var questVar = s2.GetStringBetween($"{varPlayer}:GetQuest", "(");
                            i++;
                            var s3 = codeBlock[i];
                            if (codeBlock[i + 1] != "return false")
                                throw new Exception($"[LuaIsAnnounce]CHECK SCRIPT!!!");
                            var valueStr = s3.GetStringBetween("if ", " <=");
                            if (valueStr == null)
                                valueStr = s3.GetStringBetween(">= ", " then");
                            if (valueStr == null)
                                throw new Exception($"[LuaIsAnnounce]CHECK SCRIPT!!!");
                            var value = int.Parse(valueStr);
                            currentList.Add(new ActiveObjectToEntryConditionMap() { QuestVar = questVar, ConditionValue = value, ActiveObject = ActiveEventObject.CreateActiveObjectByName(name) });
                        }
                        else
                        {
                            if (!codeBlock[i + 1].StartsWith("return false"))
                                throw new Exception($"[LuaIsAnnounce]CHECK SCRIPT!!!");
                            var valueStr = s2.GetStringBetween("if ", " <=");
                            if (valueStr == null)
                                valueStr = s2.GetStringBetween(">= ", " then");
                            if (valueStr == null)
                                throw new Exception($"[LuaIsAnnounce]CHECK SCRIPT!!!");
                            var value = int.Parse(valueStr);
                            var questVar = s2.GetStringBetween($"{varPlayer}:GetQuest", "(");
                            currentList.Add(new ActiveObjectToEntryConditionMap() { QuestVar = questVar, ConditionValue = value, ActiveObject = ActiveEventObject.CreateActiveObjectByName(name) });
                        }
                    }
                    else if (s.IndexOf($"if {varTarget2} == {varFramework}.") >= 0)
                    {
                        var name = s.GetStringBetween($"{varFramework}.", " then");
                        i++;
                        if (name.Contains("PLAYER"))
                            continue;
                        if (name.StartsWith("EVENTRANGE"))
                        {
                            currentList.Add(new ActiveObjectToEntryConditionMap() { ActiveObject = ActiveEventObject.CreateActiveObjectByName(name) });
                            continue;
                        }
                        var s2 = codeBlock[i];
                        if (s2.StartsWith("return "))
                        {
                            var valueStr = s2.GetStringBetween("return ", " > ");
                            if (valueStr != null)
                            {
                                var value = int.Parse(valueStr);
                                var questVar = s2.GetStringBetween($"{varPlayer}:GetQuest", "(");
                                currentList.Add(new ActiveObjectToEntryConditionMap() { QuestVar = questVar, ConditionValue = value, ActiveObject = ActiveEventObject.CreateActiveObjectByName(name) });
                            }
                            else
                            {
                                if (s2 == "return true")
                                {
                                    currentList.Add(new ActiveObjectToEntryConditionMap() { ActiveObject = ActiveEventObject.CreateActiveObjectByName(name) });
                                }
                            }
                        }
                    }
                    i++;
                }
                if (currentSeq >= 0 && currentList.Count > 0)
                {
                    result.SeqTargetConditionTable.Add(currentSeq, currentList);
                }
            }
            return result;
        }

        public static LuaIsAnnounce CreateFakeAnnounce(List<Sequence> seqList)
        {
            LuaIsAnnounce result = new LuaIsAnnounce();
            result.IsFake = true;
            return result;
        }

        public class ActiveObjectToEntryConditionMap
        {
            public ActiveEventObject ActiveObject;
            public string QuestVar;
            public int ConditionValue;
            public override string ToString()
            {
                return $"{ActiveObject}{(QuestVar != null ? $":{QuestVar}, {ConditionValue}" : "")}";
            }
        }

        private LuaIsAnnounce() { }
    }
}
