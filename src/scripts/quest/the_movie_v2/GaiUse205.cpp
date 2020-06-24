// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: True, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse205_01349
// Quest Name: A Small-scale Operation
// Quest ID: 66885
// Start NPC: 1008623
// End NPC: 1008626

using namespace Sapphire;

class GaiUse205 : public Sapphire::ScriptAPI::EventScript
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
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008623;
//    static constexpr auto Actor1 = 1008626;
//    static constexpr auto Eobject0 = 2003564;
//    static constexpr auto Eobject1 = 2003565;
//    static constexpr auto Eobject2 = 2003566;
//    static constexpr auto Eobject3 = 2003567;
//    static constexpr auto Eobject4 = 2003568;
//    static constexpr auto EventActionProcessLong = 17;
//    static constexpr auto EventActionProcessMiddle = 16;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001206;
//    static constexpr auto Item1 = 2001207;

  public:
    GaiUse205() : Sapphire::ScriptAPI::EventScript( 66885 ){}; 
    ~GaiUse205() = default; 

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
if( actor == 1008626 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008623 ) { Scene00003( player ); }
break;
}
case 2:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2003564 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008626 ) { Scene00006( player ); }
break;
}
case 3:{
Scene00007( player );
break;
}
case 4:{
//EOBJECT1, UI8AL, 4, -2, False
if( actor == 2003565 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00009( player ); }
//EOBJECT2, UI8AL, 4, -2, False
if( actor == 2003566 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00011( player ); }
//EOBJECT3, UI8AL, 4, -2, False
if( actor == 2003567 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00013( player ); }
//EOBJECT4, UI8AL, 4, -2, False
if( actor == 2003568 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00015( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008626 ) { Scene00017( player ); }
break;
}
case 255:{
Scene00018( player );
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
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR0", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00004 +1 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00005 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR1", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](7)Talk:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](9)Empty:Scene00010 EOBJECT1:UI8AL=-2, 4", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00011 +1 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](11)Empty:Scene00012 EOBJECT2:UI8AL=-2, 4", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00014( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00013 +1 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Empty:Scene00014 EOBJECT3:UI8AL=-2, 4", getId() );


  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00016( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00015 +1 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](15)Empty:Scene00016 EOBJECT4:UI8AL=-2, 4", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR1", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00019( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00018 +1 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](18)Talk, QuestReward, QuestComplete:Scene00019 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse205 );
