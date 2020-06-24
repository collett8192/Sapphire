// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: True, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa002_00708
// Quest Name: We Come in Peace
// Quest ID: 66244
// Start NPC: 1000168
// End NPC: 1006188

using namespace Sapphire;

class GaiUsa002 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000168;
//    static constexpr auto Actor1 = 1000257;
//    static constexpr auto Actor2 = 1000766;
//    static constexpr auto Actor3 = 1006188;
//    static constexpr auto Enemy0 = 4269923;
//    static constexpr auto Enemy1 = 4269925;
//    static constexpr auto Enemy2 = 4269926;
//    static constexpr auto Eobject0 = 2002610;
//    static constexpr auto Eobject1 = 2002611;
//    static constexpr auto Eobject2 = 2002612;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionWaitingShor = 11;
//    static constexpr auto Item0 = 2000826;
//    static constexpr auto LocActor0 = 1002275;
//    static constexpr auto LocActor1 = 1002276;
//    static constexpr auto Seq0Actor0Lq = 90;

  public:
    GaiUsa002() : Sapphire::ScriptAPI::EventScript( 66244 ){}; 
    ~GaiUsa002() = default; 

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
//EOBJECT0, null, 0, -2, False
if( actor == 2002610 ) { Scene00004( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4269923 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002611 ) { Scene00006( player ); }
//ENEMY1, UI8BH, 1, -2, False
if( actorId == 4269925 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00007( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002612 ) { Scene00008( player ); }
//ENEMY2, UI8BL, 1, -2, False
if( actorId == 4269926 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00009( player ); }
break;
}
case 4:{
Scene00010( player );
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
Scene00090( player );
    };
player.sendDebug( "questId: {}, calling QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT0", getId() );


  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Message:Scene00005 ENEMY0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY1
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Message:Scene00007 ENEMY1:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT2", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY2
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Message:Scene00009 ENEMY2:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00011 +1 ", getId() );

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

  void Scene00090( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00090 ", getId() );

    player.playScene( getId(), 90, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( GaiUsa002 );
