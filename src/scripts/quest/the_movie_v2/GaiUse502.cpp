// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse502_00364
// Quest Name: Bait and Switch
// Quest ID: 65900
// Start NPC: 1010845
// End NPC: 1010849

using namespace Sapphire;

class GaiUse502 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1010845;
//    static constexpr auto Actor1 = 1010923;
//    static constexpr auto Actor2 = 1010846;
//    static constexpr auto Actor3 = 1010847;
//    static constexpr auto Actor4 = 1010849;
//    static constexpr auto Actor5 = 1010848;
//    static constexpr auto Enemy0 = 5589283;
//    static constexpr auto Enemy1 = 5589284;
//    static constexpr auto Enemy2 = 5589285;
//    static constexpr auto Enemy3 = 5589286;
//    static constexpr auto Eobject0 = 2005112;
//    static constexpr auto Eobject1 = 2005107;
//    static constexpr auto EventActionWaiting2Middle = 12;
//    static constexpr auto LocActor0 = 5580509;
//    static constexpr auto LocActor1 = 1010849;
//    static constexpr auto LocActor2 = 1010848;
//    static constexpr auto LocActor3 = 5580514;
//    static constexpr auto LocEobject0 = 2005125;
//    static constexpr auto LocMotion0 = 1045;

  public:
    GaiUse502() : Sapphire::ScriptAPI::EventScript( 65900 ){}; 
    ~GaiUse502() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1010845 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010923 ) { Scene00002( player ); }
break;
}
case 1:{
Scene00003( player );
break;
}
case 2:{
//ACTOR3, null, 0, -2, False
if( actor == 1010847 ) { Scene00004( player ); }
break;
}
case 3:{
Scene00005( player );
break;
}
case 255:{
//ACTOR4, null, 0, -2, False
if( actor == 1010849 ) { Scene00012( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2005107 ) { Scene00013( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010848 ) { Scene00014( player ); }
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


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00002 ACTOR1", getId() );


  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00005 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00006 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00007 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 ", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00011 ", getId() );

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
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00012 ACTOR4", getId() );

    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00013 EOBJECT1", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR5", getId() );


  }

};

EXPOSE_SCRIPT( GaiUse502 );
