// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda135 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda135() : Sapphire::ScriptAPI::EventScript( 68001 ){}; 
  ~StmBda135() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 12 entries
  //SEQ_2, 15 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1020420
  //ACTOR1 = 1020414
  //ACTOR10 = 1020425
  //ACTOR11 = 1020412
  //ACTOR12 = 1020419
  //ACTOR2 = 1020415
  //ACTOR3 = 1020416
  //ACTOR4 = 1020417
  //ACTOR5 = 1019965
  //ACTOR6 = 1019486
  //ACTOR7 = 1020422
  //ACTOR8 = 1020423
  //ACTOR9 = 1020424
  //EOBJECT0 = 2008158
  //EOBJECT1 = 2008159
  //EOBJECT2 = 2008160
  //EVENTACTION0 = 23
  //ITEM0 = 2002110
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1017687
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1015903
  //LOCACTOR05 = 1019082
  //LOCACTOR06 = 1015833
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //LOCSE01 = 151

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020420 || param2 == 1020420 ) // ACTOR0 = PIPIN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020414 || param2 == 1020414 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020415 || param2 == 1020415 ) // ACTOR2 = YSHTOLA
        {
          Scene00003( player ); // Scene00003: Normal(Talk), id=YSHTOLA
        }
        if( param1 == 1020416 || param2 == 1020416 ) // ACTOR3 = CONRAD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CONRAD
        }
        if( param1 == 1020417 || param2 == 1020417 ) // ACTOR4 = KRILE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1019965 || param2 == 1019965 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019486 || param2 == 1019486 ) // ACTOR6 = ORELLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ORELLA
          }
        }
        if( param1 == 1020422 || param2 == 1020422 ) // ACTOR7 = FLAMECOURIER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=FLAMECOURIER
        }
        if( param1 == 1020423 || param2 == 1020423 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( param1 == 1020424 || param2 == 1020424 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( param1 == 1020425 || param2 == 1020425 ) // ACTOR10 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( param1 == 1020412 || param2 == 1020412 ) // ACTOR11 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020414 || param2 == 1020414 ) // ACTOR1 = LYSE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020415 || param2 == 1020415 ) // ACTOR2 = YSHTOLA
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=YSHTOLA
        }
        if( param1 == 1020416 || param2 == 1020416 ) // ACTOR3 = CONRAD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=CONRAD
        }
        if( param1 == 1020417 || param2 == 1020417 ) // ACTOR4 = KRILE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR12 = ALISAIE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019965 || param2 == 1019965 ) // ACTOR5 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 3
      case 2:
      {
        if( param1 == 2008158 || param2 == 2008158 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00020( player ); // Scene00020: Normal(None), id=unknown
          }
        }
        if( param1 == 2008159 || param2 == 2008159 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00022( player ); // Scene00022: Normal(None), id=unknown
          }
        }
        if( param1 == 2008160 || param2 == 2008160 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00024( player ); // Scene00024: Normal(None), id=unknown
          }
        }
        if( param1 == 1020422 || param2 == 1020422 ) // ACTOR7 = FLAMECOURIER
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=FLAMECOURIER
        }
        if( param1 == 1020423 || param2 == 1020423 ) // ACTOR8 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
        }
        if( param1 == 1020424 || param2 == 1020424 ) // ACTOR9 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        if( param1 == 1020425 || param2 == 1020425 ) // ACTOR10 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
        }
        if( param1 == 1020412 || param2 == 1020412 ) // ACTOR11 = ALPHINAUD
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020414 || param2 == 1020414 ) // ACTOR1 = LYSE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020415 || param2 == 1020415 ) // ACTOR2 = YSHTOLA
        {
          Scene00031( player ); // Scene00031: Normal(Talk), id=YSHTOLA
        }
        if( param1 == 1020416 || param2 == 1020416 ) // ACTOR3 = CONRAD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=CONRAD
        }
        if( param1 == 1020417 || param2 == 1020417 ) // ACTOR4 = KRILE
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR12 = ALISAIE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019965 || param2 == 1019965 ) // ACTOR5 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        if( param1 == 1019486 || param2 == 1019486 ) // ACTOR6 = ORELLA
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ORELLA
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( param1 == 1020422 || param2 == 1020422 ) // ACTOR7 = unknown
        {
          Scene00037( player ); // Scene00037: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00038: Normal(FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown
        }
        if( param1 == 1020423 || param2 == 1020423 ) // ACTOR8 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
        }
        if( param1 == 1020424 || param2 == 1020424 ) // ACTOR9 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        if( param1 == 1020425 || param2 == 1020425 ) // ACTOR10 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( param1 == 1020412 || param2 == 1020412 ) // ACTOR11 = ALPHINAUD
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020414 || param2 == 1020414 ) // ACTOR1 = LYSE
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020415 || param2 == 1020415 ) // ACTOR2 = YSHTOLA
        {
          Scene00044( player ); // Scene00044: Normal(Talk), id=YSHTOLA
        }
        if( param1 == 1020416 || param2 == 1020416 ) // ACTOR3 = CONRAD
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=CONRAD
        }
        if( param1 == 1020417 || param2 == 1020417 ) // ACTOR4 = KRILE
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR12 = ALISAIE
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019965 || param2 == 1019965 ) // ACTOR5 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 3 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda135:68001 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00003: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00004: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00005: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00007: Normal(Talk, TargetCanMove), id=ORELLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00008: Normal(Talk, TargetCanMove), id=FLAMECOURIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00014: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00015: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00016: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00020: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00022: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00024: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00025: Normal(Talk, TargetCanMove), id=FLAMECOURIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00030: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00031: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00032: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00033: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00034: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00036: Normal(Talk, TargetCanMove), id=ORELLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00037: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00038( player );
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling [BranchTrue]Scene00038: Normal(FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 38, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00042: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00043: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00044: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00045: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00046: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda135:68001 calling Scene00048: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda135 );
