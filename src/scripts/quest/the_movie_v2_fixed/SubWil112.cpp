// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubWil112_00620
// Quest Name: A Proper Burial
// Quest ID: 66156
// Start NPC: 1003929
// End NPC: 1003929

using namespace Sapphire;

class SubWil112 : public Sapphire::ScriptAPI::EventScript
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
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      Seq5 = 5,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1003929;
//    static constexpr auto Actor1 = 1005136;
//    static constexpr auto Actor2 = 1003968;
//    static constexpr auto Actor3 = 1003969;
//    static constexpr auto Eobject0 = 2001657;
//    static constexpr auto Eobject1 = 2001658;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000517;
//    static constexpr auto LocActor0 = 1005015;
//    static constexpr auto LocActor1 = 1003932;
//    static constexpr auto LocPosActor1 = 3967322;

  public:
    SubWil112() : Sapphire::ScriptAPI::EventScript( 66156 ){}; 
    ~SubWil112() = default; 

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
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2001657 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1005136 ) { Scene00004( player ); }
break;
}
case 3:{
//EOBJECT1, UI8AL, 1, -2, False
if( actor == 2001658 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00010( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1005136 ) { Scene00007( player ); }
//ACTOR2, null, 0, -2, False
//if( actor == 1003968 ) { Scene00010( player ); }
break;
}
case 4:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1005136 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00009( player ); }
//EOBJECT1, null, 0, -2, False
//if( actor == 2001658 ) { Scene00012( player ); }
break;
}
case 5:{
//ACTOR3, UI8AL, 1, -2, False
if( actor == 1003969 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00012( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1005136 ) { Scene00013( player ); }
//EOBJECT1, null, 0, -2, False
//if( actor == 2001658 ) { Scene00015( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1003929 ) { Scene00016( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1005136 ) { Scene00017( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1003969 ) { Scene00018( player ); }
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
player.setQuestUI8BH( getId(), 1 );
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
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00002 EOBJECT0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00003 ACTOR1", getId() );


  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 +2 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](4)Empty:Scene00005 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Empty:Scene00006 EOBJECT1:UI8AL=-2, 1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 +2 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](7)Empty:Scene00008 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
      player.setQuestUI8AL( getId(), 1 );
      if( player.getQuestUI8AL( getId() ) == 1 ){
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 5 );
        player.setQuestUI8BH( getId(), 1 );
      }

    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars
    { Scene00006( player ); }
player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR2", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR1

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
//does not modify quest vars
      player.setQuestUI8AL( getId(), 1 );
      if( player.getQuestUI8AL( getId() ) == 1 ){
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 1 );
      }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 EOBJECT1", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3

    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR3:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR1", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 EOBJECT1", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00016 ACTOR0", getId() );

    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00017 ACTOR1", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR3", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubWil112 );
