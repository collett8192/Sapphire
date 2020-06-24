// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse317_01458
// Quest Name: Heretical Harassment
// Quest ID: 66994
// Start NPC: 1008969
// End NPC: 1006384

using namespace Sapphire;

class GaiUse317 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008969;
//    static constexpr auto Actor1 = 1006530;
//    static constexpr auto Actor2 = 1006384;
//    static constexpr auto Actor3 = 1009077;
//    static constexpr auto Actor4 = 1009078;
//    static constexpr auto Actor5 = 1009079;
//    static constexpr auto Actor6 = 1009080;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocAction1 = 961;
//    static constexpr auto LocActor0 = 1009660;
//    static constexpr auto LocActor1 = 1009661;
//    static constexpr auto LocActor2 = 1009662;
//    static constexpr auto LocActor3 = 1009663;

  public:
    GaiUse317() : Sapphire::ScriptAPI::EventScript( 66994 ){}; 
    ~GaiUse317() = default; 

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
if( actor == 1006530 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008969 ) { Scene00003( player ); }
break;
}
case 255:{
//ACTOR2, null, 0, -2, False
if( actor == 1006384 ) { Scene00004( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006530 ) { Scene00005( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009077 ) { Scene00006( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009078 ) { Scene00007( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009079 ) { Scene00008( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009080 ) { Scene00009( player ); }
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
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00004 ACTOR2", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR3", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR4", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR5", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR6", getId() );


  }

};

EXPOSE_SCRIPT( GaiUse317 );
