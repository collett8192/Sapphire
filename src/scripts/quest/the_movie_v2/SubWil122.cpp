// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False
//parsingResult: -2
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubWil122_00632
// Quest Name: Now Hiring
// Quest ID: 66168
// Start NPC: 1003939
// End NPC: 1003939

using namespace Sapphire;

class SubWil122 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1003939;
//    static constexpr auto Actor1 = 1003952;
//    static constexpr auto Actor2 = 1003953;
//    static constexpr auto Actor3 = 1003954;
//    static constexpr auto Actor4 = 1003955;
//    static constexpr auto Actor5 = 1003956;
//    static constexpr auto Eobject0 = 2001423;
//    static constexpr auto Eobject1 = 2001424;
//    static constexpr auto Eobject2 = 2001425;
//    static constexpr auto Eobject3 = 2001453;
//    static constexpr auto Eobject4 = 2001454;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000393;
//    static constexpr auto Item1 = 2000412;

  public:
    SubWil122() : Sapphire::ScriptAPI::EventScript( 66168 ){}; 
    ~SubWil122() = default; 

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
//EOBJECT0, UI8AL, 5, -2, False
if( actor == 2001423 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00001( player ); }
//EOBJECT1, UI8AL, 5, -2, False
if( actor == 2001424 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00002( player ); }
//EOBJECT2, UI8AL, 5, -2, False
if( actor == 2001425 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00003( player ); }
//EOBJECT3, UI8AL, 5, -2, False
if( actor == 2001453 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00004( player ); }
//EOBJECT4, UI8AL, 5, -2, False
if( actor == 2001454 && player.getQuestUI8AL( getId() ) != 5 ) { Scene00005( player ); }
break;
}
case 2:{
//ACTOR0, UI8AL, 1, -2, False
if( actor == 1003939 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00006( player ); }
//EOBJECT0, null, 0, -2, False
if( actor == 2001423 ) { Scene00007( player ); }
//EOBJECT1, null, 0, -2, False
if( actor == 2001424 ) { Scene00008( player ); }
//EOBJECT2, null, 0, -2, False
if( actor == 2001425 ) { Scene00009( player ); }
//EOBJECT3, null, 0, -2, False
if( actor == 2001453 ) { Scene00010( player ); }
//EOBJECT4, null, 0, -2, False
if( actor == 2001454 ) { Scene00011( player ); }
break;
}
case 3:{
//ACTOR1, UI8AL, 1, -2, False
if( actor == 1003952 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00012( player ); }
//ACTOR2, UI8BH, 1, -2, False
if( actor == 1003953 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00013( player ); }
//ACTOR3, UI8BL, 1, -2, False
if( actor == 1003954 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00014( player ); }
//ACTOR4, UI8CH, 1, -2, False
if( actor == 1003955 && player.getQuestUI8CH( getId() ) != 1 ) { Scene00015( player ); }
//ACTOR5, UI8CL, 1, -2, False
if( actor == 1003956 && player.getQuestUI8CL( getId() ) != 1 ) { Scene00016( player ); }
break;
}
case 255:{
//ACTOR0, null, 0, -2, False
if( actor == 1003939 ) { Scene00047( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1003952 ) { Scene00048( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1003953 ) { Scene00049( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1003954 ) { Scene00050( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1003955 ) { Scene00051( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1003956 ) { Scene00052( player ); }
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
player.setQuestUI8BH( getId(), 1 );
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
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00001 EOBJECT0:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: EOBJECT1
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00002 EOBJECT1:UI8AL=-2, 5", getId() );


  }

  void Scene00003( Entity::Player& player )
  {


//Target: EOBJECT2
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00003 EOBJECT2:UI8AL=-2, 5", getId() );


  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00004 EOBJECT3:UI8AL=-2, 5", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {


//Target: EOBJECT4
player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
if( player.getQuestUI8AL( getId() ) == 5 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00005 EOBJECT4:UI8AL=-2, 5", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


//Target: ACTOR0
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 3 );
player.setQuestUI8DH( getId(), 1 );
player.setQuestUI8DL( getId(), 1 );
}

player.sendDebug( "questId: {}, calling Empty:Scene00006 ACTOR0:UI8AL=-2, 1", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00007 EOBJECT0", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {


//Target: EOBJECT1
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00008 EOBJECT1", getId() );


  }

  void Scene00009( Entity::Player& player )
  {


//Target: EOBJECT2
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00009 EOBJECT2", getId() );


  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: EOBJECT3
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00010 EOBJECT3", getId() );

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {


//Target: EOBJECT4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00011 EOBJECT4", getId() );


  }

  void Scene00012( Entity::Player& player )
  {


//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00012 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Inventory:Scene00013 ACTOR2:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {


//Target: ACTOR3
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00014 ACTOR3:UI8BL=-2, 1", getId() );


  }

  void Scene00015( Entity::Player& player )
  {


//Target: ACTOR4
player.setQuestUI8CH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
}
}
}
}

player.sendDebug( "questId: {}, calling Empty:Scene00015 ACTOR4:UI8CH=-2, 1", getId() );


  }

  void Scene00016( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
player.setQuestUI8CL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
if( player.getQuestUI8CH( getId() ) == 1 ){
if( player.getQuestUI8CL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.setQuestUI8CH( getId(), 0 );
player.setQuestUI8CL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
}
}
}
}
}
    };
player.sendDebug( "questId: {}, calling Talk:Scene00016 ACTOR5:UI8CL=-2, 1", getId() );

    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00017 ", getId() );


  }

  void Scene00018( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00018 ", getId() );


  }

  void Scene00019( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00019 ", getId() );


  }

  void Scene00020( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00020 ", getId() );


  }

  void Scene00021( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00021 ", getId() );


  }

  void Scene00022( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00022 ", getId() );


  }

  void Scene00023( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00023 ", getId() );


  }

  void Scene00024( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00024 ", getId() );


  }

  void Scene00025( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00025 ", getId() );


  }

  void Scene00026( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00026 ", getId() );


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
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](27)Talk:Scene00028 ", getId() );

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
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00030 ", getId() );

    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00032( player ); }
 else { Scene00033( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00031 +2 ", getId() );

    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](31)Talk:Scene00032 ", getId() );

    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](31)Empty:Scene00033 ", getId() );

    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00034 ", getId() );

    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00036( player ); }
 else { Scene00037( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00035 +2 ", getId() );

    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](35)Talk:Scene00036 ", getId() );

    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](35)Empty:Scene00037 ", getId() );

    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00038 ", getId() );

    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00040( player ); }
 else { Scene00041( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00039 +2 ", getId() );

    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](39)Talk:Scene00040 ", getId() );

    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](39)Empty:Scene00041 ", getId() );

    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00042 ", getId() );

    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00044( player ); }
 else { Scene00045( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00043 +2 ", getId() );

    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:Execute](43)Talk:Scene00044 ", getId() );

    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](43)Empty:Scene00045 ", getId() );

    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Talk:Scene00046 ", getId() );

    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00047 ACTOR0", getId() );

    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00048 ACTOR1", getId() );

    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00049 ACTOR2", getId() );

    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00050 ACTOR3", getId() );

    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00051 ACTOR4", getId() );

    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
//next scene not found
    };
player.sendDebug( "questId: {}, calling Talk:Scene00052 ACTOR5", getId() );

    player.playScene( getId(), 52, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubWil122 );
