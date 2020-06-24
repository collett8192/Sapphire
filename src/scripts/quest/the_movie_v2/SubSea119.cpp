// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: True, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea119_00416
// Quest Name: Forbidden Island
// Quest ID: 65952
// Start NPC: 1002446
// End NPC: 1002446

using namespace Sapphire;

class SubSea119 : public Sapphire::ScriptAPI::EventScript
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
    // GetQuestUI8DL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1002446;
//    static constexpr auto Enemy0 = 3782177;
//    static constexpr auto Enemy1 = 3782179;
//    static constexpr auto Enemy10 = 3782387;
//    static constexpr auto Enemy11 = 3782389;
//    static constexpr auto Enemy2 = 3782180;
//    static constexpr auto Enemy3 = 3782187;
//    static constexpr auto Enemy4 = 3782196;
//    static constexpr auto Enemy5 = 3782197;
//    static constexpr auto Enemy6 = 3782198;
//    static constexpr auto Enemy7 = 3782209;
//    static constexpr auto Enemy8 = 3782220;
//    static constexpr auto Enemy9 = 3782386;
//    static constexpr auto Eobject0 = 2000772;
//    static constexpr auto Eobject1 = 2000773;
//    static constexpr auto Eobject2 = 2000774;
//    static constexpr auto Item0 = 2000221;
//    static constexpr auto Seq0Actor0 = 0;
//    static constexpr auto Seq1Eobject0 = 1;
//    static constexpr auto Seq1Eobject0Useitemno = 99;
//    static constexpr auto Seq1Eobject0Useitemok = 100;
//    static constexpr auto Seq1Eobject1 = 2;
//    static constexpr auto Seq1Eobject1Useitemno = 97;
//    static constexpr auto Seq1Eobject1Useitemok = 98;
//    static constexpr auto Seq1Eobject2 = 3;
//    static constexpr auto Seq1Eobject2Useitemno = 95;
//    static constexpr auto Seq1Eobject2Useitemok = 96;
//    static constexpr auto Seq2Actor0 = 4;

  public:
    SubSea119() : Sapphire::ScriptAPI::EventScript( 65952 ){}; 
    ~SubSea119() = default; 

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
if( actor == 2000772 ) { Scene00001( player ); }
//if( actorId == 3782177 && player.getQuestUI8AL( getId() ) != 4 ) { Scene?????( player ); }
//if( actorId == 3782179 && player.getQuestUI8AL( getId() ) != 4 ) { Scene?????( player ); }
//if( actorId == 3782180 && player.getQuestUI8AL( getId() ) != 4 ) { Scene?????( player ); }
//if( actorId == 3782187 && player.getQuestUI8AL( getId() ) != 4 ) { Scene?????( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2000773 ) { Scene00002( player ); }
//if( actorId == 3782196 && player.getQuestUI8BL( getId() ) != 4 ) { Scene?????( player ); }
//if( actorId == 3782197 && player.getQuestUI8BL( getId() ) != 4 ) { Scene?????( player ); }
//if( actorId == 3782198 && player.getQuestUI8BL( getId() ) != 4 ) { Scene?????( player ); }
//if( actorId == 3782209 && player.getQuestUI8BL( getId() ) != 4 ) { Scene?????( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2000774 ) { Scene00003( player ); }
//if( actorId == 3782220 && player.getQuestUI8CL( getId() ) != 4 ) { Scene?????( player ); }
//if( actorId == 3782386 && player.getQuestUI8CL( getId() ) != 4 ) { Scene?????( player ); }
//if( actorId == 3782387 && player.getQuestUI8CL( getId() ) != 4 ) { Scene?????( player ); }
//if( actorId == 3782389 && player.getQuestUI8CL( getId() ) != 4 ) { Scene?????( player ); }
break;
}
case 255:{
Scene00004( player );
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
//      case Enemy6: { break; }
//      case Enemy7: { break; }
//      case Enemy8: { break; }
//      case Enemy9: { break; }
//      case Enemy10: { break; }
//      case Enemy11: { break; }
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
player.setQuestUI8DL( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00001 EOBJECT0", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00002 EOBJECT1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00003 EOBJECT2", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00004 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00095( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling [sub:SkippedMsg](96)Empty:Scene00095 ", getId() );


  }

  void Scene00096( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
player.sendDebug( "questId: {}, calling Message:Scene00096 +1 ", getId() );

    player.playScene( getId(), 96, NONE, callback );
  }

  void Scene00097( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling [sub:SkippedMsg](98)Empty:Scene00097 ", getId() );


  }

  void Scene00098( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
player.sendDebug( "questId: {}, calling Message:Scene00098 +1 ", getId() );

    player.playScene( getId(), 98, NONE, callback );
  }

  void Scene00099( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](100)Empty:Scene00099 ", getId() );


  }

  void Scene00100( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//next scene not found
    };
player.sendDebug( "questId: {}, calling Message:Scene00100 +1 ", getId() );

    player.playScene( getId(), 100, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubSea119 );
