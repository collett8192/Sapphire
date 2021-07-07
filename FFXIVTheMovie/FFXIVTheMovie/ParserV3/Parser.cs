﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.Remoting.Activation;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    using static FFXIVTheMovie.ParserV3.Sequence;
    public class Parser
    {
        string questId;
        string outputFolder;
        List<string> inputCpp;
        List<string> inputLua;

        Dictionary<string, string> idHint = new Dictionary<string, string>();
        public void AddIdHint(string name, string id)
        {
            //can be object names like ACTOR1 or scenes written like SCENE_2
            idHint.Add(name, id);
        }

        public void GenerateQuestScript()
        {
            List<string> outputCpp = new List<string>();

            ProcessLuaCode();
            ProcessCppCode();
            InitSceneGroupList();
            InitSeqList();
            bool isSimpleParse = false;
            int buildResult = 0;
            if (fIsAnnounce == null)
            {
                isSimpleParse = true;
                if (!BuildSeqListSimple())
                    throw new Exception("Failed");
            }
            else
            {
                buildResult = BuildSeqList();
                if (buildResult < 0)
                {
                    isSimpleParse = true;
                    if (!BuildSeqListSimple())
                        throw new Exception("Failed");
                }
            }
            InitEventItems();
            BNpcHack(); // see comment inside

            //return;

            outputCpp.Add("// FFXIVTheMovie.ParserV3.2");
            if (isSimpleParse)
            {
                outputCpp.Add("// simple method used");
            }
            else if (buildResult != 1)
            {
                outputCpp.Add("// id table disabled");
            }
            else if (idHint.Count > 0)
            {
                outputCpp.Add("// id hint used:");
                foreach (var hint in idHint)
                {
                    if (hint.Value != null)
                    {
                        if (hint.Key[0] != '_')
                        {
                            outputCpp.Add($"//{hint.Key} = {hint.Value}");
                        }
                        else
                        {
                            outputCpp.Add($"//{hint.Key} SET!!");
                        }
                    }
                    else
                        outputCpp.Add($"//{hint.Key} REMOVED!!");
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
            outputCpp.Add($"class {questId} : public Sapphire::ScriptAPI::EventScript");
            outputCpp.Add("{");
            outputCpp.Add("public:");
            outputCpp.Add($"  {questId}() : Sapphire::ScriptAPI::EventScript( {questNumber} ){{}}; ");
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
            outputCpp.Add("private:");
            outputCpp.Add("  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )");
            outputCpp.Add("  {");
            outputCpp.Add("    switch( player.getQuestSeq( getId() ) )");
            outputCpp.Add("    {");
            foreach (var seq in seqList)
            {
                foreach (var entry in seq.EntryList)
                {
                    int i = 0;
                    while (entry.EntryScene.SceneList.Count > 1 && i < entry.EntryScene.SceneList.Count)
                    {
                        if (entry.EntryScene.SceneList[i].Element == LuaScene.SceneElement.None)
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

                    if (entry.TargetObject == null)
                    {
                        if (scene != null)
                        {
                            outputCpp.Add($"        {scene.SceneFunctionName}( player ); // {scene}");
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
                    else
                    {

                        if (entry.TargetObject is ActiveTerritory)
                        {
                            outputCpp.Add($"        if( type == 4 ) // {entry.TargetObject.Name} = {entry.EntryScene.Identity}");
                        }
                        else
                        {
                            var actor = constTable.ContainsKey(entry.TargetObject.Name) ? constTable[entry.TargetObject.Name].ToString() : "/*UNKNOWN*/1";
                            outputCpp.Add($"        if( param1 == {actor} || param2 == {actor} ) // {entry.TargetObject.Name} = {entry.EntryScene.Identity}");
                        }

                        outputCpp.Add("        {");
                        if (seq.SeqNumber > 0 && entry.Var != null)
                        {
                            outputCpp.Add($"          if( {entry.Var.ToCppExprConditionNotDone()} )");
                            outputCpp.Add("          {");
                            if (scene != null)
                            {
                                outputCpp.Add($"            {scene.SceneFunctionName}( player ); // {scene}");
                            }
                            else
                            {
                                outputCpp.Add($"            {entry.Var.ToCppExprOperation()};");
                                outputCpp.Add($"            checkProgressSeq{seq.SeqNumber}( player );");
                            }
                            if (scene2 != null)
                            {
                                outputCpp.Add($"            // +Callback {scene2}");
                            }
                            if (scene3 != null)
                            {
                                outputCpp.Add($"            // +Callback {scene3}");
                                if (scene4 != null)
                                {
                                    outputCpp.Add($"            // +Callback {scene4}");
                                }
                                outputCpp.Add("          }");
                                outputCpp.Add("          break;");
                            }
                            else
                            {
                                outputCpp.Add("          }");
                                outputCpp.Add("          break;");
                            }
                        }
                        else
                        {
                            if (scene != null)
                            {
                                outputCpp.Add($"          {scene.SceneFunctionName}( player ); // {scene}");
                            }
                            else
                            {
                                outputCpp.Add("          // empty entry");
                            }
                            if (scene2 != null)
                            {
                                outputCpp.Add($"          // +Callback {scene2}");
                            }
                            if (scene3 != null)
                            {
                                outputCpp.Add($"          // +Callback {scene3}");
                            }
                            if (scene4 != null)
                            {
                                outputCpp.Add($"          // +Callback {scene4}");
                            }
                            outputCpp.Add("          break;");
                        }
                        outputCpp.Add("        }");
                    }

                }
                outputCpp.Add("        break;");
                outputCpp.Add("      }");
            }
            outputCpp.Add("      default:");
            outputCpp.Add("      {");
            outputCpp.Add("        player.sendUrgent( \"Sequence {} not defined.\", player.getQuestSeq( getId() ) );");
            outputCpp.Add("        break;");
            outputCpp.Add("      }");
            outputCpp.Add("    }");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("public:");
            outputCpp.Add("  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();");
            outputCpp.Add("    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );");
            outputCpp.Add("    onProgress( player, actorId, actor, 0, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("  void onEmote( uint64_t actorId, uint32_t eventId, uint32_t emoteId, Entity::Player& player ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();");
            outputCpp.Add("    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );");
            outputCpp.Add("    onProgress( player, actorId, actor, 1, emoteId );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( player, npcId, 0, 2, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( player, param1, param1, 3, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("  void onEnterTerritory( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override");
            outputCpp.Add("  {");
            outputCpp.Add("    onProgress( player, param1, param2, 4, 0 );");
            outputCpp.Add("  }");
            outputCpp.Add("");
            outputCpp.Add("private:");
            for (int s = 0; s < seqList.Count - 1; s++)
            {
                var seq = seqList[s];
                var s2 = s + 1;
                var nextSeq = seqList[s2];
                while (s2 < seqList.Count - 1 && nextSeq.EntryList.Count == 1 && nextSeq.EntryList[0].EntryScene.SceneList.Count == 0)
                {
                    s2++;
                    nextSeq = seqList[s2];
                }
                var eventItemList = fGetEventItem != null ? (fGetEventItem.SeqEventItems.ContainsKey(seq.SeqNumber) ? fGetEventItem.SeqEventItems[seq.SeqNumber] : null) : null;
                var nextEventItemList = fGetEventItem != null ? (fGetEventItem.SeqEventItems.ContainsKey(nextSeq.SeqNumber) ? fGetEventItem.SeqEventItems[nextSeq.SeqNumber] : null) : null;
                var varList = new List<QuestVar>();
                seq.EntryList.ForEach(e => { if (e.Var != null && varList.SingleOrDefault(v => v.Name == e.Var.Name) == null) { varList.Add(e.Var); } });
                var nextVarList = new List<QuestVar>();
                nextSeq.EntryList.ForEach(e => { if (e.Var != null && nextVarList.SingleOrDefault(v => v.Name == e.Var.Name) == null) { nextVarList.Add(e.Var); } });
                
                outputCpp.Add($"  void checkProgressSeq{seq.SeqNumber}( Entity::Player& player )");
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

                    outputCpp.Add($"{space}{(hasIf ? "  " : "")}player.updateQuest( getId(), {nextSeq.SeqNumber} );");

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
                            outputCpp.Add($"  void {current.SceneFunctionName}( Entity::Player& player )");
                            outputCpp.Add("  {");
                            outputCpp.Add($"    player.sendDebug( \"{questId}:{questNumber} calling {current}\" );");
                            if (current.Element != LuaScene.SceneElement.None)
                            {
                                outputCpp.Add("    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )");
                                outputCpp.Add("    {");
                                bool hasIf = false;
                                if (current.Type == LuaScene.SceneType.NpcTrade ||
                                    ((current.Element & LuaScene.SceneElement.QuestReward) > 0) ||
                                    ((current.Element & LuaScene.SceneElement.QuestOffer) > 0))
                                {
                                    outputCpp.Add("      if( result.param1 > 0 && result.param2 == 1 )");
                                    outputCpp.Add("      {");
                                    hasIf = true;
                                }
                                if (!hasIf && current.Type == LuaScene.SceneType.MsqDungeon)
                                {
                                    outputCpp.Add("      if( result.param1 == 768 ) // cancel");
                                    outputCpp.Add("      {");
                                    if (s < seqList.Count - 1)
                                    {
                                        var nextSeq = seqList[s + 1];
                                        if (nextSeq.EntryList.Count > 0 && nextSeq.EntryList[0].EntryScene.SceneList.Count > 0)
                                        {
                                            if (nextSeq.EntryList[0].TargetObject == null || nextSeq.EntryList[0].TargetObject is ActiveTerritory)
                                            {
                                                outputCpp.Add("        //dungeon auto skip");
                                                outputCpp.Add($"        {nextSeq.EntryList[0].EntryScene.SceneList[0].SceneFunctionName}( player );");
                                                outputCpp.Add("      }");
                                                outputCpp.Add("      else");
                                                outputCpp.Add("      {");
                                                outputCpp.Add("        player.sendUrgent( \"Select anyone and hit cancel to progress.\" );");
                                            }
                                        }
                                    }
                                    hasIf = true;
                                }
                                if (!hasIf && (current.Element & LuaScene.SceneElement.YesNo) > 0)
                                {
                                    if ((current.Element & LuaScene.SceneElement.CanCancel) > 0)
                                    {
                                        outputCpp.Add("      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )");
                                        outputCpp.Add("      {");
                                        hasIf = true;
                                    }
                                    else if (scene2 != null && (scene2.Element & LuaScene.SceneElement.CutScene) > 0)
                                    {
                                        outputCpp.Add("      if( result.param1 != 50 )");
                                        outputCpp.Add("      {");
                                        hasIf = true;
                                    }
                                    else
                                    {
                                        outputCpp.Add("      if( result.param1 > 0 && result.param2 == 1 )");
                                        outputCpp.Add("      {");
                                        hasIf = true;
                                    }
                                }
                                if (!hasIf && !afterComplete && ((current.Element & LuaScene.SceneElement.Menu) > 0 || (current.Element & LuaScene.SceneElement.CanCancel) > 0 || current.Type == LuaScene.SceneType.Snipe))
                                {
                                    if (next == null || next.Type != LuaScene.SceneType.CardGame)
                                    {
                                        outputCpp.Add("      if( result.param1 == 512 )");
                                    }
                                    else
                                    {
                                        outputCpp.Add("      if( result.param1 > 0 && result.param2 == 1 )");
                                    }
                                    outputCpp.Add("      {");
                                    hasIf = true;
                                }

                                if (next != null)
                                {
                                    outputCpp.Add($"{(hasIf ? "  " : "")}      {next.SceneFunctionName}( player );");
                                }
                                else
                                {
                                    if (afterComplete)
                                    {
                                        outputCpp.Add($"{(hasIf ? "  " : "")}      if( player.giveQuestRewards( getId(), result.param3 ) )");
                                        outputCpp.Add($"{(hasIf ? "  " : "")}      {{");
                                        outputCpp.Add($"{(hasIf ? "  " : "")}        player.finishQuest( getId() );");
                                        if ((current.Element & LuaScene.SceneElement.AutoFadeIn) > 0)
                                        {
                                            outputCpp.Add($"{(hasIf ? "  " : "")}        player.sendDebug( \"Finished with AutoFadeIn scene, calling forceZoneing...\" );");
                                            outputCpp.Add($"{(hasIf ? "  " : "")}        player.eventFinish( getId(), 1 );");
                                            outputCpp.Add($"{(hasIf ? "  " : "")}        player.forceZoneing();");
                                        }
                                        outputCpp.Add($"{(hasIf ? "  " : "")}      }}");
                                    }
                                    else
                                    {
                                        if (s > 0 && entry.Var != null)
                                        {
                                            outputCpp.Add($"{(hasIf ? "  " : "")}      {entry.Var.ToCppExprOperation()};");
                                        }
                                        if (seq.SeqNumber != 255 && entry.ShouldCheckSeqProgress())
                                            outputCpp.Add($"{(hasIf ? "  " : "")}      checkProgressSeq{seq.SeqNumber}( player );");
                                        if ((current.Element & LuaScene.SceneElement.AutoFadeIn) > 0)
                                        {
                                            outputCpp.Add($"{(hasIf ? "  " : "")}      player.sendDebug( \"Finished with AutoFadeIn scene, calling forceZoneing...\" );");
                                            outputCpp.Add($"{(hasIf ? "  " : "")}      player.eventFinish( getId(), 1 );");
                                            outputCpp.Add($"{(hasIf ? "  " : "")}      player.forceZoneing();");
                                        }
                                    }
                                }

                                if (hasIf)
                                {
                                    outputCpp.Add("      }");
                                }
                                outputCpp.Add("    };");
                                string baseSceneFlag = current.Type == LuaScene.SceneType.Snipe ? "INVIS_ENPC" : null;
                                string extraSceneFlag = (current.Element & (LuaScene.SceneElement.CutScene | LuaScene.SceneElement.FadeIn)) > 0 ? "FADE_OUT | CONDITION_CUTSCENE | HIDE_UI" : null;
                                string fullSceneFlag = baseSceneFlag == null ? (extraSceneFlag == null ? "NONE" : extraSceneFlag) : (extraSceneFlag == null ? baseSceneFlag : $"{baseSceneFlag} | {extraSceneFlag}");
                                outputCpp.Add($"    player.playScene( getId(), {current.SceneNumber}, {fullSceneFlag}, callback );");
                            }
                            else
                            {
                                if (next != null)
                                {
                                    outputCpp.Add($"    {next.SceneFunctionName}( player );");
                                }
                                else
                                {
                                    if (s > 0 && entry.Var != null)
                                    {
                                        outputCpp.Add($"    {entry.Var.ToCppExprOperation()};");
                                    }
                                    if (seq.SeqNumber != 255 && entry.ShouldCheckSeqProgress())
                                        outputCpp.Add($"    checkProgressSeq{seq.SeqNumber}( player );");
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

        private void BNpcHack()
        {
            //since we are not spawning bnpcs, move its credit to another entry and hope it's the one that suppose to do the spawning.
            //if u want to implement the quest manually based on the generated code, do not run this method.
            foreach (var seq in seqList)
            {
                while (seq.ContainsSceneElement(LuaScene.SceneElement.PopBNpc))
                {
                    var enemyEntry = seq.EntryList.FirstOrDefault(e => e.TargetObject is ActiveEnemy && e.Var != null);
                    if (enemyEntry != null)
                    {
                        for (int i = 0; i < seq.EntryList.Count; i++)
                        {
                            var e = seq.EntryList[i];
                            if (e == enemyEntry)
                                break;
                            if (!(e.TargetObject is ActiveEnemy) && e.Var == null)
                            {
                                seq.EntryList[i].Var = enemyEntry.Var;
                                seq.EntryList[i].Var.ForceSetValue = true;
                                break;
                            }
                        }
                        enemyEntry.Var = null;
                    }
                    else
                        break;
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
            foreach (var hint in idHint)
            {
                if (hint.Key.StartsWith("SCENE_"))
                {
                    var sceneNum = int.Parse(hint.Key.Split('_')[1]);
                    foreach (var g in sceneGroupList)
                    {
                        var scene = g.SceneList.FirstOrDefault(s => s.SceneNumber == sceneNum);
                        if (scene != null)
                        {
                            if (hint.Value == null)
                            {
                                g.SceneList.Remove(scene);
                                if (g.SceneList.Count == 0)
                                    sceneGroupList.Remove(g);
                            }
                            else
                            {
                                scene.Identity = hint.Value;
                            }
                            break;
                        }
                    }
                }
                else if (hint.Value != null)
                {
                    idTable.Add(hint.Key, new Tuple<string, int>(hint.Value, -1));
                }
            }
            List <EventEntry> allEntries = new List<EventEntry>();
            foreach (var seq in seqList)
            {
                allEntries.AddRange(seq.EntryList);
            }
            if (!AssignScenesNextStep(allEntries, sceneGroupList, idTable, 0, 0))
            {
                Console.WriteLine("[BuildSeqList]Build with id table failed.");
                if (!AssignScenesNextStep(allEntries, sceneGroupList, null, 0, 0))
                {
                    Console.WriteLine("[BuildSeqList]Build without id table failed.");
                    return -1;
                }
                return 2;
            }
            return 1;
        }

        public static bool PrintDebugInfo = false;

        private static bool AssignScenesNextStep(List<EventEntry> entryList, List<SceneGroup> sceneGroupList, Dictionary<string, Tuple<string, int>> idTable, int e, int g)
        {
            if (e >= entryList.Count)
                return g >= sceneGroupList.Count;
            if (g >= sceneGroupList.Count)
                return false;
            var entry = entryList[e];
            if (PrintDebugInfo) Console.WriteLine($"Assign step: {entry}");
            if (entry.TargetObject != null && entry.TargetObject.Name == "ACTOR23")
            {
                //Debugger.Break();
            }
            var tmpIdTable = idTable == null ? null : new Dictionary<string, Tuple<string, int>>(idTable);
            if (entry.CanExistWithoutScene && !entry.IsPrefferedGroup(sceneGroupList[g]))
            {
                if (AssignScenesNextStep(entryList, sceneGroupList, tmpIdTable, e + 1, g))
                    return true;
            }
            int total = 0;
            tmpIdTable = idTable == null ? null : new Dictionary<string, Tuple<string, int>>(idTable);
            int flag = 0;
            int og = g;
        label1:
            while (g < sceneGroupList.Count)
            {
                int assigned = AssignNextScene(entry, sceneGroupList, g, tmpIdTable);
                if (assigned == 0)
                    break;
                total += assigned;
                entry.AssignedGroupCount++;
                if (flag == 0 && (g + 1) < sceneGroupList.Count && entry.EntryScene.SceneList.Count < 2 && entry.IsPrefferedGroup(sceneGroupList[g + 1]))
                {
                    var tmpIdTable2 = idTable == null ? null : new Dictionary<string, Tuple<string, int>>(tmpIdTable);
                    assigned = AssignNextScene(entry, sceneGroupList, g + 1, tmpIdTable);
                    if (assigned != 0)
                    {
                        flag = 1;
                        tmpIdTable = tmpIdTable2;
                        total += assigned;
                        entry.AssignedGroupCount++;
                        g++;
                    }
                }
                var tmpIdTable3 = idTable == null ? null : new Dictionary<string, Tuple<string, int>>(tmpIdTable);
                if (AssignScenesNextStep(entryList, sceneGroupList, tmpIdTable3, e + 1, g + 1))
                    return true;
                if (flag == 2)
                    break;
                g++;
            }
            while (total > 0)
            {
                entry.EntryScene.SceneList.RemoveAt(entry.EntryScene.SceneList.Count - 1);
                total--;
                entry.AssignedGroupCount--;
            }
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
                string entryFlag = "";
                Tuple<string, int> tmp = null;
                var entryHasId = idTable != null ? idTable.TryGetValue(entry.TargetObject.Name, out tmp) : false;
                var entryhasFlag = false;
                if (entryHasId)
                {
                    entryId = tmp.Item1;
                    entryhasFlag = idTable.TryGetValue("_" + entry.TargetObject.Name, out tmp);
                    if (entryhasFlag)
                    {
                        entryFlag = tmp.Item1;
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
                if (scene.Type == LuaScene.SceneType.NpcTrade && scene.TypeParam1 != null)
                {
                    var itemTable = scene.TypeParam1 as Dictionary<string, int>;
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
            if (fIsAnnounce == null)
            {
                Console.WriteLine("[InitSeqList]IsAnnounce not found!");
            }
            foreach (var seq in seqList)
            {
                if (fIsAnnounce != null && fIsAnnounce.SeqTargetConditionTable.TryGetValue(seq.SeqNumber, out var mapList))
                {
                    foreach (var map in mapList)
                    {
                        seq.EntryList.Add(new EventEntry()
                        {
                            TargetObject = map.ActiveObject,
                            Var = map.QuestVar != null ? new QuestVar() { Name = map.QuestVar, Value = map.ConditionValue } : null,
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
                }
                sceneGroupList.Add(nextGroup);
                foreach (var s in nextGroup.SceneList)
                {
                    tmpList.Remove(s);
                }
            }
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
                            throw new Exception("[ProcessCppCode]Const redefined with different value.");
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
                    var keyOk = key + "eventactionok";
                    var keyNo = key + "eventactionno";

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