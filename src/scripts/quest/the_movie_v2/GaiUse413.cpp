// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse413_00081
// Quest Name: In Flagrante Delicto
// Quest ID: 65617
// Start NPC: 1010034
// End NPC: 1010147

using namespace Sapphire;

class GaiUse413 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1010034;
//    static constexpr auto Actor1 = 1010035;
//    static constexpr auto Actor10 = 1010031;
//    static constexpr auto Actor11 = 1010032;
//    static constexpr auto Actor12 = 1010033;
//    static constexpr auto Actor13 = 1010037;
//    static constexpr auto Actor14 = 1010038;
//    static constexpr auto Actor15 = 1009987;
//    static constexpr auto Actor16 = 1010147;
//    static constexpr auto Actor2 = 1010036;
//    static constexpr auto Actor3 = 1010024;
//    static constexpr auto Actor4 = 1010025;
//    static constexpr auto Actor5 = 1010026;
//    static constexpr auto Actor6 = 1010027;
//    static constexpr auto Actor7 = 1010028;
//    static constexpr auto Actor8 = 1010029;
//    static constexpr auto Actor9 = 1010030;
//    static constexpr auto CutSceneN01 = 614;
//    static constexpr auto LocActor0 = 1008192;
//    static constexpr auto Poprange0 = 5102247;
//    static constexpr auto QstCompChk1 = 65748;

  public:
    GaiUse413() : Sapphire::ScriptAPI::EventScript( 65617 ){}; 
    ~GaiUse413() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1010034 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010035 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1010036 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1010024 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010025 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010026 ) { Scene00006( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010027 ) { Scene00007( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1010028 ) { Scene00008( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1010029 ) { Scene00009( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1010030 ) { Scene00010( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1010031 ) { Scene00011( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1010032 ) { Scene00012( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1010033 ) { Scene00013( player ); }
break;
}
case 1:{
//ACTOR13, UI8AL, 1, -2, False
if( actor == 1010037 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00014( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1010034 ) { Scene00015( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1010035 ) { Scene00016( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1010036 ) { Scene00017( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1010024 ) { Scene00018( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010025 ) { Scene00019( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010026 ) { Scene00020( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1010027 ) { Scene00021( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1010028 ) { Scene00022( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1010029 ) { Scene00023( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1010030 ) { Scene00024( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1010031 ) { Scene00025( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1010032 ) { Scene00026( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1010033 ) { Scene00027( player ); }
break;
}
case 2:{
Scene00029( player );
break;
}
case 3:{
//no scene is assigned
break;
}
case 255:{
Scene00030( player );
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


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00003 ACTOR2", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR3", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR4", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR5", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR6", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR7", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR8", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR9", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR10", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR11
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR11", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR12
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR12", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR13
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00014 ACTOR13:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR1", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR2", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR3", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR4", getId() );


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


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR10", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR11
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00026 ACTOR11", getId() );


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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR12
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](27)CutScene:Scene00028 ACTOR12", getId() );

    player.playScene( getId(), 28, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00030 ", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse413 );
