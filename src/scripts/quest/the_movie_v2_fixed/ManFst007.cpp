// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManFst007_00447
// Quest Name: To Guard a Guardian
// Quest ID: 65983
// Start NPC: 1000100
// End NPC: 1003061

using namespace Sapphire;

class ManFst007 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
    // GetQuestBitFlag8
    // GetQuestUI8AH
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000100;
//    static constexpr auto Actor1 = 1003061;
//    static constexpr auto Actor10 = 1000721;
//    static constexpr auto Actor11 = 1000722;
//    static constexpr auto Actor12 = 1000723;
//    static constexpr auto Actor13 = 1000724;
//    static constexpr auto Actor2 = 1000423;
//    static constexpr auto Actor3 = 1000456;
//    static constexpr auto Actor4 = 1000457;
//    static constexpr auto Actor5 = 1000458;
//    static constexpr auto Actor6 = 1000463;
//    static constexpr auto Actor7 = 1000464;
//    static constexpr auto Actor8 = 1000719;
//    static constexpr auto Actor9 = 1000720;
//    static constexpr auto CutScene03 = 60;
//    static constexpr auto Eobject0 = 2001836;
//    static constexpr auto Eventrange0 = 3854369;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000249;
//    static constexpr auto LocAction1 = 961;
//    static constexpr auto LocActor0 = 1003071;
//    static constexpr auto LocFace1 = 617;
//    static constexpr auto LocFace2 = 604;
//    static constexpr auto LocLip1 = 632;
//    static constexpr auto Ncut01 = 30;
//    static constexpr auto Ncut02 = 61;
//    static constexpr auto Poprange0 = 3884000;
//    static constexpr auto Questbattle0 = 12;
//    static constexpr auto Seq0Actor0Lq = 90;
//    static constexpr auto Territorytype0 = 204;
//    static constexpr auto Territorytype1 = 226;
//    static constexpr auto Territorytype2 = 148;

  public:
    ManFst007() : Sapphire::ScriptAPI::EventScript( 65983 ){}; 
    ~ManFst007() = default; 

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
//ACTOR1, UI8AL, 1, -1, False
if( actor == 1003061 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -1, False
if( actor == 1000423 ) { Scene00005( player ); }
break;
}
case 2:{
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR3, UI8AL, 1, -2, False
if( actor == 1000456 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00006( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1000457 ) { Scene00007( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1000458 ) { Scene00008( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1000463 ) { Scene00009( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1000464 ) { Scene00010( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1000719 ) { Scene00011( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1000720 ) { Scene00012( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1000721 ) { Scene00013( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1000722 ) { Scene00014( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1000723 ) { Scene00015( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1000724 ) { Scene00016( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001836 ) { Scene00017( player ); }
break;
}
case 3:{
Scene00018( player );
break;
}
case 255:{
//ACTOR1, null, 0, -2, False
if( actor == 1003061 ) { Scene00021( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1000423 ) { Scene00022( player ); }
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
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept, CutScene:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00003( player ); }
 else { Scene00004( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00002 +2 ", getId() );

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
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](2)Talk, FadeOut:Scene00003 ACTOR1:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](2)Empty:Scene00004 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
      if( result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 204 );
      }
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00005 ACTOR2", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
Scene00019( player );
}
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00006 ACTOR3:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, QuestBattle, YesNo:Scene00007 ACTOR4", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR5", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR6", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR7", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR8", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR9", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR10", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR11
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR11", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR12
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR12", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: ACTOR13
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR13", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00017 EOBJECT0", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00018 ", getId() );


  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00020( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00019 +1 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](19)CutScene:Scene00020 ", getId() );

    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, CutScene, QuestReward, QuestComplete, FadeOut:Scene00021 ACTOR1", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
if( result.param2 == 1 ){
  player.eventFinish( getId(), 1 );
  player.enterPredefinedPrivateInstance( 204 );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00022 ACTOR2", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

};

EXPOSE_SCRIPT( ManFst007 );
