using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    public static class QuestParamDatabase
    {
        public static Dictionary<string, string> GetQuestParam(string questId)
        {
            var result = new Dictionary<string, string>();
            switch (questId)
            {
                case "StmBda139":
                    {
                        result.Add("WARP_SCENE26", "628|-130.2|-7|-59|1.57|false");
                        result.Add("PRIVATE_SCENE8", "680");
                        result.Add("PRIVATE_SCENE14", "680");
                        result.Add("PRIVATE_SCENE18", "680");
                        result.Add("PRIVATE_SCENE27", "680");
                    }
                    break;
                case "StmBda138":
                    {
                        result.Add("_ACTOR5", "B");
                        result.Add("_ACTOR5B", "2|2");
                        result.Add("_ACTOR6", "B");
                        result.Add("_ACTOR6B", "2|2");
                        result.Add("_ACTOR7", "B");
                        result.Add("_ACTOR7B", "2|2");
                        break;
                    }
                case "StmBda101":
                    {
                        result.Add("WARP_SCENE18", "612|-660|130|-533.333|0.96|false");
                    }
                    break;
                case "GaiUsd602":
                    {
                        result.Add("SCENE_4", "INVESTIGATORB");
                        result.Add("WARP_SCENE4", "156|444|-5.41|-466.9|1.21553|false");
                        break;
                    }
                case "GaiUsd401":
                    {
                        result.Add("WARP_SCENE3", "156|731.26|15.43|-58.536|0.8927|false");
                        break;
                    }
                case "GaiUsd204":
                    {
                        result.Add("IGNORE_SEQ2", "");
                        result.Add("WARP_SCENE3", "156|668|-1|-108|0.929|false");
                        break;
                    }
                case "GaiUsd203":
                    {
                        result.Add("SCENE_4", "dummye0");
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("_EOBJECT0", "S");
                        result.Add("SCENE_8", "dummye1");
                        result.Add("EOBJECT1", "dummye1");
                        result.Add("_EOBJECT1", "S");
                        result.Add("SCENE_13", "dummye4");
                        result.Add("EOBJECT4", "dummye4");
                        result.Add("_EOBJECT4", "S");
                        result.Add("SCENE_7", null);
                        result.Add("SCENE_18", null);
                        break;
                    }
                case "HeaVng104":
                    {
                        result.Add("PRIVATE_SILENTCONJURER", "205");
                        break;
                    }
                case "HeaVng103":
                    {
                        result.Add("PRIVATE_SCENE25", "636");
                        result.Add("WARP_SCENE22", "132|40|-19|94.5|2.47|true");
                        break;
                    }
                case "HeaVng102":
                    {
                        result.Add("WARP_SCENE7", "156|124.1|-15.1|-428.3|-2.81|true");
                        break;
                    }
                case "HeaVne108":
                    {
                        result.Add("SCENE_17", null);
                        break;
                    }
                case "HeaVne107":
                    {
                        result.Add("_ACTOR2", "B");
                        result.Add("_ACTOR2B", "1|2");
                        result.Add("_ACTOR3", "B");
                        result.Add("_ACTOR3B", "1|2");
                        result.Add("_ACTOR4", "B");
                        result.Add("_ACTOR4B", "1|2");
                        break;
                    }
                case "HeaVne103":
                    {
                        result.Add("SCENE_5", "AYMERIC");
                        break;
                    }
                case "HeaVnd104":
                    {
                        result.Add("WARP_SCENE1", "418|0|-2.6|141.3|-3.1415|false");
                        result.Add("WARP_SCENE5", "418|0|-2.6|141.3|-3.1415|false");
                        result.Add("SCENE_4", "AYMERIC");
                        result.Add("PRIVATE_SCENE3", "569");
                        result.Add("PRIVATE_TEMPLEKNIGHTB02245", "569");
                        break;
                    }
                case "HeaVnc110":
                    {
                        result.Add("WARP_SCENE2", "418|0.758|1.3|110.3|3.1415|false");
                        break;
                    }
                case "HeaVnc108":
                    {
                        result.Add("PRIVATE_SCENE5", "428");
                        break;
                    }
                case "HeaVnc106":
                    {
                        result.Add("_ACTOR3", "B");
                        result.Add("_ACTOR3B", "2|2");
                        result.Add("_ACTOR4", "B");
                        result.Add("_ACTOR4B", "2|2");
                        result.Add("_ACTOR17", "B");
                        result.Add("_ACTOR17B", "2|2");
                        break;
                    }
                case "HeaVnc104":
                    {
                        result.Add("_ACTOR9", "B");
                        result.Add("_ACTOR9B", "1|2");
                        result.Add("_ACTOR10", "B");
                        result.Add("_ACTOR10B", "1|2");
                        result.Add("_ACTOR4", "B");
                        result.Add("_ACTOR4B", "1|2");
                        break;
                    }
                case "HeaVnc101":
                    {
                        result.Add("SCENE_18", "HOARYBOULDER");
                        result.Add("_ACTOR10", "B");
                        result.Add("_ACTOR10B", "3|2");
                        result.Add("_ACTOR11", "B");
                        result.Add("_ACTOR11B", "3|2");
                        result.Add("_ACTOR12", "B");
                        result.Add("_ACTOR12B", "3|2");
                        result.Add("_ACTOR13", "B");
                        result.Add("_ACTOR13B", "3|2");
                        result.Add("_ACTOR14", "B");
                        result.Add("_ACTOR14B", "3|2");
                        break;
                    }
                case "HeaVnb108":
                    {
                        result.Add("WARP_SCENE1", "418|85|24|-6.53|-1.77|false");
                        result.Add("TODO_DISABLED", "");
                        result.Add("SCENE_34", "ACTOR29");
                        result.Add("PRIVATE_SCENE36", "0");
                        break;
                    }
                case "HeaVnb107":
                    {
                        result.Add("WARP_SCENE1", "418|85|24|-6.53|-1.77|false");
                        result.Add("_ACTOR12", "B");
                        result.Add("_ACTOR12B", "2|2");
                        result.Add("_ACTOR13", "B");
                        result.Add("_ACTOR13B", "2|2");
                        break;
                    }
                case "HeaVnb105":
                    {
                        result.Add("SCENE_10", null);
                        result.Add("SCENE_13", "ACTOR4");
                        break;
                    }
                case "HeaVnb104":
                    {
                        result.Add("_ACTOR7", "B");
                        result.Add("_ACTOR7B", "3|2");
                        result.Add("_ACTOR8", "B");
                        result.Add("_ACTOR8B", "3|2");
                        result.Add("_ACTOR9", "B");
                        result.Add("_ACTOR9B", "3|2");
                        result.Add("TODO_REMOVE", "0");
                        result.Add("_TODO_FORCED", "");
                        break;
                    }
                case "HeaVnb103":
                    {
                        result.Add("WARP_SCENE9", "399|-531|152.9|-487|0.219|false");
                        break;
                    }
                case "HeaVnb101":
                    {
                        result.Add("PRIVATE_SCENE1", "0");
                        result.Add("WARP_SCENE3", "418|113|24.4|-4.65|-0.856|false");
                        break;
                    }
                case "HeaVna706":
                    {
                        result.Add("MOUNT_SCENE3", "50");
                        break;
                    }
                case "HeaVna701":
                    {
                        result.Add("WARP_SCENE17", "402|-868|-184.2|-660.5|1.21|false");
                        result.Add("WARP_SCENE28", "402|-868|-184.2|-660.5|1.21|false");
                        break;
                    }
                case "ManSea001":
                    {
                        result.Add("WARP_GREHFARR", "181|9|40|14|0|false");
                        break;
                    }
                case "SubWil113":
                    {
                        result.Add("_AGGRESSIVE_BNPC_HACK", "");
                        result.Add("IGNORE_BNPCHACK_EVENTRANGE0", "");
                        break;
                    }
                case "SubWil110":
                    {
                        result.Add("ID_ACTOR1", "4298942495");
                        result.Add("ID_ACTOR2", "4298942496");
                        result.Add("ID_ACTOR3", "4298942497");
                        break;
                    }
                case "SubSea056":
                    {
                        result.Add("IGNORE_SEQ1", "");
                        break;
                    }
                case "SubSea055":
                    {
                        result.Add("ID_EOBJECT0", "4298896562");
                        result.Add("ID_EOBJECT1", "4298896563");
                        result.Add("ID_EOBJECT2", "4298896564");
                        break;
                    }
                case "SubSea054":
                    {
                        result.Add("_ACTOR1", "E");
                        result.Add("_ACTOR1E", "1|3,12");
                        result.Add("SCENE_15", "SOZAIRARZAI");
                        result.Add("_ALLOW_EMPTY_ENTRY", "");
                        break;
                    }
                case "SubSea053":
                    {
                        result.Add("ID_ACTOR1", "4298896548");
                        result.Add("ID_ACTOR2", "4298896549");
                        result.Add("ID_ACTOR3", "4298896550");
                        result.Add("ID_ACTOR4", "4298896551");
                        result.Add("ID_ACTOR5", "4298896552");
                        break;
                    }
                case "ManWil200":
                    {
                        result.Add("WARP_SCENE4", "130|-32.35|83.2|-3|1.3|false");
                        result.Add("WARP_SCENE8", "128|-11.86|92|17|-1.95|true");
                        result.Add("WARP_SCENE9", "130|-32.35|83.2|-3|1.3|false");
                        result.Add("WARP_SCENE12", "128|-13.95|91.5|-5.88|2.89|false");
                        result.Add("WARP_SCENE15", "128|-11.86|92|17|-1.95|true");
                        result.Add("WARP_SCENE24", "128|-24.3|92|2.47|-0.37|false");
                        result.Add("WARP_SCENE30", "132|7.8|-21.97|123.88|1.58|true");
                        result.Add("WARP_SCENE31", "128|-24.3|92|2.47|-0.37|false");
                        result.Add("WARP_SCENE37", "132|35.5|-19|105|-3.14|false");
                        result.Add("WARP_SCENE41", "132|7.8|-21.97|123.88|1.58|true");
                        result.Add("ID_ACTOR8", "4296108319");
                        break;
                    }
                case "ManWil009":
                    {
                        result.Add("_BRANCH", "");
                        break;
                    }
                case "ManWil007":
                    {
                        result.Add("ALTERNATIVE_QUEST_COMPLETE", "");
                        result.Add("SCENE_6", null);
                        result.Add("SCENE_7", null);
                        result.Add("PRIVATE_SULTANSWORMA", "210");
                        break;
                    }
                case "ManSea200":
                    {
                        result.Add("WARP_SCENE4", "128|-24.3|92|2.47|-0.37|false");
                        result.Add("WARP_SCENE8", "132|7.8|-21.97|123.88|1.58|true");
                        result.Add("WARP_SCENE9", "128|-24.3|92|2.47|-0.37|false");
                        result.Add("WARP_SCENE12", "132|35.5|-19|105|-3.14|false");
                        result.Add("WARP_SCENE15", "132|7.8|-21.97|123.88|1.58|true");
                        result.Add("WARP_SCENE24", "132|22.55|-19|114.2|0|false");
                        result.Add("WARP_SCENE30", "130|-44.14|84|-0.47|1.3|true");
                        result.Add("WARP_SCENE31", "132|22.55|-19|114.2|0|false");
                        result.Add("WARP_SCENE36", "130|-19.45|83.2|3.85|1.8|false");
                        result.Add("WARP_SCENE41", "130|-44.14|84|-0.47|1.3|true");
                        result.Add("ID_ACTOR5", "4296108319");
                        break;
                    }
                case "ManSea009":
                    {
                        result.Add("_BRANCH", "");
                        result.Add("PRIVATE_SCENE8", "198");
                        break;
                    }
                case "SubWil025":
                    {
                        result.Add("_ACTOR1", "B");
                        result.Add("_ACTOR1B", "1|2");
                        result.Add("_ACTOR2", "B");
                        result.Add("_ACTOR2B", "1|2");
                        result.Add("_ACTOR3", "B");
                        result.Add("_ACTOR3B", "1|2");
                        break;
                    }
                case "HeaVna612":
                    {
                        result.Add("PRIVATE_SCENE2", "0");
                        break;
                    }
                case "HeaVna610":
                    {
                        result.Add("PRIVATE_SCENE16", "463");
                        break;
                    }
                case "HeaVna607":
                    {
                        result.Add("SCENE_10", "actor4");
                        result.Add("SCENE_11", "golem_a");
                        result.Add("SCENE_12", "golem_a");
                        result.Add("SCENE_13", "golem_b");
                        result.Add("SCENE_14", "golem_b");
                        result.Add("_ACTOR5", "C");
                        result.Add("_ACTOR5C", "2|2");
                        result.Add("_ACTOR6", "C");
                        result.Add("_ACTOR6C", "2|2");
                        break;
                    }
                case "HeaVna606":
                    {
                        result.Add("SCENE_3", "dummyt");
                        result.Add("SCENE_4", "dummyt");
                        break;
                    }
                case "HeaVna601":
                    {
                        result.Add("PRIVATE_TEMPLEKIGHTGATE", "428");
                        break;
                    }
                case "HeaVna508":
                    {
                        result.Add("WARP_SCENE2", "419|166.7|-14.5|39.3|-2.1|true");
                        result.Add("SCENE_2", "CID");
                        break;
                    }
                case "HeaVna505":
                    {
                        result.Add("_ACTOR5", "E");
                        result.Add("_ACTOR5E", "2|3,5");
                        break;
                    }
                case "HeaVna503":
                    {
                        result.Add("ID_ACTOR2", "2097153");
                        result.Add("SCENE_9", null);
                        break;
                    }
                case "HeaVna502":
                    {
                        result.Add("WARP_WEDGE", "401|-807.3|-57.7|158.4|1|true");
                        break;
                    }
                case "HeaVna403":
                    {
                        result.Add("WARP_SCENE6", "418|20.37|-12|46|0.63|false");
                        break;
                    }
                case "HeaVna402":
                    {
                        result.Add("PRIVATE_SCENE1", "0");
                        result.Add("_ACTOR7", "B");
                        result.Add("_ACTOR7B", "2|2");
                        result.Add("_ACTOR8", "B");
                        result.Add("_ACTOR8B", "2|2");
                        result.Add("_ACTOR9", "B");
                        result.Add("_ACTOR9B", "2|2");
                        break;
                    }
                case "GaiUsc101":
                    {
                        result.Add("_BASE_ID_TERRITORY_TYPE", "I");
                        result.Add("_BASE_ID_TERRITORY_TYPEI", "3");
                        break;
                    }
                case "GaiUsb801":
                    {
                        result.Add("_AGGRESSIVE_BNPC_HACK", "");
                        break;
                    }
                case "GaiUsb604":
                    {
                        result.Add("IGNORE_BNPCHACK_EVENTRANGE0", "");
                        break;
                    }
                case "GaiUsb103":
                    {
                        result.Add("SCENE_4", null);
                        result.Add("IGNORE_SEQ1", "");
                        result.Add("_AGGRESSIVE_BNPC_HACK", "");
                        break;
                    }
                case "GaiUsa906":
                    {
                        result.Add("IGNORE_SEQ2", "");
                        break;
                    }
                case "GaiUsa709":
                    {
                        result.Add("ID_ACTOR2", "4299289701");
                        result.Add("ID_ACTOR3", "4299289705");
                        break;
                    }
                case "GaiUsa402":
                    {
                        result.Add("ID_ACTOR1", "2097153");
                        break;
                    }
                case "HeaVna327":
                    {
                        result.Add("SCENE_9", "dummyr1");
                        result.Add("EVENTRANGE1", "dummyr1");
                        result.Add("_EVENTRANGE1", "S");
                        result.Add("SCENE_15", "dummyr2");
                        result.Add("EVENTRANGE2", "dummyr2");
                        result.Add("_EVENTRANGE2", "S");
                        result.Add("SCENE_21", "actor7");
                        result.Add("SCENE_22", "actor7");
                        result.Add("ACTOR7", "actor7");
                        result.Add("ACTOR6", "actor6");
                        break;
                    }
                case "HeaVna316":
                    {
                        result.Add("SCENE_5", "ALPHINAUD");
                        break;
                    }
                case "HeaVna313":
                    {
                        result.Add("_ACTOR3", "B");
                        result.Add("_ACTOR3B", "1|2");
                        result.Add("_ACTOR4", "B");
                        result.Add("_ACTOR4B", "1|2");
                        result.Add("_ACTOR5", "B");
                        result.Add("_ACTOR5B", "1|2");
                        break;
                    }
                case "HeaVna311":
                    {
                        result.Add("SCENE_4", "SEQ_1");
                        break;
                    }
                case "HeaVna201":
                    {
                        result.Add("SCENE_3", "dummyt0");
                        result.Add("SCENE_4", "dummyt0");
                        result.Add("SCENE_11", "ALPHINAUD2");
                        result.Add("PRIVATE_SCENE5", "198");
                        break;
                    }
                case "HeaVna109":
                    {
                        result.Add("WARP_SCENE9", "397|463|162.57|-521|2.4|false");
                        break;
                    }
                case "HeaVna104":
                    {
                        result.Add("WARP_STABLEHAND01583", "397|475|225|794|3.1415|true");
                        break;
                    }
                case "HeaVna116":
                    {
                        result.Add("SCENE_4", null);
                        result.Add("WARP_SCENE10", "401|-676.24|-110.8|477.87|0.18|false");
                        break;
                    }
                case "HeaVna114":
                    {
                        result.Add("_ACTOR1", "E");
                        result.Add("_ACTOR1E", "1|3,30");
                        result.Add("_ACTOR3", "E");
                        result.Add("_ACTOR3E", "1|3,30");
                        result.Add("_ACTOR4", "E");
                        result.Add("_ACTOR4E", "1|3,30");
                        break;
                    }
                case "HeaVna111":
                    {
                        result.Add("WARP_WINDOW01590", "401|-726.8|-105|470|1|true");
                        break;
                    }
                case "HeaVna101":
                    {
                        result.Add("WARP_TEMPLEKNIGHT01580", "418|0|-2.6|141.3|-3.14|true");
                        result.Add("PRIVATE_SCENE16", "433");
                        break;
                    }
                case "GaiUse603":
                    {
                        result.Add("PRIVATE_FORTEMPSGUARD00054", "395");
                        break;
                    }
                case "GaiUse507":
                    {
                        result.Add("SCENE_4", "dummyt0");
                        result.Add("SCENE_5", null);
                        result.Add("SCENE_6", "dummyt0");
                        result.Add("SCENE_7", "dummyt0");
                        break;
                    }
                case "GaiUse504":
                    {
                        result.Add("SCENE_19", "dummyr0");
                        result.Add("SCENE_20", "dummyr0");
                        break;
                    }
                case "GaiUse502":
                    {
                        result.Add("SCENE_5", "SENTRY00364");
                        break;
                    }
                case "GaiUse316":
                    {
                        result.Add("_ACTOR3", "B");
                        result.Add("_ACTOR3B", "2|2");
                        result.Add("_ACTOR4", "B");
                        result.Add("_ACTOR4B", "2|2");
                        result.Add("_ACTOR5", "B");
                        result.Add("_ACTOR5B", "2|2");
                        result.Add("_ACTOR6", "B");
                        result.Add("_ACTOR6B", "2|2");
                        result.Add("_ACTOR10", "B");
                        result.Add("_ACTOR10B", "5|2");
                        result.Add("_ACTOR11", "B");
                        result.Add("_ACTOR11B", "5|2");
                        result.Add("_ACTOR12", "B");
                        result.Add("_ACTOR12B", "5|2");
                        result.Add("_ACTOR17", "B");
                        result.Add("_ACTOR17B", "8|2");
                        result.Add("_ACTOR18", "B");
                        result.Add("_ACTOR18B", "8|2");
                        result.Add("_ACTOR19", "B");
                        result.Add("_ACTOR19B", "8|2");
                        result.Add("_ACTOR20", "B");
                        result.Add("_ACTOR20B", "8|2");
                        break;
                    }
                case "GaiUse302":
                    {
                        result.Add("_ACTOR6", "E");
                        result.Add("_ACTOR6E", "255|3,35");
                        break;
                    }
                case "GaiUse214":
                    {
                        result.Add("SCENE_2", "ACTOR1_FALKBRYDA_DUPE");
                        result.Add("SCENE_3", "ACTOR1_FALKBRYDA_DUPE");
                        break;
                    }
                case "GaiUse217":
                case "GaiUse216":
                case "GaiUse212":
                    {
                        result.Add("PRIVATE_ZANTHAEL", "198");
                        break;
                    }
                case "GaiUse211":
                    {
                        result.Add("_ALLOW_EMPTY_ENTRY", "");
                        break;
                    }
                case "GaiUse208":
                    {
                        result.Add("SCENE_18", "GYOSHA01348");
                        break;
                    }
                case "GaiUse118":
                    {
                        result.Add("SCENE_3", "URIANGER");
                        break;
                    }
                case "GaiUse312":
                case "GaiUse307":
                case "GaiUse117":
                case "GaiUse115":
                    {
                        result.Add("PRIVATE_DOORMANLOTUS", "205");
                        break;
                    }
                case "XxaFst502":
                    {
                        result.Add("SCENE_3", "RAUBAHN");
                        break;
                    }
                case "XxaUsc908":
                    {
                        result.Add("_ACTOR7", "E");
                        result.Add("_ACTOR7E", "2|3,30");
                        result.Add("_ACTOR8", "E");
                        result.Add("_ACTOR8E", "2|3,30");
                        result.Add("_ACTOR9", "E");
                        result.Add("_ACTOR9E", "2|3,30");
                        break;
                    }
                case "GaiUsc901":
                    {
                        result.Add("SCENE_3", "ADALBERT");
                        break;
                    }
                case "ManFst407":
                    {
                        result.Add("WARP_SLAFBORN", "156|0.64|-158.5|13.4|3.14|false");
                        result.Add("SCENE_2", null);
                        result.Add("SCENE_8", "CID");
                        result.Add("_ACTOR5", "B");
                        result.Add("_ACTOR5B", "1|2");
                        result.Add("_ACTOR7", "E");
                        result.Add("_ACTOR7E", "2|3,59");
                        result.Add("_ACTOR9", "E");
                        result.Add("_ACTOR9E", "2|3,59");
                        result.Add("_ACTOR10", "E");
                        result.Add("_ACTOR10E", "2|3,59");
                        result.Add("_ACTOR11", "E");
                        result.Add("_ACTOR11E", "3|3,59");
                        result.Add("PRIVATE_SCENE8", "335");
                        result.Add("PRIVATE_SCENE14", "335");
                        result.Add("PRIVATE_SCENE26", "335");
                        result.Add("PRIVATE_SCENE31", "335");
                        result.Add("PRIVATE_SCENE36", "335");
                        break;
                    }
                case "GaiUsc605":
                    {
                        result.Add("WARP_SLAFBORN", "156|0.64|-158.5|13.4|3.14|false");
                        result.Add("MOUNT_SCENE9", "14");
                        result.Add("MOUNT_SCENE17", "14");
                        result.Add("MOUNT_SCENE23", "14");
                        result.Add("MOUNT_SCENE30", "14");
                        result.Add("_ACTOR7", "E");
                        result.Add("_ACTOR7E", "9|3,41");
                        break;
                    }
                case "GaiUsc604":
                    {
                        result.Add("_ACTOR1", "E");
                        result.Add("_ACTOR1E", "1|3,59");
                        result.Add("WARP_SCENE21", "156|0.64|-158.5|13.4|3.14|false");
                        break;
                    }
                case "ManFst404":
                    {
                        result.Add("WARP_LIONNELLAIS", "132|22.43|-19|115.729|0|false");
                        result.Add("PRIVATE_SCENE1", "331");
                        result.Add("PRIVATE_SCENE4", "331");
                        break;
                    }
                case "GaiUsc308":
                    {
                        result.Add("WARP_LIONNELLAIS", "132|22.43|-19|115.729|0|false");
                        break;
                    }
                case "GaiUsc208":
                    {
                        result.Add("ACTOR2", "MIMIDOA");
                        result.Add("_ACTOR2", "S");
                        result.Add("EOBJECT1", "dummye1");
                        result.Add("EOBJECT0", "dummye0");
                        result.Add("SCENE_9", "dummye1");
                        break;
                    }
                case "GaiUsc203":
                    {
                        result.Add("WARP_SENDO", "138|-290|-41|410.72|0.77|false");
                        break;
                    }
                case "ManFst200":
                    {
                        result.Add("WARP_SCENE8", "128|-11.86|92|17|-1.95|true");
                        result.Add("WARP_SCENE9", "132|22.55|-19|114.2|0|false");
                        result.Add("WARP_SCENE12", "128|-13.95|91.5|-5.88|2.89|false");
                        result.Add("WARP_SCENE15", "128|-11.86|92|17|-1.95|true");
                        result.Add("WARP_SCENE24", "128|-24.3|92|2.47|-0.37|false");
                        result.Add("WARP_SCENE30", "130|-44.14|84|-0.47|1.3|true");
                        result.Add("WARP_SCENE31", "128|-24.3|92|2.47|-0.37|false");
                        result.Add("WARP_SCENE36", "130|-19.45|83.2|3.85|1.8|false");
                        result.Add("WARP_SCENE41", "130|-44.14|84|-0.47|1.3|true");
                        break;
                    }
                case "ManFst009":
                    {
                        result.Add("_BRANCH", "");
                        result.Add("PRIVATE_DOORMANLOTUS", "205");
                        break;
                    }
                case "ManFst008":
                    {
                        result.Add("PRIVATE_SCENE2", "204");
                        break;
                    }
                case "ManFst007":
                    {
                        result.Add("PRIVATE_DOORMANSINYU", "204");
                        break;
                    }
                case "SubFst058":
                    {
                        result.Add("SCENE_6", null);
                        result.Add("SCENE_92", null);
                        result.Add("SCENE_91", null);
                        break;
                    }
                case "SubFst035":
                    {
                        result.Add("SCENE_19", "CONJURERC");
                        result.Add("SCENE_23", "dummyt");
                        break;
                    }
                case "GaiUsb507":
                    {
                        result.Add("ACTOR17", "NPCB");
                        result.Add("_ACTOR17", "S");
                        break;
                    }
                case "ManSea303":
                    {
                        result.Add("SCENE_2", null);
                        break;
                    }
                case "ManFst209":
                    {
                        result.Add("SCENE_7", null);
                        result.Add("WARP_ADALA", "146|-53.45|-24.09|-567.49|-0.55|false");
                        break;
                    }
                case "SubSea105":
                    {
                        result.Add("SCENE_100", null);
                        result.Add("SCENE_99", null);
                        result.Add("SCENE_98", null);
                        result.Add("SCENE_97", null);
                        result.Add("SCENE_96", null);
                        result.Add("SCENE_95", null);
                        result.Add("SCENE_94", null);
                        result.Add("SCENE_93", null);
                        result.Add("SCENE_92", null);
                        result.Add("SCENE_91", null);
                        result.Add("SCENE_89", null);
                        result.Add("SCENE_88", null);
                        result.Add("SCENE_87", null);
                        result.Add("SCENE_86", null);
                        result.Add("SCENE_85", null);
                        result.Add("SCENE_84", null);
                        result.Add("SCENE_83", null);
                        result.Add("SCENE_82", null);
                        result.Add("SCENE_81", null);
                        break;
                    }
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
                        result.Add("WARP_SCENE5", "144|-34.5|0.64|100|-1.58|false");
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
                        result.Add("WARP_SCENE3", "156|731.26|15.43|-58.536|-2.238|false");
                        result.Add("WARP_SCENE8", "156|444|-5.41|-466.9|1.21553|false");
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
                        result.Add("SCENE_13", "RAUBAHN");
                        result.Add("SCENE_19", "dummyt");
                        result.Add("SCENE_20", "dummyt");
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
                        result.Add("_AGGRESSIVE_BNPC_HACK", "");
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
                        result.Add("SCENE_16", null);
                        result.Add("PRIVATE_SCENE12", "507");
                        result.Add("PRIVATE_SCENE15", "507");
                        result.Add("PRIVATE_SCENE17", "433");
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
                        result.Add("SCENE_42", "dummye3");
                        result.Add("SCENE_43", "dummye3");
                        result.Add("WARP_SCENE43", "402|633.6|10.62|73.6|1|false");
                        break;
                    }
                case "HeaVna703":
                    {
                        result.Add("SCENE_15", "GUIDANCESYSTEM");
                        result.Add("WARP_SCENE22", "402|214.35|-66|-615.7|2.97|false");
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
                        result.Add("WARP_SCENE24", "402|-644.12|-176.45|-583.89|0|false");
                        break;
                    }
                case "HeaVna613":
                    {
                        result.Add("SCENE_35", "EDMONT");
                        result.Add("_ACTOR8", "B");
                        result.Add("_ACTOR8B", "2|2");
                        result.Add("_ACTOR9", "B");
                        result.Add("_ACTOR9B", "2|2");
                        result.Add("_ACTOR10", "B");
                        result.Add("_ACTOR10B", "2|2");
                        break;
                    }
                case "HeaVna604":
                    {
                        result.Add("SCENE_13", "TATARU");
                        result.Add("_ACTOR3", "B");
                        result.Add("_ACTOR3B", "1|2");
                        result.Add("_ACTOR4", "B");
                        result.Add("_ACTOR4B", "1|2");
                        break;
                    }
                case "HeaVna603":
                    {
                        result.Add("SCENE_4", "KANESENNA");
                        result.Add("SCENE_13", "YMHITRA");
                        result.Add("PRIVATE_DOORMANLOTUS", "205");
                        result.Add("WARP_SCENE13", "132|30|-8|95|0.85|false");
                        break;
                    }
                case "HeaVna507":
                    {
                        result.Add("SCENE_2", "ALPHINAUD");
                        result.Add("WARP_SCENE2", "401|-584.1|-52.4|-445.3|2.88|false");
                        break;
                    }
                case "HeaVna405":
                    {
                        result.Add("SCENE_3", "AYMERIC");
                        result.Add("SCENE_5", "AYMERIC");
                        result.Add("PRIVATE_SCENE5", "0");
                        result.Add("PRIVATE_SCENE9", "428");
                        result.Add("ID_ACTOR3", "4300878011");
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
                        result.Add("_SCENE_12", "Z");
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
                        result.Add("_SCENE_6", "Z");
                        result.Add("PRIVATE_SCENE2", "462");
                        result.Add("PRIVATE_SCENE4", "462");
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
                        result.Add("ID_EOBJECT2", "4300909001");
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
                        result.Add("_ALLOW_EMPTY_ENTRY", "");
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
    }
}
