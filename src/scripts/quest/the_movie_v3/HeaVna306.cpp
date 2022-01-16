// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna306 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna306() : Sapphire::ScriptAPI::EventScript( 67143 ){}; 
  ~HeaVna306() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 6 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1012765
  //ACTOR1 = 1012762
  //ACTOR2 = 1013435
  //ACTOR3 = 1013436
  //ACTOR4 = 1011910
  //ACTOR5 = 1011907
  //ACTOR6 = 1012283
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1012443

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012765 || param2 == 1012765 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012762 || param2 == 1012762 ) // ACTOR1 = ESTINIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1013435 || param2 == 1013435 ) // ACTOR2 = LANCER01607
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LANCER01607
          break;
        }
        if( param1 == 1013436 || param2 == 1013436 ) // ACTOR3 = ARCHER01607
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ARCHER01607
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1011910 || param2 == 1011910 ) // ACTOR4 = LUCIAE
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LUCIAE
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=LUCIAE
          }
          break;
        }
        if( param1 == 1013435 || param2 == 1013435 ) // ACTOR2 = LANCER01607
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LANCER01607
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=LANCER01607
          }
          break;
        }
        if( param1 == 1013436 || param2 == 1013436 ) // ACTOR3 = ARCHER01607
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ARCHER01607
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=ARCHER01607
          }
          break;
        }
        if( param1 == 1012762 || param2 == 1012762 ) // ACTOR1 = ESTINIEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012765 || param2 == 1012765 ) // ACTOR0 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1011907 || param2 == 1011907 ) // ACTOR5 = JANTELLOT
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=JANTELLOT
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012283 || param2 == 1012283 ) // ACTOR6 = PIERRIQUET
        {
          Scene00014( player ); // Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=PIERRIQUET
          break;
        }
        if( param1 == 1012762 || param2 == 1012762 ) // ACTOR1 = ESTINIEN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012765 || param2 == 1012765 ) // ACTOR0 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1013435 || param2 == 1013435 ) // ACTOR2 = LANCER01607
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LANCER01607
          break;
        }
        if( param1 == 1013436 || param2 == 1013436 ) // ACTOR3 = ARCHER01607
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ARCHER01607
          break;
        }
        if( param1 == 1011907 || param2 == 1011907 ) // ACTOR5 = JANTELLOT
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=JANTELLOT
          break;
        }
        if( param1 == 1011910 || param2 == 1011910 ) // ACTOR4 = LUCIAE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=LUCIAE
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00003: Normal(Talk, TargetCanMove), id=LANCER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00004: Normal(Talk, TargetCanMove), id=ARCHER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00005: Normal(Talk, TargetCanMove), id=LUCIAE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00006: Normal(Talk, TargetCanMove), id=LUCIAE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00007: Normal(Talk, TargetCanMove), id=LANCER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00008: Normal(Talk, TargetCanMove), id=LANCER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00009: Normal(Talk, TargetCanMove), id=ARCHER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00010: Normal(Talk, TargetCanMove), id=ARCHER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00013: Normal(Talk, TargetCanMove), id=JANTELLOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=PIERRIQUET" );
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
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00015: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00017: Normal(Talk, TargetCanMove), id=LANCER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00018: Normal(Talk, TargetCanMove), id=ARCHER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00019: Normal(Talk, TargetCanMove), id=JANTELLOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna306:67143 calling Scene00020: Normal(Talk, TargetCanMove), id=LUCIAE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna306 );
