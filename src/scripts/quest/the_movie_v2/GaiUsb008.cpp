// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: True, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb008_00815
// Quest Name: The Penitent Man
// Quest ID: 66351
// Start NPC: 1006279
// End NPC: 1006279

using namespace Sapphire;

class GaiUsb008 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006279;
//    static constexpr auto Enemy0 = 4292783;
//    static constexpr auto Enemy1 = 2194;
//    static constexpr auto Eobject0 = 2002038;
//    static constexpr auto Eobject1 = 2002037;
//    static constexpr auto Eobject2 = 2002039;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionSearchMiddle = 3;
//    static constexpr auto Item0 = 2000959;
//    static constexpr auto Item1 = 2000638;
//    static constexpr auto LocActor0 = 1006283;
//    static constexpr auto LocPosActor0 = 4256141;

  public:
    GaiUsb008() : Sapphire::ScriptAPI::EventScript( 66351 ){}; 
    ~GaiUsb008() = default; 

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
if( actor == 2002038 ) { Scene00002( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4292783 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ENEMY1, null, 0, -2, False
if( actorId == 2194 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002037 ) { Scene00006( player ); }
break;
}
case 2:{
Scene00007( player );
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00002 EOBJECT0", getId() );


  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00003 +1 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](3)Empty:Scene00004 ENEMY0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: ENEMY1
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00005 ENEMY1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00007 ", getId() );


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
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](8)Talk, QuestReward, QuestComplete:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb008 );
