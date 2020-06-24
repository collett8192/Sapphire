// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsc002_00939
// Quest Name: By the Lights of Ishgard
// Quest ID: 66475
// Start NPC: 1006467
// End NPC: 1006467

using namespace Sapphire;

class GaiUsc002 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006467;
//    static constexpr auto Actor1 = 1007631;
//    static constexpr auto Enemy0 = 4297103;
//    static constexpr auto Enemy1 = 4297104;
//    static constexpr auto Enemy2 = 4297106;
//    static constexpr auto Eobject0 = 2002170;
//    static constexpr auto Eobject1 = 2002322;
//    static constexpr auto Eobject2 = 2002590;
//    static constexpr auto Eventrange0 = 4297079;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000733;

  public:
    GaiUsc002() : Sapphire::ScriptAPI::EventScript( 66475 ){}; 
    ~GaiUsc002() = default; 

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
//EOBJECT0, null, 0, -2, False
if( actor == 2002170 ) { Scene00002( player ); }
//ENEMY0, UI8AL, 3, -2, False
if( actorId == 4297103 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00004( player ); }
//ENEMY1, UI8AL, 3, -2, False
if( actorId == 4297104 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00005( player ); }
//ENEMY2, UI8AL, 3, -2, False
if( actorId == 4297106 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00006( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002322 ) { Scene00007( player ); }
break;
}
case 2:{
//EOBJECT2, UI8AL, 1, -2, False
if( actor == 2002590 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007631 ) { Scene00009( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -1, False
if( actor == 1006467 ) { Scene00010( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1007631 ) { Scene00012( player ); }
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
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
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
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](2)Message:Scene00003 EOBJECT0", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: ENEMY0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 ENEMY0:UI8AL=-2, 3", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: ENEMY1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 ENEMY1:UI8AL=-2, 3", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ENEMY2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00006 ENEMY2:UI8AL=-2, 3", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT2:UI8AL=-2, 1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00010 +1 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](10)Talk, QuestReward, QuestComplete:Scene00011 ACTOR0", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR1", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsc002 );
