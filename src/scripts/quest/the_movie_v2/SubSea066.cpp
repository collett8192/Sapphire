// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea066_00478
// Quest Name: Kobolds and Indigents
// Quest ID: 66014
// Start NPC: 1002591
// End NPC: 1002571

using namespace Sapphire;

class SubSea066 : public Sapphire::ScriptAPI::EventScript
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
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1002591;
//    static constexpr auto Actor1 = 1002678;
//    static constexpr auto Actor2 = 1002571;
//    static constexpr auto Enemy0 = 4014174;
//    static constexpr auto Enemy1 = 4014176;
//    static constexpr auto Enemy2 = 4014178;
//    static constexpr auto Eobject0 = 2001489;
//    static constexpr auto Eobject1 = 2000450;
//    static constexpr auto EventActionProcessMiddle = 16;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000430;

  public:
    SubSea066() : Sapphire::ScriptAPI::EventScript( 66014 ){}; 
    ~SubSea066() = default; 

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
//EOBJECT0, null, 0, -2, False
if( actor == 2001489 ) { Scene00002( player ); }
//if( actorId == 4014174 && player.getQuestUI8AL( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4014176 && player.getQuestUI8AL( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4014178 && player.getQuestUI8AL( getId() ) != 3 ) { Scene?????( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1002678 ) { Scene00003( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2000450 ) { Scene00005( player ); }
break;
}
case 3:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1002678 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00007( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001489 ) { Scene00009( player ); }
break;
}
case 4:{
//ACTOR0, UI8AL, 1, -1, False
if( actor == 1002591 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00010( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1002678 ) { Scene00013( player ); }
//EOBJECT0, null, 0, -1, False
if( actor == 2001489 ) { Scene00014( player ); }
break;
}
case 255:{
Scene00015( player );
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
player.setQuestUI8BH( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00002 EOBJECT0", getId() );


  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00004( player ); }
    };
player.sendDebug( "questId: {}, calling Message:Scene00003 +1 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](3)Talk:Scene00004 ACTOR1", getId() );

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
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 3 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](5)Empty:Scene00006 EOBJECT1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 3 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Empty:Scene00008 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT0", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00011( player ); }
 else { Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00010 +2 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](10)Talk:Scene00011 ACTOR0:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](10)Talk:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR1", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00014 EOBJECT0", getId() );


  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00015 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubSea066 );
