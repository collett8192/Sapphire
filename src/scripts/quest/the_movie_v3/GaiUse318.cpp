// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse318 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse318() : Sapphire::ScriptAPI::EventScript( 66995 ){}; 
  ~GaiUse318() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 12 entries
  //SEQ_4, 10 entries
  //SEQ_5, 10 entries
  //SEQ_6, 10 entries
  //SEQ_7, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006384
  //ACTOR1 = 1006444
  //ACTOR10 = 1009087
  //ACTOR11 = 1009088
  //ACTOR12 = 1006530
  //ACTOR2 = 1009081
  //ACTOR3 = 1009082
  //ACTOR4 = 1009083
  //ACTOR5 = 1009084
  //ACTOR6 = 1009085
  //ACTOR7 = 1009086
  //ACTOR8 = 1006481
  //ACTOR9 = 1006480
  //CUTSCENEN01 = 530
  //CUTSCENEN02 = 531
  //CUTSCENEN03 = 532
  //ENEMY0 = 4867904
  //ENEMY1 = 4867905
  //EOBJECT0 = 2004151
  //EVENTRANGE0 = 4867918
  //EVENTACTIONSEARCH = 1
  //QSTCOMPCHK01 = 67061

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(CutScene, FadeIn, QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( actor == 1006444 || actorId == 1006444 ) // ACTOR1 = DRILLEMONT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=DRILLEMONT
          }
        }
        if( actor == 1006384 || actorId == 1006384 ) // ACTOR0 = HAURCHEFANT
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        break;
      }
      case 2:
      {
        if( actor == 1009081 || actorId == 1009081 ) // ACTOR2 = MERCHANT01459
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MERCHANT01459
          }
        }
        if( actor == 1006444 || actorId == 1006444 ) // ACTOR1 = DRILLEMONT
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=DRILLEMONT
        }
        break;
      }
      case 3:
      {
        if( actor == 4867918 || actorId == 4867918 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4867904 || actorId == 4867904 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4867905 || actorId == 4867905 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 1009082 || actorId == 1009082 ) // ACTOR3 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1009083 || actorId == 1009083 ) // ACTOR4 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1009084 || actorId == 1009084 ) // ACTOR5 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1009085 || actorId == 1009085 ) // ACTOR6 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1009086 || actorId == 1009086 ) // ACTOR7 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 2004151 || actorId == 2004151 ) // EOBJECT0 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(None), id=unknown
        }
        if( actor == 1006481 || actorId == 1006481 ) // ACTOR8 = LANCEFER
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          // +Callback Scene00015: Normal(Talk, TargetCanMove), id=LANCEFER
        }
        if( actor == 1006480 || actorId == 1006480 ) // ACTOR9 = OURDILIC
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=OURDILIC
        }
        if( actor == 1009081 || actorId == 1009081 ) // ACTOR2 = MERCHANT01459
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MERCHANT01459
        }
        break;
      }
      case 4:
      {
        if( actor == 1009087 || actorId == 1009087 ) // ACTOR10 = CAVALRYMAN01459
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CAVALRYMAN01459
          }
        }
        if( actor == 1009082 || actorId == 1009082 ) // ACTOR3 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(CutScene, FadeIn), id=unknown
        }
        if( actor == 1009083 || actorId == 1009083 ) // ACTOR4 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( actor == 1009084 || actorId == 1009084 ) // ACTOR5 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( actor == 1009085 || actorId == 1009085 ) // ACTOR6 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( actor == 1009086 || actorId == 1009086 ) // ACTOR7 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 1006481 || actorId == 1006481 ) // ACTOR8 = LANCEFER
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          // +Callback Scene00025: Normal(Talk, TargetCanMove), id=LANCEFER
        }
        if( actor == 1006480 || actorId == 1006480 ) // ACTOR9 = OURDILIC
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=OURDILIC
        }
        if( actor == 1009088 || actorId == 1009088 ) // ACTOR11 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        if( actor == 1009081 || actorId == 1009081 ) // ACTOR2 = MERCHANT01459
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=MERCHANT01459
        }
        break;
      }
      case 5:
      {
        if( actor == 1009087 || actorId == 1009087 ) // ACTOR10 = CAVALRYMAN01459
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=CAVALRYMAN01459
          }
        }
        if( actor == 1009082 || actorId == 1009082 ) // ACTOR3 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
        }
        if( actor == 1009083 || actorId == 1009083 ) // ACTOR4 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( actor == 1009084 || actorId == 1009084 ) // ACTOR5 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( actor == 1009085 || actorId == 1009085 ) // ACTOR6 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        if( actor == 1009086 || actorId == 1009086 ) // ACTOR7 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        if( actor == 1006481 || actorId == 1006481 ) // ACTOR8 = LANCEFER
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=LANCEFER
        }
        if( actor == 1006480 || actorId == 1006480 ) // ACTOR9 = OURDILIC
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=OURDILIC
        }
        if( actor == 1009088 || actorId == 1009088 ) // ACTOR11 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
        }
        if( actor == 1009081 || actorId == 1009081 ) // ACTOR2 = MERCHANT01459
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=MERCHANT01459
        }
        break;
      }
      case 6:
      {
        if( actor == 1006444 || actorId == 1006444 ) // ACTOR1 = DRILLEMONT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=DRILLEMONT
          }
        }
        if( actor == 1009082 || actorId == 1009082 ) // ACTOR3 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        if( actor == 1009083 || actorId == 1009083 ) // ACTOR4 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( actor == 1009084 || actorId == 1009084 ) // ACTOR5 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        if( actor == 1009085 || actorId == 1009085 ) // ACTOR6 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
        }
        if( actor == 1009086 || actorId == 1009086 ) // ACTOR7 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
        }
        if( actor == 1006481 || actorId == 1006481 ) // ACTOR8 = LANCEFER
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=LANCEFER
        }
        if( actor == 1006480 || actorId == 1006480 ) // ACTOR9 = OURDILIC
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=OURDILIC
        }
        if( actor == 1009087 || actorId == 1009087 ) // ACTOR10 = CAVALRYMAN01459
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=CAVALRYMAN01459
        }
        if( actor == 1009088 || actorId == 1009088 ) // ACTOR11 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
        }
        break;
      }
      case 7:
      {
        if( actor == 1006384 || actorId == 1006384 ) // ACTOR0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00049( player ); // Scene00049: Normal(CutScene, FadeIn), id=unknown
          }
        }
        if( actor == 1006444 || actorId == 1006444 ) // ACTOR1 = DRILLEMONT
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=DRILLEMONT
        }
        break;
      }
      case 255:
      {
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR12 = SLAFBORN
        {
          Scene00051( player ); // Scene00051: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SLAFBORN
        }
        if( actor == 1006384 || actorId == 1006384 ) // ACTOR0 = HAURCHEFANT
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=HAURCHEFANT
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
    onProgress( player, param1, param1, 3, param1 );
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
    if( player.getQuestUI8AL( getId() ) == 2 )
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse318:66995 calling [BranchTrue]Scene00001: Normal(CutScene, FadeIn, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00002: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00003: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00004: Normal(Talk, TargetCanMove), id=MERCHANT01459" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00005: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling [BranchTrue]Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling [BranchTrue]Scene00015: Normal(Talk, TargetCanMove), id=LANCEFER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00016: Normal(Talk, TargetCanMove), id=OURDILIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00017: Normal(Talk, TargetCanMove), id=MERCHANT01459" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00018: Normal(Talk, TargetCanMove), id=CAVALRYMAN01459" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00019: Normal(CutScene, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00024: Normal(None), id=unknown" );
    Scene00025( player );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling [BranchTrue]Scene00025: Normal(Talk, TargetCanMove), id=LANCEFER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00026: Normal(Talk, TargetCanMove), id=OURDILIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00028: Normal(Talk, TargetCanMove), id=MERCHANT01459" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00029: Normal(Talk, TargetCanMove), id=CAVALRYMAN01459" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00035: Normal(Talk, TargetCanMove), id=LANCEFER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00036: Normal(Talk, TargetCanMove), id=OURDILIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00038: Normal(Talk, TargetCanMove), id=MERCHANT01459" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00039: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00045: Normal(Talk, TargetCanMove), id=LANCEFER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00046: Normal(Talk, TargetCanMove), id=OURDILIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00047: Normal(Talk, TargetCanMove), id=CAVALRYMAN01459" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00049: Normal(CutScene, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 49, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00050: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00051: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "GaiUse318:66995 calling Scene00052: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse318 );
