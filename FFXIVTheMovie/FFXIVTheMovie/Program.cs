using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace FFXIVTheMovie.ParserV3
{
    public static class Program
    {
#if NETCOREAPP
        static readonly string SAPPHIRE_SRC_FOLDER = @"..\..\..\..\..\src";
#else
        static readonly string SAPPHIRE_SRC_FOLDER = @"..\..\..\..\src";
#endif
        static readonly string PARSER_OUTPUT_FOLDER = Path.Combine(SAPPHIRE_SRC_FOLDER, "scripts", "quest", "the_movie_v3");

        static string QuestParseOutputFolder = @"C:\work\Sapphire\build\bin\tools\generated";
        static void Main(string[] args)
        {
            if (args.Length == 1)
            {
                QuestParseOutputFolder = args[0];
            }

            string questScriptFolder = Path.Combine(SAPPHIRE_SRC_FOLDER, "scripts", "quest");
            if (!Directory.Exists(questScriptFolder))
            {
                Console.WriteLine("SAPPHIRE_SRC_FOLDER is not setup correctly.");
                Console.ReadKey();
                return;
            }

            if (!File.Exists(Path.Combine(QuestParseOutputFolder, "ManWil200.cpp")))
            {
                Console.WriteLine("QuestParseOutputFolder is not setup correctly, either edit the source or pass the path in command line.");
                Console.ReadKey();
                return;
            }

            if (!Directory.Exists(PARSER_OUTPUT_FOLDER))
            {
                Console.WriteLine($"Output folder:\n  {Path.GetFullPath(PARSER_OUTPUT_FOLDER)}\ndoes not exist, enter y to create it, or enter anything else to exit.");
                if (Console.ReadKey().Key == ConsoleKey.Y)
                {
                    Directory.CreateDirectory(PARSER_OUTPUT_FOLDER);
                    if (!Directory.Exists(PARSER_OUTPUT_FOLDER))
                    {
                        throw new Exception("Failed to create folder.");
                    }
                }
                else
                    return;
            }

            List<string> list = new List<string>();
            //list.Add("GaiUsd203");

            if (list.Count == 0)
            {
                Console.WriteLine("Input quest id (XxxXxx000) to parse:");
                Console.WriteLine("(ALL for all non-implemented quests)");
                string id = Console.ReadLine();
                if (id.ToUpper() == "ALL")
                {
                    ParseV3();
                    return;
                }
                else
                {
                    list.Add(id);
                }
            }
            ManualMode = true;
            try
            {
                foreach (var id in list)
                {
                    (var a, var b) = ReadSingleQuest(id, QuestParseOutputFolder);
                    var p = new Parser(id, PARSER_OUTPUT_FOLDER, a, b);
                    foreach (var entry in QuestParamDatabase.GetQuestParam(id))
                    {
                        p.AddParam(entry.Key, entry.Value);
                    }
                    p.GenerateQuestScript();
                }
                Console.WriteLine("All Done.");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.ReadKey();
        }
        public static bool ManualMode { get; private set; } = false;
        static void ParseV3()
        {
            HashSet<string> implementedQuestIds = new HashSet<string>();
            string questScriptFolder = Path.Combine(SAPPHIRE_SRC_FOLDER, "scripts", "quest");

            AddAllScripts(new DirectoryInfo(questScriptFolder), implementedQuestIds);
            int parsed = 0, failed = 0;
            DirectoryInfo folder = new DirectoryInfo(QuestParseOutputFolder);
            foreach (FileInfo scriptFile in folder.GetFiles("*.cpp"))
            {
                string questId = Path.GetFileNameWithoutExtension(scriptFile.Name);
                if (implementedQuestIds.Contains(questId))
                    continue;

                //if (!questId.StartsWith("HeaVng")) continue;

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
                    !questId.StartsWith("GaiUsx") &&
                    !questId.StartsWith("Xxa") &&
                    !questId.StartsWith("HeaVna") &&
                    !questId.StartsWith("HeaVnb") &&
                    !questId.StartsWith("HeaVnc") &&
                    !questId.StartsWith("HeaVnd") &&
                    !questId.StartsWith("HeaVne") &&
                    !questId.StartsWith("HeaVnf") &&
                    !questId.StartsWith("HeaVng") &&
                    !questId.StartsWith("StmBda") &&
                    !questId.StartsWith("StmBdb") &&
                    !questId.StartsWith("StmBdc") &&
                    !questId.StartsWith("StmBdd") &&
                    !questId.StartsWith("StmBde") &&
                    !questId.StartsWith("StmBdf") &&
                    !questId.StartsWith("StmBdg") &&
                    !questId.StartsWith("LucKma") &&
                    !questId.StartsWith("LucKmb") &&
                    !questId.StartsWith("LucKmc") &&
                    !questId.StartsWith("LucKmd") &&
                    !questId.StartsWith("LucKme") &&
                    !questId.StartsWith("LucKmf") &&
                    !questId.StartsWith("LucKba") &&
                    !questId.StartsWith("LucKmg") &&
                    !questId.StartsWith("LucKmh") &&
                    !questId.StartsWith("LucKmi")

                    )
                    continue;
                Console.WriteLine($"processing {questId}...");
                (var cpp, var lua) = ReadSingleQuest(questId, QuestParseOutputFolder);
                try
                {
                    var p = new Parser(questId, PARSER_OUTPUT_FOLDER, cpp, lua);
                    foreach (var entry in QuestParamDatabase.GetQuestParam(questId))
                    {
                        p.AddParam(entry.Key, entry.Value);
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

        public static string GetStringBetween(this string str, string from, string to, int startIndex = 0)
        {
            int start = from == null ? startIndex : str.IndexOf(from, startIndex);
            if (start < startIndex)
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
                {
                    Console.WriteLine($"Too many local var expands: {code}");
                    return code;
                }
                flag = false;
                foreach (var entry in localVarTable)
                {
                    if (entry.Value != null)
                    {
                        while (code.Contains(entry.Key))
                        {
                            code = code.Replace(entry.Key, entry.Value);
                            if (entry.Value.Contains(entry.Key))
                                break;
                            flag = true;
                        }
                    }
                }
            }
            return code;
        }

    }
}
