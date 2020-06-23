// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa104_00718
// Quest Name: Forest Friend
// Quest ID: 66254
// Start NPC: 1006675
// End NPC: 1000580

using namespace Sapphire;

class GaiUsa104 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventFidget = 968;
//    static constexpr auto Actor0 = 1006675;
//    static constexpr auto Actor1 = 1000584;
//    static constexpr auto Actor2 = 1000580;
//    static constexpr auto Enemy0 = 179;
//    static constexpr auto Enemy1 = 7;
//    static constexpr auto Eobject0 = 2001913;
//    static constexpr auto Eobject1 = 2001914;
//    static constexpr auto Eobject2 = 2001915;
//    static constexpr auto Eobject3 = 2001916;
//    static constexpr auto Eobject4 = 2001917;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000577;

  public:
    GaiUsa104() : Sapphire::ScriptAPI::EventScript( 66254 ){}; 
    ~GaiUsa104() = default; 

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
Scene00001( player );
break;
}
case 2:{
//ENEMY0, UI8BH, 5, -2, False
if( actorId == 223 && player.getQuestUI8BH( getId() ) != 5 ) { Scene00002( player ); }
//ENEMY1, UI8BL, 5, -2, False
if( actorId == 2157 && player.getQuestUI8BL( getId() ) != 5 ) { Scene00003( player ); }
//EOBJECT0, UI8AL, 5, -2, False
if( actor == 2001913 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00004( player ); }
//EOBJECT1, UI8AL, 5, -2, False
if( actor == 2001914 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00005( player ); }
//EOBJECT2, UI8AL, 5, -2, False
if( actor == 2001915 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00006( player ); }
//EOBJECT3, UI8AL, 5, -2, False
if( actor == 2001916 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00007( player ); }
//EOBJECT4, UI8AL, 5, -2, False
if( actor == 2001917 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00008( player ); }
break;
}
case 255:{
Scene00012( player );
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
if( result.param2 == 1 ){
player.updateQuest( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8CH( getId(), 5 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: ENEMY0
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 5 ){
if( player.getQuestUI8BL( getId() ) == 5 ){
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00002 ENEMY0:UI8BH=-2, 5", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: ENEMY1
player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 5 ){
if( player.getQuestUI8BL( getId() ) == 5 ){
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 ENEMY1:UI8BL=-2, 5", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 5 ){
if( player.getQuestUI8BL( getId() ) == 5 ){
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT0:UI8AL=-2, 5", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 5 ){
if( player.getQuestUI8BL( getId() ) == 5 ){
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT1:UI8AL=-2, 5", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 5 ){
if( player.getQuestUI8BL( getId() ) == 5 ){
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT2:UI8AL=-2, 5", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 5 ){
if( player.getQuestUI8BL( getId() ) == 5 ){
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT3:UI8AL=-2, 5", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 5 ){
if( player.getQuestUI8BL( getId() ) == 5 ){
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT4:UI8AL=-2, 5", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 ", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 ", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 5 );

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
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](12)Talk, QuestReward, QuestComplete:Scene00013 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsa104 );
