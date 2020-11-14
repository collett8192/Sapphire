// FFXIVTheMovie.ParserV3
// id table disabled
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda303 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda303() : Sapphire::ScriptAPI::EventScript( 68015 ){}; 
  ~StmBda303() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_4, 2 entries
  //SEQ_5, 6 entries
  //SEQ_6, 10 entries
  //SEQ_7, 8 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1023650
  //ACTOR1 = 1023647
  //ACTOR10 = 1019920
  //ACTOR11 = 1019921
  //ACTOR12 = 1019922
  //ACTOR13 = 1019923
  //ACTOR14 = 1019924
  //ACTOR15 = 1019925
  //ACTOR16 = 1019926
  //ACTOR17 = 1020220
  //ACTOR18 = 1023697
  //ACTOR19 = 1023698
  //ACTOR2 = 1023648
  //ACTOR20 = 1019928
  //ACTOR21 = 1019927
  //ACTOR22 = 1019942
  //ACTOR23 = 1019943
  //ACTOR24 = 1019930
  //ACTOR25 = 1019929
  //ACTOR3 = 1023649
  //ACTOR4 = 1023683
  //ACTOR5 = 1019915
  //ACTOR6 = 1019916
  //ACTOR7 = 1019917
  //ACTOR8 = 1019918
  //ACTOR9 = 1019919
  //BINDACTOR0 = 7010342
  //BINDACTOR1 = 7010343
  //BINDACTOR10 = 6829384
  //BINDACTOR2 = 7010344
  //BINDACTOR4 = 6829392
  //BINDACTOR6 = 6829378
  //CUTSCENEN01 = 1410
  //CUTSCENEN02 = 1611
  //ENEMY0 = 6829390
  //ENEMY1 = 6829391
  //EOBJECT0 = 2007851
  //EOBJECT1 = 2008753
  //EOBJECT2 = 2008754
  //EOBJECT3 = 2008765
  //EOBJECT4 = 2008207
  //EVENTRANGE0 = 6841399
  //LCUTSE0 = 149
  //LOCACTOR1 = 1021967
  //LOCACTOR2 = 1019541
  //LOCACTOR3 = 1018509
  //LOCACTOR4 = 1019710
  //POPRANGE0 = 6829379
  //POPRANGE1 = 6829380
  //POPRANGE2 = 6841396

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1023650 || param2 == 1023650 ) // ACTOR0 = SOROBAN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1023647 || param2 == 1023647 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1023648 || param2 == 1023648 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1023649 || param2 == 1023649 ) // ACTOR3 = GOSETSU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        break;
      }
      case 1:
      {
        if( param1 == 1023683 || param2 == 1023683 ) // ACTOR4 = TESHITAPIRATE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=TESHITAPIRATE
          }
        }
        if( param1 == 1019915 || param2 == 1019915 ) // ACTOR5 = GOSETSU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1019916 || param2 == 1019916 ) // ACTOR6 = LYSE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019917 || param2 == 1019917 ) // ACTOR7 = ALISAIE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019918 || param2 == 1019918 ) // ACTOR8 = GOSETSU
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        break;
      }
      case 2:
      {
        if( param1 == 1019915 || param2 == 1019915 ) // ACTOR5 = SOROBAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove, Menu), id=SOROBAN
            // +Callback Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=SOROBAN
          }
          else
          {
            Scene00012( player ); // Scene00012: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1019916 || param2 == 1019916 ) // ACTOR6 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019917 || param2 == 1019917 ) // ACTOR7 = ALISAIE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019918 || param2 == 1019918 ) // ACTOR8 = GOSETSU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1023683 || param2 == 1023683 ) // ACTOR4 = TESHITAPIRATE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=TESHITAPIRATE
        }
        break;
      }
      case 3:
      {
        if( param1 == 1019919 || param2 == 1019919 ) // ACTOR9 = SOROBAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=SOROBAN
            // +Callback Scene00018: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1019920 || param2 == 1019920 ) // ACTOR10 = LYSE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019921 || param2 == 1019921 ) // ACTOR11 = ALISAIE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019922 || param2 == 1019922 ) // ACTOR12 = GOSETSU
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 2007851 || param2 == 2007851 ) // EOBJECT0 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( param1 == 1019923 || param2 == 1019923 ) // ACTOR13 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1019924 || param2 == 1019924 ) // ACTOR14 = LYSE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 5:
      {
        if( param1 == 1019925 || param2 == 1019925 ) // ACTOR15 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1019926 || param2 == 1019926 ) // ACTOR16 = LYSE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020220 || param2 == 1020220 ) // ACTOR17 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        if( param1 == 2008753 || param2 == 2008753 ) // EOBJECT1 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
        }
        if( param1 == 2008754 || param2 == 2008754 ) // EOBJECT2 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(Message, PopBNpc), id=unknown
        }
        if( param1 == 2008765 || param2 == 2008765 ) // EOBJECT3 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        break;
      }
      case 6:
      {
        if( param1 == 6841399 || param2 == 6841399 ) // EVENTRANGE0 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        if( param1 == 6829390 || param2 == 6829390 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq6( player );
          }
        }
        if( param1 == 6829391 || param2 == 6829391 ) // ENEMY1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq6( player );
          }
        }
        if( param1 == 2008207 || param2 == 2008207 ) // EOBJECT4 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        if( param1 == 1020220 || param2 == 1020220 ) // ACTOR17 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        if( param1 == 2008753 || param2 == 2008753 ) // EOBJECT1 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
        }
        if( param1 == 2008754 || param2 == 2008754 ) // EOBJECT2 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
        }
        if( param1 == 2008765 || param2 == 2008765 ) // EOBJECT3 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
        }
        if( param1 == 1023697 || param2 == 1023697 ) // ACTOR18 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
        }
        if( param1 == 1023698 || param2 == 1023698 ) // ACTOR19 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        break;
      }
      case 7:
      {
        if( param1 == 1019928 || param2 == 1019928 ) // ACTOR20 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=LYSE
          }
        }
        if( param1 == 1019927 || param2 == 1019927 ) // ACTOR21 = ALISAIE
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019942 || param2 == 1019942 ) // ACTOR22 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
        }
        if( param1 == 1019943 || param2 == 1019943 ) // ACTOR23 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
        }
        if( param1 == 1020220 || param2 == 1020220 ) // ACTOR17 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
        }
        if( param1 == 2008753 || param2 == 2008753 ) // EOBJECT1 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
        }
        if( param1 == 2008754 || param2 == 2008754 ) // EOBJECT2 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
        }
        if( param1 == 2008765 || param2 == 2008765 ) // EOBJECT3 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019930 || param2 == 1019930 ) // ACTOR24 = LYSE
        {
          Scene00049( player ); // Scene00049: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
        }
        if( param1 == 1019929 || param2 == 1019929 ) // ACTOR25 = ALISAIE
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019942 || param2 == 1019942 ) // ACTOR22 = unknown
        {
          Scene00051( player ); // Scene00051: Normal(None), id=unknown
        }
        if( param1 == 1019943 || param2 == 1019943 ) // ACTOR23 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
        }
        if( param1 == 1020220 || param2 == 1020220 ) // ACTOR17 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
        }
        if( param1 == 2008753 || param2 == 2008753 ) // EOBJECT1 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
        }
        if( param1 == 2008754 || param2 == 2008754 ) // EOBJECT2 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
        }
        if( param1 == 2008765 || param2 == 2008765 ) // EOBJECT3 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 2 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 7 );
      }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda303:68015 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00005: Normal(Talk, TargetCanMove), id=TESHITAPIRATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00007: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00009: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00010: Normal(Talk, TargetCanMove, Menu), id=SOROBAN" );
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
    player.sendDebug( "StmBda303:68015 calling [BranchTrue]Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 613, -708.77, -0.099, -302.91, -1.65, false );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling [BranchFalse]Scene00012: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00014: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00015: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00016: Normal(Talk, TargetCanMove), id=TESHITAPIRATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling [BranchTrue]Scene00018: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 613, -740.88, 1.86, -310.57, -2.08, false );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00019: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00021: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00024: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00025: Normal(Talk, FadeIn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00026: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00029: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00031: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00032: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00033: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 2 );
    checkProgressSeq6( player );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00034: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00036: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00038: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00041: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00042: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00046: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00047: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00048: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00049: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00051: Normal(None), id=unknown" );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00052: Normal(None), id=unknown" );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00053: Normal(None), id=unknown" );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "StmBda303:68015 calling Scene00056: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda303 );
