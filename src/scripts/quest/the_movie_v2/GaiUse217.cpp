// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse217_01361
// Quest Name: Lord of the Whorl
// Quest ID: 66897
// Start NPC: 1008693
// End NPC: 1002694

using namespace Sapphire;

class GaiUse217 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008693;
//    static constexpr auto Actor1 = 1008891;
//    static constexpr auto Actor10 = 1001029;
//    static constexpr auto Actor11 = 1008676;
//    static constexpr auto Actor12 = 1008677;
//    static constexpr auto Actor13 = 1008678;
//    static constexpr auto Actor14 = 1008679;
//    static constexpr auto Actor2 = 1008892;
//    static constexpr auto Actor3 = 1008893;
//    static constexpr auto Actor4 = 1008894;
//    static constexpr auto Actor5 = 1008895;
//    static constexpr auto Actor6 = 5010000;
//    static constexpr auto Actor7 = 1005409;
//    static constexpr auto Actor8 = 1002694;
//    static constexpr auto Actor9 = 1008691;
//    static constexpr auto BgmNothing = 1;
//    static constexpr auto CutSceneN01 = 471;
//    static constexpr auto CutSceneN02 = 472;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Instancedungeon0 = 20017;
//    static constexpr auto LocActor0 = 4635444;
//    static constexpr auto LocActor1 = 4635445;
//    static constexpr auto LocActor2 = 4635446;
//    static constexpr auto LocActor3 = 4635447;
//    static constexpr auto LocActor4 = 4635448;
//    static constexpr auto LocActor5 = 4629182;
//    static constexpr auto Poprange0 = 4633262;
//    static constexpr auto Poprange1 = 4628787;
//    static constexpr auto Poprange2 = 4635171;
//    static constexpr auto Territorytype0 = 198;
//    static constexpr auto UnlockAddNewContentToCf = 3702;
//    static constexpr auto UnlockDungeonLeviathanHard = 182;

  public:
    GaiUse217() : Sapphire::ScriptAPI::EventScript( 66897 ){}; 
    ~GaiUse217() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1008693 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008891 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008892 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008893 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008894 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008895 ) { Scene00006( player ); }
break;
}
case 1:{
//ACTOR0, null, 0, -2, False
if( actor == 1008693 ) { Scene00007( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008891 ) { Scene00008( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008892 ) { Scene00009( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008893 ) { Scene00010( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008894 ) { Scene00011( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008895 ) { Scene00012( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1005409 ) { Scene00013( player ); }
break;
}
case 255:{
//ACTOR8, null, 0, -2, False
if( actor == 1002694 ) { Scene00015( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1008691 ) { Scene00016( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1001029 ) { Scene00017( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008676 ) { Scene00018( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008677 ) { Scene00019( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1008678 ) { Scene00020( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1008679 ) { Scene00021( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1005409 ) { Scene00022( player ); }
break;
}
default: { player.sendUrgent( "seq {} not defined.", player.getQuestSeq( getId() ) ); break; }
}
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, Message, FadeOut:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR4", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR5", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR0", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR2", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR3", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR4", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR5", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00014( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 +1 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](13)CutScene:Scene00014 ACTOR7", getId() );

    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling QuestReward, QuestComplete, FadeOut:Scene00015 ACTOR8", getId() );

    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR9", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//no valid quest var detected
if( result.param2 == 1 ){
//next scene not found
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00017 ACTOR10", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR11", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR12", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR13", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR14
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00021 ACTOR14", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR7", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse217 );
