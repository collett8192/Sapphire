// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: True, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst054_00160
// Quest Name: Slimy Hollows
// Quest ID: 65696
// Start NPC: 1000494
// End NPC: 1000494

using namespace Sapphire;

class SubFst054 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1000494;
//    static constexpr auto Enemy0 = 1886902;
//    static constexpr auto Enemy1 = 1886903;
//    static constexpr auto Enemy2 = 1887083;
//    static constexpr auto Enemy3 = 1887164;
//    static constexpr auto Enemy4 = 1887165;
//    static constexpr auto Enemy5 = 1887166;
//    static constexpr auto Eobject0 = 2000043;
//    static constexpr auto Eobject1 = 2000044;
//    static constexpr auto Eobject2 = 2000045;
//    static constexpr auto Item0 = 2000100;
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
    SubFst054() : Sapphire::ScriptAPI::EventScript( 65696 ){}; 
    ~SubFst054() = default; 

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
if( actor == 2000043 ) { Scene00001( player ); }
//if( actorId == 1886902 && player.getQuestUI8AL( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 1886903 && player.getQuestUI8AL( getId() ) != 2 ) { Scene?????( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2000044 ) { Scene00002( player ); }
//if( actorId == 1887083 && player.getQuestUI8BL( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 1887164 && player.getQuestUI8BL( getId() ) != 2 ) { Scene?????( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2000045 ) { Scene00003( player ); }
//if( actorId == 1887165 && player.getQuestUI8CL( getId() ) != 2 ) { Scene?????( player ); }
//if( actorId == 1887166 && player.getQuestUI8CL( getId() ) != 2 ) { Scene?????( player ); }
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

EXPOSE_SCRIPT( SubFst054 );
