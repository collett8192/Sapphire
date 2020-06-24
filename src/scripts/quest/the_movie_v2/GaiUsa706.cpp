// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa706_00779
// Quest Name: Corpse Confrontation
// Quest ID: 66315
// Start NPC: 1006226
// End NPC: 1006226

using namespace Sapphire;

class GaiUsa706 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006226;
//    static constexpr auto Actor1 = 1007710;
//    static constexpr auto Enemy0 = 4284061;
//    static constexpr auto Enemy1 = 4284063;
//    static constexpr auto Enemy2 = 4284064;
//    static constexpr auto Enemy3 = 4284065;
//    static constexpr auto Enemy4 = 4284066;
//    static constexpr auto Enemy5 = 4284067;
//    static constexpr auto Eobject0 = 2002460;
//    static constexpr auto Eobject1 = 2002640;
//    static constexpr auto Eobject2 = 2002641;
//    static constexpr auto Eventrange0 = 4283978;
//    static constexpr auto EventActionSearch = 1;

  public:
    GaiUsa706() : Sapphire::ScriptAPI::EventScript( 66315 ){}; 
    ~GaiUsa706() = default; 

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
//if( actorId == 4284061 && player.getQuestUI8AL( getId() ) != 6 ) { Scene?????( player ); }
//if( actorId == 4284063 && player.getQuestUI8AL( getId() ) != 6 ) { Scene?????( player ); }
//if( actorId == 4284064 && player.getQuestUI8AL( getId() ) != 6 ) { Scene?????( player ); }
//if( actorId == 4284065 && player.getQuestUI8AL( getId() ) != 6 ) { Scene?????( player ); }
//if( actorId == 4284066 && player.getQuestUI8AL( getId() ) != 6 ) { Scene?????( player ); }
//if( actorId == 4284067 && player.getQuestUI8AL( getId() ) != 6 ) { Scene?????( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002460 ) { Scene00002( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002640 ) { Scene00004( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002641 ) { Scene00005( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007710 ) { Scene00006( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006226 ) { Scene00007( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002640 ) { Scene00008( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002641 ) { Scene00009( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007710 ) { Scene00010( player ); }
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
//      case Enemy3: { break; }
//      case Enemy4: { break; }
//      case Enemy5: { break; }
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
if( result.param2 == 1 ){
player.updateQuest( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](2)Empty:Scene00001 EOBJECT0", getId() );


  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00002 +2 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](2)Empty:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT1", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT2", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00007 ACTOR0", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT2", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR1", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsa706 );
