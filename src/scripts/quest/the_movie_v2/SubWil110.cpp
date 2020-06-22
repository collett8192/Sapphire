// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubWil110_00618
// Quest Name: Unsolved Mystery
// Quest ID: 66154
// Start NPC: 1003929
// End NPC: 1003929

using namespace Sapphire;

class SubWil110 : public Sapphire::ScriptAPI::EventScript
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

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1003929;
//    static constexpr auto Actor1 = 1003942;
//    static constexpr auto Actor2 = 1003943;
//    static constexpr auto Actor3 = 1003944;
//    static constexpr auto Enemy0 = 4100865;
//    static constexpr auto Enemy1 = 4100866;
//    static constexpr auto Eobject0 = 2001663;
//    static constexpr auto Eobject1 = 2001664;
//    static constexpr auto Eobject2 = 2001665;
//    static constexpr auto Eobject3 = 2001866;
//    static constexpr auto Eventrange0 = 4100864;
//    static constexpr auto EventActionGatherShort = 6;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000399;

  public:
    SubWil110() : Sapphire::ScriptAPI::EventScript( 66154 ){}; 
    ~SubWil110() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
void onWithinRange( Sapphire::Entity::Player& player, uint32_t eventId, uint32_t param1,float x, float y, float z ) override
{
switch( player.getQuestSeq( getId() ) ){
case 1:{
Scene00002( player );
break;
}
case 255:{
Scene00019( player );
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
//ACTOR1, UI8BL, 1, -2, False
if( actor == 1003942 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1003943 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR3, UI8BH, 1, -2, False
if( actor == 1003944 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00004( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001663 ) { Scene00005( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001664 ) { Scene00006( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001665 ) { Scene00007( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001866 ) { Scene00008( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -1, False
if( actor == 1003929 ) { Scene00019( player ); }
//EOBJECT0, null, 0, -1, False
if( actor == 2001663 ) { Scene00022( player ); }
//EOBJECT1, null, 0, -1, False
if( actor == 2001664 ) { Scene00023( player ); }
//EOBJECT2, null, 0, -1, False
if( actor == 2001665 ) { Scene00024( player ); }
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
player.sendDebug( "questId: {}, calling Talk, QuestOffer:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept:Scene00001 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: ACTOR1
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00002 ACTOR1:UI8BL=-2, 1", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: ACTOR2
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 ACTOR2:UI8AL=-2, 1", getId() );


  }

  void Scene00004( Entity::Player& player )
  {


//Target: ACTOR3
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR3:UI8BH=-2, 1", getId() );


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
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT3", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling [sub:SkippedMsg](10)Empty:Scene00009 ", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Message:Scene00010 +2 ", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:SkippedMsg](10)Empty:Scene00011 ", getId() );

    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00012 ", getId() );


  }

  void Scene00013( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00013 ", getId() );


  }

  void Scene00014( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00014 ", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00015 ", getId() );


  }

  void Scene00016( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00016 ", getId() );


  }

  void Scene00017( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00017 ", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00018 ", getId() );


  }

  void Scene00019( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00020( player ); }
 else { Scene00021( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00019 +2 ", getId() );

    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](19)Talk, QuestReward, QuestComplete:Scene00020 ACTOR0", getId() );

    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](19)Empty:Scene00021 ", getId() );

    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {


//Target: EOBJECT0
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00022 EOBJECT0", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


//Target: EOBJECT1
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00023 EOBJECT1", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


//Target: EOBJECT2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00024 EOBJECT2", getId() );


  }

  void Scene00025( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00025 ", getId() );


  }

  void Scene00026( Entity::Player& player )
  {



player.sendDebug( "questId: {}, calling Empty:Scene00026 ", getId() );


  }

  void Scene00027( Entity::Player& player )
  {


//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00027 ", getId() );


  }

};

EXPOSE_SCRIPT( SubWil110 );
