// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubWil093_00342
// Quest Name: Lominsan Rubbish
// Quest ID: 65878
// Start NPC: 1002069
// End NPC: 1002069

using namespace Sapphire;

class SubWil093 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1002069;
//    static constexpr auto Eobject0 = 2001382;
//    static constexpr auto Eobject1 = 2001383;
//    static constexpr auto Eobject2 = 2001384;
//    static constexpr auto Eobject3 = 2001475;
//    static constexpr auto Eobject4 = 2001476;
//    static constexpr auto Eobject5 = 2001477;
//    static constexpr auto Eobject6 = 2001478;
//    static constexpr auto Eobject7 = 2001479;
//    static constexpr auto EventActionProcessShor = 15;

  public:
    SubWil093() : Sapphire::ScriptAPI::EventScript( 65878 ){}; 
    ~SubWil093() = default; 

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
//EOBJECT0, UI8AL, 8, -2, False
if( actor == 2001382 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00001( player ); }
//EOBJECT1, UI8AL, 8, -2, False
if( actor == 2001383 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00002( player ); }
//EOBJECT2, UI8AL, 8, -2, False
if( actor == 2001384 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00003( player ); }
//EOBJECT3, UI8AL, 8, -2, False
if( actor == 2001475 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00004( player ); }
//EOBJECT4, UI8AL, 8, -2, False
if( actor == 2001476 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00005( player ); }
//EOBJECT5, UI8AL, 8, -2, False
if( actor == 2001477 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00006( player ); }
//EOBJECT6, UI8AL, 8, -2, False
if( actor == 2001478 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00007( player ); }
//EOBJECT7, UI8AL, 8, -2, False
if( actor == 2001479 && player.getQuestUI8AL( getId() ) != 8 ) { Scene00008( player ); }
break;
}
case 255:{
Scene00020( player );
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
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00001 EOBJECT0:UI8AL=-2, 8", getId() );


  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00002 EOBJECT1:UI8AL=-2, 8", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT2:UI8AL=-2, 8", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT3:UI8AL=-2, 8", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT4:UI8AL=-2, 8", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT5
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT5:UI8AL=-2, 8", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT6
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT6:UI8AL=-2, 8", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT7
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 8 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT7:UI8AL=-2, 8", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 ", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 ", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 ", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00012 ", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00013 ", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00014 ", getId() );


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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00020 ", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubWil093 );
