using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie
{
    public static class Program
    {
        static readonly string SAPPHIRE_SRC_FOLDER = @"C:\work\Sapphire\src";
        static readonly string SAPPHIRE_QUEST_PARSE_OUTPUT_FOLDER = @"C:\work\Sapphire\build\bin\tools\generated";
        static void Main(string[] args)
        {
            ParseV3();
            return;
            List<string> list = new List<string>();
            list.Add("GaiUse610");
            foreach (var id in list)
            {
                (var a, var b) = ReadSingleQuest(id, @"C:\work\Sapphire\build\bin\tools\generated");
                var p = new ParserV3.Parser(id, @"C:\work\Sapphire\src\scripts\quest\the_movie_v3", a, b);
                foreach (var hint in GetIdHintForQuest(id))
                {
                    p.AddIdHint(hint.Key, hint.Value);
                }
                p.GenerateQuestScript();
            }
            Console.WriteLine("All Done.");
            Console.ReadKey();
        }

        static void ParseV3()
        {
            HashSet<string> implementedQuestIds = new HashSet<string>();
            string questScriptFolder = Path.Combine(SAPPHIRE_SRC_FOLDER, "scripts", "quest");
            string outputFolder = Path.Combine(questScriptFolder, "the_movie_v3");

            AddAllScripts(new DirectoryInfo(questScriptFolder), implementedQuestIds);
            int parsed = 0, failed = 0;
            DirectoryInfo folder = new DirectoryInfo(SAPPHIRE_QUEST_PARSE_OUTPUT_FOLDER);
            foreach (FileInfo scriptFile in folder.GetFiles("*.cpp"))
            {
                string questId = Path.GetFileNameWithoutExtension(scriptFile.Name);
                if (implementedQuestIds.Contains(questId))
                    continue;
                if (!questId.StartsWith("ManFst") &&
                    !questId.StartsWith("ManSea") &&
                    !questId.StartsWith("ManWil") &&
                    !questId.StartsWith("SubFst") &&
                    !questId.StartsWith("SubSea") &&
                    !questId.StartsWith("SubWil") &&
                    !questId.StartsWith("GaiUsa") &&
                    !questId.StartsWith("GaiUsb") &&
                    !questId.StartsWith("GaiUsc") &&
                    !questId.StartsWith("GaiUsd") &&
                    !questId.StartsWith("GaiUse") &&
                    !questId.StartsWith("GaiUsx")
                    )
                    continue;
                Console.WriteLine($"processing {questId}...");
                (var cpp, var lua) = ReadSingleQuest(questId, SAPPHIRE_QUEST_PARSE_OUTPUT_FOLDER);
                try
                {
                    var p = new ParserV3.Parser(questId, outputFolder, cpp, lua);
                    foreach (var hint in GetIdHintForQuest(questId))
                    {
                        p.AddIdHint(hint.Key, hint.Value);
                    }
                    p.GenerateQuestScript();
                    parsed++;
                }
                catch (Exception ex) 
                {
                    Console.WriteLine(ex.Message);
                    failed++;
                }
            }
            Console.WriteLine($"parsed: {parsed}, failed: {failed}");
            Console.ReadKey();
        }

        static Dictionary<string, string> GetIdHintForQuest(string questId)
        {
            var result = new Dictionary<string, string>();
            switch (questId)
            {
                //result.Add("", "");
                case "GaiUse610":
                    {
                        result.Add("ACTOR3", "TATARU_2");
                        result.Add("SCENE_9", "TATARU_2");
                        break;
                    }
                case "GaiUse609":
                    {
                        result.Add("SCENE_4", "THUBYRGEIM_2");
                        break;
                    }
                case "GaiUse611":
                    {
                        result.Add("SCENE_5", "SCIENTIST00423_2");
                        result.Add("SCENE_14", "SCIENTIST00423_3");
                        result.Add("SCENE_16", "SCIENTIST00423_4");
                        result.Add("SCENE_25", "SCIENTIST00423_5");
                        result.Add("SCENE_27", "SCIENTIST00423_6");
                        result.Add("SCENE_40", "SCIENTIST00423_7");
                        result.Add("SCENE_42", "SCIENTIST00423_8");
                        break;
                    }
                case "GaiUse606":
                    {
                        result.Add("ACTOR12", "ACTOR12");
                        result.Add("SCENE_50", "ACTOR12");
                        result.Add("ACTOR13", "null");
                        result.Add("ACTOR14", "null");
                        result.Add("ACTOR15", "null");
                        result.Add("ACTOR16", "null");
                        result.Add("ACTOR17", "null");
                        result.Add("ACTOR18", "null");
                        break;
                    }
                case "GaiUse506":
                    {
                        result.Add("ACTOR11", "YUYUHASE");
                        result.Add("ACTOR12", "null");
                        result.Add("ACTOR13", "null");
                        break;
                    }
                case "GaiUse412":
                    {
                        result.Add("ACTOR2", "SHINOBI00080");
                        result.Add("ACTOR4", "null");
                        result.Add("ACTOR5", "null");
                        result.Add("ACTOR7", "SHINOBI00080");
                        result.Add("ACTOR8", "null");
                        break;
                    }
                case "GaiUse411":
                    {
                        result.Add("ACTOR6", "ACTOR6");
                        result.Add("ACTOR7", "ACTOR7");
                        result.Add("ACTOR8", "ACTOR8");
                        result.Add("ACTOR9", "ACTOR9");
                        result.Add("SCENE_11", "ACTOR6");
                        result.Add("SCENE_12", "ACTOR6");
                        result.Add("SCENE_13", "ACTOR7");
                        result.Add("SCENE_14", "ACTOR7");
                        result.Add("SCENE_15", "ACTOR8");
                        result.Add("SCENE_16", "ACTOR8");
                        result.Add("SCENE_17", "ACTOR9");
                        result.Add("SCENE_18", "ACTOR9");
                        result.Add("SCENE_22", "ACTOR6");
                        result.Add("SCENE_23", "ACTOR7");
                        result.Add("SCENE_24", "ACTOR8");
                        result.Add("SCENE_25", "ACTOR9");
                        break;
                    }
                case "GaiUse407":
                    {
                        result.Add("ACTOR0", "DRILLEMONT");
                        result.Add("ACTOR1", "null");
                        result.Add("ACTOR2", "null");
                        result.Add("ACTOR3", "null");
                        result.Add("ACTOR4", "null");
                        break;
                    }
                case "GaiUse319":
                    {
                        result.Add("SCENE_39", "MINFILIA");
                        break;
                    }
                case "GaiUse314":
                    {
                        result.Add("SCENE_3", "TATARU");
                        break;
                    }
                case "GaiUse303":
                    {
                        result.Add("ACTOR1", "REFUGEE01444");
                        result.Add("ACTOR2", "null");
                        result.Add("ACTOR3", "null");
                        result.Add("ACTOR4", "null");
                        result.Add("ACTOR5", "null");
                        break;
                    }
                case "GaiUse215":
                    {
                        result.Add("ACTOR1", "KOKKAGUNNSOU01359");
                        result.Add("ACTOR2", "null");
                        result.Add("ACTOR3", "null");
                        result.Add("ACTOR4", "null");
                        result.Add("ACTOR5", "null");
                        result.Add("ACTOR6", "YSHTOLA");
                        break;
                    }
            }
            return result;
        }
        //helper static methods
        static void AddAllScripts(DirectoryInfo folder, HashSet<string> questIds)
        {
            foreach (var f in folder.GetFileSystemInfos())
            {
                if (f.Name == "the_movie_v3")
                    continue;
                if (f is DirectoryInfo sub)
                {
                    AddAllScripts(sub, questIds);
                }
                else if (f is FileInfo file)
                {
                    questIds.Add(Path.GetFileNameWithoutExtension(file.Name));
                }
            }
        }

        public static (List<string> cpp, List<string> lua) ReadSingleQuest(string questId, string sapphireQuestParseGeneratedFolder)
        {
            List<string> cpp = new List<string>(), lua = new List<string>();
            string cppFile = Path.Combine(sapphireQuestParseGeneratedFolder, $"{questId}.cpp");
            DirectoryInfo folder = new DirectoryInfo(sapphireQuestParseGeneratedFolder);
            var tmp = folder.GetFiles($"{questId}_*.lua");
            if (tmp.Length == 1)
            {
                string luaFile = tmp[0].FullName;
                using (StreamReader reader = new StreamReader(cppFile))
                {
                    var line = reader.ReadLine();
                    while (line != null)
                    {
                        cpp.Add(line);
                        line = reader.ReadLine();
                    }
                }
                using (StreamReader reader = new StreamReader(luaFile))
                {
                    var line = reader.ReadLine();
                    while (line != null)
                    {
                        lua.Add(line.Trim());
                        line = reader.ReadLine();
                    }
                }
            }
            else
            {
                throw new IOException();
            }
            return (cpp, lua);
        }

        public static string GetStringBetween(this string str, string from, string to)
        {
            int start = from == null ? 0 : str.IndexOf(from);
            if (start < 0)
                return null;
            int offset = from == null ? 0 : from.Length;
            string remaining = str.Substring(start + offset);
            int end = to == null ? start + offset + remaining.Length : start + offset + remaining.IndexOf(to);
            if (end < start + offset)
                return null;
            return str.Substring(start + offset, end - start - offset);
        }

        public static List<string> ToVarList(this string line)
        {
            List<string> result = new List<string>();
            (var nextArg, var remain) = line.ExtractFirstVar();
            while (nextArg != null)
            {
                result.Add(nextArg);
                if (remain == null)
                    break;
                (nextArg, remain) = remain.ExtractFirstVar();
            }
            return result;
        }

        public static (string nextArg, string remain) ExtractFirstVar(this string line)
        {
            StringBuilder builder = new StringBuilder();
            int index = 0;
            int depth = 0;
            while (index < line.Length)
            {
                var c = line[index];
                if (c == '(')
                    depth++;
                else if (c == ')')
                    depth--;
                if (depth > 0)
                    builder.Append(c);
                else
                {
                    if (c == ',')
                    {
                        index++;
                        break;
                    }
                    else if (c != ' ')
                        builder.Append(c);
                }
                index++;
            }
            var result = builder.ToString();
            if (result.Length > 0)
                return (result, index == line.Length ? null : line.Substring(index));
            else
                return (null, line);
        }

        public static List<string> ExtractFuncArgsFromLuaFuncDef(this string code)
        {
            List<string> result = new List<string>();
            var argDef = code.GetStringBetween("(", ")");
            if (argDef != null)
                result.AddRange(argDef.Split(','));
            for (int i = 0; i < result.Count; i++)
            {
                result[i] = result[i].Trim();
            }
            return result;
        }

        public static string ExpandLocalVar(this string code, Dictionary<string, string> localVarTable)
        {
            if (localVarTable == null)
                return code;
            bool flag = true;
            int depth = 0;
            while (flag)
            {
                depth++;
                if (depth > 5)
                    throw new Exception("Too many local var expands.");
                flag = false;
                foreach (var entry in localVarTable)
                {
                    if (entry.Value != null)
                    {
                        while (code.Contains(entry.Key))
                        {
                            code = code.Replace(entry.Key, entry.Value);
                            flag = true;
                        }
                    }
                }
            }
            return code;
        }

    }
}
