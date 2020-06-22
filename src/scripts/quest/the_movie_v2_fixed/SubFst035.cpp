// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst035_00129
// Quest Name: Spirithold Broken
// Quest ID: 65665
// Start NPC: 1000421
// End NPC: 1000100

using namespace Sapphire;

class SubFst035 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      Seq5 = 5,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000421;
//    static constexpr auto Actor1 = 1000465;
//    static constexpr auto Actor10 = 1000101;
//    static constexpr auto Actor2 = 1000512;
//    static constexpr auto Actor3 = 1000513;
//    static constexpr auto Actor4 = 1000514;
//    static constexpr auto Actor5 = 1000515;
//    static constexpr auto Actor6 = 1000516;
//    static constexpr auto Actor7 = 1000740;
//    static constexpr auto Actor8 = 1000100;
//    static constexpr auto Actor9 = 1000102;
//    static constexpr auto CutScene02 = 70;
//    static constexpr auto CutScene03 = 71;
//    static constexpr auto CutScene04 = 72;
//    static constexpr auto Eobject0 = 2001232;
//    static constexpr auto Eobject10 = 1140471;
//    static constexpr auto Eobject6 = 2654267;
//    static constexpr auto Eobject7 = 2654268;
//    static constexpr auto Eobject8 = 2654272;
//    static constexpr auto Eobject9 = 1140501;
//    static constexpr auto EventAction = 26;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocActor0 = 1003064;
//    static constexpr auto LogmessageRecommendListUnlock = 3701;
//    static constexpr auto Motion3 = 708;
//    static constexpr auto Questbattle0 = 15;
//    static constexpr auto Reward0 = 9;
//    static constexpr auto RewardLeve = 5;
//    static constexpr auto Seq0Actor0Lq = 50;
//    static constexpr auto Territorytype0 = 225;
//    static constexpr auto Territorytype1 = 148;
//    static constexpr auto UnlockCheckInnReward = 2;
//    static constexpr auto UnlockImageGearSet = 29;
//    static constexpr auto UnlockImageInn = 18;
//    static constexpr auto UnlockImageLeve = 20;

  public:
    SubFst035() : Sapphire::ScriptAPI::EventScript( 65665 ){}; 
    ~SubFst035() = default; 

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
//ACTOR2, UI8AL, 5, -2, False
if( actor == 1000512 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00004( player ); }
//ACTOR3, UI8AL, 5, -2, False
if( actor == 1000513 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00007( player ); }
//ACTOR4, UI8AL, 5, -2, False
if( actor == 1000514 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00010( player ); }
//ACTOR5, UI8AL, 5, -2, False
if( actor == 1000515 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00013( player ); }
//ACTOR6, UI8AL, 5, -2, False
if( actor == 1000516 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00016( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1000740 ) { Scene00018( player ); }
break;
}
case 3:{
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR7, UI8AL, 1, -2, False
if( actor == 1000740 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00019( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001232 ) { Scene00020( player ); }
break;
}
case 4:{
Scene00021( player );
break;
}
case 5:{
Scene00024( player );
break;
}
case 255:{
Scene00025( player );
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
player.sendDebug( "questId: {}, calling Talk, QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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


//Target: ACTOR2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00003 ACTOR2:UI8AL=-2, 5", getId() );


  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 +2 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](4)Empty:Scene00005 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Empty:Scene00006 ACTOR3:UI8AL=-2, 5", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 +2 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](7)Empty:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](10)Empty:Scene00009 ACTOR4:UI8AL=-2, 5", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 +2 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](10)Empty:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR5
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Empty:Scene00012 ACTOR5:UI8AL=-2, 5", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 +2 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](13)Empty:Scene00014 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR6
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](16)Empty:Scene00015 ACTOR6:UI8AL=-2, 5", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00015( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 +2 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](16)Empty:Scene00017 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR7", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
Scene00023( player );
}
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00019 ACTOR7:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00020 EOBJECT0", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {


player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00021 ", getId() );


  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00023( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00022 +1 ", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](22)CutScene:Scene00023 ", getId() );

    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00025 ", getId() );

    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( SubFst035 );
