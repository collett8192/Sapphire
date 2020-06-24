// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst159_01425
// Quest Name: Saw That One Coming
// Quest ID: 66961
// Start NPC: 1000375
// End NPC: 1007792

using namespace Sapphire;

class SubFst159 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1000375;
//    static constexpr auto Actor1 = 1007792;
//    static constexpr auto Actor2 = 1000153;
//    static constexpr auto Actor3 = 1007793;
//    static constexpr auto Actor4 = 1007794;
//    static constexpr auto Actor5 = 1007795;
//    static constexpr auto Actor6 = 1007969;
//    static constexpr auto Actor7 = 1007970;
//    static constexpr auto Actor8 = 1007971;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001249;
//    static constexpr auto LocActor0 = 1007990;
//    static constexpr auto LocActor1 = 1007991;
//    static constexpr auto LocActor2 = 1007992;
//    static constexpr auto LocActor3 = 1000153;
//    static constexpr auto LocBgm = 88;
//    static constexpr auto LocBgm2 = 87;
//    static constexpr auto LocFace0 = 604;
//    static constexpr auto LocFace1 = 605;
//    static constexpr auto LocFace2 = 614;
//    static constexpr auto LocMotion1 = 571;
//    static constexpr auto LocMotion2 = 572;
//    static constexpr auto LocPosActor0 = 4666289;
//    static constexpr auto LocPosActor1 = 4666740;
//    static constexpr auto Quest0 = 65741;

  public:
    SubFst159() : Sapphire::ScriptAPI::EventScript( 66961 ){}; 
    ~SubFst159() = default; 

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
if( actor == 1000153 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007792 ) { Scene00004( player ); }
break;
}
case 3:{
//ACTOR3, UI8AL, 3, -1, False
if( actor == 1007793 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00005( player ); }
//ACTOR4, UI8AL, 3, -1, False
if( actor == 1007794 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00008( player ); }
//ACTOR5, UI8AL, 3, -1, False
if( actor == 1007795 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00011( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1007792 ) { Scene00014( player ); }
break;
}
case 255:{
//ACTOR1, null, 0, -2, False
if( actor == 1007792 ) { Scene00015( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1007969 ) { Scene00016( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1007970 ) { Scene00017( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007971 ) { Scene00018( player ); }
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
player.sendDebug( "questId: {}, calling Talk, QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
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
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00006( player ); }
 else { Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00005 +2 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8AL( getId(), 3 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](5)Talk:Scene00006 ACTOR3:UI8AL=-1, 3", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](5)Empty:Scene00007 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00009( player ); }
 else { Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00008 +2 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), 3 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](8)Talk:Scene00009 ACTOR4:UI8AL=-1, 3", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](8)Empty:Scene00010 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00012( player ); }
 else { Scene00013( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00011 +2 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8AL( getId(), 3 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](11)Talk:Scene00012 ACTOR5:UI8AL=-1, 3", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](11)Empty:Scene00013 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
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
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00015 ACTOR1", getId() );

    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR6", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR7
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR7", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR8
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR8", getId() );


  }

};

EXPOSE_SCRIPT( SubFst159 );
