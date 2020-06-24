// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse310_01451
// Quest Name: True to Form
// Quest ID: 66987
// Start NPC: 1009414
// End NPC: 1009119

using namespace Sapphire;

class GaiUse310 : public Sapphire::ScriptAPI::EventScript
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
//      Seq5 = 5,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventBaseKneeSuffering = 936;
//    static constexpr auto ActionTimelineEventJoy = 953;
//    static constexpr auto ActionTimelineEventSad = 954;
//    static constexpr auto ActionTimelineFacialSpewing = 617;
//    static constexpr auto Actor0 = 1009414;
//    static constexpr auto Actor1 = 1009106;
//    static constexpr auto Actor2 = 1009118;
//    static constexpr auto Actor3 = 1009121;
//    static constexpr auto Actor4 = 1009122;
//    static constexpr auto Actor5 = 1009116;
//    static constexpr auto Actor6 = 1009117;
//    static constexpr auto Actor7 = 1009123;
//    static constexpr auto Actor8 = 1009119;
//    static constexpr auto Actor9 = 1009120;
//    static constexpr auto Bnpcname0 = 2878;
//    static constexpr auto Enemy0 = 4868024;
//    static constexpr auto Eobject0 = 2004143;
//    static constexpr auto Eventrange0 = 4868023;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001313;
//    static constexpr auto LevelIdNpc01 = 4868019;
//    static constexpr auto LevelIdNpc02 = 4868020;
//    static constexpr auto LevelIdNpc03 = 4868008;
//    static constexpr auto LocActor0 = 1009668;
//    static constexpr auto LocActor1 = 1008176;
//    static constexpr auto LocActor2 = 4868019;
//    static constexpr auto LocActor3 = 4868015;
//    static constexpr auto LocActor4 = 4868016;
//    static constexpr auto LocActor5 = 4868020;
//    static constexpr auto LocPosActor0 = 4892562;
//    static constexpr auto LocVfx01 = 300;

  public:
    GaiUse310() : Sapphire::ScriptAPI::EventScript( 66987 ){}; 
    ~GaiUse310() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1009414 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009106 ) { Scene00002( player ); }
break;
}
case 1:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1009118 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009121 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009122 ) { Scene00006( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009116 ) { Scene00007( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009117 ) { Scene00008( player ); }
break;
}
case 2:{
//ACTOR6, UI8AL, 1, -2, False
if( actor == 1009117 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00009( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009118 ) { Scene00011( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009121 ) { Scene00012( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009122 ) { Scene00013( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009116 ) { Scene00014( player ); }
break;
}
case 3:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1009118 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00015( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009116 ) { Scene00016( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009117 ) { Scene00017( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009121 ) { Scene00018( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009122 ) { Scene00019( player ); }
break;
}
case 4:{
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4868024 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00020( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009123 ) { Scene00022( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009116 ) { Scene00023( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009117 ) { Scene00024( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1009119 ) { Scene00025( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1009120 ) { Scene00026( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009121 ) { Scene00027( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004143 ) { Scene00028( player ); }
break;
}
case 5:{
//ACTOR7, UI8AL, 1, -2, False
if( actor == 1009123 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00029( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009116 ) { Scene00031( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009117 ) { Scene00032( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1009119 ) { Scene00033( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1009120 ) { Scene00034( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009121 ) { Scene00035( player ); }
break;
}
case 255:{
//ACTOR8, null, 0, -2, False
if( actor == 1009119 ) { Scene00035( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009116 ) { Scene00036( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009117 ) { Scene00037( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1009120 ) { Scene00038( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009121 ) { Scene00039( player ); }
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
{ Scene00004( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 +1 ", getId() );

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
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](3)Talk:Scene00004 ACTOR2:UI8AL=-2, 1", getId() );

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
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR4", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR5", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR6", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](9)Talk:Scene00010 ACTOR6:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR2", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR3", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, Inventory:Scene00013 ACTOR4", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR5", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00015 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR5", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR6", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR3", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR4", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00020 +1 ", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](20)Empty:Scene00021 ENEMY0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR7", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR5", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR6", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR8", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR9", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR3", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00028 EOBJECT0", getId() );


  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00030( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 +1 ", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](29)Talk:Scene00030 ACTOR7:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 ACTOR5", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ACTOR6", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ACTOR8", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 ACTOR9", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00035 ACTOR8", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00036 ACTOR5", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00037 ACTOR6", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00038 ACTOR9", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00039 ACTOR3", getId() );

    player.playScene( getId(), 39, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse310 );
