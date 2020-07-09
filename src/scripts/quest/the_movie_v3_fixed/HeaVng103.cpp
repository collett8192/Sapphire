// FFXIVTheMovie.ParserV3
//fix: skip quest battle, change zone
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVng103 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVng103() : Sapphire::ScriptAPI::EventScript( 67894 ){}; 
  ~HeaVng103() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 8 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1018043
  //ACTOR1 = 1018338
  //ACTOR10 = 1018322
  //ACTOR11 = 1018011
  //ACTOR12 = 1018321
  //ACTOR13 = 1013179
  //ACTOR14 = 1013178
  //ACTOR15 = 1018045
  //ACTOR16 = 1018046
  //ACTOR17 = 1018048
  //ACTOR2 = 1018042
  //ACTOR3 = 1018336
  //ACTOR4 = 1018057
  //ACTOR5 = 1018370
  //ACTOR6 = 1018337
  //ACTOR7 = 1012812
  //ACTOR8 = 1018044
  //ACTOR9 = 1018221
  //CUTSCENEN01 = 1308
  //CUTSCENEN02 = 1310
  //CUTSCENEN03 = 1311
  //CUTSCENEN04 = 1298
  //EOBJECT0 = 2007550
  //LOCACTION0 = 1071
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1017687
  //LOCACTOR2 = 1011896
  //LOCACTOR3 = 1018375
  //LOCACTOR4 = 1005521
  //LOCACTOR5 = 1011900
  //LOCACTOR6 = 1008182
  //POPRANGE0 = 6563395
  //POPRANGE1 = 6688758
  //POPRANGE2 = 6532630
  //QUESTBATTLE0 = 5004
  //TERRITORYTYPE0 = 633
  //TERRITORYTYPE1 = 636

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1018043 || param2 == 1018043 ) // ACTOR0 = unknown
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=unknown
        }
        if( param1 == 1018338 || param2 == 1018338 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018042 || param2 == 1018042 ) // ACTOR2 = CID
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=CID
        }
        if( param1 == 1018336 || param2 == 1018336 ) // ACTOR3 = YUGIRI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1018057 || param2 == 1018057 ) // ACTOR4 = GOSETSU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1018370 || param2 == 1018370 ) // ACTOR5 = NERO
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=NERO
        }
        if( param1 == 1018337 || param2 == 1018337 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1012812 || param2 == 1012812 ) // ACTOR7 = TATARU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 1:
      {
        if( param1 == 1018044 || param2 == 1018044 ) // ACTOR8 = CID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=CID
            // +Callback Scene00010: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1018221 || param2 == 1018221 ) // ACTOR9 = YUGIRI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( param1 == 1018322 || param2 == 1018322 ) // ACTOR10 = GOSETSU
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=GOSETSU
        }
        if( param1 == 1018011 || param2 == 1018011 ) // ACTOR11 = NERO
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=NERO
        }
        if( param1 == 1018321 || param2 == 1018321 ) // ACTOR12 = YDA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YDA
        }
        if( param1 == 2007550 || param2 == 2007550 ) // EOBJECT0 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1013179 || param2 == 1013179 ) // ACTOR13 = TATARU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1013178 || param2 == 1013178 ) // ACTOR14 = ALISAIE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00018( player ); // Scene00018: Normal(CutScene), id=unknown
        }
        if( param1 == 1013179 || param2 == 1013179 ) // ACTOR13 = TATARU
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1013178 || param2 == 1013178 ) // ACTOR14 = ALISAIE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018044 || param2 == 1018044 ) // ACTOR8 = CID
        {
          Scene00021( player ); // Scene00021: Normal(Talk, YesNo, TargetCanMove), id=CID
        }
        break;
      }
      case 3:
      {
        if( param1 == 1018045 || param2 == 1018045 ) // ACTOR15 = CID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, YesNo, TargetCanMove), id=CID
          }
        }
        if( param1 == 1013179 || param2 == 1013179 ) // ACTOR13 = TATARU
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1013178 || param2 == 1013178 ) // ACTOR14 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018044 || param2 == 1018044 ) // ACTOR8 = CID
        {
          Scene00025( player ); // Scene00025: Normal(Talk, YesNo, TargetCanMove), id=CID
        }
        break;
      }
      case 255:
      {
        if( param1 == 1018046 || param2 == 1018046 ) // ACTOR16 = CID
        {
          Scene00026( player ); // Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID
        }
        if( param1 == 1018048 || param2 == 1018048 ) // ACTOR17 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1013179 || param2 == 1013179 ) // ACTOR13 = TATARU
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1013178 || param2 == 1013178 ) // ACTOR14 = ALISAIE
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE
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
    player.updateQuest( getId(), 3 );
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
    player.sendDebug( "HeaVng103:67894 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "HeaVng103:67894 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVng103:67894 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00003: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00005: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00006: Normal(Talk, TargetCanMove), id=NERO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00008: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00009: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling [BranchTrue]Scene00010: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 636 );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00011: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00012: Normal(Talk), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00013: Normal(Talk, TargetCanMove), id=NERO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00014: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00016: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00018: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00019: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00020: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00021: Normal(Talk, YesNo, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00022: Normal(Talk, YesNo, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 132, 40, -19, 94.5, 2.47, true );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00023: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00025: Normal(Talk, YesNo, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00028: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVng103:67894 calling Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVng103 );
