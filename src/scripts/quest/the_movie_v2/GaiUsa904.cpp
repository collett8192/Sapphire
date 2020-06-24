// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa904_00799
// Quest Name: Power of Deduction
// Quest ID: 66335
// Start NPC: 1006240
// End NPC: 1002780

using namespace Sapphire;

class GaiUsa904 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006240;
//    static constexpr auto Actor1 = 1007541;
//    static constexpr auto Actor2 = 1002780;
//    static constexpr auto Enemy0 = 4299601;
//    static constexpr auto Eobject0 = 2002462;
//    static constexpr auto Eventrange0 = 4299594;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000861;
//    static constexpr auto LocAction1 = 788;
//    static constexpr auto LocAction2 = 981;
//    static constexpr auto LocActor0 = 1006240;
//    static constexpr auto LocActor1 = 1006241;
//    static constexpr auto LocActor2 = 1006242;
//    static constexpr auto LocActor4 = 1007541;
//    static constexpr auto LocActor5 = 1007643;
//    static constexpr auto LocPosActor = 4329140;
//    static constexpr auto LocPosActor1 = 4256813;
//    static constexpr auto LocPosActor2 = 4256814;
//    static constexpr auto LocPosActor4 = 4329223;
//    static constexpr auto LocPosActor5 = 4329392;

  public:
    GaiUsa904() : Sapphire::ScriptAPI::EventScript( 66335 ){}; 
    ~GaiUsa904() = default; 

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
//ACTOR1, null, 0, -2, False
if( actor == 1007541 ) { Scene00002( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4299601 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002462 ) { Scene00006( player ); }
break;
}
case 255:{
Scene00007( player );
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
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](2)Message:Scene00003 ACTOR1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00004 +1 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: ENEMY0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00005 ENEMY0:UI8AL=-2, 1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT0", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](7)Talk, QuestReward, QuestComplete, FadeOut:Scene00008 ", getId() );

    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( GaiUsa904 );
