// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmh105 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmh105() : Sapphire::ScriptAPI::EventScript( 69301 ){}; 
  ~LucKmh105() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 6 entries
  //SEQ_2, 5 entries
  //SEQ_3, 1 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1032121
  //ACTOR1 = 1032218
  //ACTOR10 = 1032511
  //ACTOR11 = 1032512
  //ACTOR2 = 1031725
  //ACTOR3 = 1032122
  //ACTOR4 = 1032506
  //ACTOR5 = 1032507
  //ACTOR6 = 1032508
  //ACTOR7 = 1029234
  //ACTOR8 = 1032509
  //ACTOR9 = 1032510
  //EOBJECT0 = 2010951
  //LOCACTORALMET = 1028139
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORBEQLUGG = 1029471
  //LOCACTORCYMET = 1028141
  //LOCACTORMYSTERYVOICE = 1028166
  //LOCACTORUIMET = 1028140
  //LOCACTORURIANGER = 1026570
  //LOCACTORYSHTOLA = 1026571
  //LOCBINDCYMET = 8259971
  //LOCBINDUIMET = 8259970
  //LOCBINDYSHTOLA = 7945496
  //LOCEMOTESILENCE = 140
  //NCUTLUCKMH00070 = 2238
  //NCUTLUCKMH00080 = 2239
  //NCUTLUCKMH00090 = 2240
  //QSTCHKBANQIQ001 = 69330
  //QUESTBATTLE0 = 5038
  //TERRITORYTYPE0 = 914
  //TERRITORYTYPE1 = 817

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR0 = unknown
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, Menu), id=unknown
          break;
        }
        if( param1 == 1032218 || param2 == 1032218 ) // ACTOR1 = URIANGER
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031725 || param2 == 1031725 ) // ACTOR2 = YSHTOLA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR3 = BEQLUGG
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1032506 || param2 == 1032506 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1032507 || param2 == 1032507 ) // ACTOR5 = UIMET
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1032508 || param2 == 1032508 ) // ACTOR6 = CYMET
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029234 || param2 == 1029234 ) // ACTOR7 = YSHTOLA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR0 = MYSTERYVOICE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR3 = BEQLUGG
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1032509 || param2 == 1032509 ) // ACTOR8 = ALMET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, QuestBattle, YesNo, TargetCanMove, SystemTalk, CanCancel), id=ALMET
            // +Callback Scene00012: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1032510 || param2 == 1032510 ) // ACTOR9 = UIMET
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1032511 || param2 == 1032511 ) // ACTOR10 = CYMET
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1032512 || param2 == 1032512 ) // ACTOR11 = YSHTOLA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 2010951 || param2 == 2010951 ) // EOBJECT0 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00017( player ); // Scene00017: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1032506 || param2 == 1032506 ) // ACTOR4 = ALMET
        {
          Scene00018( player ); // Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1032507 || param2 == 1032507 ) // ACTOR5 = UIMET
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1032508 || param2 == 1032508 ) // ACTOR6 = CYMET
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029234 || param2 == 1029234 ) // ACTOR7 = YSHTOLA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmh105:69301 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, Menu), id=unknown" );
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
    player.sendDebug( "LucKmh105:69301 calling Scene00002: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00004: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00005: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00006: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00007: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00009: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00010: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00011: Normal(Talk, QuestBattle, YesNo, TargetCanMove, SystemTalk, CanCancel), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00012( player );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00012: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00013: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00014: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00015: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00017: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALMET" );
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
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00019: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00020: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmh105:69301 calling Scene00021: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmh105 );
