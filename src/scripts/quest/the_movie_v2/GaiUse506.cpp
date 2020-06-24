// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse506_00368
// Quest Name: On the Counteroffensive
// Quest ID: 65904
// Start NPC: 1006646
// End NPC: 1006646

using namespace Sapphire;

class GaiUse506 : public Sapphire::ScriptAPI::EventScript
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
//      Seq5 = 5,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006646;
//    static constexpr auto Actor1 = 1010924;
//    static constexpr auto Actor10 = 1010869;
//    static constexpr auto Actor11 = 1010876;
//    static constexpr auto Actor12 = 1010877;
//    static constexpr auto Actor13 = 1010878;
//    static constexpr auto Actor2 = 1011131;
//    static constexpr auto Actor3 = 1010871;
//    static constexpr auto Actor4 = 1010872;
//    static constexpr auto Actor5 = 1010873;
//    static constexpr auto Actor6 = 1010874;
//    static constexpr auto Actor7 = 1010875;
//    static constexpr auto Actor8 = 1010867;
//    static constexpr auto Actor9 = 1010868;
//    static constexpr auto Enemy0 = 5589314;
//    static constexpr auto Enemy1 = 5589315;
//    static constexpr auto Enemy2 = 5589318;
//    static constexpr auto Enemy3 = 5589325;
//    static constexpr auto Enemy4 = 5589332;
//    static constexpr auto Enemy5 = 5654263;
//    static constexpr auto Eobject0 = 2005043;
//    static constexpr auto Eobject1 = 2005044;
//    static constexpr auto Eventrange0 = 5584274;
//    static constexpr auto Eventrange1 = 5584276;
//    static constexpr auto LocActor0 = 1008191;
//    static constexpr auto LocActor1 = 5580235;
//    static constexpr auto LocActor10 = 5580256;
//    static constexpr auto LocActor11 = 5580234;
//    static constexpr auto LocActor2 = 5580219;
//    static constexpr auto LocActor3 = 5580218;
//    static constexpr auto LocActor4 = 5580220;
//    static constexpr auto LocActor5 = 5580221;
//    static constexpr auto LocActor6 = 5580222;
//    static constexpr auto LocActor7 = 5579278;
//    static constexpr auto LocActor8 = 5579279;
//    static constexpr auto LocActor9 = 5580255;
//    static constexpr auto LocMotion0 = 1045;

  public:
    GaiUse506() : Sapphire::ScriptAPI::EventScript( 65904 ){}; 
    ~GaiUse506() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1006646 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010924 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1011131 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1010871 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010872 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010873 ) { Scene00006( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010874 ) { Scene00007( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1010875 ) { Scene00008( player ); }
break;
}
case 1:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1010924 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00009( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006646 ) { Scene00010( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1011131 ) { Scene00011( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1010871 ) { Scene00012( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010872 ) { Scene00013( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010873 ) { Scene00014( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010874 ) { Scene00015( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1010875 ) { Scene00016( player ); }
break;
}
case 2:{
//ACTOR8, UI8AL, 1, -2, False
if( actor == 1010867 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00017( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1010868 ) { Scene00018( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1010869 ) { Scene00019( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006646 ) { Scene00020( player ); }
break;
}
case 3:{
//EOBJECT0, null, 0, -2, False
if( actor == 2005043 ) { Scene00021( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006646 ) { Scene00022( player ); }
break;
}
case 4:{
//EOBJECT1, null, 0, -2, False
if( actor == 2005044 ) { Scene00023( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006646 ) { Scene00024( player ); }
break;
}
case 5:{
//ACTOR11, UI8AL, 1, -2, False
if( actor == 1010876 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00025( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1010877 ) { Scene00026( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1010878 ) { Scene00027( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006646 ) { Scene00028( player ); }
break;
}
case 255:{
Scene00037( player );
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR4", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR5", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR6", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR7", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
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
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00009 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR0", getId() );

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
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR4", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR5", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR6", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR7", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR8:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR9", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR10", getId() );


  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR0", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00021 EOBJECT0", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR0", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00023 EOBJECT1", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00024 ACTOR0", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR11
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR11:UI8AL=-2, 1", getId() );


  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR12", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00027 ACTOR13", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {


//Target: ACTOR0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00028 ACTOR0", getId() );


  }

  void Scene00029( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00029 ", getId() );


  }

  void Scene00030( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00030 ", getId() );


  }

  void Scene00031( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00031 ", getId() );


  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00034 ", getId() );


  }

  void Scene00035( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00035 ", getId() );


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
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00037 ", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse506 );
