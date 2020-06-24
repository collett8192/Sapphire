// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False, L: False, DBM: False
//parsingResult: 0
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: SubFst072_00386
// Quest Name: Walking the Planks
// Quest ID: 65922
// Start NPC: 1000501
// End NPC: 1000501

using namespace Sapphire;

class SubFst072 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1000501;
//    static constexpr auto Actor1 = 1000502;
//    static constexpr auto Actor2 = 1000507;
//    static constexpr auto Actor3 = 1000505;
//    static constexpr auto Eobject0 = 2001013;
//    static constexpr auto Eobject1 = 2001014;
//    static constexpr auto Eobject2 = 2001015;
//    static constexpr auto EventActionSearch = 1;
//    static constexpr auto Item0 = 2000246;
//    static constexpr auto Item1 = 2000247;
//    static constexpr auto Item2 = 2000248;
//    static constexpr auto Seq0Actor0 = 0;
//    static constexpr auto Seq1Eobject0 = 1;
//    static constexpr auto Seq1Eobject0Eventactionno = 99;
//    static constexpr auto Seq1Eobject0Eventactionok = 100;
//    static constexpr auto Seq1Eobject1 = 2;
//    static constexpr auto Seq1Eobject1Eventactionno = 97;
//    static constexpr auto Seq1Eobject1Eventactionok = 98;
//    static constexpr auto Seq1Eobject2 = 3;
//    static constexpr auto Seq1Eobject2Eventactionno = 95;
//    static constexpr auto Seq1Eobject2Eventactionok = 96;
//    static constexpr auto Seq2Actor1 = 4;
//    static constexpr auto Seq2Actor1Npctradeno = 93;
//    static constexpr auto Seq2Actor1Npctradeok = 94;
//    static constexpr auto Seq2Actor2 = 5;
//    static constexpr auto Seq2Actor2Npctradeno = 91;
//    static constexpr auto Seq2Actor2Npctradeok = 92;
//    static constexpr auto Seq2Actor3 = 6;
//    static constexpr auto Seq2Actor3Npctradeno = 89;
//    static constexpr auto Seq2Actor3Npctradeok = 90;
//    static constexpr auto Seq3Actor0 = 7;

  public:
    SubFst072() : Sapphire::ScriptAPI::EventScript( 65922 ){}; 
    ~SubFst072() = default; 

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
if( actor == 2001013 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00001( player ); }
//EOBJECT1, UI8BH, 1, -2, False
if( actor == 2001014 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00002( player ); }
//EOBJECT2, UI8BL, 1, -2, False
if( actor == 2001015 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00003( player ); }
break;
}
case 2:{
//ACTOR1, UI8AL, 1, -1, False
if( actor == 1000502 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00004( player ); }
//ACTOR2, UI8BH, 1, -1, False
if( actor == 1000507 && player.getQuestUI8BH( getId() ) != 1 ) { Scene00005( player ); }
//ACTOR3, UI8BL, 1, -1, False
if( actor == 1000505 && player.getQuestUI8BL( getId() ) != 1 ) { Scene00006( player ); }
break;
}
case 255:{
Scene00007( player );
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
player.setQuestUI8CL( getId(), 1 );
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
player.updateQuest( getId(), 2 );
player.setQuestUI8CH( getId(), 1 );
player.setQuestUI8CL( getId(), 1 );
player.setQuestUI8DH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Empty:Scene00001 +2 ", getId() );

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8CH( getId(), 1 );
player.setQuestUI8CL( getId(), 1 );
player.setQuestUI8DH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Empty:Scene00002 +2 ", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 2 );
player.setQuestUI8CH( getId(), 1 );
player.setQuestUI8CL( getId(), 1 );
player.setQuestUI8DH( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling Empty:Scene00003 +2 ", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00094( player ); }
 else { Scene00093( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00004 +2 ", getId() );

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

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00090( player ); }
 else { Scene00089( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00006 +2 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00007 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00089( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](6)Empty:Scene00089 ", getId() );

    player.playScene( getId(), 89, NONE, callback );
  }

  void Scene00090( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR3
player.setQuestUI8BL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](6)Talk:Scene00090 ACTOR3:UI8BL=-1, 1", getId() );

    player.playScene( getId(), 90, NONE, callback );
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
//Target: ACTOR2
player.setQuestUI8BH( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](5)Talk:Scene00092 ACTOR2:UI8BH=-1, 1", getId() );

    player.playScene( getId(), 92, NONE, callback );
  }

  void Scene00093( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](4)Empty:Scene00093 ", getId() );

    player.playScene( getId(), 93, NONE, callback );
  }

  void Scene00094( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
if( player.getQuestUI8BH( getId() ) == 1 ){
if( player.getQuestUI8BL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.setQuestUI8BH( getId(), 0 );
player.setQuestUI8BL( getId(), 0 );
player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );
player.setQuestUI8BL( getId(), 1 );
player.setQuestUI8CH( getId(), 1 );
}
}
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](4)Talk:Scene00094 ACTOR1:UI8AL=-1, 1", getId() );

    player.playScene( getId(), 94, NONE, callback );
  }

  void Scene00095( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:No](3)Empty:Scene00095 ", getId() );

    player.playScene( getId(), 95, NONE, callback );
  }

  void Scene00096( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:Ok](3)Empty:Scene00096 EOBJECT2:UI8BL=-2, 1", getId() );

    player.playScene( getId(), 96, NONE, callback );
  }

  void Scene00097( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:No](2)Empty:Scene00097 ", getId() );

    player.playScene( getId(), 97, NONE, callback );
  }

  void Scene00098( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:Ok](2)Empty:Scene00098 EOBJECT1:UI8BH=-2, 1", getId() );

    player.playScene( getId(), 98, NONE, callback );
  }

  void Scene00099( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:No](1)Empty:Scene00099 ", getId() );

    player.playScene( getId(), 99, NONE, callback );
  }

  void Scene00100( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//don't know how to do with this sub scene
    };
player.sendDebug( "questId: {}, calling [sub:Ok](1)Empty:Scene00100 EOBJECT0:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 100, NONE, callback );
  }

};

EXPOSE_SCRIPT( SubFst072 );
