// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse606_00418
// Quest Name: An Allied Perspective
// Quest ID: 65954
// Start NPC: 1010961
// End NPC: 1006454

using namespace Sapphire;

class GaiUse606 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto ActionTimelineEventLink = 1002;
//    static constexpr auto Actor0 = 1010961;
//    static constexpr auto Actor1 = 1009057;
//    static constexpr auto Actor10 = 1010974;
//    static constexpr auto Actor11 = 1010975;
//    static constexpr auto Actor12 = 1010976;
//    static constexpr auto Actor13 = 1010969;
//    static constexpr auto Actor14 = 1010962;
//    static constexpr auto Actor15 = 1010963;
//    static constexpr auto Actor16 = 1010964;
//    static constexpr auto Actor17 = 1010965;
//    static constexpr auto Actor18 = 1010966;
//    static constexpr auto Actor19 = 1010967;
//    static constexpr auto Actor2 = 1001821;
//    static constexpr auto Actor20 = 1010968;
//    static constexpr auto Actor3 = 1006454;
//    static constexpr auto Actor4 = 1010977;
//    static constexpr auto Actor5 = 1011624;
//    static constexpr auto Actor6 = 1010970;
//    static constexpr auto Actor7 = 1010971;
//    static constexpr auto Actor8 = 1010972;
//    static constexpr auto Actor9 = 1010973;
//    static constexpr auto CutSceneN01 = 709;
//    static constexpr auto Enemy0 = 5607264;
//    static constexpr auto Enemy1 = 5607265;
//    static constexpr auto Enemy10 = 5607216;
//    static constexpr auto Enemy11 = 5607217;
//    static constexpr auto Enemy2 = 5607266;
//    static constexpr auto Enemy3 = 5607269;
//    static constexpr auto Enemy4 = 5607271;
//    static constexpr auto Enemy5 = 5607272;
//    static constexpr auto Enemy6 = 5607212;
//    static constexpr auto Enemy7 = 5607213;
//    static constexpr auto Enemy8 = 5607214;
//    static constexpr auto Enemy9 = 5607215;
//    static constexpr auto Eobject0 = 2005062;
//    static constexpr auto Eobject1 = 2005061;
//    static constexpr auto Eventrange0 = 5607357;
//    static constexpr auto Eventrange1 = 5607356;
//    static constexpr auto LocSe01 = 42;

  public:
    GaiUse606() : Sapphire::ScriptAPI::EventScript( 65954 ){}; 
    ~GaiUse606() = default; 

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
if( actor == 1009057 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1010961 ) { Scene00004( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1001821 ) { Scene00005( player ); }
break;
}
case 2:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1009057 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00006( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1001821 ) { Scene00007( player ); }
break;
}
case 3:{
//ACTOR3, UI8AL, 1, -2, False
if( actor == 1006454 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009057 ) { Scene00009( player ); }
break;
}
case 4:{
//EOBJECT0, null, 0, -2, False
if( actor == 2005062 ) { Scene00010( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010977 ) { Scene00011( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1011624 ) { Scene00012( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010970 ) { Scene00013( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1010971 ) { Scene00014( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1010972 ) { Scene00015( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1010973 ) { Scene00016( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1010974 ) { Scene00017( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1010975 ) { Scene00018( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1010976 ) { Scene00019( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006454 ) { Scene00020( player ); }
break;
}
case 5:{
//EOBJECT1, null, 0, -2, False
if( actor == 2005061 ) { Scene00021( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1010969 ) { Scene00022( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1010962 ) { Scene00023( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1010963 ) { Scene00024( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1010964 ) { Scene00025( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1010965 ) { Scene00026( player ); }
//ACTOR18, null, 0, -2, False
if( actor == 1010966 ) { Scene00027( player ); }
//ACTOR19, null, 0, -2, False
if( actor == 1010967 ) { Scene00028( player ); }
//ACTOR20, null, 0, -2, False
if( actor == 1010968 ) { Scene00029( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010970 ) { Scene00030( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1010971 ) { Scene00031( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1010972 ) { Scene00032( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1010973 ) { Scene00033( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1010974 ) { Scene00034( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1010975 ) { Scene00035( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1010976 ) { Scene00036( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006454 ) { Scene00037( player ); }
break;
}
case 255:{
//ACTOR3, null, 0, -2, False
if( actor == 1006454 ) { Scene00052( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1010962 ) { Scene00053( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1010963 ) { Scene00054( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1010964 ) { Scene00055( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1010965 ) { Scene00056( player ); }
//ACTOR18, null, 0, -2, False
if( actor == 1010966 ) { Scene00057( player ); }
//ACTOR19, null, 0, -2, False
if( actor == 1010967 ) { Scene00058( player ); }
//ACTOR20, null, 0, -2, False
if( actor == 1010968 ) { Scene00059( player ); }
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
//      case Enemy7: { break; }
//      case Enemy8: { break; }
//      case Enemy9: { break; }
//      case Enemy10: { break; }
//      case Enemy11: { break; }
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
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](2)CutScene:Scene00003 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR0", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR2", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00006 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR2", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR3:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00010 EOBJECT0", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR4", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR5", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR6", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR7", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR8
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR8", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: ACTOR9
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR9", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR10
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR10", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR11
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR11", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR12
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR12", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR3", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00021 EOBJECT1", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR13
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR13", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR14
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR14", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR15
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00024 ACTOR15", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR16
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR16", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR17
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00026 ACTOR17", getId() );


  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR18
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR18", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR19
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00028 ACTOR19", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {


//Target: ACTOR20
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00029 ACTOR20", getId() );


  }

  void Scene00030( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00030 ACTOR6", getId() );


  }

  void Scene00031( Entity::Player& player )
  {


//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00031 ACTOR7", getId() );


  }

  void Scene00032( Entity::Player& player )
  {


//Target: ACTOR8
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00032 ACTOR8", getId() );


  }

  void Scene00033( Entity::Player& player )
  {


//Target: ACTOR9
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00033 ACTOR9", getId() );


  }

  void Scene00034( Entity::Player& player )
  {


//Target: ACTOR10
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00034 ACTOR10", getId() );


  }

  void Scene00035( Entity::Player& player )
  {


//Target: ACTOR11
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00035 ACTOR11", getId() );


  }

  void Scene00036( Entity::Player& player )
  {


//Target: ACTOR12
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00036 ACTOR12", getId() );


  }

  void Scene00037( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00037 ACTOR3", getId() );


  }

  void Scene00038( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00038 ", getId() );


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


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00046 ", getId() );


  }

  void Scene00047( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00047 ", getId() );


  }

  void Scene00048( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00048 ", getId() );


  }

  void Scene00049( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00049 ", getId() );


  }

  void Scene00050( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00050 ", getId() );


  }

  void Scene00051( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00051 ", getId() );

    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00052 ACTOR3", getId() );

    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {


//Target: ACTOR14
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00053 ACTOR14", getId() );


  }

  void Scene00054( Entity::Player& player )
  {


//Target: ACTOR15
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00054 ACTOR15", getId() );


  }

  void Scene00055( Entity::Player& player )
  {


//Target: ACTOR16
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00055 ACTOR16", getId() );


  }

  void Scene00056( Entity::Player& player )
  {


//Target: ACTOR17
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00056 ACTOR17", getId() );


  }

  void Scene00057( Entity::Player& player )
  {


//Target: ACTOR18
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00057 ACTOR18", getId() );


  }

  void Scene00058( Entity::Player& player )
  {


//Target: ACTOR19
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00058 ACTOR19", getId() );


  }

  void Scene00059( Entity::Player& player )
  {


//Target: ACTOR20
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00059 ACTOR20", getId() );


  }

};

EXPOSE_SCRIPT( GaiUse606 );
