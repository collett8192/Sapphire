// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManSea203 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManSea203() : Sapphire::ScriptAPI::EventScript( 65781 ){}; 
  ~ManSea203() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 9 entries
  //SEQ_4, 7 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000972
  //ACTOR1 = 1003621
  //ACTOR10 = 5010000
  //ACTOR11 = 6229214
  //ACTOR2 = 1017075
  //ACTOR3 = 1004472
  //ACTOR4 = 1004473
  //ACTOR5 = 1004474
  //ACTOR6 = 1004475
  //ACTOR7 = 1004476
  //ACTOR8 = 1004477
  //ACTOR9 = 1004478
  //COLLECTPARTYUNLOCK = 3704
  //INSTANCEDUNGEON0 = 4
  //LOCACTOR0 = 1004471
  //LOCACTOR1 = 1004479
  //LOCACTOR2 = 1004480
  //LOCACTOR3 = 1004481
  //QSTACCEPTCHECK = 66211
  //SCREENIMAGE1 = 91
  //SEQ0ACTOR0LQ = 90
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEONSASTASHA = 74
  //UNLOCKLFGPARTY = 137

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BADERON
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=VMELLPA
        break;
      }
      case 2:
      {
        if( param1 == 1017075 || param2 == 1017075 ) // ACTOR2 = AIDE00675
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove, ENpcBind), id=AIDE00675
          }
          break;
        }
        if( param1 == 1003621 || param2 == 1003621 ) // ACTOR1 = VMELLPA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=VMELLPA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1004472 || param2 == 1004472 ) // ACTOR3 = YELLOWJACKET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, Message, TargetCanMove, SystemTalk), id=YELLOWJACKET
          }
          break;
        }
        if( param1 == 1017075 || param2 == 1017075 ) // ACTOR2 = AIDE00675
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=AIDE00675
          break;
        }
        if( param1 == 1004473 || param2 == 1004473 ) // ACTOR4 = AVERE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=AVERE
          break;
        }
        if( param1 == 1004474 || param2 == 1004474 ) // ACTOR5 = LIAVINNE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LIAVINNE
          break;
        }
        if( param1 == 1004475 || param2 == 1004475 ) // ACTOR6 = PAIYOREIYO
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=PAIYOREIYO
          break;
        }
        if( param1 == 1004476 || param2 == 1004476 ) // ACTOR7 = EDDA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=EDDA
          break;
        }
        if( param1 == 1004477 || param2 == 1004477 ) // ACTOR8 = ISILDAURE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ISILDAURE
          break;
        }
        if( param1 == 1004478 || param2 == 1004478 ) // ACTOR9 = ALIANNE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1003621 || param2 == 1003621 ) // ACTOR1 = VMELLPA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=VMELLPA
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1004473 || param2 == 1004473 ) // ACTOR4 = AVERE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=AVERE
          break;
        }
        if( param1 == 1004474 || param2 == 1004474 ) // ACTOR5 = LIAVINNE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=LIAVINNE
          break;
        }
        if( param1 == 1004475 || param2 == 1004475 ) // ACTOR6 = PAIYOREIYO
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=PAIYOREIYO
          break;
        }
        if( param1 == 1004476 || param2 == 1004476 ) // ACTOR7 = EDDA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=EDDA
          break;
        }
        if( param1 == 1004477 || param2 == 1004477 ) // ACTOR8 = ISILDAURE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ISILDAURE
          break;
        }
        if( param1 == 1004478 || param2 == 1004478 ) // ACTOR9 = ALIANNE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1004472 || param2 == 1004472 ) // ACTOR3 = YELLOWJACKET
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove, SystemTalk), id=YELLOWJACKET
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00021( player ); // Scene00021: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=BADERON
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
    player.sendDebug( "emote: {}", emoteId );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BADERON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00002: Normal(Talk, TargetCanMove), id=VMELLPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "ManSea203:65781 calling Scene00003: Normal(Talk, TargetCanMove, ENpcBind), id=AIDE00675" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00004: Normal(Talk, TargetCanMove), id=VMELLPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_3: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "ManSea203:65781 calling Scene00005: Normal(Talk, Message, TargetCanMove, SystemTalk), id=YELLOWJACKET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00006: Normal(Talk, TargetCanMove), id=AIDE00675" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00007: Normal(Talk, TargetCanMove), id=AVERE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00008: Normal(Talk, TargetCanMove), id=LIAVINNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00009: Normal(Talk, TargetCanMove), id=PAIYOREIYO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00010: Normal(Talk, TargetCanMove), id=EDDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00011: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00012: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00013: Normal(Talk, TargetCanMove), id=VMELLPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00014: Normal(Talk, TargetCanMove), id=AVERE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00015: Normal(Talk, TargetCanMove), id=LIAVINNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00016: Normal(Talk, TargetCanMove), id=PAIYOREIYO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00017: Normal(Talk, TargetCanMove), id=EDDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00018: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00019: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00020: Normal(Talk, TargetCanMove, SystemTalk), id=YELLOWJACKET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "ManSea203:65781 calling Scene00021: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=BADERON" );
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
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( ManSea203 );
