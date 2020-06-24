// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: True, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubWil038_00230
// Quest Name: Search and Seizure
// Quest ID: 65766
// Start NPC: 1002014
// End NPC: 1001353

using namespace Sapphire;

class SubWil038 : public Sapphire::ScriptAPI::EventScript
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
    // GetQuestUI8CL

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
//    static constexpr auto Actor0 = 1002014;
//    static constexpr auto Actor1 = 1003685;
//    static constexpr auto Actor2 = 1001353;
//    static constexpr auto Enemy0 = 4086831;
//    static constexpr auto Enemy1 = 4086832;
//    static constexpr auto Enemy2 = 4086833;
//    static constexpr auto Enemy3 = 4086834;
//    static constexpr auto Eobject0 = 2001456;
//    static constexpr auto Eobject1 = 2001457;
//    static constexpr auto Eobject2 = 2001458;
//    static constexpr auto Eobject3 = 2001459;
//    static constexpr auto Eventrange0 = 4187339;
//    static constexpr auto Eventrange1 = 4187340;
//    static constexpr auto Eventrange2 = 4187344;
//    static constexpr auto Eventrange3 = 4187347;
//    static constexpr auto EventActionProcessUpperShort = 31;
//    static constexpr auto Item0 = 2000413;
//    static constexpr auto Item1 = 2000165;
//    static constexpr auto LocActor0 = 1002033;
//    static constexpr auto LocActor1 = 1002027;
//    static constexpr auto LocActor2 = 1002044;
//    static constexpr auto LocFace0 = 604;
//    static constexpr auto LocFace1 = 605;
//    static constexpr auto LocFace2 = 617;
//    static constexpr auto LocPosCam1 = 4072493;
//    static constexpr auto Seq0Actor0Lq = 90;

  public:
    SubWil038() : Sapphire::ScriptAPI::EventScript( 65766 ){}; 
    ~SubWil038() = default; 

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
if( actor == 1003685 ) { Scene00002( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001456 ) { Scene00003( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4086831 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001457 ) { Scene00006( player ); }
//ENEMY1, UI8BH, 1, -2, False
if( actorId == 4086832 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00008( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001458 ) { Scene00009( player ); }
//ENEMY2, UI8BL, 1, -2, False
if( actorId == 4086833 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00011( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001459 ) { Scene00012( player ); }
//ENEMY3, UI8CH, 1, -2, False
if( actorId == 4086834 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00014( player ); }
break;
}
case 2:{
Scene00015( player );
break;
}
case 3:{
Scene00017( player );
break;
}
case 255:{
Scene00018( player );
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
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
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
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](3)Message:Scene00004 EOBJECT0", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: ENEMY0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 ENEMY0:UI8AL=-2, 1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](6)Message:Scene00007 EOBJECT1", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: ENEMY1
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00008 ENEMY1:UI8BH=-2, 1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](9)Message:Scene00010 EOBJECT2", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: ENEMY2
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00011 ENEMY2:UI8BL=-2, 1", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00012 +1 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](12)Message:Scene00013 EOBJECT3", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: ENEMY3
player.setQuestUI8CH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00014 ENEMY3:UI8CH=-2, 1", getId() );


  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00016( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00015 +1 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](15)Talk:Scene00016 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00017 ", getId() );

    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00019( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00018 +1 ", getId() );

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
player.sendDebug( "questId: {}, calling [sub:Execute](18)Talk, QuestReward, QuestComplete:Scene00019 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00090( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
player.setQuestUI8CL( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00090 ", getId() );

    player.playScene( getId(), 90, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( SubWil038 );
