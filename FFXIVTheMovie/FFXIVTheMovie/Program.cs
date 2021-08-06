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

            //debug code below
            List<string> list = new List<string>();
            list.Add("SubCts999");
            foreach (var id in list)
            {
                (var a, var b) = ReadSingleQuest(id, SAPPHIRE_QUEST_PARSE_OUTPUT_FOLDER);
                var p = new ParserV3.Parser(id, Path.Combine(SAPPHIRE_SRC_FOLDER, "scripts", "quest", "the_movie_v3"), a, b);
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
                //add or remove any quest prefix
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
                //id hint used to parse certain quests, do not modify them.
                case "SubCts999":
                    {
                        result.Add("ACTOR1", "CEREMONYSHOP01578");
                        result.Add("_ACTOR1", "S");
                        result.Add("SCENE_100", null);
                        break;
                    }
                case "LucKmh108":
                    {
                        result.Add("SCENE_9", "URIANGER");
                        break;
                    }
                case "LucKmg103":
                    {
                        result.Add("SCENE_14", "VOYNE");
                        result.Add("SCENE_15", "VOYNE");
                        result.Add("SCENE_16", "VOYNE");
                        result.Add("SCENE_17", "a11");
                        result.Add("SCENE_18", "a11");
                        result.Add("SCENE_19", "a11");
                        result.Add("SCENE_20", "PAWNIL");
                        result.Add("SCENE_21", "PAWNIL");
                        result.Add("SCENE_22", "PAWNIL");
                        break;
                    }
                case "LucKmg101":
                    {
                        result.Add("SCENE_3", "FLHAMINN");
                        break;
                    }
                case "LucKba251":
                    {
                        result.Add("ACTOR1", "GIOTT");
                        result.Add("_ACTOR1", "S");
                        break;
                    }
                case "LucKba241":
                    {
                        result.Add("SCENE_0", "SEQ0");
                        result.Add("SCENE_1", "SEQ0");
                        result.Add("SCENE_2", "SEQ1");
                        result.Add("ACTOR2", "GIOTT");
                        result.Add("SCENE_3", "GIOTT");
                        result.Add("SCENE_4", "GIOTT");
                        result.Add("ACTOR3", "A3");
                        break;
                    }
                case "LucKba231":
                    {
                        result.Add("ACTOR2", "GIOTT");
                        result.Add("_ACTOR2", "S");
                        result.Add("ACTOR3", "GIOTT");
                        result.Add("_ACTOR3", "S");
                        break;
                    }
                case "LucKba221":
                    {
                        result.Add("SCENE_13", "A13");
                        result.Add("SCENE_14", "A13");
                        result.Add("ACTOR3", "A13");
                        break;
                    }
                case "LucKba211":
                    {
                        result.Add("ACTOR2", "GIOTT");
                        result.Add("_ACTOR2", "S");
                        result.Add("ACTOR3", "GIOTT");
                        result.Add("_ACTOR3", "S");
                        result.Add("SCENE_16", "GIOTT");
                        result.Add("SCENE_17", "GIOTT");
                        result.Add("ACTOR4", "A4");
                        break;
                    }
                case "LucKmf111":
                    {
                        result.Add("SCENE_46", "TATARU");
                        result.Add("SCENE_32", "A14");
                        result.Add("SCENE_33", "A14");
                        result.Add("SCENE_34", "A14");
                        result.Add("SCENE_35", "dummyt");
                        break;
                    }
                case "LucKmf110":
                    {
                        result.Add("SCENE_6", "dummye0");
                        result.Add("ACTOR2", "OFFICIALA03653");
                        result.Add("_ACTOR2", "S");
                        result.Add("ACTOR3", "AMAUROTADMINISTRATOR");
                        result.Add("_ACTOR3", "S");
                        break;
                    }
                case "LucKmf108":
                    {
                        result.Add("SCENE_3", "dummy_seq1");
                        result.Add("SCENE_4", "dummy_seq1");
                        break;
                    }
                case "LucKba101":
                    {
                        result.Add("ACTOR2", "GRANSON_SEQ2");
                        result.Add("_ACTOR2", "S");
                        result.Add("SCENE_9", "GRANSON_SEQ2");
                        result.Add("ACTOR3", "GRANSON_SEQ3");
                        result.Add("_ACTOR3", "S");
                        result.Add("SCENE_15", "GRANSON_SEQ3");
                        break;
                    }
                case "LucKmf106":
                    {
                        result.Add("SCENE_3", "dummye0");
                        result.Add("SCENE_4", "dummye0");
                        result.Add("SCENE_5", "dummye1");
                        result.Add("SCENE_6", "dummye1");
                        result.Add("SCENE_9", "dummye2");
                        result.Add("SCENE_10", "dummye2");
                        break;
                    }
                case "LucKmf105":
                    {
                        result.Add("SCENE_7", "A6");
                        result.Add("SCENE_8", "A6");
                        break;
                    }
                case "LucKmf103":
                    {
                        result.Add("SCENE_3", "CRYSTALGATEKEEPER");
                        break;
                    }
                case "LucKme106":
                    {
                        result.Add("ACTOR1", "ALPHINAUD");
                        result.Add("_ACTOR1", "S");
                        break;
                    }
                case "LucKme105":
                    {
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("SCENE_11", "dummye0");
                        result.Add("SCENE_12", "dummye0");
                        break;
                    }
                case "LucKmd112":
                    {
                        result.Add("ACTOR2", "GUTHJON");
                        result.Add("_ACTOR2", "S");
                        result.Add("SCENE_86", "GUTHJON");
                        break;
                    }
                case "LucKmc115":
                    {
                        result.Add("EOBJECT2", "dummye2");
                        result.Add("SCENE_12", "dummye2");
                        result.Add("SCENE_13", "dummye2");
                        result.Add("SCENE_14", "dummye2");
                        result.Add("EOBJECT1", "dummye1");
                        result.Add("SCENE_15", "dummye1");
                        result.Add("SCENE_16", "dummye1");
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("SCENE_17", "dummye0");
                        result.Add("SCENE_18", "dummye0");
                        break;
                    }
                case "LucKmb119":
                    {
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("SCENE_3", "dummye0");
                        break;
                    }
                case "LucKmb112":
                    {
                        result.Add("EVENTRANGE1", "dummyr1");
                        result.Add("SCENE_14", "dummyr1");
                        result.Add("SCENE_15", "dummyr1");
                        break;
                    }
                case "LucKmb111":
                    {
                        result.Add("SCENE_8", "dummyBOSSOFFUATH");
                        break;
                    }
                case "SubGsc001":
                    {
                        result.Add("ACTOR1", "dummy1");
                        result.Add("SCENE_2", "dummy1");
                        result.Add("SCENE_5", "ELYENORA");
                        break;
                    }
                case "LucKmb109":
                    {
                        result.Add("SCENE_2", null);
                        result.Add("SCENE_8", null);
                        result.Add("SCENE_14", null);
                        result.Add("SCENE_3", "dummyFEOUL");
                        result.Add("SCENE_9", "dummyFEOUL");
                        result.Add("SCENE_15", "dummyFEOUL");
                        break;
                    }
                case "LucKmb105":
                    {
                        result.Add("SCENE_10", "dummye0");
                        result.Add("SCENE_12", "dummye1");
                        result.Add("SCENE_14", "dummye2");
                        result.Add("SCENE_21", "THANCRED");
                        break;
                    }
                case "LucKma305":
                    {
                        result.Add("SCENE_10", "dummye3");
                        result.Add("SCENE_14", "dummye5");
                        result.Add("SCENE_18", "dummye7");
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("EOBJECT1", "dummye1");
                        result.Add("EOBJECT2", "dummye2");
                        result.Add("EOBJECT3", "dummye3");
                        result.Add("EOBJECT4", "dummye4");
                        result.Add("EOBJECT5", "dummye5");
                        result.Add("EOBJECT6", "dummye6");
                        result.Add("EOBJECT7", "dummye7");
                        break;
                    }
                case "LucKma304":
                    {
                        result.Add("SCENE_17", "dummye1");
                        result.Add("SCENE_19", "dummye2");
                        result.Add("ENEMY1", "dummye1");
                        result.Add("ENEMY2", "dummye2");
                        break;
                    }
                case "LucKma303":
                    {
                        result.Add("SCENE_3", "dummye0");
                        result.Add("SCENE_5", "dummye1");
                        result.Add("SCENE_7", "dummye2");
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("EOBJECT1", "dummye1");
                        result.Add("EOBJECT2", "dummye2");
                        break;
                    }
                case "LucKma301":
                    {
                        result.Add("ACTOR6", "CASSARD");
                        result.Add("SCENE_6", "CASSARD");
                        result.Add("SCENE_22", "dummye0");
                        result.Add("EOBJECT0", "dummye0");
                        break;
                    }
                case "LucKma207":
                    {
                        result.Add("SCENE_6", "card1");
                        result.Add("SCENE_7", "card1");
                        result.Add("SCENE_8", "card2");
                        result.Add("SCENE_9", "card2");
                        result.Add("SCENE_10", "card2");
                        result.Add("ACTOR4", "actor4");
                        result.Add("SCENE_12", "actor4");
                        break;
                    }
                case "LucKma206":
                    {
                        result.Add("SCENE_6", "actor2");
                        result.Add("SCENE_7", "actor3");
                        break;
                    }
                case "LucKma204":
                    {
                        result.Add("ACTOR5", "ALPHINAUD");
                        break;
                    }
                case "LucKma203":
                    {
                        result.Add("SCENE_15", "dummye0");
                        result.Add("ACTOR4", "ALPHINAUD");
                        break;
                    }
                case "GaiUsd601":
                    {
                        result.Add("SCENE_3", "WEDGE");
                        break;
                    }
                case "StmBdg102":
                    {
                        result.Add("SCENE_3", "RAUBAHN");
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("SCENE_6", "dummyt0");
                        break;
                    }
                case "StmBdf105":
                    {
                        result.Add("ACROT0", "LYSE");
                        result.Add("SCENE_2", "LYSE");
                        result.Add("ACTOR1", "outter_gate_keeper_before_quest");
                        result.Add("SCENE_3", "outter_gate_keeper_before_quest");
                        result.Add("ACTOR3", "RESISTANCEGATEKEEPER");
                        result.Add("SCENE_13", "HOARYBOULDER");
                        break;
                    }
                case "StmBdf103":
                    {
                        result.Add("SCENE_15", "HIEN");
                        result.Add("ACTOR11", "TANSUI2");
                        result.Add("SCENE_12", "TANSUI2");
                        result.Add("SCENE_28", "TANSUI2");
                        result.Add("SCENE_36", "TANSUI2");
                        result.Add("ACTOR12", "CIRINA2");
                        result.Add("SCENE_13", "CIRINA2");
                        result.Add("SCENE_29", "CIRINA2");
                        result.Add("SCENE_37", "CIRINA2");
                        break;
                    }
                case "StmBde107":
                    {
                        result.Add("SCENE_2", "ALISAIE");
                        break;
                    }
                case "StmBdc108":
                    {
                        result.Add("ACTOR4", "actor4");
                        result.Add("SCENE_23", "dummyt0");
                        result.Add("SCENE_24", "dummyt0");
                        break;
                    }
                case "StmBdc104":
                    {
                        result.Add("SCENE_27", "RESISTANCE03025");
                        break;
                    }
                case "StmBdc101":
                    {
                        result.Add("SCENE_5", "dummyr0");
                        result.Add("SCENE_6", "dummyr0");
                        break;
                    }
                case "StmBdb104":
                    {
                        result.Add("SCENE_4", "LYSE");
                        break;
                    }
                case "StmBda705":
                    {
                        result.Add("SCENE_20", "actor5");
                        result.Add("SCENE_28", "HAKURO");
                        break;
                    }
                case "StmBda502":
                    {
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("EOBJECT1", "dummye1");
                        result.Add("SCENE_8", "dummye0");
                        result.Add("SCENE_13", "dummye1");
                        break;
                    }
                case "StmBda414":
                    {
                        result.Add("EVENTRANGE0", "r0");
                        result.Add("SCENE_3", "r0");
                        result.Add("SCENE_4", "r0");
                        result.Add("SCENE_5", "r0");
                        break;
                    }
                case "StmBda411":
                    {
                        result.Add("ACTOR6", "sheep1");
                        result.Add("ACTOR7", "sheep2");
                        result.Add("ACTOR8", "sheep3");
                        result.Add("ACTOR9", "sheep4");
                        result.Add("SCENE_8", "sheep1");
                        result.Add("SCENE_10", "sheep2");
                        result.Add("SCENE_12", "sheep3");
                        result.Add("SCENE_14", "sheep4");
                        break;
                    }
                case "StmBda407":
                    {
                        result.Add("ACTOR5", "CIRINA_3");
                        result.Add("ACTOR6", "CIRINA_2");
                        result.Add("ACTOR7", "LYSE");
                        result.Add("ACTOR10", "dead1");
                        result.Add("ACTOR11", "dead2");
                        result.Add("ACTOR12", "dead3");
                        result.Add("SCENE_7", "CIRINA_3");
                        result.Add("SCENE_8", "CIRINA_2");
                        result.Add("SCENE_18", "CIRINA_2");
                        result.Add("SCENE_24", "CIRINA_2");
                        result.Add("SCENE_34", "CIRINA_2");
                        result.Add("SCENE_41", "CIRINA_2");
                        break;
                    }
                case "StmBda405":
                    {
                        result.Add("ENEMY10", "dummye10");
                        result.Add("ENEMY11", "dummye11");
                        result.Add("SCENE_40", "dummye10");
                        result.Add("SCENE_42", "dummye11");
                        break;
                    }
                case "StmBda320":
                    {
                        result.Add("ACTOR4", "BIGSOLDIER02496");
                        result.Add("ACTOR5", "SMALLSOLDIER02496");
                        result.Add("ACTOR6", "MIDDLESOLDIER02496");
                        result.Add("SCENE_16", "BIGSOLDIER02496");
                        result.Add("SCENE_19", "SMALLSOLDIER02496");
                        result.Add("SCENE_22", "MIDDLESOLDIER02496");
                        break;
                    }
                case "StmBda312":
                    {
                        result.Add("EVENTRANGE1", "range1");
                        result.Add("SCENE_10", "range1");
                        result.Add("ACTOR5", "LYSE");
                        result.Add("ACTOR6", "dummy6");
                        result.Add("ACTOR7", "dummy7");
                        break;
                    }
                case "StmBda113":
                    {
                        result.Add("ACTOR3", "RAUBAHN");
                        result.Add("ACTOR4", "ALISAIE");
                        break;
                    }
                case "StmBda112":
                    {
                        result.Add("SCENE_5", "RAUBAHN");
                        break;
                    }
                case "StmBda125":
                    {
                        result.Add("SCENE_4", "MEFFRID");
                        break;
                    }
                case "StmBda124":
                    {
                        result.Add("ENEMY2", "enemy2");
                        result.Add("ENEMY3", "enemy3");
                        result.Add("ENEMY4", "enemy4");
                        result.Add("SCENE_28", "enemy2");
                        result.Add("SCENE_29", "enemy3");
                        result.Add("SCENE_30", "enemy4");
                        result.Add("ACTOR3", "dummy3");
                        break;
                    }
                case "HeaVng101":
                    {
                        result.Add("SCENE_2", "ALISAIE");
                        break;
                    }
                case "HeaVnf104":
                    {
                        result.Add("SCENE_22", "ALPHINAUD");
                        break;
                    }
                case "HeaVnf102":
                    {
                        result.Add("SCENE_3", "dummy0");
                        result.Add("SCENE_7", "AYMERIC");
                        break;
                    }
                case "HeaVnf101":
                    {
                        result.Add("SCENE_2", "TATARU");
                        result.Add("SCENE_4", "dummy0");
                        break;
                    }
                case "HeaVnd106":
                    {
                        result.Add("SCENE_9", "ALPHINAUD");
                        break;
                    }
                case "HeaVnc111":
                    {
                        result.Add("SCENE_2", "dummy");
                        result.Add("SCENE_3", "dummy");
                        result.Add("SCENE_4", "dummy2");
                        result.Add("SCENE_6", "ALPHINAUD");
                        break;
                    }
                case "HeaVna707":
                    {
                        result.Add("ENEMY0", "dummy0");
                        result.Add("ENEMY1", "dummy1");
                        result.Add("ENEMY2", "dummy2");
                        result.Add("ENEMY3", "dummy3");
                        result.Add("ENEMY4", "dummy4");
                        result.Add("ENEMY5", "dummy5");
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("SCENE_3", "dummy0");
                        result.Add("SCENE_4", "dummy1");
                        result.Add("SCENE_5", "dummy2");
                        result.Add("SCENE_6", "dummy3");
                        result.Add("SCENE_7", "dummy4");
                        result.Add("SCENE_8", "dummy5");
                        result.Add("SCENE_9", "dummye0");
                        break;
                    }
                case "HeaVna705":
                    {
                        result.Add("SCENE_3", "ESTINIEN");
                        result.Add("SCENE_7", "dummy0");
                        result.Add("SCENE_8", "dummy1");
                        result.Add("SCENE_9", "dummy2");
                        result.Add("SCENE_10", "dummy3");
                        result.Add("SCENE_11", "dummy4");
                        result.Add("SCENE_12", "dummy5");
                        result.Add("SCENE_13", "dummy6");
                        result.Add("SCENE_14", "dummye0");
                        result.Add("ENEMY0", "dummy0");
                        result.Add("ENEMY1", "dummy1");
                        result.Add("ENEMY2", "dummy2");
                        result.Add("ENEMY3", "dummy3");
                        result.Add("ENEMY4", "dummy4");
                        result.Add("ENEMY5", "dummy5");
                        result.Add("ENEMY6", "dummy6");
                        result.Add("EOBJECT0", "dummye0");
                        break;
                    }
                case "HeaVna704":
                    {
                        result.Add("SCENE_35", "dummy");
                        result.Add("SCENE_36", "dummy");
                        result.Add("SCENE_38", "GUIDANCESYSTEM");
                        break;
                    }
                case "HeaVna703":
                    {
                        result.Add("SCENE_15", "GUIDANCESYSTEM");
                        break;
                    }
                case "HeaVna702":
                    {
                        result.Add("EOBJECT0", "dummy0");
                        result.Add("EOBJECT1", "dummy1");
                        result.Add("EOBJECT2", "dummy2");
                        result.Add("EOBJECT3", "dummy3");
                        result.Add("SCENE_8", "dummy0");
                        result.Add("SCENE_10", "dummy1");
                        result.Add("SCENE_12", "dummy2");
                        result.Add("SCENE_24", "dummy3");
                        break;
                    }
                case "HeaVna613":
                    {
                        result.Add("SCENE_35", "EDMONT");
                        break;
                    }
                case "HeaVna604":
                    {
                        result.Add("SCENE_13", "TATARU");
                        break;
                    }
                case "HeaVna603":
                    {
                        result.Add("SCENE_4", "KANESENNA");
                        result.Add("SCENE_13", "YMHITRA");
                        break;
                    }
                case "HeaVna507":
                    {
                        result.Add("SCENE_2", "ALPHINAUD");
                        break;
                    }
                case "HeaVna405":
                    {
                        result.Add("SCENE_3", "AYMERIC");
                        result.Add("SCENE_5", "AYMERIC");
                        break;
                    }
                case "HeaVna335":
                    {
                        result.Add("SCENE_2", "ESTINIEN");
                        break;
                    }
                case "HeaVna333":
                    {
                        result.Add("SCENE_3", "CID");
                        break;
                    }
                case "HeaVna332":
                    {
                        result.Add("SCENE_13", "TEMPLEKIGHTGATE");
                        break;
                    }
                case "HeaVna330":
                    {
                        result.Add("SCENE_4", "BARTHOLOMEW");
                        break;
                    }
                case "HeaVna318":
                    {
                        result.Add("SCENE_5", "DOORMANLOTUS");
                        result.Add("SCENE_12", "ESTINIEN");
                        break;
                    }
                case "HeaVna317":
                    {
                        result.Add("EOBJECT0", "dummyESTINIEN");
                        result.Add("EOBJECT1", "dummy");
                        result.Add("EOBJECT2", "dummyICEHEART");
                        result.Add("SCENE_8", "dummyESTINIEN");
                        result.Add("SCENE_12", "dummyICEHEART");
                        break;
                    }
                case "HeaVna315":
                    {
                        result.Add("SCENE_6", "dummy0");
                        break;
                    }
                case "HeaVna314":
                    {
                        result.Add("ACTOR5", "ICEHEART");
                        result.Add("ACTOR6", "null");
                        result.Add("ACTOR7", "null");
                        result.Add("ACTOR8", "null");
                        result.Add("ACTOR9", "null");
                        result.Add("ACTOR10", "null");
                        result.Add("ACTOR11", "null");
                        break;
                    }
                case "HeaVna303":
                    {
                        result.Add("ENEMY0", "dummy0");
                        result.Add("ENEMY1", "dummy1");
                        result.Add("SCENE_13", "dummy0");
                        result.Add("SCENE_14", "dummy1");
                        break;
                    }
                case "HeaVna302":
                    {
                        result.Add("SCENE_9", "TEMPLEKIGHTGATE");
                        result.Add("SCENE_13", "ALPHINAUD");
                        break;
                    }
                case "HeaVna203":
                    {
                        result.Add("SCENE_9", "HOUZAN");
                        result.Add("SCENE_36", "PAPASHAN_2");
                        break;
                    }
                case "HeaVna113":
                    {
                        result.Add("SCENE_19", "MARIELLE_2");
                        break;
                    }
                case "HeaVna105":
                    {
                        result.Add("SCENE_25", "ROTHE_2");
                        break;
                    }
                case "ManFst300":
                    {
                        result.Add("EOBJECT0", "dummy1");
                        result.Add("EOBJECT1", "dummy2");
                        result.Add("ACTOR5", "ZANTHAEL");
                        result.Add("SCENE_7", "dummy1");
                        result.Add("SCENE_9", "dummy2");
                        result.Add("SCENE_11", "ZANTHAEL");
                        break;
                    }
                case "SubWil066":
                    {
                        result.Add("SCENE_5", "KODOMOA");
                        result.Add("SCENE_8", "KODOMOB");
                        result.Add("SCENE_11", "KODOMOC");
                        result.Add("SCENE_14", "KODOMOD");
                        break;
                    }
                case "SubWil064":
                    {
                        result.Add("SCENE_11", "dummy");
                        break;
                    }
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
