// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse216_01360
// Quest Name: Into the Heart of the Whorl
// Quest ID: 66896
// Start NPC: 1008803
// End NPC: 1008693

using namespace Sapphire;

class GaiUse216 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventBaseAttentionStand = 1013;
//    static constexpr auto ActionTimelineEventBaseSorry = 819;
//    static constexpr auto Actor0 = 1008803;
//    static constexpr auto Actor1 = 1002694;
//    static constexpr auto Actor10 = 1008891;
//    static constexpr auto Actor11 = 1008892;
//    static constexpr auto Actor12 = 1008893;
//    static constexpr auto Actor13 = 1008894;
//    static constexpr auto Actor14 = 1008895;
//    static constexpr auto Actor2 = 1001029;
//    static constexpr auto Actor3 = 1008676;
//    static constexpr auto Actor4 = 1008677;
//    static constexpr auto Actor5 = 1008678;
//    static constexpr auto Actor6 = 1008679;
//    static constexpr auto Actor7 = 1008691;
//    static constexpr auto Actor8 = 1008692;
//    static constexpr auto Actor9 = 1008693;
//    static constexpr auto CutSceneN01 = 469;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LevelIdNpc01 = 4629168;
//    static constexpr auto LevelIdNpc02 = 4629169;
//    static constexpr auto LevelIdNpc03 = 4629170;
//    static constexpr auto LevelIdNpc04 = 4629171;
//    static constexpr auto LocAction10 = 1002;
//    static constexpr auto LocActor0 = 4087076;
//    static constexpr auto LocActor1 = 4628783;
//    static constexpr auto LocActor10 = 4259850;
//    static constexpr auto LocActor11 = 1008175;
//    static constexpr auto LocActor2 = 4628784;
//    static constexpr auto LocActor3 = 4628785;
//    static constexpr auto LocActor4 = 1008797;
//    static constexpr auto LocBgm0 = 88;
//    static constexpr auto LocFace10 = 614;
//    static constexpr auto LocFace11 = 606;
//    static constexpr auto LocFace12 = 617;
//    static constexpr auto LocSe1 = 70;
//    static constexpr auto LocSe10 = 42;
//    static constexpr auto Poprange0 = 4628787;
//    static constexpr auto Territorytype0 = 198;

  public:
    GaiUse216() : Sapphire::ScriptAPI::EventScript( 66896 ){}; 
    ~GaiUse216() = default; 

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
if( actor == 1002694 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1001029 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008676 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008677 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008678 ) { Scene00006( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1008679 ) { Scene00007( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1008691 ) { Scene00008( player ); }
break;
}
case 2:{
//ACTOR6, UI8AL, 1, -2, False
if( actor == 1008679 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00009( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008676 ) { Scene00010( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008677 ) { Scene00011( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008678 ) { Scene00012( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1002694 ) { Scene00013( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1001029 ) { Scene00014( player ); }
break;
}
case 3:{
//ACTOR8, UI8AL, 1, -2, False
if( actor == 1008692 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00015( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1002694 ) { Scene00016( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008676 ) { Scene00017( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008677 ) { Scene00018( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008678 ) { Scene00019( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1008679 ) { Scene00020( player ); }
break;
}
case 255:{
//ACTOR9, null, 0, -2, False
if( actor == 1008693 ) { Scene00021( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1008891 ) { Scene00022( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008892 ) { Scene00023( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008893 ) { Scene00024( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1008894 ) { Scene00025( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1008895 ) { Scene00026( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling CutScene:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00003 ACTOR2", getId() );

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
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR6", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR7", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00009 ACTOR6:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR3", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR4", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR5", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00014 ACTOR2", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00015 ACTOR8:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR1", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR3", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR4", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR5", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR6", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00021 ACTOR9", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR10", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR11", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR12", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR13", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR14
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR14", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse216 );
