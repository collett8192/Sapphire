// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb507_00876
// Quest Name: Bringing out the Dead
// Quest ID: 66412
// Start NPC: 1003958
// End NPC: 1003958

using namespace Sapphire;

class GaiUsb507 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag16
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH
    // GetQuestUI8CL
    // GetQuestUI8DH

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
//    static constexpr auto Actor0 = 1003958;
//    static constexpr auto Actor1 = 1006361;
//    static constexpr auto Actor10 = 1006345;
//    static constexpr auto Actor11 = 1006346;
//    static constexpr auto Actor12 = 1006347;
//    static constexpr auto Actor13 = 1006348;
//    static constexpr auto Actor14 = 1007587;
//    static constexpr auto Actor15 = 1007588;
//    static constexpr auto Actor16 = 1007589;
//    static constexpr auto Actor17 = 1006362;
//    static constexpr auto Actor18 = 1006349;
//    static constexpr auto Actor19 = 1006344;
//    static constexpr auto Actor2 = 1006353;
//    static constexpr auto Actor20 = 1007591;
//    static constexpr auto Actor21 = 1007592;
//    static constexpr auto Actor22 = 1007593;
//    static constexpr auto Actor23 = 1007594;
//    static constexpr auto Actor24 = 1006350;
//    static constexpr auto Actor25 = 1006351;
//    static constexpr auto Actor26 = 1007590;
//    static constexpr auto Actor27 = 1007595;
//    static constexpr auto Actor28 = 1007596;
//    static constexpr auto Actor29 = 1007597;
//    static constexpr auto Actor3 = 1006354;
//    static constexpr auto Actor4 = 1007586;
//    static constexpr auto Actor5 = 1007599;
//    static constexpr auto Actor6 = 1007600;
//    static constexpr auto Actor7 = 1007601;
//    static constexpr auto Actor8 = 1007618;
//    static constexpr auto Actor9 = 1007619;
//    static constexpr auto EventActionProcessLong = 17;
//    static constexpr auto EventActionProcessMiddle = 16;
//    static constexpr auto EventActionProcessShor = 15;
//    static constexpr auto Item0 = 2000685;
//    static constexpr auto Item1 = 2001067;
//    static constexpr auto Item2 = 2000686;

  public:
    GaiUsb507() : Sapphire::ScriptAPI::EventScript( 66412 ){}; 
    ~GaiUsb507() = default; 

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
if( actor == 1006361 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006353 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1006354 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007586 ) { Scene00005( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1007599 ) { Scene00006( player ); }
//ACTOR6, null, 0, -2, False
if( actor == 1007600 ) { Scene00007( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1007601 ) { Scene00008( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007618 ) { Scene00009( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1007619 ) { Scene00010( player ); }
break;
}
case 2:{
//ACTOR10, UI8AL, 4, -2, False
if( actor == 1006345 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00011( player ); }
//ACTOR11, UI8AL, 4, -2, False
if( actor == 1006346 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00012( player ); }
//ACTOR12, UI8AL, 4, -2, False
if( actor == 1006347 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00013( player ); }
//ACTOR13, UI8AL, 4, -2, False
if( actor == 1006348 && player.getQuestUI8AL( getId() ) != 4 ) { Scene00014( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006353 ) { Scene00015( player ); }
//ACTOR7, null, 0, -2, False
if( actor == 1007601 ) { Scene00016( player ); }
//ACTOR8, null, 0, -2, False
if( actor == 1007618 ) { Scene00017( player ); }
//ACTOR9, null, 0, -2, False
if( actor == 1007619 ) { Scene00018( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1007587 ) { Scene00019( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1007588 ) { Scene00020( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1007589 ) { Scene00021( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1006362 ) { Scene00026( player ); }
break;
}
case 3:{
//ACTOR17, UI8AL, 1, -2, False
if( actor == 1006362 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00027( player ); }
//ACTOR2, null, 0, -2, False
//if( actor == 1006353 ) { Scene00024( player ); }
//ACTOR7, null, 0, -2, False
//if( actor == 1007601 ) { Scene00025( player ); }
//ACTOR8, null, 0, -2, False
//if( actor == 1007618 ) { Scene00026( player ); }
//ACTOR9, null, 0, -2, False
//if( actor == 1007619 ) { Scene00027( player ); }
//ACTOR14, null, 0, -2, False
//if( actor == 1007587 ) { Scene00030( player ); }
//ACTOR15, null, 0, -2, False
//if( actor == 1007588 ) { Scene00031( player ); }
//ACTOR16, null, 0, -2, False
//if( actor == 1007589 ) { Scene00032( player ); }
break;
}
case 4:{
//ACTOR18, UI8AL, 1, -2, False
if( actor == 1006349 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00033( player ); }
//ACTOR19, UI8BH, 1, -2, False
if( actor == 1006344 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00034( player ); }
//ACTOR20, null, 0, -2, False
if( actor == 1007591 ) { Scene00035( player ); }
//ACTOR21, null, 0, -2, False
if( actor == 1007592 ) { Scene00036( player ); }
//ACTOR22, null, 0, -2, False
if( actor == 1007593 ) { Scene00037( player ); }
//ACTOR23, null, 0, -2, False
if( actor == 1007594 ) { Scene00038( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1007587 ) { Scene00039( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1007588 ) { Scene00040( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1007589 ) { Scene00041( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1006362 ) { Scene00047( player ); }
//ACTOR24, UI8BL, 1, -2, False
if( actor == 1006350 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00043( player ); }
//ACTOR25, UI8CH, 1, -2, False
if( actor == 1006351 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00044( player ); }
break;
}
case 5:{
//ACTOR17, UI8AL, 1, -2, False
if( actor == 1006362 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00052( player ); }
//ACTOR20, null, 0, -2, False
//if( actor == 1007591 ) { Scene00046( player ); }
//ACTOR21, null, 0, -2, False
//if( actor == 1007592 ) { Scene00047( player ); }
//ACTOR22, null, 0, -2, False
//if( actor == 1007593 ) { Scene00048( player ); }
//ACTOR23, null, 0, -2, False
//if( actor == 1007594 ) { Scene00049( player ); }
//ACTOR14, null, 0, -2, False
//if( actor == 1007587 ) { Scene00050( player ); }
//ACTOR15, null, 0, -2, False
//if( actor == 1007588 ) { Scene00051( player ); }
//ACTOR16, null, 0, -2, False
//if( actor == 1007589 ) { Scene00052( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1003958 ) { Scene00061( player ); }
//ACTOR26, null, 0, -2, False
if( actor == 1007590 ) { Scene00062( player ); }
//ACTOR20, null, 0, -2, False
if( actor == 1007591 ) { Scene00063( player ); }
//ACTOR21, null, 0, -2, False
if( actor == 1007592 ) { Scene00064( player ); }
//ACTOR22, null, 0, -2, False
if( actor == 1007593 ) { Scene00065( player ); }
//ACTOR23, null, 0, -2, False
if( actor == 1007594 ) { Scene00066( player ); }
//ACTOR27, null, 0, -2, False
if( actor == 1007595 ) { Scene00067( player ); }
//ACTOR28, null, 0, -2, False
if( actor == 1007596 ) { Scene00068( player ); }
//ACTOR29, null, 0, -2, False
if( actor == 1007597 ) { Scene00069( player ); }
//ACTOR14, null, 0, -2, False
if( actor == 1007587 ) { Scene00070( player ); }
//ACTOR15, null, 0, -2, False
if( actor == 1007588 ) { Scene00071( player ); }
//ACTOR16, null, 0, -2, False
if( actor == 1007589 ) { Scene00072( player ); }
//ACTOR17, null, 0, -2, False
if( actor == 1006362 ) { Scene00073( player ); }
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
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept:Scene00001 ", getId() );

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
player.setQuestUI8BH( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00003 ACTOR2", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR3", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR4", getId() );


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


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 ACTOR8", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR9", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR10
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR10:UI8AL=-2, 4", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR11
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR11:UI8AL=-2, 4", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: ACTOR12
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00013 ACTOR12:UI8AL=-2, 4", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR13
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 4 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR13:UI8AL=-2, 4", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR2", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00016 ACTOR7", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR8
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR8", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR9", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR14
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR14", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//Target: ACTOR15
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00020 ACTOR15", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


//Target: ACTOR16
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00021 ACTOR16", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: ACTOR17
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00022 ACTOR17", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: ACTOR17
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8CL( getId(), 1 );
player.setQuestUI8DH( getId(), 3 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00023 ACTOR17:UI8AL=-2, 1", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00024 ACTOR2", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


//Target: ACTOR7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00025 ACTOR7", getId() );


  }

  void Scene00026( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR8
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00026 ACTOR8", getId() );

    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00028( player ); }
 else { Scene00029( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00027 +2 ", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR9
//does not modify quest vars
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.setQuestUI8CH( getId(), 0 );
      player.updateQuest( getId(), 4 );
      player.setQuestUI8CL( getId(), 1 );
      player.setQuestUI8DH( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](27)Talk:Scene00028 ACTOR9", getId() );

    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](27)Empty:Scene00029 ", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {


//Target: ACTOR14
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00030 ACTOR14", getId() );


  }

  void Scene00031( Entity::Player& player )
  {


//Target: ACTOR15
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00031 ACTOR15", getId() );


  }

  void Scene00032( Entity::Player& player )
  {


//Target: ACTOR16
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00032 ACTOR16", getId() );


  }

  void Scene00033( Entity::Player& player )
  {


//Target: ACTOR18
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 5 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 3 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00033 ACTOR18:UI8AL=-2, 1", getId() );


  }

  void Scene00034( Entity::Player& player )
  {


//Target: ACTOR19
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 5 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 3 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00034 ACTOR19:UI8BH=-2, 1", getId() );


  }

  void Scene00035( Entity::Player& player )
  {


//Target: ACTOR20
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00035 ACTOR20", getId() );


  }

  void Scene00036( Entity::Player& player )
  {


//Target: ACTOR21
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00036 ACTOR21", getId() );


  }

  void Scene00037( Entity::Player& player )
  {


//Target: ACTOR22
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00037 ACTOR22", getId() );


  }

  void Scene00038( Entity::Player& player )
  {


//Target: ACTOR23
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00038 ACTOR23", getId() );


  }

  void Scene00039( Entity::Player& player )
  {


//Target: ACTOR14
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00039 ACTOR14", getId() );


  }

  void Scene00040( Entity::Player& player )
  {


//Target: ACTOR15
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00040 ACTOR15", getId() );


  }

  void Scene00041( Entity::Player& player )
  {


//Target: ACTOR16
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00041 ACTOR16", getId() );


  }

  void Scene00042( Entity::Player& player )
  {


//Target: ACTOR17
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00042 ACTOR17", getId() );


  }

  void Scene00043( Entity::Player& player )
  {


//Target: ACTOR24
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 5 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 3 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00043 ACTOR24:UI8BL=-2, 1", getId() );


  }

  void Scene00044( Entity::Player& player )
  {


//Target: ACTOR25
player.setQuestUI8CH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.updateQuest( getId(), 5 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 3 );
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00044 ACTOR25:UI8CH=-2, 1", getId() );


  }

  void Scene00045( Entity::Player& player )
  {


//Target: ACTOR17
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00045 ACTOR17:UI8AL=-2, 1", getId() );


  }

  void Scene00046( Entity::Player& player )
  {


//Target: ACTOR20
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00046 ACTOR20", getId() );


  }

  void Scene00047( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR21
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00047 ACTOR21", getId() );

    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {


//Target: ACTOR22
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00048 ACTOR22", getId() );


  }

  void Scene00049( Entity::Player& player )
  {


//Target: ACTOR23
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00049 ACTOR23", getId() );


  }

  void Scene00050( Entity::Player& player )
  {


//Target: ACTOR14
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00050 ACTOR14", getId() );


  }

  void Scene00051( Entity::Player& player )
  {


//Target: ACTOR15
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00051 ACTOR15", getId() );


  }

  void Scene00052( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00053( player ); }
 else { Scene00054( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00052 +2 ", getId() );

    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR16
//does not modify quest vars
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](52)Talk:Scene00053 ACTOR16", getId() );

    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](52)Empty:Scene00054 ", getId() );

    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00055 ", getId() );


  }

  void Scene00056( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00056 ", getId() );


  }

  void Scene00057( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00057 ", getId() );


  }

  void Scene00058( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00058 ", getId() );


  }

  void Scene00059( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00059 ", getId() );


  }

  void Scene00060( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00060 ", getId() );


  }

  void Scene00061( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00061 ACTOR0", getId() );

    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {


//Target: ACTOR26
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00062 ACTOR26", getId() );


  }

  void Scene00063( Entity::Player& player )
  {


//Target: ACTOR20
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00063 ACTOR20", getId() );


  }

  void Scene00064( Entity::Player& player )
  {


//Target: ACTOR21
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00064 ACTOR21", getId() );


  }

  void Scene00065( Entity::Player& player )
  {


//Target: ACTOR22
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00065 ACTOR22", getId() );


  }

  void Scene00066( Entity::Player& player )
  {


//Target: ACTOR23
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00066 ACTOR23", getId() );


  }

  void Scene00067( Entity::Player& player )
  {


//Target: ACTOR27
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00067 ACTOR27", getId() );


  }

  void Scene00068( Entity::Player& player )
  {


//Target: ACTOR28
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00068 ACTOR28", getId() );


  }

  void Scene00069( Entity::Player& player )
  {


//Target: ACTOR29
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00069 ACTOR29", getId() );


  }

  void Scene00070( Entity::Player& player )
  {


//Target: ACTOR14
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00070 ACTOR14", getId() );


  }

  void Scene00071( Entity::Player& player )
  {


//Target: ACTOR15
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00071 ACTOR15", getId() );


  }

  void Scene00072( Entity::Player& player )
  {


//Target: ACTOR16
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00072 ACTOR16", getId() );


  }

  void Scene00073( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR17
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00073 ACTOR17", getId() );

    player.playScene( getId(), 73, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsb507 );
