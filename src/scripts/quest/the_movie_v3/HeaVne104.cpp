// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVne104 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVne104() : Sapphire::ScriptAPI::EventScript( 67880 ){}; 
  ~HeaVne104() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 4 entries
  //SEQ_5, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1006325
  //ACTOR1 = 1017728
  //ACTOR10 = 1017737
  //ACTOR11 = 1016815
  //ACTOR2 = 1017729
  //ACTOR3 = 1017732
  //ACTOR4 = 1017730
  //ACTOR5 = 1017731
  //ACTOR6 = 1017733
  //ACTOR7 = 1017734
  //ACTOR8 = 1017735
  //ACTOR9 = 1017736
  //LOCACTION0 = 953
  //LOCACTION1 = 1071
  //LOCACTION2 = 1022
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1017687
  //LOCACTOR2 = 1017698
  //LOCACTOR3 = 6433062
  //LOCACTOR4 = 1017689
  //LOCFACIAL0 = 608
  //LOCIDLE0 = 4294
  //LOCIDLE1 = 4295
  //LOCIDLE2 = 4199

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR0 = BLOEIDIN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=BLOEIDIN
        }
        if( param1 == 1017728 || param2 == 1017728 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017729 || param2 == 1017729 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 1:
      {
        if( param1 == 1017728 || param2 == 1017728 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR0 = BLOEIDIN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        if( param1 == 1017729 || param2 == 1017729 ) // ACTOR2 = ALISAIE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 2:
      {
        if( param1 == 1017732 || param2 == 1017732 ) // ACTOR3 = GABU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=GABU
          }
        }
        if( param1 == 1017730 || param2 == 1017730 ) // ACTOR4 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017731 || param2 == 1017731 ) // ACTOR5 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR0 = BLOEIDIN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        break;
      }
      case 3:
      {
        if( param1 == 1017733 || param2 == 1017733 ) // ACTOR6 = GABU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=GABU
          }
        }
        if( param1 == 1017730 || param2 == 1017730 ) // ACTOR4 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017731 || param2 == 1017731 ) // ACTOR5 = ALISAIE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR0 = BLOEIDIN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        break;
      }
      case 4:
      {
        if( param1 == 1017734 || param2 == 1017734 ) // ACTOR7 = GABU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=GABU
          }
        }
        if( param1 == 1017730 || param2 == 1017730 ) // ACTOR4 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017731 || param2 == 1017731 ) // ACTOR5 = ALISAIE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR0 = BLOEIDIN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        break;
      }
      case 5:
      {
        if( param1 == 1017735 || param2 == 1017735 ) // ACTOR8 = GABU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, FadeIn, TargetCanMove), id=GABU
          }
        }
        if( param1 == 1017730 || param2 == 1017730 ) // ACTOR4 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017731 || param2 == 1017731 ) // ACTOR5 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR0 = BLOEIDIN
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=BLOEIDIN
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017736 || param2 == 1017736 ) // ACTOR9 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017737 || param2 == 1017737 ) // ACTOR10 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1016815 || param2 == 1016815 ) // ACTOR11 = GABU
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=GABU
        }
        if( param1 == 1006325 || param2 == 1006325 ) // ACTOR0 = BLOEIDIN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=BLOEIDIN
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVne104:67880 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00005: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00010: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00014: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00018: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00019: Normal(Talk, FadeIn, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00022: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00023: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00025: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVne104:67880 calling Scene00026: Normal(Talk, TargetCanMove), id=BLOEIDIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne104 );
