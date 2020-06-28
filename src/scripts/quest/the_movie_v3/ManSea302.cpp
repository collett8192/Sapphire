// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManSea302 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManSea302() : Sapphire::ScriptAPI::EventScript( 66217 ){}; 
  ~ManSea302() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 12 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1004885
  //ACTOR1 = 1002388
  //ACTOR2 = 1004883
  //ACTOR3 = 1004884
  //ACTOR4 = 1004888
  //ACTOR5 = 1004999
  //ACTOR6 = 1005000
  //ACTOR7 = 1005001
  //ACTOR8 = 1005002
  //EOBJECT0 = 2001656
  //EOBJECT1 = 2001807
  //EVENTRANGE0 = 4126868
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1005105
  //NCUT0 = 218
  //QUESTBATTLE0 = 48
  //TERRITORYTYPE0 = 279

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, YesNo, QuestOffer, QuestAccept, TargetCanMove), id=STORMOFFICER
        break;
      }
      case 1:
      {
        if( actor == 1002388 || actorId == 1002388 ) // ACTOR1 = STORMPERSONNEL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, FadeIn, TargetCanMove), id=STORMPERSONNEL
          }
        }
        if( actor == 1004883 || actorId == 1004883 ) // ACTOR2 = FLAMEOFFICER
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=FLAMEOFFICER
        }
        if( actor == 1004884 || actorId == 1004884 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        if( actor == 1004885 || actorId == 1004885 ) // ACTOR0 = STORMOFFICER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=STORMOFFICER
        }
        break;
      }
      case 2:
      {
        if( actor == 1004888 || actorId == 1004888 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(QuestBattle, YesNo), id=unknown
          }
        }
        if( actor == 4126868 || actorId == 4126868 ) // EVENTRANGE0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(QuestBattle, YesNo), id=unknown
        }
        if( actor == 1004999 || actorId == 1004999 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1005000 || actorId == 1005000 ) // ACTOR6 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1005001 || actorId == 1005001 ) // ACTOR7 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1005002 || actorId == 1005002 ) // ACTOR8 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1002388 || actorId == 1002388 ) // ACTOR1 = STORMPERSONNEL
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          // +Callback Scene00012: Normal(Talk, TargetCanMove), id=STORMPERSONNEL
        }
        if( actor == 1004883 || actorId == 1004883 ) // ACTOR2 = FLAMEOFFICER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=FLAMEOFFICER
        }
        if( actor == 1004884 || actorId == 1004884 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        if( actor == 1004885 || actorId == 1004885 ) // ACTOR0 = STORMOFFICER
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=STORMOFFICER
        }
        if( actor == 2001656 || actorId == 2001656 ) // EOBJECT0 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          // +Callback Scene00017: Normal(None), id=unknown
        }
        if( actor == 2001807 || actorId == 2001807 ) // EOBJECT1 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1002388 || actorId == 1002388 ) // ACTOR1 = STORMPERSONNEL
        {
          Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STORMPERSONNEL
        }
        if( actor == 1004883 || actorId == 1004883 ) // ACTOR2 = FLAMEOFFICER
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=FLAMEOFFICER
        }
        if( actor == 1004884 || actorId == 1004884 ) // ACTOR3 = SERPENTOFFICER
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        if( actor == 1004885 || actorId == 1004885 ) // ACTOR0 = STORMOFFICER
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=STORMOFFICER
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
    player.sendDebug( "ManSea302:66217 calling Scene00000: Normal(Talk, YesNo, QuestOffer, QuestAccept, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00001: Normal(Talk, FadeIn, TargetCanMove), id=STORMPERSONNEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00002: Normal(Talk, TargetCanMove), id=FLAMEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00003: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00004: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00005: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00006: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling [BranchTrue]Scene00012: Normal(Talk, TargetCanMove), id=STORMPERSONNEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00013: Normal(Talk, TargetCanMove), id=FLAMEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00014: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00015: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling [BranchTrue]Scene00017: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=STORMPERSONNEL" );
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
    player.sendDebug( "ManSea302:66217 calling Scene00021: Normal(Talk, TargetCanMove), id=FLAMEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00022: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "ManSea302:66217 calling Scene00023: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }
};

EXPOSE_SCRIPT( ManSea302 );
