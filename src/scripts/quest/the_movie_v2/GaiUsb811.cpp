// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: True, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsb811_00920
// Quest Name: Thieves and Robbers
// Quest ID: 66456
// Start NPC: 1006438
// End NPC: 1006438

using namespace Sapphire;

class GaiUsb811 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006438;
//    static constexpr auto Actor1 = 1006718;
//    static constexpr auto Enemy0 = 4293195;
//    static constexpr auto Enemy1 = 4293196;
//    static constexpr auto Enemy2 = 4293197;
//    static constexpr auto Enemy3 = 4293198;
//    static constexpr auto Enemy4 = 4293199;
//    static constexpr auto Enemy5 = 4293200;
//    static constexpr auto Eobject0 = 2002620;
//    static constexpr auto Eobject1 = 2002621;
//    static constexpr auto Eobject2 = 2002622;
//    static constexpr auto Eobject3 = 2002153;
//    static constexpr auto Eobject4 = 2002154;
//    static constexpr auto Eobject5 = 2002155;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto EventActionSearchMiddle = 3;
//    static constexpr auto EventActionSearchShort = 2;

  public:
    GaiUsb811() : Sapphire::ScriptAPI::EventScript( 66456 ){}; 
    ~GaiUsb811() = default; 

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
if( actor == 1006718 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002620 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002621 ) { Scene00006( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002622 ) { Scene00007( player ); }
break;
}
case 2:{
//EOBJECT3, null, 0, -2, False
if( actor == 2002153 ) { Scene00008( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2002154 ) { Scene00009( player ); }
//ENEMY2, UI8BH, 2, -2, False
if( actorId == 4293197 && player.getQuestUI8BH( getId() ) != 2 ) { Scene00010( player ); }
//ENEMY3, UI8BH, 2, -2, False
if( actorId == 4293198 && player.getQuestUI8BH( getId() ) != 2 ) { Scene00014( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2002155 ) { Scene00016( player ); }
//ENEMY4, UI8BL, 2, -2, False
if( actorId == 4293199 && player.getQuestUI8BL( getId() ) != 2 ) { Scene00019( player ); }
//ENEMY5, UI8BL, 2, -2, False
if( actorId == 4293200 && player.getQuestUI8BL( getId() ) != 2 ) { Scene00020( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006718 ) { Scene00021( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002620 ) { Scene00022( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002621 ) { Scene00023( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002622 ) { Scene00026( player ); }
break;
}
case 3:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1006718 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00027( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002620 ) { Scene00028( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002621 ) { Scene00029( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002622 ) { Scene00030( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1006438 ) { Scene00031( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1006718 ) { Scene00032( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2002620 ) { Scene00033( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2002621 ) { Scene00034( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2002622 ) { Scene00035( player ); }
break;
}
default: { player.sendUrgent( "seq {} not defined.", player.getQuestSeq( getId() ) ); break; }
}
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
//    switch( npcId )
//    {
//      case Enemy0: { break; }
//      case Enemy1: { break; }
//      case Enemy2: { break; }
//      case Enemy3: { break; }
//      case Enemy4: { break; }
//      case Enemy5: { break; }
//    }
onTalk( getId(), player, npcId );
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
{ Scene00003( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00002 +2 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
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
player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Talk:Scene00003 ACTOR1:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](2)Talk:Scene00004 ", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT0", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT2", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT3", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT4", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


//Target: ENEMY2
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00010 ENEMY2:UI8BH=-2, 2", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](12)Empty:Scene00011 ", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ENEMY3
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](14)Message:Scene00012 +2 ENEMY3:UI8BH=-2, 2", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](12)Empty:Scene00013 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00014 +2 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](14)Empty:Scene00015 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00017( player ); }
    };
player.sendDebug( "questId: {}, calling Message:Scene00016 +2 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT5
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](16)Talk:Scene00017 EOBJECT5", getId() );

    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](16)Empty:Scene00018 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {


//Target: ENEMY4
player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00019 ENEMY4:UI8BL=-2, 2", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


//Target: ENEMY5
player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 2 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 3 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00020 ENEMY5:UI8BL=-2, 2", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


//Target: ACTOR1
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00021 ACTOR1", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00022 EOBJECT0", getId() );


  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00024( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00023 +2 ", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
//no valid quest var detected
player.updateQuest( getId(), 3 );
    };
player.sendDebug( "questId: {}, calling [sub:BranchTrue](23)Talk:Scene00024 EOBJECT1", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//not used because scene condition is not parsed
    };
player.sendDebug( "questId: {}, calling [sub:BranchFalse](23)Empty:Scene00025 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
player.updateQuest( getId(), 3 );

player.sendDebug( "questId: {}, calling Empty:Scene00026 EOBJECT2", getId() );


  }

  void Scene00027( Entity::Player& player )
  {


//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00027 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00028( Entity::Player& player )
  {


//Target: EOBJECT0
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00028 EOBJECT0", getId() );


  }

  void Scene00029( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00029 EOBJECT1", getId() );


  }

  void Scene00030( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00030 EOBJECT2", getId() );


  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00031 ACTOR0", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00032 ACTOR1", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00033 EOBJECT0", getId() );


  }

  void Scene00034( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00034 EOBJECT1", getId() );


  }

  void Scene00035( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00035 EOBJECT2", getId() );


  }

  void Scene00036( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00036 ", getId() );


  }

  void Scene00037( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00037 ", getId() );


  }

  void Scene00038( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00038 ", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsb811 );
