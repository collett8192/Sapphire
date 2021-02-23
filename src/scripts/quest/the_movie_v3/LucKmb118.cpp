// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb118 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb118() : Sapphire::ScriptAPI::EventScript( 68855 ){}; 
  ~LucKmb118() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 7 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1027690
  //ACTOR1 = 1029577
  //ACTOR2 = 1029581
  //ACTOR3 = 1029582
  //CUTSCENE0 = 1996
  //EOBJECT0 = 2009837
  //EOBJECT1 = 2009838
  //EOBJECT2 = 2009839
  //EVENTACTION0 = 1
  //ITEM0 = 2002578

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR0 = SETO
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SETO
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR1 = URIANGER
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029581 || param2 == 1029581 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029582 || param2 == 1029582 ) // ACTOR3 = RYNE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 2009837 || param2 == 2009837 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2009838 || param2 == 2009838 ) // EOBJECT1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2009839 || param2 == 2009839 ) // EOBJECT2 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR0 = SETO
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=SETO
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR1 = URIANGER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029581 || param2 == 1029581 ) // ACTOR2 = THANCRED
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029582 || param2 == 1029582 ) // ACTOR3 = RYNE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR0 = unknown
        {
          Scene00015( player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00016: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR1 = URIANGER
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029581 || param2 == 1029581 ) // ACTOR2 = THANCRED
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029582 || param2 == 1029582 ) // ACTOR3 = RYNE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=RYNE
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
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmb118:68855 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00002: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00004: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00008: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00010: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00011: Normal(Talk, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00012: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00013: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00014: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00016: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00017: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00018: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmb118:68855 calling Scene00019: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb118 );
