// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: True, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa308_00740
// Quest Name: Nouveau Riche
// Quest ID: 66276
// Start NPC: 1000590
// End NPC: 1000590

using namespace Sapphire;

class GaiUsa308 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
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
//      Seq5 = 5,
//      Seq6 = 6,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000590;
//    static constexpr auto Actor1 = 1006199;
//    static constexpr auto Actor2 = 1006200;
//    static constexpr auto Actor3 = 1006201;
//    static constexpr auto Actor4 = 1006202;
//    static constexpr auto Actor5 = 1006203;
//    static constexpr auto Enemy0 = 4293402;
//    static constexpr auto Eobject0 = 2001651;
//    static constexpr auto Eobject1 = 2001652;
//    static constexpr auto Eobject2 = 2001653;
//    static constexpr auto Eobject3 = 2001654;
//    static constexpr auto Eobject4 = 2001954;
//    static constexpr auto Eobject5 = 2002271;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Questbattle0 = 13;
//    static constexpr auto Seq0Actor0Lq = 90;
//    static constexpr auto Territorytype0 = 232;

  public:
    GaiUsa308() : Sapphire::ScriptAPI::EventScript( 66276 ){}; 
    ~GaiUsa308() = default; 

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
Scene00002( player );
break;
}
case 2:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1006200 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001651 ) { Scene00004( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001652 ) { Scene00006( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001653 ) { Scene00008( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001654 ) { Scene00010( player ); }
break;
}
case 3:{
//ACTOR3, null, 0, -2, False
if( actor == 1006201 ) { Scene00012( player ); }
//if( actorId == 4293402 && player.getQuestUI8AL( getId() ) != 1 ) { Scene?????( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2001954 ) { Scene00013( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001651 ) { Scene00015( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001652 ) { Scene00017( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001653 ) { Scene00019( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001654 ) { Scene00021( player ); }
break;
}
case 4:{
//ACTOR3, UI8AL, 1, -2, False
if( actor == 1006201 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00023( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2001954 ) { Scene00024( player ); }
break;
}
case 5:{
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1006202 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00026( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2001954 ) { Scene00027( player ); }
break;
}
case 6:{
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR5, UI8AL, 1, -2, False
if( actor == 1006203 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00029( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002271 ) { Scene00030( player ); }
break;
}
case 255:{
Scene00032( player );
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
Scene00090( player );
    };
player.sendDebug( "questId: {}, calling QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2:UI8AL=-2, 1", getId() );

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
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00005 EOBJECT0", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](6)Empty:Scene00007 EOBJECT1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00008 +1 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](8)Empty:Scene00009 EOBJECT2", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00010 +1 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](10)Empty:Scene00011 EOBJECT3", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk, Message:Scene00012 ACTOR3", getId() );

    player.playScene( getId(), 12, NONE, callback );
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


//Target: EOBJECT4
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Empty:Scene00014 EOBJECT4", getId() );


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


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](15)Empty:Scene00016 EOBJECT0", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00018( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00017 +1 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](17)Empty:Scene00018 EOBJECT1", getId() );


  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00020( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00019 +1 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](19)Empty:Scene00020 EOBJECT2", getId() );


  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00022( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00021 +1 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling [sub:BranchTrue](21)Empty:Scene00022 EOBJECT3", getId() );


  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 5 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR3:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00025( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00024 +1 ", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](24)Empty:Scene00025 EOBJECT4", getId() );


  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00028( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00027 +1 ", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](27)Empty:Scene00028 EOBJECT4", getId() );


  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00029 ACTOR5:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00031( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00030 +1 ", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](30)Empty:Scene00031 EOBJECT5", getId() );


  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00032 ", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00090( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00090 ", getId() );

    player.playScene( getId(), 90, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( GaiUsa308 );
