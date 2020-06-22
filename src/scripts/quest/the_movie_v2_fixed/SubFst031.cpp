// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst031_00125
// Quest Name: A Soldier's Breakfast
// Quest ID: 65661
// Start NPC: 1000685
// End NPC: 1000408

using namespace Sapphire;

class SubFst031 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1000685;
//    static constexpr auto Actor1 = 1000408;
//    static constexpr auto Enemy0 = 142;
//    static constexpr auto Eobject0 = 2000010;
//    static constexpr auto Eobject1 = 2000011;
//    static constexpr auto Eobject2 = 2000012;
//    static constexpr auto Eobject3 = 2000013;
//    static constexpr auto Eobject4 = 2000014;
//    static constexpr auto Eobject5 = 2000150;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000071;

  public:
    SubFst031() : Sapphire::ScriptAPI::EventScript( 65661 ){}; 
    ~SubFst031() = default; 

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
//EOBJECT0, UI8BH, 4, -2, False
if( actorId == 4296417417 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00001( player ); }
//EOBJECT1, UI8BH, 4, -2, False
if( actorId == 4296417418 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00002( player ); }
//EOBJECT2, UI8BH, 4, -2, False
if( actorId == 4296417419 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00003( player ); }
//EOBJECT3, UI8BH, 4, -2, False
if( actorId == 4296417420 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00004( player ); }
//EOBJECT4, UI8BH, 4, -2, False
if( actorId == 4296417421 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00005( player ); }
//EOBJECT5, UI8BH, 4, -2, False
if( actorId == 4297617284 && player.getQuestUI8BH( getId() ) != 4 ) { Scene00006( player ); }
//ENEMY0, UI8AL, 6, -2, False
if( actorId == 120 && player.getQuestUI8AL( getId() ) != 6 ) { Scene00007( player ); }
break;
}
case 2:{
//no scene is assigned
break;
}
case 255:{
Scene00008( player );
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
if( result.param2 == 1 ){
player.updateQuest( getId(), 1 );
player.setQuestUI8BL( getId(), 4 );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00001 EOBJECT0:UI8BH=-2, 4", getId() );


  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00002 EOBJECT1:UI8BH=-2, 4", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT2:UI8BH=-2, 4", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT3
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT3:UI8BH=-2, 4", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT4:UI8BH=-2, 4", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT5
player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT5:UI8BH=-2, 4", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    //auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    //{
//Target: ENEMY0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8BH( getId() ) == 4 ){
if( player.getQuestUI8AL( getId() ) == 6 ){
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 4 );
}
}
    //};
player.sendDebug( "questId: {}, calling Talk:Scene00007 ENEMY0:UI8AL=-2, 6", getId() );

    //player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00088( player ); }
 else { Scene00087( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00008 +2 ", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00087( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](8)Empty:Scene00087 ", getId() );

    player.playScene( getId(), 87, NONE, callback );
  }

  void Scene00088( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](8)QuestReward, QuestComplete:Scene00088 ", getId() );

    player.playScene( getId(), 88, NONE, callback );
  }

  void Scene00089( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00089 ", getId() );


  }

  void Scene00090( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00090 ", getId() );


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

EXPOSE_SCRIPT( SubFst031 );
