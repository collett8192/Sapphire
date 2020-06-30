// FFXIVTheMovie.ParserV3
//fix: skip dungeon, fix black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna404 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna404() : Sapphire::ScriptAPI::EventScript( 67176 ){}; 
  ~HeaVna404() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 7 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_5, 1 entries
  //SEQ_6, 2 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1012780
  //ACTOR1 = 1012776
  //ACTOR10 = 1013101
  //ACTOR11 = 1013227
  //ACTOR12 = 1012580
  //ACTOR13 = 1012377
  //ACTOR14 = 1012337
  //ACTOR2 = 1012777
  //ACTOR3 = 1012778
  //ACTOR4 = 1012779
  //ACTOR5 = 1012781
  //ACTOR6 = 1012782
  //ACTOR7 = 1012212
  //ACTOR8 = 1013381
  //ACTOR9 = 5010000
  //CUTSCENEN01 = 856
  //CUTSCENEN02 = 857
  //INSTANCEDUNGEON0 = 34
  //LOCACTOR0 = 5864726
  //LOCACTOR1 = 5864729
  //LOCACTOR2 = 5864731
  //LOCACTOR3 = 5864732
  //LOCACTOR4 = 5864734
  //LOCACTOR5 = 5864735
  //LOCACTOR6 = 5864736
  //LOCMUSIC0 = 317
  //LOCSCREENIMAGE0 = 305
  //POPRANGE0 = 5865411
  //POPRANGE1 = 5827750
  //TERRITORYTYPE0 = 419

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012780 || actorId == 1012780 ) // ACTOR0 = HILDA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=HILDA
        }
        if( actor == 1012776 || actorId == 1012776 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012777 || actorId == 1012777 ) // ACTOR2 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1012778 || actorId == 1012778 ) // ACTOR3 = LUCIA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1012779 || actorId == 1012779 ) // ACTOR4 = HAURCHEFANT
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1012781 || actorId == 1012781 ) // ACTOR5 = REVOLUTIONARY1
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
        }
        if( actor == 1012782 || actorId == 1012782 ) // ACTOR6 = REVOLUTIONARY2A
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2A
        }
        break;
      }
      case 1:
      {
        if( actor == 1012778 || actorId == 1012778 ) // ACTOR3 = LUCIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LUCIA
          }
        }
        if( actor == 1012776 || actorId == 1012776 ) // ACTOR1 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012777 || actorId == 1012777 ) // ACTOR2 = TATARU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1012779 || actorId == 1012779 ) // ACTOR4 = HAURCHEFANT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1012780 || actorId == 1012780 ) // ACTOR0 = HILDA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( actor == 1012781 || actorId == 1012781 ) // ACTOR5 = REVOLUTIONARY1
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1
        }
        if( actor == 1012782 || actorId == 1012782 ) // ACTOR6 = REVOLUTIONARY2A
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2A
        }
        break;
      }
      case 2:
      {
        if( actor == 1012212 || actorId == 1012212 ) // ACTOR7 = TEMPLEKNIGHT01640
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, Message, TargetCanMove), id=TEMPLEKNIGHT01640
          }
        }
        if( actor == 1013381 || actorId == 1013381 ) // ACTOR8 = TATARU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 3:
      {
        if( actor == 1012212 || actorId == 1012212 ) // ACTOR7 = TEMPLEKNIGHT01640
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640
        }
        if( actor == 1013381 || actorId == 1013381 ) // ACTOR8 = TATARU
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00019( player ); // Scene00019: Normal(CutScene), id=unknown
        }
        if( actor == 1013381 || actorId == 1013381 ) // ACTOR8 = TATARU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 5:
      {
        Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640
        break;
      }
      case 6:
      {
        if( actor == 1013101 || actorId == 1013101 ) // ACTOR10 = HOUSEFORTEMPSGUARD01580
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSGUARD01580
          }
        }
        if( actor == 1012212 || actorId == 1012212 ) // ACTOR7 = TEMPLEKNIGHT01640
        {
          Scene00024( player );
        }
        break;
      }
      case 255:
      {
        if( actor == 1013227 || actorId == 1013227 ) // ACTOR11 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012580 || actorId == 1012580 ) // ACTOR12 = TATARU
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1012377 || actorId == 1012377 ) // ACTOR13 = HOUSEFORTEMPSSTEWARD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD
        }
        if( actor == 1012337 || actorId == 1012337 ) // ACTOR14 = BUTLER01580
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=BUTLER01580
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
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna404:67176 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00004: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00005: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00006: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00007: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2A" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00008: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00011: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00012: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00013: Normal(Talk, TargetCanMove), id=REVOLUTIONARY1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00014: Normal(Talk, TargetCanMove), id=REVOLUTIONARY2A" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00015: Normal(Talk, Message, TargetCanMove), id=TEMPLEKNIGHT01640" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00016: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00017: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00018: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00020: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00021: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00022: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSGUARD01580" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00023: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 419, 17, 16, -7.5, -1.57 );
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00024: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT01640" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00026: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00027: Normal(Talk, TargetCanMove), id=HOUSEFORTEMPSSTEWARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna404:67176 calling Scene00028: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna404 );
