// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse107_01181
// Quest Name: Better Late than Sever
// Quest ID: 66717
// Start NPC: 1006544
// End NPC: 1006544

using namespace Sapphire;

class GaiUse107 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
    // GetQuestBitFlag8
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
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006544;
//    static constexpr auto Actor1 = 1007741;
//    static constexpr auto Actor2 = 1007742;
//    static constexpr auto Actor3 = 1007743;
//    static constexpr auto Actor4 = 1007744;
//    static constexpr auto Actor5 = 1007745;
//    static constexpr auto Actor6 = 1007746;
//    static constexpr auto Actor7 = 1007747;
//    static constexpr auto Actor8 = 1007748;
//    static constexpr auto Actor9 = 1007749;
//    static constexpr auto Eobject0 = 2002844;
//    static constexpr auto Eobject1 = 2002845;
//    static constexpr auto Eobject2 = 2002846;
//    static constexpr auto Eobject3 = 2002920;
//    static constexpr auto Eobject4 = 2002921;
//    static constexpr auto EventActionProcessMiddle = 16;
//    static constexpr auto EventActionRescueUnderMiddle = 35;

  public:
    GaiUse107() : Sapphire::ScriptAPI::EventScript( 66717 ){}; 
    ~GaiUse107() = default; 

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
if( actor == 1007741 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006544 ) { Scene00003( player ); }
break;
}
case 2:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1007742 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007743 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007744 ) { Scene00006( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007745 ) { Scene00007( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006544 ) { Scene00008( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007741 ) { Scene00009( player ); }
break;
}
case 3:{
//ACTOR6, UI8BH, 2, -1, False
if( actor == 1007746 && player.getQuestUI8BH( getId() ) != 2 ) { Scene00011( player ); }
//ACTOR7, UI8BH, 2, -1, False
if( actor == 1007747 && player.getQuestUI8BH( getId() ) != 2 ) { Scene00013( player ); }
//EOBJECT0, UI8BL, 3, -1, False
if( actor == 2002844 && player.getQuestUI8BL( getId() ) != 3 ) { Scene00014( player ); }
//EOBJECT1, UI8BL, 3, -1, False
if( actor == 2002845 && player.getQuestUI8BL( getId() ) != 3 ) { Scene00014( player ); }
//EOBJECT2, UI8BL, 3, -1, False
if( actor == 2002846 && player.getQuestUI8BL( getId() ) != 3 ) { Scene00014( player ); }
//ACTOR3, null, 0, -1, False
if( actor == 1007743 ) { Scene00020( player ); }
//ACTOR4, null, 0, -1, False
if( actor == 1007744 ) { Scene00021( player ); }
//ACTOR5, null, 0, -1, False
if( actor == 1007745 ) { Scene00022( player ); }
//ACTOR2, null, 0, -1, False
if( actor == 1007742 ) { Scene00023( player ); }
//ACTOR0, null, 0, -1, False
if( actor == 1006544 ) { Scene00024( player ); }
break;
}
case 4:{
//ACTOR8, UI8AL, 1, -2, False
if( actor == 1007748 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00025( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007743 ) { Scene00026( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007744 ) { Scene00027( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007745 ) { Scene00028( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1007742 ) { Scene00029( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002920 ) { Scene00030( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002921 ) { Scene00031( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1007749 ) { Scene00032( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006544 ) { Scene00033( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006544 ) { Scene00034( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007743 ) { Scene00035( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007744 ) { Scene00036( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007745 ) { Scene00037( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1007749 ) { Scene00038( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002920 ) { Scene00039( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002921 ) { Scene00040( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1007742 ) { Scene00041( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007748 ) { Scene00042( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
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
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR0", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00004 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR3", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR4", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR5", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00008 ACTOR0", getId() );

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


player.sendDebug( "questId: {}, calling Empty:Scene00010 ", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
      if( player.getQuestUI8BH( getId() ) == 2 )
      {
        if( player.getQuestUI8BL( getId() ) == 3 )
        {
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.updateQuest( getId(), 4 );
        }
      }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR8:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR3", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
      if( player.getQuestUI8BH( getId() ) == 2 )
      {
        if( player.getQuestUI8BL( getId() ) == 3 )
        {
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.updateQuest( getId(), 4 );
        }
      }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00013 ACTOR4", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
    if( player.getQuestUI8BH( getId() ) == 2 )
    {
      if( player.getQuestUI8BL( getId() ) == 3 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.updateQuest( getId(), 4 );
      }
    }

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR5", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR2", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00016 EOBJECT3", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00017 EOBJECT4", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR9", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR0", getId() );


  }

  void Scene00020( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00020 ", getId() );


  }

  void Scene00021( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00021 ", getId() );


  }

  void Scene00022( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00022 ", getId() );


  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00023 ", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00024 ", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00025 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00026 ", getId() );


  }

  void Scene00027( Entity::Player& player )
  {




player.sendDebug( "questId: {}, calling Empty:Scene00027 ", getId() );


  }

  void Scene00028( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00028 ", getId() );


  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00029 ", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00030 ", getId() );


  }

  void Scene00031( Entity::Player& player )
  {




player.sendDebug( "questId: {}, calling Empty:Scene00031 ", getId() );


  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {

    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00034 ACTOR0", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00035 ACTOR3", getId() );


  }

  void Scene00036( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00036 ACTOR4", getId() );


  }

  void Scene00037( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00037 ACTOR5", getId() );


  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00038 ACTOR9", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00039 EOBJECT3", getId() );


  }

  void Scene00040( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00040 EOBJECT4", getId() );


  }

  void Scene00041( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00041 ACTOR2", getId() );

    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00042 ACTOR8", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse107 );
