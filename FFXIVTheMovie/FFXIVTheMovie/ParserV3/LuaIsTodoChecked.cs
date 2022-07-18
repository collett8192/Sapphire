using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    public class LuaIsTodoChecked
    {
        public List<Tuple<int, string, int>> TodoList = new List<Tuple<int, string, int>>();
        public static LuaIsTodoChecked ParseLuaCode(List<string> codeBlock)
        {
            LuaIsTodoChecked result = new LuaIsTodoChecked();
            if (codeBlock.Count > 0)
            {
                var argList = codeBlock[0].ExtractFuncArgsFromLuaFuncDef();
                if (argList.Count != 3)
                    throw new Exception($"[LuaIsTodoChecked]Invalid arg list.");
                string varFramework = argList[0], varPlayer = argList[1], varTodoIndex = argList[2];
                int i = 0;
                while (i < codeBlock.Count)
                {
                    var s = codeBlock[i];
                    if (s.IndexOf($"if {varTodoIndex} == ") >= 0)
                    {
                        var index = int.Parse(s.GetStringBetween($"if {varTodoIndex} == ", " then"));
                        i++;
                        s = codeBlock[i];
                        if (s.IndexOf("return false") >= 0)
                        {
                            i++;
                            continue;
                        }
                        else if (s.IndexOf($"{varPlayer}:GetQuestU") >= 0)
                        {
                            var name = s.GetStringBetween(":GetQuest", "(");
                            int value;
                            if (s.IndexOf($"return {varPlayer}") >= 0)
                            {
                                value = int.Parse(s.Substring(s.Length - 2, 2));
                            }
                            else
                            {
                                var a = s.GetStringBetween("return", $"{varPlayer}").Substring(0, 3);
                                value = int.Parse(a);
                            }
                            result.TodoList.Add(new Tuple<int, string, int>(index, name, value));
                        }
                    }
                    i++;
                }
            }
            return result;
        }

        private LuaIsTodoChecked() { }
    }
}
