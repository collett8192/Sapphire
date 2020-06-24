// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb607_00889
// Quest Name: Three for Three
// Quest ID: 66425
// Start NPC: 1006380
// End NPC: 1006380

using namespace Sapphire;

class GaiUsb607 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH
    // GetQuestUI8CL
    // GetQuestUI8DH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006380;
//    static constexpr auto Enemy0 = 4290078;
//    static constexpr auto Enemy1 = 4290079;
//    static constexpr auto Enemy2 = 4290080;
//    static constexpr auto Eobject0 = 2002261;
//    static constexpr auto Eobject1 = 2002111;
//    static constexpr auto Eobject2 = 2002110;
//    static constexpr auto Eventrange0 = 4290068;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000693;
//    static constexpr auto Item1 = 2000694;
//    static constexpr auto Item2 = 2000695;
//    static constexpr auto LocActor0 = 1007664;
//    static constexpr auto LocActor1 = 1006382;
//    static constexpr auto LocBgm1 = 130;
//    static constexpr auto LocEobj1 = 2002556;
//    static constexpr auto LocEobj2 = 2002557;
//    static constexpr auto LocEobj3 = 2002558;
//    static constexpr auto LocPosActor1 = 4260909;
//    static constexpr auto LocPosEobj1 = 4329703;
//    static constexpr auto LocPosEobj2 = 4329704;
//    static constexpr auto LocPosEobj3 = 4329705;

  public:
    GaiUsb607() : Sapphire::ScriptAPI::EventScript( 66425 ){}; 
    ~GaiUsb607() = default; 

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
//EOBJECT0, null, 0, -2, False
if( actor == 2002261 ) { Scene00003( player ); }
//if( actorId == 4290078 && player.getQuestUI8BL( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4290079 && player.getQuestUI8BL( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4290080 && player.getQuestUI8BL( getId() ) != 3 ) { Scene?????( player ); }
//EOBJECT1, UI8AL, 1, -2, False
if( actor == 2002111 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//EOBJECT2, UI8BH, 1, -2, False
if( actor == 2002110 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00007( player ); }
break;
}
case 255:{
Scene00009( player );
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
//      case Enemy1: { break; }
//      case Enemy2: { break; }
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
player.setQuestUI8CH( getId(), 1 );
player.setQuestUI8CL( getId(), 1 );
player.setQuestUI8DH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](3)Message:Scene00002 EOBJECT0", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00003 +2 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](3)Empty:Scene00004 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](5)Empty:Scene00006 EOBJECT1:UI8AL=-2, 1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Empty:Scene00008 EOBJECT2:UI8BH=-2, 1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](9)Talk, QuestReward, QuestComplete, FadeOut:Scene00010 ", getId() );

    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb607 );
