// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb010_00817
// Quest Name: We'll Always Have Ul'dah
// Quest ID: 66353
// Start NPC: 1006283
// End NPC: 1006283

using namespace Sapphire;

class GaiUsb010 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006283;
//    static constexpr auto Actor1 = 1006284;
//    static constexpr auto Actor2 = 1006285;
//    static constexpr auto Actor3 = 1007646;
//    static constexpr auto Enemy0 = 4292844;
//    static constexpr auto Enemy1 = 4292847;
//    static constexpr auto Eobject0 = 2002289;
//    static constexpr auto Eventrange0 = 4292885;
//    static constexpr auto EventActionRescueUnderMiddle = 35;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000639;

  public:
    GaiUsb010() : Sapphire::ScriptAPI::EventScript( 66353 ){}; 
    ~GaiUsb010() = default; 

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
//ACTOR1, null, 0, -2, False
if( actor == 1006284 ) { Scene00002( player ); }
//if( actorId == 4292844 && player.getQuestUI8AL( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 4292847 && player.getQuestUI8AL( getId() ) != 2 ) { Scene?????( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006285 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007646 ) { Scene00005( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002289 ) { Scene00006( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -1, False
if( actor == 1006283 ) { Scene00009( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1006284 ) { Scene00012( player ); }
//ACTOR2, null, 0, -1, False
if( actor == 1006285 ) { Scene00013( player ); }
//if( actor == 1007646 ) { Scene?????( player ); }
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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
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
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](2)Message:Scene00003 ACTOR1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR2", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR3", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT0", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00007 ", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00008 ", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00010( player ); }
 else { Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00009 +2 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](9)Talk, QuestReward, QuestComplete:Scene00010 ACTOR0", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](9)Talk:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR1", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR2", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb010 );
