// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVne108 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVne108() : Sapphire::ScriptAPI::EventScript( 67884 ){}; 
  ~HeaVne108() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 5 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1017759
  //ACTOR1 = 1017757
  //ACTOR2 = 1017758
  //ACTOR3 = 1017755
  //ACTOR4 = 1006224
  //ACTOR5 = 1017760
  //ACTOR6 = 1017761
  //ACTOR7 = 1017762
  //CUTSCENEN01 = 1262
  //ITEM0 = 2001354
  //LOCACTOR0 = 6433883
  //LOCACTOR1 = 6433884
  //LOCACTOR2 = 6433887
  //RITEM0 = 2995
  //RITEM1 = 3306

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        if( param1 == 1017759 || param2 == 1017759 ) // ACTOR0 = PAPALYMO
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PAPALYMO
        }
        if( param1 == 1017757 || param2 == 1017757 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017758 || param2 == 1017758 ) // ACTOR2 = YDA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YDA
        }
        if( param1 == 1017755 || param2 == 1017755 ) // ACTOR3 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 1006224 || param2 == 1006224 ) // ACTOR4 = TALEBOT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: NpcTrade(None), id=unknown
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=TALEBOT
          }
        }
        if( param1 == 1017760 || param2 == 1017760 ) // ACTOR5 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017758 || param2 == 1017758 ) // ACTOR2 = YDA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YDA
        }
        if( param1 == 1017759 || param2 == 1017759 ) // ACTOR0 = PAPALYMO
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( param1 == 1017755 || param2 == 1017755 ) // ACTOR3 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 2:
      {
        if( param1 == 1017760 || param2 == 1017760 ) // ACTOR5 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1006224 || param2 == 1006224 ) // ACTOR4 = TALEBOT
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=TALEBOT
        }
        if( param1 == 1017755 || param2 == 1017755 ) // ACTOR3 = ALISAIE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
          // +Callback Scene00014: Normal(TargetCanMove), id=unknown
        }
        break;
      }
      case 3:
      {
        if( param1 == 1017761 || param2 == 1017761 ) // ACTOR6 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00016: Normal(CutScene), id=unknown
          }
          else
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1006224 || param2 == 1006224 ) // ACTOR4 = TALEBOT
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=TALEBOT
        }
        if( param1 == 1017755 || param2 == 1017755 ) // ACTOR3 = ALISAIE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017762 || param2 == 1017762 ) // ACTOR7 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017755 || param2 == 1017755 ) // ACTOR3 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
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
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVne108:67884 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00003: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00005: NpcTrade(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling [BranchTrue]Scene00006: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00008: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00009: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00012: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling [BranchTrue]Scene00014: Normal(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling [BranchTrue]Scene00016: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling [BranchFalse]Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00018: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVne108:67884 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.sendDebug( "HeaVne108:67884 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne108 );
