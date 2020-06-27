// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsc604_01004
// Quest Name: Fool Me Twice
// Quest ID: 66540
// Start NPC: 1006531
// End NPC: 1006555

using namespace Sapphire;

class GaiUsc604 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH

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
//    static constexpr auto Actor0 = 1006531;
//    static constexpr auto Actor1 = 1006709;
//    static constexpr auto Actor2 = 1006553;
//    static constexpr auto Actor3 = 1006706;
//    static constexpr auto Actor4 = 1006707;
//    static constexpr auto Actor5 = 1006708;
//    static constexpr auto Actor6 = 1006554;
//    static constexpr auto Actor7 = 1006705;
//    static constexpr auto Actor8 = 1006555;
//    static constexpr auto Actor9 = 1006530;
//    static constexpr auto Eobject0 = 2002329;
//    static constexpr auto EquipCheckBody = 6224;
//    static constexpr auto EquipCheckHead = 6223;
//    static constexpr auto Item0 = 2000771;
//    static constexpr auto Poprange0 = 4321644;
//    static constexpr auto Questbattle0 = 63;
//    static constexpr auto Territorytype0 = 308;
//    static constexpr auto Territorytype1 = 156;

  public:
    GaiUsc604() : Sapphire::ScriptAPI::EventScript( 66540 ){}; 
    ~GaiUsc604() = default; 

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
if( actor == 1006709 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006553 ) { Scene00005( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006706 ) { Scene00006( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006707 ) { Scene00007( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006708 ) { Scene00008( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006554 ) { Scene00009( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1006705 ) { Scene00010( player ); }
break;
}
case 2:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002329 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00012( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006553 ) { Scene00013( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006706 ) { Scene00014( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006707 ) { Scene00015( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006708 ) { Scene00016( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006709 ) { Scene00017( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1006705 ) { Scene00018( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006554 ) { Scene00019( player ); }
break;
}
case 255:{
//ACTOR8, null, 0, -2, False
if( actor == 1006555 ) { Scene00020( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1006530 ) { Scene00021( player ); }
break;
}
default: { player.sendUrgent( "seq {} not defined.", player.getQuestSeq( getId() ) ); break; }
}
  }

  void onEmote( uint64_t actorId, uint32_t eventId, uint32_t emoteId, Sapphire::Entity::Player& player ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );

    switch( player.getQuestSeq( getId() ) )
    {
      case 1:
      {
        if( actor == 1006709 )
        {
          if( emoteId == 59 )
          {
            Scene00003( player );
          }
          else
          {
            Scene00004( player );
          }
        }
        break;
      }
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
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 2 );
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


player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR2", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00011 ACTOR3", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param2 == 1 )
        player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00012 ACTOR4", getId() );
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR5", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR1", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR7", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR6", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00019 ", getId() );


  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00020 ACTOR8", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//no valid quest var detected
if( result.param2 == 1 ){
  player.eventFinish( getId(), 1 );
  player.setPosAndSendActorMove( 0.64, -158.5, 13.4, 3.13 );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00021 ACTOR9", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsc604 );
