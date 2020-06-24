// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManWil005_00550
// Quest Name: Underneath the Sultantree
// Quest ID: 66086
// Start NPC: 1003995
// End NPC: 1003995

using namespace Sapphire;

class ManWil005 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1003995;
//    static constexpr auto Actor1 = 1003996;
//    static constexpr auto Actor2 = 1003997;
//    static constexpr auto Actor20 = 1006171;
//    static constexpr auto Actor3 = 1003998;
//    static constexpr auto Actor30 = 1006167;
//    static constexpr auto Actor4 = 1003999;
//    static constexpr auto Actor40 = 1006168;
//    static constexpr auto Actor5 = 1004000;
//    static constexpr auto Actor50 = 1006169;
//    static constexpr auto Actor6 = 1004001;
//    static constexpr auto Actor60 = 1006170;
//    static constexpr auto CutScene02 = 141;
//    static constexpr auto CutScene03 = 56;
//    static constexpr auto CutScene04 = 142;
//    static constexpr auto Eobject0 = 2001853;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Questbattle0 = 37;
//    static constexpr auto Seq0Actor0Lq = 50;
//    static constexpr auto Territorytype0 = 270;
//    static constexpr auto Territorytype1 = 141;

  public:
    ManWil005() : Sapphire::ScriptAPI::EventScript( 66086 ){}; 
    ~ManWil005() = default; 

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
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1003996 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001853 ) { Scene00003( player ); }
break;
}
case 2:{
Scene00004( player );
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1003995 ) { Scene00006( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1003997 ) { Scene00007( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1003998 ) { Scene00008( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1003999 ) { Scene00009( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1004000 ) { Scene00010( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1004001 ) { Scene00011( player ); }
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
player.sendDebug( "questId: {}, calling Talk, QuestOffer:Scene00000 +1 ", getId() );

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
//Target: ACTOR1
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
Scene00004( player );
}
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestBattle, YesNo:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT0", getId() );


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
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](4)CutScene:Scene00005 ", getId() );

    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00006 ACTOR0", getId() );

    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR2", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR3", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR4", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR5", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR6
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR6", getId() );


  }

};

EXPOSE_SCRIPT( ManWil005 );
