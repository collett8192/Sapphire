// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: True, S: False, R: False, DM: False, L: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubWil128_00642
// Quest Name: Dead Bodies Everywhere
// Quest ID: 66178
// Start NPC: 1003936
// End NPC: 1003936

using namespace Sapphire;

class SubWil128 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1003936;
//    static constexpr auto Eobject0 = 2001438;
//    static constexpr auto Eobject1 = 2001439;
//    static constexpr auto Eobject2 = 2001440;
//    static constexpr auto Eobject3 = 2001441;
//    static constexpr auto Eobject4 = 2001444;
//    static constexpr auto Eobject5 = 2001445;
//    static constexpr auto EventActionProcessShor = 15;
//    static constexpr auto Item0 = 2000406;

  public:
    SubWil128() : Sapphire::ScriptAPI::EventScript( 66178 ){}; 
    ~SubWil128() = default; 

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
//EOBJECT0, UI8AL, 6, -2, False
if( actor == 2001438 && player.getQuestUI8AL( getId() ) != 6 ) { Scene00001( player ); }
//EOBJECT1, UI8AL, 6, -2, False
if( actor == 2001439 && player.getQuestUI8AL( getId() ) != 6 ) { Scene00004( player ); }
//EOBJECT2, UI8AL, 6, -2, False
if( actor == 2001440 && player.getQuestUI8AL( getId() ) != 6 ) { Scene00007( player ); }
//EOBJECT3, UI8AL, 6, -2, False
if( actor == 2001441 && player.getQuestUI8AL( getId() ) != 6 ) { Scene00010( player ); }
//EOBJECT4, UI8AL, 6, -2, False
if( actor == 2001444 && player.getQuestUI8AL( getId() ) != 6 ) { Scene00013( player ); }
//EOBJECT5, UI8AL, 6, -2, False
if( actor == 2001445 && player.getQuestUI8AL( getId() ) != 6 ) { Scene00016( player ); }
break;
}
case 255:{
Scene00019( player );
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
player.setQuestUI8BH( getId(), 6 );
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
player.sendDebug( "questId: {}, calling Empty:Scene00001 +2 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](1)Empty:Scene00002 EOBJECT0:UI8AL=-2, 6", getId() );


  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](1)Empty:Scene00003 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00005( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00004 +2 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00005 EOBJECT1:UI8AL=-2, 6", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](4)Empty:Scene00006 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00007 +2 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Empty:Scene00008 EOBJECT2:UI8AL=-2, 6", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](7)Empty:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00010 +2 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](10)Empty:Scene00011 EOBJECT3:UI8AL=-2, 6", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](10)Empty:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00014( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00013 +2 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Empty:Scene00014 EOBJECT4:UI8AL=-2, 6", getId() );


  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](13)Empty:Scene00015 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00017( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00016 +2 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


//Target: EOBJECT5
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 6 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](16)Empty:Scene00017 EOBJECT5:UI8AL=-2, 6", getId() );


  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](16)Empty:Scene00018 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00020( player ); }
 else { Scene00021( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00019 +2 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](19)Talk, QuestReward, QuestComplete:Scene00020 ", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](19)Empty:Scene00021 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubWil128 );
