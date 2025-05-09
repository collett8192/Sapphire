#ifndef _COMMON_GEN_H_
#define _COMMON_GEN_H_

#include <stdint.h>

/* This file has been automatically generated.
Changes will be lost upon regeneration.
To change the content edit tools/exd_common_gen */
namespace Sapphire::Common {

  ///////////////////////////////////////////////////////////
  //ActionCategory.exd
  enum class ActionCategory : uint8_t
  {
    None = 0,
    Autoattack = 1,
    Spell = 2,
    Weaponskill = 3,
    Ability = 4,
    Item = 5,
    DoLAbility = 6,
    DoHAbility = 7,
    Event = 8,
    LimitBreak = 9,
    System = 10,
    Artillery = 11,
    Mount = 12,
    Special = 13,
    ItemManipulation = 14,
    AdrenalineRush = 15,
    //1 = 16,
  };

  ///////////////////////////////////////////////////////////
  //BaseParam.exd
  enum class BaseParam : uint8_t
  {
    None = 0,
    Strength = 1,
    Dexterity = 2,
    Vitality = 3,
    Intelligence = 4,
    Mind = 5,
    Piety = 6,
    HP = 7,
    MP = 8,
    TP = 9,
    GP = 10,
    CP = 11,
    PhysicalDamage = 12,
    MagicDamage = 13,
    Delay = 14,
    AdditionalEffect = 15,
    AttackSpeed = 16,
    BlockRate = 17,
    BlockStrength = 18,
    Tenacity = 19,
    AttackPower = 20,
    Defense = 21,
    DirectHitRate = 22,
    Evasion = 23,
    MagicDefense = 24,
    CriticalHitPower = 25,
    CriticalHitResilience = 26,
    CriticalHit = 27,
    CriticalHitEvasion = 28,
    SlashingResistance = 29,
    PiercingResistance = 30,
    BluntResistance = 31,
    ProjectileResistance = 32,
    AttackMagicPotency = 33,
    HealingMagicPotency = 34,
    EnhancementMagicPotency = 35,
    ElementalBonus = 36,
    FireResistance = 37,
    IceResistance = 38,
    WindResistance = 39,
    EarthResistance = 40,
    LightningResistance = 41,
    WaterResistance = 42,
    MagicResistance = 43,
    Determination = 44,
    SkillSpeed = 45,
    SpellSpeed = 46,
    Haste = 47,
    Morale = 48,
    Enmity = 49,
    EnmityReduction = 50,
    DesynthesisSkillGain = 51,
    EXPBonus = 52,
    Regen = 53,
    Refresh = 54,
    MainAttribute = 55,
    SecondaryAttribute = 56,
    SlowResistance = 57,
    PetrificationResistance = 58,
    ParalysisResistance = 59,
    SilenceResistance = 60,
    BlindResistance = 61,
    PoisonResistance = 62,
    StunResistance = 63,
    SleepResistance = 64,
    BindResistance = 65,
    HeavyResistance = 66,
    DoomResistance = 67,
    ReducedDurabilityLoss = 68,
    IncreasedSpiritbondGain = 69,
    Craftsmanship = 70,
    Control = 71,
    Gathering = 72,
    Perception = 73,
  };

  ///////////////////////////////////////////////////////////
  //BeastReputationRank.exd
  enum class BeastReputationRank : uint8_t
  {
    None = 0,
    Neutral = 1,
    Recognized = 2,
    Friendly = 3,
    Trusted = 4,
    Respected = 5,
    Honored = 6,
    Sworn = 7,
    Allied = 8,
  };

  ///////////////////////////////////////////////////////////
  //BeastTribe.exd
  enum class BeastTribe : uint8_t
  {
    /* = 0,
    1 = 1,
    2 = 2,
    3 = 3,
    4 = 4,
    5 = 5,
    6 = 6,
    7 = 7,
    8 = 8,
    9 = 9,
    10 = 10,
    11 = 11,
    12 = 12,
    13 = 13,
    14 = 14,*/
  };

  ///////////////////////////////////////////////////////////
  //ClassJob.exd
  enum class ClassJob : uint8_t
  {
    Adventurer = 0,
    Gladiator = 1,
    Pugilist = 2,
    Marauder = 3,
    Lancer = 4,
    Archer = 5,
    Conjurer = 6,
    Thaumaturge = 7,
    Carpenter = 8,
    Blacksmith = 9,
    Armorer = 10,
    Goldsmith = 11,
    Leatherworker = 12,
    Weaver = 13,
    Alchemist = 14,
    Culinarian = 15,
    Miner = 16,
    Botanist = 17,
    Fisher = 18,
    Paladin = 19,
    Monk = 20,
    Warrior = 21,
    Dragoon = 22,
    Bard = 23,
    Whitemage = 24,
    Blackmage = 25,
    Arcanist = 26,
    Summoner = 27,
    Scholar = 28,
    Rogue = 29,
    Ninja = 30,
    Machinist = 31,
    Darkknight = 32,
    Astrologian = 33,
    Samurai = 34,
    Redmage = 35,
    Bluemage = 36,
    Gunbreaker = 37,
    Dancer = 38,
    // = 39,
    //1 = 40,
  };

  ///////////////////////////////////////////////////////////
  //ContentType.exd
  enum class ContentType : uint8_t
  {
    None = 0,
    DutyRoulette = 1,
    Dungeons = 2,
    Guildhests = 3,
    Trials = 4,
    Raids = 5,
    PvP = 6,
    QuestBattles = 7,
    FATEs = 8,
    TreasureHunt = 9,
    Levequests = 10,
    GrandCompany = 11,
    Companions = 12,
    BeastTribeQuests = 13,
    OverallCompletion = 14,
    PlayerCommendation = 15,
    DisciplesoftheLand = 16,
    DisciplesoftheHand = 17,
    RetainerVentures = 18,
    GoldSaucer = 19,
    //1 = 20,
    DeepDungeons = 21,
    //2 = 22,
    //3 = 23,
    WondrousTails = 24,
    CustomDeliveries = 25,
    Eureka = 26,
    //4 = 27,
    UltimateRaids = 28,
    //5 = 29,
  };

  ///////////////////////////////////////////////////////////
  //EmoteCategory.exd
  enum class EmoteCategory : uint8_t
  {
    None = 0,
    General = 1,
    Special = 2,
    Expressions = 3,
    //1 = 4,
  };

  ///////////////////////////////////////////////////////////
  //ExVersion.exd
  enum class ExVersion : uint8_t
  {
    ARealmReborn = 0,
    Heavensward = 1,
    Stormblood = 2,
    Shadowbringers = 3,
  };

  ///////////////////////////////////////////////////////////
  //GrandCompany.exd
  enum class GrandCompany : uint8_t
  {
    None = 0,
    Maelstrom = 1,
    OrderoftheTwinAdder = 2,
    ImmortalFlames = 3,
  };

  ///////////////////////////////////////////////////////////
  //GuardianDeity.exd
  enum class GuardianDeity : uint8_t
  {
    None = 0,
    HalonetheFury = 1,
    MenphinatheLover = 2,
    ThaliaktheScholar = 3,
    NymeiatheSpinner = 4,
    LlymlaentheNavigator = 5,
    OschontheWanderer = 6,
    ByregottheBuilder = 7,
    RhalgrtheDestroyer = 8,
    AzeymatheWarden = 9,
    NaldthaltheTraders = 10,
    NophicatheMatron = 11,
    AlthyktheKeeper = 12,
  };

  ///////////////////////////////////////////////////////////
  //ItemUICategory.exd
  enum class ItemUICategory : uint8_t
  {
    None = 0,
    PugilistsArm = 1,
    GladiatorsArm = 2,
    MaraudersArm = 3,
    ArchersArm = 4,
    LancersArm = 5,
    OnehandedThaumaturgesArm = 6,
    TwohandedThaumaturgesArm = 7,
    OnehandedConjurersArm = 8,
    TwohandedConjurersArm = 9,
    ArcanistsGrimoire = 10,
    Shield = 11,
    CarpentersPrimaryTool = 12,
    CarpentersSecondaryTool = 13,
    BlacksmithsPrimaryTool = 14,
    BlacksmithsSecondaryTool = 15,
    ArmorersPrimaryTool = 16,
    ArmorersSecondaryTool = 17,
    GoldsmithsPrimaryTool = 18,
    GoldsmithsSecondaryTool = 19,
    LeatherworkersPrimaryTool = 20,
    LeatherworkersSecondaryTool = 21,
    WeaversPrimaryTool = 22,
    WeaversSecondaryTool = 23,
    AlchemistsPrimaryTool = 24,
    AlchemistsSecondaryTool = 25,
    CulinariansPrimaryTool = 26,
    CulinariansSecondaryTool = 27,
    MinersPrimaryTool = 28,
    MinersSecondaryTool = 29,
    BotanistsPrimaryTool = 30,
    BotanistsSecondaryTool = 31,
    FishersPrimaryTool = 32,
    FishingTackle = 33,
    Head = 34,
    Body = 35,
    Legs = 36,
    Hands = 37,
    Feet = 38,
    Waist = 39,
    Necklace = 40,
    Earrings = 41,
    Bracelets = 42,
    Ring = 43,
    Medicine = 44,
    Ingredient = 45,
    Meal = 46,
    Seafood = 47,
    Stone = 48,
    Metal = 49,
    Lumber = 50,
    Cloth = 51,
    Leather = 52,
    Bone = 53,
    Reagent = 54,
    Dye = 55,
    Part = 56,
    Furnishing = 57,
    Materia = 58,
    Crystal = 59,
    Catalyst = 60,
    Miscellany = 61,
    SoulCrystal = 62,
    Other = 63,
    ConstructionPermit = 64,
    Roof = 65,
    ExteriorWall = 66,
    Window = 67,
    Door = 68,
    RoofDecoration = 69,
    ExteriorWallDecoration = 70,
    Placard = 71,
    Fence = 72,
    InteriorWall = 73,
    Flooring = 74,
    CeilingLight = 75,
    OutdoorFurnishing = 76,
    Table = 77,
    Tabletop = 78,
    Wallmounted = 79,
    Rug = 80,
    Minion = 81,
    Gardening = 82,
    Demimateria = 83,
    RoguesArm = 84,
    SeasonalMiscellany = 85,
    TripleTriadCard = 86,
    DarkKnightsArm = 87,
    MachinistsArm = 88,
    AstrologiansArm = 89,
    AirshipHull = 90,
    AirshipRigging = 91,
    AirshipAftcastle = 92,
    AirshipForecastle = 93,
    OrchestrionRoll = 94,
    Painting = 95,
    SamuraisArm = 96,
    RedMagesArm = 97,
    ScholarsArm = 98,
    FishersSecondaryTool = 99,
    Currency = 100,
    SubmersibleHull = 101,
    SubmersibleStern = 102,
    SubmersibleBow = 103,
    SubmersibleBridge = 104,
    BlueMagesArm = 105,
    GunbreakersArm = 106,
    DancersArm = 107,
  };

  ///////////////////////////////////////////////////////////
  //ItemSearchCategory.exd
  enum class ItemSearchCategory : uint8_t
  {
    None = 0,
    PrimaryArms = 1,
    PrimaryTools = 2,
    PrimaryTools1 = 3,
    Armor = 4,
    Accessories = 5,
    Medicines = 6,
    Materials = 7,
    Other = 8,
    PugilistsArms = 9,
    GladiatorsArms = 10,
    MaraudersArms = 11,
    ArchersArms = 12,
    LancersArms = 13,
    ThaumaturgesArms = 14,
    ConjurersArms = 15,
    ArcanistsArms = 16,
    Shields = 17,
    DancersArms = 18,
    CarpentersTools = 19,
    BlacksmithsTools = 20,
    ArmorersTools = 21,
    GoldsmithsTools = 22,
    LeatherworkersTools = 23,
    WeaversTools = 24,
    AlchemistsTools = 25,
    CulinariansTools = 26,
    MinersTools = 27,
    BotanistsTools = 28,
    FishersTools = 29,
    FishingTackle = 30,
    Head = 31,
    Undershirts = 32,
    Body = 33,
    Undergarments = 34,
    Legs = 35,
    Hands = 36,
    Feet = 37,
    Waist = 38,
    Necklaces = 39,
    Earrings = 40,
    Bracelets = 41,
    Rings = 42,
    Medicine = 43,
    Ingredients = 44,
    Meals = 45,
    Seafood = 46,
    Stone = 47,
    Metal = 48,
    Lumber = 49,
    Cloth = 50,
    Leather = 51,
    Bone = 52,
    Reagents = 53,
    Dyes = 54,
    WeaponParts = 55,
    Furnishings = 56,
    Materia = 57,
    Crystals = 58,
    Catalysts = 59,
    Miscellany = 60,
    SoulCrystals = 61,
    Arrows = 62,
    QuestItems = 63,
    Other1 = 64,
    ExteriorFixtures = 65,
    InteriorFixtures = 66,
    OutdoorFurnishings = 67,
    ChairsandBeds = 68,
    Tables = 69,
    Tabletop = 70,
    Wallmounted = 71,
    Rugs = 72,
    RoguesArms = 73,
    SeasonalMiscellany = 74,
    Minions = 75,
    DarkKnightsArms = 76,
    MachinistsArms = 77,
    AstrologiansArms = 78,
    AirshipSubmersibleComponents = 79,
    OrchestrionComponents = 80,
    GardeningItems = 81,
    Paintings = 82,
    SamuraisArms = 83,
    RedMagesArms = 84,
    ScholarsArms = 85,
    GunbreakersArms = 86,
    DancersArms1 = 87,
    /*1 = 88,
    2 = 89,
    3 = 90,
    4 = 91,
    5 = 92,
    6 = 93,
    7 = 94,
    8 = 95,
    9 = 96,
    10 = 97,
    11 = 98,
    12 = 99,
    13 = 100,*/
  };

  ///////////////////////////////////////////////////////////
  //OnlineStatus.exd
  enum class OnlineStatus : uint8_t
  {
    Producer = 1,
    GameMaster = 2,
    GameMaster1 = 3,
    GameMaster2 = 4,
    Disconnected = 5,
    WaitingforFriendListApproval = 6,
    WaitingforLinkshellApproval = 7,
    WaitingforFreeCompanyApproval = 8,
    NotFound = 9,
    Offline = 10,
    Mentor = 11,
    Busy = 12,
    PvP = 13,
    PlayingTripleTriad = 14,
    ViewingCutscene = 15,
    UsingaChocoboPorter = 16,
    AwayfromKeyboard = 17,
    CameraMode = 18,
    LookingforRepairs = 19,
    LookingtoRepair = 20,
    LookingtoMeldMateria = 21,
    Roleplaying = 22,
    LookingforParty = 23,
    SwordforHire = 24,
    WaitingforDutyFinder = 25,
    RecruitingPartyMembers = 26,
    Mentor1 = 27,
    PvEMentor = 28,
    TradeMentor = 29,
    PvPMentor = 30,
    Returner = 31,
    NewAdventurer = 32,
    AllianceLeader = 33,
    AlliancePartyLeader = 34,
    AlliancePartyMember = 35,
    PartyLeader = 36,
    PartyMember = 37,
    PartyLeaderCrossworld = 38,
    PartyMemberCrossworld = 39,
    AnotherWorld = 40,
    SharingDuty = 41,
    SimilarDuty = 42,
    InDuty = 43,
    TrialAdventurer = 44,
    FreeCompany = 45,
    GrandCompany = 46,
    Online = 47,
  };

  ///////////////////////////////////////////////////////////
  //Race.exd
  enum class Race : uint8_t
  {
    None = 0,
    Hyur = 1,
    Elezen = 2,
    Lalafell = 3,
    Miqote = 4,
    Roegadyn = 5,
    AuRa = 6,
    Hrothgar = 7,
    Viera = 8,
  };

  ///////////////////////////////////////////////////////////
  //Tribe.exd
  enum class Tribe : uint8_t
  {
    None = 0,
    Midlander = 1,
    Highlander = 2,
    Wildwood = 3,
    Duskwight = 4,
    Plainsfolk = 5,
    Dunesfolk = 6,
    SeekeroftheSun = 7,
    KeeperoftheMoon = 8,
    SeaWolf = 9,
    Hellsguard = 10,
    Raen = 11,
    Xaela = 12,
    Helions = 13,
    TheLost = 14,
    Rava = 15,
    Veena = 16,
  };

  ///////////////////////////////////////////////////////////
  //Town.exd
  enum class Town : uint8_t
  {
    Nowheresville = 0,
    LimsaLominsa = 1,
    Gridania = 2,
    Uldah = 3,
    Ishgard = 4,
    // = 5,
    //1 = 6,
    Kugane = 7,
    //2 = 8,
    //3 = 9,
    Crystarium = 10,
    //4 = 11,
  };

  ///////////////////////////////////////////////////////////
  //Weather.exd
  enum class Weather : uint8_t
  {
    None = 0,
    ClearSkies = 1,
    FairSkies = 2,
    Clouds = 3,
    Fog = 4,
    Wind = 5,
    Gales = 6,
    Rain = 7,
    Showers = 8,
    Thunder = 9,
    Thunderstorms = 10,
    DustStorms = 11,
    Sandstorms = 12,
    HotSpells = 13,
    HeatWaves = 14,
    Snow = 15,
    Blizzards = 16,
    Gloom = 17,
    Auroras = 18,
    Darkness = 19,
    Tension = 20,
    Clouds1 = 21,
    StormClouds = 22,
    RoughSeas = 23,
    RoughSeas1 = 24,
    Louring = 25,
    HeatWaves1 = 26,
    Gloom1 = 27,
    Gales1 = 28,
    Eruptions = 29,
    FairSkies1 = 30,
    FairSkies2 = 31,
    FairSkies3 = 32,
    FairSkies4 = 33,
    FairSkies5 = 34,
    Irradiance = 35,
    CoreRadiation = 36,
    CoreRadiation1 = 37,
    CoreRadiation2 = 38,
    CoreRadiation3 = 39,
    ShelfClouds = 40,
    ShelfClouds1 = 41,
    ShelfClouds2 = 42,
    ShelfClouds3 = 43,
    Oppression = 44,
    Oppression1 = 45,
    Oppression2 = 46,
    Oppression3 = 47,
    Oppression4 = 48,
    UmbralWind = 49,
    UmbralStatic = 50,
    Smoke = 51,
    FairSkies6 = 52,
    RoyalLevin = 53,
    Hyperelectricity = 54,
    RoyalLevin1 = 55,
    Oppression5 = 56,
    Thunder1 = 57,
    Thunder2 = 58,
    CutScene = 59,
    Multiplicity = 60,
    Multiplicity1 = 61,
    Rain1 = 62,
    FairSkies7 = 63,
    Rain2 = 64,
    FairSkies8 = 65,
    Dragonstorms = 66,
    Dragonstorms1 = 67,
    Subterrain = 68,
    Concordance = 69,
    Concordance1 = 70,
    BeyondTime = 71,
    BeyondTime1 = 72,
    BeyondTime2 = 73,
    DemonicInfinity = 74,
    DemonicInfinity1 = 75,
    DemonicInfinity2 = 76,
    DimensionalDisruption = 77,
    DimensionalDisruption1 = 78,
    DimensionalDisruption2 = 79,
    Revelstorms = 80,
    Revelstorms1 = 81,
    EternalBliss = 82,
    EternalBliss1 = 83,
    Wyrmstorms = 84,
    Wyrmstorms1 = 85,
    Revelstorms2 = 86,
    Quicklevin = 87,
    Thunder3 = 88,
    DimensionalDisruption3 = 89,
    FairSkies9 = 90,
    ClearSkies1 = 91,
    WhiteCyclones = 92,
    WhiteCyclones1 = 93,
    WhiteCyclones2 = 94,
    Ultimania = 95,
    WhiteCyclones3 = 96,
    Moonlight = 97,
    Moonlight1 = 98,
    Moonlight2 = 99,
    Moonlight3 = 100,
    RedMoon = 101,
    Scarlet = 102,
    Scarlet1 = 103,
    Scarlet2 = 104,
    FairSkies10 = 105,
    FairSkies11 = 106,
    FairSkies12 = 107,
    FairSkies13 = 108,
    Flames = 109,
    Tsunamis = 110,
    Cyclones = 111,
    Geostorms = 112,
    TrueBlue = 113,
    TrueBlue1 = 114,
    TrueBlue2 = 115,
    UmbralTurbulence = 116,
    TrueBlue3 = 117,
    EverlastingLight = 118,
    Gales2 = 119,
    Termination = 120,
    Termination1 = 121,
    Dreams = 122,
    Dreams1 = 123,
    Dreams2 = 124,
    Brilliance = 125,
    Brilliance1 = 126,
    Termination2 = 127,
    Termination3 = 128,
    EverlastingLight1 = 129,
    Eruptions1 = 130,
    Termination4 = 131,
    FairSkies14 = 132,
    UmbralFlare = 133,
    UmbralDuststorm = 134,
    UmbralLevin = 135,
    UmbralTempest = 136,
    Starshower = 137,
    Delirium = 138,
    Clouds2 = 139,
    Clouds3 = 140,
    Irradiance1 = 141,
    Irradiance2 = 142,
    StormClouds1 = 143,
    Firestorm = 144,
    SpectralCurrent = 145,
    //1 = 146,
    Climactic = 147,
    //2 = 148,
    //3 = 149,
    //4 = 150,
    //5 = 151,
    //6 = 152,
    //7 = 153,
  };

  ///////////////////////////////////////////////////////////
  //HousingAppeal.exd
  enum class HousingAppeal : uint8_t
  {
    None = 0,
    Emporium = 1,
    Boutique = 2,
    DesignerHome = 3,
    MessageBook = 4,
    Tavern = 5,
    Eatery = 6,
    ImmersiveExperience = 7,
    Cafe = 8,
    Aquarium = 9,
    Sanctum = 10,
    Venue = 11,
    Florist = 12,
    // = 13,
    Library = 14,
    PhotoStudio = 15,
    HauntedHouse = 16,
    Atelier = 17,
    Bathhouse = 18,
    Garden = 19,
    FarEastern = 20,
    VisitorsWelcome = 21,
    Bakery = 22,
    UnderRenovation = 23,
    ConcertHall = 24,
  };
}
#endif