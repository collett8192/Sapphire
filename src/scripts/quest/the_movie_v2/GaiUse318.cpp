// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse318_01459
// Quest Name: When the Cold Sets In
// Quest ID: 66995
// Start NPC: 1006384
// End NPC: 1006530

using namespace Sapphire;

class GaiUse318 : public Sapphire::ScriptAPI::EventScript
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
//      Seq6 = 6,
//      Seq7 = 7,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006384;
//    static constexpr auto Actor1 = 1006444;
//    static constexpr auto Actor10 = 1009087;
//    static constexpr auto Actor11 = 1009088;
//    static constexpr auto Actor12 = 1006530;
//    static constexpr auto Actor2 = 1009081;
//    static constexpr auto Actor3 = 1009082;
//    static constexpr auto Actor4 = 1009083;
//    static constexpr auto Actor5 = 1009084;
//    static constexpr auto Actor6 = 1009085;
//    static constexpr auto Actor7 = 1009086;
//    static constexpr auto Actor8 = 1006481;
//    static constexpr auto Actor9 = 1006480;
//    static constexpr auto CutSceneN01 = 530;
//    static constexpr auto CutSceneN02 = 531;
//    static constexpr auto CutSceneN03 = 532;
//    static constexpr auto Enemy0 = 4867904;
//    static constexpr auto Enemy1 = 4867905;
//    static constexpr auto Eobject0 = 2004151;
//    static constexpr auto Eventrange0 = 4867918;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto QstCompChk01 = 67061;

  public:
    GaiUse318() : Sapphire::ScriptAPI::EventScript( 66995 ){}; 
    ~GaiUse318() = default; 

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
if( actor == 1006444 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006384 ) { Scene00003( player ); }
break;
}
case 2:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1009081 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006444 ) { Scene00005( player ); }
break;
}
case 3:{
//ACTOR3, null, 0, -2, False
if( actor == 1009082 ) { Scene00006( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009083 ) { Scene00008( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009084 ) { Scene00009( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009085 ) { Scene00010( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009086 ) { Scene00011( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004151 ) { Scene00012( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1006481 ) { Scene00013( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1006480 ) { Scene00014( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009081 ) { Scene00015( player ); }
break;
}
case 4:{
//ACTOR10, UI8AL, 1, -2, False
if( actor == 1009087 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00016( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009082 ) { Scene00017( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009083 ) { Scene00018( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009084 ) { Scene00020( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009085 ) { Scene00021( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009086 ) { Scene00022( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1006481 ) { Scene00023( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1006480 ) { Scene00024( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1009088 ) { Scene00025( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009081 ) { Scene00026( player ); }
break;
}
case 5:{
//ACTOR10, UI8AL, 1, -2, False
if( actor == 1009087 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00027( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009082 ) { Scene00028( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009083 ) { Scene00029( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009084 ) { Scene00030( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009085 ) { Scene00031( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009086 ) { Scene00032( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1006481 ) { Scene00033( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1006480 ) { Scene00034( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1009088 ) { Scene00035( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009081 ) { Scene00036( player ); }
break;
}
case 6:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1006444 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00037( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009082 ) { Scene00038( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1009083 ) { Scene00039( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009084 ) { Scene00040( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009085 ) { Scene00041( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009086 ) { Scene00042( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1006481 ) { Scene00043( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1006480 ) { Scene00044( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1009087 ) { Scene00045( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1009088 ) { Scene00046( player ); }
break;
}
case 7:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1006384 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00047( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006444 ) { Scene00048( player ); }
break;
}
case 255:{
//ACTOR12, null, 0, -2, False
if( actor == 1006530 ) { Scene00051( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006384 ) { Scene00052( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept, CutScene, FadeOut:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](6)Empty:Scene00007 ACTOR3", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR4", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR5", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR6", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR7", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00012 EOBJECT0", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR8
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR8", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR9
//no valid quest var detected
player.updateQuest( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR9", getId() );


  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR2", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 5 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR10:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR3", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00019( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 +1 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](18)CutScene, FadeOut:Scene00019 ACTOR4", getId() );

    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR5", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00021 ACTOR6", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR7", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR8", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00024 ACTOR9", getId() );


  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR11", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR2", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {


//Target: ACTOR10
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00027 ACTOR10:UI8AL=-2, 1", getId() );


  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00028 ACTOR3", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ACTOR4", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00030 ACTOR5", getId() );


  }

  void Scene00031( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00031 ACTOR6", getId() );


  }

  void Scene00032( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00032 ACTOR7", getId() );


  }

  void Scene00033( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00033 ACTOR8", getId() );


  }

  void Scene00034( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00034 ACTOR9", getId() );


  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00035 ACTOR11", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00036 ACTOR2", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {


//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 7 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00037 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00038 ACTOR3", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00039 ACTOR4", getId() );

    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00040 ACTOR5", getId() );


  }

  void Scene00041( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00041 ACTOR6", getId() );


  }

  void Scene00042( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00042 ACTOR7", getId() );


  }

  void Scene00043( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00043 ACTOR8", getId() );


  }

  void Scene00044( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00044 ACTOR9", getId() );


  }

  void Scene00045( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00045 ACTOR10", getId() );

    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00046 ACTOR11", getId() );

    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00047 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00049( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00048 +1 ", getId() );

    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](48)CutScene, FadeOut:Scene00049 ACTOR1", getId() );

    player.playScene( getId(), 49, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00050 ", getId() );

    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00051 ACTOR12", getId() );

    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00052 ACTOR0", getId() );

    player.playScene( getId(), 52, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse318 );
