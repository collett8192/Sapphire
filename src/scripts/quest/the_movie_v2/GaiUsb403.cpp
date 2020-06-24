// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb403_00859
// Quest Name: Never Trout That I Love
// Quest ID: 66395
// Start NPC: 1006325
// End NPC: 1006325

using namespace Sapphire;

class GaiUsb403 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1006325;
//    static constexpr auto Actor1 = 1006326;
//    static constexpr auto Actor2 = 1006327;
//    static constexpr auto Actor3 = 1006328;
//    static constexpr auto Eobject0 = 2002087;
//    static constexpr auto Eobject1 = 2002298;
//    static constexpr auto Eobject2 = 2002602;
//    static constexpr auto Eobject3 = 2002603;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionSearchLong = 4;
//    static constexpr auto Item0 = 2000666;
//    static constexpr auto Item1 = 2000667;

  public:
    GaiUsb403() : Sapphire::ScriptAPI::EventScript( 66395 ){}; 
    ~GaiUsb403() = default; 

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
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002087 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002298 ) { Scene00004( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002602 ) { Scene00005( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002603 ) { Scene00006( player ); }
break;
}
case 3:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1006326 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00007( player ); }
//ACTOR2, UI8BH, 1, -2, False
if( actor == 1006327 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR3, UI8BL, 1, -2, False
if( actor == 1006328 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00009( player ); }
break;
}
case 255:{
Scene00018( player );
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
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8CH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT1", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT2", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT3", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR2
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR2:UI8BH=-2, 1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR3
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR3:UI8BL=-2, 1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 ", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 ", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00013( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00012 +1 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](12)Talk:Scene00013 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00015( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00014 +1 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](14)Talk:Scene00015 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00017( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00016 +1 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](16)Talk:Scene00017 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00018 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb403 );
