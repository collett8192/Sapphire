// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse404_00057
// Quest Name: The Intercession of Saints
// Quest ID: 65593
// Start NPC: 1009976
// End NPC: 1009977

using namespace Sapphire;

class GaiUse404 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1009976;
//    static constexpr auto Actor1 = 1009978;
//    static constexpr auto Actor2 = 1006384;
//    static constexpr auto Actor3 = 1009977;
//    static constexpr auto Actor4 = 1006401;
//    static constexpr auto Actor5 = 1009979;
//    static constexpr auto Actor6 = 1009980;
//    static constexpr auto Actor7 = 1009981;
//    static constexpr auto Actor8 = 1009982;
//    static constexpr auto Actor9 = 1009983;
//    static constexpr auto Eobject0 = 2004647;
//    static constexpr auto Eobject1 = 2004648;
//    static constexpr auto LocActor0 = 5032467;
//    static constexpr auto LocActor1 = 5032468;
//    static constexpr auto LocActor2 = 4261335;
//    static constexpr auto LocActor3 = 1014660;
//    static constexpr auto LocMusic0 = 78;
//    static constexpr auto LocMusicNo = 1;

  public:
    GaiUse404() : Sapphire::ScriptAPI::EventScript( 65593 ){}; 
    ~GaiUse404() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1009976 ) { Scene00000( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009978 ) { Scene00002( player ); }
break;
}
case 1:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1006384 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009977 ) { Scene00004( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009978 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006401 ) { Scene00006( player ); }
break;
}
case 2:{
//ACTOR5, UI8AL, 1, -2, False
if( actor == 1009979 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00007( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009977 ) { Scene00008( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009978 ) { Scene00009( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009980 ) { Scene00010( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009981 ) { Scene00011( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004647 ) { Scene00012( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2004648 ) { Scene00013( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006384 ) { Scene00014( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006401 ) { Scene00015( player ); }
break;
}
case 3:{
//ACTOR8, UI8AL, 1, -2, False
if( actor == 1009982 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00016( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1009983 ) { Scene00017( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1009977 ) { Scene00018( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009978 ) { Scene00019( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1009979 ) { Scene00020( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1009980 ) { Scene00021( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1009981 ) { Scene00022( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2004647 ) { Scene00023( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2004648 ) { Scene00024( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006384 ) { Scene00025( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006401 ) { Scene00026( player ); }
break;
}
case 255:{
//ACTOR3, null, 0, -2, False
if( actor == 1009977 ) { Scene00027( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1009982 ) { Scene00028( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1009983 ) { Scene00029( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1009978 ) { Scene00030( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006384 ) { Scene00031( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1006401 ) { Scene00032( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ACTOR0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
    };
player.sendDebug( "questId: {}, calling Talk, FadeOut:Scene00003 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR3", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00005 ACTOR1", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR4", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00007 ACTOR5:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR3", getId() );

    player.playScene( getId(), 8, NONE, callback );
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


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR6", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR7", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 EOBJECT0", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 EOBJECT1", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00014 ACTOR2", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00015 ACTOR4", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR8:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR9", getId() );


  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00018 ACTOR3", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00019 ACTOR1", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00020 ACTOR5", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00021 ACTOR6", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR7", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00023 EOBJECT0", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00024 EOBJECT1", getId() );


  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ACTOR2", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR4", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete, FadeOut:Scene00027 ACTOR3", getId() );

    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00028 ACTOR8", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {


//Target: ACTOR9
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00029 ACTOR9", getId() );


  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 ACTOR1", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00031 ACTOR2", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ACTOR4", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse404 );
