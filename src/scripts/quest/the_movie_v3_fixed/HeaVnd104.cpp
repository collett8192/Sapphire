// FFXIVTheMovie.ParserV3
//fix: change zone, skip dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnd104 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnd104() : Sapphire::ScriptAPI::EventScript( 67781 ){}; 
  ~HeaVnd104() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 21 entries
  //SEQ_3, 22 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1016813
  //ACTOR1 = 1016814
  //ACTOR10 = 1017545
  //ACTOR11 = 1017546
  //ACTOR12 = 1017547
  //ACTOR13 = 1017548
  //ACTOR14 = 1017550
  //ACTOR15 = 1017551
  //ACTOR16 = 1017552
  //ACTOR17 = 1017553
  //ACTOR18 = 1017554
  //ACTOR19 = 1016821
  //ACTOR2 = 5010000
  //ACTOR20 = 1011196
  //ACTOR21 = 1006454
  //ACTOR22 = 1006455
  //ACTOR23 = 1006456
  //ACTOR24 = 1016589
  //ACTOR25 = 1012157
  //ACTOR26 = 1012155
  //ACTOR27 = 1012162
  //ACTOR28 = 1012164
  //ACTOR29 = 1012163
  //ACTOR3 = 1017124
  //ACTOR4 = 1017539
  //ACTOR5 = 1017540
  //ACTOR6 = 1017541
  //ACTOR7 = 1017542
  //ACTOR8 = 1017543
  //ACTOR9 = 1017544
  //CUTSCENEN01 = 1199
  //CUTSCENEN02 = 1177
  //CUTSCENEN03 = 1178
  //CUTSCENEN04 = 1200
  //CUTSCENEN05 = 1201
  //CUTSCENEN06 = 1179
  //CUTSCENEN07 = 1180
  //INSTANCEDUNGEON0 = 20039
  //LOCBGM0 = 382
  //LOCSCREENIMAGE0 = 404
  //POPRANGE0 = 6349138
  //POPRANGE1 = 6351891
  //TERRITORYTYPE0 = 569
  //TERRITORYTYPE1 = 418

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016813 || param2 == 1016813 ) // ACTOR0 = AYMERIC
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1016814 || param2 == 1016814 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk), id=ALPHINAUD
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00003( player ); // Scene00003: Normal(CutScene), id=unknown
        }
        if( param1 == 1016813 || param2 == 1016813 ) // ACTOR0 = AYMERIC
        {
          Scene00004( player ); // Scene00004: Normal(Message, FadeIn), id=unknown
          // +Callback Scene00005: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1016814 || param2 == 1016814 ) // ACTOR1 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        if( param1 == 1017124 || param2 == 1017124 ) // ACTOR3 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( param1 == 1017539 || param2 == 1017539 ) // ACTOR4 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( param1 == 1017540 || param2 == 1017540 ) // ACTOR5 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( param1 == 1017541 || param2 == 1017541 ) // ACTOR6 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( param1 == 1017542 || param2 == 1017542 ) // ACTOR7 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( param1 == 1017543 || param2 == 1017543 ) // ACTOR8 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( param1 == 1017544 || param2 == 1017544 ) // ACTOR9 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( param1 == 1017545 || param2 == 1017545 ) // ACTOR10 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( param1 == 1017546 || param2 == 1017546 ) // ACTOR11 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1017547 || param2 == 1017547 ) // ACTOR12 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( param1 == 1017548 || param2 == 1017548 ) // ACTOR13 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( param1 == 1017550 || param2 == 1017550 ) // ACTOR14 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( param1 == 1017551 || param2 == 1017551 ) // ACTOR15 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( param1 == 1017552 || param2 == 1017552 ) // ACTOR16 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( param1 == 1017553 || param2 == 1017553 ) // ACTOR17 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( param1 == 1017554 || param2 == 1017554 ) // ACTOR18 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( param1 == 1016821 || param2 == 1016821 ) // ACTOR19 = TEMPLEKNIGHTB02245
        {
          Scene00023( player ); // Scene00023: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKNIGHTB02245
        }
        if( param1 == 1011196 || param2 == 1011196 ) // ACTOR20 = BELTARDOIS
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=BELTARDOIS
        }
        if( param1 == 1006454 || param2 == 1006454 ) // ACTOR21 = MARCELAIN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=MARCELAIN
        }
        if( param1 == 1006455 || param2 == 1006455 ) // ACTOR22 = LOANNE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=LOANNE
        }
        if( param1 == 1006456 || param2 == 1006456 ) // ACTOR23 = CHAUNOLLET
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=CHAUNOLLET
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00028( player ); // Scene00028: Normal(CutScene), id=unknown
        }
        if( param1 == 1017124 || param2 == 1017124 ) // ACTOR3 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
        }
        if( param1 == 1017539 || param2 == 1017539 ) // ACTOR4 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
        }
        if( param1 == 1017540 || param2 == 1017540 ) // ACTOR5 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( param1 == 1017541 || param2 == 1017541 ) // ACTOR6 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( param1 == 1017542 || param2 == 1017542 ) // ACTOR7 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        if( param1 == 1017543 || param2 == 1017543 ) // ACTOR8 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        if( param1 == 1017544 || param2 == 1017544 ) // ACTOR9 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        if( param1 == 1017545 || param2 == 1017545 ) // ACTOR10 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
        }
        if( param1 == 1017546 || param2 == 1017546 ) // ACTOR11 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
        }
        if( param1 == 1017547 || param2 == 1017547 ) // ACTOR12 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
        }
        if( param1 == 1017548 || param2 == 1017548 ) // ACTOR13 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
        }
        if( param1 == 1017550 || param2 == 1017550 ) // ACTOR14 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        if( param1 == 1017551 || param2 == 1017551 ) // ACTOR15 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( param1 == 1017552 || param2 == 1017552 ) // ACTOR16 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        if( param1 == 1017553 || param2 == 1017553 ) // ACTOR17 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
        }
        if( param1 == 1017554 || param2 == 1017554 ) // ACTOR18 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
        }
        if( param1 == 1016821 || param2 == 1016821 ) // ACTOR19 = TEMPLEKNIGHTB02245
        {
          Scene00045( player ); // Scene00045: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKNIGHTB02245
        }
        if( param1 == 1011196 || param2 == 1011196 ) // ACTOR20 = BELTARDOIS
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=BELTARDOIS
        }
        if( param1 == 1006454 || param2 == 1006454 ) // ACTOR21 = MARCELAIN
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=MARCELAIN
        }
        if( param1 == 1006455 || param2 == 1006455 ) // ACTOR22 = LOANNE
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=LOANNE
        }
        if( param1 == 1006456 || param2 == 1006456 ) // ACTOR23 = CHAUNOLLET
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=CHAUNOLLET
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016589 || param2 == 1016589 ) // ACTOR24 = ALPHINAUD
        {
          Scene00050( player ); // Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1011196 || param2 == 1011196 ) // ACTOR20 = BELTARDOIS
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=BELTARDOIS
        }
        if( param1 == 1006454 || param2 == 1006454 ) // ACTOR21 = MARCELAIN
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=MARCELAIN
        }
        if( param1 == 1006455 || param2 == 1006455 ) // ACTOR22 = LOANNE
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=LOANNE
        }
        if( param1 == 1006456 || param2 == 1006456 ) // ACTOR23 = CHAUNOLLET
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=CHAUNOLLET
        }
        if( param1 == 1012157 || param2 == 1012157 ) // ACTOR25 = QUOMONRENTIN
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=QUOMONRENTIN
        }
        if( param1 == 1012155 || param2 == 1012155 ) // ACTOR26 = GONDELIMBAUD
        {
          Scene00056( player ); // Scene00056: Normal(Talk, TargetCanMove), id=GONDELIMBAUD
        }
        if( param1 == 1012162 || param2 == 1012162 ) // ACTOR27 = VAINCANNET
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=VAINCANNET
        }
        if( param1 == 1012164 || param2 == 1012164 ) // ACTOR28 = TESCELINGEON
        {
          Scene00058( player ); // Scene00058: Normal(Talk, TargetCanMove), id=TESCELINGEON
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR29 = HANDELOUP
        {
          Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=HANDELOUP
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnd104:67781 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 418, 0, -2.6, 141.3, -3.1415 );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00002: Normal(Talk), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00004: Normal(Message, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 418, 0, -2.6, 141.3, -3.1415 );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00006: Normal(Talk), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00023: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKNIGHTB02245" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00028( player );
      }
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00024: Normal(Talk, TargetCanMove), id=BELTARDOIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00025: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00026: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00027: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00028: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 28, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00045: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKNIGHTB02245" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00046: Normal(Talk, TargetCanMove), id=BELTARDOIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00047: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00048: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00049: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00051: Normal(Talk, TargetCanMove), id=BELTARDOIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00052: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00053: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00054: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00055: Normal(Talk, TargetCanMove), id=QUOMONRENTIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00056: Normal(Talk, TargetCanMove), id=GONDELIMBAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00057: Normal(Talk, TargetCanMove), id=VAINCANNET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00058: Normal(Talk, TargetCanMove), id=TESCELINGEON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd104:67781 calling Scene00059: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 59, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnd104 );
