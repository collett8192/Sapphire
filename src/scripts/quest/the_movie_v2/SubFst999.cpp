// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst999_01437
// Quest Name: The Greatest Story Never Told
// Quest ID: 66973
// Start NPC: 1008961
// End NPC: 2004136

using namespace Sapphire;

class SubFst999 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
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
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      Seq5 = 5,
//      Seq6 = 6,
//      Seq7 = 7,
//      Seq8 = 8,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008961;
//    static constexpr auto Actor1 = 1008962;
//    static constexpr auto Actor10 = 1001217;
//    static constexpr auto Actor2 = 1008963;
//    static constexpr auto Actor3 = 1008964;
//    static constexpr auto Actor4 = 1001294;
//    static constexpr auto Actor5 = 1002768;
//    static constexpr auto Actor6 = 1003556;
//    static constexpr auto Actor7 = 1001474;
//    static constexpr auto Actor8 = 1003908;
//    static constexpr auto Actor9 = 1000768;
//    static constexpr auto Eobject0 = 2004132;
//    static constexpr auto Eobject1 = 2004113;
//    static constexpr auto Eobject10 = 2004120;
//    static constexpr auto Eobject11 = 2004121;
//    static constexpr auto Eobject12 = 2004122;
//    static constexpr auto Eobject13 = 2004123;
//    static constexpr auto Eobject14 = 2004124;
//    static constexpr auto Eobject15 = 2004125;
//    static constexpr auto Eobject16 = 2004126;
//    static constexpr auto Eobject17 = 2004127;
//    static constexpr auto Eobject18 = 2004128;
//    static constexpr auto Eobject19 = 2004153;
//    static constexpr auto Eobject2 = 2004109;
//    static constexpr auto Eobject20 = 2004133;
//    static constexpr auto Eobject21 = 2004134;
//    static constexpr auto Eobject22 = 2004136;
//    static constexpr auto Eobject3 = 2004107;
//    static constexpr auto Eobject4 = 2004110;
//    static constexpr auto Eobject5 = 2004111;
//    static constexpr auto Eobject6 = 2004112;
//    static constexpr auto Eobject7 = 2004108;
//    static constexpr auto Eobject8 = 2004114;
//    static constexpr auto Eobject9 = 2004115;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionSearchMiddle = 3;
//    static constexpr auto Item0 = 2001307;
//    static constexpr auto ItemNoBrace01 = 4109;
//    static constexpr auto ItemNoBrace02 = 4113;
//    static constexpr auto ItemNoBrace03 = 4117;
//    static constexpr auto ItemNoEar01 = 4214;
//    static constexpr auto ItemNoEar02 = 4218;
//    static constexpr auto ItemNoEar03 = 4222;
//    static constexpr auto ItemNoNek01 = 4305;
//    static constexpr auto ItemNoRing01 = 4442;
//    static constexpr auto ItemNoRing02 = 4446;
//    static constexpr auto ItemNoRing03 = 4450;
//    static constexpr auto LocEnpc01 = 1008965;
//    static constexpr auto LocPosActor1 = 4721965;

  public:
    SubFst999() : Sapphire::ScriptAPI::EventScript( 66973 ){}; 
    ~SubFst999() = default; 

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
if( actor == 1008962 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008963 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008964 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1001294 ) { Scene00005( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008961 ) { Scene00006( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004132 ) { Scene00007( player ); }
break;
}
case 2:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1008961 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00008( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004132 ) { Scene00009( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008962 ) { Scene00010( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008963 ) { Scene00011( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008964 ) { Scene00012( player ); }
break;
}
case 3:{
//EOBJECT1, null, 0, -2, False
if( actor == 2004113 ) { Scene00013( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2004109 ) { Scene00014( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2004107 ) { Scene00015( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2004110 ) { Scene00016( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2004111 ) { Scene00017( player ); }
//EOBJECT6, null, 0, -2, False
if( actor == 2004112 ) { Scene00018( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2004108 ) { Scene00019( player ); }
//EOBJECT8, null, 0, -2, False
if( actor == 2004114 ) { Scene00020( player ); }
//EOBJECT9, null, 0, -2, False
if( actor == 2004115 ) { Scene00021( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1002768 ) { Scene00022( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1003556 ) { Scene00023( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1001474 ) { Scene00024( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004132 ) { Scene00025( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008961 ) { Scene00026( player ); }
break;
}
case 4:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1008961 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00027( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004132 ) { Scene00028( player ); }
break;
}
case 5:{
//EOBJECT10, null, 0, -2, False
if( actor == 2004120 ) { Scene00029( player ); }
//EOBJECT11, null, 0, -2, False
if( actor == 2004121 ) { Scene00030( player ); }
//EOBJECT12, null, 0, -2, False
if( actor == 2004122 ) { Scene00031( player ); }
//EOBJECT13, null, 0, -2, False
if( actor == 2004123 ) { Scene00032( player ); }
//EOBJECT14, null, 0, -2, False
if( actor == 2004124 ) { Scene00033( player ); }
//EOBJECT15, null, 0, -2, False
if( actor == 2004125 ) { Scene00034( player ); }
//EOBJECT16, null, 0, -2, False
if( actor == 2004126 ) { Scene00035( player ); }
//EOBJECT17, null, 0, -2, False
if( actor == 2004127 ) { Scene00036( player ); }
//EOBJECT18, null, 0, -2, False
if( actor == 2004128 ) { Scene00037( player ); }
//EOBJECT19, null, 0, -2, False
if( actor == 2004153 ) { Scene00038( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004132 ) { Scene00039( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008961 ) { Scene00040( player ); }
break;
}
case 6:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1008961 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00041( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004132 ) { Scene00042( player ); }
break;
}
case 7:{
//EOBJECT0, UI8BL, 1, -2, False
if( actor == 2004132 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00043( player ); }
//EOBJECT20, UI8AL, 1, -2, False
if( actor == 2004133 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00044( player ); }
//EOBJECT21, UI8BH, 1, -2, False
if( actor == 2004134 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00045( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1003908 ) { Scene00046( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1000768 ) { Scene00047( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1001217 ) { Scene00048( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008961 ) { Scene00049( player ); }
break;
}
case 8:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1008961 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00050( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004132 ) { Scene00051( player ); }
break;
}
case 255:{
//EOBJECT22, null, 0, -2, False
if( actor == 2004136 ) { Scene00071( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004132 ) { Scene00072( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1008961 ) { Scene00073( player ); }
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
if( result.param2 == 1 ){
player.updateQuest( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, YesNo:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR4", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR0", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 EOBJECT0", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8CH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00009 EOBJECT0", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR1", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR2", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR3", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00013 EOBJECT1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 EOBJECT2", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00015 EOBJECT3", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT4
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 EOBJECT4", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT5
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00017 EOBJECT5", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT6
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 EOBJECT6", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT7
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00019 EOBJECT7", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT8
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 EOBJECT8", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT9
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00021 EOBJECT9", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR5", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00023 ACTOR6", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR7", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00025 EOBJECT0", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR0", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 5 );
player.setQuestUI8CH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00027 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00028 EOBJECT0", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT10
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00029 EOBJECT10", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT11
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 EOBJECT11", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT12
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 EOBJECT12", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT13
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 EOBJECT13", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT14
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 EOBJECT14", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT15
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 EOBJECT15", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT16
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00035 EOBJECT16", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT17
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00036 EOBJECT17", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT18
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00037 EOBJECT18", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT19
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00038 EOBJECT19", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00039 EOBJECT0", getId() );

    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00040 ACTOR0", getId() );

    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 7 );
player.setQuestUI8CH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00041 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00042 EOBJECT0", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 8 );
player.setQuestUI8BH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00043 EOBJECT0:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT20
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 8 );
player.setQuestUI8BH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00044 EOBJECT20:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT21
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 8 );
player.setQuestUI8BH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00045 EOBJECT21:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00046 ACTOR8", getId() );

    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00047 ACTOR9", getId() );

    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00048 ACTOR10", getId() );

    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00049 ACTOR0", getId() );

    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00050 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00051 EOBJECT0", getId() );

    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00052 ", getId() );

    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00053 ", getId() );

    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00054 ", getId() );

    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00055 ", getId() );

    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00056 ", getId() );

    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00057 ", getId() );

    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00058 ", getId() );

    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00059 ", getId() );

    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00060 ", getId() );

    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00061 ", getId() );

    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00062 ", getId() );

    player.playScene( getId(), 62, NONE, callback );
  }

  void Scene00063( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00063 ", getId() );

    player.playScene( getId(), 63, NONE, callback );
  }

  void Scene00064( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00064 ", getId() );

    player.playScene( getId(), 64, NONE, callback );
  }

  void Scene00065( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00065 ", getId() );

    player.playScene( getId(), 65, NONE, callback );
  }

  void Scene00066( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00066 ", getId() );

    player.playScene( getId(), 66, NONE, callback );
  }

  void Scene00067( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00067 ", getId() );

    player.playScene( getId(), 67, NONE, callback );
  }

  void Scene00068( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00068 ", getId() );

    player.playScene( getId(), 68, NONE, callback );
  }

  void Scene00069( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00069 ", getId() );

    player.playScene( getId(), 69, NONE, callback );
  }

  void Scene00070( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00070 ", getId() );

    player.playScene( getId(), 70, NONE, callback );
  }

  void Scene00071( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT22
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00071 EOBJECT22", getId() );

    player.playScene( getId(), 71, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00072( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00072 EOBJECT0", getId() );

    player.playScene( getId(), 72, NONE, callback );
  }

  void Scene00073( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00073 ACTOR0", getId() );

    player.playScene( getId(), 73, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubFst999 );
