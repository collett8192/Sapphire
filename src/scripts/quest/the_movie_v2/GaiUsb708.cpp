// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb708_00903
// Quest Name: Too Many Enemies
// Quest ID: 66439
// Start NPC: 1006403
// End NPC: 1006403

using namespace Sapphire;

class GaiUsb708 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006403;
//    static constexpr auto Actor1 = 1007701;
//    static constexpr auto Actor2 = 1007702;
//    static constexpr auto Enemy0 = 4292758;
//    static constexpr auto Enemy1 = 4293100;
//    static constexpr auto Eobject0 = 2002131;
//    static constexpr auto Eobject1 = 2002509;
//    static constexpr auto Eobject2 = 2002626;
//    static constexpr auto Eobject3 = 2002627;
//    static constexpr auto Eventrange0 = 4292757;
//    static constexpr auto EventActionSearch = 1;

  public:
    GaiUsb708() : Sapphire::ScriptAPI::EventScript( 66439 ){}; 
    ~GaiUsb708() = default; 

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
//ENEMY0, UI8AL, 2, -2, False
if( actorId == 4292758 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00002( player ); }
//ENEMY1, UI8AL, 2, -2, False
if( actorId == 4293100 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00004( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002131 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002509 ) { Scene00006( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002626 ) { Scene00007( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002627 ) { Scene00008( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007701 ) { Scene00009( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1007702 ) { Scene00010( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006403 ) { Scene00013( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002131 ) { Scene00014( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002626 ) { Scene00015( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002627 ) { Scene00016( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007701 ) { Scene00017( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1007702 ) { Scene00018( player ); }
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
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](2)Empty:Scene00003 ENEMY0:UI8AL=-2, 2", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: ENEMY1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 2 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 ENEMY1:UI8AL=-2, 2", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT0", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT2", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT3", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR2", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 ", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00012 ", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00013 ACTOR0", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00014 EOBJECT0", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00015 EOBJECT2", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00016 EOBJECT3", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR1", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR2", getId() );


  }

  void Scene00019( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00019 ", getId() );


  }

  void Scene00020( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00020 ", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00021 ", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb708 );
