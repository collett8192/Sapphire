// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManWil302_00682
// Quest Name: The Company You Keep (Immortal Flames)
// Quest ID: 66218
// Start NPC: 1004883
// End NPC: 1002391

using namespace Sapphire;

class ManWil302 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH

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
//    static constexpr auto Actor0 = 1004883;
//    static constexpr auto Actor1 = 1002391;
//    static constexpr auto Actor2 = 1004884;
//    static constexpr auto Actor3 = 1004885;
//    static constexpr auto Actor4 = 1004887;
//    static constexpr auto Actor5 = 1004995;
//    static constexpr auto Actor6 = 1004996;
//    static constexpr auto Actor7 = 1004997;
//    static constexpr auto Eobject0 = 2001714;
//    static constexpr auto Eobject1 = 2001808;
//    static constexpr auto Eventrange0 = 4126799;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto LocActor0 = 1005106;
//    static constexpr auto Ncut0 = 219;
//    static constexpr auto Questbattle0 = 47;
//    static constexpr auto Territorytype0 = 278;

  public:
    ManWil302() : Sapphire::ScriptAPI::EventScript( 66218 ){}; 
    ~ManWil302() = default; 

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
if( actor == 1002391 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00001( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1004884 ) { Scene00002( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1004885 ) { Scene00003( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1004883 ) { Scene00004( player ); }
break;
}
case 2:{
player.sendUrgent( "This scene contains quest battle." );
player.sendUrgent( "If stuck in black loading screen, enter and exit \"/gpose\" to get rid of it." );
//ACTOR4, UI8AL, 1, -2, False
if( actor == 1004887 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1004995 ) { Scene00006( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1004996 ) { Scene00007( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1004997 ) { Scene00008( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1002391 ) { Scene00009( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1004883 ) { Scene00010( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1004884 ) { Scene00011( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1004885 ) { Scene00012( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001714 ) { Scene00013( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001808 ) { Scene00014( player ); }
break;
}
case 255:{
//ACTOR1, null, 0, -2, False
if( actor == 1002391 ) { Scene00018( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1004883 ) { Scene00019( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1004884 ) { Scene00020( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1004885 ) { Scene00021( player ); }
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
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept, YesNo:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00001 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR2", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR3", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR0", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
}
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00005 ACTOR4:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR5", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR6", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR7", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00009 ACTOR1", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00010 ACTOR0", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR2", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ACTOR3", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling QuestBattle, YesNo:Scene00013 EOBJECT0", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00014 EOBJECT1", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00015 ", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00016 ", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00017 ", getId() );


  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00018 ACTOR1", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR0", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR2", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00021 ACTOR3", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

};

EXPOSE_SCRIPT( ManWil302 );
