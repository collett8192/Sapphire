// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda134 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda134() : Sapphire::ScriptAPI::EventScript( 68000 ){}; 
  ~StmBda134() = default; 

  //SEQ_0, 9 entries
  //SEQ_1, 10 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1020400
  //ACTOR1 = 1020411
  //ACTOR10 = 1020419
  //ACTOR2 = 1020190
  //ACTOR3 = 1020414
  //ACTOR4 = 1020415
  //ACTOR5 = 1020417
  //ACTOR6 = 1020420
  //ACTOR7 = 1020416
  //ACTOR8 = 1019965
  //ACTOR9 = 1020412
  //BINDACTOR01 = 6844543
  //BINDACTOR02 = 6844541
  //BINDACTOR03 = 6844542
  //BINDACTOR04 = 6895243
  //ITEM0 = 2002109

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020400 || param2 == 1020400 ) // ACTOR0 = RAUBAHN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=RAUBAHN
        }
        if( param1 == 1020411 || param2 == 1020411 ) // ACTOR1 = MEFFRID
        {
          Scene00002( player ); // Scene00002: Normal(Talk), id=MEFFRID
        }
        if( param1 == 1020190 || param2 == 1020190 ) // ACTOR2 = WISCAR
        {
          Scene00003( player ); // Scene00003: Normal(Talk), id=WISCAR
        }
        if( param1 == 1020414 || param2 == 1020414 ) // ACTOR3 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020415 || param2 == 1020415 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk), id=YSHTOLA
        }
        if( param1 == 1020417 || param2 == 1020417 ) // ACTOR5 = KRILE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020420 || param2 == 1020420 ) // ACTOR6 = PIPIN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020416 || param2 == 1020416 ) // ACTOR7 = CONRAD
        {
          Scene00008( player ); // Scene00008: Normal(Talk), id=CONRAD
        }
        if( param1 == 1019965 || param2 == 1019965 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 1020411 || param2 == 1020411 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
        }
        if( param1 == 1020190 || param2 == 1020190 ) // ACTOR2 = WISCAR
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=WISCAR
        }
        if( param1 == 1020412 || param2 == 1020412 ) // ACTOR9 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR10 = ALISAIE
        {
          Scene00013( player ); // Scene00013: Normal(Talk), id=ALISAIE
        }
        if( param1 == 1020414 || param2 == 1020414 ) // ACTOR3 = LYSE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020415 || param2 == 1020415 ) // ACTOR4 = YSHTOLA
        {
          Scene00015( player ); // Scene00015: Normal(Talk), id=YSHTOLA
        }
        if( param1 == 1020417 || param2 == 1020417 ) // ACTOR5 = KRILE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020420 || param2 == 1020420 ) // ACTOR6 = PIPIN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020416 || param2 == 1020416 ) // ACTOR7 = CONRAD
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=CONRAD
        }
        if( param1 == 1019965 || param2 == 1019965 ) // ACTOR8 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1020416 || param2 == 1020416 ) // ACTOR7 = CONRAD
        {
          Scene00020( player ); // Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00021: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CONRAD
        }
        if( param1 == 1020412 || param2 == 1020412 ) // ACTOR9 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020414 || param2 == 1020414 ) // ACTOR3 = LYSE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020415 || param2 == 1020415 ) // ACTOR4 = YSHTOLA
        {
          Scene00024( player ); // Scene00024: Normal(Talk), id=YSHTOLA
        }
        if( param1 == 1020417 || param2 == 1020417 ) // ACTOR5 = KRILE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1020419 || param2 == 1020419 ) // ACTOR10 = ALISAIE
        {
          Scene00026( player ); // Scene00026: Normal(Talk), id=ALISAIE
        }
        if( param1 == 1020420 || param2 == 1020420 ) // ACTOR6 = PIPIN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=PIPIN
        }
        if( param1 == 1020411 || param2 == 1020411 ) // ACTOR1 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
        }
        if( param1 == 1020190 || param2 == 1020190 ) // ACTOR2 = WISCAR
        {
          Scene00029( player ); // Scene00029: Normal(Talk), id=WISCAR
        }
        if( param1 == 1019965 || param2 == 1019965 ) // ACTOR8 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
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
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda134:68000 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00002: Normal(Talk), id=MEFFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00003: Normal(Talk), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00005: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00006: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00007: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00008: Normal(Talk), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00011: Normal(Talk), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00013: Normal(Talk), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00014: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00015: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00016: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00017: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00018: Normal(Talk), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00021( player );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling [BranchTrue]Scene00021: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00023: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00024: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00025: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00026: Normal(Talk), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00027: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00029: Normal(Talk), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda134:68000 calling Scene00030: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda134 );
