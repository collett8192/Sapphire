// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubWil036_00228
// Quest Name: Getting Your Bearings
// Quest ID: 65764
// Start NPC: 1002030
// End NPC: 1002044

using namespace Sapphire;

class SubWil036 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1002030;
//    static constexpr auto Actor1 = 1002044;
//    static constexpr auto Enemy0 = 3923955;
//    static constexpr auto Enemy1 = 3949791;
//    static constexpr auto Enemy2 = 3949797;
//    static constexpr auto Eobject0 = 2001276;
//    static constexpr auto Eobject1 = 2001356;
//    static constexpr auto Eobject2 = 2001357;
//    static constexpr auto Eventrange0 = 4084925;
//    static constexpr auto Eventrange1 = 4084894;
//    static constexpr auto Eventrange2 = 4084766;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000153;

  public:
    SubWil036() : Sapphire::ScriptAPI::EventScript( 65764 ){}; 
    ~SubWil036() = default; 

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
if( actor == 2001276 ) { Scene00002( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 3923955 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001356 ) { Scene00005( player ); }
//ENEMY1, UI8BH, 1, -2, False
if( actorId == 3949791 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00007( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001357 ) { Scene00008( player ); }
//ENEMY2, UI8BL, 1, -2, False
if( actorId == 3949797 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00010( player ); }
break;
}
case 255:{
Scene00011( player );
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
player.setQuestUI8CH( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
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
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 ENEMY0:UI8AL=-2, 1", getId() );


  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](5)Message:Scene00006 EOBJECT1", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
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
player.setQuestUI8BH( getId(), 3 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00007 ENEMY1:UI8BH=-2, 1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00008 +1 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](8)Message:Scene00009 EOBJECT2", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
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
player.setQuestUI8BH( getId(), 3 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00010 ENEMY2:UI8BL=-2, 1", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00012( player ); }
 else { Scene00013( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00011 +2 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](11)Talk, QuestReward, QuestComplete:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](11)Empty:Scene00013 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubWil036 );
