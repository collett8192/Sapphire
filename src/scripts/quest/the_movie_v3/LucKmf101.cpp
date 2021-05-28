// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmf101 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmf101() : Sapphire::ScriptAPI::EventScript( 69180 ){}; 
  ~LucKmf101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1027231
  //ACTOR1 = 1027224
  //ACTOR2 = 1027248
  //ACTOR3 = 1027226
  //ACTOR4 = 1027232
  //LOCACTION01 = 182
  //LOCACTION02 = 183
  //LOCACTOR01 = 1028130
  //QUESTDKB01 = 68763
  //QUESTDKB02 = 68766
  //QUESTDKB03 = 68769
  //QUESTDKB04 = 68772
  //QUESTDKB05 = 68775
  //QUESTROLL01 = 68779
  //QUESTROLL02 = 68803
  //QUESTROLL03 = 68809
  //QUESTROLL04 = 69159

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUIDEOFTHEPENDANTS
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=BRAGI
        break;
      }
      case 2:
      {
        if( param1 == 1027248 || param2 == 1027248 ) // ACTOR2 = CHESSAMILE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=CHESSAMILE
          }
          break;
        }
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR1 = BRAGI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=BRAGI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1027226 || param2 == 1027226 ) // ACTOR3 = MOREN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MOREN
          }
          break;
        }
        if( param1 == 1027248 || param2 == 1027248 ) // ACTOR2 = CHESSAMILE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CHESSAMILE
          break;
        }
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR1 = BRAGI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=BRAGI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1027232 || param2 == 1027232 ) // ACTOR4 = KATLISS
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=KATLISS
          // +Callback Scene00009: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=KATLISS
          break;
        }
        if( param1 == 1027226 || param2 == 1027226 ) // ACTOR3 = MOREN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MOREN
          break;
        }
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR1 = BRAGI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=BRAGI
          break;
        }
        if( param1 == 1027248 || param2 == 1027248 ) // ACTOR2 = CHESSAMILE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=CHESSAMILE
          break;
        }
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmf101:69180 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUIDEOFTHEPENDANTS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00002: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00003: Normal(Talk, TargetCanMove), id=CHESSAMILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00004: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00005: Normal(Talk, TargetCanMove), id=MOREN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00006: Normal(Talk, TargetCanMove), id=CHESSAMILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00007: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00008: Normal(Talk, TargetCanMove), id=KATLISS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00009: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=KATLISS" );
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
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00010: Normal(Talk, TargetCanMove), id=MOREN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00011: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmf101:69180 calling Scene00012: Normal(Talk, TargetCanMove), id=CHESSAMILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmf101 );
