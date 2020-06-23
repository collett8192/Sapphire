// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: False, A3: False, S: True, R: False, DM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea159_01426
// Quest Name: Good for What Ales You
// Quest ID: 66962
// Start NPC: 1003505
// End NPC: 1003505

using namespace Sapphire;

class SubSea159 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1003505;
//    static constexpr auto Actor1 = 1007960;
//    static constexpr auto Actor2 = 1007961;
//    static constexpr auto Actor3 = 1007962;
//    static constexpr auto Actor4 = 1007797;
//    static constexpr auto Actor5 = 1007959;
//    static constexpr auto Actor6 = 1007976;
//    static constexpr auto Actor7 = 1007975;
//    static constexpr auto Actor8 = 1007977;
//    static constexpr auto Actor9 = 1007796;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001250;
//    static constexpr auto LocActor0 = 1007978;
//    static constexpr auto LocActor1 = 1007989;
//    static constexpr auto LocActor2 = 1007986;
//    static constexpr auto LocActor3 = 1007987;
//    static constexpr auto LocActor4 = 1007988;
//    static constexpr auto LocBgm = 88;
//    static constexpr auto LocFace0 = 604;
//    static constexpr auto LocFace1 = 608;
//    static constexpr auto LocFace2 = 617;
//    static constexpr auto LocMotion1 = 873;
//    static constexpr auto LocMotion2 = 570;
//    static constexpr auto LocPosActor0 = 4660295;

  public:
    SubSea159() : Sapphire::ScriptAPI::EventScript( 66962 ){}; 
    ~SubSea159() = default; 

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
//ACTOR1, UI8AL, 3, -2, False
if( actor == 1007960 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00002( player ); }
//ACTOR2, UI8AL, 3, -2, False
if( actor == 1007961 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00004( player ); }
//ACTOR3, UI8AL, 3, -2, False
if( actor == 1007962 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00006( player ); }
break;
}
case 2:{
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1007797 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007959 ) { Scene00009( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1007976 ) { Scene00010( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1007975 ) { Scene00011( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007977 ) { Scene00012( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1007796 ) { Scene00013( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007960 ) { Scene00015( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1007961 ) { Scene00017( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007962 ) { Scene00018( player ); }
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
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Talk:Scene00003 ACTOR1:UI8AL=-2, 3", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 +1 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Talk:Scene00005 ACTOR2:UI8AL=-2, 3", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](6)Talk:Scene00007 ACTOR3:UI8AL=-2, 3", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00008 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR5", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR6", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR7", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR8", getId() );


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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Talk:Scene00014 ACTOR9", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00016( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 +1 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](15)Talk:Scene00016 ACTOR1", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00017 ACTOR2", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00018 ACTOR3", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubSea159 );
