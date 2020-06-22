// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst073_00387
// Quest Name: Salvaging the Scene
// Quest ID: 65923
// Start NPC: 1000503
// End NPC: 1000470

using namespace Sapphire;

class SubFst073 : public Sapphire::ScriptAPI::EventScript
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
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1000503;
//    static constexpr auto Actor1 = 1000470;
//    static constexpr auto Enemy0 = 3842567;
//    static constexpr auto Eobject0 = 2001016;
//    static constexpr auto Eobject1 = 2001018;
//    static constexpr auto Eobject2 = 2001017;
//    static constexpr auto Eobject3 = 2001086;
//    static constexpr auto Eobject4 = 2001087;
//    static constexpr auto Eobject5 = 2001088;
//    static constexpr auto Eobject6 = 2001845;
//    static constexpr auto Eventrange0 = 3842570;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000237;

  public:
    SubFst073() : Sapphire::ScriptAPI::EventScript( 65923 ){}; 
    ~SubFst073() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
void onWithinRange( Sapphire::Entity::Player& player, uint32_t eventId, uint32_t param1,float x, float y, float z ) override
{
switch( player.getQuestSeq( getId() ) ){
case 1:{
Scene00022( player );
break;
}
case 255:{
//Scene00023( player );
break;
}
}
}
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
//EOBJECT0, UI8AL, 2, -2, False
if( actor == 2001016 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00002( player ); }
//EOBJECT1, UI8AL, 2, -2, False
if( actor == 2001018 && player.getQuestUI8AL( getId() ) != 2 ) { Scene00003( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001017 ) { Scene00004( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001086 ) { Scene00005( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2001087 ) { Scene00006( player ); }
//EOBJECT5, null, 0, -2, False
if( actor == 2001088 ) { Scene00007( player ); }
//EOBJECT6, null, 0, -2, False
if( actor == 2001845 ) { Scene00008( player ); }
break;
}
case 255:{
//ACTOR1, null, 0, -1, False
if( actor == 1000470 ) { Scene00023( player ); }
//EOBJECT2, null, 0, -1, False
if( actor == 2001017 ) { Scene00026( player ); }
//EOBJECT3, null, 0, -1, False
if( actor == 2001086 ) { Scene00027( player ); }
//EOBJECT4, null, 0, -1, False
if( actor == 2001087 ) { Scene00028( player ); }
//EOBJECT5, null, 0, -1, False
if( actor == 2001088 ) { Scene00029( player ); }
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
player.setQuestUI8BH( getId(), 2 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)Talk, QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT0
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 2 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00002 EOBJECT0:UI8AL=-2, 2", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 2 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT1:UI8AL=-2, 2", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00004 EOBJECT2", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT3", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00006 EOBJECT4", getId() );


  }

  void Scene00007( Entity::Player& player )
  {


//Target: EOBJECT5
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00007 EOBJECT5", getId() );


  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT6
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT6", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00009 ", getId() );


  }

  void Scene00010( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00010 ", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00011 ", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00012 ", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00013 ", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00014 ", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00015 ", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00016 ", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00017 ", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00018 ", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00019 ", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00020 ", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 2 );

player.sendDebug( "questId: {}, calling Empty:Scene00021 ", getId() );


  }

  void Scene00022( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
player.sendDebug( "questId: {}, calling Message:Scene00022 ", getId() );

    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00024( player ); }
 else { Scene00025( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00023 +2 ", getId() );

    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](23)Talk, QuestReward, QuestComplete:Scene00024 ACTOR1", getId() );

    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](23)Empty:Scene00025 ", getId() );

    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00026 EOBJECT2", getId() );


  }

  void Scene00027( Entity::Player& player )
  {


//Target: EOBJECT3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00027 EOBJECT3", getId() );


  }

  void Scene00028( Entity::Player& player )
  {


//Target: EOBJECT4
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00028 EOBJECT4", getId() );


  }

  void Scene00029( Entity::Player& player )
  {


//Target: EOBJECT5
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00029 EOBJECT5", getId() );


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



player.sendDebug( "questId: {}, calling Empty:Scene00032 ", getId() );


  }

  void Scene00033( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00033 ", getId() );


  }

  void Scene00034( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00034 ", getId() );


  }

  void Scene00035( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00035 ", getId() );


  }

  void Scene00036( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00036 ", getId() );


  }

  void Scene00037( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00037 ", getId() );


  }

};

EXPOSE_SCRIPT( SubFst073 );
