// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse410_00078
// Quest Name: Tendrils of Intrigue
// Quest ID: 65614
// Start NPC: 1010191
// End NPC: 1010010

using namespace Sapphire;

class GaiUse410 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventSaluteCry = 1045;
//    static constexpr auto Actor0 = 1010191;
//    static constexpr auto Actor1 = 1010369;
//    static constexpr auto Actor2 = 1009130;
//    static constexpr auto Actor3 = 1010009;
//    static constexpr auto Actor4 = 1000460;
//    static constexpr auto Actor5 = 1010010;
//    static constexpr auto Actor6 = 1010011;
//    static constexpr auto BgmNothing = 1;
//    static constexpr auto BgmNothing = 1;
//    static constexpr auto CutSceneN01 = 615;
//    static constexpr auto CutSceneN02 = 616;
//    static constexpr auto CutSceneN03 = 617;
//    static constexpr auto LevelIdNpc01 = 5110399;
//    static constexpr auto LocActor0 = 1008192;
//    static constexpr auto LocActor1 = 3643001;
//    static constexpr auto LocBgm01 = 130;
//    static constexpr auto LocBgm02 = 76;
//    static constexpr auto LocBgm03 = 78;
//    static constexpr auto Poprange0 = 3878860;

  public:
    GaiUse410() : Sapphire::ScriptAPI::EventScript( 65614 ){}; 
    ~GaiUse410() = default; 

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
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1010191 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010369 ) { Scene00003( player ); }
break;
}
case 2:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1009130 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1010009 ) { Scene00005( player ); }
break;
}
case 3:{
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1000460 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00006( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009130 ) { Scene00008( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1010009 ) { Scene00009( player ); }
break;
}
case 4:{
Scene00010( player );
break;
}
case 255:{
//ACTOR5, null, 0, -2, False
if( actor == 1010010 ) { Scene00011( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010011 ) { Scene00012( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR3", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](6)CutScene:Scene00007 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR2", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR3", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00011 ACTOR5", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR6", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse410 );
