// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse612_00424
// Quest Name: The Least among Us
// Quest ID: 65960
// Start NPC: 1010984
// End NPC: 1010897

using namespace Sapphire;

class GaiUse612 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineBattleCorpse = 73;
//    static constexpr auto ActionTimelineEventActionEnd = 82;
//    static constexpr auto ActionTimelineEventActionLoop = 81;
//    static constexpr auto ActionTimelineEventActionStart = 80;
//    static constexpr auto ActionTimelineEventBaseFrightened = 983;
//    static constexpr auto ActionTimelineEventBaseFrightened2 = 985;
//    static constexpr auto ActionTimelineEventBaseGuardStand = 808;
//    static constexpr auto ActionTimelineEventBaseTalkMemo = 923;
//    static constexpr auto ActionTimelineFacialFear = 614;
//    static constexpr auto Actor0 = 1010984;
//    static constexpr auto Actor1 = 1010988;
//    static constexpr auto Actor2 = 1010897;
//    static constexpr auto Actor3 = 1010989;
//    static constexpr auto Actor4 = 1010990;
//    static constexpr auto Actor5 = 1010991;
//    static constexpr auto Actor6 = 1011614;
//    static constexpr auto Eobject0 = 2005068;
//    static constexpr auto EventActionWatchguardMiddle = 56;
//    static constexpr auto LocActor0 = 5607545;
//    static constexpr auto LocActor1 = 1009412;
//    static constexpr auto LocActor2 = 1009413;
//    static constexpr auto LocActor3 = 1011648;
//    static constexpr auto LocActor4 = 1011617;
//    static constexpr auto LocPosActor0 = 5681111;
//    static constexpr auto LocPosActor1 = 5681116;
//    static constexpr auto LocPosActor2 = 5839603;
//    static constexpr auto Poprange0 = 5684830;

  public:
    GaiUse612() : Sapphire::ScriptAPI::EventScript( 65960 ){}; 
    ~GaiUse612() = default; 

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
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2005068 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010988 ) { Scene00004( player ); }
break;
}
case 255:{
//ACTOR2, null, 0, -2, False
if( actor == 1010897 ) { Scene00006( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1010989 ) { Scene00007( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010990 ) { Scene00008( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010991 ) { Scene00009( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1011614 ) { Scene00010( player ); }
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
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00004 ACTOR1", getId() );

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00006 ACTOR2", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR3", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR4", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR5", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR6", getId() );


  }

};

EXPOSE_SCRIPT( GaiUse612 );
