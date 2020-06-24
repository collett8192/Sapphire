// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubWil067_00321
// Quest Name: The Slaying of the Shrews
// Quest ID: 65857
// Start NPC: 1001457
// End NPC: 1001457

using namespace Sapphire;

class SubWil067 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1001457;
//    static constexpr auto Enemy0 = 3785533;
//    static constexpr auto Enemy1 = 3785534;
//    static constexpr auto Enemy2 = 3785535;
//    static constexpr auto Eobject0 = 2000372;
//    static constexpr auto Eobject1 = 2000373;
//    static constexpr auto Eobject2 = 2000374;
//    static constexpr auto EventActionSearch = 1;

  public:
    SubWil067() : Sapphire::ScriptAPI::EventScript( 65857 ){}; 
    ~SubWil067() = default; 

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
if( actor == 2000372 ) { Scene00002( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 3785533 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2000373 ) { Scene00008( player ); }
//ENEMY1, UI8BH, 1, -2, False
if( actorId == 3785534 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00011( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2000374 ) { Scene00014( player ); }
//ENEMY2, UI8BL, 1, -2, False
if( actorId == 3785535 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00017( player ); }
break;
}
case 255:{
Scene00019( player );
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
if( result.param2 == 1 ){
player.updateQuest( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](2)Empty:Scene00001 EOBJECT0", getId() );


  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00002 +2 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](2)Empty:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: ENEMY0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](5)Empty:Scene00004 ENEMY0:UI8AL=-2, 1", getId() );


  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
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


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](8)Empty:Scene00007 EOBJECT1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00008 +2 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](8)Empty:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: ENEMY1
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](11)Empty:Scene00010 ENEMY1:UI8BH=-2, 1", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00011 +2 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](11)Empty:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](14)Empty:Scene00013 EOBJECT2", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00014 +2 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](14)Empty:Scene00015 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: ENEMY2
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](17)Empty:Scene00016 ENEMY2:UI8BL=-2, 1", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00017 +2 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](17)Empty:Scene00018 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00019 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubWil067 );
