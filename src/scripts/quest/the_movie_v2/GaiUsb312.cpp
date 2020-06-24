// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb312_00853
// Quest Name: The Stench of Danger
// Quest ID: 66389
// Start NPC: 1006271
// End NPC: 1006271

using namespace Sapphire;

class GaiUsb312 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006271;
//    static constexpr auto Actor1 = 1007563;
//    static constexpr auto Enemy0 = 4293341;
//    static constexpr auto Enemy1 = 4293342;
//    static constexpr auto Enemy2 = 4293343;
//    static constexpr auto Eobject0 = 2002295;
//    static constexpr auto Eventrange0 = 4293329;
//    static constexpr auto EventActionSearch = 1;

  public:
    GaiUsb312() : Sapphire::ScriptAPI::EventScript( 66389 ){}; 
    ~GaiUsb312() = default; 

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
//ENEMY0, UI8AL, 3, -2, False
if( actorId == 4293341 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00002( player ); }
//ENEMY1, UI8AL, 3, -2, False
if( actorId == 4293342 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00003( player ); }
//ENEMY2, UI8AL, 3, -2, False
if( actorId == 4293343 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00004( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007563 ) { Scene00005( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002295 ) { Scene00006( player ); }
break;
}
case 2:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1007563 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00007( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002295 ) { Scene00008( player ); }
break;
}
case 255:{
Scene00009( player );
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Message:Scene00002 ENEMY0:UI8AL=-2, 3", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: ENEMY1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 ENEMY1:UI8AL=-2, 3", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: ENEMY2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 ENEMY2:UI8AL=-2, 3", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT0", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT0", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb312 );
