// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda317 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda317() : Sapphire::ScriptAPI::EventScript( 68029 ){}; 
  ~StmBda317() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 2 entries
  //SEQ_2, 4 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1020011
  //ACTOR1 = 1020010
  //ACTOR2 = 1020017
  //ACTOR3 = 1020012
  //ACTOR4 = 1020013
  //ACTOR5 = 1020015
  //ACTOR6 = 1019263
  //ACTOR7 = 1022719
  //ACTOR8 = 1019259
  //BINDACTOR0 = 6782229
  //LOCACTOR0 = 1018509

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020011 || param2 == 1020011 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020010 || param2 == 1020010 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020017 || param2 == 1020017 ) // ACTOR2 = RESISTANCE02492
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RESISTANCE02492
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020012 || param2 == 1020012 ) // ACTOR3 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1020013 || param2 == 1020013 ) // ACTOR4 = LYSE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020015 || param2 == 1020015 ) // ACTOR5 = MIYAMA
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MIYAMA
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=MIYAMA
          }
        }
        if( param1 == 1019263 || param2 == 1019263 ) // ACTOR6 = HONAMI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HONAMI
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=HONAMI
          }
        }
        if( param1 == 1022719 || param2 == 1022719 ) // ACTOR7 = CHIGUSA
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove, Menu, CanCancel), id=CHIGUSA
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=CHIGUSA
          }
        }
        if( param1 == 1019259 || param2 == 1019259 ) // ACTOR8 = MASATSUCHI
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MASATSUCHI
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=MASATSUCHI
          }
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020012 || param2 == 1020012 ) // ACTOR3 = YUGIRI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020013 || param2 == 1020013 ) // ACTOR4 = LYSE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020015 || param2 == 1020015 ) // ACTOR5 = MIYAMA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MIYAMA
        }
        if( param1 == 1019263 || param2 == 1019263 ) // ACTOR6 = HONAMI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HONAMI
        }
        if( param1 == 1022719 || param2 == 1022719 ) // ACTOR7 = CHIGUSA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CHIGUSA
        }
        if( param1 == 1019259 || param2 == 1019259 ) // ACTOR8 = MASATSUCHI
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MASATSUCHI
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8CH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
          if( player.getQuestUI8BL( getId() ) == 1 )
          {
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.updateQuest( getId(), 255 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda317:68029 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00003: Normal(Talk, TargetCanMove), id=RESISTANCE02492" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00005: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00006: Normal(Talk, TargetCanMove), id=MIYAMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00007: Normal(Talk, TargetCanMove), id=MIYAMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00008: Normal(Talk, TargetCanMove), id=HONAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00009: Normal(Talk, TargetCanMove), id=HONAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00010: Normal(Talk, TargetCanMove, Menu, CanCancel), id=CHIGUSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00011: Normal(Talk, TargetCanMove), id=CHIGUSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00012: Normal(Talk, TargetCanMove), id=MASATSUCHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00013: Normal(Talk, TargetCanMove), id=MASATSUCHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI" );
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
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00015: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00016: Normal(Talk, TargetCanMove), id=MIYAMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00017: Normal(Talk, TargetCanMove), id=HONAMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00018: Normal(Talk, TargetCanMove), id=CHIGUSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda317:68029 calling Scene00019: Normal(Talk, TargetCanMove), id=MASATSUCHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda317 );
