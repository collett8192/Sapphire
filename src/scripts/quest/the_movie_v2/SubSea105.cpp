// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea105_00402
// Quest Name: Thanks a Million
// Quest ID: 65938
// Start NPC: 1003239
// End NPC: 1003244

using namespace Sapphire;

class SubSea105 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1003239;
//    static constexpr auto Actor1 = 1003244;
//    static constexpr auto Enemy0 = 3927183;
//    static constexpr auto Enemy1 = 3927184;
//    static constexpr auto Eobject0 = 2001255;
//    static constexpr auto Eobject1 = 2001256;
//    static constexpr auto Eobject2 = 2001257;
//    static constexpr auto Eobject3 = 2001258;
//    static constexpr auto Eobject4 = 2001259;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000342;

  public:
    SubSea105() : Sapphire::ScriptAPI::EventScript( 65938 ){}; 
    ~SubSea105() = default; 

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
if( actor == 2001255 ) { Scene00002( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001256 ) { Scene00003( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001257 ) { Scene00004( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001258 ) { Scene00005( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2001259 ) { Scene00006( player ); }
break;
}
case 255:{
//ACTOR1, null, 0, -1, False
if( actor == 1003244 ) { Scene00006( player ); }
//EOBJECT1, null, 0, -1, False
if( actor == 2001256 ) { Scene00007( player ); }
//EOBJECT2, null, 0, -1, False
if( actor == 2001257 ) { Scene00008( player ); }
//EOBJECT3, null, 0, -1, False
if( actor == 2001258 ) { Scene00009( player ); }
//EOBJECT4, null, 0, -1, False
if( actor == 2001259 ) { Scene00010( player ); }
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
//next scene not found
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](100)Unknown:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00002 EOBJECT0", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00003 EOBJECT1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00004 EOBJECT2", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00005 EOBJECT3", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00090( player ); }
 else { Scene00089( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00006 +2 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00007 EOBJECT1", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00008 EOBJECT2", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00009 EOBJECT3", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT4
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00010 EOBJECT4", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00081( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00081 ", getId() );


  }

  void Scene00082( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00082 ", getId() );


  }

  void Scene00083( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00083 ", getId() );


  }

  void Scene00084( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00084 ", getId() );


  }

  void Scene00085( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00085 ", getId() );


  }

  void Scene00086( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00086 ", getId() );


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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](6)Empty:Scene00089 ", getId() );

    player.playScene( getId(), 89, NONE, callback );
  }

  void Scene00090( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](6)Talk, QuestReward, QuestComplete:Scene00090 ACTOR1", getId() );

    player.playScene( getId(), 90, NONE, callback );
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


//next scene not found

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](100)Empty:Scene00099 ", getId() );


  }

  void Scene00100( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//next scene not found
    };
player.sendDebug( "questId: {}, calling Message:Scene00100 +2 ", getId() );

    player.playScene( getId(), 100, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubSea105 );
