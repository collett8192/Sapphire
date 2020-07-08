// FFXIVTheMovie.ParserV3
//fix: black screen, skip dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnd103 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnd103() : Sapphire::ScriptAPI::EventScript( 67780 ){}; 
  ~HeaVnd103() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 4 entries
  //SEQ_3, 2 entries
  //SEQ_4, 3 entries
  //SEQ_5, 3 entries
  //SEQ_6, 2 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1016819
  //ACTOR1 = 1016810
  //ACTOR10 = 1017022
  //ACTOR11 = 1017023
  //ACTOR12 = 5010000
  //ACTOR2 = 1016811
  //ACTOR3 = 1016822
  //ACTOR4 = 1012078
  //ACTOR5 = 1016825
  //ACTOR6 = 1016882
  //ACTOR7 = 1016813
  //ACTOR8 = 1017011
  //ACTOR9 = 1016812
  //CUTSCENEN01 = 1174
  //CUTSCENEN02 = 1175
  //CUTSCENEN03 = 1176
  //EOBJECT0 = 2006956
  //INSTANCEDUNGEON0 = 44
  //LOCACTION0 = 962
  //LOCACTION1 = 967
  //LOCACTION2 = 958
  //LOCACTION3 = 954
  //LOCACTOR0 = 6275933
  //LOCACTOR1 = 1013802
  //LOCACTOR2 = 6211082
  //LOCACTOR3 = 1012904
  //LOCACTOR4 = 6211059
  //LOCACTOR5 = 6276424
  //LOCBGM0 = 322
  //LOCIDLE0 = 983
  //LOCQUEST0 = 66608
  //LOCSCREENIMAGE0 = 402
  //LOCSE0 = 99
  //LOCSE2 = 101
  //LOCSE3 = 102
  //LOCSE4 = 103
  //LOCSE5 = 104
  //POPRANGE0 = 6253216
  //POPRANGE1 = 6211086
  //TERRITORYTYPE0 = 400

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016819 || param2 == 1016819 ) // ACTOR0 = unknown
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=unknown
        }
        if( param1 == 1016810 || param2 == 1016810 ) // ACTOR1 = AYMERIC
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016811 || param2 == 1016811 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          }
        }
        if( param1 == 1016822 || param2 == 1016822 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        if( param1 == 2006956 || param2 == 2006956 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1012078 || param2 == 1012078 ) // ACTOR4 = MOGHAN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MOGHAN
        }
        if( param1 == 1016825 || param2 == 1016825 ) // ACTOR5 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016882 || param2 == 1016882 ) // ACTOR6 = AYMERIC
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016813 || param2 == 1016813 ) // ACTOR7 = AYMERIC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=AYMERIC
          }
        }
        if( param1 == 1017011 || param2 == 1017011 ) // ACTOR8 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 4:
      {
        if( param1 == 1016812 || param2 == 1016812 ) // ACTOR9 = WYVERN02244
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, Message, TargetCanMove), id=WYVERN02244
          }
        }
        if( param1 == 1017022 || param2 == 1017022 ) // ACTOR10 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017023 || param2 == 1017023 ) // ACTOR11 = AYMERIC
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        break;
      }
      case 5:
      {
        if( param1 == 1016812 || param2 == 1016812 ) // ACTOR9 = WYVERN02244
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=WYVERN02244
        }
        if( param1 == 1017022 || param2 == 1017022 ) // ACTOR10 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017023 || param2 == 1017023 ) // ACTOR11 = AYMERIC
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        break;
      }
      case 6:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00017( player ); // Scene00017: Normal(CutScene), id=unknown
        }
        if( param1 == 1016812 || param2 == 1016812 ) // ACTOR9 = WYVERN02244
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=WYVERN02244
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017011 || param2 == 1017011 ) // ACTOR8 = ALPHINAUD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00020: Normal(CutScene), id=unknown
          // +Callback Scene00021: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( param1 == 1016813 || param2 == 1016813 ) // ACTOR7 = AYMERIC
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1016812 || param2 == 1016812 ) // ACTOR9 = WYVERN02244
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=WYVERN02244
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
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "HeaVnd103:67780 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00005: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00006: Normal(Talk, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00008: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00011: Normal(Talk, Message, TargetCanMove), id=WYVERN02244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00013: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00014: Normal(Talk, TargetCanMove), id=WYVERN02244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00017: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00018: Normal(Talk, TargetCanMove), id=WYVERN02244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00019: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling [BranchTrue]Scene00020: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling [BranchChain]Scene00021: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00022: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd103:67780 calling Scene00023: Normal(Talk, TargetCanMove), id=WYVERN02244" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnd103 );
