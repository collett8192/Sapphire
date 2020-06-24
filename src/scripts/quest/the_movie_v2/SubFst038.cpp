// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst038_00175
// Quest Name: Surveying the Damage
// Quest ID: 65711
// Start NPC: 1000449
// End NPC: 1000685

using namespace Sapphire;

class SubFst038 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000449;
//    static constexpr auto Actor1 = 1000685;
//    static constexpr auto Eobject0 = 2000141;
//    static constexpr auto Eobject1 = 2000147;
//    static constexpr auto Eobject2 = 2000148;
//    static constexpr auto Eobject3 = 2000149;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000141;
//    static constexpr auto Item1 = 2000146;
//    static constexpr auto Item2 = 2000147;

  public:
    SubFst038() : Sapphire::ScriptAPI::EventScript( 65711 ){}; 
    ~SubFst038() = default; 

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
if( actor == 2000141 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00001( player ); }
//EOBJECT1, UI8BH, 2, -2, False
if( actor == 2000147 && player.getQuestUI8BH( getId() ) != 2 ) { Scene00002( player ); }
//EOBJECT2, UI8BH, 2, -2, False
if( actor == 2000148 && player.getQuestUI8BH( getId() ) != 2 ) { Scene00003( player ); }
//EOBJECT3, UI8BL, 1, -2, False
if( actor == 2000149 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00004( player ); }
break;
}
case 255:{
Scene00005( player );
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
player.setQuestUI8CH( getId(), 1 );
player.setQuestUI8CL( getId(), 2 );
player.setQuestUI8DH( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 2 );
player.setQuestUI8CH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00001 EOBJECT0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT1
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 2 );
player.setQuestUI8CH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00002 EOBJECT1:UI8BH=-2, 2", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT2
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 2 );
player.setQuestUI8CH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00003 EOBJECT2:UI8BH=-2, 2", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 2 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 2 );
player.setQuestUI8CH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling Unknown:Scene00004 EOBJECT3:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00092( player ); }
 else { Scene00091( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00005 +2 ", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00091( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](5)Empty:Scene00091 ", getId() );

    player.playScene( getId(), 91, NONE, callback );
  }

  void Scene00092( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](5)Talk, QuestReward, QuestComplete:Scene00092 ", getId() );

    player.playScene( getId(), 92, NONE, callback );
  }

  void Scene00093( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00093 ", getId() );


  }

  void Scene00094( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00094 ", getId() );


  }

  void Scene00095( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00095 ", getId() );


  }

  void Scene00096( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00096 ", getId() );


  }

  void Scene00097( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00097 ", getId() );


  }

  void Scene00098( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00098 ", getId() );


  }

  void Scene00099( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00099 ", getId() );


  }

  void Scene00100( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00100 ", getId() );


  }

};

EXPOSE_SCRIPT( SubFst038 );
