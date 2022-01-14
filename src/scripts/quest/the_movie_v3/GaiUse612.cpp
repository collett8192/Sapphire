// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse612 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse612() : Sapphire::ScriptAPI::EventScript( 65960 ){}; 
  ~GaiUse612() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEBATTLECORPSE = 73
  //ACTIONTIMELINEEVENTACTIONEND = 82
  //ACTIONTIMELINEEVENTACTIONLOOP = 81
  //ACTIONTIMELINEEVENTACTIONSTART = 80
  //ACTIONTIMELINEEVENTBASEFRIGHTENED = 983
  //ACTIONTIMELINEEVENTBASEFRIGHTENED2 = 985
  //ACTIONTIMELINEEVENTBASEGUARDSTAND = 808
  //ACTIONTIMELINEEVENTBASETALKMEMO = 923
  //ACTIONTIMELINEFACIALFEAR = 614
  //ACTOR0 = 1010984
  //ACTOR1 = 1010988
  //ACTOR2 = 1010897
  //ACTOR3 = 1010989
  //ACTOR4 = 1010990
  //ACTOR5 = 1010991
  //ACTOR6 = 1011614
  //EOBJECT0 = 2005068
  //EVENTACTIONWATCHGUARDMIDDLE = 56
  //LOCACTOR0 = 5607545
  //LOCACTOR1 = 1009412
  //LOCACTOR2 = 1009413
  //LOCACTOR3 = 1011648
  //LOCACTOR4 = 1011617
  //LOCPOSACTOR0 = 5681111
  //LOCPOSACTOR1 = 5681116
  //LOCPOSACTOR2 = 5839603
  //POPRANGE0 = 5684830
  //QSTCHECK01 = 66031
  //QSTCHECK02 = 65958
  //QSTCHECK03 = 66735
  //QSTCHECK04 = 67245

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=SCIENTIST00423
        break;
      }
      case 2:
      {
        if( param1 == 2005068 || param2 == 2005068 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, QuestGimmickReaction, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1010988 || param2 == 1010988 ) // ACTOR1 = SCIENTIST00423
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SCIENTIST00423
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1010897 || param2 == 1010897 ) // ACTOR2 = MINFILIA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MINFILIA
          break;
        }
        if( param1 == 1010989 || param2 == 1010989 ) // ACTOR3 = SCIENTIST00423
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SCIENTIST00423
          break;
        }
        if( param1 == 1010990 || param2 == 1010990 ) // ACTOR4 = HOARYBOULDER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HOARYBOULDER
          break;
        }
        if( param1 == 1010991 || param2 == 1010991 ) // ACTOR5 = COULTENET
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=COULTENET
          break;
        }
        if( param1 == 1011614 || param2 == 1011614 ) // ACTOR6 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse612:65960 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse612:65960 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse612:65960 calling Scene00002: Normal(Talk, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse612:65960 calling Scene00004: Normal(Talk, FadeIn, QuestGimmickReaction, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse612:65960 calling Scene00005: Normal(Talk, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse612:65960 calling Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=MINFILIA" );
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
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse612:65960 calling Scene00007: Normal(Talk, TargetCanMove), id=SCIENTIST00423" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse612:65960 calling Scene00008: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse612:65960 calling Scene00009: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse612:65960 calling Scene00010: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUse612 );
