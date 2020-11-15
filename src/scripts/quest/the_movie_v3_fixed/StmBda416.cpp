// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda416 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda416() : Sapphire::ScriptAPI::EventScript( 68051 ){}; 
  ~StmBda416() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 12 entries
  //SEQ_2, 13 entries
  //SEQ_3, 13 entries
  //SEQ_4, 1 entries
  //SEQ_255, 16 entries

  //ACTOR0 = 1020539
  //ACTOR1 = 1021633
  //ACTOR10 = 1019388
  //ACTOR11 = 1019396
  //ACTOR12 = 1020540
  //ACTOR13 = 1020541
  //ACTOR14 = 1020542
  //ACTOR15 = 1019417
  //ACTOR16 = 1020280
  //ACTOR17 = 1021635
  //ACTOR18 = 1021924
  //ACTOR2 = 1021631
  //ACTOR3 = 1021632
  //ACTOR4 = 1021634
  //ACTOR5 = 1021636
  //ACTOR6 = 1021637
  //ACTOR7 = 1021638
  //ACTOR8 = 1019386
  //ACTOR9 = 1019382
  //BINDCHIRINA001 = 6851362
  //BINDGOSETSU001 = 6871034
  //BINDHIEN001 = 6871032
  //BINDLYSE001 = 6871033
  //BINDTEMURUN001 = 6719188
  //EOBJECT0 = 2008267
  //JPBOW2 = 5481
  //LOCBGMAISHU = 458
  //LOCBINDNEKKETSU = 6871037
  //LOCBINDONKO = 6871039
  //LOCBINDRESEI = 6871038
  //NCUTEVENT04100 = 1445
  //NCUTEVENT04120 = 1447
  //POPRANGE0 = 6789080
  //QUESTBATTLE0 = 5008
  //TERRITORYTYPE0 = 688
  //TERRITORYTYPE1 = 622

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR0 = CIRINA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CIRINA
        }
        if( param1 == 1021633 || param2 == 1021633 ) // ACTOR1 = HIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HIEN
        }
        if( param1 == 1021631 || param2 == 1021631 ) // ACTOR2 = GOSETSU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1021632 || param2 == 1021632 ) // ACTOR3 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR4 = MOLA02514
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MOLA02514
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MOLC02514
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MOLD02514
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MOLE02514
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019386 || param2 == 1019386 ) // ACTOR8 = BUJEG
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=BUJEG
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=BUJEG
          }
        }
        if( param1 == 1021633 || param2 == 1021633 ) // ACTOR1 = HIEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HIEN
        }
        if( param1 == 1021631 || param2 == 1021631 ) // ACTOR2 = GOSETSU
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1021632 || param2 == 1021632 ) // ACTOR3 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR0 = CIRINA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CIRINA
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MOLC02514
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOLD02514
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MOLE02514
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR4 = MOLA02514
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove, Menu, CanCancel), id=MOLA02514
            // +Callback Scene00019: Normal(Talk, TargetCanMove), id=MOLA02514
          }
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN
        }
        if( param1 == 1019388 || param2 == 1019388 ) // ACTOR10 = COTAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove, Menu), id=COTAN
            // +Callback Scene00022: Normal(Talk, TargetCanMove), id=COTAN
          }
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR11 = DORBEI
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=DORBEI
            // +Callback Scene00024: Normal(Talk, TargetCanMove), id=DORBEI
          }
        }
        break;
      }
      case 2:
      {
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, FadeIn, TargetCanMove), id=TEMULUN
          }
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR0 = CIRINA
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=CIRINA
        }
        if( param1 == 1021631 || param2 == 1021631 ) // ACTOR2 = GOSETSU
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1021632 || param2 == 1021632 ) // ACTOR3 = LYSE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR0 = CIRINA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=CIRINA
        }
        if( param1 == 1021633 || param2 == 1021633 ) // ACTOR1 = HIEN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=HIEN
        }
        if( param1 == 1019386 || param2 == 1019386 ) // ACTOR8 = BUJEG
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=BUJEG
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR11 = DORBEI
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=DORBEI
        }
        if( param1 == 1019388 || param2 == 1019388 ) // ACTOR10 = COTAN
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=COTAN
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR4 = MOLA02514
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=MOLA02514
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=MOLC02514
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=MOLD02514
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=MOLE02514
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR0 = CIRINA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00038( player ); // Scene00038: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=CIRINA
            // +Callback Scene00039: Normal(CutScene, AutoFadeIn), id=unknown
          }
        }
        if( param1 == 1021633 || param2 == 1021633 ) // ACTOR1 = HIEN
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=HIEN
        }
        if( param1 == 1021631 || param2 == 1021631 ) // ACTOR2 = GOSETSU
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1021632 || param2 == 1021632 ) // ACTOR3 = LYSE
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 2008267 || param2 == 2008267 ) // EOBJECT0 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
        }
        if( param1 == 1019388 || param2 == 1019388 ) // ACTOR10 = COTAN
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=COTAN
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR11 = DORBEI
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=DORBEI
        }
        if( param1 == 1019386 || param2 == 1019386 ) // ACTOR8 = BUJEG
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=BUJEG
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=TEMULUN
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR4 = MOLA02514
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=MOLA02514
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=MOLC02514
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=MOLD02514
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=MOLE02514
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00052( player ); // Scene00052: Normal(CutScene), id=unknown
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020540 || param2 == 1020540 ) // ACTOR12 = HIEN
        {
          Scene00053( player ); // Scene00053: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN
        }
        if( param1 == 1020541 || param2 == 1020541 ) // ACTOR13 = LYSE
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020542 || param2 == 1020542 ) // ACTOR14 = GOSETSU
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00056( player ); // Scene00056: Normal(Talk, TargetCanMove), id=TEMULUN
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR0 = CIRINA
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=CIRINA
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR4 = MOLA02514
        {
          Scene00058( player ); // Scene00058: Normal(Talk, TargetCanMove), id=MOLA02514
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR5 = MOLC02514
        {
          Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=MOLC02514
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR6 = MOLD02514
        {
          Scene00060( player ); // Scene00060: Normal(Talk), id=MOLD02514
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR7 = MOLE02514
        {
          Scene00061( player ); // Scene00061: Normal(Talk, TargetCanMove), id=MOLE02514
        }
        if( param1 == 1019388 || param2 == 1019388 ) // ACTOR10 = COTAN
        {
          Scene00062( player ); // Scene00062: Normal(Talk, TargetCanMove), id=COTAN
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR11 = DORBEI
        {
          Scene00063( player ); // Scene00063: Normal(Talk, TargetCanMove), id=DORBEI
        }
        if( param1 == 1019386 || param2 == 1019386 ) // ACTOR8 = BUJEG
        {
          Scene00064( player ); // Scene00064: Normal(Talk, TargetCanMove), id=BUJEG
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR15 = MAGNAI
        {
          Scene00065( player ); // Scene00065: Normal(Talk), id=MAGNAI
        }
        if( param1 == 1020280 || param2 == 1020280 ) // ACTOR16 = SADU
        {
          Scene00066( player ); // Scene00066: Normal(Talk), id=SADU
        }
        if( param1 == 1021635 || param2 == 1021635 ) // ACTOR17 = MOLB02514
        {
          Scene00067( player ); // Scene00067: Normal(Talk), id=MOLB02514
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR18 = DORBEI
        {
          Scene00068( player ); // Scene00068: Normal(Talk, TargetCanMove), id=DORBEI
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8CH( getId() ) == 1 )
        if( player.getQuestUI8AL( getId() ) == 1 )
          if( player.getQuestUI8BH( getId() ) == 1 )
          {
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda416:68051 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00002: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00005: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00006: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00007: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00008: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00009: Normal(Talk, TargetCanMove), id=BUJEG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00010: Normal(Talk, TargetCanMove), id=BUJEG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00011: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00012: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00014: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00015: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00016: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00017: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00018: Normal(Talk, TargetCanMove, Menu, CanCancel), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00019: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00021: Normal(Talk, TargetCanMove, Menu), id=COTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00022( player );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00022: Normal(Talk, TargetCanMove), id=COTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00023: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00024: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00025: Normal(Talk, FadeIn, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00026: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00027: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00028: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00029: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00030: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00031: Normal(Talk, TargetCanMove), id=BUJEG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00032: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00033: Normal(Talk, TargetCanMove), id=COTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00034: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00035: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00036: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00037: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00038: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00039( player );
      }
    };
    player.playScene( getId(), 38, NONE, callback );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00039: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      /*
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
      */
      Scene00052( player );
    };
    player.playScene( getId(), 39, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00040: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00041: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00042: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00043: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00044: Normal(Talk, TargetCanMove), id=COTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00045: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00046: Normal(Talk, TargetCanMove), id=BUJEG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00047: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00048: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00049: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00050: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00051: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00052: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 52, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00053: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
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
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00054: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00055: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00056: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00057: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00058: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00059: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00060: Normal(Talk), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00061: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00062: Normal(Talk, TargetCanMove), id=COTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 62, NONE, callback );
  }

  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00063: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 63, NONE, callback );
  }

  void Scene00064( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00064: Normal(Talk, TargetCanMove), id=BUJEG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 64, NONE, callback );
  }

  void Scene00065( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00065: Normal(Talk), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 65, NONE, callback );
  }

  void Scene00066( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00066: Normal(Talk), id=SADU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 66, NONE, callback );
  }

  void Scene00067( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00067: Normal(Talk), id=MOLB02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 67, NONE, callback );
  }

  void Scene00068( Entity::Player& player )
  {
    player.sendDebug( "StmBda416:68051 calling Scene00068: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 68, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda416 );
