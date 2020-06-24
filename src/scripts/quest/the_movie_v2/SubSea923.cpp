// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea923_00246
// Quest Name: Feast of Famine
// Quest ID: 65782
// Start NPC: 1000856
// End NPC: 1000856

using namespace Sapphire;

class SubSea923 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1000856;
//    static constexpr auto Actor1 = 1003585;
//    static constexpr auto Actor2 = 1000857;
//    static constexpr auto Actor3 = 1008882;
//    static constexpr auto Actor4 = 1005414;
//    static constexpr auto LcutActorAscelyn01 = 1008946;
//    static constexpr auto LcutActorCheer01 = 4165351;
//    static constexpr auto LcutActorFisherman01 = 1010698;
//    static constexpr auto LcutActorFisher01 = 5049369;
//    static constexpr auto LcutActorNeptdragon01 = 1010699;
//    static constexpr auto LcutActorSisipu = 1673578;
//    static constexpr auto LcutActorWawarago = 1673577;
//    static constexpr auto LcutBgmDisquiet01 = 78;
//    static constexpr auto LcutBgmJoy01 = 87;
//    static constexpr auto LcutBgmRiseInArms01 = 86;
//    static constexpr auto LcutBgmThemeFaceWar01 = 83;
//    static constexpr auto LcutBgmThemeRest0201 = 98;
//    static constexpr auto LcutMotionBaseLie01 = 981;
//    static constexpr auto LcutMotionEventArms = 1041;
//    static constexpr auto LcutPosAscelyn01 = 4632830;
//    static constexpr auto LcutPosPc01 = 4653199;
//    static constexpr auto Poprange0 = 4165755;
//    static constexpr auto Ritem0 = 8756;
//    static constexpr auto Ritem1 = 8775;
//    static constexpr auto Ritem2 = 8768;
//    static constexpr auto Ritem3 = 8772;
//    static constexpr auto Ritem4 = 8763;
//    static constexpr auto Ritem5 = 8754;

  public:
    SubSea923() : Sapphire::ScriptAPI::EventScript( 65782 ){}; 
    ~SubSea923() = default; 

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
Scene00004( player );
break;
}
case 3:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1003585 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00007( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1000857 ) { Scene00008( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1000856 ) { Scene00009( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008882 ) { Scene00010( player ); }
break;
}
case 4:{
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1005414 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00013( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1003585 ) { Scene00014( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1000857 ) { Scene00015( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1000856 ) { Scene00016( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008882 ) { Scene00017( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1000856 ) { Scene00016( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1000857 ) { Scene00017( player ); }
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
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](2)Talk, FadeOut:Scene00003 ", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](4)Talk, FadeOut:Scene00005 ", getId() );

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR1:UI8AL=-2, 1", getId() );

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
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR0", getId() );

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
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:Execute](10)Talk, FadeOut:Scene00011 ACTOR3", getId() );

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
//Target: ACTOR4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR1", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR2", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00016 ACTOR0", getId() );

    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR2", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubSea923 );
