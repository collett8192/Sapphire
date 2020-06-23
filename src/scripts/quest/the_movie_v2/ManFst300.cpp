// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManFst300_00511
// Quest Name: A Hero in the Making
// Quest ID: 66047
// Start NPC: 1005116
// End NPC: 1005122

using namespace Sapphire;

class ManFst300 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag24
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL

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
//    static constexpr auto Actor0 = 1005116;
//    static constexpr auto Actor1 = 1003785;
//    static constexpr auto Actor10 = 1004875;
//    static constexpr auto Actor11 = 1004876;
//    static constexpr auto Actor12 = 1006179;
//    static constexpr auto Actor13 = 1004880;
//    static constexpr auto Actor14 = 1004881;
//    static constexpr auto Actor15 = 1004882;
//    static constexpr auto Actor16 = 1006173;
//    static constexpr auto Actor17 = 1006174;
//    static constexpr auto Actor18 = 1006175;
//    static constexpr auto Actor19 = 1006181;
//    static constexpr auto Actor2 = 1004883;
//    static constexpr auto Actor20 = 1006183;
//    static constexpr auto Actor21 = 1006184;
//    static constexpr auto Actor22 = 1006177;
//    static constexpr auto Actor23 = 1006178;
//    static constexpr auto Actor24 = 1005122;
//    static constexpr auto Actor3 = 1004884;
//    static constexpr auto Actor4 = 1004885;
//    static constexpr auto Actor5 = 1001029;
//    static constexpr auto Actor6 = 1004870;
//    static constexpr auto Actor7 = 1004871;
//    static constexpr auto Actor8 = 1004872;
//    static constexpr auto Actor9 = 1004874;
//    static constexpr auto Eobject0 = 2001690;
//    static constexpr auto Eobject1 = 2001691;
//    static constexpr auto EventActionWaiting = 10;
//    static constexpr auto LocAction1 = 1002;
//    static constexpr auto LocActor0 = 1003783;
//    static constexpr auto LocSe1 = 42;
//    static constexpr auto LocTalkshape1 = 6;
//    static constexpr auto Ncut0 = 89;
//    static constexpr auto Ncut1 = 90;
//    static constexpr auto Ncut2 = 151;
//    static constexpr auto Ncut3 = 91;
//    static constexpr auto Ncut4 = 152;
//    static constexpr auto Ncut5 = 92;
//    static constexpr auto Ncut6 = 153;
//    static constexpr auto Ncut7 = 93;

  public:
    ManFst300() : Sapphire::ScriptAPI::EventScript( 66047 ){}; 
    ~ManFst300() = default; 

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
if( actor == 1003785 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1004883 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1004884 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1004885 ) { Scene00005( player ); }
break;
}
case 2:{
//EOBJECT0, UI8BH, 1, -2, False
if( actor == 2001690 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00006( player ); }
//EOBJECT1, UI8BL, 1, -2, False
if( actor == 2001691 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR5, UI8AL, 1, -2, False
if( actor == 1001029 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00010( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1004870 ) { Scene00012( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1004871 ) { Scene00013( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1004872 ) { Scene00014( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1004874 ) { Scene00015( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1004875 ) { Scene00016( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1004876 ) { Scene00017( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1006179 ) { Scene00018( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1004880 ) { Scene00019( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1004881 ) { Scene00020( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1004882 ) { Scene00021( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1006173 ) { Scene00022( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1006174 ) { Scene00023( player ); }
//ACTOR18, null, 0, -2, False
if( actor == 1006175 ) { Scene00024( player ); }
//ACTOR19, null, 0, -2, False
if( actor == 1006181 ) { Scene00025( player ); }
//ACTOR20, null, 0, -2, False
if( actor == 1006183 ) { Scene00026( player ); }
//ACTOR21, null, 0, -2, False
if( actor == 1006184 ) { Scene00027( player ); }
//ACTOR22, null, 0, -2, False
if( actor == 1006177 ) { Scene00028( player ); }
//ACTOR23, null, 0, -2, False
if( actor == 1006178 ) { Scene00029( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1004883 ) { Scene00030( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1004884 ) { Scene00031( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1004885 ) { Scene00032( player ); }
break;
}
case 255:{
//ACTOR24, null, 0, -2, False
if( actor == 1005122 ) { Scene00033( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1004883 ) { Scene00035( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1004884 ) { Scene00036( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1004885 ) { Scene00037( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept, CutScene:Scene00001 ", getId() );

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
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](6)Talk, CutScene, FadeOut:Scene00007 EOBJECT0:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00008 +1 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](8)Talk, CutScene, FadeOut:Scene00009 EOBJECT1:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00010 +1 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](10)Talk, CutScene, FadeOut:Scene00011 ACTOR5:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR6", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR7", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR8", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR9", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR10", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR11
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR11", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR12
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR12", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR13
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR13", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR14
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR14", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


//Target: ACTOR15
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00021 ACTOR15", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR16
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR16", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR17
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR17", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR18
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00024 ACTOR18", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR19
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR19", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR20
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00026 ACTOR20", getId() );


  }

  void Scene00027( Entity::Player& player )
  {


//Target: ACTOR21
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00027 ACTOR21", getId() );


  }

  void Scene00028( Entity::Player& player )
  {


//Target: ACTOR22
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00028 ACTOR22", getId() );


  }

  void Scene00029( Entity::Player& player )
  {


//Target: ACTOR23
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00029 ACTOR23", getId() );


  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 ACTOR2", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 ACTOR3", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ACTOR4", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
Scene00034( player );
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00033 +1 ", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR24
//no valid quest var detected
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](33)CutScene:Scene00034 ACTOR24", getId() );

    player.playScene( getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00035 ACTOR2", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00036 ACTOR3", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00037 ACTOR4", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

};

EXPOSE_SCRIPT( ManFst300 );
