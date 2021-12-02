// FFXIVTheMovie.ParserV3.3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst980 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst980() : Sapphire::ScriptAPI::EventScript( 67206 ){}; 
  ~SubFst980() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1008948
  //ACTOR1 = 1003075
  //ACTOR2 = 5010000
  //EVENTACTIONSIGH = 4229
  //INSTANCEDUNGEON0 = 20008
  //INSTANCEDUNGEON1 = 20010
  //INSTANCEDUNGEON2 = 20009
  //ITEM0 = 2001942
  //ITEM1 = 2001943
  //ITEM2 = 2001944
  //LOCACTION0 = 241
  //LOCACTION1 = 250
  //LOCACTION2 = 4261
  //LOCACTION3 = 827
  //LOCACTION5 = 1091
  //LOCACTION6 = 936
  //LOCACTOR0 = 4311940
  //LOCACTOR1 = 4697909
  //LOCACTOR2 = 4678141
  //LOCACTOR3 = 4328412
  //LOCBGM0 = 100
  //LOCBGM1 = 101
  //LOCBGM2 = 86
  //LOCBGM3 = 89
  //LOCFACE0 = 606
  //LOCFACE1 = 612
  //LOCITEM0 = 14884
  //LOCITEM1 = 14885
  //LOCITEM2 = 14886
  //LOCITEM3 = 13775
  //LOCOBJECT0 = 2006975
  //LOCSE0 = 72
  //LOCSE1 = 80
  //LOCVFX0 = 241
  //QUEST0 = 67747
  //RITEM0 = 7883
  //RITEM1 = 6268

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=JALZAHN
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=GEROLT
        break;
      }
      case 2:
      {
        if( type != 2 ) Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=GEROLT
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=JALZAHN
        break;
      }
      //seq 4 event item ITEM0 = UI8CH max stack 1
      //seq 4 event item ITEM1 = UI8CL max stack 1
      //seq 4 event item ITEM2 = UI8DH max stack 1
      case 4:
      {
        if( type != 2 ) Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=GEROLT
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      //seq 255 event item ITEM2 = UI8CH max stack 1
      case 255:
      {
        // empty entry
        break;
      }
      default:
      {
        player.sendUrgent( "Sequence {} not defined.", player.getQuestSeq( getId() ) );
        break;
      }
    }
  }

public:
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    onProgress( player, actorId, actor, 0, 0 );
  }

  void onEmote( uint64_t actorId, uint32_t eventId, uint32_t emoteId, Entity::Player& player ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, 0 );
  }

  void onEnterTerritory( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( player, param1, param2, 4, 0 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.setQuestUI8CH( getId(), 0 );
    player.setQuestUI8CL( getId(), 0 );
    player.setQuestUI8DH( getId(), 0 );
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst980:67206 calling Scene00000: Normal(QuestOffer), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "SubFst980:67206 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=JALZAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubFst980:67206 calling Scene00002: Normal(Talk, TargetCanMove), id=GEROLT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubFst980:67206 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=GEROLT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubFst980:67206 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=JALZAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubFst980:67206 calling Scene00008: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=GEROLT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

};

EXPOSE_SCRIPT( SubFst980 );
