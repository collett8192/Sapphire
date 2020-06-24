// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse303_01444
// Quest Name: Shock and Awe
// Quest ID: 66980
// Start NPC: 1009049
// End NPC: 1004576

using namespace Sapphire;

class GaiUse303 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1009049;
//    static constexpr auto Actor1 = 1009050;
//    static constexpr auto Actor2 = 1009051;
//    static constexpr auto Actor3 = 1009052;
//    static constexpr auto Actor4 = 1009053;
//    static constexpr auto Actor5 = 1009054;
//    static constexpr auto Actor6 = 1009055;
//    static constexpr auto Actor7 = 1004576;
//    static constexpr auto Enemy0 = 4841637;
//    static constexpr auto Enemy1 = 4841638;
//    static constexpr auto Enemy2 = 4841640;
//    static constexpr auto Enemy3 = 4841641;
//    static constexpr auto Enemy4 = 4841642;
//    static constexpr auto Enemy5 = 4841643;
//    static constexpr auto Enemy6 = 4841644;
//    static constexpr auto EventActionSearch = 1;

  public:
    GaiUse303() : Sapphire::ScriptAPI::EventScript( 66980 ){}; 
    ~GaiUse303() = default; 

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
//ACTOR1, null, 0, -2, False
if( actor == 1009050 ) { Scene00002( player ); }
//if( actorId == 4841637 && player.getQuestUI8AL( getId() ) != 7 ) { Scene?????( player ); }
//if( actorId == 4841638 && player.getQuestUI8AL( getId() ) != 7 ) { Scene?????( player ); }
//if( actorId == 4841640 && player.getQuestUI8AL( getId() ) != 7 ) { Scene?????( player ); }
//if( actorId == 4841641 && player.getQuestUI8AL( getId() ) != 7 ) { Scene?????( player ); }
//if( actorId == 4841642 && player.getQuestUI8AL( getId() ) != 7 ) { Scene?????( player ); }
//if( actorId == 4841643 && player.getQuestUI8AL( getId() ) != 7 ) { Scene?????( player ); }
//if( actorId == 4841644 && player.getQuestUI8AL( getId() ) != 7 ) { Scene?????( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1009049 ) { Scene00003( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009051 ) { Scene00005( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009052 ) { Scene00007( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009053 ) { Scene00009( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009054 ) { Scene00011( player ); }
break;
}
case 2:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1009050 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00013( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1009049 ) { Scene00015( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009051 ) { Scene00016( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009052 ) { Scene00017( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009053 ) { Scene00018( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009054 ) { Scene00019( player ); }
break;
}
case 3:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1009049 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00020( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009050 ) { Scene00022( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009051 ) { Scene00023( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009052 ) { Scene00024( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009053 ) { Scene00025( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009054 ) { Scene00026( player ); }
break;
}
case 4:{
Scene00027( player );
break;
}
case 255:{
//ACTOR7, null, 0, -2, False
if( actor == 1004576 ) { Scene00028( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009055 ) { Scene00029( player ); }
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
//      case Enemy2: { break; }
//      case Enemy3: { break; }
//      case Enemy4: { break; }
//      case Enemy5: { break; }
//      case Enemy6: { break; }
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
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk, Message:Scene00002 ACTOR1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00003 +1 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](3)Message:Scene00004 ACTOR0", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](5)Message:Scene00006 ACTOR2", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](7)Message:Scene00008 ACTOR3", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Message:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](9)Talk:Scene00010 ACTOR4", getId() );

    player.playScene( getId(), 10, NONE, callback );
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


//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 2 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](11)Empty:Scene00012 ACTOR5", getId() );


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


//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Empty:Scene00014 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR0", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR2", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR3", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR4", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR5", getId() );


  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00021( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00020 +1 ", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](20)Talk:Scene00021 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR1", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR2", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00024 ACTOR3", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR4", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00026 ACTOR5", getId() );


  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00028 ACTOR7", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ACTOR6", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse303 );
