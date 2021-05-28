// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba151 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba151() : Sapphire::ScriptAPI::EventScript( 68784 ){}; 
  ~LucKba151() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1029963
  //ACTOR1 = 1029966
  //ACTOR2 = 1029969
  //ACTOR3 = 1029889
  //BINDACTOR01 = 7929591
  //EOBJECT0 = 2009948
  //EOBJECT1 = 2009949
  //EVENTACTION0 = 1
  //ITEM0 = 2002569
  //LOCACTION01 = 5627
  //LOCACTION02 = 5665
  //LOCACTOR01 = 1028190
  //LOCBGM01 = 577
  //LOCBGM02 = 91
  //LOCBGM03 = 400
  //LOGMES01 = 3744
  //NCUTEVENTLUCKBA15101 = 2094
  //NCUTEVENTLUCKBA15102 = 2095
  //QUESTBATTLE0 = 187
  //TERRITORYTYPE0 = 869
  //TERRITORYTYPE1 = 816

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( param1 == 1029963 || param2 == 1029963 ) // ACTOR0 = SULOUL
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=SULOUL
          break;
        }
        if( param1 == 1029966 || param2 == 1029966 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(Talk), id=unknown
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 2009948 || param2 == 2009948 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, Inventory, CanCancel), id=unknown
            // +Callback Scene00004: Normal(QuestBattle, YesNo, SystemTalk, CanCancel), id=unknown
            // +Callback Scene00005: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029969 || param2 == 1029969 ) // ACTOR2 = GRANSON
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        if( param1 == 1029963 || param2 == 1029963 ) // ACTOR0 = SULOUL
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SULOUL
          break;
        }
        if( param1 == 2009949 || param2 == 2009949 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00010( player ); // Scene00010: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1029963 || param2 == 1029963 ) // ACTOR0 = SULOUL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=SULOUL
          }
          break;
        }
        if( param1 == 1029966 || param2 == 1029966 ) // ACTOR1 = GRANSON
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=GRANSON
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029889 || param2 == 1029889 ) // ACTOR3 = GRANSON
        {
          Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=GRANSON
          break;
        }
        if( param1 == 1029963 || param2 == 1029963 ) // ACTOR0 = SULOUL
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SULOUL
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
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
    player.sendDebug( "LucKba151:68784 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKba151:68784 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=SULOUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00002: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00003: Normal(Message, Inventory, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00004: Normal(QuestBattle, YesNo, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00005: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      Scene00010( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00006: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00007: Normal(Talk, TargetCanMove), id=SULOUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00010: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00011: Normal(Talk, FadeIn, TargetCanMove), id=SULOUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00012: Normal(Talk, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00013: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=GRANSON" );
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
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKba151:68784 calling Scene00014: Normal(Talk, TargetCanMove), id=SULOUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKba151 );
