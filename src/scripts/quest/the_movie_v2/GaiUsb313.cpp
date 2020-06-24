// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: True, A3: False, S: True, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb313_00854
// Quest Name: A Final Ignominy
// Quest ID: 66390
// Start NPC: 1006266
// End NPC: 1006266

using namespace Sapphire;

class GaiUsb313 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
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
//      Seq2 = 2,
//      Seq3 = 3,
//      Seq4 = 4,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006266;
//    static constexpr auto Actor1 = 1006272;
//    static constexpr auto Eobject0 = 2002676;
//    static constexpr auto Eobject1 = 2002675;
//    static constexpr auto Eobject2 = 2002072;
//    static constexpr auto Eobject3 = 2002073;
//    static constexpr auto Eobject4 = 2002074;
//    static constexpr auto Eobject5 = 2002067;
//    static constexpr auto Eobject6 = 2002068;
//    static constexpr auto Eobject7 = 2002069;
//    static constexpr auto Eobject8 = 2002070;
//    static constexpr auto Eobject9 = 2002071;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000662;
//    static constexpr auto Item1 = 2000663;
//    static constexpr auto Item2 = 2000664;

  public:
    GaiUsb313() : Sapphire::ScriptAPI::EventScript( 66390 ){}; 
    ~GaiUsb313() = default; 

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
Scene00002( player );
break;
}
case 2:{
Scene00003( player );
break;
}
case 3:{
//EOBJECT1, UI8AL, 1, -1, False
if( actor == 2002675 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00005( player ); }
//EOBJECT2, null, 0, -1, False
if( actor == 2002072 ) { Scene00007( player ); }
//EOBJECT3, null, 0, -1, False
if( actor == 2002073 ) { Scene00009( player ); }
//EOBJECT4, null, 0, -1, False
if( actor == 2002074 ) { Scene00011( player ); }
break;
}
case 4:{
//EOBJECT5, UI8AL, 3, -2, False
if( actor == 2002067 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00013( player ); }
//EOBJECT6, UI8AL, 3, -2, False
if( actor == 2002068 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00015( player ); }
//EOBJECT7, UI8AL, 3, -2, False
if( actor == 2002069 && player.getQuestUI8AL( getId() ) != 3 ) { Scene00017( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002072 ) { Scene00019( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002073 ) { Scene00021( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002074 ) { Scene00023( player ); }
//EOBJECT8, null, 0, -2, False
if( actor == 2002070 ) { Scene00025( player ); }
//EOBJECT9, null, 0, -2, False
if( actor == 2002071 ) { Scene00027( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006266 ) { Scene00029( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002067 ) { Scene00030( player ); }
//EOBJECT6, null, 0, -2, False
if( actor == 2002068 ) { Scene00032( player ); }
//EOBJECT7, null, 0, -2, False
if( actor == 2002069 ) { Scene00034( player ); }
//EOBJECT8, null, 0, -2, False
if( actor == 2002070 ) { Scene00036( player ); }
//EOBJECT9, null, 0, -2, False
if( actor == 2002071 ) { Scene00038( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002072 ) { Scene00040( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2002073 ) { Scene00042( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002074 ) { Scene00044( player ); }
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
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 3 );
player.setQuestUI8CH( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 3 );
player.setQuestUI8CH( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00004( player ); }
    };
player.sendDebug( "questId: {}, calling NpcTrade:Scene00003 +1 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {


player.updateQuest( getId(), 3 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 2 );

player.sendDebug( "questId: {}, calling [sub:Execute](3)Empty:Scene00004 ", getId() );


  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00006( player ); }
    };
player.sendDebug( "questId: {}, calling NpcTrade:Scene00005 +1 ", getId() );

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

player.sendDebug( "questId: {}, calling [sub:Execute](5)Empty:Scene00006 EOBJECT1:UI8AL=-1, 1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00008( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00007 +1 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](7)Empty:Scene00008 EOBJECT2", getId() );


  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00010( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00009 +1 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](9)Empty:Scene00010 EOBJECT3", getId() );


  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00012( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00011 +1 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](11)Empty:Scene00012 EOBJECT4", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00014( player ); }
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00013 +1 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: EOBJECT5
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](13)Empty:Scene00014 EOBJECT5:UI8AL=-2, 3", getId() );


  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00016( player ); }
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00015 +1 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {


//Target: EOBJECT6
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](15)Empty:Scene00016 EOBJECT6:UI8AL=-2, 3", getId() );


  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00018( player ); }
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00017 +1 ", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {


//Target: EOBJECT7
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 3 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](17)Empty:Scene00018 EOBJECT7:UI8AL=-2, 3", getId() );


  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00020( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00019 +1 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](19)Empty:Scene00020 EOBJECT2", getId() );


  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00022( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00021 +1 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](21)Empty:Scene00022 EOBJECT3", getId() );


  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00024( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00023 +1 ", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](23)Empty:Scene00024 EOBJECT4", getId() );


  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00026( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00025 +1 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {


//Target: EOBJECT8
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](25)Empty:Scene00026 EOBJECT8", getId() );


  }

  void Scene00027( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00028( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00027 +1 ", getId() );

    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {


//Target: EOBJECT9
//does not modify quest vars

player.sendDebug( "questId: {}, calling [sub:BranchTrue](27)Empty:Scene00028 EOBJECT9", getId() );


  }

  void Scene00029( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00029 ACTOR0", getId() );

    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00031( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00030 +1 ", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](30)Empty:Scene00031 EOBJECT5", getId() );


  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00033( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00032 +1 ", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {


//Target: EOBJECT6
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](32)Empty:Scene00033 EOBJECT6", getId() );


  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00035( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00034 +1 ", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {


//Target: EOBJECT7
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](34)Empty:Scene00035 EOBJECT7", getId() );


  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00037( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00036 +1 ", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {


//Target: EOBJECT8
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](36)Empty:Scene00037 EOBJECT8", getId() );


  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00039( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00038 +1 ", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {


//Target: EOBJECT9
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](38)Empty:Scene00039 EOBJECT9", getId() );


  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00041( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00040 +1 ", getId() );

    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](40)Empty:Scene00041 EOBJECT2", getId() );


  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00043( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00042 +1 ", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](42)Empty:Scene00043 EOBJECT3", getId() );


  }

  void Scene00044( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00045( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00044 +1 ", getId() );

    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling [sub:BranchTrue](44)Empty:Scene00045 EOBJECT4", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb313 );
