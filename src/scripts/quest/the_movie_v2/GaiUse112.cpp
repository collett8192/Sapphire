// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: -1
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse112_01186
// Quest Name: You're Gonna Carry That
// Quest ID: 66722
// Start NPC: 1006530
// End NPC: 1003785

using namespace Sapphire;

class GaiUse112 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006530;
//    static constexpr auto Actor1 = 1007722;
//    static constexpr auto Actor2 = 1003785;
//    static constexpr auto Eobject0 = 2002850;
//    static constexpr auto Eobject1 = 2002851;
//    static constexpr auto Eobject2 = 2002852;
//    static constexpr auto Eobject3 = 2002853;
//    static constexpr auto EventActionProcessUpperLong = 33;
//    static constexpr auto EventActionProcessUpperMiddle = 32;
//    static constexpr auto EventActionProcessUpperShort = 31;
//    static constexpr auto Item0 = 2001080;

  public:
    GaiUse112() : Sapphire::ScriptAPI::EventScript( 66722 ){}; 
    ~GaiUse112() = default; 

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
if( actor == 1007722 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006530 ) { Scene00003( player ); }
break;
}
case 2:{
//EOBJECT0, UI8BH, 4, -2, False
if( actor == 2002850 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00004( player ); }
//EOBJECT1, UI8BH, 4, -2, False
if( actor == 2002851 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00005( player ); }
//EOBJECT2, UI8BH, 4, -2, False
if( actor == 2002852 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00006( player ); }
//EOBJECT3, UI8BH, 4, -2, False
if( actor == 2002853 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00007( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1007722 ) { Scene00008( player ); }
break;
}
case 255:{
//ACTOR2, null, 0, -1, False
if( actor == 1003785 ) { Scene00013( player ); }
//if( actor == 1007722 ) { Scene?????( player ); }
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
player.setQuestUI8BL( getId(), 4 );
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


//Target: EOBJECT0
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT0:UI8BH=-2, 4", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT1:UI8BH=-2, 4", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT2:UI8BH=-2, 4", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 4 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT3:UI8BH=-2, 4", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: ACTOR1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 ACTOR1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 ", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 ", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 4 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 ", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BL( getId(), 4 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00012 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00014( player ); }
 else { Scene00015( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00013 +2 ", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](13)Talk, QuestReward, QuestComplete:Scene00014 ACTOR2", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](13)Talk:Scene00015 ", getId() );

    player.playScene( getId(), 15, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse112 );
