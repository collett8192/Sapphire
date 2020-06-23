// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa205_00728
// Quest Name: The Trees Have Eyes
// Quest ID: 66264
// Start NPC: 1000594
// End NPC: 1000594

using namespace Sapphire;

class GaiUsa205 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000594;
//    static constexpr auto Enemy0 = 3;
//    static constexpr auto Enemy1 = 23;
//    static constexpr auto Eobject0 = 2002258;
//    static constexpr auto Eobject1 = 2001930;
//    static constexpr auto Eobject2 = 2001931;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000582;
//    static constexpr auto Item1 = 2000583;

  public:
    GaiUsa205() : Sapphire::ScriptAPI::EventScript( 66264 ){}; 
    ~GaiUsa205() = default; 

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
//ENEMY0, UI8BL, 4, -1, False
if( actorId == 3 && player.getQuestUI8BL( getId() ) != 4 ) { Scene00002( player ); }
//ENEMY1, UI8CH, 2, -1, False
if( actorId == 23 && player.getQuestUI8CH( getId() ) != 2 ) { Scene00004( player ); }
break;
}
case 2:{
Scene00007( player );
break;
}
case 3:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002258 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00008( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001930 ) { Scene00009( player ); }
break;
}
case 4:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002258 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00010( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001930 ) { Scene00011( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001931 ) { Scene00012( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1000594 ) { Scene00014( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001930 ) { Scene00015( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001931 ) { Scene00016( player ); }
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
player.setQuestUI8BL( getId(), 4 );
player.setQuestUI8CH( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling NpcTrade:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY0
player.setQuestUI8BL( getId(), 4 );
if( player.getQuestUI8BL( getId() ) == 4 ){
if( player.getQuestUI8CH( getId() ) == 2 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
player.setQuestUI8BL( getId(), 2 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](2)Empty:Scene00003 ENEMY0:UI8BL=-1, 4", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00005( player ); }
 else { Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling NpcTrade:Scene00004 +2 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY1
player.setQuestUI8CH( getId(), 2 );
if( player.getQuestUI8BL( getId() ) == 4 ){
if( player.getQuestUI8CH( getId() ) == 2 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 4 );
player.setQuestUI8BL( getId(), 2 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](4)Empty:Scene00005 ENEMY1:UI8CH=-1, 2", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](4)Empty:Scene00006 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00007 ", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00010 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 EOBJECT1", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 EOBJECT2", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00013 ", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00014 ACTOR0", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00015 EOBJECT1", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00016 EOBJECT2", getId() );


  }

  void Scene00017( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00017 ", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00018 ", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsa205 );
