// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubWil066_00320
// Quest Name: Way Down in the Hole
// Quest ID: 65856
// Start NPC: 1001578
// End NPC: 1001353

using namespace Sapphire;

class SubWil066 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1001578;
//    static constexpr auto Actor1 = 1002947;
//    static constexpr auto Actor10 = 1002956;
//    static constexpr auto Actor11 = 1002957;
//    static constexpr auto Actor12 = 1002958;
//    static constexpr auto Actor13 = 1001353;
//    static constexpr auto Actor15 = 1002990;
//    static constexpr auto Actor16 = 1002991;
//    static constexpr auto Actor17 = 1002992;
//    static constexpr auto Actor2 = 1002948;
//    static constexpr auto Actor3 = 1002949;
//    static constexpr auto Actor4 = 1002950;
//    static constexpr auto Actor5 = 1002951;
//    static constexpr auto Actor6 = 1002955;
//    static constexpr auto Actor7 = 1002952;
//    static constexpr auto Actor8 = 1002953;
//    static constexpr auto Actor9 = 1002954;
//    static constexpr auto CutScene02 = 190;
//    static constexpr auto CutScene03 = 191;
//    static constexpr auto CutScene04 = 192;
//    static constexpr auto Eobject0 = 2001851;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000239;
//    static constexpr auto LocActor20 = 1001976;
//    static constexpr auto LocActor30 = 1001794;
//    static constexpr auto LocPosCam1 = 4162159;
//    static constexpr auto LocPosCam2 = 4162312;
//    static constexpr auto LocPosEnpc1 = 3817003;
//    static constexpr auto LocPosEnpc2 = 3817009;
//    static constexpr auto LocPosEnpc3 = 3817004;
//    static constexpr auto LocPosEnpc6 = 4162156;
//    static constexpr auto LocPosEnpc7 = 4162311;
//    static constexpr auto LogmessageRecommendListUnlock = 3701;
//    static constexpr auto Questbattle0 = 18;
//    static constexpr auto Reward0 = 9;
//    static constexpr auto RewardLeve = 5;
//    static constexpr auto Territorytype0 = 248;
//    static constexpr auto Territorytype1 = 141;
//    static constexpr auto UnlockCheckInnReward = 2;
//    static constexpr auto UnlockImageGearSet = 29;
//    static constexpr auto UnlockImageInn = 18;
//    static constexpr auto UnlockImageLeve = 20;

  public:
    SubWil066() : Sapphire::ScriptAPI::EventScript( 65856 ){}; 
    ~SubWil066() = default; 

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
//ACTOR2, UI8AL, 1, -1, False
if( actor == 1002948 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR3, UI8BH, 1, -1, False
if( actor == 1002949 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00006( player ); }
//ACTOR4, UI8BL, 1, -1, False
if( actor == 1002950 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00009( player ); }
//ACTOR5, UI8CH, 1, -1, False
if( actor == 1002951 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00012( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1002947 ) { Scene00015( player ); }
break;
}
case 3:{
Scene00016( player );
break;
}
case 4:{
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR6, UI8AL, 1, -2, False
if( actor == 1002955 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00017( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1002952 ) { Scene00018( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1002953 ) { Scene00019( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1002954 ) { Scene00020( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1002956 ) { Scene00021( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1002957 ) { Scene00022( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1002958 ) { Scene00023( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001851 ) { Scene00024( player ); }
break;
}
case 5:{
Scene00025( player );
break;
}
case 6:{
Scene00027( player );
break;
}
case 255:{
Scene00028( player );
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
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8CL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00004( player ); }
 else { Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00003 +2 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](3)Talk:Scene00004 ACTOR2:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](3)Empty:Scene00005 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00007( player ); }
 else { Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00006 +2 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](6)Talk:Scene00007 ACTOR3:UI8BH=-1, 1", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](6)Empty:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
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
//Target: ACTOR4
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](9)Talk:Scene00010 ACTOR4:UI8BL=-1, 1", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](9)Empty:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00013( player ); }
 else { Scene00014( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00012 +2 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8CH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](12)Talk:Scene00013 ACTOR5:UI8CH=-1, 1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](12)Empty:Scene00014 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR1", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00016 ", getId() );

    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
Scene00025( player );
}
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00017 ACTOR6:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR7", getId() );


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


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00021 ACTOR10", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR11
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR11", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR12
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR12", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00024 EOBJECT0", getId() );


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
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00027 ", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00028 ", getId() );

    player.playScene( getId(), 28, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( SubWil066 );
