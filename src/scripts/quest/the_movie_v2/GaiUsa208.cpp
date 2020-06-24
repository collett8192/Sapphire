// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: True, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa208_00731
// Quest Name: Potsherds for Posterity
// Quest ID: 66267
// Start NPC: 1000439
// End NPC: 1000439

using namespace Sapphire;

class GaiUsa208 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL
    // GetQuestUI8BH
    // GetQuestUI8BL
    // GetQuestUI8CH
    // GetQuestUI8CL
    // GetQuestUI8DH
    // GetQuestUI8DL
    // GetQuestUI8EH
    // GetQuestUI8EL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000439;
//    static constexpr auto Eobject0 = 2000727;
//    static constexpr auto Eobject1 = 2000728;
//    static constexpr auto Eobject2 = 2000729;
//    static constexpr auto Eobject3 = 2001184;
//    static constexpr auto Eobject4 = 2001185;
//    static constexpr auto Eobject5 = 2001186;
//    static constexpr auto Eobject6 = 2001187;
//    static constexpr auto Eobject7 = 2001188;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000585;

  public:
    GaiUsa208() : Sapphire::ScriptAPI::EventScript( 66267 ){}; 
    ~GaiUsa208() = default; 

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
//EOBJECT0, UI8AL, 1, -2, False
if( actor == 2000727 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//EOBJECT1, UI8BH, 1, -2, False
if( actor == 2000728 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00004( player ); }
//EOBJECT2, UI8BL, 1, -2, False
if( actor == 2000729 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00006( player ); }
//EOBJECT3, UI8CH, 1, -2, False
if( actor == 2001184 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00008( player ); }
//EOBJECT4, UI8CL, 1, -2, False
if( actor == 2001185 && player.getQuestUI8CL( getId() ) != 1 ) { Scene00010( player ); }
//EOBJECT5, UI8DH, 1, -2, False
if( actor == 2001186 && player.getQuestUI8DH( getId() ) != 1 ) { Scene00012( player ); }
//EOBJECT6, UI8DL, 1, -2, False
if( actor == 2001187 && player.getQuestUI8DL( getId() ) != 1 ) { Scene00014( player ); }
//EOBJECT7, UI8EH, 1, -2, False
if( actor == 2001188 && player.getQuestUI8EH( getId() ) != 1 ) { Scene00016( player ); }
break;
}
case 255:{
Scene00018( player );
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
player.setQuestUI8EL( getId(), 8 );
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
player.sendDebug( "questId: {}, calling Empty:Scene00002 +1 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 8 );
}
}
}
}
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](2)Empty:Scene00003 EOBJECT0:UI8AL=-2, 1", getId() );


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


//Target: EOBJECT1
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 8 );
}
}
}
}
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](4)Empty:Scene00005 EOBJECT1:UI8BH=-2, 1", getId() );


  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 8 );
}
}
}
}
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](6)Empty:Scene00007 EOBJECT2:UI8BL=-2, 1", getId() );


  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00008 +1 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8CH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 8 );
}
}
}
}
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](8)Empty:Scene00009 EOBJECT3:UI8CH=-2, 1", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00011( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00010 +1 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8CL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 8 );
}
}
}
}
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](10)Empty:Scene00011 EOBJECT4:UI8CL=-2, 1", getId() );


  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00013( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00012 +1 ", getId() );

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {


//Target: EOBJECT5
player.setQuestUI8DH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 8 );
}
}
}
}
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](12)Empty:Scene00013 EOBJECT5:UI8DH=-2, 1", getId() );


  }

  void Scene00014( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00015( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00014 +1 ", getId() );

    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {


//Target: EOBJECT6
player.setQuestUI8DL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 8 );
}
}
}
}
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](14)Empty:Scene00015 EOBJECT6:UI8DL=-2, 1", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00017( player ); }
    };
player.sendDebug( "questId: {}, calling Empty:Scene00016 +1 ", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


//Target: EOBJECT7
player.setQuestUI8EH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
if( player.getQuestUI8DH( getId() ) == 1 ){
if( player.getQuestUI8DL( getId() ) == 1 ){
if( player.getQuestUI8EH( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.setQuestUI8DH( getId(), 0 );
player.setQuestUI8DL( getId(), 0 );
player.setQuestUI8EH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 8 );
}
}
}
}
}
}
}
}

player.sendDebug( "questId: {}, calling [sub:BranchTrue](16)Empty:Scene00017 EOBJECT7:UI8EH=-2, 1", getId() );


  }

  void Scene00018( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00019( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00018 +1 ", getId() );

    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](18)Talk, QuestReward, QuestComplete:Scene00019 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUsa208 );
