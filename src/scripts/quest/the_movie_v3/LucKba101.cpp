// FFXIVTheMovie.ParserV3.2
// id hint used:
//ACTOR2 = GRANSON_SEQ2
//_ACTOR2 SET!!
//SCENE_9 = GRANSON_SEQ2
//ACTOR3 = GRANSON_SEQ3
//_ACTOR3 SET!!
//SCENE_15 = GRANSON_SEQ3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba101 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba101() : Sapphire::ScriptAPI::EventScript( 68779 ){}; 
  ~LucKba101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 4 entries
  //SEQ_3, 1 entries
  //SEQ_4, 3 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1029900
  //ACTOR1 = 1029890
  //ACTOR2 = 1029891
  //ACTOR3 = 1029892
  //ACTOR4 = 1029889
  //ENEMY0 = 7928811
  //ENEMY1 = 7928812
  //ENEMY2 = 7928821
  //EOBJECT0 = 2009942
  //EOBJECT1 = 2009943
  //EVENTACTION0 = 68
  //EVENTACTION1 = 1
  //EVENTACTION2 = 41
  //EVENTPICTRUELUCKBA10101 = 797
  //LOCACTOR01 = 1028190
  //LOCBGM01 = 577
  //QSTLUCKME114 = 69179

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=GRANSON
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON
        break;
      }
      case 2:
      {
        if( param1 == 2009942 || param2 == 2009942 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00004( player ); // Scene00004: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7928811 || param2 == 7928811 ) // ENEMY0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7928812 || param2 == 7928812 ) // ENEMY1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1029891 || param2 == 1029891 ) // ACTOR2 = GRANSON_SEQ2
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=GRANSON_SEQ2
          break;
        }
        break;
      }
      case 3:
      {
        Scene00010( player ); // Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON
        break;
      }
      case 4:
      {
        if( param1 == 2009943 || param2 == 2009943 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7928821 || param2 == 7928821 ) // ENEMY2 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1029892 || param2 == 1029892 ) // ACTOR3 = GRANSON_SEQ3
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=GRANSON_SEQ3
          break;
        }
        break;
      }
      case 5:
      {
        Scene00016( player ); // Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON
        break;
      }
      case 255:
      {
        Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GRANSON
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKba101:68779 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00004: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00009: Normal(Talk, TargetCanMove), id=GRANSON_SEQ2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00015: Normal(Talk, TargetCanMove), id=GRANSON_SEQ3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00016: Normal(Talk, NpcDespawn, TargetCanMove), id=GRANSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKba101:68779 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GRANSON" );
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
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKba101 );
