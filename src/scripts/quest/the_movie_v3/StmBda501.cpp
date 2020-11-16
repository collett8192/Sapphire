// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda501 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda501() : Sapphire::ScriptAPI::EventScript( 68055 ){}; 
  ~StmBda501() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1020519
  //ACTOR1 = 1020520
  //ACTOR2 = 1020521
  //ACTOR3 = 1020523
  //ACTOR4 = 1020522
  //ACTOR5 = 1020524
  //ACTOR6 = 1023084
  //ACTOR7 = 1020622
  //BINDYUGIRI001 = 6843952
  //NCUTEVENT05010 = 1449
  //POPRANGE0 = 6973936

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00002: Normal(CutScene, QuestAccept), id=unknown
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020521 || param2 == 1020521 ) // ACTOR2 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR3 = YUGIRI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020522 || param2 == 1020522 ) // ACTOR4 = GOSETSU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR5 = HIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR5 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020521 || param2 == 1020521 ) // ACTOR2 = LYSE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR3 = YUGIRI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020522 || param2 == 1020522 ) // ACTOR4 = GOSETSU
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR3 = YUGIRI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020521 || param2 == 1020521 ) // ACTOR2 = LYSE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020522 || param2 == 1020522 ) // ACTOR4 = GOSETSU
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR5 = HIEN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1023084 || param2 == 1023084 ) // ACTOR6 = TATARU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020521 || param2 == 1020521 ) // ACTOR2 = LYSE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020522 || param2 == 1020522 ) // ACTOR4 = GOSETSU
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR5 = HIEN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR7 = HANCOCK
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=HANCOCK
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda501:68055 calling Scene00001: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00002: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00007: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00008: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00011: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00012: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00015: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00017: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00018: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00019: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU" );
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
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00024: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda501:68055 calling Scene00025: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda501 );
