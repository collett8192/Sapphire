// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: True, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse214_01358
// Quest Name: Scouts in Distress
// Quest ID: 66894
// Start NPC: 1006614
// End NPC: 1006614

using namespace Sapphire;

class GaiUse214 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006614;
//    static constexpr auto Actor1 = 1008683;
//    static constexpr auto Actor2 = 1008684;
//    static constexpr auto Actor3 = 1008685;
//    static constexpr auto Enemy0 = 4628586;
//    static constexpr auto Enemy1 = 4628587;
//    static constexpr auto Enemy2 = 4628588;
//    static constexpr auto Eobject0 = 2003590;
//    static constexpr auto Eventrange0 = 4628585;
//    static constexpr auto EventActionProcessLong = 17;
//    static constexpr auto EventActionProcessMiddle = 16;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001214;
//    static constexpr auto Item1 = 2001215;

  public:
    GaiUse214() : Sapphire::ScriptAPI::EventScript( 66894 ){}; 
    ~GaiUse214() = default; 

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
if( actor == 1008683 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006614 ) { Scene00005( player ); }
break;
}
case 2:{
//EOBJECT0, null, 0, -2, False
if( actor == 2003590 ) { Scene00008( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008684 ) { Scene00011( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008685 ) { Scene00014( player ); }
break;
}
case 3:{
//ACTOR2, UI8AL, 2, -2, False
if( actor == 1008684 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00015( player ); }
//ACTOR3, UI8AL, 2, -2, False
if( actor == 1008685 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00016( player ); }
break;
}
case 255:{
Scene00016( player );
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
player.sendDebug( "questId: {}, calling Talk, Inventory:Scene00002 +2 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Talk:Scene00003 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](2)Talk:Scene00004 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Message:Scene00005 +2 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR0
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](5)Empty:Scene00006 ACTOR0", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](5)Empty:Scene00007 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00008 +2 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](8)Empty:Scene00009 EOBJECT0", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](8)Message:Scene00010 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Message:Scene00011 +2 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](11)Empty:Scene00012 ACTOR2", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](11)Empty:Scene00013 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR3", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 2 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR2:UI8AL=-2, 2", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00017( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00016 +1 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](16)Talk, QuestReward, QuestComplete:Scene00017 ACTOR3:UI8AL=-2, 2", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse214 );
