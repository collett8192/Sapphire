// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse213_01357
// Quest Name: Fireworks and Fish Don't Mix
// Quest ID: 66893
// Start NPC: 1006614
// End NPC: 1006614

using namespace Sapphire;

class GaiUse213 : public Sapphire::ScriptAPI::EventScript
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
    // GetQuestUI8DH

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
//    static constexpr auto Actor0 = 1006614;
//    static constexpr auto Actor1 = 1006616;
//    static constexpr auto Enemy0 = 4628559;
//    static constexpr auto Enemy1 = 4628560;
//    static constexpr auto Enemy2 = 4628566;
//    static constexpr auto Enemy3 = 4628567;
//    static constexpr auto Enemy4 = 4628568;
//    static constexpr auto Eobject0 = 2003588;
//    static constexpr auto Eobject1 = 2003589;
//    static constexpr auto Eobject2 = 2003585;
//    static constexpr auto Eobject3 = 2003586;
//    static constexpr auto Eobject4 = 2003587;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001213;

  public:
    GaiUse213() : Sapphire::ScriptAPI::EventScript( 66893 ){}; 
    ~GaiUse213() = default; 

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
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1006616 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006614 ) { Scene00004( player ); }
break;
}
case 2:{
//EOBJECT0, UI8BH, 1, -2, False
if( actor == 2003588 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00005( player ); }
//EOBJECT1, UI8AL, 1, -2, False
if( actor == 2003589 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00007( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2003585 ) { Scene00009( player ); }
//ENEMY0, UI8CH, 2, -2, False
if( actorId == 4628559 && player.getQuestUI8CH( getId() ) != 2 ) { Scene00011( player ); }
//ENEMY1, UI8CH, 2, -2, False
if( actorId == 4628560 && player.getQuestUI8CH( getId() ) != 2 ) { Scene00013( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2003586 ) { Scene00015( player ); }
//ENEMY2, UI8BL, 1, -2, False
if( actorId == 4628566 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00017( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2003587 ) { Scene00019( player ); }
//ENEMY3, UI8CL, 2, -2, False
if( actorId == 4628567 && player.getQuestUI8CL( getId() ) != 2 ) { Scene00021( player ); }
//ENEMY4, UI8CL, 2, -2, False
if( actorId == 4628568 && player.getQuestUI8CL( getId() ) != 2 ) { Scene00023( player ); }
break;
}
case 255:{
Scene00024( player );
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
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8DH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Talk:Scene00003 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00004 ACTOR0", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](5)Inventory:Scene00006 EOBJECT0:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Inventory:Scene00008 EOBJECT1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
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
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](9)Empty:Scene00010 EOBJECT2", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00011 +1 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](11)Empty:Scene00012 ENEMY0:UI8CH=-2, 2", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00013 +1 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](13)Inventory:Scene00014 ENEMY1:UI8CH=-2, 2", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00015 +1 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](15)Empty:Scene00016 EOBJECT3", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00017 +1 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](17)Inventory:Scene00018 ENEMY2:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00019 +1 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](19)Empty:Scene00020 EOBJECT4", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00021 +1 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](21)Empty:Scene00022 ENEMY3:UI8CL=-2, 2", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY4
player.setQuestUI8CL( getId(), player.getQuestUI8CL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Message:Scene00023 ENEMY4:UI8CL=-2, 2", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00024 ", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse213 );
