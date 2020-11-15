// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda401 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda401() : Sapphire::ScriptAPI::EventScript( 68036 ){}; 
  ~StmBda401() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 6 entries
  //SEQ_2, 8 entries
  //SEQ_3, 5 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1020079
  //ACTOR1 = 1020080
  //ACTOR10 = 1020506
  //ACTOR2 = 1020081
  //ACTOR3 = 1019355
  //ACTOR4 = 1019353
  //ACTOR5 = 1019349
  //ACTOR6 = 1019376
  //ACTOR7 = 1020281
  //ACTOR8 = 1019360
  //ACTOR9 = 1020275
  //LOCACTOR1 = 6790085
  //LOCACTOR2 = 6790084
  //LOCACTORYASAI = 6665305

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020079 || param2 == 1020079 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020080 || param2 == 1020080 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020081 || param2 == 1020081 ) // ACTOR2 = GOSETSU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019355 || param2 == 1019355 ) // ACTOR3 = CHAMBUI
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CHAMBUI
            // +Callback Scene00005: Normal(Talk), id=CHAMBUI
          }
          break;
        }
        if( param1 == 1019353 || param2 == 1019353 ) // ACTOR4 = YESUI
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YESUI
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=YESUI
          }
          break;
        }
        if( param1 == 1019349 || param2 == 1019349 ) // ACTOR5 = BAIDUR
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=BAIDUR
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=BAIDUR
          }
          break;
        }
        if( param1 == 1019376 || param2 == 1019376 ) // ACTOR6 = UCUGEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk), id=UCUGEN
          break;
        }
        if( param1 == 1020281 || param2 == 1020281 ) // ACTOR7 = CIRINA
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=CIRINA
          break;
        }
        if( param1 == 1019360 || param2 == 1019360 ) // ACTOR8 = NARENGAWA
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=NARENGAWA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020275 || param2 == 1020275 ) // ACTOR9 = GORO02500
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=GORO02500
          }
          break;
        }
        if( param1 == 1019376 || param2 == 1019376 ) // ACTOR6 = UCUGEN
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=UCUGEN
          break;
        }
        if( param1 == 1019360 || param2 == 1019360 ) // ACTOR8 = NARENGAWA
        {
          Scene00015( player ); // Scene00015: Normal(Talk), id=NARENGAWA
          break;
        }
        if( param1 == 1020281 || param2 == 1020281 ) // ACTOR7 = CIRINA
        {
          Scene00016( player ); // Scene00016: Normal(Talk), id=CIRINA
          break;
        }
        if( param1 == 1020506 || param2 == 1020506 ) // ACTOR10 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1019355 || param2 == 1019355 ) // ACTOR3 = CHAMBUI
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=CHAMBUI
          break;
        }
        if( param1 == 1019353 || param2 == 1019353 ) // ACTOR4 = YESUI
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=YESUI
          break;
        }
        if( param1 == 1019349 || param2 == 1019349 ) // ACTOR5 = BAIDUR
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=BAIDUR
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020281 || param2 == 1020281 ) // ACTOR7 = CIRINA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk), id=CIRINA
            // +Callback Scene00022: Normal(Talk, TargetCanMove), id=CIRINA
          }
          else
          {
            Scene00023( player ); // Scene00023: Normal(Talk), id=CIRINA
          }
          break;
        }
        if( param1 == 1019360 || param2 == 1019360 ) // ACTOR8 = NARENGAWA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk), id=NARENGAWA
            // +Callback Scene00025: Normal(Talk, TargetCanMove, CanCancel), id=NARENGAWA
          }
          else
          {
            Scene00026( player ); // Scene00026: Normal(Talk), id=NARENGAWA
          }
          break;
        }
        if( param1 == 1019376 || param2 == 1019376 ) // ACTOR6 = UCUGEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk), id=UCUGEN
            // +Callback Scene00028: Normal(Talk, TargetCanMove, CanCancel), id=UCUGEN
          }
          else
          {
            Scene00029( player ); // Scene00029: Normal(Talk), id=UCUGEN
          }
          break;
        }
        if( param1 == 1020275 || param2 == 1020275 ) // ACTOR9 = GORO02500
        {
          Scene00030( player ); // Scene00030: Normal(Talk), id=GORO02500
          break;
        }
        if( param1 == 1020506 || param2 == 1020506 ) // ACTOR10 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020281 || param2 == 1020281 ) // ACTOR7 = CIRINA
        {
          Scene00032( player ); // Scene00032: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1019360 || param2 == 1019360 ) // ACTOR8 = NARENGAWA
        {
          Scene00033( player ); // Scene00033: Normal(Talk), id=NARENGAWA
          break;
        }
        if( param1 == 1019376 || param2 == 1019376 ) // ACTOR6 = UCUGEN
        {
          Scene00034( player ); // Scene00034: Normal(Talk), id=UCUGEN
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
    if( player.getQuestUI8AL( getId() ) == 3 )
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
    player.sendDebug( "StmBda401:68036 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda401:68036 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00004: Normal(Talk, TargetCanMove), id=CHAMBUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00005: Normal(Talk), id=CHAMBUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00006: Normal(Talk, TargetCanMove), id=YESUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00007: Normal(Talk, TargetCanMove), id=YESUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00008: Normal(Talk, TargetCanMove), id=BAIDUR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00009: Normal(Talk, TargetCanMove), id=BAIDUR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00010: Normal(Talk), id=UCUGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00011: Normal(Talk), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00012: Normal(Talk), id=NARENGAWA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=GORO02500" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00014: Normal(Talk), id=UCUGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00015: Normal(Talk), id=NARENGAWA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00016: Normal(Talk), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00018: Normal(Talk), id=CHAMBUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00019: Normal(Talk, TargetCanMove), id=YESUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00020: Normal(Talk, TargetCanMove), id=BAIDUR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00021: Normal(Talk), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00022( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00022: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00023: Normal(Talk), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00024: Normal(Talk), id=NARENGAWA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00025: Normal(Talk, TargetCanMove, CanCancel), id=NARENGAWA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00026: Normal(Talk), id=NARENGAWA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00027: Normal(Talk), id=UCUGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00028( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00028: Normal(Talk, TargetCanMove, CanCancel), id=UCUGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00029: Normal(Talk), id=UCUGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00030: Normal(Talk), id=GORO02500" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00032: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CIRINA" );
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
    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00033: Normal(Talk), id=NARENGAWA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda401:68036 calling Scene00034: Normal(Talk), id=UCUGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda401 );
