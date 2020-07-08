// FFXIVTheMovie.ParserV3
//fix: enter and exit instance
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc108 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnc108() : Sapphire::ScriptAPI::EventScript( 67774 ){}; 
  ~HeaVnc108() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 5 entries
  //SEQ_2, 4 entries
  //SEQ_3, 5 entries
  //SEQ_4, 5 entries
  //SEQ_5, 6 entries
  //SEQ_6, 7 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1016579
  //ACTOR1 = 1016069
  //ACTOR10 = 1012253
  //ACTOR11 = 1016584
  //ACTOR12 = 1016585
  //ACTOR13 = 1016595
  //ACTOR14 = 1015978
  //ACTOR2 = 1016070
  //ACTOR3 = 1013183
  //ACTOR4 = 1011223
  //ACTOR5 = 1016024
  //ACTOR6 = 1016583
  //ACTOR7 = 1013167
  //ACTOR8 = 1012251
  //ACTOR9 = 1012252
  //CUTSCENEN01 = 1149
  //ITEM0 = 2001945
  //LOCACTION0 = 788
  //LOCACTOR0 = 6212174
  //LOCACTOR1 = 1015842
  //LOCACTOR10 = 6184909
  //LOCACTOR2 = 1008194
  //LOCBGM0 = 313
  //LOCBGM1 = 316
  //POPRANGE0 = 5821838
  //POPRANGE1 = 5827491
  //TERRITORYTYPE0 = 428

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016579 || param2 == 1016579 ) // ACTOR0 = THANCRED
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016069 || param2 == 1016069 ) // ACTOR1 = LUCIA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016070 || param2 == 1016070 ) // ACTOR2 = ARTOIREL
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        break;
      }
      case 1:
      {
        if( param1 == 1013183 || param2 == 1013183 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(FadeIn), id=unknown
          }
        }
        if( param1 == 1011223 || param2 == 1011223 ) // ACTOR4 = TEMPLEKIGHTGATE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKIGHTGATE
        }
        if( param1 == 1016024 || param2 == 1016024 ) // ACTOR5 = EDMONT
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=EDMONT
        }
        if( param1 == 1016069 || param2 == 1016069 ) // ACTOR1 = LUCIA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016070 || param2 == 1016070 ) // ACTOR2 = ARTOIREL
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016583 || param2 == 1016583 ) // ACTOR6 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
          }
        }
        if( param1 == 1013183 || param2 == 1013183 ) // ACTOR3 = AYMERIC
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1016024 || param2 == 1016024 ) // ACTOR5 = EDMONT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=EDMONT
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR7 = LUCIA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=LUCIA
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR7 = LUCIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LUCIA
          }
        }
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR8 = HILDA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR9 = SYMME
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR10 = EUDESTAND
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        if( param1 == 1016584 || param2 == 1016584 ) // ACTOR11 = THANCRED
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=THANCRED
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR8 = HILDA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00019: Normal(Talk, TargetCanMove), id=HILDA
          }
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR7 = LUCIA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016584 || param2 == 1016584 ) // ACTOR11 = THANCRED
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR9 = SYMME
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR10 = EUDESTAND
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        break;
      }
      case 5:
      {
        if( param1 == 1016585 || param2 == 1016585 ) // ACTOR12 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=EMMANELLAIN
          }
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR7 = LUCIA
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR8 = HILDA
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR9 = SYMME
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR10 = EUDESTAND
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        if( param1 == 1016584 || param2 == 1016584 ) // ACTOR11 = THANCRED
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=THANCRED
        }
        break;
      }
      case 6:
      {
        if( param1 == 1011223 || param2 == 1011223 ) // ACTOR4 = TEMPLEKIGHTGATE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00030( player ); // Scene00030: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKIGHTGATE
            // +Callback Scene00031: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1016583 || param2 == 1016583 ) // ACTOR6 = THANCRED
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR7 = LUCIA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR8 = HILDA
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR9 = SYMME
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR10 = EUDESTAND
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        if( param1 == 1016595 || param2 == 1016595 ) // ACTOR13 = EMMANELLAIN
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016583 || param2 == 1016583 ) // ACTOR6 = THANCRED
        {
          Scene00038( player ); // Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
        }
        if( param1 == 1015978 || param2 == 1015978 ) // ACTOR14 = LUCIA
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR8 = HILDA
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR9 = SYMME
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR10 = EUDESTAND
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=EUDESTAND
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
      player.updateQuest( getId(), 4 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnc108:67774 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00002: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00003: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00004: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.exitInstance();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00005: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKIGHTGATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 428 );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00006: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00007: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00008: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00010: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00011: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00012: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00013: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00014: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00015: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00016: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00017: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling [BranchTrue]Scene00019: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00020: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00021: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00022: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00023: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00025: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00026: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00027: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00028: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00029: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00030: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKIGHTGATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        Scene00031( player );
      }
    };
    player.playScene( getId(), 30, NONE, callback );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling [BranchTrue]Scene00031: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 418, 113.1, 24.4, -4.65, -0.27 );
    };
    player.playScene( getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00032: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00033: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00034: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00035: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00036: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00037: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00039: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00040: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00041: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc108:67774 calling Scene00042: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc108 );
