// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsc603_01003
// Quest Name: Dressed for Conquest
// Quest ID: 66539
// Start NPC: 1006552
// End NPC: 1006552

using namespace Sapphire;

class GaiUsc603 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
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
//      Seq2 = 2,
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006552;
//    static constexpr auto Actor1 = 1001685;
//    static constexpr auto Actor2 = 1001000;
//    static constexpr auto Enemy0 = 64;
//    static constexpr auto Enemy1 = 63;
//    static constexpr auto Enemy2 = 62;
//    static constexpr auto Enemy3 = 55;
//    static constexpr auto Enemy4 = 61;
//    static constexpr auto Item0 = 2000767;
//    static constexpr auto Item1 = 2000768;
//    static constexpr auto Item2 = 2000769;
//    static constexpr auto Item3 = 2000770;
//    static constexpr auto LocActor1 = 1001682;
//    static constexpr auto LocActor2 = 1001013;
//    static constexpr auto LocPosActor1 = 4308329;
//    static constexpr auto LocPosActor2 = 2367980;

  public:
    GaiUsc603() : Sapphire::ScriptAPI::EventScript( 66539 ){}; 
    ~GaiUsc603() = default; 

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

case 2:{
Scene00002( player );
break;
}
case 3:{
//ACTOR1, UI8AL, 1, -1, False
if( actor == 1001685 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR2, UI8BH, 1, -1, False
if( actor == 1001000 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00006( player ); }
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
//      case Enemy2: { break; }
//      case Enemy3: { break; }
//      case Enemy4: { break; }
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
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8CL( getId(), 3 );
player.setQuestUI8CH( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](2)Talk:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00004 +1 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //Target: ACTOR1
      player.setQuestUI8AL( getId(), 1 );
      if( player.getQuestUI8AL( getId() ) == 1 ){
        if( player.getQuestUI8BH( getId() ) == 1 ){
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 3 );
          player.updateQuest( getId(), 255 );
        }
      }
    };
player.sendDebug( "questId: {}, calling [sub:Execute](4)Talk, FadeOut:Scene00005 ", getId() );

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 3 );
player.updateQuest( getId(), 255 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](6)Talk, FadeOut:Scene00007 ACTOR1:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
player.sendDebug( "questId: {}, calling [sub:Execute](8)QuestReward, QuestComplete:Scene00009 ACTOR2:UI8BH=-1, 1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsc603 );