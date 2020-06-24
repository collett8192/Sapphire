// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa103_00717
// Quest Name: Dance Dance Diplomacy
// Quest ID: 66253
// Start NPC: 1006674
// End NPC: 1006674

using namespace Sapphire;

class GaiUsa103 : public Sapphire::ScriptAPI::EventScript
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
    // GetQuestUI8EH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineEventByebye = 962;
//    static constexpr auto ActionTimelineEventFidget = 968;
//    static constexpr auto ActionTimelineEventJoyBig = 945;
//    static constexpr auto ActionTimelineEventLaugh = 952;
//    static constexpr auto ActionTimelineEventTrouble = 944;
//    static constexpr auto Actor0 = 1006674;
//    static constexpr auto Actor1 = 1000563;
//    static constexpr auto Actor2 = 1000437;
//    static constexpr auto Actor3 = 1000576;
//    static constexpr auto Actor4 = 1000585;
//    static constexpr auto Actor5 = 1000584;
//    static constexpr auto Actor6 = 1000587;
//    static constexpr auto Actor7 = 1000578;
//    static constexpr auto Actor8 = 1000277;

  public:
    GaiUsa103() : Sapphire::ScriptAPI::EventScript( 66253 ){}; 
    ~GaiUsa103() = default; 

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
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1000563 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00001( player ); }
//ACTOR2, UI8BH, 1, -2, False
if( actor == 1000437 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR3, UI8BL, 1, -2, False
if( actor == 1000576 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00007( player ); }
//ACTOR4, UI8CH, 1, -2, False
if( actor == 1000585 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00010( player ); }
//ACTOR5, UI8CL, 1, -2, False
if( actor == 1000584 && player.getQuestUI8CL( getId() ) != 1 ) { Scene00013( player ); }
//ACTOR6, UI8DH, 1, -2, False
if( actor == 1000587 && player.getQuestUI8DH( getId() ) != 1 ) { Scene00016( player ); }
//ACTOR7, UI8DL, 1, -2, False
if( actor == 1000578 && player.getQuestUI8DL( getId() ) != 1 ) { Scene00019( player ); }
//ACTOR8, UI8EH, 1, -2, False
if( actor == 1000277 && player.getQuestUI8EH( getId() ) != 1 ) { Scene00022( player ); }
break;
}
case 255:{
Scene00025( player );
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
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00002( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00001 +2 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](1)Talk:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](1)Talk:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 +2 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Talk:Scene00005 ACTOR2:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](4)Talk:Scene00006 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 +2 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Talk:Scene00008 ACTOR3:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](7)Talk:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 +2 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
player.setQuestUI8CH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](10)Talk:Scene00011 ACTOR4:UI8CH=-2, 1", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](10)Talk:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00014( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 +2 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8CL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Talk:Scene00014 ACTOR5:UI8CL=-2, 1", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](13)Talk:Scene00015 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00017( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 +2 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR6
player.setQuestUI8DH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](16)Talk:Scene00017 ACTOR6:UI8DH=-2, 1", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](16)Talk:Scene00018 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00020( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 +2 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
player.setQuestUI8DL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](19)Talk:Scene00020 ACTOR7:UI8DL=-2, 1", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](19)Talk:Scene00021 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00023( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00022 +2 ", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
player.setQuestUI8EH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
}
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](22)Talk:Scene00023 ACTOR8:UI8EH=-2, 1", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](22)Talk:Scene00024 ", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00025 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsa103 );
