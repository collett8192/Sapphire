// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse504_00366
// Quest Name: The Rising Chorus
// Quest ID: 65902
// Start NPC: 1010891
// End NPC: 1010858

using namespace Sapphire;

class GaiUse504 : public Sapphire::ScriptAPI::EventScript
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
//      Seq6 = 6,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1010891;
//    static constexpr auto Actor1 = 1010855;
//    static constexpr auto Actor10 = 1010856;
//    static constexpr auto Actor11 = 1010858;
//    static constexpr auto Actor2 = 1011122;
//    static constexpr auto Actor3 = 1011123;
//    static constexpr auto Actor4 = 1008969;
//    static constexpr auto Actor5 = 1010854;
//    static constexpr auto Actor6 = 1010881;
//    static constexpr auto Actor7 = 5010000;
//    static constexpr auto Actor8 = 1010857;
//    static constexpr auto Actor9 = 1011124;
//    static constexpr auto Companion0 = 119;
//    static constexpr auto CutSceneN01 = 695;
//    static constexpr auto CutSceneN02 = 697;
//    static constexpr auto CutSceneN03 = 698;
//    static constexpr auto CutSceneN04 = 699;
//    static constexpr auto Instancedungeon0 = 32;
//    static constexpr auto LocActor0 = 4725177;
//    static constexpr auto LocActor1 = 5578843;
//    static constexpr auto LocActor2 = 5578845;
//    static constexpr auto LocActor3 = 5578846;
//    static constexpr auto LocActor4 = 5578574;
//    static constexpr auto LocEobject0 = 2005157;
//    static constexpr auto LocMotion0 = 731;
//    static constexpr auto LocMotion1 = 707;
//    static constexpr auto LocMotion2 = 719;
//    static constexpr auto Poprange0 = 5582034;
//    static constexpr auto Poprange1 = 5589530;
//    static constexpr auto Territorytype0 = 156;
//    static constexpr auto UnlockDungeonTowerOfSecret = 266;

  public:
    GaiUse504() : Sapphire::ScriptAPI::EventScript( 65902 ){}; 
    ~GaiUse504() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1010891 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010855 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1011122 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1011123 ) { Scene00004( player ); }
break;
}
case 1:{
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1008969 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00006( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010855 ) { Scene00007( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1011122 ) { Scene00008( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1011123 ) { Scene00009( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010854 ) { Scene00010( player ); }
break;
}
case 2:{
//ACTOR6, UI8AL, 1, -2, False
if( actor == 1010881 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00011( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008969 ) { Scene00012( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010855 ) { Scene00013( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1010891 ) { Scene00014( player ); }
break;
}
case 3:{
//ACTOR4, null, 0, -2, False
if( actor == 1008969 ) { Scene00015( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010855 ) { Scene00016( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1010891 ) { Scene00017( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010881 ) { Scene00018( player ); }
break;
}
case 4:{
//BASE_ID_TERRITORY_TYPE, null, 0, -2, False
//if( actor == BASE_ID_TERRITORY_TYPE ) { Scene00020( player ); }
break;
}
case 5:{
//ACTOR6, UI8AL, 1, -2, False
if( actor == 1010881 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00021( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008969 ) { Scene00022( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010855 ) { Scene00023( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1010891 ) { Scene00024( player ); }
break;
}
case 6:{
//ACTOR8, UI8AL, 1, -2, False
if( actor == 1010857 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00025( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008969 ) { Scene00027( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1010891 ) { Scene00028( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1011124 ) { Scene00029( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1010856 ) { Scene00030( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010881 ) { Scene00031( player ); }
break;
}
case 255:{
//ACTOR11, null, 0, -2, False
if( actor == 1010858 ) { Scene00032( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008969 ) { Scene00033( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1010891 ) { Scene00034( player ); }
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
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 +1 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](4)CutScene:Scene00005 ACTOR3", getId() );

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00006 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR5", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
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
player.sendDebug( "questId: {}, calling Talk, Message, FadeOut:Scene00011 ACTOR6:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR4", getId() );

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
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR0", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR4", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR1", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR0", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00019( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 +1 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](18)CutScene:Scene00019 ACTOR6", getId() );

    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: BASE_ID_TERRITORY_TYPE
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling FadeOut:Scene00020 BASE_ID_TERRITORY_TYPE", getId() );

    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00021 ACTOR6:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR4", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR1", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR0", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00026( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 +1 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
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
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](25)CutScene:Scene00026 ACTOR8:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR4", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00028 ACTOR0", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ACTOR9", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 ACTOR10", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 ACTOR6", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00032 ACTOR11", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ACTOR4", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 ACTOR0", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse504 );
