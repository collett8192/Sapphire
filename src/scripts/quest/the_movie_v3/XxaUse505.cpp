// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class XxaUse505 : public Sapphire::ScriptAPI::EventScript
{
public:
  XxaUse505() : Sapphire::ScriptAPI::EventScript( 69424 ){}; 
  ~XxaUse505() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 7 entries
  //SEQ_3, 7 entries
  //SEQ_4, 5 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1010858
  //ACTOR1 = 1010890
  //ACTOR10 = 1010883
  //ACTOR11 = 1010884
  //ACTOR12 = 1010885
  //ACTOR13 = 1010861
  //ACTOR14 = 1011125
  //ACTOR15 = 1006646
  //ACTOR2 = 1008969
  //ACTOR3 = 1010886
  //ACTOR4 = 1010887
  //ACTOR5 = 1010888
  //ACTOR6 = 1010889
  //ACTOR7 = 1010860
  //ACTOR8 = 1010859
  //ACTOR9 = 1010882
  //CUTSCENEN01 = 700
  //LOCACTOR0 = 5578876
  //LOCACTOR1 = 5580469
  //LOCACTOR2 = 5580470
  //LOCACTOR3 = 1011648
  //LOCACTOR4 = 1008176
  //LOCACTOR5 = 1008179
  //LOCACTOR7 = 4269938
  //LOCACTOR8 = 5580468
  //LOCACTOR9 = 5578877
  //LOCACTORDUMMY0 = 1011647
  //POPRANGE0 = 5655567
  //QSTACCEPTCHECK = 65903

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( param1 == 1010890 || param2 == 1010890 ) // ACTOR1 = MOENBRYDA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MOENBRYDA
          }
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1010886 || param2 == 1010886 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1010887 || param2 == 1010887 ) // ACTOR4 = YDA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1010888 || param2 == 1010888 ) // ACTOR5 = PAPALYMO
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1010889 || param2 == 1010889 ) // ACTOR6 = YSHTOLA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1010858 || param2 == 1010858 ) // ACTOR0 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1010860 || param2 == 1010860 ) // ACTOR7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1010886 || param2 == 1010886 ) // ACTOR3 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1010887 || param2 == 1010887 ) // ACTOR4 = YDA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1010888 || param2 == 1010888 ) // ACTOR5 = PAPALYMO
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1010889 || param2 == 1010889 ) // ACTOR6 = YSHTOLA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1010858 || param2 == 1010858 ) // ACTOR0 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1010858 || param2 == 1010858 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          }
          break;
        }
        if( param1 == 1010859 || param2 == 1010859 ) // ACTOR8 = TATARU
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1010882 || param2 == 1010882 ) // ACTOR9 = FLHAMINN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=FLHAMINN
          break;
        }
        if( param1 == 1010883 || param2 == 1010883 ) // ACTOR10 = HIGIRI
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=HIGIRI
          break;
        }
        if( param1 == 1010884 || param2 == 1010884 ) // ACTOR11 = HOARYBOULDER
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1010885 || param2 == 1010885 ) // ACTOR12 = COULTENET
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=COULTENET
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1010861 || param2 == 1010861 ) // ACTOR13 = WILRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=WILRED
          }
          break;
        }
        if( param1 == 1010859 || param2 == 1010859 ) // ACTOR8 = TATARU
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1010883 || param2 == 1010883 ) // ACTOR10 = HIGIRI
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=HIGIRI
          break;
        }
        if( param1 == 1011125 || param2 == 1011125 ) // ACTOR14 = ALIANNE
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006646 || param2 == 1006646 ) // ACTOR15 = EDELSTEIN
        {
          Scene00029( player ); // Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EDELSTEIN
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=MINFILIA
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
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "XxaUse505:69424 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00005: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00006: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00009: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00010: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00012: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00013: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00014: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00018: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00019: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00020: Normal(Talk, TargetCanMove), id=HIGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00021: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00022: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00023: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00024: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00025: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00026: Normal(Talk, TargetCanMove), id=HIGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00027: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00028: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EDELSTEIN" );
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
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "XxaUse505:69424 calling Scene00030: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }
};

EXPOSE_SCRIPT( XxaUse505 );
