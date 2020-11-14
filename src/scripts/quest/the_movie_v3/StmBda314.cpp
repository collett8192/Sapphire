// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda314 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda314() : Sapphire::ScriptAPI::EventScript( 68026 ){}; 
  ~StmBda314() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1019988
  //ACTOR1 = 1019989
  //ACTOR2 = 1019990
  //ACTOR3 = 1019991
  //ACTOR4 = 1019992
  //ACTOR5 = 1019993
  //ACTOR6 = 1019947
  //BINDACTOR0 = 6836865
  //CUTSCENEN01 = 1421
  //EVENTACTION0 = 26

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1019988 || param2 == 1019988 ) // ACTOR0 = LYSE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE
        }
        if( param1 == 1019989 || param2 == 1019989 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019990 || param2 == 1019990 ) // ACTOR2 = VILLAGERA02489
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=VILLAGERA02489
        }
        if( param1 == 1019991 || param2 == 1019991 ) // ACTOR3 = VILLAGERB02489
        {
          Scene00004( player ); // Scene00004: Normal(Talk), id=VILLAGERB02489
        }
        if( param1 == 1019992 || param2 == 1019992 ) // ACTOR4 = PIRATE02481
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=PIRATE02481
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019990 || param2 == 1019990 ) // ACTOR2 = VILLAGERA02489
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=VILLAGERA02489
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=VILLAGERA02489
          }
        }
        if( param1 == 1019991 || param2 == 1019991 ) // ACTOR3 = VILLAGERB02489
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=VILLAGERB02489
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=VILLAGERB02489
          }
        }
        if( param1 == 1019992 || param2 == 1019992 ) // ACTOR4 = PIRATE02481
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=PIRATE02481
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=PIRATE02481
          }
        }
        if( param1 == 1019993 || param2 == 1019993 ) // ACTOR5 = LYSE
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=LYSE
        }
        if( param1 == 1019947 || param2 == 1019947 ) // ACTOR6 = PIRATE02490
        {
          Scene00015( player ); // Scene00015: Normal(Talk), id=PIRATE02490
        }
        if( param1 == 1019989 || param2 == 1019989 ) // ACTOR1 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019989 || param2 == 1019989 ) // ACTOR1 = ALISAIE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE
          // +Callback Scene00018: Normal(CutScene, AutoFadeIn), id=unknown
          // +Callback Scene00019: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( param1 == 1019993 || param2 == 1019993 ) // ACTOR5 = LYSE
        {
          Scene00020( player ); // Scene00020: Normal(Talk), id=LYSE
        }
        if( param1 == 1019947 || param2 == 1019947 ) // ACTOR6 = PIRATE02490
        {
          Scene00021( player ); // Scene00021: Normal(Talk), id=PIRATE02490
        }
        if( param1 == 1019990 || param2 == 1019990 ) // ACTOR2 = VILLAGERA02489
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=VILLAGERA02489
        }
        if( param1 == 1019991 || param2 == 1019991 ) // ACTOR3 = VILLAGERB02489
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=VILLAGERB02489
        }
        if( param1 == 1019992 || param2 == 1019992 ) // ACTOR4 = PIRATE02481
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=PIRATE02481
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
    if( player.getQuestUI8BH( getId() ) == 2 )
      if( player.getQuestUI8BH( getId() ) == 2 )
        if( player.getQuestUI8AL( getId() ) == 1 )
        {
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "StmBda314:68026 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00003: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00004: Normal(Talk), id=VILLAGERB02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00005: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00007: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00008: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00010: Normal(Talk, TargetCanMove), id=VILLAGERB02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00011: Normal(Talk, TargetCanMove), id=VILLAGERB02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00012: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00013: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00014: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00015: Normal(Talk), id=PIRATE02490" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00017: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00018: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00019: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00020: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00021: Normal(Talk), id=PIRATE02490" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00022: Normal(Talk, TargetCanMove), id=VILLAGERA02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00023: Normal(Talk, TargetCanMove), id=VILLAGERB02489" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda314:68026 calling Scene00024: Normal(Talk, TargetCanMove), id=PIRATE02481" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda314 );
