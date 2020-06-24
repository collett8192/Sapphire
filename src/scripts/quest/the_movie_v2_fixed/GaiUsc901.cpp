// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsc901_01036
// Quest Name: Operation Archon
// Quest ID: 66572
// Start NPC: 1006690
// End NPC: 1006578

using namespace Sapphire;

class GaiUsc901 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006690;
//    static constexpr auto Actor1 = 1006578;
//    static constexpr auto Actor2 = 1006633;
//    static constexpr auto Actor3 = 1006712;
//    static constexpr auto Actor4 = 1006713;
//    static constexpr auto CutScene01 = 117;
//    static constexpr auto CutScene02 = 261;
//    static constexpr auto CutSceneAfter01 = 294;
//    static constexpr auto CutSceneAfter02 = 264;
//    static constexpr auto Eobject0 = 2002252;
//    static constexpr auto EventActionTouchMiddle = 46;
//    static constexpr auto Instancedungeon0 = 20007;
//    static constexpr auto Poprange0 = 4309569;
//    static constexpr auto Territorytype0 = 140;
//    static constexpr auto UnlockAddNewContentToCf = 3702;
//    static constexpr auto UnlockImageContentBattle = 114;

  public:
    GaiUsc901() : Sapphire::ScriptAPI::EventScript( 66572 ){}; 
    ~GaiUsc901() = default; 

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
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1006633 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006712 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006713 ) { Scene00005( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006578 ) { Scene00006( player ); }
break;
}
case 3:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002252 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00007( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006633 ) { Scene00009( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006578 ) { Scene00010( player ); }
break;
}
case 4:{
//ACTOR2, null, 0, -2, False
if( actor == 1006633 ) { Scene00011( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006578 ) { Scene00012( player ); }
break;
}
case 5:{
//no scene is assigned
break;
}
case 255:{
Scene00014( player );
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept, CutScene:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //Target: ACTOR2
      player.setQuestUI8AL( getId(), 1 );
      if( player.getQuestUI8AL( getId() ) == 1 ){
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 3 );
      }
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](2)CutScene:Scene00003 ", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {




player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR2:UI8AL=-2, 1", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR3", getId() );


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


Scene00008( player );

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
      Scene00013( player );
    };
player.sendDebug( "questId: {}, calling Message:Scene00008 EOBJECT0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR2", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR1", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR2", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 +1 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](12)CutScene:Scene00013 ACTOR1", getId() );

    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00014 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsc901 );
