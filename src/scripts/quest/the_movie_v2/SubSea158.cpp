// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubSea158_01291
// Quest Name: Curiosity Killed the Coeurl
// Quest ID: 66827
// Start NPC: 1005394
// End NPC: 1005394

using namespace Sapphire;

class SubSea158 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
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
//    static constexpr auto Actor0 = 1005394;
//    static constexpr auto Actor1 = 1005396;
//    static constexpr auto Actor2 = 1005397;
//    static constexpr auto Enemy0 = 4507190;
//    static constexpr auto Enemy1 = 4507192;
//    static constexpr auto Eobject0 = 2002863;
//    static constexpr auto Eventrange0 = 4497402;
//    static constexpr auto EventActionRescure = 26;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2001086;
//    static constexpr auto LocActor0 = 1005400;
//    static constexpr auto LocSe1 = 55;
//    static constexpr auto VfxReaction = 177;

  public:
    SubSea158() : Sapphire::ScriptAPI::EventScript( 66827 ){}; 
    ~SubSea158() = default; 

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
//ENEMY0, UI8BL, 2, -2, False
if( actor == 4507190 && player.getQuestUI8BL( getId() ) != 2 ) { Scene00002( player ); }
//ENEMY1, UI8BL, 2, -2, False
if( actor == 4507192 && player.getQuestUI8BL( getId() ) != 2 ) { Scene00003( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1005396 ) { Scene00004( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1005397 ) { Scene00005( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1005394 ) { Scene00006( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002863 ) { Scene00007( player ); }
break;
}
case 2:{
//ACTOR1, UI8BH, 1, -2, False
if( actor == 1005396 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00008( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1005397 ) { Scene00009( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1005394 ) { Scene00010( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -1, False
if( actor == 1005394 ) { Scene00012( player ); }
//ACTOR2, null, 0, -1, False
if( actor == 1005397 ) { Scene00015( player ); }
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
//Target: ENEMY0
player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
if( player.getQuestUI8BL( getId() ) == 2 ){
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BL( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Message:Scene00002 ENEMY0:UI8BL=-2, 2", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY1
player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
if( player.getQuestUI8BL( getId() ) == 2 ){
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BL( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ENEMY1:UI8BL=-2, 2", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR1", getId() );


  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR2", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR0", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 2 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT0", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR1:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR2", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR0", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
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
//Target: ACTOR0
//no valid quest var detected
Scene00014( player );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](12)Talk, FadeOut:Scene00013 +1 ACTOR0", getId() );

    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:CombinedComplete](13)QuestReward, QuestComplete:Scene00014 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR2", getId() );


  }

};

EXPOSE_SCRIPT( SubSea158 );
