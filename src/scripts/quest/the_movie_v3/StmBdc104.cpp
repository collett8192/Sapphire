// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_27 = RESISTANCE03025
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdc104 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdc104() : Sapphire::ScriptAPI::EventScript( 68561 ){}; 
  ~StmBdc104() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 1 entries
  //SEQ_2, 7 entries
  //SEQ_3, 6 entries
  //SEQ_4, 7 entries
  //SEQ_5, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1024837
  //ACTOR1 = 1024838
  //ACTOR10 = 1020524
  //ACTOR11 = 1025025
  //ACTOR12 = 1024846
  //ACTOR13 = 1024845
  //ACTOR14 = 1024847
  //ACTOR15 = 1024848
  //ACTOR16 = 1024729
  //ACTOR17 = 1024730
  //ACTOR18 = 1024849
  //ACTOR19 = 1024850
  //ACTOR2 = 1024839
  //ACTOR20 = 1024851
  //ACTOR21 = 1024852
  //ACTOR3 = 1024840
  //ACTOR4 = 1024841
  //ACTOR5 = 1024842
  //ACTOR6 = 1019285
  //ACTOR7 = 1019286
  //ACTOR8 = 1024843
  //ACTOR9 = 1024844
  //BINDACTOR01 = 7182516
  //BINDACTOR02 = 7182517
  //BINDACTOR03 = 7182518
  //BINDACTOR04 = 7182519
  //BINDACTOR05 = 7186121
  //EVENTRANGE0 = 7327283
  //LOCACTION01 = 625
  //LOCACTION02 = 4312
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1019096
  //LOCACTOR04 = 1024396
  //LOCACTOR05 = 1019544
  //LOCIDLE01 = 4193
  //NCUTEVENTSTMBDC10401 = 1679
  //NCUTEVENTSTMBDC10402 = 1680
  //POPRANGE0 = 7186110

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024837 || param2 == 1024837 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024838 || param2 == 1024838 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024839 || param2 == 1024839 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024840 || param2 == 1024840 ) // ACTOR3 = GOSETSU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1024841 || param2 == 1024841 ) // ACTOR4 = YOTSUYU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YOTSUYU
          break;
        }
        break;
      }
      case 1:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI
        // +Callback Scene00007: Normal(CutScene, AutoFadeIn), id=unknown
        // +Callback Scene00008: Normal(Talk, FadeIn, AutoFadeIn), id=unknown
        break;
      }
      case 2:
      {
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR6 = HANAME
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=HANAME
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=HANAME
          }
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR7 = KAIDATE
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=KAIDATE
            // +Callback Scene00012: Normal(Talk, TargetCanMove), id=KAIDATE
          }
          break;
        }
        if( param1 == 1024843 || param2 == 1024843 ) // ACTOR8 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024844 || param2 == 1024844 ) // ACTOR9 = GOSETSU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR10 = HIEN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025025 || param2 == 1025025 ) // ACTOR11 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 7327283 || param2 == 7327283 ) // EVENTRANGE0 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1024846 || param2 == 1024846 ) // ACTOR12 = RESISTANCE03025
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=RESISTANCE03025
          }
          break;
        }
        if( param1 == 1024845 || param2 == 1024845 ) // ACTOR13 = ALISAIE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024843 || param2 == 1024843 ) // ACTOR8 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1019285 || param2 == 1019285 ) // ACTOR6 = HANAME
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HANAME
          break;
        }
        if( param1 == 1019286 || param2 == 1019286 ) // ACTOR7 = KAIDATE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=KAIDATE
          break;
        }
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR10 = HIEN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1024847 || param2 == 1024847 ) // ACTOR14 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1024848 || param2 == 1024848 ) // ACTOR15 = ALISAIE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024843 || param2 == 1024843 ) // ACTOR8 = ALPHINAUD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024846 || param2 == 1024846 ) // ACTOR12 = RESISTANCE03025
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=RESISTANCE03025
          break;
        }
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR10 = HIEN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1024729 || param2 == 1024729 ) // ACTOR16 = YUGIRI
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024730 || param2 == 1024730 ) // ACTOR17 = GOSETSU
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1024849 || param2 == 1024849 ) // ACTOR18 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1024848 || param2 == 1024848 ) // ACTOR15 = ALISAIE
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024850 || param2 == 1024850 ) // ACTOR19 = ALPHINAUD
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024851 || param2 == 1024851 ) // ACTOR20 = GOSETSU
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR10 = HIEN
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020524 || param2 == 1020524 ) // ACTOR10 = HIEN
        {
          Scene00036( player ); // Scene00036: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1024848 || param2 == 1024848 ) // ACTOR15 = ALISAIE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1024850 || param2 == 1024850 ) // ACTOR19 = ALPHINAUD
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024851 || param2 == 1024851 ) // ACTOR20 = GOSETSU
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1024852 || param2 == 1024852 ) // ACTOR21 = YUGIRI
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=YUGIRI
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
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
    player.sendDebug( "StmBdc104:68561 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdc104:68561 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00005: Normal(Talk, TargetCanMove), id=YOTSUYU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00007: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00008: Normal(Talk, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00009: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00010: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00011: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00012: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00014: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00015: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00018: Normal(Talk, TargetCanMove), id=RESISTANCE03025" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00021: Normal(Talk, TargetCanMove), id=HANAME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00022: Normal(Talk, TargetCanMove), id=KAIDATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00023: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00024: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00027: Normal(Talk, TargetCanMove), id=RESISTANCE03025" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00028: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00029: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00030: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00031: Normal(Talk, NpcDespawn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00032: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00033: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00034: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00035: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00036: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
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
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00039: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBdc104:68561 calling Scene00040: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdc104 );
