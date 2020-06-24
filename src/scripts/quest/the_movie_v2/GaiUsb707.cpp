// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb707_00902
// Quest Name: Dark and Stormy Night
// Quest ID: 66438
// Start NPC: 1006402
// End NPC: 1006402

using namespace Sapphire;

class GaiUsb707 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006402;
//    static constexpr auto Eobject0 = 2002126;
//    static constexpr auto Eobject1 = 2002127;
//    static constexpr auto Eobject2 = 2002128;
//    static constexpr auto Eobject3 = 2002129;
//    static constexpr auto Eobject4 = 2002130;
//    static constexpr auto Eobject5 = 2002561;
//    static constexpr auto Eobject6 = 2002562;
//    static constexpr auto Eobject7 = 2002563;
//    static constexpr auto Eobject8 = 2002564;
//    static constexpr auto Eobject9 = 2002565;
//    static constexpr auto Item0 = 2000706;

  public:
    GaiUsb707() : Sapphire::ScriptAPI::EventScript( 66438 ){}; 
    ~GaiUsb707() = default; 

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
if( actor == 2002126 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00001( player ); }
//EOBJECT1, UI8AL, 5, -2, False
if( actor == 2002127 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00002( player ); }
//EOBJECT2, UI8AL, 5, -2, False
if( actor == 2002128 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00003( player ); }
//EOBJECT3, UI8AL, 5, -2, False
if( actor == 2002129 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00004( player ); }
//EOBJECT4, UI8AL, 5, -2, False
if( actor == 2002130 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00005( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006402 ) { Scene00012( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002561 ) { Scene00013( player ); }
//EOBJECT6, null, 0, -2, False
if( actor == 2002562 ) { Scene00014( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002563 ) { Scene00015( player ); }
//EOBJECT8, null, 0, -2, False
if( actor == 2002564 ) { Scene00016( player ); }
//EOBJECT9, null, 0, -2, False
if( actor == 2002565 ) { Scene00017( player ); }
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


//Target: EOBJECT0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00001 EOBJECT0:UI8AL=-2, 5", getId() );


  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00002 EOBJECT1:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT2:UI8AL=-2, 5", getId() );


  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00004 EOBJECT3:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT4:UI8AL=-2, 5", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00006 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00007 ", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 ", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00010 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 ", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00012 ACTOR0", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00013 EOBJECT5", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: EOBJECT6
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00014 EOBJECT6", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: EOBJECT7
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00015 EOBJECT7", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT8
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00016 EOBJECT8", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: EOBJECT9
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00017 EOBJECT9", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb707 );
