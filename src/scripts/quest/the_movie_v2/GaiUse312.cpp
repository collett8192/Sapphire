// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse312_01453
// Quest Name: What Little Gods Are Made Of
// Quest ID: 66989
// Start NPC: 1009097
// End NPC: 1008969

using namespace Sapphire;

class GaiUse312 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1009097;
//    static constexpr auto Actor1 = 1003027;
//    static constexpr auto Actor10 = 1009134;
//    static constexpr auto Actor11 = 1008969;
//    static constexpr auto Actor2 = 1009091;
//    static constexpr auto Actor3 = 1009092;
//    static constexpr auto Actor4 = 1009093;
//    static constexpr auto Actor5 = 1009094;
//    static constexpr auto Actor6 = 1000460;
//    static constexpr auto Actor7 = 1009096;
//    static constexpr auto Actor8 = 1009095;
//    static constexpr auto Actor9 = 1009127;
//    static constexpr auto BgmNothing = 1;
//    static constexpr auto CutSceneN01 = 536;
//    static constexpr auto CutSceneN02 = 537;
//    static constexpr auto CutSceneN03 = 542;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Poprange0 = 3877982;
//    static constexpr auto Poprange1 = 3878860;
//    static constexpr auto Territorytype0 = 205;

  public:
    GaiUse312() : Sapphire::ScriptAPI::EventScript( 66989 ){}; 
    ~GaiUse312() = default; 

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
//ACTOR0, null, 0, -2, False
if( actor == 1009097 ) { Scene00003( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009091 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009092 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009093 ) { Scene00006( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009094 ) { Scene00007( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1000460 ) { Scene00008( player ); }
break;
}
case 2:{
//ACTOR7, UI8AL, 1, -2, False
if( actor == 1009096 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00009( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1009095 ) { Scene00010( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1009127 ) { Scene00011( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1009134 ) { Scene00012( player ); }
break;
}
case 255:{
//ACTOR11, null, 0, -2, False
if( actor == 1008969 ) { Scene00013( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1009095 ) { Scene00015( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009096 ) { Scene00016( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1009127 ) { Scene00017( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1009134 ) { Scene00018( player ); }
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
player.sendDebug( "questId: {}, calling CutScene:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

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
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR2", getId() );

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
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00008 ACTOR6", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR7:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR8", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR9", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR10", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
Scene00014( player );
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward:Scene00013 +1 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
    };
player.sendDebug( "questId: {}, calling [sub:Complete](13)CutScene, QuestComplete:Scene00014 ACTOR11", getId() );

    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR8", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR7", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR9", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR10", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse312 );
