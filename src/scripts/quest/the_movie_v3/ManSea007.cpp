// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManSea007 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManSea007() : Sapphire::ScriptAPI::EventScript( 66080 ){}; 
  ~ManSea007() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000972
  //ACTOR1 = 1003282
  //ACTOR2 = 1003283
  //ACTOR3 = 1003284
  //ACTOR4 = 1003285
  //ACTOR5 = 1003286
  //CUTEVENT0 = 207
  //CUTEVENT1 = 211
  //CUTEVENT2 = 136
  //CUTSCENE03 = 210
  //EOBJECT0 = 2001739
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000519
  //LOCACTOR0 = 1005031
  //LOCFACE0 = 604
  //LOCFACE1 = 617
  //QUESTBATTLE0 = 36
  //TERRITORYTYPE0 = 280
  //TERRITORYTYPE1 = 138

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=BADERON
        // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        Scene00002( player ); // Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=REYNER
        break;
      }
      case 2:
      {
        if( actor == 1003283 || actorId == 1003283 ) // ACTOR2 = RYSSFLOH
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=RYSSFLOH
          }
        }
        if( actor == 1003284 || actorId == 1003284 ) // ACTOR3 = GLAZRAEL
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=GLAZRAEL
        }
        if( actor == 1003285 || actorId == 1003285 ) // ACTOR4 = YELLOWJACKETA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YELLOWJACKETA
        }
        if( actor == 1003286 || actorId == 1003286 ) // ACTOR5 = YELLOWJACKETB
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YELLOWJACKETB
        }
        if( actor == 2001739 || actorId == 2001739 ) // EOBJECT0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          // +Callback Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        Scene00010( player ); // Scene00010: Normal(CutScene), id=unknown
        break;
      }
      case 255:
      {
        Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=REYNER
        // +Callback Scene00012: Normal(CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown
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
    onProgress( player, param1, param1, 3, param1 );
  }

  void onEnterTerritory( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( player, param1, param2, 4, 0 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=BADERON" );
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
    player.sendDebug( "ManSea007:66080 calling [BranchTrue]Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling [BranchTrue]Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=REYNER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling Scene00004: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=RYSSFLOH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling Scene00005: Normal(Talk, TargetCanMove), id=GLAZRAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling Scene00006: Normal(Talk, TargetCanMove), id=YELLOWJACKETA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling Scene00007: Normal(Talk, TargetCanMove), id=YELLOWJACKETB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling Scene00010: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling Scene00011: Normal(Talk, TargetCanMove), id=REYNER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "ManSea007:66080 calling [BranchTrue]Scene00012: Normal(CutScene, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( ManSea007 );
