// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse614 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse614() : Sapphire::ScriptAPI::EventScript( 65962 ){}; 
  ~GaiUse614() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTACTIONEND = 82
  //ACTIONTIMELINEEVENTACTIONLOOP = 81
  //ACTIONTIMELINEEVENTLINK = 1002
  //ACTOR0 = 1010992
  //ACTOR1 = 1010993
  //ACTOR2 = 1010994
  //ACTOR3 = 1010995
  //ACTOR4 = 1010996
  //ACTOR5 = 1001353
  //ACTOR6 = 1011623
  //CUTSCENEN01 = 712
  //EOBJECT0 = 2005069
  //EOBJECT1 = 2005071
  //EOBJECT2 = 2005070
  //EOBJECT3 = 2005072
  //EVENTACTIONLEVELSQUATSHORT = 20
  //EVENTACTIONWAITING2MIDDLE = 12
  //EVENTACTIONWAITING3LONG = 13
  //ITEM0 = 2001545
  //LOCACTOR0 = 5608163
  //LOCACTOR1 = 5608164
  //LOCACTOR2 = 5608165
  //LOCACTOR3 = 5608166
  //LOCACTOR4 = 1011128
  //LOCPOSACTOR0 = 5673522
  //LOCPOSACTOR1 = 5673523
  //LOCPOSACTOR2 = 5673524
  //POPRANGE0 = 5610991

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1010992 || actorId == 1010992 ) // ACTOR0 = MINFILIA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010993 || actorId == 1010993 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010994 || actorId == 1010994 ) // ACTOR2 = YSHTOLA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1010995 || actorId == 1010995 ) // ACTOR3 = YDA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010996 || actorId == 1010996 ) // ACTOR4 = PAPALYMO
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        break;
      }
      case 1:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MOMODI
        break;
      }
      case 2:
      {
        if( actor == 2005069 || actorId == 2005069 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
            // +Callback Scene00008: Normal(None), id=unknown
          }
        }
        if( actor == 2005071 || actorId == 2005071 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1001353 || actorId == 1001353 ) // ACTOR5 = MOMODI
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MOMODI
        }
        break;
      }
      case 3:
      {
        if( actor == 2005070 || actorId == 2005070 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
            // +Callback Scene00012: Normal(None), id=unknown
          }
        }
        if( actor == 2005071 || actorId == 2005071 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          // +Callback Scene00014: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( actor == 2005072 || actorId == 2005072 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(FadeIn, QuestGimmickReaction), id=unknown
            // +Callback Scene00016: Normal(CutScene), id=unknown
          }
        }
        if( actor == 2005071 || actorId == 2005071 ) // EOBJECT1 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          // +Callback Scene00018: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( actor == 1001353 || actorId == 1001353 ) // ACTOR5 = MOMODI
        {
          Scene00019( player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOMODI
        }
        if( actor == 1011623 || actorId == 1011623 ) // ACTOR6 = LAURENTIUS
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=LAURENTIUS
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
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse614:65962 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00004: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00005: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00006: Normal(Talk, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00010: Normal(Talk, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling [BranchTrue]Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling [BranchTrue]Scene00014: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00015: Normal(FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling [BranchTrue]Scene00016: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling [BranchTrue]Scene00018: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00020( player );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling [BranchTrue]Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse614:65962 calling Scene00021: Normal(Talk, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse614 );
