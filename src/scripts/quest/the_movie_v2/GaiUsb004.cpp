// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb004_00811
// Quest Name: The Lominsan Way
// Quest ID: 66347
// Start NPC: 1006264
// End NPC: 1006266

using namespace Sapphire;

class GaiUsb004 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006264;
//    static constexpr auto Actor1 = 1006265;
//    static constexpr auto Actor2 = 1006266;
//    static constexpr auto Eobject0 = 2002284;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocAction0 = 1005;
//    static constexpr auto LocActor0 = 1005259;
//    static constexpr auto LocActor1 = 1003782;
//    static constexpr auto LocActor9 = 1006676;
//    static constexpr auto LocBgm1 = 101;
//    static constexpr auto LocFace0 = 604;
//    static constexpr auto LocFace1 = 620;
//    static constexpr auto LocSe1 = 39;
//    static constexpr auto LocSe2 = 40;
//    static constexpr auto Questbattle0 = 59;
//    static constexpr auto Seq0Actor0Lq = 90;
//    static constexpr auto Territorytype0 = 307;

  public:
    GaiUsb004() : Sapphire::ScriptAPI::EventScript( 66347 ){}; 
    ~GaiUsb004() = default; 

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
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1006265 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002284 ) { Scene00004( player ); }
break;
}
case 255:{
Scene00005( player );
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
Scene00090( player );
    };
player.sendDebug( "questId: {}, calling QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Empty:Scene00003 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT0", getId() );


  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00005 ", getId() );

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00090( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00090 ", getId() );

    player.playScene( getId(), 90, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb004 );
