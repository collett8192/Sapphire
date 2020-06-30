// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna305 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna305() : Sapphire::ScriptAPI::EventScript( 67142 ){}; 
  ~HeaVna305() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 7 entries
  //SEQ_2, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1012600
  //ACTOR1 = 1012601
  //ACTOR10 = 1013436
  //ACTOR2 = 1012602
  //ACTOR3 = 1012596
  //ACTOR4 = 1011905
  //ACTOR5 = 1012603
  //ACTOR6 = 1012604
  //ACTOR7 = 1011904
  //ACTOR8 = 1011907
  //ACTOR9 = 1013435
  //EOBJECT0 = 2005464
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1012443
  //LOCACTOR2 = 1012455
  //LOCACTOR3 = 5795833
  //LOCACTOR4 = 5853407
  //LOCACTOR5 = 5854952
  //LOCACTOR6 = 5854953
  //PLAYBGMSONG = 318
  //QUESTBATTLE0 = 108
  //TERRITORYTYPE0 = 457

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012600 || actorId == 1012600 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012601 || actorId == 1012601 ) // ACTOR1 = KIGHTLEADER01605
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KIGHTLEADER01605
        }
        if( actor == 1012602 || actorId == 1012602 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012596 || actorId == 1012596 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( actor == 1011905 || actorId == 1011905 ) // ACTOR4 = TRISTECHAMBEL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=TRISTECHAMBEL
          }
        }
        if( actor == 1012596 || actorId == 1012596 ) // ACTOR3 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( actor == 1012601 || actorId == 1012601 ) // ACTOR1 = KIGHTLEADER01605
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KIGHTLEADER01605
        }
        if( actor == 1012603 || actorId == 1012603 ) // ACTOR5 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012604 || actorId == 1012604 ) // ACTOR6 = ESTINIEN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 2005464 || actorId == 2005464 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1011904 || actorId == 1011904 ) // ACTOR7 = ADELPHEL
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ADELPHEL
        }
        break;
      }
      case 2:
      {
        if( actor == 1012604 || actorId == 1012604 ) // ACTOR6 = ESTINIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ESTINIEN
          }
        }
        if( actor == 1012603 || actorId == 1012603 ) // ACTOR5 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1011904 || actorId == 1011904 ) // ACTOR7 = ADELPHEL
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ADELPHEL
        }
        if( actor == 1011905 || actorId == 1011905 ) // ACTOR4 = TRISTECHAMBEL
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=TRISTECHAMBEL
        }
        break;
      }
      case 255:
      {
        if( actor == 1011907 || actorId == 1011907 ) // ACTOR8 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1013435 || actorId == 1013435 ) // ACTOR9 = LANCER01607
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LANCER01607
        }
        if( actor == 1013436 || actorId == 1013436 ) // ACTOR10 = ARCHER01607
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ARCHER01607
        }
        if( actor == 1011904 || actorId == 1011904 ) // ACTOR7 = ADELPHEL
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ADELPHEL
        }
        if( actor == 1011905 || actorId == 1011905 ) // ACTOR4 = TRISTECHAMBEL
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TRISTECHAMBEL
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
    onProgress( player, param1, param1, 3, param1 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna305:67142 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00002: Normal(Talk, TargetCanMove), id=KIGHTLEADER01605" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00005: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=TRISTECHAMBEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00007: Normal(Talk, TargetCanMove), id=KIGHTLEADER01605" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00009: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00011: Normal(Talk, TargetCanMove), id=ADELPHEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00012: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00014: Normal(Talk, TargetCanMove), id=ADELPHEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00015: Normal(Talk, TargetCanMove), id=TRISTECHAMBEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00016: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00017: Normal(Talk, TargetCanMove), id=LANCER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00018: Normal(Talk, TargetCanMove), id=ARCHER01607" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00019: Normal(Talk, TargetCanMove), id=ADELPHEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna305:67142 calling Scene00020: Normal(Talk, TargetCanMove), id=TRISTECHAMBEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna305 );
