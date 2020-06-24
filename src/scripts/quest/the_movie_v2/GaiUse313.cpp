// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: False, A3: False, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse313_01454
// Quest Name: A Hard Hapalit to Break
// Quest ID: 66990
// Start NPC: 1008969
// End NPC: 1006530

using namespace Sapphire;

class GaiUse313 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1008969;
//    static constexpr auto Actor1 = 1006530;
//    static constexpr auto Actor2 = 1009076;
//    static constexpr auto Enemy0 = 4867448;
//    static constexpr auto Eobject0 = 2004144;
//    static constexpr auto Eventrange0 = 4867451;
//    static constexpr auto EventActionRescueUpperMiddle = 39;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocAction1 = 1041;
//    static constexpr auto LocActor0 = 1004145;
//    static constexpr auto LocEobj1 = 2004499;
//    static constexpr auto LocFace1 = 617;
//    static constexpr auto LocFace2 = 611;
//    static constexpr auto LocFace3 = 605;
//    static constexpr auto LocPosCam1 = 4891203;
//    static constexpr auto LocPosEobj1 = 4891195;
//    static constexpr auto LocSe1 = 44;
//    static constexpr auto LocSe2 = 45;
//    static constexpr auto QstBanama005 = 66757;
//    static constexpr auto QstBanixa005 = 67026;
//    static constexpr auto QstBankob005 = 66860;
//    static constexpr auto QstBansah005 = 66914;
//    static constexpr auto QstGaiusd101 = 66695;
//    static constexpr auto QstGaiusd203 = 66737;

  public:
    GaiUse313() : Sapphire::ScriptAPI::EventScript( 66990 ){}; 
    ~GaiUse313() = default; 

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
//ENEMY0, UI8AL, 1, -2, False
if( actorId == 4867448 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004144 ) { Scene00005( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1009076 ) { Scene00007( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006530 ) { Scene00008( player ); }
break;
}
case 3:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1009076 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00010( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006530 ) { Scene00012( player ); }
break;
}
case 4:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1009076 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00014( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006530 ) { Scene00015( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept, FadeOut:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
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
player.sendDebug( "questId: {}, calling Message:Scene00003 +1 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](3)Empty:Scene00004 ENEMY0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00005 +1 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](5)Talk:Scene00006 EOBJECT0", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR2", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00008 +1 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](8)Talk:Scene00009 ACTOR1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 +1 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](10)Talk:Scene00011 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00013( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 +1 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](12)Talk:Scene00013 ACTOR1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00015 ACTOR1", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse313 );
