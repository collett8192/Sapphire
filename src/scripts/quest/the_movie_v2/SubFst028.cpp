// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst028_00171
// Quest Name: The Valued Vilekin
// Quest ID: 65707
// Start NPC: 1000629
// End NPC: 1000612

using namespace Sapphire;

class SubFst028 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000629;
//    static constexpr auto Actor1 = 1000612;
//    static constexpr auto Enemy0 = 2653890;
//    static constexpr auto Eobject0 = 2000140;
//    static constexpr auto Eobject1 = 2000142;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000144;
//    static constexpr auto Seq0Actor0 = 0;
//    static constexpr auto Seq1Eobject0 = 1;
//    static constexpr auto Seq1Eobject0Eventactionno = 99;
//    static constexpr auto Seq1Eobject0Eventactionok = 100;
//    static constexpr auto Seq2Eobject1 = 2;
//    static constexpr auto Seq2Eobject1Eventactionno = 97;
//    static constexpr auto Seq2Eobject1Eventactionok = 98;
//    static constexpr auto Seq3Actor1 = 3;
//    static constexpr auto Seq3Actor1Npctradeno = 95;
//    static constexpr auto Seq3Actor1Npctradeok = 96;

  public:
    SubFst028() : Sapphire::ScriptAPI::EventScript( 65707 ){}; 
    ~SubFst028() = default; 

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
if( actor == 2000140 ) { Scene00001( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 2653890 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
break;
}
case 2:{
//no scene is assigned
break;
}
case 255:{
Scene00003( player );
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
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Empty:Scene00001 +2 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: ENEMY0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00002 ENEMY0:UI8AL=-2, 1", getId() );


  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00096( player ); }
 else { Scene00095( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00003 +2 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00095( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](3)Empty:Scene00095 ", getId() );

    player.playScene( getId(), 95, NONE, callback );
  }

  void Scene00096( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](3)QuestReward, QuestComplete:Scene00096 ", getId() );

    player.playScene( getId(), 96, NONE, callback );
  }

  void Scene00097( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00097 ", getId() );


  }

  void Scene00098( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00098 ", getId() );


  }

  void Scene00099( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:No](1)Empty:Scene00099 ", getId() );

    player.playScene( getId(), 99, NONE, callback );
  }

  void Scene00100( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:Ok](1)Message:Scene00100 EOBJECT0", getId() );

    player.playScene( getId(), 100, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubFst028 );
