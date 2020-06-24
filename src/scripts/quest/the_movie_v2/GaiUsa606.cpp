// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa606_00768
// Quest Name: An Apple a Day
// Quest ID: 66304
// Start NPC: 1006236
// End NPC: 1006237

using namespace Sapphire;

class GaiUsa606 : public Sapphire::ScriptAPI::EventScript
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
    // GetQuestUI8DH
    // GetQuestUI8DL

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
//    static constexpr auto Actor0 = 1006236;
//    static constexpr auto Actor1 = 1006237;
//    static constexpr auto Enemy0 = 4278319;
//    static constexpr auto Enemy1 = 4278320;
//    static constexpr auto Enemy2 = 4278321;
//    static constexpr auto Eobject0 = 2001969;
//    static constexpr auto Eobject1 = 2001970;
//    static constexpr auto Eobject2 = 2001971;
//    static constexpr auto Eobject3 = 2001972;
//    static constexpr auto Eobject4 = 2002269;
//    static constexpr auto Eobject5 = 2001973;
//    static constexpr auto EventActionProcessUpperMiddle = 32;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000608;

  public:
    GaiUsa606() : Sapphire::ScriptAPI::EventScript( 66304 ){}; 
    ~GaiUsa606() = default; 

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
if( actor == 2001969 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001970 ) { Scene00006( player ); }
//if( actorId == 4278319 && player.getQuestUI8CH( getId() ) != 1 ) { Scene?????( player ); }
//EOBJECT2, UI8BH, 1, -2, False
if( actor == 2001971 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00008( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001972 ) { Scene00010( player ); }
//if( actorId == 4278320 && player.getQuestUI8CL( getId() ) != 1 ) { Scene?????( player ); }
//EOBJECT4, UI8BL, 1, -2, False
if( actor == 2002269 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00012( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2001973 ) { Scene00013( player ); }
//if( actorId == 4278321 && player.getQuestUI8DH( getId() ) != 1 ) { Scene?????( player ); }
break;
}
case 255:{
Scene00015( player );
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
player.setQuestUI8DL( getId(), 6 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00004( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00003 +1 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](3)Empty:Scene00004 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](6)Empty:Scene00005 EOBJECT1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00006 +2 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](6)Empty:Scene00007 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT2:UI8BH=-2, 1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](10)Empty:Scene00009 EOBJECT3", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00010 +2 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](10)Empty:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00012 EOBJECT4:UI8BL=-2, 1", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00014( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00013 +1 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Message:Scene00014 EOBJECT5", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00016( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00015 +1 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](15)Talk, QuestReward, QuestComplete:Scene00016 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsa606 );
