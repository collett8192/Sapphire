// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse414 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse414() : Sapphire::ScriptAPI::EventScript( 65618 ){}; 
  ~GaiUse414() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1010147
  //ACTOR1 = 1010039
  //ACTOR2 = 1010109
  //ACTOR3 = 1010110
  //ACTOR4 = 1010111
  //ACTOR5 = 1010112
  //ACTOR6 = 1010040
  //ACTOR7 = 1010041
  //CUTSCENEN01 = 619
  //CUTSCENEN02 = 620
  //EOBJECT0 = 2004661
  //EVENTACTIONWAITING2MIDDLE = 12
  //LEVELIDNPC01 = 5035266

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( actor == 2004661 || actorId == 2004661 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00003: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1010039 || actorId == 1010039 ) // ACTOR1 = MINFILIA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010109 || actorId == 1010109 ) // ACTOR2 = THANCRED
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010110 || actorId == 1010110 ) // ACTOR3 = YDA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010111 || actorId == 1010111 ) // ACTOR4 = PAPALYMO
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1010112 || actorId == 1010112 ) // ACTOR5 = YSHTOLA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 2:
      {
        if( actor == 1010039 || actorId == 1010039 ) // ACTOR1 = MINFILIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=MINFILIA
          }
        }
        if( actor == 1010040 || actorId == 1010040 ) // ACTOR6 = MOENBRYDA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MOENBRYDA
        }
        if( actor == 1010109 || actorId == 1010109 ) // ACTOR2 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010110 || actorId == 1010110 ) // ACTOR3 = YDA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010111 || actorId == 1010111 ) // ACTOR4 = PAPALYMO
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1010112 || actorId == 1010112 ) // ACTOR5 = YSHTOLA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 255:
      {
        if( actor == 1010147 || actorId == 1010147 ) // ACTOR0 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(CutScene), id=unknown
          // +Callback Scene00016: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1010041 || actorId == 1010041 ) // ACTOR7 = MOENBRYDA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MOENBRYDA
        }
        if( actor == 1010109 || actorId == 1010109 ) // ACTOR2 = THANCRED
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010110 || actorId == 1010110 ) // ACTOR3 = YDA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010111 || actorId == 1010111 ) // ACTOR4 = PAPALYMO
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1010112 || actorId == 1010112 ) // ACTOR5 = YSHTOLA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=YSHTOLA
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "GaiUse414:65618 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling [BranchTrue]Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00004: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00006: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00007: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00010: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00012: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00013: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00014: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00015: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling [BranchTrue]Scene00016: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00017: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00018: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00019: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00020: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse414:65618 calling Scene00021: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse414 );
