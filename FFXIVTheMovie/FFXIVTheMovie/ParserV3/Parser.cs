using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    using static FFXIVTheMovie.ParserV3.Sequence;
    public class Parser
    {
        public static readonly bool CppOutputExtraInfo = false;

        string questId;
        string outputFolder;
        List<string> inputCpp;
        List<string> inputLua;
        bool useBranchGlobal = false;
        Dictionary<string, int> privateInstanceEntranceTable;
        Dictionary<string, Tuple<int, float, float, float, float, string>> warpTable;
        Dictionary<string, int> mountTable;
        Dictionary<string, long> unmappedObjTable;
        bool allowEmptyEntry = false;

        Dictionary<string, string> paramTable = new Dictionary<string, string>();
        public void AddParam(string name, string value)
        {
            paramTable.Add(name, value);
        }

        public void GenerateQuestScript()
        {
            List<string> outputCpp = new List<string>();

            ProcessLuaCode();
            ProcessCppCode();
            InitSceneGroupList();
            InitSeqList();
            EntryPreProcess();
            bool isSimpleParse = false;
            allowEmptyEntry = seqList.Count > sceneGroupList.Count;
            int buildResult = 0;
            buildResult = paramTable.ContainsKey("_ALLOW_EMPTY_ENTRY") ? -1 : BuildSeqList();
            if (buildResult < 0)
            {
                if (!allowEmptyEntry)
                {
                    Console.WriteLine("allowEmptyEntry = true");
                    allowEmptyEntry = true;
                    InitSceneGroupList();
                    InitSeqList();
                    EntryPreProcess();
                    buildResult = BuildSeqList();
                }
                if (buildResult < 0)
                {
                    if (Program.ManualMode)
                    {
                        Console.WriteLine("Output simple mode result...");
                        isSimpleParse = true;
                        if (!BuildSeqListSimple())
                            throw new Exception("Failed");
                    }
                    else
                        throw new Exception("Failed");
                }
            }
            InitEventItems();
            BNpcHack(); // see comment inside
            EntryPostProcess();

            //return;

            outputCpp.Add("// FFXIVTheMovie.ParserV3.10");
            if (CppOutputExtraInfo)
            {
                outputCpp.Add("// Extra info is ON");
            }
            if (isSimpleParse)
            {
                outputCpp.Add("// simple method used");
            }
            else if (buildResult != 1)
            {
                outputCpp.Add("// id table disabled");
            }
            if (fIsAnnounce.IsFake)
            {
                outputCpp.Add("// fake IsAnnounce table");
            }
            if (!isSimpleParse && paramTable.Count > 0)
            {
                outputCpp.Add("// param used:");
                foreach (var entry in paramTable)
                {
                    if (entry.Value != null)
                    {
                        if ((entry.Key[0] != '_' && !entry.Key.StartsWith("IGNORE_")) || !string.IsNullOrEmpty(entry.Value))
                        {
                            outputCpp.Add($"//{entry.Key} = {entry.Value}");
                        }
                        else
                        {
                            outputCpp.Add($"//{entry.Key} SET!!");
                        }
                    }
                    else
                        outputCpp.Add($"//{entry.Key} REMOVED!!");
                }
            }
            outputCpp.Add("#include <Actor/Player.h>");
            outputCpp.Add("#include <ScriptObject.h>");
            outputCpp.Add("#include <Service.h>");
            outputCpp.Add("#include \"Manager/TerritoryMgr.h\"");
            outputCpp.Add("#include \"Manager/EventMgr.h\"");
            outputCpp.Add("");
            outputCpp.Add("using namespace Sapphire;");
            outputCpp.Add("");
            outputCpp.Add($"class {questId} : public Sapphire::ScriptAPI::QuestScript");
            outputCpp.Add("{");
            outputCpp.Add("public:");
            outputCpp.Add($"  {questId}() : Sapphire::ScriptAPI::QuestScript( {questNumber} ){{}}; ");
            outputCpp.Add($"  ~{questId}() = default; ");
            outputCpp.Add("");
            foreach (var seq in seqList)
            {
                outputCpp.Add($"  //SEQ_{seq.SeqNumber}, {seq.EntryList.Count} entries");
            }
            outputCpp.Add("");
            foreach (var c in constTable)
            {
                outputCpp.Add($"  //{c.Key} = {c.Value}");
            }
            outputCpp.Add("");
            outputCpp.Add("  static constexpr auto EVENT_ON_TALK = 0;");
            outputCpp.Add("  static constexpr auto EVENT_ON_EMOTE = 1;");
            outputCpp.Add("  static constexpr auto EVENT_ON_BNPC_KILL = 2;");
            outputCpp.Add("  static constexpr auto EVENT_ON_WITHIN_RANGE = 3;");
            outputCpp.Add("  static constexpr auto EVENT_ON_ENTER_TERRITORY = 4;");
            outputCpp.Add("  static constexpr auto EVENT_ON_EVENT_ITEM = 5;");
            outputCpp.Add("  static constexpr auto EVENT_ON_EOBJ_HIT = 6;");
            outputCpp.Add("  static constexpr auto EVENT_ON_SAY = 7;");
            outputCpp.Add("");
            outputCpp.Add("private:");
            outputCpp.Add("  void onProgress( World::Quest& quest, Entity::Player& player, uint32_t type, uint64_t param1, uint32_t param2, uint32_t param3 )");
            outputCpp.Add("  {");
            outputCpp.Add("    switch( quest.getSeq() )");
            outputCpp.Add("    {");
            foreach (var seq in seqList)
            {
                foreach (var entry in seq.EntryList)
                {
                    int minCount = 1;
                    int i = 0;
                    if (entry.EntryScene.ContainsSceneElement(LuaScene.SceneElement.Inventory))
                    {
                        minCount = 2;
                        i = 1;
                    }
                    while (entry.EntryScene.SceneList.Count > minCount && i < entry.EntryScene.SceneList.Count)
                    {
                        if (entry.EntryScene.SceneList[i].Type == LuaScene.SceneType.Empty)
                            entry.EntryScene.SceneList.RemoveAt(i);
                        else
                            i++;
                    }
                }
            }
            foreach (var seq in seqList)
            {
                var eventItemList = fGetEventItem != null ? (fGetEventItem.SeqEventItems.ContainsKey(seq.SeqNumber) ? fGetEventItem.SeqEventItems[seq.SeqNumber] : null) : null;
                if (eventItemList != null)
                {
                    foreach (var item in eventItemList)
                    {
                        outputCpp.Add($"      //seq {seq.SeqNumber} event item {item.Item} = {item.QuestVar} max stack {(item.Amount == 0 ? "?" : item.Amount.ToString())}");
                    }
                }
                outputCpp.Add($"      case {seq.SeqNumber}:");
                outputCpp.Add("      {");
                foreach (var entry in seq.EntryList)
                {
                    var scene = entry.EntryScene.SceneList.Count > 0 ? entry.EntryScene.SceneList[0] : null;
                    var scene2 = entry.EntryScene.SceneList.Count > 1 ? entry.EntryScene.SceneList[1] : null;
                    var scene3 = entry.EntryScene.SceneList.Count > 2 ? entry.EntryScene.SceneList[2] : null;
                    var scene4 = entry.EntryScene.SceneList.Count > 3 ? entry.EntryScene.SceneList[3] : null;
                    if (entry.bNpcHackCreditDest != null)
                    {
                        outputCpp.Add($"        // BNpcHack credit moved to {entry.bNpcHackCreditDest}");
                    }
                    if (entry.TargetObject == null)
                    {
                        if (entry.InventoryBranch)
                        {
                            if (scene == null || scene2 == null)
                                throw new Exception("WTF???");
                            outputCpp.Add($"        if( type == EVENT_ON_TALK ) {scene.SceneFunctionName}( quest, player ); // {scene}");
                            outputCpp.Add($"        if( type == EVENT_ON_EVENT_ITEM ) {scene2.SceneFunctionName}( quest, player ); // {scene2}");
                            if (scene3 != null)
                            {
                                outputCpp.Add($"        // +Callback {scene3}");
                            }
                            if (scene4 != null)
                            {
                                outputCpp.Add($"        // +Callback {scene4}");
                            }
                        }
                        else
                        {
                            if (scene != null)
                            {
                                outputCpp.Add($"        if( type != EVENT_ON_BNPC_KILL ) {scene.SceneFunctionName}( quest, player ); // {scene}");
                            }
                            else
                            {
                                outputCpp.Add("        // empty entry");
                            }
                            if (scene2 != null)
                            {
                                outputCpp.Add($"        // +Callback {scene2}");
                            }
                            if (scene3 != null)
                            {
                                outputCpp.Add($"        // +Callback {scene3}");
                            }
                            if (scene4 != null)
                            {
                                outputCpp.Add($"        // +Callback {scene4}");
                            }
                        }
                    }
                    else
                    {

                        if (entry.TargetObject is ActiveTerritory)
                        {
                            outputCpp.Add($"        if( type == EVENT_ON_ENTER_TERRITORY ) // {entry.TargetObject.Name} = {entry.EntryScene.Identity}");
                        }
                        else
                        {
                            var objId = constTable.ContainsKey(entry.TargetObject.Name) ? constTable[entry.TargetObject.Name].ToString() : "/*UNKNOWN*/1";
                            var unmappedId = unmappedObjTable.ContainsKey(entry.TargetObject.Name) ? unmappedObjTable[entry.TargetObject.Name].ToString() : null;
                            outputCpp.Add($"        if( param1 == {objId}{(unmappedId != null ? $" || param1 == {unmappedId}" : "")} ) // {entry.TargetObject.Name} = {entry.EntryScene.Identity}{(entry.ConditionBranch ? $", CB={entry.RequiredGroupCount}" : "")}{(entry.EmoteBranch != null ? $", EB={entry.RequiredGroupCount}(emote={entry.EmoteBranch.Value})" : "")}");
                        }

                        outputCpp.Add("        {");
                        string extraSpace = entry.Var != null ? "  " : "";
                        if (entry.Var != null)
                        {
                            
                            if (/*entry.ConditionBranch && */entry.Var.Value > 1 && entry.Flag != null)
                            {
                                outputCpp.Add($"          if( {entry.Flag.ToCppExprConditionNotDone()} )");
                            }
                            else
                            {
                                outputCpp.Add($"          if( {entry.Var.ToCppExprConditionNotDone()} )");
                            }
                            outputCpp.Add($"          {{");
                        }
                        if (entry.ConditionBranch && entry.Var != null)
                        {
                            if (scene != null)
                            {
                                outputCpp.Add($"{extraSpace}          {scene.SceneFunctionName}( quest, player ); // {scene}");
                            }
                            else
                            {
                                outputCpp.Add($"{extraSpace}          {entry.Var.ToCppExprOperation()};");
                                if (entry.Owner.SeqNumber > 0 && entry.Owner.SeqNumber < 255 && entry.TodoIndex.HasValue)
                                {
                                    outputCpp.Add($"{extraSpace}          {entry.ToCppEventNotice()};");
                                }
                                if (entry.Flag != null)
                                    outputCpp.Add($"{extraSpace}          {entry.Flag.ToCppExprSet()};");
                                outputCpp.Add($"{extraSpace}          checkProgressSeq{seq.SeqNumber}( quest, player );");
                            }
                            if (scene2 != null)
                            {
                                if (scene3 == null)
                                {
                                    outputCpp.Add($"{extraSpace}        }}");
                                    outputCpp.Add($"{extraSpace}        else");
                                    outputCpp.Add($"{extraSpace}        {{");
                                    outputCpp.Add($"{extraSpace}          {scene2.SceneFunctionName}( quest, player ); // {scene2}");
                                }
                                else
                                {
                                    outputCpp.Add($"{extraSpace}          // +Callback {scene2}");
                                }
                            }
                            if (scene3 != null)
                            {
                                if (scene4 == null)
                                {
                                    outputCpp.Add($"{extraSpace}        }}");
                                    outputCpp.Add($"{extraSpace}        else");
                                    outputCpp.Add($"{extraSpace}        {{");
                                    outputCpp.Add($"{extraSpace}          {scene3.SceneFunctionName}( quest, player ); // {scene3}");
                                }
                                else
                                {
                                    outputCpp.Add($"{extraSpace}          // +Callback {scene3}");
                                }
                            }
                            if (scene4 != null)
                            {
                                outputCpp.Add($"{extraSpace}        }}");
                                outputCpp.Add($"{extraSpace}        else");
                                outputCpp.Add($"{extraSpace}        {{");
                                outputCpp.Add($"{extraSpace}          {scene4.SceneFunctionName}( quest, player ); // {scene4}");
                            }
                        }
                        else if (entry.EmoteBranch != null)
                        {
                            if (scene == null || scene2 == null)
                                throw new Exception("WTF???");
                            outputCpp.Add($"{extraSpace}          if( type == EVENT_ON_TALK ) {scene.SceneFunctionName}( quest, player ); // {scene}");
                            outputCpp.Add($"{extraSpace}          if( type == EVENT_ON_EMOTE )");
                            outputCpp.Add($"{extraSpace}          {{");
                            outputCpp.Add($"{extraSpace}            {(entry.EmoteBranch.Value == 0 ? "/*" : "")}if( param3 == {entry.EmoteBranch.Value} ){(entry.EmoteBranch.Value == 0 ? "*/" : "")} {scene2.SceneFunctionName}( quest, player ); // Correct {scene2}");
                            if (scene3 != null)
                            {
                                if (entry.EmoteBranch.Value == 0) outputCpp.Add($"{extraSpace}              /*");
                                outputCpp.Add($"{extraSpace}            else {scene3.SceneFunctionName}( quest, player ); // Incorrect {scene3}");
                                if (entry.EmoteBranch.Value == 0) outputCpp.Add($"{extraSpace}              */");
                            }
                            else
                            {
                                outputCpp.Add($"{extraSpace}              //No incorrect branch.");
                            }
                            outputCpp.Add($"{extraSpace}          }}");
                            if (scene4 != null)
                            {
                                outputCpp.Add($"{extraSpace}          // WTF IS THIS????? {scene4}");
                            }
                        }
                        else if (entry.InventoryBranch)
                        {
                            if (scene == null || scene2 == null)
                                throw new Exception("WTF???");
                            outputCpp.Add($"{extraSpace}          if( type == EVENT_ON_TALK ) {scene.SceneFunctionName}( quest, player ); // {scene}");
                            outputCpp.Add($"{extraSpace}          if( type == EVENT_ON_EVENT_ITEM ) {scene2.SceneFunctionName}( quest, player ); // {scene2}");
                            if (scene3 != null)
                            {
                                outputCpp.Add($"{extraSpace}          // +Callback {scene3}");
                            }
                            if (scene4 != null)
                            {
                                outputCpp.Add($"{extraSpace}          // +Callback {scene4}");
                            }
                        }
                        else if (entry.ChatSayBranch)
                        {
                            if (scene == null || scene2 == null)
                                throw new Exception("WTF???");
                            outputCpp.Add($"{extraSpace}          if( type == EVENT_ON_TALK ) {scene.SceneFunctionName}( quest, player ); // {scene}");
                            outputCpp.Add($"{extraSpace}          if( type == EVENT_ON_SAY ) {scene2.SceneFunctionName}( quest, player ); // {scene2}");
                            if (scene3 != null)
                            {
                                outputCpp.Add($"{extraSpace}          // +Callback {scene3}");
                            }
                            if (scene4 != null)
                            {
                                outputCpp.Add($"{extraSpace}          // +Callback {scene4}");
                            }
                        }
                        else
                        {
                            if (scene != null)
                            {
                                outputCpp.Add($"{extraSpace}          {scene.SceneFunctionName}( quest, player ); // {scene}");
                            }
                            else
                            {
                                if (entry.Var != null)
                                {
                                    outputCpp.Add($"{extraSpace}          {entry.Var.ToCppExprOperation()};");
                                    if (entry.Owner.SeqNumber > 0 && entry.Owner.SeqNumber < 255 && entry.TodoIndex.HasValue)
                                    {
                                        outputCpp.Add($"{extraSpace}          {entry.ToCppEventNotice()};");
                                    }
                                    if (entry.Flag != null)
                                        outputCpp.Add($"{extraSpace}          {entry.Flag.ToCppExprSet()};");
                                    outputCpp.Add($"{extraSpace}          checkProgressSeq{seq.SeqNumber}( quest, player );");
                                }
                                else
                                    outputCpp.Add($"{extraSpace}        // empty entry");
                            }
                            if (scene2 != null)
                            {
                                outputCpp.Add($"{extraSpace}          // +Callback {scene2}");
                            }
                            if (scene3 != null)
                            {
                                outputCpp.Add($"{extraSpace}          // +Callback {scene3}");
                            }
                            if (scene4 != null)
                            {
                                outputCpp.Add($"{extraSpace}          // +Callback {scene4}");
                            }
                        }
                        if (entry.Var != null)
                        {
                            outputCpp.Add($"          }}");
                        }
                        outputCpp.Add($"          break;");
                        outputCpp.Add("        }");
                    }

                }
                outputCpp.Add("        break;");
                outputCpp.Add("      }");
            }
            outputCpp.Add("      default:");
            outputCpp.Add("      {");
            outputCpp.Add("        playerMgr().sendUrgent( player, \"Sequence {} not defined.\", quest.getSeq() );");
            outputCpp.Add("        break;");
            outputCpp.Add("      }");
            outputCpp.Add("    }");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("public:");
            outputCpp.Add("  void onTalk( World::Quest& quest, Entity::Player& player, uint64_t actorId ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( quest, player, EVENT_ON_TALK, actorId, 0, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("  void onEmote( World::Quest& quest, uint64_t actorId, uint32_t emoteId, Sapphire::Entity::Player& player ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    playerMgr().sendDebug( player, \"emote: {}\", emoteId );");
            outputCpp.Add("    onProgress( quest, player, EVENT_ON_EMOTE, actorId, 0, emoteId );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("  void onBNpcKill( World::Quest& quest, uint16_t nameId, uint32_t entityId, Sapphire::Entity::Player& player ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( quest, player, EVENT_ON_BNPC_KILL, static_cast< uint64_t >( nameId ), entityId, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("  void onWithinRange( World::Quest& quest, Sapphire::Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( quest, player, EVENT_ON_WITHIN_RANGE, static_cast< uint64_t >( param1 ), 0, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("  void onEnterTerritory( World::Quest& quest, Sapphire::Entity::Player& player, uint16_t param1, uint16_t param2 ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( quest, player, EVENT_ON_ENTER_TERRITORY, static_cast< uint64_t >( param1 ), static_cast< uint32_t >( param2 ), 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("  void onEventItem( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( quest, player, EVENT_ON_EVENT_ITEM, actorId, 0, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("  void onEObjHit( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t actionId ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( quest, player, EVENT_ON_EOBJ_HIT, actorId, actionId, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("  void onSay( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t sayId ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( quest, player, EVENT_ON_SAY, actorId, sayId, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("private:");
            for (int s = 0; s < seqList.Count - 1; s++)
            {
                var seq = seqList[s];
                var s2 = s + 1;
                var nextSeq = seqList[s2];
                while (BNpcHackUsed && !nextSeq.Ignore && s2 < seqList.Count - 1 && nextSeq.EntryList.Count == 1 && nextSeq.EntryList[0].EntryScene.SceneList.Count == 0)
                {
                    s2++;
                    nextSeq = seqList[s2];
                }
                var eventItemList = fGetEventItem != null ? (fGetEventItem.SeqEventItems.ContainsKey(seq.SeqNumber) ? fGetEventItem.SeqEventItems[seq.SeqNumber] : null) : null;
                var nextEventItemList = fGetEventItem != null ? (fGetEventItem.SeqEventItems.ContainsKey(nextSeq.SeqNumber) ? fGetEventItem.SeqEventItems[nextSeq.SeqNumber] : null) : null;
                var varList = new List<QuestVar>();
                seq.EntryList.ForEach(e => { if (e.Var != null && varList.SingleOrDefault(v => v.Name == e.Var.Name) == null) { varList.Add(e.Var); } });
                var flagList = new List<QuestFlag>();
                seq.EntryList.ForEach(e => { if (e.Flag != null) { flagList.Add(e.Flag); } });
                var nextVarList = new List<QuestVar>();
                nextSeq.EntryList.ForEach(e => { if (e.Var != null && nextVarList.SingleOrDefault(v => v.Name == e.Var.Name) == null) { nextVarList.Add(e.Var); } });
                
                outputCpp.Add($"  void checkProgressSeq{seq.SeqNumber}( World::Quest& quest, Entity::Player& player )");
                outputCpp.Add("  {");
                bool hasIf = varList.Count > 0;
                if (s > 0)
                {
                    for (int i = 0; i < varList.Count; i++)
                    {
                        var v = varList[i];
                        StringBuilder builder = new StringBuilder();
                        builder.Append("    ");
                        for (int a = 0; a < i; a++)
                        {
                            builder.Append("  ");
                        }
                        builder.Append($"if( {v.ToCppExprConditionDone()} )");
                        outputCpp.Add(builder.ToString());
                    }
                }
                else
                    hasIf = false;
                ////
                {
                    StringBuilder builder = new StringBuilder();
                    builder.Append("    ");
                    if (hasIf)
                    {
                        for (int a = 0; a < varList.Count - 1; a++)
                        {
                            builder.Append("  ");
                        }
                    }
                    string space = builder.ToString();
                    if(hasIf)
                        outputCpp.Add($"{space}{{");

                    if (s > 0)
                    {
                        for (int i = 0; i < varList.Count; i++)
                        {
                            var v = varList[i];
                            if (eventItemList != null && nextEventItemList != null)
                            {
                                var item = eventItemList.FirstOrDefault(a => a.QuestVar == v.Name);
                                if (item != null)
                                {
                                    var itemNext = nextEventItemList.FirstOrDefault(a => a.Item == item.Item && a.QuestVar == v.Name);
                                    if (itemNext != null)
                                    {
                                        continue;
                                    }
                                }
                            }
                            outputCpp.Add($"{space}{(hasIf ? "  " : "")}{v.ToCppExprClear()};");
                        }
                        for (int i = 0; i < flagList.Count; i++)
                        {
                            var f = flagList[i];
                            outputCpp.Add($"{space}{(hasIf ? "  " : "")}{f.ToCppExprClear()};");
                        }
                    }

                    if (s > 0 && eventItemList != null)
                    {
                        foreach (var item in eventItemList)
                        {
                            bool found = false;
                            if (nextEventItemList != null)
                            {
                                foreach (var nextItem in nextEventItemList)
                                {
                                    if (item.Item == nextItem.Item && item.QuestVar == nextItem.QuestVar)
                                    {
                                        found = true;
                                        break;
                                    }
                                }
                            }
                            if (!found)
                            {
                                outputCpp.Add($"{space}{(hasIf ? "  " : "")}{item.ToCppExprClear()};");
                            }
                        }
                    }

                    outputCpp.Add($"{space}{(hasIf ? "  " : "")}quest.setSeq( {nextSeq.SeqNumber} );");

                    if (nextSeq.ShouldGiveEventItemAtSeqUpdate() && nextEventItemList != null)
                    {
                        foreach (var item in nextEventItemList)
                        {
                            bool found = false;
                            if (seq.ShouldGiveEventItemAtSeqUpdate() && s > 0 && eventItemList != null)
                            {
                                foreach (var prevItem in eventItemList)
                                {
                                    if (item.Item == prevItem.Item && item.QuestVar == prevItem.QuestVar)
                                    {
                                        found = true;
                                        break;
                                    }
                                }
                            }
                            if (!found)
                            {
                                foreach (var v in nextVarList)
                                {
                                    if (item.QuestVar == v.Name)
                                    {
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found)
                                {
                                    outputCpp.Add($"{space}{(hasIf ? "  " : "")}{item.ToCppExprUpdate()};");
                                }
                            }
                        }
                    }
                    if (hasIf)
                        outputCpp.Add($"{space}}}");
                }
                outputCpp.Add("  }");
            }
            for (int s = 0; s < seqList.Count; s++)
            {
                var seq = seqList[s];
                foreach (var entry in seq.EntryList)
                {
                    var scene = entry.EntryScene.SceneList.Count > 0 ? entry.EntryScene.SceneList[0] : null;
                    var scene2 = entry.EntryScene.SceneList.Count > 1 ? entry.EntryScene.SceneList[1] : null;
                    var scene3 = entry.EntryScene.SceneList.Count > 2 ? entry.EntryScene.SceneList[2] : null;
                    var scene4 = entry.EntryScene.SceneList.Count > 3 ? entry.EntryScene.SceneList[3] : null;
                    outputCpp.Add("");
                    Action<LuaScene, LuaScene, bool> createSceneCppFunction = (current, next, afterComplete) =>
                    {
                        if (current != null)
                        {
                            if (CppOutputExtraInfo)
                            {
                                outputCpp.Add($"  //Key functions found in scene {current.SceneNumber}");
                                foreach (var f in current.FunctionList)
                                {
                                    if (f.IsKeyFunction)
                                    {
                                        outputCpp.Add($"  //{f.ToDetailString()}");
                                    }
                                }
                                outputCpp.Add($"  //=======================");
                                if (current.ParamTable.ContainsKey("TradeItem"))
                                {
                                    outputCpp.Add("  //TradeItem:");
                                    var itemTable = current.ParamTable["TradeItem"] as Dictionary<string, int>;
                                    foreach (var itemEntry in itemTable)
                                    {
                                        outputCpp.Add($"    //{itemEntry.Key} = {itemEntry.Value}");
                                    }
                                }
                                if (current.ParamTable.ContainsKey("ENpcBind"))
                                {
                                    outputCpp.Add("  //ENpcBind:");
                                    var bindSet = current.ParamTable["ENpcBind"] as HashSet<string>;
                                    foreach (var npc in bindSet)
                                    {
                                        outputCpp.Add($"    //{npc}");
                                    }
                                }
                            }
                            outputCpp.Add($"  void {current.SceneFunctionName}( World::Quest& quest, Entity::Player& player ) //{entry.ToSimpleString()}");
                            outputCpp.Add("  {");
                            outputCpp.Add($"    playerMgr().sendDebug( player, \"{questId}:{questNumber} calling {current}\" );");
                            bool shouldProduceCode = true;
                            if (entry.ConditionBranch)
                            {
                                shouldProduceCode = current != entry.EntryScene.SceneList[entry.EntryScene.SceneList.Count - 1];
                            }
                            else if (entry.EmoteBranch != null)
                            {
                                shouldProduceCode = current == entry.EntryScene.SceneList[1];
                            }
                            else if (entry.InventoryBranch || entry.ChatSayBranch)
                            {
                                shouldProduceCode = current != entry.EntryScene.SceneList[0];
                            }

                            if (!shouldProduceCode)
                            {
                                string baseSceneFlag = current.Type == LuaScene.SceneType.Snipe ? "INVIS_ENPC" : null;
                                string extraSceneFlag = (current.Element & (LuaScene.SceneElement.CutScene | LuaScene.SceneElement.FadeIn)) > 0 ? "FADE_OUT | CONDITION_CUTSCENE | HIDE_UI" : null;
                                string fullSceneFlag = baseSceneFlag == null ? (extraSceneFlag == null ? "NONE" : extraSceneFlag) : (extraSceneFlag == null ? baseSceneFlag : $"{baseSceneFlag} | {extraSceneFlag}");
                                outputCpp.Add($"    eventMgr().playQuestScene( player, getId(), {current.SceneNumber}, {fullSceneFlag}, nullptr );");
                            }
                            else
                            {
                                if (current.Type != LuaScene.SceneType.Empty)
                                {
                                    if (current.ShouldCastAction)
                                    {
                                        int action = -1, actionMid = -1;
                                        if (constTable.ContainsKey("EVENTACTION"))
                                        {
                                            action = constTable["EVENTACTION"];
                                        }
                                        if (constTable.ContainsKey("EVENTACTIONPROCESSMIDDLE"))
                                        {
                                            actionMid = constTable["EVENTACTIONPROCESSMIDDLE"];
                                        }
                                        if (action < 0)
                                        {
                                            action = actionMid;
                                        }
                                        else if (actionMid > 0 && entry.TargetObject is ActiveEObject)
                                        {
                                            action = actionMid;
                                        }
                                        if (action < 0)
                                        {
                                            outputCpp.Add($"    //eventMgr().eventActionStart( player, getId(), ***NOT_FOUND***, [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional )");
                                        }
                                        else
                                        {
                                            outputCpp.Add($"    eventMgr().eventActionStart( player, getId(), {action}, [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional )");
                                        }
                                        outputCpp.Add("    {");
                                    }
                                    outputCpp.Add("    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )");
                                    outputCpp.Add("    {");
                                    bool hasIf = false;
                                    if (current.Type == LuaScene.SceneType.NpcTrade ||
                                        ((current.Element & LuaScene.SceneElement.QuestReward) > 0) ||
                                        ((current.Element & LuaScene.SceneElement.QuestOffer) > 0))
                                    {
                                        outputCpp.Add("      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )");
                                        outputCpp.Add("      {");
                                        hasIf = true;
                                    }
                                    if (!hasIf && (current.Element & LuaScene.SceneElement.YesNo) > 0)
                                    {
                                        if ((current.Element & LuaScene.SceneElement.CanCancel) > 0)
                                        {
                                            outputCpp.Add("      if( result.errorCode == 0 || ( result.numOfResults > 0 && result.getResult( 0 ) == 1 ) )");

                                            outputCpp.Add("      {");
                                            hasIf = true;
                                        }
                                        else if (scene2 != null && (scene2.Element & LuaScene.SceneElement.CutScene) > 0)
                                        {
                                            outputCpp.Add("      if( result.errorCode != 50 )");
                                            outputCpp.Add("      {");
                                            hasIf = true;
                                        }
                                        else
                                        {
                                            outputCpp.Add("      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )");
                                            outputCpp.Add("      {");
                                            hasIf = true;
                                        }
                                    }
                                    if (!hasIf && !afterComplete && ((current.Element & LuaScene.SceneElement.Menu) > 0 || (current.Element & LuaScene.SceneElement.CanCancel) > 0 || current.Type == LuaScene.SceneType.Snipe))
                                    {
                                        if (next == null || next.Type != LuaScene.SceneType.CardGame)
                                        {
                                            outputCpp.Add("      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )");
                                        }
                                        else
                                        {
                                            outputCpp.Add("      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )");
                                        }
                                        outputCpp.Add("      {");
                                        hasIf = true;
                                    }

                                    string keyForPrivate = $"{current.Identity}";
                                    if (!privateInstanceEntranceTable.ContainsKey(keyForPrivate))
                                    {
                                        keyForPrivate = $"SCENE{current.SceneNumber}";
                                        if (!privateInstanceEntranceTable.ContainsKey(keyForPrivate))
                                        {
                                            keyForPrivate = null;
                                        }
                                    }

                                    string keyForWarp = $"{current.Identity}";
                                    if (!warpTable.ContainsKey(keyForWarp))
                                    {
                                        keyForWarp = $"SCENE{current.SceneNumber}";
                                        if (!warpTable.ContainsKey(keyForWarp))
                                        {
                                            keyForWarp = null;
                                        }
                                    }

                                    string keyForMount = $"{current.Identity}";
                                    if (!mountTable.ContainsKey(keyForMount))
                                    {
                                        keyForMount = $"SCENE{current.SceneNumber}";
                                        if (!mountTable.ContainsKey(keyForMount))
                                        {
                                            keyForMount = null;
                                        }
                                    }

                                    bool shouldUseFakeZoneing = keyForPrivate == null && keyForWarp == null;
                                    bool shouldContinue = shouldContinue = next != null;
                                    if (entry.ConditionBranch)
                                    {
                                        shouldContinue = shouldContinue && entry.EntryScene.SceneList[entry.EntryScene.SceneList.Count - 1] != next;
                                    }
                                    else if (entry.EmoteBranch != null)
                                    {
                                        shouldContinue = false;
                                    }
                                    else if (entry.InventoryBranch || entry.ChatSayBranch)
                                    {
                                        shouldContinue = shouldContinue && current != entry.EntryScene.SceneList[0];
                                    }

                                    if (shouldContinue)
                                    {
                                        outputCpp.Add($"{(hasIf ? "  " : "")}      {next.SceneFunctionName}( quest, player );");
                                    }
                                    else
                                    {
                                        if (afterComplete)
                                        {
                                            outputCpp.Add($"{(hasIf ? "  " : "")}      player.finishQuest( getId(), result.getResult( 1 ) );");
                                            if (shouldUseFakeZoneing && (current.Element & LuaScene.SceneElement.AutoFadeIn) > 0)
                                            {
                                                outputCpp.Add($"{(hasIf ? "  " : "")}      playerMgr().sendDebug( player, \"Finished with AutoFadeIn scene, reloading zone...\" );");
                                                outputCpp.Add($"{(hasIf ? "  " : "")}      eventMgr().eventFinish( player, result.eventId, 1 );");
                                                outputCpp.Add($"{(hasIf ? "  " : "")}      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );");
                                            }
                                        }
                                        else
                                        {
                                            if (entry.EntryScene.ContainsSceneElement(LuaScene.SceneElement.QuestBattle))
                                            {
                                                outputCpp.Add($"{(hasIf ? "  " : "")}      //quest battle");
                                                outputCpp.Add($"{(hasIf ? "  " : "")}      eventMgr().eventFinish( player, result.eventId, 1 );");
                                                if (constTable.ContainsKey("QUESTBATTLE0"))
                                                {
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      teriMgr().createAndJoinQuestBattle( player, {constTable["QUESTBATTLE0"]} );");
                                                }
                                                else
                                                {
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      //teriMgr().createAndJoinQuestBattle( player, ??? );");
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      playerMgr().sendUrgent( player, \"Missing QuestBattle ID, returning to previous zone.\" );");
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );");
                                                }
                                            }
                                            else
                                            {
                                                if (s > 0 && entry.Var != null)
                                                {
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      {entry.Var.ToCppExprOperation()};");
                                                }
                                                if (s > 0 && entry.Flag != null)
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      {entry.Flag.ToCppExprSet()};");
                                                if (s > 0 && s < 255 && entry.Var != null && entry.TodoIndex.HasValue)
                                                {
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      {entry.ToCppEventNotice()};");
                                                }
                                                if (seq.SeqNumber != 255 && entry.ShouldCheckSeqProgress())
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      checkProgressSeq{seq.SeqNumber}( quest, player );");
                                                if (shouldUseFakeZoneing && (current.Element & LuaScene.SceneElement.AutoFadeIn) > 0)
                                                {
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      playerMgr().sendDebug( player, \"Finished with AutoFadeIn scene, reloading zone...\" );");
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      eventMgr().eventFinish( player, result.eventId, 1 );");
                                                    outputCpp.Add($"{(hasIf ? "  " : "")}      player.performZoning( player.getTerritoryTypeId(), 0, player.getPos(), player.getRot() );");
                                                }
                                            }
                                        }
                                    }
                                    

                                    if (keyForPrivate != null || keyForWarp != null)
                                    {
                                        outputCpp.Add($"{(hasIf ? "  " : "")}      eventMgr().eventFinish( player, result.eventId, 1 );");
                                    }
                                    if (keyForPrivate != null)
                                    {
                                        var zone = privateInstanceEntranceTable[keyForPrivate];
                                        if (zone > 0)
                                        {
                                            outputCpp.Add($"{(hasIf ? "  " : "")}      player.enterPredefinedPrivateInstance( {privateInstanceEntranceTable[keyForPrivate]} );");
                                            //outputCpp.Add($"{(hasIf ? "  " : "")}      playerMgr().sendUrgent( player, \"Missing function to enter private zone {privateInstanceEntranceTable[keyForPrivate]}.\" );");
                                        }
                                        else
                                        {
                                            outputCpp.Add($"{(hasIf ? "  " : "")}      player.exitInstance();");
                                        }
                                    }
                                    if (keyForMount != null)
                                    {
                                        outputCpp.Add($"{(hasIf ? "  " : "")}      player.setMount( {mountTable[keyForMount]} );");
                                    }
                                    else if (keyForWarp != null)
                                    {
                                        var dst = warpTable[keyForWarp];
                                        outputCpp.Add($"{(hasIf ? "  " : "")}      player.forceZoneing( {dst.Item1}, {dst.Item2:#0.0#}f, {dst.Item3:#0.0#}f, {dst.Item4:#0.0#}f, {dst.Item5:#0.0#}f, {dst.Item6} );");
                                        //outputCpp.Add($"{(hasIf ? "  " : "")}      player.performZoning( {dst.Item1}, 0, {{ {dst.Item2:#0.0#}f, {dst.Item3:#0.0#}f, {dst.Item4:#0.0#}f }}, {dst.Item5:#0.0#}f );");
                                        //outputCpp.Add($"{(hasIf ? "  " : "")}      playerMgr().sendUrgent( player, \"Missing function to apply showZoneName = {dst.Item6}\" );");
                                    }

                                    if (hasIf)
                                    {
                                        outputCpp.Add("      }");
                                    }
                                    outputCpp.Add("    };");
                                    string baseSceneFlag = current.Type == LuaScene.SceneType.Snipe ? "INVIS_ENPC" : null;
                                    string extraSceneFlag = (current.Element & (LuaScene.SceneElement.CutScene | LuaScene.SceneElement.FadeIn)) > 0 ? "FADE_OUT | CONDITION_CUTSCENE | HIDE_UI" : null;
                                    string fullSceneFlag = baseSceneFlag == null ? (extraSceneFlag == null ? "NONE" : extraSceneFlag) : (extraSceneFlag == null ? baseSceneFlag : $"{baseSceneFlag} | {extraSceneFlag}");
                                    outputCpp.Add($"    eventMgr().playQuestScene( player, getId(), {current.SceneNumber}, {fullSceneFlag}, callback );");
                                    if (current.ShouldCastAction)
                                    {
                                        outputCpp.Add("    }, nullptr, getId() );");
                                    }
                                }
                                else
                                {
                                    bool shouldContinue = shouldContinue = next != null;
                                    if (entry.ConditionBranch)
                                    {
                                        shouldContinue = shouldContinue && entry.EntryScene.SceneList[entry.EntryScene.SceneList.Count - 1] != next;
                                    }
                                    else if (entry.EmoteBranch != null)
                                    {
                                        shouldContinue = false;
                                    }
                                    else if (entry.InventoryBranch || entry.ChatSayBranch)
                                    {
                                        shouldContinue = shouldContinue && current != entry.EntryScene.SceneList[0];
                                    }
                                    if (shouldContinue)
                                    {
                                        outputCpp.Add($"    {next.SceneFunctionName}( quest, player );");
                                    }
                                    else
                                    {
                                        if (s > 0 && entry.Var != null)
                                        {
                                            outputCpp.Add($"    {entry.Var.ToCppExprOperation()};");
                                        }
                                        if (s > 0 && entry.Flag != null)
                                            outputCpp.Add($"    {entry.Flag.ToCppExprSet()};");
                                        if (s > 0 && s < 255 && entry.Var != null && entry.TodoIndex.HasValue)
                                        {
                                            outputCpp.Add($"    {entry.ToCppEventNotice()};");
                                        }
                                        if (seq.SeqNumber != 255 && entry.ShouldCheckSeqProgress())
                                            outputCpp.Add($"    checkProgressSeq{seq.SeqNumber}( quest, player );");
                                    }
                                }
                            }
                            outputCpp.Add("  }");
                        }
                    };
                    bool c = (scene != null && ((scene.Element & LuaScene.SceneElement.QuestComplete) > 0));
                    createSceneCppFunction(scene, scene2, c);
                    c = c || (scene2 != null && ((scene2.Element & LuaScene.SceneElement.QuestComplete) > 0));
                    createSceneCppFunction(scene2, scene3, c);
                    c = c || (scene3 != null && ((scene3.Element & LuaScene.SceneElement.QuestComplete) > 0));
                    createSceneCppFunction(scene3, scene4, c);
                    c = c || (scene4 != null && ((scene4.Element & LuaScene.SceneElement.QuestComplete) > 0));
                    createSceneCppFunction(scene4, null, c);
                }
             }

            outputCpp.Add("};");
            outputCpp.Add("");
            outputCpp.Add($"EXPOSE_SCRIPT( {questId} );");

            using (StreamWriter writer = new StreamWriter(Path.Combine(outputFolder, $"{questId}.cpp")))
            {
                foreach (var s in outputCpp)
                {
                    writer.WriteLine(s);
                }
            }
        }
        private static bool BNpcHackUsed = false;
        private void BNpcHack()
        {
            //since we are not spawning bnpcs, move its credit to another entry and hope it's the one that suppose to do the spawning.
            //if u want to implement the quest manually based on the generated code, do not run this method.
            
            //return;

            HashSet<string> processedVars = new HashSet<string>();
            foreach (var seq in seqList)
            {
                while (paramTable.ContainsKey("_AGGRESSIVE_BNPC_HACK") || seq.ContainsSceneElement(LuaScene.SceneElement.PopBNpc))
                {
                    var enemyEntry = seq.EntryList.FirstOrDefault(e => e.TargetObject is ActiveEnemy && e.Var != null);
                    if (enemyEntry != null)
                    {
                        if (!processedVars.Contains(enemyEntry.Var.Name))
                        {
                            for (int i = seq.EntryList.IndexOf(enemyEntry) - 1; i >= 0; i--)
                            {
                                var e = seq.EntryList[i];
                                if (e == enemyEntry)
                                    continue;
                                if (e.TargetObject != null && !(e.TargetObject is ActiveEnemy) && e.Var == null)
                                {
                                    if (paramTable.ContainsKey($"IGNORE_BNPCHACK_{e.TargetObject.Name}"))
                                        continue;
                                    seq.EntryList[i].Var = enemyEntry.Var;
                                    seq.EntryList[i].Var.ForceSetValue = true;
                                    enemyEntry.bNpcHackCreditDest = seq.EntryList[i].TargetObject.Name;
                                    if (enemyEntry.Flag != null)
                                    {
                                        if (seq.EntryList[i].Flag == null)
                                            seq.EntryList[i].Flag = enemyEntry.Flag;
                                        else
                                            Console.WriteLine($"[BNpcHack]Cannot move {enemyEntry.Flag} to {seq.EntryList[i].TargetObject.Name}, a flag is already present.");
                                    }
                                    processedVars.Add(enemyEntry.Var.Name);
                                    break;
                                }
                            }
                        }
                        enemyEntry.Var = null;
                    }
                    else
                        break;
                }
            }
            BNpcHackUsed = true;
        }

        private void EntryPreProcess()
        {
            foreach (var seq in seqList)
            {
                foreach (var entry in seq.EntryList)
                {
                    if (entry.TargetObject != null && paramTable.TryGetValue($"_{entry.TargetObject.Name}", out var f))
                    {
                        if (f.Contains('E'))
                        {
                            var value = paramTable[$"_{entry.TargetObject.Name}E"];
                            var array = value.Split('|');
                            var seqList = array[0].Split(',');
                            for (var i = 0; i < seqList.Length; i++)
                            {
                                seqList[i] = seqList[i].Trim();
                            }
                            if (seqList.FirstOrDefault(s => s == entry.Owner.SeqNumber.ToString()) != null)
                            {
                                var type = array[1];
                                int emote = 0;
                                array = array[1].Split(',');
                                if (array.Length == 2)
                                {
                                    type = array[0];
                                    emote = int.Parse(array[1]);
                                }
                                entry.EmoteBranch = emote;
                                switch (type)
                                {
                                    case "3":
                                        {
                                            entry.RequiredGroupCount = 3;
                                            break;
                                        }
                                    case "2":
                                        {
                                            entry.RequiredGroupCount = 2;
                                            break;
                                        }
                                }
                            }
                        }
                        if (f.Contains('B'))
                        {
                            var value = paramTable[$"_{entry.TargetObject.Name}B"];
                            var array = value.Split('|');
                            var seqList = array[0].Split(',');
                            for (var i = 0; i < seqList.Length; i++)
                            {
                                seqList[i] = seqList[i].Trim();
                            }
                            if (seqList.FirstOrDefault(s => s == entry.Owner.SeqNumber.ToString()) != null)
                            {
                                entry.ConditionBranch = true;
                                entry.RequiredGroupCount = int.Parse(array[1]);
                            }
                        }
                        /*
                        if (f.Contains('C'))
                        {
                            var value = paramTable[$"_{entry.TargetObject.Name}C"];
                            var array = value.Split('|');
                            var seqList = array[0].Split(',');
                            for (var i = 0; i < seqList.Length; i++)
                            {
                                seqList[i] = seqList[i].Trim();
                            }
                            if (seqList.FirstOrDefault(s => s == entry.Owner.SeqNumber.ToString()) != null)
                            {
                                entry.ChatSayBranch = true;
                                entry.RequiredGroupCount = int.Parse(array[1]);
                            }
                        }
                        */
                    }
                }
            }
        }

        private void EntryPostProcess()
        {
            int todoCurrentPos = 0;
            Tuple<int, string, int> lastTodo = null;
            bool todoDisabled = paramTable.ContainsKey("TODO_DISABLED");
            foreach (var seq in seqList)
            {
                lastTodo = null;
                foreach (var entry in seq.EntryList)
                {
                    if (!todoDisabled && seq.SeqNumber > 0 && fIsTodoChecked != null)
                    {
                        if (entry.Var != null)
                        {
                            if (lastTodo != null && lastTodo.Item2 == entry.Var.Name)
                            {
                                entry.TodoIndex = lastTodo.Item1;
                            }
                            else if (todoCurrentPos < fIsTodoChecked.TodoList.Count)
                            {
                                var todo = fIsTodoChecked.TodoList[todoCurrentPos];
                                if (todo.Item2 == entry.Var.Name)
                                {
                                    lastTodo = todo;
                                    entry.TodoIndex = todo.Item1;
                                    todoCurrentPos++;
                                }
                            }
                        }
                        else if (entry.EntryScene.ContainsSceneElement(LuaScene.SceneElement.ReturnTrue))
                        {
                            if (seq.EntryList.FirstOrDefault(e => e.TargetObject is ActiveTerritory) != null)
                            {
                                var todo = fIsTodoChecked.TodoList[todoCurrentPos];
                                if (todo.Item3 < 2)
                                {
                                    lastTodo = todo;
                                    entry.TodoIndex = todo.Item1;
                                    todoCurrentPos++;
                                }
                            }
                        }
                    }

                    if (!entry.ConditionBranch && useBranchGlobal)
                    {
                        if (entry.TargetObject != null &&
                            entry.TargetObject.Type == ActiveEventObject.ObjectType.Actor &&
                            entry.Var != null &&
                            entry.Var.Value == 1 &&
                            entry.EntryScene.Identity != "unknown" &&
                            entry.EntryScene.HasSubScenes &&
                            (entry.EntryScene.SceneList[0].Element & LuaScene.SceneElement.Talk) > 0 &&
                            (entry.EntryScene.SceneList[entry.EntryScene.SceneList.Count - 1].Element & LuaScene.SceneElement.Talk) > 0)
                        {
                            var id = entry.EntryScene.Identity;
                            bool flag = true;
                            foreach (var scene in entry.EntryScene.SceneList)
                            {
                                if ((scene.Element & LuaScene.SceneElement.Talk) > 0 && scene.Identity != id)
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            entry.ConditionBranch = flag;
                        }
                    }

                    if (entry.EntryScene.SceneList.Count >= 2 && (entry.EntryScene.SceneList[0].Element & LuaScene.SceneElement.Inventory) > 0)
                    {
                        entry.InventoryBranch = true;
                    }
                }
            }

        }

        private bool BuildSeqListSimple()
        {
            List<EventEntry> allEntries = new List<EventEntry>();
            foreach (var seq in seqList)
            {
                allEntries.AddRange(seq.EntryList);
            }
            int g = 0;
            int e = 0;
            try
            {
                for (e = 0; e < allEntries.Count; e++)
                {
                    var entry = allEntries[e];
                    if (entry.TargetObject == null)
                    {
                        entry.EntryScene.SceneList.AddRange(sceneGroupList[g].SceneList);
                        g++;
                    }
                    else if (entry.TargetObject is ActiveActor || entry.TargetObject is ActiveEObject)
                    {
                        entry.EntryScene.SceneList.AddRange(sceneGroupList[g].SceneList);
                        g++;
                        if (g < sceneGroupList.Count && (sceneGroupList.Count - g > allEntries.Count - e) && entry.EntryScene.SceneList.Count < 2 && sceneGroupList[g].SceneList.Count < 2 && entry.Var != null && entry.Var.Value > 1)
                        {
                            entry.EntryScene.SceneList.AddRange(sceneGroupList[g].SceneList);
                            g++;
                        }
                    }
                    else if (entry.TargetObject is ActiveRange || entry.TargetObject is ActiveTerritory)
                    {
                        entry.EntryScene.SceneList.AddRange(sceneGroupList[g].SceneList);
                        g++;
                    }
                }
                if (g != sceneGroupList.Count)
                {
                    if (sceneGroupList[g].ContainsSceneElement(LuaScene.SceneElement.QuestReward))
                    {
                        allEntries[allEntries.Count - 1].EntryScene.SceneList.AddRange(sceneGroupList[g].SceneList);
                    }
                    else
                        throw new Exception();
                }
                return true;
            }
            catch (Exception) { }
            foreach (var entry in allEntries)
            {
                entry.EntryScene.SceneList.Clear();
            }
            e = 0;
            for (g = 0; g < sceneGroupList.Count; g++)
            {
                var group = sceneGroupList[g];
                if ((group.SceneList[0].Element & LuaScene.SceneElement.QuestReward) > 0)
                {
                    e = allEntries.Count - 1;
                }
                allEntries[e].EntryScene.SceneList.AddRange(group.SceneList);
                if (e >= allEntries.Count - 1)
                    break;
                e++;
            }
            return true;
        }
        private int BuildSeqList()
        {
            var idTable = new Dictionary<string, Tuple<string, int>>();
            privateInstanceEntranceTable = new Dictionary<string, int>();
            mountTable = new Dictionary<string, int>();
            warpTable = new Dictionary<string, Tuple<int, float, float, float, float, string>>();
            unmappedObjTable = new Dictionary<string, long>();
            foreach (var entry in paramTable)
            {
                if (entry.Key.StartsWith("SCENE_"))
                {
                    var sceneNum = int.Parse(entry.Key.Split('_')[1]);
                    foreach (var g in sceneGroupList)
                    {
                        var scene = g.SceneList.FirstOrDefault(s => s.SceneNumber == sceneNum);
                        if (scene != null)
                        {
                            if (entry.Value == null)
                            {
                                g.SceneList.Remove(scene);
                                if (g.SceneList.Count == 0)
                                    sceneGroupList.Remove(g);
                            }
                            else
                            {
                                scene.Identity = entry.Value;
                            }
                            break;
                        }
                    }
                }
                else if (entry.Key.StartsWith("_SCENE_"))
                {
                    var sceneNum = int.Parse(entry.Key.Split('_')[2]);
                    foreach (var g in sceneGroupList)
                    {
                        var scene = g.SceneList.FirstOrDefault(s => s.SceneNumber == sceneNum);
                        if (scene != null)
                        {
                            if (entry.Value.Contains("Z"))
                            {
                                scene.Element |= LuaScene.SceneElement.AutoFadeIn;
                            }
                            break;
                        }
                    }
                }
                else if (entry.Key.StartsWith("PRIVATE_"))
                {
                    var id = entry.Key.Split('_')[1];
                    privateInstanceEntranceTable.Add(id, int.Parse(entry.Value));
                }
                else if (entry.Key.StartsWith("WARP_"))
                {
                    var id = entry.Key.Split('_')[1];
                    var dst = entry.Value.Split('|');
                    try
                    {
                        warpTable.Add(id, new Tuple<int, float, float, float, float, string>(
                            int.Parse(dst[0]),
                            float.Parse(dst[1]),
                            float.Parse(dst[2]),
                            float.Parse(dst[3]),
                            float.Parse(dst[4]),
                            bool.Parse(dst[5]).ToString().ToLower()
                        ));
                    }
                    catch (Exception)
                    {
                        throw new Exception($"WARP destination for {id} not valid.");
                    }
                }
                else if (entry.Key.StartsWith("MOUNT_"))
                {
                    var id = entry.Key.Split('_')[1];
                    mountTable.Add(id, int.Parse(entry.Value));
                }
                else if (entry.Key.StartsWith("ID_"))
                {
                    var obj = entry.Key.Split('_')[1];
                    unmappedObjTable.Add(obj, long.Parse(entry.Value));
                }
                else if (entry.Key.StartsWith("IGNORE_"))
                {
                    //processed later
                }
                else if (entry.Key.StartsWith("TODO_CLEAR"))
                {
                    if (fIsTodoChecked != null)
                    {
                        fIsTodoChecked.TodoList.Clear();
                    }
                }
                else if (entry.Key.StartsWith("TODO_REMOVE"))
                {
                    if (fIsTodoChecked != null)
                    {
                        fIsTodoChecked.TodoList.RemoveAt(int.Parse(entry.Value));
                    }
                }
                else if (entry.Key == "_AGGRESSIVE_BNPC_HACK") { }
                else if (entry.Key == "_ALLOW_EMPTY_ENTRY") { }
                else if (entry.Value != null)
                {
                    idTable.Add(entry.Key, new Tuple<string, int>(entry.Value, -1));
                }
            }
            useBranchGlobal = idTable.ContainsKey("_BRANCH");
            if (fIsAnnounce == null)
            {
                fIsAnnounce = LuaIsAnnounce.CreateFakeAnnounce(seqList);
            }
            List <EventEntry> allEntries = new List<EventEntry>();
            foreach (var seq in seqList)
            {
                if (paramTable.ContainsKey($"IGNORE_SEQ{seq.SeqNumber}"))
                {
                    seq.Ignore = true;
                }
                if (seq.SeqNumber == 255 && paramTable.ContainsKey("ALTERNATIVE_QUEST_COMPLETE"))
                {
                    seq.MarkForAlternativeQuestComplete = true;
                }
                allEntries.AddRange(seq.EntryList);
            }
            if (!AssignScenesNextStep(allEntries, sceneGroupList, idTable, 0, 0, allowEmptyEntry))
            {
                Console.WriteLine("[BuildSeqList]Build with id table failed.");
                if (!AssignScenesNextStep(allEntries, sceneGroupList, null, 0, 0, allowEmptyEntry))
                {
                    Console.WriteLine("[BuildSeqList]Build without id table failed.");
                    return -1;
                }
                return 2;
            }
            return 1;
        }

        public static bool PrintDebugInfo = false;

        private static bool AssignScenesNextStep(List<EventEntry> entryList, List<SceneGroup> sceneGroupList, Dictionary<string, Tuple<string, int>> idTable, int e, int g, bool allowEmptyEntry = false)
        {
            if (e >= entryList.Count)
                return g >= sceneGroupList.Count;
            if (g >= sceneGroupList.Count)
                return false;
            var entry = entryList[e];
            var tmpIdTable = idTable == null ? null : new Dictionary<string, Tuple<string, int>>(idTable);
            if (idTable != null && entry.TargetObject != null && idTable.ContainsKey($"_{entry.TargetObject.Name}"))
            {
                var entryFlag = idTable[$"_{entry.TargetObject.Name}"];
                if (entryFlag.Item1.Contains("I"))
                {
                    var flagOption = idTable[$"_{entry.TargetObject.Name}I"].Item1;
                    if (entry.Owner.SeqNumber == int.Parse(flagOption))
                    {
                        return AssignScenesNextStep(entryList, sceneGroupList, tmpIdTable, e + 1, g, allowEmptyEntry);
                    }
                }
            }
            if (entry.Owner.Ignore)
            {
                return AssignScenesNextStep(entryList, sceneGroupList, tmpIdTable, e + 1, g, allowEmptyEntry);
            }
            else if (allowEmptyEntry && entry.CanExistWithoutScene && !entry.IsPrefferedGroup(sceneGroupList[g]))
            {
                if (AssignScenesNextStep(entryList, sceneGroupList, tmpIdTable, e + 1, g, allowEmptyEntry))
                    return true;
            }
            int total = 0;
            tmpIdTable = idTable == null ? null : new Dictionary<string, Tuple<string, int>>(idTable);
            int flag = 0;
            int og = g;
        label1:
            while (g < sceneGroupList.Count)
            {
                if (PrintDebugInfo) Console.WriteLine($"Assigning: seq{entry.Owner.SeqNumber}, {entry} <- {sceneGroupList[g]}");
                int assigned = AssignNextScene(entry, sceneGroupList, g, tmpIdTable);
                if (assigned == 0)
                {
                    if (PrintDebugInfo) Console.WriteLine($"Failed.");
                    break;
                }
                total += assigned;
                entry.AssignedGroupCount++;
                if (entry.AssignedGroupCount >= entry.RequiredGroupCount)
                {
                    if (flag == 0 && (g + 1) < sceneGroupList.Count && entry.EntryScene.SceneList.Count < 2 && entry.IsPrefferedGroup(sceneGroupList[g + 1]))
                    {
                        var tmpIdTable2 = idTable == null ? null : new Dictionary<string, Tuple<string, int>>(tmpIdTable);
                        if (PrintDebugInfo) Console.WriteLine($"Assigning: seq{entry.Owner.SeqNumber}, {entry} <- {sceneGroupList[g + 1]}");
                        assigned = AssignNextScene(entry, sceneGroupList, g + 1, tmpIdTable);
                        if (assigned != 0)
                        {
                            flag = 1;
                            tmpIdTable = tmpIdTable2;
                            total += assigned;
                            entry.AssignedGroupCount++;
                            g++;
                        }
                        else
                            if (PrintDebugInfo) Console.WriteLine($"Failed.");
                    }
                    var tmpIdTable3 = idTable == null ? null : new Dictionary<string, Tuple<string, int>>(tmpIdTable);
                    if (AssignScenesNextStep(entryList, sceneGroupList, tmpIdTable3, e + 1, g + 1, allowEmptyEntry))
                        return true;
                    if (flag == 2)
                        break;
                }
                g++;
            }
            while (total > 0)
            {
                entry.EntryScene.SceneList.RemoveAt(entry.EntryScene.SceneList.Count - 1);
                total--;
            }
            entry.AssignedGroupCount = 0;
            if (flag == 1)
            {
                g = og;
                flag = 2;
                goto label1;
            }
            return false;
        }
        private static int AssignNextScene(EventEntry entry, List<SceneGroup> sceneGroupList, int i, Dictionary<string, Tuple<string, int>> idTable)
        {
            if (!entry.CanAddSceneGroup(sceneGroupList[i]))
                return 0;
            var group = sceneGroupList[i];
            if (!group.ContainsSceneType(LuaScene.SceneType.Snipe) && group.HasSubScenes && entry.EntryScene.SceneList.Count > 0)
                return 0;
            if (entry.TargetObject != null)
            {
                var groupId = group.Identity;
                string entryId = null;
                Tuple<string, int> tmp = null;
                var entryHasId = idTable != null ? idTable.TryGetValue(entry.TargetObject.Name, out tmp) : false;
                if (entryHasId)
                {
                    entryId = tmp.Item1;
                    var entryhasFlag = idTable.TryGetValue("_" + entry.TargetObject.Name, out tmp);
                    if (entryhasFlag)
                    {
                        string entryFlag = tmp.Item1;
                        if (entryFlag.Contains('S'))
                        {
                            if (group.Identity == "unknown" || group.Identity != entryId)
                                return 0;
                        }
                    }
                }
                if (!entryHasId)
                {
                    entryId = entry.EntryScene.Identity;
                    if (entryId != "unknown")
                        entryHasId = true;
                }
                if (idTable != null && groupId != "unknown" && !entryHasId)
                {
                    foreach (var kvp in idTable)
                    {
                        if (kvp.Value.Item1 == groupId && kvp.Value.Item2 == entry.Owner.SeqNumber)
                            return 0;
                    }
                }
                if (group.IsIdentityCompatible(entryId))
                {
                    if (!entryHasId)
                    {
                        if (entry.TargetObject.CanHaveIdentity(groupId))
                        {
                            if (idTable != null && groupId != "unknown")
                            {
                                idTable.Add(entry.TargetObject.Name, new Tuple<string, int>(groupId, entry.Owner.SeqNumber));
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    //Console.WriteLine($"Adding {group} to {entry}");
                    entry.EntryScene.SceneList.AddRange(group.SceneList);
                    return group.SceneList.Count;
                }
            }
            else if (entry.EntryScene.SceneList.Count < 3)
            {
                //Console.WriteLine($"Adding {group} to {entry}");
                entry.EntryScene.SceneList.AddRange(group.SceneList);
                return group.SceneList.Count;
            }
            return 0;
        }
        Dictionary<string, int> eventItemMaxStackTable = new Dictionary<string, int>();
        private void InitEventItems()
        {
            foreach (var scene in sceneList)
            {
                if (scene.Type == LuaScene.SceneType.NpcTrade && scene.ParamTable.ContainsKey("TradeItem"))
                {
                    var itemTable = scene.ParamTable["TradeItem"] as Dictionary<string, int>;
                    foreach (var entry in itemTable)
                    {
                        if (!eventItemMaxStackTable.ContainsKey(entry.Key))
                            eventItemMaxStackTable.Add(entry.Key, 1);
                        var currentStack = eventItemMaxStackTable[entry.Key];
                        eventItemMaxStackTable[entry.Key] = Math.Max(currentStack, entry.Value);
                    }
                }
            }
            if (fNpcTradeInfo != null)
            {
                foreach (var entry in fNpcTradeInfo.SeqToNpcTradeItemList)
                {
                    var npcTradeList = entry.Value;
                    foreach (var npcTradeInfo in npcTradeList)
                    {
                        foreach (var tradeItem in npcTradeInfo.TradeList)
                        {
                            var item = tradeItem.Item;
                            var amount = tradeItem.Amount;
                            if (!eventItemMaxStackTable.ContainsKey(item))
                                eventItemMaxStackTable.Add(item, 1);
                            var currentStack = eventItemMaxStackTable[item];
                            eventItemMaxStackTable[item] = Math.Max(currentStack, amount);
                        }
                    }
                }
            }
            if (fGetEventItem != null)
            {
                foreach (var seq in seqList)
                {
                    List<QuestVar> varList = new List<QuestVar>();
                    seq.EntryList.ForEach(e => { if (e.Var != null) { varList.Add(e.Var); } });
                    var eventItemList = fGetEventItem.SeqEventItems.ContainsKey(seq.SeqNumber) ? fGetEventItem.SeqEventItems[seq.SeqNumber] : null;
                    if (eventItemList != null)
                    {
                        foreach (var item in eventItemList)
                        {
                            if (eventItemMaxStackTable.ContainsKey(item.Item))
                            {
                                item.Amount = eventItemMaxStackTable[item.Item];
                            }
                            foreach (var v in varList)
                            {
                                if (item.QuestVar == v.Name)
                                {
                                    item.Amount = Math.Max(item.Amount, v.Value);
                                }
                            }
                        }
                    }
                }
            }
        }

        private void InitSeqList()
        {
            foreach (var seq in seqList)
            {
                seq.EntryList.Clear();
                if (fIsAnnounce != null && fIsAnnounce.SeqTargetConditionTable.TryGetValue(seq.SeqNumber, out var mapList))
                {
                    foreach (var map in mapList)
                    {
                        LuaIsAnnounce.ObjectNameToQuestFlagMap flag = null;
                        if (fIsAnnounce.SeqTargetFlagTable.ContainsKey(seq.SeqNumber))
                        {
                            flag = fIsAnnounce.SeqTargetFlagTable[seq.SeqNumber].FirstOrDefault(f => f.ObjectName == map.ActiveObject.Name);
                        }
                        seq.EntryList.Add(new EventEntry()
                        {
                            TargetObject = map.ActiveObject,
                            Var = map.QuestVar != null ? new QuestVar() { Name = map.QuestVar, Value = map.ConditionValue } : null,
                            Flag = flag != null ? new QuestFlag() { Flag = flag.Flag, Index = flag.Index, TargetValue = flag.TargetValue } : null,
                            Owner = seq
                        });
                    }
                }
                else
                {
                    seq.EntryList.Add(new EventEntry() { Owner = seq });
                }
            }
            seqList.Sort();
        }

        List<SceneGroup> sceneGroupList = new List<SceneGroup>();
        private void InitSceneGroupList()
        {
            sceneGroupList.Clear();
            var tmpList = sceneList.ToList();
            while (tmpList.Count > 0)
            {
                var scene = tmpList[0];
                SceneGroup nextGroup = new SceneGroup();
                nextGroup.SceneList.Add(scene);
                if (predefinedSceneBranchTable.ContainsKey(scene.SceneNumber))
                {
                    var branches = predefinedSceneBranchTable[scene.SceneNumber];
                    nextGroup.SceneList.Add(tmpList.First(s => s.SceneNumber == branches.Item1));
                    nextGroup.SceneList.Add(tmpList.First(s => s.SceneNumber == branches.Item2));
                }
                else
                {
                    if (tmpList.Count > 1 && (scene.Element & LuaScene.SceneElement.QuestOffer) > 0)
                    {
                        if ((scene.Element & LuaScene.SceneElement.QuestAccept) == 0)
                        {
                            var index = tmpList.FindIndex(s => (s.Element & LuaScene.SceneElement.QuestAccept) > 0);
                            for (int i = 1; i <= index; i++)
                            {
                                var sub = tmpList[i];
                                if (sub.Type != LuaScene.SceneType.Normal)
                                    throw new Exception($"[InitSceneGroupList]Scene{sub.SceneNumber} cannot be added as sub scene.");
                                nextGroup.SceneList.Add(sub);
                            }
                        }
                    }
                    else if (tmpList.Count > 1 && (scene.Element & LuaScene.SceneElement.QuestReward) > 0)
                    {
                        if ((scene.Element & LuaScene.SceneElement.QuestComplete) == 0)
                        {
                            var index = tmpList.FindIndex(s => (s.Element & LuaScene.SceneElement.QuestComplete) > 0);
                            for (int i = 1; i <= index; i++)
                            {
                                var sub = tmpList[i];
                                if (sub.Type != LuaScene.SceneType.Normal)
                                    throw new Exception($"[InitSceneGroupList]Scene{sub.SceneNumber} cannot be added as sub scene.");
                                nextGroup.SceneList.Add(sub);
                            }
                        }
                    }
                    else if (tmpList.Count > 1 && scene.Type == LuaScene.SceneType.NpcTrade)
                    {
                        var sub = tmpList[1];
                        if (sub.Type != LuaScene.SceneType.Normal)
                            throw new Exception($"[InitSceneGroupList]Scene{sub.SceneNumber} cannot be added as sub scene.");
                        nextGroup.SceneList.Add(sub);
                    }
                    else if (tmpList.Count > 1 && scene.Type == LuaScene.SceneType.Snipe)
                    {
                        var sub = tmpList[1];
                        if ((sub.Element & (LuaScene.SceneElement.CutScene | LuaScene.SceneElement.FadeIn)) > 0)
                            nextGroup.SceneList.Add(sub);
                    }
                    else if (tmpList.Count > 1 && scene.ShouldCastAction)
                    {
                        var sub = tmpList[1];
                        nextGroup.SceneList.Add(sub);
                    }
                }
                sceneGroupList.Add(nextGroup);
                foreach (var s in nextGroup.SceneList)
                {
                    tmpList.Remove(s);
                }
            }
            sceneGroupList.Sort();
        }

        int questNumber;
        List<Sequence> seqList = new List<Sequence>();
        Dictionary<string, int> constTable = new Dictionary<string, int>();
        Dictionary<int, Tuple<int, int>> predefinedSceneBranchTable = new Dictionary<int, Tuple<int, int>>();
        private void ProcessCppCode()
        {
            string cppSeqEnumHead = "enum Sequence : uint8_t";
            string cppConstHead = "static constexpr auto";
            string cppQuestNumberHead = $"    {questId}() : Sapphire::ScriptAPI::EventScript( ";
            string cppQuestNumberHeadThreePointOh = $"    {questId}() : Sapphire::ScriptAPI::QuestScript( ";

            int i = 0;
            while (i < inputCpp.Count)
            {
                var s = inputCpp[i];
                if (s.IndexOf(cppSeqEnumHead) >= 0)
                {
                    i += 2;
                    while (inputCpp[i].IndexOf("}") < 0)
                    {
                        var seqDef = inputCpp[i].Split('=');
                        if (seqDef.Length == 2 && seqDef[1].Length > 1 && seqDef[1][seqDef[1].Length - 1] == ',')
                        {
                            if (int.TryParse(seqDef[1].Substring(0, seqDef[1].Length - 1), out int seqValue))
                            {
                                seqList.Add(new Sequence(seqValue));
                            }
                        }
                        i++;
                    }
                    break;
                }
                i++;
            }
            while (i < inputCpp.Count)
            {
                var s = inputCpp[i];
                if (s == "  public:")
                    break;
                if (s.IndexOf(cppConstHead) >= 0)
                {
                    s = s.Replace(cppConstHead, "").Trim();
                    s = s.Substring(0, s.Length - 1);
                    var constDef = s.Split('=');
                    if (constDef.Length != 2)
                        throw new Exception("[ProcessCppCode]Invalid const.");
                    var key = constDef[0].Trim().ToUpper();
                    var value = int.Parse(constDef[1].Trim());
                    if (constTable.ContainsKey(key))
                    {
                        if (constTable[key] != value)
                        {
                            if (!key.StartsWith("LOCACTOR"))
                            {
                                throw new Exception("[ProcessCppCode]Const redefined with different value.");
                            }
                        }
                    }
                    else
                    {
                        constTable.Add(key, value);
                    }
                }
                i++;
            }
            while (i < inputCpp.Count)
            {
                var s = inputCpp[i];
                if (s.IndexOf(cppQuestNumberHead) >= 0)
                {
                    questNumber = int.Parse(s.GetStringBetween(cppQuestNumberHead, " )"));
                    break;
                }
                if (s.IndexOf(cppQuestNumberHeadThreePointOh) >= 0)
                {
                    questNumber = int.Parse(s.GetStringBetween(cppQuestNumberHeadThreePointOh, " )"));
                    break;
                }
                i++;
            }
            foreach (var sequence in seqList)
            {
                var seq = sequence.SeqNumber;
                int objNum = 0;
                var key = $"Seq{seq}Eobject{objNum}".ToUpper();
                while (constTable.ContainsKey(key))
                {
                    int sceneNum = constTable[key];
                    var keyOk = key + "EVENTACTIONOK";
                    var keyNo = key + "EVENTACTIONNO";

                    if (constTable.ContainsKey(keyOk) && constTable.ContainsKey(keyNo))
                    {
                        var sceneNumOk = constTable[keyOk];
                        var sceneNumNo = constTable[keyNo];
                        predefinedSceneBranchTable.Add(sceneNum, new Tuple<int, int>(sceneNumOk, sceneNumNo));
                    }

                    objNum++;
                    key = $"Seq{seq}Eobject{objNum}".ToUpper();
                }
            }
        }

        List<LuaScene> sceneList = new List<LuaScene>();
        LuaGetEventItem fGetEventItem;
        LuaIsAnnounce fIsAnnounce;
        LuaNpcTradeInfo fNpcTradeInfo;
        LuaIsTodoChecked fIsTodoChecked;
        private void ProcessLuaCode()
        {
            sceneList.Clear();
            string luaSceneHead = $"function {questId}.OnScene";
            string luaGetEventItemHead = $"function {questId}.GetEventItems";
            string luaIsTodoCheckedHead = $"function {questId}.IsTodoChecked";
            int i = 0;
            while (i < inputLua.Count)
            {
            label1:
                var s = inputLua[i];
                if (s == "end)()")
                    break;
                if (s.StartsWith(luaSceneHead))
                {
                    int sceneNum = int.Parse(s.Substring(luaSceneHead.Length, 5));
                    List<string> codeBlock = new List<string>();
                    codeBlock.Add(s);
                    i++;
                    if (inputLua[i] == "end")
                    {
                        sceneList.Add(LuaScene.ParseLuaCode(codeBlock, sceneNum));
                        goto label2;
                    }

                    while (i < inputLua.Count)
                    {
                        s = inputLua[i];
                        if (s == "end)()" || s.StartsWith("function"))
                        {
                            sceneList.Add(LuaScene.ParseLuaCode(codeBlock, sceneNum));
                            goto label1;
                        }
                        codeBlock.Add(s);
                        i++;
                    }
                }
                else if (s.StartsWith(luaGetEventItemHead))
                {
                    List<string> codeBlock = new List<string>();
                    codeBlock.Add(s);
                    i++;
                    while (i < inputLua.Count)
                    {
                        s = inputLua[i];
                        if (s == "end)()" || s.StartsWith("function"))
                        {
                            fGetEventItem = LuaGetEventItem.ParseLuaCode(codeBlock);
                            goto label1;
                        }
                        codeBlock.Add(s);
                        i++;
                    }
                }
                else if (s.StartsWith(luaIsTodoCheckedHead))
                {
                    List<string> codeBlock = new List<string>();
                    codeBlock.Add(s);
                    i++;
                    while (i < inputLua.Count)
                    {
                        s = inputLua[i];
                        if (s == "end)()" || s.StartsWith("function"))
                        {
                            fIsTodoChecked = LuaIsTodoChecked.ParseLuaCode(codeBlock);
                            goto label1;
                        }
                        codeBlock.Add(s);
                        i++;
                    }
                }
            label2:
                i++;
            }
            i += 2;
            if (!inputLua[i].StartsWith("local"))
                throw new Exception("Cannot find event funcions.");
            var localList = inputLua[i].Substring(5).ToVarList();
            if (localList.Count != 2)
                throw new Exception("Cannot find event funcions.");
            var varScript = localList[0];
            var varFuncPointer = localList[1];
            while (i < inputLua.Count)
            {
            label3:
                var s = inputLua[i];
                if (s == "end)()")
                    break;
                if (s.StartsWith($"function {varFuncPointer}("))
                {
                    List<string> codeBlock = new List<string>();
                    i++;
                    if (inputLua[i] == "end")
                    {
                        goto label4;
                    }
                    else
                        codeBlock.Add(s);
                    while (i < inputLua.Count)
                    {
                        s = inputLua[i];
                        if (s.StartsWith(varScript))
                        {
                            var eventName = s.GetStringBetween($"{varScript}.", $" = {varFuncPointer}");
                            if (eventName != null)
                            {
                                switch (eventName.ToLower())
                                {
                                    case "isannounce":
                                        {
                                            fIsAnnounce = LuaIsAnnounce.ParseLuaCode(codeBlock);
                                            break;
                                        }
                                    case "getnpctradeiteminfo":
                                        {
                                            fNpcTradeInfo = LuaNpcTradeInfo.ParseLuaCode(codeBlock);
                                            break;
                                        }
                                }
                            }
                            goto label3;
                        }
                        codeBlock.Add(s);
                        i++;
                    }
                }
            label4:
                i++;
            }
        }

        public Parser(string questId, string outputFolder, List<string> cpp, List<string> lua)
        {
            this.questId = questId;
            this.outputFolder = outputFolder;
            this.inputCpp = cpp;
            this.inputLua = lua;
        }
    }
}
