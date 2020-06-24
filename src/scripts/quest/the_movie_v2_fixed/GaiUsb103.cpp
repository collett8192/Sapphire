// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb103_00822
// Quest Name: When the Worm Turns
// Quest ID: 66358
// Start NPC: 1004917
// End NPC: 1004917

using namespace Sapphire;

class GaiUsb103 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH

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
//    static constexpr auto Actor0 = 1004917;
//    static constexpr auto Actor1 = 1007626;
//    static constexpr auto Enemy0 = 356;
//    static constexpr auto Enemy1 = 4293190;
//    static constexpr auto Eobject0 = 2002046;
//    static constexpr auto Eobject1 = 2002576;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionWaiting = 10;
//    static constexpr auto Item0 = 2000645;
//    static constexpr auto Item1 = 2000833;

  public:
    GaiUsb103() : Sapphire::ScriptAPI::EventScript( 66358 ){}; 
    ~GaiUsb103() = default; 

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
Scene00002( player );
break;
}
case 2:{
Scene00003( player );
break;
}
case 3:{
//EOBJECT1, null, 0, -2, False
if( actor == 2002576 ) { Scene00005( player ); }
//ENEMY1, UI8AL, 1, -2, False
if( actorId == 4293190 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00007( player ); }
//ACTOR1, null, 0, -2, False
//if( actor == 1007626 ) { Scene00008( player ); }
break;
}
case 255:{
Scene00008( player );
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
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    //auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    //{
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
    //};
player.sendDebug( "questId: {}, calling Inventory:Scene00002 ", getId() );

    //player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00003 ", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](5)Empty:Scene00004 EOBJECT1", getId() );


  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00005 +2 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](5)Empty:Scene00006 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: ENEMY1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00007 ENEMY1:UI8AL=-2, 1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00008 +1 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](8)Talk, QuestReward, QuestComplete:Scene00009 ACTOR1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb103 );
