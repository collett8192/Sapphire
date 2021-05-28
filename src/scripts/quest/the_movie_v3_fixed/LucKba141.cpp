// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba141 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba141() : Sapphire::ScriptAPI::EventScript( 68783 ){}; 
  ~LucKba141() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1029963
  //ACTOR1 = 1029966
  //ACTOR2 = 1029967
  //ACTOR3 = 1029968
  //BINDACTOR01 = 7929591
  //EOBJECT0 = 2009947
  //EVENTACTION0 = 1
  //LOCACTION01 = 5627
  //LOCACTION02 = 5665
  //LOCACTION03 = 934
  //LOCACTION04 = 4260
  //LOCACTOR01 = 1028190
  //LOCACTOR02 = 1028194
  //LOCBGM01 = 649
  //LOCBGM02 = 165
  //LOGMES01 = 3744
  //NCUTEVENTLUCKBA14101 = 2092
  //NCUTEVENTLUCKBA14102 = 2121
  //NCUTEVENTLUCKBA14103 = 2093
  //QSTLUCKMB119 = 68856
  //QUESTBATTLE0 = 5029
  //TERRITORYTYPE0 = 873
  //TERRITORYTYPE1 = 816

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029963 || param2 == 1029963 ) // ACTOR0 = SULOUL
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=SULOUL
          break;
        }
        if( param1 == 1029966 || param2 == 1029966 ) // ACTOR1 = GRANSON
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029967 || param2 == 1029967 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(QuestBattle, YesNo, Message, CanCancel), id=unknown
            // +Callback Scene00004: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029968 || param2 == 1029968 ) // ACTOR3 = GRANSON
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        if( param1 == 2009947 || param2 == 2009947 ) // EOBJECT0 = unknown
        {
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00008( player );
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029963 || param2 == 1029963 ) // ACTOR0 = SULOUL
        {
          Scene00010( player ); // Scene00010: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=SULOUL
          break;
        }
        if( param1 == 1029966 || param2 == 1029966 ) // ACTOR1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=unknown
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKba141:68783 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk), id=unknown" );
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
    player.sendDebug( "LucKba141:68783 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=SULOUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKba141:68783 calling Scene00002: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKba141:68783 calling Scene00003: Normal(QuestBattle, YesNo, Message, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba141:68783 calling Scene00004: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      //player.eventFinish( getId(), 1 );
      //player.forceZoneing();
      Scene00008( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKba141:68783 calling Scene00005: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKba141:68783 calling Scene00008: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );

    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba141:68783 calling Scene00009: Normal(Talk, FadeIn, Dismount), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba141:68783 calling Scene00010: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=SULOUL" );
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
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKba141:68783 calling Scene00011: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKba141 );
