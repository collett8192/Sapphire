// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: True, A3: False, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb003_00810
// Quest Name: Hungry Hungry Goobbues
// Quest ID: 66346
// Start NPC: 1006264
// End NPC: 1006264

using namespace Sapphire;

class GaiUsb003 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006264;
//    static constexpr auto Enemy0 = 4291318;
//    static constexpr auto Eobject0 = 2002034;
//    static constexpr auto Eobject1 = 2002633;
//    static constexpr auto Eobject2 = 2002634;
//    static constexpr auto Eobject3 = 2002635;
//    static constexpr auto Eobject4 = 2002636;
//    static constexpr auto Eobject5 = 2002637;
//    static constexpr auto EventActionLookoutLong = 41;
//    static constexpr auto EventActionSearch = 1;

  public:
    GaiUsb003() : Sapphire::ScriptAPI::EventScript( 66346 ){}; 
    ~GaiUsb003() = default; 

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
if( actor == 2002034 ) { Scene00002( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4291318 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002633 ) { Scene00005( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002634 ) { Scene00007( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002635 ) { Scene00009( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002636 ) { Scene00011( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002637 ) { Scene00013( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006264 ) { Scene00014( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002633 ) { Scene00015( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002634 ) { Scene00017( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002635 ) { Scene00019( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002636 ) { Scene00021( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002637 ) { Scene00023( player ); }
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
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](5)Empty:Scene00006 EOBJECT1", getId() );


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
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Empty:Scene00008 EOBJECT2", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](9)Empty:Scene00010 EOBJECT3", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00011 +1 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](11)Empty:Scene00012 EOBJECT4", getId() );


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
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00014 ACTOR0", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00016( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00015 +1 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](15)Empty:Scene00016 EOBJECT1", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00018( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00017 +1 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](17)Empty:Scene00018 EOBJECT2", getId() );


  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00020( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00019 +1 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](19)Empty:Scene00020 EOBJECT3", getId() );


  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00022( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00021 +1 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](21)Empty:Scene00022 EOBJECT4", getId() );


  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00024( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00023 +1 ", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](23)Empty:Scene00024 EOBJECT5", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb003 );
