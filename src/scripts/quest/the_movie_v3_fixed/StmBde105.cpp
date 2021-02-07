// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBde105 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBde105() : Sapphire::ScriptAPI::EventScript( 68683 ){}; 
  ~StmBde105() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 5 entries
  //SEQ_4, 6 entries
  //SEQ_5, 1 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1026284
  //ACTOR1 = 1026283
  //ACTOR10 = 1026252
  //ACTOR11 = 1026236
  //ACTOR12 = 1026237
  //ACTOR13 = 1019417
  //ACTOR14 = 1019431
  //ACTOR2 = 1025874
  //ACTOR3 = 1025875
  //ACTOR4 = 1020539
  //ACTOR5 = 1026233
  //ACTOR6 = 1026234
  //ACTOR7 = 1020280
  //ACTOR8 = 1019382
  //ACTOR9 = 1026235
  //EOBJECT0 = 2009591
  //EVENTACTION0 = 11
  //LCUTENPCCAM01 = 1010402
  //LOCBGM01 = 459
  //LOCBINDCIROFE01 = 6851362
  //LOCBINDHINDTK01 = 7587538
  //LOCBINDHINMOL01 = 7587557
  //LOCBINDHINOFE01 = 7593416
  //LOCBINDSHLDTK01 = 6841536
  //LOCBINDYSHDTK01 = 7587547
  //LOCBINDYSHFIN01 = 7593417
  //LOCBINDYSHMOL01 = 7587556
  //LOCENPCGYS01 = 1025714
  //LOCFACE01 = 624
  //LOCFACE02 = 6215
  //LOCNCUT01 = 1812
  //LOCNCUT02 = 1813
  //LOCNCUT03 = 1815
  //QUESTBATTLE0 = 5026
  //TERRITORYTYPE0 = 797
  //TERRITORYTYPE1 = 622

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1026284 || param2 == 1026284 ) // ACTOR0 = YSHTOLA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1026283 || param2 == 1026283 ) // ACTOR1 = HIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1025874 || param2 == 1025874 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1025875 || param2 == 1025875 ) // ACTOR3 = HIEN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR4 = CIRINA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CIRINA
          }
          break;
        }
        if( param1 == 1026233 || param2 == 1026233 ) // ACTOR5 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1026234 || param2 == 1026234 ) // ACTOR6 = HIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020280 || param2 == 1020280 ) // ACTOR7 = SADU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove, Menu), id=SADU
          }
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR4 = CIRINA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR8 = TEMULUN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1026235 || param2 == 1026235 ) // ACTOR9 = HIEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1026252 || param2 == 1026252 ) // ACTOR10 = YSHTOLA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2009591 || param2 == 2009591 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(SystemTalk, CanCancel), id=unknown
            // +Callback Scene00014: Normal(QuestBattle, YesNo, CanCancel), id=unknown
            // +Callback Scene00015: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1026236 || param2 == 1026236 ) // ACTOR11 = YSHTOLA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1026237 || param2 == 1026237 ) // ACTOR12 = HIEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR4 = CIRINA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR8 = TEMULUN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1020280 || param2 == 1020280 ) // ACTOR7 = SADU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=SADU
          break;
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00021( player ); // Scene00021: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR4 = CIRINA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1026283 || param2 == 1026283 ) // ACTOR1 = HIEN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1026284 || param2 == 1026284 ) // ACTOR0 = YSHTOLA
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1019382 || param2 == 1019382 ) // ACTOR8 = TEMULUN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TEMULUN
          break;
        }
        if( param1 == 1020280 || param2 == 1020280 ) // ACTOR7 = SADU
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=SADU
          break;
        }
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR13 = MAGNAI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=MAGNAI
          break;
        }
        if( param1 == 1019431 || param2 == 1019431 ) // ACTOR14 = DAIDUKUL
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=DAIDUKUL
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
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBde105:68683 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00002: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00004: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00005: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00007: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove, Menu), id=SADU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00009: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00010: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00011: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00013: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00014: Normal(QuestBattle, YesNo, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00015: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      Scene00021( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00017: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00018: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00019: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00020: Normal(Talk, TargetCanMove), id=SADU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00021: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA" );
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
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00023: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00025: Normal(Talk, TargetCanMove), id=TEMULUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00026: Normal(Talk, TargetCanMove), id=SADU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00027: Normal(Talk, TargetCanMove), id=MAGNAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBde105:68683 calling Scene00028: Normal(Talk, TargetCanMove), id=DAIDUKUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBde105 );
