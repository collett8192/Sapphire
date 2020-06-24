// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa407_00749
// Quest Name: Strawman Defense
// Quest ID: 66285
// Start NPC: 1006207
// End NPC: 1006207

using namespace Sapphire;

class GaiUsa407 : public Sapphire::ScriptAPI::EventScript
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

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006207;
//    static constexpr auto Eobject0 = 2001960;
//    static constexpr auto Eobject1 = 2001961;
//    static constexpr auto Eobject2 = 2001962;
//    static constexpr auto Eobject3 = 2001963;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000599;

  public:
    GaiUsa407() : Sapphire::ScriptAPI::EventScript( 66285 ){}; 
    ~GaiUsa407() = default; 

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
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2001960 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//EOBJECT1, UI8BH, 1, -2, False
if( actor == 2001961 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00004( player ); }
//EOBJECT2, UI8BL, 1, -2, False
if( actor == 2001962 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00006( player ); }
//EOBJECT3, UI8CH, 1, -2, False
if( actor == 2001963 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00008( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006207 ) { Scene00010( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001960 ) { Scene00011( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001961 ) { Scene00012( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001962 ) { Scene00013( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001963 ) { Scene00014( player ); }
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
player.setQuestUI8CL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Empty:Scene00003 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00004 +1 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00005 EOBJECT1:UI8BH=-2, 1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](6)Empty:Scene00007 EOBJECT2:UI8BL=-2, 1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00008 +1 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8CH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](8)Empty:Scene00009 EOBJECT3:UI8CH=-2, 1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00010 ACTOR0", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00011 EOBJECT0", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00012 EOBJECT1", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00013 EOBJECT2", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00014 EOBJECT3", getId() );


  }

  void Scene00015( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00015 ", getId() );


  }

  void Scene00016( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00016 ", getId() );


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

EXPOSE_SCRIPT( GaiUsa407 );
