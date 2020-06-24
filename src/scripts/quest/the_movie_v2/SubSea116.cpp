// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: True, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea116_00413
// Quest Name: Do Angry Pirates Dream
// Quest ID: 65949
// Start NPC: 1002238
// End NPC: 1002237

using namespace Sapphire;

class SubSea116 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1002238;
//    static constexpr auto Actor1 = 1002237;
//    static constexpr auto Actor2 = 1002240;
//    static constexpr auto Actor3 = 1002463;
//    static constexpr auto Actor4 = 1002464;
//    static constexpr auto Actor5 = 1002465;
//    static constexpr auto Eobject0 = 2000766;
//    static constexpr auto Eobject1 = 2000767;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocActor1 = 1002534;
//    static constexpr auto LocActor2 = 1002535;
//    static constexpr auto LocEobj1 = 2000768;

  public:
    SubSea116() : Sapphire::ScriptAPI::EventScript( 65949 ){}; 
    ~SubSea116() = default; 

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
Scene00001( player );
break;
}
case 2:{
Scene00002( player );
break;
}
case 3:{
//ACTOR3, UI8AL, 1, -2, False
if( actor == 1002463 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1002464 ) { Scene00004( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1002465 ) { Scene00007( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2000766 ) { Scene00010( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2000767 ) { Scene00011( player ); }
break;
}
case 255:{
Scene00012( player );
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
if( result.param2 == 1 ){
player.updateQuest( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00003 ACTOR3:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 +2 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Talk:Scene00005 ACTOR4", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](4)Empty:Scene00006 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00007 +2 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Empty:Scene00008 ACTOR5", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](7)Empty:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 EOBJECT0", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 EOBJECT1", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubSea116 );
