// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb901_00924
// Quest Name: Ye of Little Faith
// Quest ID: 66460
// Start NPC: 1006435
// End NPC: 1006444

using namespace Sapphire;

class GaiUsb901 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
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
//    static constexpr auto Actor0 = 1006435;
//    static constexpr auto Actor1 = 1006441;
//    static constexpr auto Actor2 = 1006442;
//    static constexpr auto Actor3 = 1006443;
//    static constexpr auto Actor4 = 1006444;
//    static constexpr auto Item0 = 2000856;
//    static constexpr auto Item1 = 2000858;
//    static constexpr auto LocActor0 = 1003855;
//    static constexpr auto LocActor1 = 1004145;
//    static constexpr auto LocActor2 = 1006902;
//    static constexpr auto LocFace0 = 604;
//    static constexpr auto LocFace1 = 617;

  public:
    GaiUsb901() : Sapphire::ScriptAPI::EventScript( 66460 ){}; 
    ~GaiUsb901() = default; 

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
Scene00004( player );
break;
}
case 255:{
Scene00005( player );
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
player.setQuestUI8BL( getId(), 1 );
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
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](5)Talk, QuestReward, QuestComplete, FadeOut:Scene00006 ", getId() );

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb901 );
