// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse503_00365
// Quest Name: Best Laid Schemes
// Quest ID: 65901
// Start NPC: 1010849
// End NPC: 1010891

using namespace Sapphire;

class GaiUse503 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1010849;
//    static constexpr auto Actor1 = 1010848;
//    static constexpr auto Actor10 = 1008969;
//    static constexpr auto Actor2 = 1010850;
//    static constexpr auto Actor3 = 1010851;
//    static constexpr auto Actor4 = 1010852;
//    static constexpr auto Actor5 = 1010853;
//    static constexpr auto Actor6 = 1010891;
//    static constexpr auto Actor7 = 1010855;
//    static constexpr auto Actor8 = 1011122;
//    static constexpr auto Actor9 = 1011123;
//    static constexpr auto Eobject0 = 2005114;
//    static constexpr auto Eobject1 = 2005113;
//    static constexpr auto EventActionSearchShort = 2;
//    static constexpr auto Item0 = 2001498;
//    static constexpr auto LocActor0 = 5578499;
//    static constexpr auto LocActor1 = 5578500;
//    static constexpr auto LocActor2 = 1010404;
//    static constexpr auto LocActor3 = 1010854;
//    static constexpr auto LocActor4 = 5578497;
//    static constexpr auto LocActor5 = 5578845;
//    static constexpr auto LocEobject0 = 2005125;
//    static constexpr auto LocFacial0 = 617;
//    static constexpr auto LocMotion0 = 1002;
//    static constexpr auto LocMotion1 = 708;
//    static constexpr auto LocMotion2 = 707;
//    static constexpr auto LocMotion3 = 1045;
//    static constexpr auto LocMotion4 = 731;
//    static constexpr auto LocSe0 = 42;
//    static constexpr auto LocSeBoxGet = 78;
//    static constexpr auto LocSeBoxSet = 80;
//    static constexpr auto LocTalkshape0 = 6;

  public:
    GaiUse503() : Sapphire::ScriptAPI::EventScript( 65901 ){}; 
    ~GaiUse503() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1010849 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010848 ) { Scene00002( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2005114 ) { Scene00003( player ); }
break;
}
case 1:{
//EOBJECT1, UI8AL, 1, -2, False
if( actor == 2005113 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2005114 ) { Scene00005( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1010849 ) { Scene00006( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010848 ) { Scene00007( player ); }
break;
}
case 2:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1010850 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1010851 ) { Scene00009( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010852 ) { Scene00012( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010848 ) { Scene00013( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1010849 ) { Scene00014( player ); }
break;
}
case 3:{
Scene00015( player );
break;
}
case 255:{
//ACTOR6, null, 0, -2, False
if( actor == 1010891 ) { Scene00016( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1010855 ) { Scene00017( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1011122 ) { Scene00018( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1011123 ) { Scene00019( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1008969 ) { Scene00020( player ); }
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
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00002 ACTOR1", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT0", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT1:UI8AL=-2, 1", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT0", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR0", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR1", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR2:UI8AL=-2, 1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00010( player ); }
 else { Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00009 +2 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:Execute](9)Talk, FadeOut:Scene00010 ACTOR3", getId() );

    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](9)Talk:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR4", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR1", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR0", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00015 ", getId() );

    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00016 ACTOR6", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR7", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR8", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR9", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR10", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse503 );
