// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse315_01456
// Quest Name: Guardian of Eorzea
// Quest ID: 66992
// Start NPC: 1009058
// End NPC: 1009021

using namespace Sapphire;

class GaiUse315 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineFacialLaughStrong = 609;
//    static constexpr auto ActionTimelineFacialSmile = 605;
//    static constexpr auto Actor0 = 1009058;
//    static constexpr auto Actor1 = 1008980;
//    static constexpr auto Actor10 = 1008993;
//    static constexpr auto Actor11 = 1008994;
//    static constexpr auto Actor12 = 1008995;
//    static constexpr auto Actor13 = 1008996;
//    static constexpr auto Actor14 = 1008997;
//    static constexpr auto Actor15 = 1008998;
//    static constexpr auto Actor16 = 1008999;
//    static constexpr auto Actor17 = 1009000;
//    static constexpr auto Actor18 = 1009001;
//    static constexpr auto Actor19 = 1009002;
//    static constexpr auto Actor2 = 1009282;
//    static constexpr auto Actor20 = 1009003;
//    static constexpr auto Actor21 = 1009004;
//    static constexpr auto Actor22 = 1009005;
//    static constexpr auto Actor23 = 1009006;
//    static constexpr auto Actor24 = 1009007;
//    static constexpr auto Actor3 = 1009283;
//    static constexpr auto Actor4 = 1009284;
//    static constexpr auto Actor5 = 1009285;
//    static constexpr auto Actor6 = 1009286;
//    static constexpr auto Actor7 = 1009287;
//    static constexpr auto Actor8 = 1009021;
//    static constexpr auto Actor9 = 1008969;
//    static constexpr auto Eobject0 = 2004306;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocActor0 = 4725232;
//    static constexpr auto LocActor1 = 4725233;
//    static constexpr auto LocActor2 = 4725234;
//    static constexpr auto LocActor3 = 4725226;
//    static constexpr auto LocActor4 = 4725227;
//    static constexpr auto Questbattle0 = 89;
//    static constexpr auto Territorytype0 = 379;

  public:
    GaiUse315() : Sapphire::ScriptAPI::EventScript( 66992 ){}; 
    ~GaiUse315() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
Scene00000( player );
break;
}
case 1:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1008980 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1009058 ) { Scene00003( player ); }
break;
}
case 2:{
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1009282 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009283 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009284 ) { Scene00006( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009285 ) { Scene00007( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009286 ) { Scene00008( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009287 ) { Scene00009( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004306 ) { Scene00010( player ); }
break;
}
case 255:{
//ACTOR8, null, 0, -2, False
if( actor == 1009021 ) { Scene00011( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1008969 ) { Scene00012( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1008993 ) { Scene00013( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008994 ) { Scene00014( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008995 ) { Scene00015( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1008996 ) { Scene00016( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1008997 ) { Scene00017( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1008998 ) { Scene00018( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1008999 ) { Scene00019( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1009000 ) { Scene00020( player ); }
//ACTOR18, null, 0, -2, False
if( actor == 1009001 ) { Scene00021( player ); }
//ACTOR19, null, 0, -2, False
if( actor == 1009002 ) { Scene00022( player ); }
//ACTOR20, null, 0, -2, False
if( actor == 1009003 ) { Scene00023( player ); }
//ACTOR21, null, 0, -2, False
if( actor == 1009004 ) { Scene00024( player ); }
//ACTOR22, null, 0, -2, False
if( actor == 1009005 ) { Scene00025( player ); }
//ACTOR23, null, 0, -2, False
if( actor == 1009006 ) { Scene00026( player ); }
//ACTOR24, null, 0, -2, False
if( actor == 1009007 ) { Scene00027( player ); }
break;
}
default: { player.sendUrgent( "seq {} not defined.", player.getQuestSeq( getId() ) ); break; }
}
  }


  private:
  //////////////////////////////////////////////////////////////////////
  // Available Scenes in this quest, not necessarly all are used
  void Scene00000( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
Scene00001( player );
    };
player.sendDebug( "questId: {}, calling QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR0", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestBattle, YesNo:Scene00004 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR3", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR4", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR5", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR6", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR7", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 EOBJECT0", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00011 ACTOR8", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR9", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR10", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR11", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR12", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR13", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR14
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR14", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR15
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR15", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR16
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR16", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR17
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR17", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR18
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00021 ACTOR18", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR19
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR19", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR20
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR20", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR21
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR21", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR22
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR22", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR23
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR23", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR24
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR24", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse315 );
