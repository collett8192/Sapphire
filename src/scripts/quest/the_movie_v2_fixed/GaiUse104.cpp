// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse104_01178
// Quest Name: All Things in Time
// Quest ID: 66714
// Start NPC: 1007739
// End NPC: 1006693

using namespace Sapphire;

class GaiUse104 : public Sapphire::ScriptAPI::EventScript
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
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1007739;
//    static constexpr auto Actor1 = 1007752;
//    static constexpr auto Actor2 = 1007764;
//    static constexpr auto Actor3 = 1006693;
//    static constexpr auto Bnpcname0 = 688;
//    static constexpr auto CutSceneN01 = 435;
//    static constexpr auto Enemy0 = 383;
//    static constexpr auto Enemy1 = 4504670;
//    static constexpr auto Eobject0 = 2002842;
//    static constexpr auto Eobject1 = 2002843;
//    static constexpr auto EventActionProcessLong = 17;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionWaiting3Long = 13;
//    static constexpr auto Item0 = 2001072;
//    static constexpr auto Item1 = 2001073;

  public:
    GaiUse104() : Sapphire::ScriptAPI::EventScript( 66714 ){}; 
    ~GaiUse104() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1007739 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007752 ) { Scene00002( player ); }
break;
}
case 1:{
if( actorId == 642 && player.getQuestUI8BH( getId() ) != 3 )
{
  auto c = player.getQuestUI8BH( getId() ) + 1;
  player.setQuestUI8BH( getId(), c );
  if( c == 3 )
    player.updateQuest( getId(), 2 );
}
//ACTOR1, null, 0, -2, False
if( actor == 1007752 ) { Scene00003( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1007739 ) { Scene00004( player ); }
break;
}
case 2:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002842 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007752 ) { Scene00007( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1007739 ) { Scene00008( player ); }
break;
}
case 3:{
//EOBJECT1, null, 0, -2, False
if( actor == 2002843 ) { Scene00009( player ); }
//ENEMY1, UI8AL, 1, -2, False
if( actorId == 4504670 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00010( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1007764 ) { Scene00012( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007752 ) { Scene00013( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1007739 ) { Scene00014( player ); }
break;
}
case 4:{
//ACTOR0, UI8AL, 1, -1, False
if( actor == 1007739 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00015( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1007752 ) { Scene00017( player ); }
break;
}
case 255:{
//ACTOR3, null, 0, -2, False
if( actor == 1006693 ) { Scene00019( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007752 ) { Scene00020( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1007739 ) { Scene00021( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR0", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](5)Empty:Scene00006 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR1", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR0", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00010 +1 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](10)Empty:Scene00011 ENEMY1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR2", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR0", getId() );

    player.playScene( getId(), 14, NONE, callback );
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
{ Scene00018( player ); }
    };
player.sendDebug( "questId: {}, calling [sub:Execute](15)Talk:Scene00016 +1 ACTOR0:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling [sub:Cancel](15)Talk:Scene00017 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.eventFinish( getId(), 1 );
player.enterPredefinedPrivateInstance( 212 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](16)CutScene:Scene00018 ", getId() );

    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling QuestReward, QuestComplete, FadeOut:Scene00019 ACTOR3", getId() );

    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR1", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00021 ACTOR0", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse104 );
