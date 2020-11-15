// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda412 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda412() : Sapphire::ScriptAPI::EventScript( 68047 ){}; 
  ~StmBda412() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 6 entries
  //SEQ_3, 14 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1019417
  //ACTOR1 = 1021730
  //ACTOR10 = 1021606
  //ACTOR11 = 1021607
  //ACTOR12 = 1021609
  //ACTOR13 = 1021610
  //ACTOR14 = 1021625
  //ACTOR15 = 1022085
  //ACTOR2 = 1021732
  //ACTOR3 = 1021731
  //ACTOR4 = 1021605
  //ACTOR5 = 1022078
  //ACTOR6 = 1019431
  //ACTOR7 = 5010000
  //ACTOR8 = 1021624
  //ACTOR9 = 1021608
  //ENEMY0 = 6875162
  //ENEMY1 = 6875163
  //ENEMY2 = 6875164
  //EOBJECT0 = 2008264
  //EOBJECT1 = 2008265
  //EVENTACTION0 = 1
  //EVENTACTION1 = 36
  //EVENTRANGE0 = 6888119
  //EVENTRANGE1 = 6875161
  //LOCAOKI = 1022002
  //LOCAURA001 = 1021983
  //LOCAURA002 = 1021984
  //LOCBINDBAATU = 6887824
  //LOCBINDDUID = 6840981
  //LOCBINDGOSETSUDOTA = 6865911
  //LOCBINDGOUSETSU = 6872468
  //LOCBINDGOUSETSU002 = 6865882
  //LOCBINDHIEN = 6872466
  //LOCBINDIET001 = 6865903
  //LOCBINDIET002 = 6865905
  //LOCBINDLISE = 6872467
  //LOCBINDMAGUNAI = 6840967
  //LOCCAMERAHUKEI = 6983463
  //LOCGESERU = 1019579
  //LOCGESERU002 = 6865929
  //LOCGOKAI = 4312
  //LOCIET = 1022001
  //LOCPOSEWINK = 621
  //LOCPOSAOKI = 6983461
  //LOCPOSGESERU = 6983462
  //LOCSADO = 1018980
  //LOCSEAKU = 44
  //LOCSESHIMARU = 45

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR0 = MAGNAI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=MAGNAI
        }
        if( param1 == 1021730 || param2 == 1021730 ) // ACTOR1 = HIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HIEN
        }
        if( param1 == 1021732 || param2 == 1021732 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1021731 || param2 == 1021731 ) // ACTOR3 = GOSETSU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        break;
      }
      case 1:
      {
        if( param1 == 1021605 || param2 == 1021605 ) // ACTOR4 = GOSETSU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU
          }
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR0 = MAGNAI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MAGNAI
        }
        if( param1 == 1022078 || param2 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=BAATU
        }
        if( param1 == 1019431 || param2 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=DAIDUKUL
        }
        break;
      }
      case 2:
      {
        if( type == 1 && param3 == 22 ) // ACTOR7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          }
        }
        if( param1 == 1021624 || param2 == 1021624 ) // ACTOR8 = GOSETSU
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 2008264 || param2 == 2008264 ) // EOBJECT0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( param1 == 1022078 || param2 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=BAATU
        }
        if( param1 == 1019431 || param2 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=DAIDUKUL
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR0 = MAGNAI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MAGNAI
        }
        break;
      }
      case 3:
      {
        // broken seq manual rewritten
        if( param1 == 6875161 || param2 == 6875161 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00018( player ); // Scene00018: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 1021608 || param2 == 1021608 ) // ACTOR9 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, FadeIn, TargetCanMove), id=DOTHARL02511
          }
        }
        if( param1 == 1021606 || param2 == 1021606 ) // ACTOR10 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(Talk), id=GOSETSU
        }
        if( param1 == 1019431 || param2 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=DAIDUKUL
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR0 = MAGNAI
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=MAGNAI
        }
        if( param1 == 1022078 || param2 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=BAATU
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021625 || param2 == 1021625 ) // ACTOR14 = GOSETSU
        {
          Scene00033( player ); // Scene00033: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1021608 || param2 == 1021608 ) // ACTOR9 = DOTHARL02511
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=DOTHARL02511
        }
        if( param1 == 1022085 || param2 == 1022085 ) // ACTOR15 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        if( param1 == 1019431 || param2 == 1019431 ) // ACTOR6 = DAIDUKUL
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=DAIDUKUL
        }
        if( param1 == 1022078 || param2 == 1022078 ) // ACTOR5 = BAATU
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=BAATU
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR0 = MAGNAI
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=MAGNAI
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
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda412:68047 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00002: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00006: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00007: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00008: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00013: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00015: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00016: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00017: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //player.setQuestUI8AL( getId(), 3 );
      //checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00019: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //player.setQuestUI8AL( getId(), 3 );
      //checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00020: Normal(Talk, FadeIn, TargetCanMove), id=DOTHARL02511" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI | INVIS_EOBJ, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00026: Normal(Talk), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00030: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00031: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00032: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00033: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GOSETSU" );
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
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00034: Normal(Talk, TargetCanMove), id=DOTHARL02511" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00036: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00037: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda412:68047 calling Scene00038: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda412 );
