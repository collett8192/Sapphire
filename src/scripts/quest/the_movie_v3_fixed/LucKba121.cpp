// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba121 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba121() : Sapphire::ScriptAPI::EventScript( 68781 ){}; 
  ~LucKba121() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_4, 4 entries
  //SEQ_5, 3 entries
  //SEQ_6, 2 entries
  //SEQ_7, 4 entries
  //SEQ_8, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1029893
  //ACTOR1 = 1029899
  //ACTOR10 = 1029958
  //ACTOR11 = 1029959
  //ACTOR2 = 1029898
  //ACTOR3 = 1029951
  //ACTOR4 = 1027876
  //ACTOR5 = 1029953
  //ACTOR6 = 1029954
  //ACTOR7 = 1029956
  //ACTOR8 = 1029955
  //ACTOR9 = 1029957
  //ENEMY0 = 7929515
  //EOBJECT0 = 2009944
  //EOBJECT1 = 2009945
  //EVENTACTION0 = 41
  //EVENTACTION1 = 1
  //EVENTRANGE0 = 7929507
  //LOCACTION01 = 5591
  //LOCACTOR01 = 1028190
  //NCUTEVENTLUCKBA12101 = 2090
  //POPRANGE0 = 7929511

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=GRANSON
        break;
      }
      case 1:
      {
        if( param1 == 1029899 || param2 == 1029899 ) // ACTOR1 = ANTIQUEDEALER03245
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ANTIQUEDEALER03245
          }
          break;
        }
        if( param1 == 1029893 || param2 == 1029893 ) // ACTOR0 = GRANSON
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029893 || param2 == 1029893 ) // ACTOR0 = GRANSON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON
          }
          break;
        }
        if( param1 == 1029899 || param2 == 1029899 ) // ACTOR1 = ANTIQUEDEALER03245
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ANTIQUEDEALER03245
          break;
        }
        break;
      }
      case 3:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON
        break;
      }
      case 4:
      {
        if( param1 == 1029951 || param2 == 1029951 ) // ACTOR3 = HUMEMERCHANT03245
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HUMEMERCHANT03245
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=HUMEMERCHANT03245
          }
          break;
        }
        if( param1 == 4302778125 || param2 == 4302778125 ) // ACTOR4 = ZHINZIN
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ZHINZIN
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=ZHINZIN
          }
          break;
        }
        if( param1 == 1029953 || param2 == 1029953 ) // ACTOR5 = GRANSON
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        if( param1 == 1029954 || param2 == 1029954 ) // ACTOR6 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1029953 || param2 == 1029953 ) // ACTOR5 = GRANSON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON
          }
          break;
        }
        if( param1 == 1029951 || param2 == 1029951 ) // ACTOR3 = HUMEMERCHANT03245
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=HUMEMERCHANT03245
          break;
        }
        if( param1 == 1027876 || param2 == 1027876 ) // ACTOR4 = ZHINZIN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ZHINZIN
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 2009944 || param2 == 2009944 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029956 || param2 == 1029956 ) // ACTOR7 = GRANSON
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 7929507 || param2 == 7929507 ) // EVENTRANGE0 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(Message), id=unknown
          break;
        }
        if( param1 == 7929515 || param2 == 7929515 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq7( player );
          }
          break;
        }
        if( param1 == 1029955 || param2 == 1029955 ) // ACTOR8 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009945 || param2 == 2009945 ) // EOBJECT1 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 8:
      {
        if( param1 == 1029957 || param2 == 1029957 ) // ACTOR9 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player );
          }
          break;
        }
        if( param1 == 1029958 || param2 == 1029958 ) // ACTOR10 = unknown
        {
          break;
        }
        break;
      }
      case 255:
      {
        Scene00026( player ); // Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GRANSON
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
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
    player.sendDebug( "LucKba121:68781 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKba121:68781 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00002: Normal(Talk, TargetCanMove), id=ANTIQUEDEALER03245" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00003: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00005: Normal(Talk, TargetCanMove), id=ANTIQUEDEALER03245" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00007: Normal(Talk, TargetCanMove), id=HUMEMERCHANT03245" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00008: Normal(Talk, TargetCanMove), id=HUMEMERCHANT03245" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00009: Normal(Talk, TargetCanMove), id=ZHINZIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00010: Normal(Talk, TargetCanMove), id=ZHINZIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00011: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00014: Normal(Talk, TargetCanMove), id=HUMEMERCHANT03245" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00015: Normal(Talk, TargetCanMove), id=ZHINZIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00017: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00018: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00019: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }


  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00024: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKba121:68781 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GRANSON" );
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
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKba121 );
