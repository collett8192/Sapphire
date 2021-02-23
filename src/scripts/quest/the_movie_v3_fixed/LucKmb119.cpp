// FFXIVTheMovie.ParserV3.2
// id hint used:
//EOBJECT0 = dummye0
//SCENE_3 = dummye0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb119 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb119() : Sapphire::ScriptAPI::EventScript( 68856 ){}; 
  ~LucKmb119() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_255, 8 entries

  //ACTIONTIMELINEEVENTLCUTDEPOP = 4231
  //ACTIONTIMELINEEVENTLCUTHIDE = 1078
  //ACTIONTIMELINEEVENTLCUTPOP = 4230
  //ACTIONTIMELINETOUCHACTIONLOOP = 173
  //ACTIONTIMELINETOUCHTOUCHEND = 174
  //ACTOR0 = 1027690
  //ACTOR1 = 5010000
  //ACTOR2 = 1029583
  //ACTOR3 = 1029584
  //ACTOR4 = 1029585
  //ACTOR5 = 1029586
  //ACTOR6 = 1029587
  //ACTOR7 = 1027654
  //ACTOR8 = 1027655
  //ACTOR9 = 1027656
  //CUTSCENE0 = 1997
  //CUTSCENE1 = 1998
  //EOBJECT0 = 2009840
  //EVENTACTION0 = 46
  //EVENTAPPEARANCE = 1048
  //INSTANCEDUNGEON0 = 20062
  //LCUTACTOR0 = 1028110
  //LCUTBGM0 = 573
  //LCUTBGM1 = 652
  //LCUTVFX0 = 760
  //POPRANGE0 = 7924204
  //SCREENIMAGE0 = 751
  //SEEVENTTREMOR = 92
  //TERRITORYTYPE0 = 816

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SETO
        break;
      }
      case 1:
      {
        if( param1 == 2009840 || param2 == 2009840 ) // EOBJECT0 = dummye0
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn), id=dummye0
          }
          break;
        }
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR0 = SETO
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SETO
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR0 = SETO
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SETO
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00006( player ); // Scene00006: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR0 = SETO
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SETO
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029583 || param2 == 1029583 ) // ACTOR2 = URIANGER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029584 || param2 == 1029584 ) // ACTOR3 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029585 || param2 == 1029585 ) // ACTOR4 = RYNE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029586 || param2 == 1029586 ) // ACTOR5 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029587 || param2 == 1029587 ) // ACTOR6 = ALISAIE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1027654 || param2 == 1027654 ) // ACTOR7 = SULUIN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=SULUIN
          break;
        }
        if( param1 == 1027655 || param2 == 1027655 ) // ACTOR8 = YSIALA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YSIALA
          break;
        }
        if( param1 == 1027656 || param2 == 1027656 ) // ACTOR9 = OULSIGUN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=OULSIGUN
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmb119:68856 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00003: Normal(Talk, FadeIn), id=dummye0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00004: Normal(Talk, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00005: Normal(Talk, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00006: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 816, -373.5, 48.08, 469.5, -0.725, false );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00007: Normal(Talk, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER" );
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
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00010: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00013: Normal(Talk, TargetCanMove), id=SULUIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00014: Normal(Talk, TargetCanMove), id=YSIALA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb119:68856 calling Scene00015: Normal(Talk, TargetCanMove), id=OULSIGUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb119 );
