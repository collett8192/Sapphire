using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    public class LuaNpcTradeInfo
    {
        public static LuaNpcTradeInfo ParseLuaCode(List<string> codeBlock)
        {
            LuaNpcTradeInfo result = new LuaNpcTradeInfo();
            if (codeBlock.Count > 0)
            {
                var argList = codeBlock[0].ExtractFuncArgsFromLuaFuncDef();
                if (argList.Count != 4)
                    throw new Exception($"[LuaNpcTradeInfo]Invalid arg list.");
                string varFramework = argList[0], varSeq = argList[2], varTarget = argList[3];
                int i = 1;
                while (i < codeBlock.Count)
                {
                    var s = codeBlock[i];

                    if (s.IndexOf($"if {varSeq} == {varFramework}.SEQ_") >= 0)
                    {
                        var seqStr = s.GetStringBetween($"{varFramework}.SEQ_", " and");
                        bool twoLineFlag = false;
                        if (seqStr == null)
                        {
                            twoLineFlag = true;
                            seqStr = s.GetStringBetween($"{varFramework}.SEQ_", " then");
                        }
                        if (seqStr != null)
                        {
                            var seq = seqStr == "FINISH" ? 255 : int.Parse(seqStr);
                            if (twoLineFlag)
                            {
                                i++;
                                s = codeBlock[i];
                            }
                            var actor = s.GetStringBetween($"{varTarget} == {varFramework}.", " then");
                            if (actor == null)
                            {
                                continue;
                            }
                            var tradeList = new NpcTradeList();
                            tradeList.Actor = actor;
                            i++;
                            while (true)
                            {
                                if (!codeBlock[i].StartsWith("return") && codeBlock[i].IndexOf("({})[") >= 0)
                                {
                                    i++;
                                    while (codeBlock[i].StartsWith($"{varFramework}.ITEM"))
                                    {
                                        var item = codeBlock[i].GetStringBetween($"{varFramework}.", ",");
                                        var amount = int.Parse(codeBlock[i + 1].Substring(0, codeBlock[i + 1].Length - 1));
                                        //unknown bool
                                        tradeList.TradeList.Add(new TradeItem { Item = item, Amount = amount });
                                        i += 3;
                                    }
                                    while (codeBlock[i] == "0," || codeBlock[i] == "0" || codeBlock[i] == "}")
                                    {
                                        i++;
                                    }
                                }
                                else
                                    break;
                            }
                            if (!result.SeqToNpcTradeItemList.ContainsKey(seq))
                            {
                                result.SeqToNpcTradeItemList.Add(seq, new List<NpcTradeList>());
                            }
                            result.SeqToNpcTradeItemList[seq].Add(tradeList);
                        }
                    }

                    i++;
                }
            }
            return result;
        }
        public Dictionary<int, List<NpcTradeList>> SeqToNpcTradeItemList = new Dictionary<int, List<NpcTradeList>>();
        public class NpcTradeList
        {
            public string Actor;
            public List<TradeItem> TradeList = new List<TradeItem>();

            public override string ToString()
            {
                return $"TradeInfo: {Actor}({TradeList.Count})";
            }
        }

        public class TradeItem
        {
            public string Item;
            public int Amount;
        }

        private LuaNpcTradeInfo() { }
    }
}
