// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: True, S: True, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb913_00936
// Quest Name: The King Rat Must Die
// Quest ID: 66472
// Start NPC: 1006460
// End NPC: 1006460

using namespace Sapphire;

class GaiUsb913 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
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
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006460;
//    static constexpr auto Enemy0 = 4293236;
//    static constexpr auto Enemy1 = 4293237;
//    static constexpr auto Enemy2 = 4293238;
//    static constexpr auto Enemy3 = 4293239;
//    static constexpr auto Enemy4 = 4293240;
//    static constexpr auto Enemy5 = 4293241;
//    static constexpr auto Enemy6 = 4293242;
//    static constexpr auto Enemy7 = 4293243;
//    static constexpr auto Enemy8 = 4293244;
//    static constexpr auto Enemy9 = 4293246;
//    static constexpr auto Eobject0 = 2002166;
//    static constexpr auto Eobject1 = 2002167;
//    static constexpr auto Eobject2 = 2002168;
//    static constexpr auto Eobject3 = 2002169;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionSearchMiddle = 3;

  public:
    GaiUsb913() : Sapphire::ScriptAPI::EventScript( 66472 ){}; 
    ~GaiUsb913() = default; 

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
//EOBJECT0, null, 0, -2, False
if( actor == 2002166 ) { Scene00002( player ); }
//if( actorId == 4293236 && player.getQuestUI8AL( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4293237 && player.getQuestUI8AL( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4293238 && player.getQuestUI8AL( getId() ) != 3 ) { Scene?????( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002167 ) { Scene00004( player ); }
//if( actorId == 4293239 && player.getQuestUI8BH( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4293240 && player.getQuestUI8BH( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4293241 && player.getQuestUI8BH( getId() ) != 3 ) { Scene?????( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002168 ) { Scene00006( player ); }
//if( actorId == 4293242 && player.getQuestUI8BL( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4293243 && player.getQuestUI8BL( getId() ) != 3 ) { Scene?????( player ); }
//if( actorId == 4293244 && player.getQuestUI8BL( getId() ) != 3 ) { Scene?????( player ); }
break;
}
case 2:{
Scene00008( player );
break;
}
case 3:{
//EOBJECT3, null, 0, -2, False
if( actor == 2002169 ) { Scene00009( player ); }
//if( actorId == 4293246 && player.getQuestUI8AL( getId() ) != 1 ) { Scene?????( player ); }
break;
}
case 255:{
Scene00011( player );
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
//      case Enemy3: { break; }
//      case Enemy4: { break; }
//      case Enemy5: { break; }
//      case Enemy6: { break; }
//      case Enemy7: { break; }
//      case Enemy8: { break; }
//      case Enemy9: { break; }
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
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Message:Scene00003 EOBJECT0", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00004 +1 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Message:Scene00005 EOBJECT1", getId() );

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
//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](6)Message:Scene00007 EOBJECT2", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](9)Message:Scene00010 EOBJECT3", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb913 );
