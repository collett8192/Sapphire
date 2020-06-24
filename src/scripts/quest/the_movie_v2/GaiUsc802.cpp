// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsc802_01026
// Quest Name: Pier Review
// Quest ID: 66562
// Start NPC: 1006614
// End NPC: 1006618

using namespace Sapphire;

class GaiUsc802 : public Sapphire::ScriptAPI::EventScript
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
//      Seq6 = 6,
//      Seq7 = 7,
//      Seq8 = 8,
//      Seq9 = 9,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006614;
//    static constexpr auto Actor1 = 1006618;
//    static constexpr auto Actor2 = 1006621;
//    static constexpr auto Actor3 = 1007713;
//    static constexpr auto Actor4 = 1007714;
//    static constexpr auto Eobject0 = 2002452;
//    static constexpr auto Eobject1 = 2002666;
//    static constexpr auto Eobject2 = 2002667;
//    static constexpr auto Eobject3 = 2002668;
//    static constexpr auto Eobject4 = 2002453;
//    static constexpr auto Eobject5 = 2002669;
//    static constexpr auto Eobject6 = 2002672;
//    static constexpr auto Eobject7 = 2002670;
//    static constexpr auto Eobject8 = 2002673;
//    static constexpr auto Eobject9 = 2002671;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000781;
//    static constexpr auto Item1 = 2000869;
//    static constexpr auto Item2 = 2000870;

  public:
    GaiUsc802() : Sapphire::ScriptAPI::EventScript( 66562 ){}; 
    ~GaiUsc802() = default; 

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
if( actor == 1006618 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006621 ) { Scene00003( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00004( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00005( player ); }
break;
}
case 2:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1006621 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00006( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00007( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00008( player ); }
break;
}
case 3:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002452 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00009( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006621 ) { Scene00010( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00011( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00012( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002666 ) { Scene00013( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002667 ) { Scene00014( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002668 ) { Scene00015( player ); }
break;
}
case 4:{
//EOBJECT4, UI8AL, 1, -2, False
if( actor == 2002453 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00016( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006621 ) { Scene00017( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00018( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00019( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002667 ) { Scene00020( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002668 ) { Scene00023( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002666 ) { Scene00024( player ); }
break;
}
case 5:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002452 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00025( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006621 ) { Scene00026( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00027( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00028( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002667 ) { Scene00029( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002668 ) { Scene00030( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002669 ) { Scene00031( player ); }
break;
}
case 6:{
//EOBJECT6, UI8AL, 1, -2, False
if( actor == 2002672 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00032( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006621 ) { Scene00033( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00034( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00035( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002668 ) { Scene00036( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002669 ) { Scene00037( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002667 ) { Scene00038( player ); }
break;
}
case 7:{
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2002452 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00039( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006621 ) { Scene00040( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00041( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00042( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002668 ) { Scene00045( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002669 ) { Scene00046( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002670 ) { Scene00047( player ); }
break;
}
case 8:{
//EOBJECT8, UI8AL, 1, -2, False
if( actor == 2002673 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00048( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006621 ) { Scene00049( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00050( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00051( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002669 ) { Scene00052( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002670 ) { Scene00053( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002668 ) { Scene00054( player ); }
break;
}
case 9:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1006621 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00055( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00056( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00057( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002669 ) { Scene00058( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002670 ) { Scene00059( player ); }
//EOBJECT9, null, 0, -2, False
if( actor == 2002671 ) { Scene00060( player ); }
break;
}
case 255:{
//ACTOR1, null, 0, -2, False
if( actor == 1006618 ) { Scene00084( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1006621 ) { Scene00085( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007713 ) { Scene00086( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007714 ) { Scene00087( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002669 ) { Scene00088( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002670 ) { Scene00089( player ); }
//EOBJECT9, null, 0, -2, False
if( actor == 2002671 ) { Scene00090( player ); }
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
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR2", getId() );

    player.playScene( getId(), 3, NONE, callback );
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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 6, NONE, callback );
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


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 4 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR2", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00011 ACTOR3", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR4", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00013 EOBJECT1", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00014 EOBJECT2", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00015 EOBJECT3", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 5 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00016 EOBJECT4:UI8AL=-2, 1", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00017 ACTOR2", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00018 ACTOR3", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00019 ACTOR4", getId() );


  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00021( player ); }
 else { Scene00022( player ); }
    };
player.sendDebug( "questId: {}, calling NpcTrade:Scene00020 +2 ", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:Execute](20)Empty:Scene00021 EOBJECT2", getId() );


  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](20)Talk:Scene00022 ", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00023 EOBJECT3", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00024 EOBJECT1", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 6 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00025 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00026 ACTOR2", getId() );


  }

  void Scene00027( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00027 ACTOR3", getId() );


  }

  void Scene00028( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00028 ACTOR4", getId() );


  }

  void Scene00029( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00029 EOBJECT2", getId() );


  }

  void Scene00030( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00030 EOBJECT3", getId() );


  }

  void Scene00031( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00031 EOBJECT5", getId() );


  }

  void Scene00032( Entity::Player& player )
  {


//Target: EOBJECT6
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 7 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00032 EOBJECT6:UI8AL=-2, 1", getId() );


  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00033 ACTOR2", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00034 ACTOR3", getId() );


  }

  void Scene00035( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00035 ACTOR4", getId() );


  }

  void Scene00036( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00036 EOBJECT3", getId() );


  }

  void Scene00037( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00037 EOBJECT5", getId() );


  }

  void Scene00038( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00038 EOBJECT2", getId() );


  }

  void Scene00039( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 8 );
player.setQuestUI8BH( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00039 EOBJECT0:UI8AL=-2, 1", getId() );


  }

  void Scene00040( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00040 ACTOR2", getId() );


  }

  void Scene00041( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00041 ACTOR3", getId() );


  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00043( player ); }
 else { Scene00044( player ); }
    };
player.sendDebug( "questId: {}, calling NpcTrade:Scene00042 +2 ", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:Execute](42)Empty:Scene00043 ACTOR4", getId() );


  }

  void Scene00044( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](42)Talk:Scene00044 ", getId() );

    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00045 EOBJECT3", getId() );


  }

  void Scene00046( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00046 EOBJECT5", getId() );


  }

  void Scene00047( Entity::Player& player )
  {


//Target: EOBJECT7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00047 EOBJECT7", getId() );


  }

  void Scene00048( Entity::Player& player )
  {


//Target: EOBJECT8
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 9 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00048 EOBJECT8:UI8AL=-2, 1", getId() );


  }

  void Scene00049( Entity::Player& player )
  {


//Target: ACTOR2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00049 ACTOR2", getId() );


  }

  void Scene00050( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00050 ACTOR3", getId() );


  }

  void Scene00051( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00051 ACTOR4", getId() );


  }

  void Scene00052( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00052 EOBJECT5", getId() );


  }

  void Scene00053( Entity::Player& player )
  {


//Target: EOBJECT7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00053 EOBJECT7", getId() );


  }

  void Scene00054( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00054 EOBJECT3", getId() );


  }

  void Scene00055( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00055 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00056 ACTOR3", getId() );


  }

  void Scene00057( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00057 ACTOR4", getId() );


  }

  void Scene00058( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00058 EOBJECT5", getId() );


  }

  void Scene00059( Entity::Player& player )
  {


//Target: EOBJECT7
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00059 EOBJECT7", getId() );


  }

  void Scene00060( Entity::Player& player )
  {


//Target: EOBJECT9
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00060 EOBJECT9", getId() );


  }

  void Scene00061( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00061 ", getId() );


  }

  void Scene00062( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00062 ", getId() );


  }

  void Scene00063( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00063 ", getId() );


  }

  void Scene00064( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00065( player ); }
 else { Scene00066( player ); }
    };
player.sendDebug( "questId: {}, calling NpcTrade:Scene00064 +2 ", getId() );

    player.playScene( getId(), 64, NONE, callback );
  }

  void Scene00065( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling [sub:Execute](64)Empty:Scene00065 ", getId() );


  }

  void Scene00066( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](64)Talk:Scene00066 ", getId() );

    player.playScene( getId(), 66, NONE, callback );
  }

  void Scene00067( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00067 ", getId() );


  }

  void Scene00068( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00068 ", getId() );


  }

  void Scene00069( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00069 ", getId() );


  }

  void Scene00070( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00070 ", getId() );


  }

  void Scene00071( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00071 ", getId() );


  }

  void Scene00072( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00072 ", getId() );


  }

  void Scene00073( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00073 ", getId() );


  }

  void Scene00074( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00074 ", getId() );


  }

  void Scene00075( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00075 ", getId() );

    player.playScene( getId(), 75, NONE, callback );
  }

  void Scene00076( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00076 ", getId() );


  }

  void Scene00077( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00077 ", getId() );


  }

  void Scene00078( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00078 ", getId() );


  }

  void Scene00079( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00079 ", getId() );


  }

  void Scene00080( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00080 ", getId() );


  }

  void Scene00081( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00081 ", getId() );


  }

  void Scene00082( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00082 ", getId() );


  }

  void Scene00083( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );

player.sendDebug( "questId: {}, calling Empty:Scene00083 ", getId() );


  }

  void Scene00084( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00084 ACTOR1", getId() );

    player.playScene( getId(), 84, NONE, callback );
  }

  void Scene00085( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00085 ACTOR2", getId() );

    player.playScene( getId(), 85, NONE, callback );
  }

  void Scene00086( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00086 ACTOR3", getId() );


  }

  void Scene00087( Entity::Player& player )
  {


//Target: ACTOR4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00087 ACTOR4", getId() );


  }

  void Scene00088( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00088 EOBJECT5", getId() );


  }

  void Scene00089( Entity::Player& player )
  {


//Target: EOBJECT7
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00089 EOBJECT7", getId() );


  }

  void Scene00090( Entity::Player& player )
  {


//Target: EOBJECT9
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00090 EOBJECT9", getId() );


  }

  void Scene00091( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00091 ", getId() );


  }

  void Scene00092( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00092 ", getId() );


  }

  void Scene00093( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00093 ", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsc802 );
