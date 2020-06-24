// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea059_00471
// Quest Name: Rocks in a Hard Place
// Quest ID: 66007
// Start NPC: 1002633
// End NPC: 1002633

using namespace Sapphire;

class SubSea059 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL

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
//    static constexpr auto Actor0 = 1002633;
//    static constexpr auto Eobject0 = 2001272;
//    static constexpr auto Eobject1 = 2001243;
//    static constexpr auto Eobject2 = 2001244;
//    static constexpr auto Eobject3 = 2001245;
//    static constexpr auto Eobject4 = 2001246;
//    static constexpr auto Eobject5 = 2001247;
//    static constexpr auto Eobject6 = 2001248;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionSearchShort = 2;
//    static constexpr auto Item0 = 2000350;

  public:
    SubSea059() : Sapphire::ScriptAPI::EventScript( 66007 ){}; 
    ~SubSea059() = default; 

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
//EOBJECT1, UI8BH, 3, -2, False
if( actor == 2001243 && player.getQuestUI8BH( getId() ) != 3 ) { Scene00002( player ); }
//EOBJECT2, UI8BH, 3, -2, False
if( actor == 2001244 && player.getQuestUI8BH( getId() ) != 3 ) { Scene00003( player ); }
//EOBJECT3, UI8BH, 3, -2, False
if( actor == 2001245 && player.getQuestUI8BH( getId() ) != 3 ) { Scene00004( player ); }
//EOBJECT4, UI8AL, 3, -2, False
if( actor == 2001246 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00005( player ); }
//EOBJECT5, UI8AL, 3, -2, False
if( actor == 2001247 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00006( player ); }
//EOBJECT6, UI8AL, 3, -2, False
if( actor == 2001248 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00007( player ); }
break;
}
case 255:{
Scene00008( player );
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


player.updateQuest( getId(), 2 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00001 ", getId() );


  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 3 ){
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00002 EOBJECT1:UI8BH=-2, 3", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 3 ){
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00003 EOBJECT2:UI8BH=-2, 3", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 3 ){
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00004 EOBJECT3:UI8BH=-2, 3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 3 ){
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT4:UI8AL=-2, 3", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT5
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 3 ){
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT5:UI8AL=-2, 3", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT6
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 3 ){
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT6:UI8AL=-2, 3", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
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



player.sendDebug( "questId: {}, calling Empty:Scene00098 ", getId() );


  }

  void Scene00099( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00099 ", getId() );


  }

  void Scene00100( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00100 ", getId() );


  }

};

EXPOSE_SCRIPT( SubSea059 );
