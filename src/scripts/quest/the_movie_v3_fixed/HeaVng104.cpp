// FFXIVTheMovie.ParserV3
//fix: enter instance
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVng104 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVng104() : Sapphire::ScriptAPI::EventScript( 67895 ){}; 
  ~HeaVng104() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 7 entries
  //SEQ_2, 10 entries
  //SEQ_3, 14 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1018048
  //ACTOR1 = 1018046
  //ACTOR10 = 1018323
  //ACTOR11 = 1018324
  //ACTOR12 = 1018329
  //ACTOR13 = 1018325
  //ACTOR14 = 1018326
  //ACTOR15 = 1018328
  //ACTOR16 = 1012813
  //ACTOR17 = 1018017
  //ACTOR18 = 1018331
  //ACTOR19 = 1018327
  //ACTOR2 = 1013179
  //ACTOR20 = 1018330
  //ACTOR21 = 1018332
  //ACTOR3 = 1013178
  //ACTOR4 = 1003027
  //ACTOR5 = 1018054
  //ACTOR6 = 1018056
  //ACTOR7 = 1018055
  //ACTOR8 = 1000460
  //ACTOR9 = 1018430
  //CUTSCENEN01 = 1312
  //CUTSCENEN02 = 1313
  //CUTSCENEN03 = 1314
  //CUTSCENEN04 = 1378
  //CUTSCENEN05 = 1348
  //LOCACTION0 = 1022
  //LOCACTOR0 = 6532518
  //LOCACTOR1 = 1018383
  //LOCACTOR10 = 1011887
  //LOCACTOR2 = 1011896
  //LOCACTOR3 = 1018375
  //LOCACTOR4 = 1005521
  //LOCACTOR5 = 6472355
  //LOCACTOR6 = 6472356
  //LOCACTOR7 = 6472357
  //LOCACTOR8 = 1011900
  //LOCACTOR9 = 1005521
  //POPRANGE0 = 6543808
  //POPRANGE1 = 6543809
  //POPRANGE2 = 6544038
  //TERRITORYTYPE0 = 205

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1018048 || param2 == 1018048 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1018046 || param2 == 1018046 ) // ACTOR1 = CID
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CID
        }
        if( param1 == 1013179 || param2 == 1013179 ) // ACTOR2 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1013178 || param2 == 1013178 ) // ACTOR3 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 1:
      {
        if( param1 == 1003027 || param2 == 1003027 ) // ACTOR4 = KANESENNA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=KANESENNA
          }
        }
        if( param1 == 1018054 || param2 == 1018054 ) // ACTOR5 = RAUBAHN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1018056 || param2 == 1018056 ) // ACTOR6 = AYMERIC
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1018055 || param2 == 1018055 ) // ACTOR7 = MERLWYB
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MERLWYB
        }
        if( param1 == 1000460 || param2 == 1000460 ) // ACTOR8 = SILENTCONJURER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove), id=SILENTCONJURER
        }
        if( param1 == 1013179 || param2 == 1013179 ) // ACTOR2 = TATARU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1013178 || param2 == 1013178 ) // ACTOR3 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 2:
      {
        if( param1 == 1018430 || param2 == 1018430 ) // ACTOR9 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1018054 || param2 == 1018054 ) // ACTOR5 = RAUBAHN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1018056 || param2 == 1018056 ) // ACTOR6 = AYMERIC
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1018055 || param2 == 1018055 ) // ACTOR7 = MERLWYB
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MERLWYB
        }
        if( param1 == 1018323 || param2 == 1018323 ) // ACTOR10 = CID
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CID
        }
        if( param1 == 1018324 || param2 == 1018324 ) // ACTOR11 = NERO
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=NERO
        }
        if( param1 == 1000460 || param2 == 1000460 ) // ACTOR8 = SILENTCONJURER
        {
          Scene00018( player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove), id=SILENTCONJURER
        }
        if( param1 == 1013179 || param2 == 1013179 ) // ACTOR2 = TATARU
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1013178 || param2 == 1013178 ) // ACTOR3 = ALISAIE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1003027 || param2 == 1003027 ) // ACTOR4 = KANESENNA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=KANESENNA
        }
        break;
      }
      case 3:
      {
        if( param1 == 1018329 || param2 == 1018329 ) // ACTOR12 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1018325 || param2 == 1018325 ) // ACTOR13 = GOSETSU
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1018326 || param2 == 1018326 ) // ACTOR14 = YUGIRI
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1018328 || param2 == 1018328 ) // ACTOR15 = YDA
        {
          Scene00025( player ); // Scene00025: Normal(Talk), id=YDA
        }
        if( param1 == 1018054 || param2 == 1018054 ) // ACTOR5 = RAUBAHN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1018056 || param2 == 1018056 ) // ACTOR6 = AYMERIC
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1018055 || param2 == 1018055 ) // ACTOR7 = MERLWYB
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=MERLWYB
        }
        if( param1 == 1018323 || param2 == 1018323 ) // ACTOR10 = CID
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=CID
        }
        if( param1 == 1018324 || param2 == 1018324 ) // ACTOR11 = NERO
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=NERO
        }
        if( param1 == 1013179 || param2 == 1013179 ) // ACTOR2 = TATARU
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1013178 || param2 == 1013178 ) // ACTOR3 = ALISAIE
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1012813 || param2 == 1012813 ) // ACTOR16 = KRILE
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1003027 || param2 == 1003027 ) // ACTOR4 = KANESENNA
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=KANESENNA
        }
        if( param1 == 1018017 || param2 == 1018017 ) // ACTOR17 = ALPHINAUD
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 255:
      {
        if( param1 == 1018331 || param2 == 1018331 ) // ACTOR18 = ALISAIE
        {
          Scene00036( player ); // Scene00036: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
          // +Callback Scene00037: Normal(CutScene), id=unknown
        }
        if( param1 == 1018327 || param2 == 1018327 ) // ACTOR19 = LYSE
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1018329 || param2 == 1018329 ) // ACTOR12 = YSHTOLA
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1018330 || param2 == 1018330 ) // ACTOR20 = ALPHINAUD
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1018332 || param2 == 1018332 ) // ACTOR21 = TATARU
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=TATARU
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVng104:67895 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00002: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00006: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00007: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00008: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00009: Normal(Talk, YesNo, TargetCanMove), id=SILENTCONJURER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 205 );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00013: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00014: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00015: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00016: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00017: Normal(Talk, TargetCanMove), id=NERO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00018: Normal(Talk, YesNo, TargetCanMove), id=SILENTCONJURER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00019: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00021: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00022: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 351 );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00023: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00025: Normal(Talk), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00027: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00028: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00029: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00030: Normal(Talk, TargetCanMove), id=NERO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00031: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00032: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00033: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00034: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00036: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00037( player );
      }
    };
    player.playScene( getId(), 36, NONE, callback );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling [BranchTrue]Scene00037: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 37, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00038: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00039: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00040: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVng104:67895 calling Scene00041: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVng104 );
