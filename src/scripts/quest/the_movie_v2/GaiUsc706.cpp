// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsc706_01018
// Quest Name: Honor the Fallen
// Quest ID: 66554
// Start NPC: 1006594
// End NPC: 1006594

using namespace Sapphire;

class GaiUsc706 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006594;
//    static constexpr auto Actor1 = 1006595;
//    static constexpr auto Actor2 = 1006596;
//    static constexpr auto Actor3 = 1006597;
//    static constexpr auto Actor4 = 1006598;
//    static constexpr auto Eobject0 = 2002566;
//    static constexpr auto Eobject1 = 2002567;
//    static constexpr auto Eobject2 = 2002568;
//    static constexpr auto Eobject3 = 2002569;
//    static constexpr auto EventActionSearchMiddle = 3;
//    static constexpr auto Item0 = 2000775;

  public:
    GaiUsc706() : Sapphire::ScriptAPI::EventScript( 66554 ){}; 
    ~GaiUsc706() = default; 

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
//EOBJECT0, UI8AL, 4, -2, False
if( actor == 2002566 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00002( player ); }
//EOBJECT1, UI8AL, 4, -2, False
if( actor == 2002567 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00003( player ); }
//EOBJECT2, UI8AL, 4, -2, False
if( actor == 2002568 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00004( player ); }
//EOBJECT3, UI8AL, 4, -2, False
if( actor == 2002569 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00005( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006595 ) { Scene00006( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006596 ) { Scene00007( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006597 ) { Scene00008( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006598 ) { Scene00009( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -1, False
if( actor == 1006594 ) { Scene00014( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1006595 ) { Scene00017( player ); }
//ACTOR2, null, 0, -1, False
if( actor == 1006596 ) { Scene00018( player ); }
//ACTOR3, null, 0, -1, False
if( actor == 1006597 ) { Scene00019( player ); }
//if( actor == 1006598 ) { Scene?????( player ); }
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
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00002 EOBJECT0:UI8AL=-2, 4", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT1:UI8AL=-2, 4", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT2:UI8AL=-2, 4", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT3:UI8AL=-2, 4", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR2", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR3", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR4", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 ", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 ", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00012 ", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00013 ", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00015( player ); }
 else { Scene00016( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00014 +2 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](14)Talk, QuestReward, QuestComplete:Scene00015 ACTOR0", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](14)Empty:Scene00016 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR1", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR2", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR3", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsc706 );
