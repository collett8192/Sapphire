// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea110_00407
// Quest Name: A Bridge Too Full
// Quest ID: 65943
// Start NPC: 1002231
// End NPC: 1002231

using namespace Sapphire;

class SubSea110 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1002231;
//    static constexpr auto Actor1 = 1002447;
//    static constexpr auto Actor10 = 1003496;
//    static constexpr auto Actor2 = 1002448;
//    static constexpr auto Actor3 = 1002449;
//    static constexpr auto Actor4 = 1002450;
//    static constexpr auto Actor5 = 1002451;
//    static constexpr auto Actor6 = 1002452;
//    static constexpr auto Actor7 = 1003493;
//    static constexpr auto Actor8 = 1003494;
//    static constexpr auto Actor9 = 1003495;
//    static constexpr auto Eobject0 = 2000756;
//    static constexpr auto EventActionSearch = 1;

  public:
    SubSea110() : Sapphire::ScriptAPI::EventScript( 65943 ){}; 
    ~SubSea110() = default; 

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
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1002447 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00001( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1002448 ) { Scene00002( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1002449 ) { Scene00003( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1002450 ) { Scene00004( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1002451 ) { Scene00005( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1002452 ) { Scene00006( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1003493 ) { Scene00007( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1003494 ) { Scene00008( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1003495 ) { Scene00009( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1003496 ) { Scene00010( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2000756 ) { Scene00011( player ); }
break;
}
case 2:{
//ACTOR3, UI8AL, 2, -2, False
if( actor == 1002449 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00012( player ); }
//ACTOR4, UI8AL, 2, -2, False
if( actor == 1002450 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00013( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1002447 ) { Scene00014( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1002448 ) { Scene00015( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1002451 ) { Scene00016( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1002452 ) { Scene00017( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1003493 ) { Scene00018( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1003494 ) { Scene00019( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1003495 ) { Scene00020( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1003496 ) { Scene00021( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2000756 ) { Scene00022( player ); }
break;
}
case 3:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1002447 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00023( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1002448 ) { Scene00024( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1002449 ) { Scene00025( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1002450 ) { Scene00026( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1002451 ) { Scene00027( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1002452 ) { Scene00028( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1003493 ) { Scene00029( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1003494 ) { Scene00030( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1003495 ) { Scene00031( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1003496 ) { Scene00032( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2000756 ) { Scene00033( player ); }
break;
}
case 255:{
Scene00046( player );
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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00001 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR2", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR3", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR4", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR5", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR6", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR7", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR8", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR9", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR10", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 EOBJECT0", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 2 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR3:UI8AL=-2, 2", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 2 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR4:UI8AL=-2, 2", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR1", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR2", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR5", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR6", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR7", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR8", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR9", getId() );


  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00021 ACTOR10", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 EOBJECT0", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR2", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR3", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00026 ACTOR4", getId() );


  }

  void Scene00027( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00027 ACTOR5", getId() );


  }

  void Scene00028( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00028 ACTOR6", getId() );


  }

  void Scene00029( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00029 ACTOR7", getId() );


  }

  void Scene00030( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00030 ACTOR8", getId() );


  }

  void Scene00031( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00031 ACTOR9", getId() );


  }

  void Scene00032( Entity::Player& player )
  {


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00032 ACTOR10", getId() );


  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 EOBJECT0", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 ", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00035 ", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00036 ", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00037 ", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00038 ", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00039 ", getId() );


  }

  void Scene00040( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00040 ", getId() );


  }

  void Scene00041( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00041 ", getId() );


  }

  void Scene00042( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00042 ", getId() );


  }

  void Scene00043( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00043 ", getId() );


  }

  void Scene00044( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00044 ", getId() );


  }

  void Scene00045( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00045 ", getId() );


  }

  void Scene00046( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00046 ", getId() );

    player.playScene( getId(), 46, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubSea110 );
