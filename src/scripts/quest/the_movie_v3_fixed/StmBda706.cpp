// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda706 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda706() : Sapphire::ScriptAPI::EventScript( 68089 ){}; 
  ~StmBda706() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_4, 1 entries
  //SEQ_5, 12 entries
  //SEQ_6, 13 entries
  //SEQ_7, 12 entries
  //SEQ_255, 12 entries

  //ACTOR0 = 1021724
  //ACTOR1 = 1021723
  //ACTOR10 = 1022724
  //ACTOR11 = 1022729
  //ACTOR12 = 1021706
  //ACTOR13 = 1022725
  //ACTOR14 = 1022726
  //ACTOR15 = 1021726
  //ACTOR16 = 1021727
  //ACTOR17 = 1022727
  //ACTOR18 = 1021720
  //ACTOR19 = 1021698
  //ACTOR2 = 1021725
  //ACTOR20 = 1021728
  //ACTOR3 = 1020598
  //ACTOR4 = 1023838
  //ACTOR5 = 5010000
  //ACTOR6 = 1023616
  //ACTOR7 = 1020356
  //ACTOR8 = 1021704
  //ACTOR9 = 1021708
  //BINDACTOR01 = 7031300
  //BINDACTOR02 = 6870672
  //BINDACTOR03 = 6870738
  //BINDACTOR04 = 6925951
  //CUTSCENEN01 = 1483
  //CUTSCENEN02 = 1484
  //CUTSCENEN03 = 1485
  //CUTSCENEN04 = 1486
  //CUTSCENEN06 = 1488
  //CUTSCENEN07 = 1489
  //CUTSCENEN08 = 1490
  //CUTSCENEN09 = 1491
  //CUTSCENEN10 = 1492
  //INSTANCEDUNGEON0 = 56
  //INSTANCEDUNGEON1 = 55
  //INSTANCEDUNGEON2 = 20045
  //POPRANGE0 = 6954778
  //POPRANGE1 = 6998999
  //POPRANGE2 = 6870797
  //POPRANGE3 = 6998989
  //POPRANGE4 = 6870807
  //SCREENIMAGE0 = 496
  //SCREENIMAGE1 = 499
  //TERRITORYTYPE0 = 727
  //TERRITORYTYPE1 = 621

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1021724 || param2 == 1021724 ) // ACTOR0 = PIPIN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1021723 || param2 == 1021723 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021725 || param2 == 1021725 ) // ACTOR2 = AYMERIC
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1020598 || param2 == 1020598 ) // ACTOR3 = LUCIA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1023838 || param2 == 1023838 ) // ACTOR4 = RAUBAHN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1021724 || param2 == 1021724 ) // ACTOR0 = PIPIN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1021723 || param2 == 1021723 ) // ACTOR1 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021725 || param2 == 1021725 ) // ACTOR2 = AYMERIC
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1020598 || param2 == 1020598 ) // ACTOR3 = LUCIA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1023838 || param2 == 1023838 ) // ACTOR4 = RAUBAHN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00011( player ); // Scene00011: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1023616 || param2 == 1023616 ) // ACTOR6 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=FLAMERECRUIT
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1023616 || param2 == 1023616 ) // ACTOR6 = FLAMERECRUIT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=FLAMERECRUIT
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00015( player ); // Scene00015: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020356 || param2 == 1020356 ) // ACTOR7 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1021704 || param2 == 1021704 ) // ACTOR8 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021708 || param2 == 1021708 ) // ACTOR9 = THANCRED
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022724 || param2 == 1022724 ) // ACTOR10 = MNAAGO
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022729 || param2 == 1022729 ) // ACTOR11 = WISCAR
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1021706 || param2 == 1021706 ) // ACTOR12 = ARENVALD
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022725 || param2 == 1022725 ) // ACTOR13 = VMAHTIA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 || param2 == 1022726 ) // ACTOR14 = JMOLDVA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021726 || param2 == 1021726 ) // ACTOR15 = YUGIRI
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021727 || param2 == 1021727 ) // ACTOR16 = HIEN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022727 || param2 == 1022727 ) // ACTOR17 = HAKURO
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1021720 || param2 == 1021720 ) // ACTOR18 = URIANGER
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1021704 || param2 == 1021704 ) // ACTOR8 = ALPHINAUD
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020356 || param2 == 1020356 ) // ACTOR7 = LYSE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021708 || param2 == 1021708 ) // ACTOR9 = THANCRED
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022729 || param2 == 1022729 ) // ACTOR11 = WISCAR
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1021706 || param2 == 1021706 ) // ACTOR12 = ARENVALD
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022725 || param2 == 1022725 ) // ACTOR13 = VMAHTIA
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 || param2 == 1022726 ) // ACTOR14 = JMOLDVA
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021727 || param2 == 1021727 ) // ACTOR16 = HIEN
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022727 || param2 == 1022727 ) // ACTOR17 = HAKURO
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1021720 || param2 == 1021720 ) // ACTOR18 = URIANGER
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1022724 || param2 == 1022724 ) // ACTOR10 = MNAAGO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=MNAAGO
            // +Callback Scene00040: Normal(Talk, TargetCanMove), id=MNAAGO
          }
          break;
        }
        if( param1 == 1021698 || param2 == 1021698 ) // ACTOR19 = RAUBAHN
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=RAUBAHN
            // +Callback Scene00042: Normal(Talk, TargetCanMove), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1021726 || param2 == 1021726 ) // ACTOR15 = YUGIRI
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=YUGIRI
            // +Callback Scene00044: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1020356 || param2 == 1020356 ) // ACTOR7 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00045( player ); // Scene00045: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1021704 || param2 == 1021704 ) // ACTOR8 = ALPHINAUD
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021708 || param2 == 1021708 ) // ACTOR9 = THANCRED
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022724 || param2 == 1022724 ) // ACTOR10 = MNAAGO
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022729 || param2 == 1022729 ) // ACTOR11 = WISCAR
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1021706 || param2 == 1021706 ) // ACTOR12 = ARENVALD
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022725 || param2 == 1022725 ) // ACTOR13 = VMAHTIA
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 || param2 == 1022726 ) // ACTOR14 = JMOLDVA
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021726 || param2 == 1021726 ) // ACTOR15 = YUGIRI
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021727 || param2 == 1021727 ) // ACTOR16 = HIEN
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022727 || param2 == 1022727 ) // ACTOR17 = HAKURO
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1021720 || param2 == 1021720 ) // ACTOR18 = URIANGER
        {
          Scene00056( player ); // Scene00056: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021728 || param2 == 1021728 ) // ACTOR20 = LYSE
        {
          Scene00057( player ); // Scene00057: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=LYSE
          // +Callback Scene00058: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1021704 || param2 == 1021704 ) // ACTOR8 = ALPHINAUD
        {
          Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021708 || param2 == 1021708 ) // ACTOR9 = THANCRED
        {
          Scene00060( player ); // Scene00060: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022724 || param2 == 1022724 ) // ACTOR10 = MNAAGO
        {
          Scene00061( player ); // Scene00061: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022729 || param2 == 1022729 ) // ACTOR11 = WISCAR
        {
          Scene00062( player ); // Scene00062: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1021706 || param2 == 1021706 ) // ACTOR12 = ARENVALD
        {
          Scene00063( player ); // Scene00063: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022725 || param2 == 1022725 ) // ACTOR13 = VMAHTIA
        {
          Scene00064( player ); // Scene00064: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022726 || param2 == 1022726 ) // ACTOR14 = JMOLDVA
        {
          Scene00065( player ); // Scene00065: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1021726 || param2 == 1021726 ) // ACTOR15 = YUGIRI
        {
          Scene00066( player ); // Scene00066: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1021727 || param2 == 1021727 ) // ACTOR16 = HIEN
        {
          Scene00067( player ); // Scene00067: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022727 || param2 == 1022727 ) // ACTOR17 = HAKURO
        {
          Scene00068( player ); // Scene00068: Normal(Talk, TargetCanMove), id=HAKURO
          break;
        }
        if( param1 == 1021720 || param2 == 1021720 ) // ACTOR18 = URIANGER
        {
          Scene00069( player ); // Scene00069: Normal(Talk, TargetCanMove), id=URIANGER
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
    player.updateQuest( getId(), 3 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8CH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
          if( player.getQuestUI8BL( getId() ) == 1 )
          {
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.updateQuest( getId(), 7 );
          }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda706:68089 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00003: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00004: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00005: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00006: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.enterPredefinedPrivateInstance( 727 );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00008: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00009: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00010: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00011: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00012: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      Scene00015( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00013: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=FLAMERECRUIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 727 );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00014: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=FLAMERECRUIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 727 );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00015: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00016: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00018: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00019: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00020: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00021: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00022: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00023: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00025: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00026: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00027: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00029( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00030: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00031: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00032: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00033: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00034: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00035: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00036: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00037: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00038: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00039: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00040( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }
  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00040: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00041: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00042( player );
    };
    player.playScene( getId(), 41, NONE, callback );
  }
  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00042: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00043: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00044( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }
  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00044: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00045: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00047: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00048: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00049: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00050: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00051: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00052: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00053: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00054: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00055: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00056: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00057: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00058( player );
      }
    };
    player.playScene( getId(), 57, NONE, callback );
  }
  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00058: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
        player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 58, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00059: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00060: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00061: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00062: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 62, NONE, callback );
  }

  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00063: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 63, NONE, callback );
  }

  void Scene00064( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00064: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 64, NONE, callback );
  }

  void Scene00065( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00065: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 65, NONE, callback );
  }

  void Scene00066( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00066: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 66, NONE, callback );
  }

  void Scene00067( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00067: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 67, NONE, callback );
  }

  void Scene00068( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00068: Normal(Talk, TargetCanMove), id=HAKURO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 68, NONE, callback );
  }

  void Scene00069( Entity::Player& player )
  {
    player.sendDebug( "StmBda706:68089 calling Scene00069: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 69, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda706 );
