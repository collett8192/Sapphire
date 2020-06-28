using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    public class LuaGetEventItem
    {
        public Dictionary<int, List<ItemToQuestVarMapping>> SeqEventItems = new Dictionary<int, List<ItemToQuestVarMapping>>();
        public static LuaGetEventItem ParseLuaCode(List<string> codeBlock)
        {
            LuaGetEventItem result = new LuaGetEventItem();
            if (codeBlock.Count > 0)
            {
                var argList = codeBlock[0].ExtractFuncArgsFromLuaFuncDef();
                if (argList.Count != 2)
                    throw new Exception($"[LuaGetEventItem]Invalid arg list.");
                string varFramework = argList[0], varPlayer = argList[1];
                int i = 0;
                int currentSeq = 0;
                while (i < codeBlock.Count)
                {
                    var s = codeBlock[i];
                    i++;
                    if (s.IndexOf($"if {varPlayer}:GetQuestSequence(") >= 0)
                    {
                        var seq = s.GetStringBetween($"{varFramework}.SEQ_", " then");
                        if (seq == "FINISH")
                            currentSeq = 255;
                        else
                            currentSeq = int.Parse(seq);
                    }
                    else if (s.StartsWith($"return {varFramework}."))
                    {
                        if (result.SeqEventItems.ContainsKey(currentSeq))
                        {
                            continue;
                        }
                        s = s.Substring(7);
                        var valueList = s.ToVarList();
                        if (valueList.Count % 3 != 0)
                            throw new Exception($"[LuaGetEventItem]Invalid event item list at seq{currentSeq}.");
                        var itemList = new List<ItemToQuestVarMapping>();
                        for (int p = 0; p < valueList.Count; p += 3)
                        {
                            var nextItem = valueList[p].GetStringBetween($"{varFramework}.", null);
                            var nextQuestVar = valueList[p + 1].GetStringBetween($"{varPlayer}:GetQuest", "(L");
                            //var unknownBoolean = bool.Parse(valueList[p + 2]);
                            itemList.Add(new ItemToQuestVarMapping() { Item = nextItem, QuestVar = nextQuestVar });
                        }
                        if (itemList.Count > 0)
                            result.SeqEventItems.Add(currentSeq, itemList);
                    }
                }
                if (result.SeqEventItems.Count == 0)
                {
                    //if nothing found, reparse using second pattern
                    i = 0;
                    currentSeq = 0;
                    while (i < codeBlock.Count)
                    {
                        var s = codeBlock[i];
                        i++;
                        if (s.Contains($"{varFramework}.SEQ_"))
                        {
                            var seq = s.GetStringBetween($"{varFramework}.SEQ_", s.EndsWith(" then") ? " then" : null);
                            if (seq == "FINISH")
                                currentSeq = 255;
                            else
                                currentSeq = int.Parse(seq);
                            if (codeBlock[i].StartsWith("elseif") || codeBlock[i] == "end")
                            {
                                continue;
                            }
                            i += 3;
                            if (i < codeBlock.Count && !result.SeqEventItems.ContainsKey(currentSeq))
                            {
                                s = codeBlock[i];
                                if (s.StartsWith("return") && s.IndexOf($"{varPlayer}:GetQuestUI") > 0)
                                {
                                    var item = codeBlock[i - 1].GetStringBetween($"{varFramework}.", null);
                                    var questVar = s.GetStringBetween($"{varPlayer}:GetQuest", "(");
                                    var itemList = new List<ItemToQuestVarMapping>();
                                    itemList.Add(new ItemToQuestVarMapping() { Item = item, QuestVar = questVar });
                                    result.SeqEventItems.Add(currentSeq, itemList);
                                    i++;
                                }
                                else if (s.StartsWith($"if {varPlayer}:GetQuestUI"))
                                {
                                    Console.WriteLine("[Warning]This quest uses event items in a way that is not supported by this parser. It can still work without issue, otherwise manual fix is requried.");
                                    i++;
                                    var itemList = new List<ItemToQuestVarMapping>();
                                    if (codeBlock[i].Contains($"{varFramework}.ITEM"))
                                    {
                                        var item = codeBlock[i].GetStringBetween($"{varFramework}.", null);
                                        i += 2;
                                        if (item != null && codeBlock[i] == "else" && codeBlock[i + 1].Contains($"{varFramework}.ITEM"))
                                        {
                                            i++;
                                            var questVar = codeBlock[i + 3].GetStringBetween($"{varPlayer}:GetQuest", "(");
                                            if (questVar != null)
                                            {
                                                itemList.Add(new ItemToQuestVarMapping() { Item = item, QuestVar = questVar });
                                            }
                                            i += 4;
                                        }
                                    }
                                    if (itemList.Count > 0)
                                    {
                                        result.SeqEventItems.Add(currentSeq, itemList);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (result.SeqEventItems.Count == 0)
                Console.WriteLine($"[LuaGetEventItem]No event item found.");
            return result;
        }

        public class ItemToQuestVarMapping
        {
            public string Item;
            public string QuestVar;
            public int Amount;

            public string ToCppExprUpdate()
            {
                return $"player.setQuest{QuestVar}( getId(), {(Amount == 0 ? 1 : Amount)} )";
            }

            public string ToCppExprClear()
            {
                return $"player.setQuest{QuestVar}( getId(), 0 )";
            }

            public override string ToString()
            {
                return $"{Item}:{QuestVar}={(Amount == 0 ? "?" : Amount.ToString())}";
            }
        }

        private LuaGetEventItem() { }
    }
}
