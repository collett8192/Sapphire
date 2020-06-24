// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsc101_00952
// Quest Name: In Pursuit of the Past
// Quest ID: 66488
// Start NPC: 1006467
// End NPC: 1006491

using namespace Sapphire;

class GaiUsc101 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
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
//    static constexpr auto Actor0 = 1006467;
//    static constexpr auto Actor1 = 1006444;
//    static constexpr auto Actor2 = 1006490;
//    static constexpr auto Actor4 = 1006491;
//    static constexpr auto Actor5 = 1000106;
//    static constexpr auto ContentStart = 11;
//    static constexpr auto CutScene01 = 250;
//    static constexpr auto Eobject0 = 2002481;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Instancedungeon0 = 11;
//    static constexpr auto LocActor0 = 1003855;
//    static constexpr auto LocActor1 = 1004145;
//    static constexpr auto LocBgm1 = 82;
//    static constexpr auto Poprange0 = 4332874;
//    static constexpr auto Poprange1 = 4103392;
//    static constexpr auto Territorytype0 = 132;
//    static constexpr auto UnlockAddNewContentToCf = 3702;
//    static constexpr auto UnlockImageDungeon = 84;

  public:
    GaiUsc101() : Sapphire::ScriptAPI::EventScript( 66488 ){}; 
    ~GaiUsc101() = default; 

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
Scene00003( player );
break;
}
case 3:{
//if( actor == 2002481 ) { Scene?????( player ); }
//if( actor == 1006490 ) { Scene?????( player ); }
//if( actor == BASE_ID_TERRITORY_TYPE ) { Scene?????( player ); }
Scene00004( player );
break;
}
case 4:{
Scene00005( player );
break;
}
case 255:{
//ACTOR4, null, 0, -2, False
if( actor == 1006491 ) { Scene00008( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1000106 ) { Scene00009( player ); }
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
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00002 ", getId() );

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk, Message:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


Scene00007( player );

player.sendDebug( "questId: {}, calling Empty:Scene00004 ", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00005 ", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](6)CutScene:Scene00007 ", getId() );

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00008 ACTOR4", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
if( result.param2 == 1 ){
  player.sendUrgent( "not implemented, use \"!nudge 4\" to cross the gate." );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00009 ACTOR5", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsc101 );
