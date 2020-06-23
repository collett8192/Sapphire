// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst047_00374
// Quest Name: Feeding Time
// Quest ID: 65910
// Start NPC: 1000470
// End NPC: 1000470

using namespace Sapphire;

class SubFst047 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1000470;
//    static constexpr auto Eobject0 = 2000999;
//    static constexpr auto Eobject1 = 2001000;
//    static constexpr auto Eobject2 = 2001001;
//    static constexpr auto Eobject3 = 2001002;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000242;
//    static constexpr auto Seq0Actor0 = 0;
//    static constexpr auto Seq1Eobject0 = 1;
//    static constexpr auto Seq1Eobject0Eventactionno = 99;
//    static constexpr auto Seq1Eobject0Eventactionok = 100;
//    static constexpr auto Seq2Eobject1 = 2;
//    static constexpr auto Seq2Eobject1Useitemno = 97;
//    static constexpr auto Seq2Eobject1Useitemok = 98;
//    static constexpr auto Seq2Eobject2 = 3;
//    static constexpr auto Seq2Eobject2Useitemno = 95;
//    static constexpr auto Seq2Eobject2Useitemok = 96;
//    static constexpr auto Seq2Eobject3 = 4;
//    static constexpr auto Seq2Eobject3Useitemno = 93;
//    static constexpr auto Seq2Eobject3Useitemok = 94;
//    static constexpr auto Seq3Actor0 = 5;
//    static constexpr auto Seq3Eobject1 = 6;
//    static constexpr auto Seq3Eobject1Eventactionno = 91;
//    static constexpr auto Seq3Eobject1Eventactionok = 92;
//    static constexpr auto Seq3Eobject2 = 7;
//    static constexpr auto Seq3Eobject2Eventactionno = 89;
//    static constexpr auto Seq3Eobject2Eventactionok = 90;
//    static constexpr auto Seq3Eobject3 = 8;
//    static constexpr auto Seq3Eobject3Eventactionno = 87;
//    static constexpr auto Seq3Eobject3Eventactionok = 88;

  public:
    SubFst047() : Sapphire::ScriptAPI::EventScript( 65910 ){}; 
    ~SubFst047() = default; 

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
//EOBJECT1, UI8AL, 3, -2, False
if( actor == 2001000 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00002( player ); }
//EOBJECT2, UI8AL, 3, -2, False
if( actor == 2001001 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00003( player ); }
//EOBJECT3, UI8AL, 3, -2, False
if( actor == 2001002 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00004( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1000470 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001000 ) { Scene00006( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001001 ) { Scene00007( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001002 ) { Scene00008( player ); }
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
if( result.param2 == 1 ){
player.updateQuest( getId(), 1 );
player.setQuestUI8BH( getId(), 1 );
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
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Empty:Scene00001 +2 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00002 EOBJECT1:UI8AL=-2, 3", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00003 EOBJECT2:UI8AL=-2, 3", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00004 EOBJECT3:UI8AL=-2, 3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00005 ACTOR0", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT2", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT3", getId() );


  }

  void Scene00087( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00087 ", getId() );


  }

  void Scene00088( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00088 ", getId() );


  }

  void Scene00089( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00089 ", getId() );


  }

  void Scene00090( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00090 ", getId() );


  }

  void Scene00091( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00091 ", getId() );


  }

  void Scene00092( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00092 ", getId() );


  }

  void Scene00093( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00093 ", getId() );


  }

  void Scene00094( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00094 ", getId() );


  }

  void Scene00095( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00095 ", getId() );


  }

  void Scene00096( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00096 ", getId() );


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
player.sendDebug( "questId: {}, calling [sub:Ok](1)Empty:Scene00100 ", getId() );

    player.playScene( getId(), 100, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubFst047 );
