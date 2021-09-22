// FFXIVTheMovie.ParserV3.3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea057 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea057() : Sapphire::ScriptAPI::EventScript( 66005 ){}; 
  ~SubSea057() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 7 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 1 entries
  //SEQ_6, 2 entries
  //SEQ_7, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002626
  //ACTOR1 = 1002633
  //ACTOR10 = 1000972
  //ACTOR2 = 1002645
  //ACTOR3 = 1002644
  //ACTOR4 = 1002646
  //ACTOR5 = 1002647
  //ACTOR6 = 1002648
  //ACTOR7 = 1002649
  //ACTOR8 = 1002650
  //ACTOR9 = 1003349
  //CUTSCENE02 = 204
  //CUTSCENE03 = 205
  //CUTSCENE04 = 206
  //EOBJECT0 = 2001734
  //EVENTACTION = 35
  //EVENTACTIONSEARCH = 1
  //LOCACTOR1 = 1003289
  //LOCACTOR2 = 1000970
  //LOCACTOR3 = 1000974
  //LOCPOSACTOR2 = 4155969
  //LOCPOSACTOR3 = 4155970
  //LOGMESSAGERECOMMENDLISTUNLOCK = 3701
  //QUESTBATTLE0 = 29
  //REWARD0 = 9
  //SEQ0ACTOR0LQ = 90
  //TERRITORYTYPE0 = 272
  //TERRITORYTYPE1 = 134
  //UNLOCKIMAGEINN = 18
  //UNLOCKIMAGELEVE = 20

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=STAELWYRN
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=STAELWYRN
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=GRYNEWYDA
        break;
      }
      case 2:
      {
        if( param1 == 1002645 || param2 == 1002645 ) // ACTOR2 = AYLMER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=AYLMER
          }
          break;
        }
        if( param1 == 1002644 || param2 == 1002644 ) // ACTOR3 = SEVRIN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SEVRIN
          break;
        }
        if( param1 == 1002646 || param2 == 1002646 ) // ACTOR4 = EYRIMHUS
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=EYRIMHUS
          break;
        }
        if( param1 == 1002647 || param2 == 1002647 ) // ACTOR5 = SOZAIRARZAI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=SOZAIRARZAI
          break;
        }
        if( param1 == 1002648 || param2 == 1002648 ) // ACTOR6 = IREZUMI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=IREZUMI
          break;
        }
        if( param1 == 1002649 || param2 == 1002649 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002650 || param2 == 1002650 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1002646 || param2 == 1002646 ) // ACTOR4 = EYRIMHUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=EYRIMHUS
          }
          break;
        }
        if( param1 == 1002644 || param2 == 1002644 ) // ACTOR3 = SEVRIN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=SEVRIN
          break;
        }
        if( param1 == 1002648 || param2 == 1002648 ) // ACTOR6 = IREZUMI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=IREZUMI
          break;
        }
        if( param1 == 1002649 || param2 == 1002649 ) // ACTOR7 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002650 || param2 == 1002650 ) // ACTOR8 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002647 || param2 == 1002647 ) // ACTOR5 = SOZAIRARZAI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=SOZAIRARZAI
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1002647 || param2 == 1002647 ) // ACTOR5 = SOZAIRARZAI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=SOZAIRARZAI
          }
          break;
        }
        if( param1 == 1002648 || param2 == 1002648 ) // ACTOR6 = IREZUMI
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=IREZUMI
          break;
        }
        if( param1 == 1002649 || param2 == 1002649 ) // ACTOR7 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002650 || param2 == 1002650 ) // ACTOR8 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1002644 || param2 == 1002644 ) // ACTOR3 = SEVRIN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=SEVRIN
          break;
        }
        if( param1 == 2001734 || param2 == 2001734 ) // EOBJECT0 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type != 2 ) Scene00026( player ); // Scene00026: Normal(CutScene, AutoFadeIn), id=unknown
        break;
      }
      case 6:
      {
        if( param1 == 1002626 || param2 == 1002626 ) // ACTOR0 = STAELWYRN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, FadeIn, TargetCanMove), id=STAELWYRN
          }
          break;
        }
        if( param1 == 1003349 || param2 == 1003349 ) // ACTOR9 = SEVRIN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=SEVRIN
          break;
        }
        break;
      }
      case 7:
      {
        if( type != 2 ) Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=STAELWYRN
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00030( player ); // Scene00030: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=BADERON
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
    player.updateQuest( getId(), 6 );
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=STAELWYRN" );
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
    player.sendDebug( "SubSea057:66005 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=STAELWYRN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00002: Normal(Talk, TargetCanMove), id=GRYNEWYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=AYLMER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00004: Normal(Talk, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00005: Normal(Talk, TargetCanMove), id=EYRIMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00006: Normal(Talk, TargetCanMove), id=SOZAIRARZAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00007: Normal(Talk, TargetCanMove), id=IREZUMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=EYRIMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00013: Normal(Talk, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00014: Normal(Talk, TargetCanMove), id=IREZUMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00017: Normal(Talk, TargetCanMove), id=SOZAIRARZAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00019: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=SOZAIRARZAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        //quest battle
        player.eventFinish( getId(), 1 );
        auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
        pTeriMgr.createAndJoinQuestBattle( player, 29 );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00020: Normal(Talk, TargetCanMove), id=IREZUMI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00023: Normal(Talk, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00026: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00027: Normal(Talk, FadeIn, TargetCanMove), id=STAELWYRN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00028: Normal(Talk, TargetCanMove), id=SEVRIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00029: Normal(Talk, TargetCanMove), id=STAELWYRN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "SubSea057:66005 calling Scene00030: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=BADERON" );
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
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( SubSea057 );
