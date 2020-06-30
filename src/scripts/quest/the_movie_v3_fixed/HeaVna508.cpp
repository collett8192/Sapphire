// FFXIVTheMovie.ParserV3
//fix: change zone
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna508 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna508() : Sapphire::ScriptAPI::EventScript( 67185 ){}; 
  ~HeaVna508() = default; 

  //SEQ_0, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1013386
  //ACTOR1 = 1014573
  //ACTOR10 = 1013115
  //ACTOR11 = 1013116
  //ACTOR2 = 1013099
  //ACTOR3 = 1014564
  //ACTOR4 = 1014567
  //ACTOR5 = 1014568
  //ACTOR6 = 1013111
  //ACTOR7 = 1013112
  //ACTOR8 = 1013113
  //ACTOR9 = 1013114
  //CHOCOBONADERU = 848
  //LOCACTORAL = 1011887
  //LOCACTORBI = 1012125
  //LOCACTORENTA = 2006048
  //LOCACTORMAD = 1012494
  //LOCACTORRUKIA = 1008193
  //LOCACTORUE = 1012492
  //LOCMAKERAL = 5923535
  //LOCMAKERBI = 5923540
  //LOCMAKERENTA = 5923411
  //LOCMAKERMAD = 5923538
  //LOCMAKERRUKIA = 5923536
  //LOCMAKERUE = 5923539
  //NCUTHEAVNA50810 = 872
  //NCUTHEAVNA50820 = 873
  //PLAYBGMSAKUSEN = 317
  //PLAYBUK = 86
  //PLAYSEMOVE = 97
  //PLAYSEOFF = 98
  //POPRANGE0 = 5862287

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1013386 || actorId == 1013386 ) // ACTOR0 = CID
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CID
          // +Callback Scene00002: Normal(CutScene), id=unknown
        }
        if( actor == 1014573 || actorId == 1014573 ) // ACTOR1 = WEDGE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1013099 || actorId == 1013099 ) // ACTOR2 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1014564 || actorId == 1014564 ) // ACTOR3 = BIGGS
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1014567 || actorId == 1014567 ) // ACTOR4 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( actor == 1014568 || actorId == 1014568 ) // ACTOR5 = LUCIA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LUCIA
        }
        break;
      }
      case 255:
      {
        if( actor == 1013111 || actorId == 1013111 ) // ACTOR6 = CID
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID
        }
        if( actor == 1013112 || actorId == 1013112 ) // ACTOR7 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013113 || actorId == 1013113 ) // ACTOR8 = LUCIA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1013114 || actorId == 1013114 ) // ACTOR9 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1013115 || actorId == 1013115 ) // ACTOR10 = WEDGE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1013116 || actorId == 1013116 ) // ACTOR11 = BIGGS
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=BIGGS
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "HeaVna508:67185 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling [BranchChain]Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 419, 166.7, -14.5, 39.3, -2.1 );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00003: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00005: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00007: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00010: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00012: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna508:67185 calling Scene00013: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna508 );
