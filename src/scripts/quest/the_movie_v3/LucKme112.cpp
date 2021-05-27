// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme112 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme112() : Sapphire::ScriptAPI::EventScript( 69177 ){}; 
  ~LucKme112() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_2, 10 entries
  //SEQ_3, 11 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1030238
  //ACTOR1 = 1030250
  //ACTOR2 = 1030251
  //ACTOR3 = 1030252
  //ACTOR4 = 1030253
  //ACTOR5 = 1030254
  //ACTOR6 = 1030255
  //ACTOR7 = 1030256
  //ACTOR8 = 1030287
  //ACTOR9 = 1030288
  //BINDACTOR01 = 7943570
  //BINDACTOR02 = 7943571
  //BINDACTOR03 = 7943572
  //BINDACTOR04 = 7943573
  //BINDACTOR05 = 7943580
  //EOBJECT0 = 2010097
  //EOBJECT1 = 2010098
  //EVENTACTION0 = 60
  //LOCOBJECT01 = 2009846
  //LOCSE0 = 78

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( param1 == 1030250 || param2 == 1030250 ) // ACTOR1 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1030251 || param2 == 1030251 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030252 || param2 == 1030252 ) // ACTOR3 = URIANGER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030253 || param2 == 1030253 ) // ACTOR4 = CHAINUZZ
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030254 || param2 == 1030254 ) // ACTOR5 = DULIACHAI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030255 || param2 == 1030255 ) // ACTOR6 = RUNAR
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1030256 || param2 == 1030256 ) // ACTOR7 = GUARDMAN03641
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=GUARDMAN03641
          break;
        }
        if( param1 == 1030287 || param2 == 1030287 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030288 || param2 == 1030288 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030250 || param2 == 1030250 ) // ACTOR1 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1030251 || param2 == 1030251 ) // ACTOR2 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030252 || param2 == 1030252 ) // ACTOR3 = URIANGER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030253 || param2 == 1030253 ) // ACTOR4 = CHAINUZZ
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030254 || param2 == 1030254 ) // ACTOR5 = DULIACHAI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030255 || param2 == 1030255 ) // ACTOR6 = RUNAR
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1030256 || param2 == 1030256 ) // ACTOR7 = GUARDMAN03641
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=GUARDMAN03641
          break;
        }
        if( param1 == 2010097 || param2 == 2010097 ) // EOBJECT0 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030287 || param2 == 1030287 ) // ACTOR8 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030288 || param2 == 1030288 ) // ACTOR9 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2010098 || param2 == 2010098 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, FadeIn, Menu), id=unknown
          }
          break;
        }
        if( param1 == 1030250 || param2 == 1030250 ) // ACTOR1 = YSHTOLA
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030251 || param2 == 1030251 ) // ACTOR2 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030252 || param2 == 1030252 ) // ACTOR3 = URIANGER
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030253 || param2 == 1030253 ) // ACTOR4 = CHAINUZZ
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030254 || param2 == 1030254 ) // ACTOR5 = DULIACHAI
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030255 || param2 == 1030255 ) // ACTOR6 = RUNAR
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1030256 || param2 == 1030256 ) // ACTOR7 = GUARDMAN03641
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=GUARDMAN03641
          break;
        }
        if( param1 == 2010097 || param2 == 2010097 ) // EOBJECT0 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030287 || param2 == 1030287 ) // ACTOR8 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030288 || param2 == 1030288 ) // ACTOR9 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030253 || param2 == 1030253 ) // ACTOR4 = CHAINUZZ
        {
          Scene00034( player ); // Scene00034: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030254 || param2 == 1030254 ) // ACTOR5 = DULIACHAI
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=DULIACHAI
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
    player.sendDebug( "LucKme112:69177 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme112:69177 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00005: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00006: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00007: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00008: Normal(Talk, TargetCanMove), id=GUARDMAN03641" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00013: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00014: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00015: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00016: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00017: Normal(Talk, TargetCanMove), id=GUARDMAN03641" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00022: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00023: Normal(Talk, FadeIn, Menu), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00026: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00027: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00028: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00029: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00030: Normal(Talk, TargetCanMove), id=GUARDMAN03641" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00031: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00034: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CHAINUZZ" );
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
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKme112:69177 calling Scene00035: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKme112 );
