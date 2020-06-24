// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb504_00873
// Quest Name: Plagued by Indecision
// Quest ID: 66409
// Start NPC: 1006355
// End NPC: 1006355

using namespace Sapphire;

class GaiUsb504 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006355;
//    static constexpr auto Actor1 = 1006359;
//    static constexpr auto Eobject0 = 2002097;
//    static constexpr auto Eobject1 = 2002098;
//    static constexpr auto Eobject2 = 2002099;
//    static constexpr auto Eobject3 = 2002100;
//    static constexpr auto Item0 = 2000681;

  public:
    GaiUsb504() : Sapphire::ScriptAPI::EventScript( 66409 ){}; 
    ~GaiUsb504() = default; 

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
if( actor == 2002097 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//EOBJECT1, UI8BH, 1, -2, False
if( actor == 2002098 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00006( player ); }
//EOBJECT2, UI8BL, 1, -2, False
if( actor == 2002099 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00007( player ); }
//EOBJECT3, UI8CH, 1, -2, False
if( actor == 2002100 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00008( player ); }
break;
}
case 3:{
Scene00009( player );
break;
}
case 255:{
Scene00013( player );
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
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00003( player ); }
 else { Scene00004( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00002 +2 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8CL( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](2)Talk:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](2)Inventory:Scene00004 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
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
player.setQuestUI8BH( getId(), 4 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00005 EOBJECT0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
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
player.setQuestUI8BH( getId(), 4 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00006 EOBJECT1:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
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
player.setQuestUI8BH( getId(), 4 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00007 EOBJECT2:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
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
player.setQuestUI8BH( getId(), 4 );
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00008 EOBJECT3:UI8CH=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00010 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00013 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb504 );
