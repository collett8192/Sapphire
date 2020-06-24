// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb202_00833
// Quest Name: Who Moved My Headcheese
// Quest ID: 66369
// Start NPC: 1006269
// End NPC: 1006269

using namespace Sapphire;

class GaiUsb202 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006269;
//    static constexpr auto Enemy0 = 4293253;
//    static constexpr auto Enemy1 = 4293254;
//    static constexpr auto Eobject0 = 2002050;
//    static constexpr auto Eobject1 = 2002291;
//    static constexpr auto Eobject2 = 2002292;
//    static constexpr auto Eobject3 = 2002293;
//    static constexpr auto Eobject4 = 2002294;
//    static constexpr auto Eobject5 = 2002051;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionWaitingShor = 11;
//    static constexpr auto Item0 = 2000650;

  public:
    GaiUsb202() : Sapphire::ScriptAPI::EventScript( 66369 ){}; 
    ~GaiUsb202() = default; 

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
//EOBJECT0, UI8AL, 5, -2, False
if( actor == 2002050 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00002( player ); }
//EOBJECT1, UI8AL, 5, -2, False
if( actor == 2002291 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00003( player ); }
//EOBJECT2, UI8AL, 5, -2, False
if( actor == 2002292 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00004( player ); }
//EOBJECT3, UI8AL, 5, -2, False
if( actor == 2002293 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00005( player ); }
//EOBJECT4, UI8AL, 5, -2, False
if( actor == 2002294 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00006( player ); }
break;
}
case 2:{
//EOBJECT5, null, 0, -2, False
if( actor == 2002051 ) { Scene00007( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002050 ) { Scene00008( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002291 ) { Scene00009( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002292 ) { Scene00010( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002293 ) { Scene00011( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002294 ) { Scene00013( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006269 ) { Scene00024( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002050 ) { Scene00025( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002291 ) { Scene00026( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002292 ) { Scene00027( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002293 ) { Scene00028( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002294 ) { Scene00029( player ); }
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
//Target: EOBJECT0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00002 EOBJECT0:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT1:UI8AL=-2, 5", getId() );


  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00004 EOBJECT2:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT3:UI8AL=-2, 5", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00006 EOBJECT4:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT5", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00008 EOBJECT0", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00010 EOBJECT2", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 EOBJECT3", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](13)Empty:Scene00012 EOBJECT4", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00013 +2 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](13)Empty:Scene00014 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00015 ", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00016 ", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00017 ", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00018 ", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00019 ", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00020 ", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00021 ", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00022 ", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00023 ", getId() );


  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00024 ACTOR0", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00025 EOBJECT0", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00026 EOBJECT1", getId() );


  }

  void Scene00027( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00027 EOBJECT2", getId() );


  }

  void Scene00028( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00028 EOBJECT3", getId() );


  }

  void Scene00029( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00029 EOBJECT4", getId() );


  }

  void Scene00030( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00030 ", getId() );


  }

  void Scene00031( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00031 ", getId() );


  }

  void Scene00032( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00032 ", getId() );


  }

  void Scene00033( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00033 ", getId() );


  }

  void Scene00034( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00034 ", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb202 );
