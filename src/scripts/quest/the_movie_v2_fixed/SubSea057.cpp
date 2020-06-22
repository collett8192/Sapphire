// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea057_00469
// Quest Name: Just Deserts
// Quest ID: 66005
// Start NPC: 1002626
// End NPC: 1000972

using namespace Sapphire;

class SubSea057 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1002626;
//    static constexpr auto Actor1 = 1002633;
//    static constexpr auto Actor10 = 1000972;
//    static constexpr auto Actor2 = 1002645;
//    static constexpr auto Actor3 = 1002644;
//    static constexpr auto Actor4 = 1002646;
//    static constexpr auto Actor5 = 1002647;
//    static constexpr auto Actor6 = 1002648;
//    static constexpr auto Actor7 = 1002649;
//    static constexpr auto Actor8 = 1002650;
//    static constexpr auto Actor9 = 1003349;
//    static constexpr auto CutScene02 = 204;
//    static constexpr auto CutScene03 = 205;
//    static constexpr auto CutScene04 = 206;
//    static constexpr auto Eobject0 = 2001734;
//    static constexpr auto EventAction = 35;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocActor1 = 1003289;
//    static constexpr auto LocActor2 = 1000970;
//    static constexpr auto LocActor3 = 1000974;
//    static constexpr auto LocPosActor2 = 4155969;
//    static constexpr auto LocPosActor3 = 4155970;
//    static constexpr auto LogmessageRecommendListUnlock = 3701;
//    static constexpr auto Questbattle0 = 29;
//    static constexpr auto Reward0 = 9;
//    static constexpr auto Seq0Actor0Lq = 90;
//    static constexpr auto Territorytype0 = 272;
//    static constexpr auto Territorytype1 = 134;
//    static constexpr auto UnlockImageInn = 18;
//    static constexpr auto UnlockImageLeve = 20;

  public:
    SubSea057() : Sapphire::ScriptAPI::EventScript( 66005 ){}; 
    ~SubSea057() = default; 

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
if( actor == 1002645 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
if( actor == 1002644 ) { Scene00004( player ); }
if( actor == 1002646 ) { Scene00005( player ); }
if( actor == 1002647 ) { Scene00006( player ); }
if( actor == 1002648 ) { Scene00007( player ); }
if( actor == 1002649 ) { Scene00008( player ); }
if( actor == 1002650 ) { Scene00009( player ); }
break;
}
case 3:{
if( actor == 1002646 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00011( player ); }
if( actor == 1002644 ) { Scene00011( player ); }
if( actor == 1002648 ) { Scene00012( player ); }
if( actor == 1002649 ) { Scene00013( player ); }
if( actor == 1002650 ) { Scene00014( player ); }
if( actor == 1002647 ) { Scene00015( player ); }
break;
}
case 4:{
if( actor == 1002647 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00019( player ); }
if( actor == 1002648 ) { Scene00017( player ); }
if( actor == 1002649 ) { Scene00018( player ); }
if( actor == 1002650 ) { Scene00019( player ); }
if( actor == 1002644 ) { Scene00020( player ); }
if( actor == 2001734 ) { Scene00021( player ); }
break;
}
case 5:{
Scene00022( player );
break;
}
case 6:{
if( actor == 1002626 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00027( player ); }
if( actorId == 4299112342 ) { Scene00028( player ); }
break;
}
case 7:{
Scene00029( player );
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
player.sendDebug( "questId: {}, calling Talk, QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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


//Target: ACTOR4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR4:UI8AL=-2, 1", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
      player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR3", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR6", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR7", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR8", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR5", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: ACTOR5
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 5 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR5:UI8AL=-2, 1", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
      Scene00019( player );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR6", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00018 ACTOR7", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
      if( result.param2 == 1 )
        Scene00025( player );
    };
player.sendDebug( "questId: {}, calling Talk, QuestBattle, YesNo:Scene00019 ACTOR8", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR3", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00021 EOBJECT0", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


player.updateQuest( getId(), 6 );

player.sendDebug( "questId: {}, calling Empty:Scene00022 ", getId() );


  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 7 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 23, NONE, callback );
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
{ Scene00026( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00025 +1 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 6 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](25)CutScene:Scene00026 ", getId() );

    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 7 );
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00027 ", getId() );

    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00028 ", getId() );

    player.playScene( getId(), 28, NONE, callback );
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
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00030 ", getId() );

    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( SubSea057 );
