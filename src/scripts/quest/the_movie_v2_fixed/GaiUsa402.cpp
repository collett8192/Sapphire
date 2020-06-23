// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2
//[switches]A: False, A2: False, A3: False, S: False, R: False, DM: False
#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUsa402_00744
// Quest Name: Believe in Your Sylph
// Quest ID: 66280
// Start NPC: 1000580
// End NPC: 1000168

using namespace Sapphire;

class GaiUsa402 : public Sapphire::ScriptAPI::EventScript
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
//    static constexpr auto Actor0 = 1000580;
//    static constexpr auto Actor1 = 5010000;
//    static constexpr auto Actor2 = 1007651;
//    static constexpr auto Actor3 = 1007652;
//    static constexpr auto Actor4 = 1007653;
//    static constexpr auto Actor5 = 1000168;
//    static constexpr auto CutEvent = 242;
//    static constexpr auto Eobject0 = 2001957;
//    static constexpr auto Eventrange0 = 4323294;
//    static constexpr auto Item0 = 2000596;
//    static constexpr auto LocPosCam1 = 4334898;

  public:
    GaiUsa402() : Sapphire::ScriptAPI::EventScript( 66280 ){}; 
    ~GaiUsa402() = default; 

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
if( actor == 5010000 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00003( player ); }
//ACTOR2, null, 0, -2, False
if( actor == 1007651 ) { Scene00004( player ); }
//ACTOR3, null, 0, -2, False
if( actor == 1007652 ) { Scene00005( player ); }
//ACTOR4, null, 0, -2, False
if( actor == 1007653 ) { Scene00006( player ); }
break;
}
case 255:{
//ACTOR5, null, 0, -1, False
if( actor == 1000168 ) { Scene00007( player ); }
//ACTOR2, null, 0, -1, False
if( actor == 1007651 ) { Scene00010( player ); }
//ACTOR3, null, 0, -1, False
if( actor == 1007652 ) { Scene00011( player ); }
//if( actor == 1007653 ) { Scene?????( player ); }
break;
}
default: { player.sendUrgent( "seq {} not defined.", player.getQuestSeq( getId() ) ); break; }
}
  }

  void onEmote( uint64_t actorId, uint32_t eventId, uint32_t emoteId, Sapphire::Entity::Player& player ) override
  {
    if( emoteId == 22 )
    {
      Scene00003( player );
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
    };
player.sendDebug( "questId: {}, calling [sub:Accept](0)QuestAccept, CutScene:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {


//Target: ACTOR1


player.sendDebug( "questId: {}, calling Empty:Scene00002 ACTOR1:UI8AL=-2, 1", getId() );


  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//does not modify quest vars
      player.setQuestUI8AL( getId(), 1 );
      if( player.getQuestUI8AL( getId() ) == 1 ){
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 1 );
      }
    };
player.sendDebug( "questId: {}, calling FadeOut:Scene00003 ACTOR2", getId() );

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {


//Target: ACTOR3
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00004 ACTOR3", getId() );


  }

  void Scene00005( Entity::Player& player )
  {


//Target: ACTOR4
//does not modify quest vars

player.sendDebug( "questId: {}, calling Empty:Scene00005 ACTOR4", getId() );


  }

  void Scene00006( Entity::Player& player )
  {


player.updateQuest( getId(), 255 );
player.setQuestUI8BH( getId(), 1 );

player.sendDebug( "questId: {}, calling Empty:Scene00006 ", getId() );


  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param1 > 0 && result.param2 == 1 )
{ Scene00008( player ); }
 else { Scene00009( player ); }
    };
player.sendDebug( "questId: {}, calling Talk, NpcTrade:Scene00007 +2 ", getId() );

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling [sub:Execute](7)Talk, QuestReward, QuestComplete:Scene00008 ACTOR5", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//exit event
    };
player.sendDebug( "questId: {}, calling [sub:Cancel](7)Empty:Scene00009 ", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {


//Target: ACTOR2
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00010 ACTOR2", getId() );


  }

  void Scene00011( Entity::Player& player )
  {


//Target: ACTOR3
//no valid quest var detected
//next scene not found

player.sendDebug( "questId: {}, calling Empty:Scene00011 ACTOR3", getId() );


  }

};

EXPOSE_SCRIPT( GaiUsa402 );
