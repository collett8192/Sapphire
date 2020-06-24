// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb406_00862
// Quest Name: Deduce, Reuse, Recycle
// Quest ID: 66398
// Start NPC: 1006331
// End NPC: 1006331

using namespace Sapphire;

class GaiUsb406 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006331;
//    static constexpr auto Actor1 = 1007542;
//    static constexpr auto Actor2 = 1007543;
//    static constexpr auto Actor3 = 1007544;
//    static constexpr auto Actor4 = 1007545;
//    static constexpr auto Actor5 = 1007546;
//    static constexpr auto Actor6 = 1007547;
//    static constexpr auto Eobject0 = 2002341;
//    static constexpr auto Eobject1 = 2002342;
//    static constexpr auto Eobject2 = 2002343;
//    static constexpr auto Eobject3 = 2002338;
//    static constexpr auto Eobject4 = 2002339;
//    static constexpr auto Eobject5 = 2002340;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000669;
//    static constexpr auto Item1 = 2000929;

  public:
    GaiUsb406() : Sapphire::ScriptAPI::EventScript( 66398 ){}; 
    ~GaiUsb406() = default; 

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
//EOBJECT0, UI8AL, 3, -2, False
if( actor == 2002341 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00002( player ); }
//EOBJECT1, UI8AL, 3, -2, False
if( actor == 2002342 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00003( player ); }
//EOBJECT2, UI8AL, 3, -2, False
if( actor == 2002343 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00004( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007542 ) { Scene00005( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1007543 ) { Scene00006( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007544 ) { Scene00007( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007545 ) { Scene00008( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007546 ) { Scene00009( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1007547 ) { Scene00010( player ); }
//EOBJECT3, UI8BH, 3, -2, False
if( actor == 2002338 && player.getQuestUI8BH( getId() ) != 3 ) { Scene00011( player ); }
//EOBJECT4, UI8BH, 3, -2, False
if( actor == 2002339 && player.getQuestUI8BH( getId() ) != 3 ) { Scene00012( player ); }
//EOBJECT5, UI8BH, 3, -2, False
if( actor == 2002340 && player.getQuestUI8BH( getId() ) != 3 ) { Scene00013( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -1, False
if( actor == 1006331 ) { Scene00020( player ); }
//ACTOR1, null, 0, -1, False
if( actor == 1007542 ) { Scene00023( player ); }
//ACTOR2, null, 0, -1, False
if( actor == 1007543 ) { Scene00024( player ); }
//ACTOR3, null, 0, -1, False
if( actor == 1007544 ) { Scene00025( player ); }
//ACTOR4, null, 0, -1, False
if( actor == 1007545 ) { Scene00026( player ); }
//ACTOR5, null, 0, -1, False
if( actor == 1007546 ) { Scene00027( player ); }
//if( actor == 1007547 ) { Scene?????( player ); }
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
player.setQuestUI8BL( getId(), 3 );
player.setQuestUI8CH( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
if( player.getQuestUI8BH( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00002 EOBJECT0:UI8AL=-2, 3", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
if( player.getQuestUI8BH( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT1:UI8AL=-2, 3", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
if( player.getQuestUI8BH( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT2:UI8AL=-2, 3", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR2", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 ACTOR3", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR4", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: ACTOR5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR5", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR6", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
if( player.getQuestUI8BH( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00011 EOBJECT3:UI8BH=-2, 3", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
if( player.getQuestUI8BH( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00012 EOBJECT4:UI8BH=-2, 3", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT5
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
if( player.getQuestUI8BH( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00013 EOBJECT5:UI8BH=-2, 3", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00014 ", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00015 ", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00016 ", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00017 ", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00018 ", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 3 );
player.setQuestUI8BL( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00019 ", getId() );


  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00021( player ); }
 else { Scene00022( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00020 +2 ", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](20)Talk, QuestReward, QuestComplete:Scene00021 ACTOR0", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](20)Empty:Scene00022 ", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR1", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00024 ACTOR2", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR3", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00026 ACTOR4", getId() );


  }

  void Scene00027( Entity::Player& player )
  {


//Target: ACTOR5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00027 ACTOR5", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb406 );
