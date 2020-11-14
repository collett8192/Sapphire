// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda319 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda319() : Sapphire::ScriptAPI::EventScript( 68031 ){}; 
  ~StmBda319() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 1 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_5, 7 entries
  //SEQ_6, 9 entries
  //SEQ_7, 4 entries
  //SEQ_8, 3 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTBASEWOUNDED = 4204
  //ACTIONTIMELINEEVENTEMPIRIALSALUTE = 587
  //ACTIONTIMELINEEVENTFRIGHTENED = 4215
  //ACTIONTIMELINEEVENTLOOKKNEEL = 4323
  //ACTIONTIMELINEEVENTLOOKSTAND = 4322
  //ACTOR0 = 1020020
  //ACTOR1 = 1020021
  //ACTOR10 = 1020212
  //ACTOR11 = 1020213
  //ACTOR12 = 1020025
  //ACTOR13 = 1020026
  //ACTOR14 = 1020027
  //ACTOR15 = 1019966
  //ACTOR16 = 1019967
  //ACTOR17 = 1020283
  //ACTOR2 = 1020022
  //ACTOR3 = 1020023
  //ACTOR4 = 1020024
  //ACTOR5 = 1020210
  //ACTOR6 = 1020211
  //ACTOR7 = 1020282
  //ACTOR8 = 1019892
  //ACTOR9 = 1019980
  //BINDACTOR0 = 6782246
  //BINDACTOR1 = 6941236
  //EOBJECT0 = 2007838
  //EOBJECT1 = 2007835
  //EOBJECT2 = 2007915
  //EVENTACTION0 = 11
  //EVENTACTION1 = 50
  //ITEM0 = 2002068
  //LOCACTOR0 = 1019553
  //LOCACTOR1 = 1019552
  //LOCACTOR2 = 1019547
  //LOCACTOR3 = 1018527
  //LOCACTOR4 = 1018528
  //LOCACTOR5 = 1018533
  //LOCACTOR6 = 1018977
  //LOCACTOR7 = 1019554
  //LOCMAKERPC = 6981179
  //NCUT01 = 1426
  //SNIPE0 = 8
  //SNIPE1 = 9
  //SNIPE2 = 10

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020020 || param2 == 1020020 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020021 || param2 == 1020021 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007838 || param2 == 2007838 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1020022 || param2 == 1020022 ) // ACTOR2 = YUGIRI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1020023 || param2 == 1020023 ) // ACTOR3 = LYSE
        {
          Scene00006( player ); // Scene00006: Normal(Talk), id=LYSE
        }
        break;
      }
      case 2:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 1020024 || param2 == 1020024 ) // ACTOR4 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1020210 || param2 == 1020210 ) // ACTOR5 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( param1 == 1020211 || param2 == 1020211 ) // ACTOR6 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack ?
      case 4:
      {
        if( param1 == 1020282 || param2 == 1020282 ) // ACTOR7 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=YUGIRI
            // +Callback Scene00012: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00013: Normal(Talk, FadeIn), id=unknown
          }
        }
        if( param1 == 1020210 || param2 == 1020210 ) // ACTOR5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( param1 == 1020211 || param2 == 1020211 ) // ACTOR6 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack ?
      case 5:
      {
        if( param1 == 2007835 || param2 == 2007835 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00018: Normal(FadeIn, SystemTalk), id=unknown
          }
        }
        if( param1 == 1020210 || param2 == 1020210 ) // ACTOR5 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( param1 == 1020211 || param2 == 1020211 ) // ACTOR6 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( param1 == 1019892 || param2 == 1019892 ) // ACTOR8 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( param1 == 1019980 || param2 == 1019980 ) // ACTOR9 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( param1 == 1020212 || param2 == 1020212 ) // ACTOR10 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( param1 == 1020213 || param2 == 1020213 ) // ACTOR11 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
        }
        break;
      }
      //seq 6 event item ITEM0 = UI8BH max stack ?
      case 6:
      {
        if( param1 == 1020025 || param2 == 1020025 ) // ACTOR12 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1020210 || param2 == 1020210 ) // ACTOR5 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
        }
        if( param1 == 1020211 || param2 == 1020211 ) // ACTOR6 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        if( param1 == 1020026 || param2 == 1020026 ) // ACTOR13 = SOLDIERA02495
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=SOLDIERA02495
        }
        if( param1 == 1020027 || param2 == 1020027 ) // ACTOR14 = SOLDIERB02495
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=SOLDIERB02495
        }
        if( param1 == 1019892 || param2 == 1019892 ) // ACTOR8 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
        }
        if( param1 == 1019980 || param2 == 1019980 ) // ACTOR9 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( param1 == 1020212 || param2 == 1020212 ) // ACTOR10 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( param1 == 1020213 || param2 == 1020213 ) // ACTOR11 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        break;
      }
      //seq 7 event item ITEM0 = UI8BH max stack ?
      case 7:
      {
        if( param1 == 2007915 || param2 == 2007915 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00036: Normal(FadeIn, SystemTalk), id=unknown
          }
        }
        if( param1 == 1020026 || param2 == 1020026 ) // ACTOR13 = SOLDIERA02495
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=SOLDIERA02495
        }
        if( param1 == 1020027 || param2 == 1020027 ) // ACTOR14 = SOLDIERB02495
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=SOLDIERB02495
        }
        if( param1 == 1020025 || param2 == 1020025 ) // ACTOR12 = YUGIRI
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        break;
      }
      //seq 8 event item ITEM0 = UI8BH max stack ?
      case 8:
      {
        if( param1 == 1020025 || param2 == 1020025 ) // ACTOR12 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00040( player ); // Scene00040: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI
          }
        }
        if( param1 == 1019966 || param2 == 1019966 ) // ACTOR15 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( param1 == 1019967 || param2 == 1019967 ) // ACTOR16 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( param1 == 1020283 || param2 == 1020283 ) // ACTOR17 = YUGIRI
        {
          Scene00043( player ); // Scene00043: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1019966 || param2 == 1019966 ) // ACTOR15 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
        }
        if( param1 == 1019967 || param2 == 1019967 ) // ACTOR16 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
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
    player.updateQuest( getId(), 3 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 8 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda319:68031 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00006: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00012: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, INVIS_ENPC, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00013: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00017: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00018( player );
      }
    };
    player.playScene( getId(), 17, INVIS_ENPC, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00018: Normal(FadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00028: Normal(Talk, TargetCanMove), id=SOLDIERA02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00029: Normal(Talk, TargetCanMove), id=SOLDIERB02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00035: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00036( player );
      }
    };
    player.playScene( getId(), 35, INVIS_ENPC, callback );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00036: Normal(FadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00037: Normal(Talk, TargetCanMove), id=SOLDIERA02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00038: Normal(Talk, TargetCanMove), id=SOLDIERB02495" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00039: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00040: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00043: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YUGIRI" );
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
    player.playScene( getId(), 43, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda319:68031 calling Scene00045: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda319 );
