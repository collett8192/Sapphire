// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb803_00912
// Quest Name: In the Eyes of Gods and Men
// Quest ID: 66448
// Start NPC: 1006384
// End NPC: 1006384

using namespace Sapphire;

class GaiUsb803 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
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
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006384;
//    static constexpr auto Actor1 = 1006415;
//    static constexpr auto Actor10 = 1006424;
//    static constexpr auto Actor11 = 1006425;
//    static constexpr auto Actor2 = 1006416;
//    static constexpr auto Actor3 = 1006417;
//    static constexpr auto Actor4 = 1006418;
//    static constexpr auto Actor5 = 1006419;
//    static constexpr auto Actor6 = 1006420;
//    static constexpr auto Actor7 = 1006421;
//    static constexpr auto Actor8 = 1006422;
//    static constexpr auto Actor9 = 1006423;
//    static constexpr auto Eobject0 = 2002588;
//    static constexpr auto Eobject1 = 2002615;
//    static constexpr auto Eventrange0 = 4333660;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Questbattle0 = 60;
//    static constexpr auto Territorytype0 = 301;

  public:
    GaiUsb803() : Sapphire::ScriptAPI::EventScript( 66448 ){}; 
    ~GaiUsb803() = default; 

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
Scene00003( player );
break;
}
case 3:{
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1006416 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002588 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002615 ) { Scene00006( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006417 ) { Scene00007( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006418 ) { Scene00008( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006419 ) { Scene00009( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006420 ) { Scene00010( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1006421 ) { Scene00011( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1006422 ) { Scene00012( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1006423 ) { Scene00013( player ); }
//ACTOR10, null, 0, -2, False
if( actor == 1006424 ) { Scene00014( player ); }
//ACTOR11, null, 0, -2, False
if( actor == 1006425 ) { Scene00015( player ); }
break;
}
case 255:{
Scene00019( player );
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
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
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestBattle, YesNo:Scene00004 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT0", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR3", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR4", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR5", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR6", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR7", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR8", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR9", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR10
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR10", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR11
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR11", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00016 ", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00017 ", getId() );


  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00018 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00019 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb803 );
