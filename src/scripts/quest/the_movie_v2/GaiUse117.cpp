// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse117_01191
// Quest Name: On the Properties of Primals
// Quest ID: 66727
// Start NPC: 1006751
// End NPC: 1006693

using namespace Sapphire;

class GaiUse117 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006751;
//    static constexpr auto Actor1 = 1003027;
//    static constexpr auto Actor2 = 1008274;
//    static constexpr auto Actor3 = 1008272;
//    static constexpr auto Actor4 = 1008273;
//    static constexpr auto Actor5 = 1000460;
//    static constexpr auto Actor6 = 1006693;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocAction0 = 787;
//    static constexpr auto LocActor01 = 1005013;
//    static constexpr auto LocActor02 = 1005014;
//    static constexpr auto LocActor03 = 1003069;
//    static constexpr auto LocActor11 = 1004396;
//    static constexpr auto LocActor12 = 1004397;
//    static constexpr auto LocActor13 = 1004398;
//    static constexpr auto LocActor14 = 1004399;
//    static constexpr auto LocActor15 = 1004400;
//    static constexpr auto LocPosition01 = 4491673;
//    static constexpr auto LocPosition02 = 4491674;
//    static constexpr auto LocPosition03 = 4491675;
//    static constexpr auto LocPosition11 = 4065819;
//    static constexpr auto LocPosition12 = 4065820;
//    static constexpr auto LocPosition13 = 4065821;
//    static constexpr auto LocPosition14 = 4065822;
//    static constexpr auto LocPosition15 = 4065823;
//    static constexpr auto MotEventJoyBig = 945;
//    static constexpr auto Poprange0 = 3877982;
//    static constexpr auto PubActorL = 4307833;
//    static constexpr auto PubActorR = 4307834;
//    static constexpr auto Territorytype0 = 205;

  public:
    GaiUse117() : Sapphire::ScriptAPI::EventScript( 66727 ){}; 
    ~GaiUse117() = default; 

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
if( actor == 1003027 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008274 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008272 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008273 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1000460 ) { Scene00006( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006751 ) { Scene00007( player ); }
break;
}
case 255:{
//ACTOR6, null, 0, -2, False
if( actor == 1006693 ) { Scene00008( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1003027 ) { Scene00009( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008274 ) { Scene00010( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008272 ) { Scene00011( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008273 ) { Scene00012( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1000460 ) { Scene00013( player ); }
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
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR4", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00006 ACTOR5", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR0", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00008 ACTOR6", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR2", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR3", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR4", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR5", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse117 );
