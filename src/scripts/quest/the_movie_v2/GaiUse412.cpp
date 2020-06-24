// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse412_00080
// Quest Name: Doman Connection
// Quest ID: 65616
// Start NPC: 1010017
// End NPC: 1010034

using namespace Sapphire;

class GaiUse412 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1010017;
//    static constexpr auto Actor1 = 1010020;
//    static constexpr auto Actor10 = 1010024;
//    static constexpr auto Actor11 = 1010025;
//    static constexpr auto Actor12 = 1010026;
//    static constexpr auto Actor13 = 1010027;
//    static constexpr auto Actor14 = 1010028;
//    static constexpr auto Actor15 = 1010029;
//    static constexpr auto Actor16 = 1010030;
//    static constexpr auto Actor17 = 1010031;
//    static constexpr auto Actor18 = 1010032;
//    static constexpr auto Actor19 = 1010033;
//    static constexpr auto Actor2 = 1010021;
//    static constexpr auto Actor3 = 1009986;
//    static constexpr auto Actor4 = 1010022;
//    static constexpr auto Actor5 = 1010023;
//    static constexpr auto Actor6 = 1009975;
//    static constexpr auto Actor7 = 1010034;
//    static constexpr auto Actor8 = 1010035;
//    static constexpr auto Actor9 = 1010036;
//    static constexpr auto BgmNothing = 1;
//    static constexpr auto Enemy0 = 5099974;
//    static constexpr auto Enemy1 = 5099975;
//    static constexpr auto Enemy2 = 5099976;
//    static constexpr auto Eobject0 = 2004660;
//    static constexpr auto Eventrange0 = 5099945;
//    static constexpr auto LocActor0 = 1007097;
//    static constexpr auto LocBgm01 = 114;
//    static constexpr auto LocPosActor0 = 5249407;
//    static constexpr auto Poprange0 = 5249405;

  public:
    GaiUse412() : Sapphire::ScriptAPI::EventScript( 65616 ){}; 
    ~GaiUse412() = default; 

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
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1010021 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009986 ) { Scene00006( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010022 ) { Scene00009( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010023 ) { Scene00010( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009975 ) { Scene00011( player ); }
break;
}
case 3:{
//EOBJECT0, null, 0, -2, False
if( actor == 2004660 ) { Scene00012( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1010021 ) { Scene00015( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1010022 ) { Scene00016( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1010023 ) { Scene00017( player ); }
break;
}
case 255:{
//ACTOR7, null, 0, -2, False
if( actor == 1010034 ) { Scene00016( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1010035 ) { Scene00017( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1010036 ) { Scene00018( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1010024 ) { Scene00019( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1010025 ) { Scene00020( player ); }
//ACTOR12, null, 0, -2, False
if( actor == 1010026 ) { Scene00021( player ); }
//ACTOR13, null, 0, -2, False
if( actor == 1010027 ) { Scene00022( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1010028 ) { Scene00023( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1010029 ) { Scene00024( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1010030 ) { Scene00025( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1010031 ) { Scene00026( player ); }
//ACTOR18, null, 0, -2, False
if( actor == 1010032 ) { Scene00027( player ); }
//ACTOR19, null, 0, -2, False
if( actor == 1010033 ) { Scene00028( player ); }
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
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00002 ", getId() );

    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00004( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 +2 ", getId() );

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
player.sendDebug( "questId: {}, calling [sub:BranchTrue](3)Talk:Scene00004 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](3)Empty:Scene00005 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00006 +2 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](6)Talk:Scene00007 ACTOR3", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](6)Unknown:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR4", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR5", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR6", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00013( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00012 +2 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](12)Talk:Scene00013 EOBJECT0", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](12)Empty:Scene00014 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR2", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00016 ACTOR7", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR8
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR8", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR9
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR9", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR10
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR10", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR11
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR11", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


//Target: ACTOR12
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00021 ACTOR12", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR13
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR13", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR14
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR14", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR15
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00024 ACTOR15", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR16
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR16", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR17
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00026 ACTOR17", getId() );


  }

  void Scene00027( Entity::Player& player )
  {


//Target: ACTOR18
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00027 ACTOR18", getId() );


  }

  void Scene00028( Entity::Player& player )
  {


//Target: ACTOR19
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00028 ACTOR19", getId() );


  }

};

EXPOSE_SCRIPT( GaiUse412 );
