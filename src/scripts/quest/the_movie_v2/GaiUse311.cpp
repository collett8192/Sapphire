// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse311_01452
// Quest Name: Levin an Impression
// Quest ID: 66988
// Start NPC: 1009119
// End NPC: 1009097

using namespace Sapphire;

class GaiUse311 : public Sapphire::ScriptAPI::EventScript
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
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventByebye = 962;
//    static constexpr auto Actor0 = 1009119;
//    static constexpr auto Actor1 = 1009117;
//    static constexpr auto Actor2 = 1009120;
//    static constexpr auto Actor3 = 1009121;
//    static constexpr auto Actor4 = 1009116;
//    static constexpr auto Actor5 = 1009124;
//    static constexpr auto Actor6 = 1009125;
//    static constexpr auto Actor7 = 1009126;
//    static constexpr auto Actor8 = 5010000;
//    static constexpr auto Actor9 = 1009097;
//    static constexpr auto CutSceneN01 = 534;
//    static constexpr auto CutSceneN02 = 535;
//    static constexpr auto Eventrange0 = 4841610;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Instancedungeon0 = 20022;
//    static constexpr auto LevelIdNpc01 = 4868016;
//    static constexpr auto LevelIdNpc02 = 4868018;
//    static constexpr auto LevelIdNpc03 = 4868019;
//    static constexpr auto LevelIdNpc04 = 4868015;
//    static constexpr auto LevelIdNpc05 = 4841607;
//    static constexpr auto LevelIdNpc06 = 4841608;
//    static constexpr auto LevelIdNpc07 = 4841609;
//    static constexpr auto Poprange0 = 4868026;
//    static constexpr auto Territorytype0 = 152;
//    static constexpr auto UnlockAddNewContentToCf = 3702;
//    static constexpr auto UnlockDungeonRamuhHard = 222;

  public:
    GaiUse311() : Sapphire::ScriptAPI::EventScript( 66988 ){}; 
    ~GaiUse311() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1009119 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009117 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009120 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009121 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009116 ) { Scene00005( player ); }
break;
}
case 1:{
//ACTOR5, null, 0, -2, False
if( actor == 1009124 ) { Scene00007( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009125 ) { Scene00008( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009126 ) { Scene00009( player ); }
break;
}
case 2:{
Scene00010( player );
break;
}
case 3:{
//no scene is assigned
break;
}
case 255:{
Scene00012( player );
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1", getId() );

    player.playScene( getId(), 2, NONE, callback );
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
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](5)CutScene:Scene00006 ACTOR4", getId() );

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message, FadeOut:Scene00007 ACTOR5", getId() );

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR6", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR7", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00010 +1 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](10)CutScene:Scene00011 ", getId() );

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse311 );
