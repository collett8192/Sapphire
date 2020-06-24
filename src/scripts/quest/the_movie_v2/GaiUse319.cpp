// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse319_01460
// Quest Name: Brave New Companions
// Quest ID: 66996
// Start NPC: 1006530
// End NPC: 1008969

using namespace Sapphire;

class GaiUse319 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006530;
//    static constexpr auto Actor1 = 1008997;
//    static constexpr auto Actor10 = 1009021;
//    static constexpr auto Actor11 = 1008969;
//    static constexpr auto Actor2 = 1009141;
//    static constexpr auto Actor3 = 1009142;
//    static constexpr auto Actor4 = 1009143;
//    static constexpr auto Actor5 = 1009144;
//    static constexpr auto Actor6 = 1009145;
//    static constexpr auto Actor7 = 1009146;
//    static constexpr auto Actor8 = 1009147;
//    static constexpr auto Actor9 = 1009148;
//    static constexpr auto BgmNothing = 1;
//    static constexpr auto CutSceneN01 = 539;
//    static constexpr auto CutSceneN02 = 540;
//    static constexpr auto CutSceneN03 = 543;
//    static constexpr auto CutSceneN04 = 544;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001315;

  public:
    GaiUse319() : Sapphire::ScriptAPI::EventScript( 66996 ){}; 
    ~GaiUse319() = default; 

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
if( actor == 1008997 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006530 ) { Scene00003( player ); }
break;
}
case 2:{
//ACTOR2, UI8AL, 8, -1, False
if( actor == 1009141 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00004( player ); }
//ACTOR3, UI8AL, 8, -1, False
if( actor == 1009142 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00007( player ); }
//ACTOR4, UI8AL, 8, -1, False
if( actor == 1009143 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00010( player ); }
//ACTOR5, UI8AL, 8, -1, False
if( actor == 1009144 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00013( player ); }
//ACTOR6, UI8AL, 8, -1, False
if( actor == 1009145 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00016( player ); }
//ACTOR7, UI8AL, 8, -1, False
if( actor == 1009146 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00019( player ); }
//ACTOR8, UI8AL, 8, -1, False
if( actor == 1009147 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00022( player ); }
//ACTOR9, UI8AL, 8, -1, False
if( actor == 1009148 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00025( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1008997 ) { Scene00028( player ); }
break;
}
case 3:{
//ACTOR10, UI8AL, 1, -2, False
if( actor == 1009021 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00029( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009141 ) { Scene00031( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009142 ) { Scene00032( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009143 ) { Scene00033( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009144 ) { Scene00034( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009145 ) { Scene00035( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009146 ) { Scene00036( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1009147 ) { Scene00037( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1009148 ) { Scene00038( player ); }
break;
}
case 255:{
Scene00040( player );
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
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR0", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00005( player ); }
 else { Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00004 +2 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 8 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](4)Talk:Scene00005 ACTOR2:UI8AL=-1, 8", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](4)Talk:Scene00006 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00008( player ); }
 else { Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00007 +2 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8AL( getId(), 8 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](7)Talk:Scene00008 ACTOR3:UI8AL=-1, 8", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](7)Talk:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00011( player ); }
 else { Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00010 +2 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), 8 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](10)Talk:Scene00011 ACTOR4:UI8AL=-1, 8", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](10)Talk:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00014( player ); }
 else { Scene00015( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00013 +2 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8AL( getId(), 8 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](13)Talk:Scene00014 ACTOR5:UI8AL=-1, 8", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](13)Talk:Scene00015 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00017( player ); }
 else { Scene00018( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00016 +2 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
player.setQuestUI8AL( getId(), 8 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](16)Talk:Scene00017 ACTOR6:UI8AL=-1, 8", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](16)Talk:Scene00018 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00020( player ); }
 else { Scene00021( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00019 +2 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
player.setQuestUI8AL( getId(), 8 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](19)Talk:Scene00020 ACTOR7:UI8AL=-1, 8", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](19)Talk:Scene00021 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00023( player ); }
 else { Scene00024( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00022 +2 ", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
player.setQuestUI8AL( getId(), 8 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](22)Talk:Scene00023 ACTOR8:UI8AL=-1, 8", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](22)Talk:Scene00024 ", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00026( player ); }
 else { Scene00027( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00025 +2 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
player.setQuestUI8AL( getId(), 8 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](25)Talk:Scene00026 ACTOR9:UI8AL=-1, 8", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](25)Talk:Scene00027 ", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00028 ACTOR1", getId() );

    player.playScene( getId(), 28, NONE, callback );
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
//Target: ACTOR10
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](29)CutScene:Scene00030 ACTOR10:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 ACTOR2", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ACTOR3", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ACTOR4", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 ACTOR5", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00035 ACTOR6", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00036 ACTOR7", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00037 ACTOR8", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00039( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00038 +1 ", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](38)CutScene:Scene00039 ACTOR9", getId() );

    player.playScene( getId(), 39, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
Scene00041( player );
    };
player.sendDebug( "questId: {}, calling QuestReward, QuestComplete, FadeOut:Scene00040 +1 ", getId() );

    player.playScene( getId(), 40, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](40)CutScene:Scene00041 ", getId() );

    player.playScene( getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( GaiUse319 );
