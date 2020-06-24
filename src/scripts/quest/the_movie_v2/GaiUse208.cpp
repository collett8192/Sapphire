// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse208_01352
// Quest Name: Why We Adventure
// Quest ID: 66888
// Start NPC: 1008639
// End NPC: 1008623

using namespace Sapphire;

class GaiUse208 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008639;
//    static constexpr auto Actor1 = 1008638;
//    static constexpr auto Actor10 = 1008643;
//    static constexpr auto Actor11 = 1008644;
//    static constexpr auto Actor12 = 1008645;
//    static constexpr auto Actor13 = 1008646;
//    static constexpr auto Actor14 = 1008623;
//    static constexpr auto Actor15 = 1008648;
//    static constexpr auto Actor16 = 1008649;
//    static constexpr auto Actor17 = 1008650;
//    static constexpr auto Actor18 = 1008651;
//    static constexpr auto Actor19 = 1008652;
//    static constexpr auto Actor2 = 1008632;
//    static constexpr auto Actor20 = 1008653;
//    static constexpr auto Actor21 = 1008654;
//    static constexpr auto Actor22 = 1008656;
//    static constexpr auto Actor23 = 1008657;
//    static constexpr auto Actor24 = 1008658;
//    static constexpr auto Actor3 = 1008647;
//    static constexpr auto Actor4 = 1008655;
//    static constexpr auto Actor5 = 1008703;
//    static constexpr auto Actor6 = 1008704;
//    static constexpr auto Actor7 = 1008640;
//    static constexpr auto Actor8 = 1008641;
//    static constexpr auto Actor9 = 1008642;
//    static constexpr auto CutSceneN01 = 463;
//    static constexpr auto Enemy0 = 4622373;
//    static constexpr auto Eobject0 = 2003570;
//    static constexpr auto Eobject1 = 2003573;
//    static constexpr auto Eobject2 = 2003571;
//    static constexpr auto Eobject3 = 2003572;
//    static constexpr auto EventActionLookoutMiddle = 50;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionSearchShort = 2;
//    static constexpr auto LevelIdNpc01 = 4622300;
//    static constexpr auto Poprange0 = 4627351;

  public:
    GaiUse208() : Sapphire::ScriptAPI::EventScript( 66888 ){}; 
    ~GaiUse208() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1008639 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1008638 ) { Scene00002( player ); }
break;
}
case 1:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1008632 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008647 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008655 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008703 ) { Scene00006( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1008704 ) { Scene00007( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2003570 ) { Scene00008( player ); }
break;
}
case 2:{
//EOBJECT1, null, 0, -2, False
if( actor == 2003573 ) { Scene00009( player ); }
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4622373 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00010( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1008647 ) { Scene00011( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1008655 ) { Scene00012( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1008703 ) { Scene00013( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1008704 ) { Scene00014( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1008632 ) { Scene00015( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2003570 ) { Scene00016( player ); }
break;
}
case 3:{
//ACTOR7, UI8AL, 1, -2, False
if( actor == 1008640 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00017( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1008641 ) { Scene00019( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1008642 ) { Scene00020( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1008643 ) { Scene00021( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1008644 ) { Scene00022( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1008645 ) { Scene00023( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1008646 ) { Scene00024( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2003571 ) { Scene00025( player ); }
break;
}
case 255:{
//ACTOR14, null, 0, -2, False
if( actor == 1008623 ) { Scene00026( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1008648 ) { Scene00027( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1008649 ) { Scene00028( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1008650 ) { Scene00029( player ); }
//ACTOR18, null, 0, -2, False
if( actor == 1008651 ) { Scene00030( player ); }
//ACTOR19, null, 0, -2, False
if( actor == 1008652 ) { Scene00031( player ); }
//ACTOR20, null, 0, -2, False
if( actor == 1008653 ) { Scene00032( player ); }
//ACTOR21, null, 0, -2, False
if( actor == 1008654 ) { Scene00033( player ); }
//ACTOR22, null, 0, -2, False
if( actor == 1008656 ) { Scene00034( player ); }
//ACTOR23, null, 0, -2, False
if( actor == 1008657 ) { Scene00035( player ); }
//ACTOR24, null, 0, -2, False
if( actor == 1008658 ) { Scene00036( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2003572 ) { Scene00037( player ); }
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
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2:UI8AL=-2, 1", getId() );

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


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT0", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Message:Scene00010 ENEMY0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR3", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR4", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR5", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR6", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR2", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00016 EOBJECT0", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00018( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 +1 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](17)CutScene:Scene00018 ACTOR7:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR8", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR9", getId() );


  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR10
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00021 ACTOR10", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR11
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 ACTOR11", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR12", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ACTOR13", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00025 EOBJECT2", getId() );


  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00026 ACTOR14", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR15
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ACTOR15", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {


//Target: ACTOR16
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00028 ACTOR16", getId() );


  }

  void Scene00029( Entity::Player& player )
  {


//Target: ACTOR17
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00029 ACTOR17", getId() );


  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR18
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 ACTOR18", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR19
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 ACTOR19", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR20
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ACTOR20", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR21
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ACTOR21", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR22
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 ACTOR22", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR23
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00035 ACTOR23", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR24
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00036 ACTOR24", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00037 EOBJECT3", getId() );


  }

};

EXPOSE_SCRIPT( GaiUse208 );
