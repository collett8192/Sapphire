// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb103 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnb103() : Sapphire::ScriptAPI::EventScript( 67694 ){}; 
  ~HeaVnb103() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1015983
  //ACTOR1 = 1015984
  //ACTOR10 = 1012423
  //ACTOR2 = 1015985
  //ACTOR3 = 1015987
  //ACTOR4 = 1015986
  //ACTOR5 = 1015988
  //ACTOR6 = 1015989
  //ACTOR7 = 1012163
  //ACTOR8 = 1015992
  //ACTOR9 = 1012422
  //CUTSCENEN01 = 1047
  //EOBJECT0 = 2006605
  //EVENTACTIONWAITING3LONG = 13
  //LOCACTOR0 = 6080650
  //POPRANGE0 = 6164974

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1015983 || param2 == 1015983 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1015984 || param2 == 1015984 ) // ACTOR1 = LUCIA
        {
          Scene00002( player ); // Scene00002: Normal(Talk), id=LUCIA
        }
        if( param1 == 1015985 || param2 == 1015985 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( param1 == 1015987 || param2 == 1015987 ) // ACTOR3 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          }
        }
        if( param1 == 1015984 || param2 == 1015984 ) // ACTOR1 = LUCIA
        {
          Scene00005( player ); // Scene00005: Normal(Talk), id=LUCIA
        }
        if( param1 == 1015985 || param2 == 1015985 ) // ACTOR2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( param1 == 1015986 || param2 == 1015986 ) // ACTOR4 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        if( param1 == 2006605 || param2 == 2006605 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1015988 || param2 == 1015988 ) // ACTOR5 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1015989 || param2 == 1015989 ) // ACTOR6 = YSHTOLA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR7 = HANDELOUP
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        break;
      }
      case 255:
      {
        if( param1 == 1015992 || param2 == 1015992 ) // ACTOR8 = KRILE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KRILE
        }
        if( param1 == 1012422 || param2 == 1012422 ) // ACTOR9 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1012423 || param2 == 1012423 ) // ACTOR10 = YSHTOLA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR7 = HANDELOUP
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=HANDELOUP
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnb103:67694 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00002: Normal(Talk), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00005: Normal(Talk), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling [BranchTrue]Scene00009: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 399, -531, 152.9, -487, 0.219 );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00012: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00015: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb103:67694 calling Scene00016: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb103 );
