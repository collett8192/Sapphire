// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: False, A3: False, S: True, R: False, DM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa007_00713
// Quest Name: Stand-in Sentry
// Quest ID: 66249
// Start NPC: 1006189
// End NPC: 1006189

using namespace Sapphire;

class GaiUsa007 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006189;
//    static constexpr auto Enemy0 = 4277274;
//    static constexpr auto Enemy1 = 4277391;
//    static constexpr auto Enemy2 = 4278132;
//    static constexpr auto Eobject0 = 2002606;
//    static constexpr auto Eobject1 = 2002607;
//    static constexpr auto Eobject2 = 2002608;
//    static constexpr auto Eobject3 = 2000717;
//    static constexpr auto Eobject4 = 2000718;
//    static constexpr auto Eobject5 = 2000719;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionWatchguardLong = 28;

  public:
    GaiUsa007() : Sapphire::ScriptAPI::EventScript( 66249 ){}; 
    ~GaiUsa007() = default; 

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
if( actor == 2002606 ) { Scene00002( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4277274 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002607 ) { Scene00005( player ); }
//ENEMY1, UI8BH, 1, -2, False
if( actorId == 4277391 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00007( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002608 ) { Scene00009( player ); }
//ENEMY2, UI8BL, 1, -2, False
if( actorId == 4278132 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00010( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2000717 ) { Scene00011( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2000718 ) { Scene00012( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2000719 ) { Scene00013( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006189 ) { Scene00014( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2000717 ) { Scene00015( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2000718 ) { Scene00016( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2000719 ) { Scene00017( player ); }
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
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00002 EOBJECT0", getId() );


  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00003 +1 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](3)Empty:Scene00004 ENEMY0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](5)Empty:Scene00006 EOBJECT1", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](7)Empty:Scene00008 ENEMY1:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT2", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ENEMY2
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00010 ENEMY2:UI8BL=-2, 1", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 EOBJECT3", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00012 EOBJECT4", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00013 EOBJECT5", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00014 ACTOR0", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00015 EOBJECT3", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00016 EOBJECT4", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00017 EOBJECT5", getId() );


  }

  void Scene00018( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00018 ", getId() );


  }

  void Scene00019( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00019 ", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00020 ", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsa007 );
