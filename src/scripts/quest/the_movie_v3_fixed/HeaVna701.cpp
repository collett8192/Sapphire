// FFXIVTheMovie.ParserV3
// id table disabled
//fix: change zone
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna701 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna701() : Sapphire::ScriptAPI::EventScript( 67199 ){}; 
  ~HeaVna701() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 8 entries
  //SEQ_2, 10 entries
  //SEQ_3, 11 entries
  //SEQ_4, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1012430
  //ACTOR1 = 1013166
  //ACTOR10 = 1007478
  //ACTOR11 = 1012854
  //ACTOR12 = 1012851
  //ACTOR13 = 1012852
  //ACTOR14 = 1012853
  //ACTOR15 = 1012855
  //ACTOR16 = 1012856
  //ACTOR17 = 1012792
  //ACTOR18 = 1012793
  //ACTOR19 = 1013268
  //ACTOR2 = 1013176
  //ACTOR20 = 1012789
  //ACTOR21 = 1012790
  //ACTOR22 = 1012791
  //ACTOR3 = 1012431
  //ACTOR4 = 1012432
  //ACTOR5 = 1013173
  //ACTOR6 = 1013174
  //ACTOR7 = 1013175
  //ACTOR8 = 1015138
  //ACTOR9 = 1014562
  //CUTSCENEN01 = 888
  //CUTSCENEN02 = 889
  //CUTSCENEN03 = 990
  //CUTSCENEN04 = 890
  //LOCACTOR0 = 5890648
  //LOCACTOR1 = 5890649
  //LOCACTOR2 = 5890650
  //LOCACTOR3 = 5890652
  //LOCACTOR4 = 5890653
  //LOCMUSIC0 = 314
  //LOCMUSIC1 = 316
  //POPRANGE0 = 5873901
  //TERRITORYTYPE0 = 402

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012430 || actorId == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013166 || actorId == 1013166 ) // ACTOR1 = AYMERIC
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 1013176 || actorId == 1013176 ) // ACTOR2 = NOTRELCHAMPS
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
        }
        if( actor == 1012431 || actorId == 1012431 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1012432 || actorId == 1012432 ) // ACTOR4 = ESTINIEN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013173 || actorId == 1013173 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( actor == 1013174 || actorId == 1013174 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1013175 || actorId == 1013175 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( actor == 1012431 || actorId == 1012431 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1012430 || actorId == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012432 || actorId == 1012432 ) // ACTOR4 = ESTINIEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013166 || actorId == 1013166 ) // ACTOR1 = AYMERIC
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 1013173 || actorId == 1013173 ) // ACTOR5 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1013174 || actorId == 1013174 ) // ACTOR6 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( actor == 1013175 || actorId == 1013175 ) // ACTOR7 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 1013176 || actorId == 1013176 ) // ACTOR2 = NOTRELCHAMPS
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
        }
        break;
      }
      case 2:
      {
        if( actor == 1012430 || actorId == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1012431 || actorId == 1012431 ) // ACTOR3 = YSHTOLA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1015138 || actorId == 1015138 ) // ACTOR8 = ESTINIEN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013166 || actorId == 1013166 ) // ACTOR1 = AYMERIC
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 1013173 || actorId == 1013173 ) // ACTOR5 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( actor == 1013174 || actorId == 1013174 ) // ACTOR6 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( actor == 1013175 || actorId == 1013175 ) // ACTOR7 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 1013176 || actorId == 1013176 ) // ACTOR2 = NOTRELCHAMPS
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
        }
        if( actor == 1014562 || actorId == 1014562 ) // ACTOR9 = URIANGER
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=URIANGER
        }
        if( actor == 1007478 || actorId == 1007478 ) // ACTOR10 = URIANGER
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=URIANGER
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00027( player ); // Scene00027: Normal(CutScene), id=unknown
        }
        if( actor == 1012430 || actorId == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012431 || actorId == 1012431 ) // ACTOR3 = YSHTOLA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1015138 || actorId == 1015138 ) // ACTOR8 = ESTINIEN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013166 || actorId == 1013166 ) // ACTOR1 = AYMERIC
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 1013173 || actorId == 1013173 ) // ACTOR5 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( actor == 1013174 || actorId == 1013174 ) // ACTOR6 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        if( actor == 1013175 || actorId == 1013175 ) // ACTOR7 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        if( actor == 1013176 || actorId == 1013176 ) // ACTOR2 = NOTRELCHAMPS
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
        }
        if( actor == 1014562 || actorId == 1014562 ) // ACTOR9 = URIANGER
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=URIANGER
        }
        if( actor == 1007478 || actorId == 1007478 ) // ACTOR10 = URIANGER
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=URIANGER
        }
        break;
      }
      case 4:
      {
        if( actor == 1012854 || actorId == 1012854 ) // ACTOR11 = CID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00038( player ); // Scene00038: Normal(Talk, FadeIn, TargetCanMove), id=CID
          }
        }
        if( actor == 1012851 || actorId == 1012851 ) // ACTOR12 = ALPHINAUD
        {
          Scene00039( player ); // Scene00039: Normal(Talk), id=ALPHINAUD
        }
        if( actor == 1012852 || actorId == 1012852 ) // ACTOR13 = ESTINIEN
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012853 || actorId == 1012853 ) // ACTOR14 = YSHTOLA
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1012855 || actorId == 1012855 ) // ACTOR15 = BIGGS
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1012856 || actorId == 1012856 ) // ACTOR16 = WEDGE
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=WEDGE
        }
        break;
      }
      case 255:
      {
        if( actor == 1012792 || actorId == 1012792 ) // ACTOR17 = CID
        {
          Scene00044( player ); // Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID
        }
        if( actor == 1012793 || actorId == 1012793 ) // ACTOR18 = BIGGS
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1013268 || actorId == 1013268 ) // ACTOR19 = WEDGE
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1012789 || actorId == 1012789 ) // ACTOR20 = ALPHINAUD
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012790 || actorId == 1012790 ) // ACTOR21 = ESTINIEN
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012791 || actorId == 1012791 ) // ACTOR22 = YSHTOLA
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    onProgress( player, param1, param1, 3, param1 );
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
    player.sendDebug( "HeaVna701:67199 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna701:67199 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00003: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00009: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00011: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00012: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00016: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 402, -868, -184.2, -660.5, 1.21 );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00020: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00024: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00025: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00026: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00027: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00030: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00031: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00035: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00036: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00037: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00038: Normal(Talk, FadeIn, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 38, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00039: Normal(Talk), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00040: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00042: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00043: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00045: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00046: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00047: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00048: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "HeaVna701:67199 calling Scene00049: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna701 );
