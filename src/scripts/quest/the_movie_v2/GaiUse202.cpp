// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: True, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse202_01346
// Quest Name: A Final Temptation
// Quest ID: 66882
// Start NPC: 1008597
// End NPC: 1002058

using namespace Sapphire;

class GaiUse202 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1008597;
//    static constexpr auto Actor1 = 1008702;
//    static constexpr auto Actor2 = 1002058;
//    static constexpr auto Actor3 = 1008598;
//    static constexpr auto Actor4 = 1008599;
//    static constexpr auto Enemy0 = 4620255;
//    static constexpr auto Enemy1 = 4620256;
//    static constexpr auto Enemy2 = 4620257;
//    static constexpr auto Enemy3 = 4620258;
//    static constexpr auto Eobject0 = 2003561;
//    static constexpr auto Eobject1 = 2003562;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionSearchShort = 2;
//    static constexpr auto EventActionWatchguardLong = 28;
//    static constexpr auto LocAction1 = 1002;
//    static constexpr auto LocActior0 = 1008176;
//    static constexpr auto LocActior1 = 1008177;
//    static constexpr auto LocFace0 = 605;
//    static constexpr auto LocFace1 = 604;
//    static constexpr auto LocFace2 = 619;
//    static constexpr auto LocSe1 = 42;

  public:
    GaiUse202() : Sapphire::ScriptAPI::EventScript( 66882 ){}; 
    ~GaiUse202() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1008597 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008702 ) { Scene00002( player ); }
break;
}
case 1:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1002058 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008597 ) { Scene00004( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008702 ) { Scene00005( player ); }
break;
}
case 2:{
//EOBJECT0, null, 0, -2, False
if( actor == 2003561 ) { Scene00006( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008598 ) { Scene00008( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008599 ) { Scene00009( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2003562 ) { Scene00010( player ); }
break;
}
case 3:{
//ACTOR3, UI8AL, 1, -2, False
if( actor == 1008598 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00011( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008599 ) { Scene00012( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2003562 ) { Scene00013( player ); }
break;
}
case 255:{
//ACTOR2, null, 0, -2, False
if( actor == 1002058 ) { Scene00014( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008597 ) { Scene00015( player ); }
break;
}
default: { player.sendUrgent( "seq {} not defined.", player.getQuestSeq( getId() ) ); break; }
}
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
//    switch( npcId )
//    {
//      case Enemy0: { break; }
//      case Enemy1: { break; }
//      case Enemy2: { break; }
//      case Enemy3: { break; }
//    }
onTalk( getId(), player, npcId );
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
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00003 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR0", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](6)Message:Scene00007 EOBJECT0", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR3", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR4", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 EOBJECT1", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00011 ACTOR3:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR4", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 EOBJECT1", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00014 ACTOR2", getId() );

    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR0", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse202 );
