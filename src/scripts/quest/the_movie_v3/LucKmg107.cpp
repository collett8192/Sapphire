// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmg107 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmg107() : Sapphire::ScriptAPI::EventScript( 69215 ){}; 
  ~LucKmg107() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_3, 1 entries
  //SEQ_4, 4 entries
  //SEQ_5, 2 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1031746
  //ACTOR1 = 1031747
  //ACTOR10 = 1031755
  //ACTOR11 = 1031756
  //ACTOR12 = 1031748
  //ACTOR13 = 1031760
  //ACTOR14 = 1031757
  //ACTOR15 = 1031759
  //ACTOR16 = 1031758
  //ACTOR2 = 1027306
  //ACTOR3 = 1031749
  //ACTOR4 = 1031750
  //ACTOR5 = 1031751
  //ACTOR6 = 1031752
  //ACTOR7 = 1031753
  //ACTOR8 = 1027462
  //ACTOR9 = 1031754
  //BGMMUSICEX3EVENTBATTLE01 = 651
  //CUTSCENE0 = 2191
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORCHAINUZZ = 1028120
  //LOCACTORKAISHIRR = 1028121
  //LOCACTORWRENDEN = 1029472
  //LOCBINDACTOR0 = 8132573
  //LOCBINDACTOR1 = 8132738
  //LOCBINDACTOR2 = 8132780
  //LOCBINDACTOR3 = 8132781
  //LOCBINDACTOR4 = 8132782

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1031746 || param2 == 1031746 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031747 || param2 == 1031747 ) // ACTOR1 = KAISHIRR
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1027306 || param2 == 1027306 ) // ACTOR2 = HASTELOT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HASTELOT
          }
          break;
        }
        if( param1 == 1031749 || param2 == 1031749 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031750 || param2 == 1031750 ) // ACTOR4 = KAISHIRR
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1031751 || param2 == 1031751 ) // ACTOR5 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1031752 || param2 == 1031752 ) // ACTOR6 = KAISHIRR
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1027306 || param2 == 1027306 ) // ACTOR2 = HASTELOT
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HASTELOT
          break;
        }
        break;
      }
      case 3:
      {
        Scene00009( player ); // Scene00009: Normal(Talk, FadeIn, Menu), id=unknown
        break;
      }
      case 4:
      {
        if( param1 == 1027462 || param2 == 1027462 ) // ACTOR8 = TRISTOL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TRISTOL
          }
          break;
        }
        if( param1 == 1031754 || param2 == 1031754 ) // ACTOR9 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031755 || param2 == 1031755 ) // ACTOR10 = KAISHIRR
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1031756 || param2 == 1031756 ) // ACTOR11 = CHAINUZZ
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1031748 || param2 == 1031748 ) // ACTOR12 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1027462 || param2 == 1027462 ) // ACTOR8 = TRISTOL
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=TRISTOL
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1031760 || param2 == 1031760 ) // ACTOR13 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1031757 || param2 == 1031757 ) // ACTOR14 = WRENDEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=WRENDEN
          break;
        }
        if( param1 == 1031759 || param2 == 1031759 ) // ACTOR15 = KAISHIRR
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1031758 || param2 == 1031758 ) // ACTOR16 = ALPHINAUD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
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
    player.updateQuest( getId(), 4 );
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
    player.sendDebug( "LucKmg107:69215 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmg107:69215 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00002: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00003: Normal(Talk, TargetCanMove), id=HASTELOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00005: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00007: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00008: Normal(Talk, TargetCanMove), id=HASTELOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00009: Normal(Talk, FadeIn, Menu), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00010: Normal(Talk, TargetCanMove), id=TRISTOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00012: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00013: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00014: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00015: Normal(Talk, TargetCanMove), id=TRISTOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00017: Normal(Talk, TargetCanMove), id=WRENDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00018: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmg107:69215 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmg107 );
