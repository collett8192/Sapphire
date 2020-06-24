// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea101_00398
// Quest Name: Courier for a Day
// Quest ID: 65934
// Start NPC: 1003239
// End NPC: 1003239

using namespace Sapphire;

class SubSea101 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1003239;
//    static constexpr auto Actor1 = 1003240;
//    static constexpr auto Actor2 = 1003241;
//    static constexpr auto Item0 = 2000338;
//    static constexpr auto Item1 = 2000339;

  public:
    SubSea101() : Sapphire::ScriptAPI::EventScript( 65934 ){}; 
    ~SubSea101() = default; 

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
//ACTOR1, UI8AL, 1, -1, False
if( actor == 1003240 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00001( player ); }
//ACTOR2, UI8BH, 1, -1, False
if( actor == 1003241 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00002( player ); }
break;
}
case 255:{
Scene00003( player );
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
if( result.param2 == 1 ){
player.updateQuest( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00100( player ); }
 else { Scene00099( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00001 +2 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00098( player ); }
 else { Scene00097( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00002 +2 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00097( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](2)Empty:Scene00097 ", getId() );

    player.playScene( getId(), 97, NONE, callback );
  }

  void Scene00098( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](2)Talk:Scene00098 ACTOR2:UI8BH=-1, 1", getId() );

    player.playScene( getId(), 98, NONE, callback );
  }

  void Scene00099( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](1)Empty:Scene00099 ", getId() );

    player.playScene( getId(), 99, NONE, callback );
  }

  void Scene00100( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](1)Talk:Scene00100 ACTOR1:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 100, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubSea101 );
