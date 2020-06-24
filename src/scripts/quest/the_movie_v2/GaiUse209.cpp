// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse209_01353
// Quest Name: All Due Respect
// Quest ID: 66889
// Start NPC: 1008623
// End NPC: 1008547

using namespace Sapphire;

class GaiUse209 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1008623;
//    static constexpr auto Actor1 = 1008656;
//    static constexpr auto Actor2 = 1008657;
//    static constexpr auto Actor3 = 1008658;
//    static constexpr auto Actor4 = 1006530;
//    static constexpr auto Actor5 = 1008659;
//    static constexpr auto Actor6 = 1008660;
//    static constexpr auto Actor7 = 1008661;
//    static constexpr auto Actor8 = 1008547;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocAction1 = 1002;
//    static constexpr auto LocActor0 = 1007097;
//    static constexpr auto LocActor1 = 1007098;
//    static constexpr auto LocActor2 = 1007099;
//    static constexpr auto LocActor3 = 1007766;
//    static constexpr auto LocActor4 = 1007767;
//    static constexpr auto LocFace1 = 605;
//    static constexpr auto LocFace2 = 620;
//    static constexpr auto LocPosActor0 = 4680581;
//    static constexpr auto LocPosActor1 = 4680587;
//    static constexpr auto LocSe1 = 42;

  public:
    GaiUse209() : Sapphire::ScriptAPI::EventScript( 66889 ){}; 
    ~GaiUse209() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1008623 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008656 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008657 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008658 ) { Scene00004( player ); }
break;
}
case 1:{
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1006530 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008656 ) { Scene00006( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008657 ) { Scene00007( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008658 ) { Scene00008( player ); }
break;
}
case 2:{
//ACTOR5, UI8AL, 1, -2, False
if( actor == 1008659 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00009( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1008660 ) { Scene00010( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1008661 ) { Scene00011( player ); }
break;
}
case 255:{
//ACTOR8, null, 0, -2, False
if( actor == 1008547 ) { Scene00012( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008659 ) { Scene00013( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1008660 ) { Scene00014( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1008661 ) { Scene00015( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00005 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR1", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR2", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR3", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR5:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR6", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR7", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00012 ACTOR8", getId() );

    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR5", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR6", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR7", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse209 );
