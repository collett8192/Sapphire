// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: True, A3: False, S: True, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb612_00894
// Quest Name: I'd Rather Be Cannon Fodder
// Quest ID: 66430
// Start NPC: 1006386
// End NPC: 1006386

using namespace Sapphire;

class GaiUsb612 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006386;
//    static constexpr auto Enemy0 = 4291307;
//    static constexpr auto Eobject0 = 2002121;
//    static constexpr auto Eobject1 = 2002264;
//    static constexpr auto Eobject2 = 2002122;
//    static constexpr auto Eobject3 = 2002619;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000701;

  public:
    GaiUsb612() : Sapphire::ScriptAPI::EventScript( 66430 ){}; 
    ~GaiUsb612() = default; 

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
if( actor == 2002121 ) { Scene00002( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002264 ) { Scene00004( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002122 ) { Scene00006( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4291307 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00007( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002619 ) { Scene00009( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -1, False
if( actor == 1006386 ) { Scene00010( player ); }
//EOBJECT3, null, 0, -1, False
if( actor == 2002619 ) { Scene00012( player ); }
//EOBJECT1, null, 0, -1, False
if( actor == 2002264 ) { Scene00014( player ); }
//EOBJECT0, null, 0, -1, False
if( actor == 2002121 ) { Scene00016( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Empty:Scene00003 EOBJECT0", getId() );


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


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00005 EOBJECT1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT2", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
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
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](7)Empty:Scene00008 ENEMY0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT3", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00010 +1 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](10)Talk, QuestReward, QuestComplete:Scene00011 ACTOR0", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00013( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00012 +1 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](12)Empty:Scene00013 EOBJECT3", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00015( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00014 +1 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](14)Empty:Scene00015 EOBJECT1", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00017( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00016 +1 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](16)Empty:Scene00017 EOBJECT0", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb612 );
