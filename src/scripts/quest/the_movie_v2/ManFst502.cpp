// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManFst502_01136
// Quest Name: Rock the Castrum
// Quest ID: 66672
// Start NPC: 1006657
// End NPC: 1006657

using namespace Sapphire;

class ManFst502 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006657;
//    static constexpr auto Actor2 = 1006662;
//    static constexpr auto Actor3 = 1006663;
//    static constexpr auto Actor4 = 1006664;
//    static constexpr auto Actor5 = 1006660;
//    static constexpr auto Actor6 = 1006661;
//    static constexpr auto Actor7 = 1007682;
//    static constexpr auto Actor8 = 1007683;
//    static constexpr auto ContentStart = 15;
//    static constexpr auto CutScene01 = 265;
//    static constexpr auto Instancedungeon0 = 15;
//    static constexpr auto Poprange0 = 4332876;
//    static constexpr auto UnlockAddNewContentToCf = 3702;
//    static constexpr auto UnlockImageDungeon = 98;

  public:
    ManFst502() : Sapphire::ScriptAPI::EventScript( 66672 ){}; 
    ~ManFst502() = default; 

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
//ACTOR2, null, 0, -2, False
if( actor == 1006662 ) { Scene00002( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006663 ) { Scene00003( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006664 ) { Scene00004( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1006660 ) { Scene00005( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1006661 ) { Scene00006( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1007682 ) { Scene00007( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007683 ) { Scene00008( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006657 ) { Scene00009( player ); }
break;
}
case 255:{
Scene00010( player );
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
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept, CutScene, Message:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00002 ACTOR2", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00003 ACTOR3", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR4", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR5", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR6", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR7
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR7", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR8", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR0", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00010 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

};

EXPOSE_SCRIPT( ManFst502 );
