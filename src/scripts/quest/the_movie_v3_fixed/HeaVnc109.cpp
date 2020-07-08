// FFXIVTheMovie.ParserV3
//fix: skip quest battle
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc109 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnc109() : Sapphire::ScriptAPI::EventScript( 67775 ){}; 
  ~HeaVnc109() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 10 entries
  //SEQ_2, 11 entries
  //SEQ_3, 1 entries
  //SEQ_4, 9 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1015978
  //ACTOR1 = 1016583
  //ACTOR10 = 1016586
  //ACTOR11 = 1017096
  //ACTOR12 = 1016072
  //ACTOR13 = 1016073
  //ACTOR2 = 1016587
  //ACTOR3 = 1016588
  //ACTOR4 = 1016074
  //ACTOR5 = 1016075
  //ACTOR6 = 1016076
  //ACTOR7 = 1017095
  //ACTOR8 = 1006455
  //ACTOR9 = 1006456
  //CUTSCENEN01 = 1150
  //CUTSCENEN02 = 1151
  //CUTSCENEN03 = 1169
  //EOBJECT0 = 2006860
  //LOCACTOR0 = 6185296
  //LOCACTOR10 = 6197374
  //LOCMPEQ0ARM = 15
  //LOCMPEQ0BODY = 14
  //LOCMPEQ0FEET = 17
  //LOCMPEQ0HEAD = 18
  //LOCMPEQ0LEG = 16
  //QUESTBATTLE0 = 5001
  //TERRITORYTYPE0 = 533
  //TERRITORYTYPE1 = 155

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1015978 || param2 == 1015978 ) // ACTOR0 = LUCIA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016583 || param2 == 1016583 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016587 || param2 == 1016587 ) // ACTOR2 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          }
        }
        if( param1 == 1016588 || param2 == 1016588 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016074 || param2 == 1016074 ) // ACTOR4 = AYMERIC
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1016075 || param2 == 1016075 ) // ACTOR5 = LUCIA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016076 || param2 == 1016076 ) // ACTOR6 = HILDA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1017095 || param2 == 1017095 ) // ACTOR7 = MESSENGER02239
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MESSENGER02239
        }
        if( param1 == 1006455 || param2 == 1006455 ) // ACTOR8 = LOANNE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=LOANNE
        }
        if( param1 == 1006456 || param2 == 1006456 ) // ACTOR9 = CHAUNOLLET
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CHAUNOLLET
        }
        if( param1 == 1016586 || param2 == 1016586 ) // ACTOR10 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( param1 == 1017096 || param2 == 1017096 ) // ACTOR11 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016587 || param2 == 1016587 ) // ACTOR2 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=EMMANELLAIN
            // +Callback Scene00014: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1016588 || param2 == 1016588 ) // ACTOR3 = THANCRED
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016074 || param2 == 1016074 ) // ACTOR4 = AYMERIC
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1016075 || param2 == 1016075 ) // ACTOR5 = LUCIA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016076 || param2 == 1016076 ) // ACTOR6 = HILDA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1017095 || param2 == 1017095 ) // ACTOR7 = MESSENGER02239
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MESSENGER02239
        }
        if( param1 == 1006455 || param2 == 1006455 ) // ACTOR8 = LOANNE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=LOANNE
        }
        if( param1 == 1006456 || param2 == 1006456 ) // ACTOR9 = CHAUNOLLET
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=CHAUNOLLET
        }
        if( param1 == 2006860 || param2 == 2006860 ) // EOBJECT0 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( param1 == 1016586 || param2 == 1016586 ) // ACTOR10 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( param1 == 1017096 || param2 == 1017096 ) // ACTOR11 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00025( player ); // Scene00025: Normal(CutScene), id=unknown
        }
        break;
      }
      case 4:
      {
        if( param1 == 1016072 || param2 == 1016072 ) // ACTOR12 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN
          }
        }
        if( param1 == 1016073 || param2 == 1016073 ) // ACTOR13 = PIPPIN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=PIPPIN
        }
        if( param1 == 1016587 || param2 == 1016587 ) // ACTOR2 = EMMANELLAIN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( param1 == 1016588 || param2 == 1016588 ) // ACTOR3 = THANCRED
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016074 || param2 == 1016074 ) // ACTOR4 = AYMERIC
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1016075 || param2 == 1016075 ) // ACTOR5 = LUCIA
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016076 || param2 == 1016076 ) // ACTOR6 = HILDA
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1006455 || param2 == 1006455 ) // ACTOR8 = LOANNE
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=LOANNE
        }
        if( param1 == 1006456 || param2 == 1006456 ) // ACTOR9 = CHAUNOLLET
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=CHAUNOLLET
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016588 || param2 == 1016588 ) // ACTOR3 = THANCRED
        {
          Scene00035( player ); // Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016587 || param2 == 1016587 ) // ACTOR2 = EMMANELLAIN
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( param1 == 1016074 || param2 == 1016074 ) // ACTOR4 = AYMERIC
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1016075 || param2 == 1016075 ) // ACTOR5 = LUCIA
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016076 || param2 == 1016076 ) // ACTOR6 = HILDA
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1006455 || param2 == 1006455 ) // ACTOR8 = LOANNE
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=LOANNE
        }
        if( param1 == 1006456 || param2 == 1006456 ) // ACTOR9 = CHAUNOLLET
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=CHAUNOLLET
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnc109:67775 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00005: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00006: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00007: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00008: Normal(Talk, TargetCanMove), id=MESSENGER02239" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00009: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00010: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00013: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling [BranchTrue]Scene00014: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00015: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00017: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00018: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00019: Normal(Talk, TargetCanMove), id=MESSENGER02239" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00020: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00021: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00025: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 155, -53.43, 299, -208.5, 0 );
    };
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00027: Normal(Talk, TargetCanMove), id=PIPPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00028: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00029: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00030: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00031: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00032: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00033: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00034: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00036: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00037: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00038: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00039: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00040: Normal(Talk, TargetCanMove), id=LOANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc109:67775 calling Scene00041: Normal(Talk, TargetCanMove), id=CHAUNOLLET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc109 );
