// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda417 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda417() : Sapphire::ScriptAPI::EventScript( 68052 ){}; 
  ~StmBda417() = default; 

  //SEQ_0, 9 entries
  //SEQ_1, 13 entries
  //SEQ_2, 11 entries
  //SEQ_3, 13 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1020540
  //ACTOR1 = 1020541
  //ACTOR10 = 1020539
  //ACTOR11 = 1021633
  //ACTOR12 = 1021632
  //ACTOR13 = 1021631
  //ACTOR14 = 1019396
  //ACTOR15 = 1021641
  //ACTOR16 = 1021640
  //ACTOR17 = 1021639
  //ACTOR18 = 5010000
  //ACTOR2 = 1020542
  //ACTOR3 = 1021634
  //ACTOR4 = 1021636
  //ACTOR5 = 1021637
  //ACTOR6 = 1021638
  //ACTOR7 = 1021635
  //ACTOR8 = 1021924
  //ACTOR9 = 1019382
  //BINDDORUBEI001 = 6998811
  //BINDGOUSETSU001 = 6851388
  //BINDGOUSETSU002 = 6871034
  //BINDHIEN001 = 6871032
  //BINDLISE001 = 6851387
  //BINDLISE002 = 6871033
  //BINDSHIRINA001 = 6851362
  //EMOTE0 = 122
  //EOBJECT0 = 2008268
  //EVENTRANGE0 = 6894728
  //LOCACTOR1 = 6871045
  //LOCACTOR2 = 6871046
  //LOCACTOR3 = 6871047
  //LOCACTOR4 = 6871035
  //LOCACTOR6 = 6871037
  //LOCACTOR7 = 6871038
  //LOCACTOR8 = 6871039
  //LOCBASEGROUNFDAMAGE = 4206
  //LOCBATTLEEMOTEEND = 3779
  //LOCLAUGHBIG = 4312

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020540 || param2 == 1020540 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020541 || param2 == 1020541 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020542 || param2 == 1020542 ) // ACTOR2 = GOSETSU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR3 = MOLA02514
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1021635 || param2 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00008( player ); // Scene00008: Normal(Talk), id=MOLB02514
          break;
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TEMULUN
          }
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR10 = CIRINA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021633 || param2 == 1021633 ) // ACTOR11 = HIEN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021632 || param2 == 1021632 ) // ACTOR12 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021631 || param2 == 1021631 ) // ACTOR13 = GOSETSU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR14 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR3 = MOLA02514
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1021635 || param2 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00021( player ); // Scene00021: Normal(Talk), id=MOLB02514
          break;
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR3 = MOLA02514
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MOLA02514
          }
          break;
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1021641 || param2 == 1021641 ) // ACTOR15 = HIEN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021640 || param2 == 1021640 ) // ACTOR16 = LYSE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021639 || param2 == 1021639 ) // ACTOR17 = GOSETSU
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR10 = CIRINA
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021635 || param2 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00032( player ); // Scene00032: Normal(Talk), id=MOLB02514
          break;
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 1 && param3 == 122 ) // ACTOR18 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00036( player ); // Scene00036: Normal(FadeIn, TargetCanMove), id=unknown
          }
          break;
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR3 = MOLA02514
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=MOLD02514
          break;
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=MOLE02514
          break;
        }
        if( param1 == 1021641 || param2 == 1021641 ) // ACTOR15 = HIEN
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021640 || param2 == 1021640 ) // ACTOR16 = LYSE
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021639 || param2 == 1021639 ) // ACTOR17 = GOSETSU
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR10 = CIRINA
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 2008268 || param2 == 2008268 ) // EOBJECT0 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021635 || param2 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00049( player ); // Scene00049: Normal(Talk), id=MOLB02514
          break;
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR10 = CIRINA
        {
          Scene00051( player ); // Scene00051: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR9 = TEMULUN
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1021633 || param2 == 1021633 ) // ACTOR11 = HIEN
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021632 || param2 == 1021632 ) // ACTOR12 = LYSE
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021631 || param2 == 1021631 ) // ACTOR13 = GOSETSU
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021634 || param2 == 1021634 ) // ACTOR3 = MOLA02514
        {
          Scene00056( player ); // Scene00056: Normal(Talk, TargetCanMove), id=MOLA02514
          break;
        }
        if( param1 == 1021636 || param2 == 1021636 ) // ACTOR4 = MOLC02514
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=MOLC02514
          break;
        }
        if( param1 == 1021637 || param2 == 1021637 ) // ACTOR5 = MOLD02514
        {
          Scene00058( player ); // Scene00058: Normal(Talk), id=MOLD02514
          break;
        }
        if( param1 == 1021638 || param2 == 1021638 ) // ACTOR6 = MOLE02514
        {
          Scene00059( player ); // Scene00059: Normal(Talk), id=MOLE02514
          break;
        }
        if( param1 == 1021635 || param2 == 1021635 ) // ACTOR7 = MOLB02514
        {
          Scene00060( player ); // Scene00060: Normal(Talk), id=MOLB02514
          break;
        }
        if( param1 == 1021924 || param2 == 1021924 ) // ACTOR8 = DORBEI
        {
          Scene00061( player ); // Scene00061: Normal(Talk, TargetCanMove), id=DORBEI
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda417:68052 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00004: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00005: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00006: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00007: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00008: Normal(Talk), id=MOLB02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00009: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00010: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00011: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00012: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00014: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00016: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00017: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00018: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00019: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00020: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00021: Normal(Talk), id=MOLB02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00022: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00023: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00024: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00025: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00026: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00027: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00028: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00029: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00030: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00031: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00032: Normal(Talk), id=MOLB02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00033: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00036: Normal(FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00039: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00040: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00041: Normal(Talk, TargetCanMove), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00042: Normal(Talk, TargetCanMove), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00043: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00044: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00045: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00046: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00047: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00048: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00049: Normal(Talk), id=MOLB02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00050: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00051: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA" );
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
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00052: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00053: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00054: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00055: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00056: Normal(Talk, TargetCanMove), id=MOLA02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00057: Normal(Talk, TargetCanMove), id=MOLC02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00058: Normal(Talk), id=MOLD02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00059: Normal(Talk), id=MOLE02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00060: Normal(Talk), id=MOLB02514" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "StmBda417:68052 calling Scene00061: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 61, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda417 );
