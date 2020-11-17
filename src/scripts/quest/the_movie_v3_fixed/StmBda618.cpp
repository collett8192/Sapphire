// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda618 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda618() : Sapphire::ScriptAPI::EventScript( 68080 ){}; 
  ~StmBda618() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 8 entries
  //SEQ_2, 8 entries
  //SEQ_3, 5 entries
  //SEQ_4, 8 entries
  //SEQ_5, 6 entries
  //SEQ_6, 2 entries
  //SEQ_7, 1 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1023606
  //ACTOR1 = 1020604
  //ACTOR10 = 1021622
  //ACTOR11 = 1021623
  //ACTOR12 = 1020646
  //ACTOR13 = 5010000
  //ACTOR14 = 1023608
  //ACTOR15 = 1023609
  //ACTOR16 = 1020647
  //ACTOR17 = 1020648
  //ACTOR18 = 1020650
  //ACTOR19 = 1020651
  //ACTOR2 = 1020632
  //ACTOR20 = 1020652
  //ACTOR3 = 1020437
  //ACTOR4 = 1020638
  //ACTOR5 = 1020639
  //ACTOR6 = 1023607
  //ACTOR7 = 1022346
  //ACTOR8 = 1021620
  //ACTOR9 = 1021621
  //BINDACTOR01 = 6905897
  //BINDACTOR02 = 6992969
  //BINDACTOR03 = 6905400
  //CUTSCENEN01 = 1475
  //CUTSCENEN02 = 1476
  //ENEMY0 = 7021931
  //ENEMY1 = 7021932
  //ENEMY2 = 7021933
  //ENEMY3 = 7021934
  //ENEMY4 = 7021935
  //ENEMY5 = 7021936
  //EOBJECT0 = 2009011
  //EOBJECT1 = 2009012
  //EOBJECT2 = 2009013
  //EOBJECT3 = 2008212
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //INSTANCEDUNGEON0 = 55
  //LOCACTOR01 = 1011887
  //LOCACTOR02 = 1019541
  //LOCACTOR03 = 1018509
  //LOCACTOR04 = 1021989
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295
  //POPRANGE0 = 6870953
  //SCREENIMAGE0 = 495
  //TERRITORYTYPE0 = 620

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1023606 || param2 == 1023606 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020604 || param2 == 1020604 ) // ACTOR1 = RAUBAHN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 || param2 == 1020632 ) // ACTOR2 = PIPIN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020437 || param2 == 1020437 ) // ACTOR3 = STARKWOAD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=STARKWOAD
          break;
        }
        if( param1 == 1020638 || param2 == 1020638 ) // ACTOR4 = SERPENTOFFICER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 || param2 == 1020639 ) // ACTOR5 = STORMOFFICER
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1023607 || param2 == 1023607 ) // ACTOR6 = ALISAIE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1022346 || param2 == 1022346 ) // ACTOR7 = LYSE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009011 || param2 == 2009011 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7021931 || param2 == 7021931 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7021932 || param2 == 7021932 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1021620 || param2 == 1021620 ) // ACTOR8 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1021621 || param2 == 1021621 ) // ACTOR9 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1021622 || param2 == 1021622 ) // ACTOR10 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021623 || param2 == 1021623 ) // ACTOR11 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020646 || param2 == 1020646 ) // ACTOR12 = STARKWOAD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=STARKWOAD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2009012 || param2 == 2009012 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00021( player ); // Scene00021: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7021933 || param2 == 7021933 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7021934 || param2 == 7021934 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1021620 || param2 == 1021620 ) // ACTOR8 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1021621 || param2 == 1021621 ) // ACTOR9 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1021622 || param2 == 1021622 ) // ACTOR10 = ALPHINAUD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021623 || param2 == 1021623 ) // ACTOR11 = ALISAIE
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020646 || param2 == 1020646 ) // ACTOR12 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1020646 || param2 == 1020646 ) // ACTOR12 = STARKWOAD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=STARKWOAD
            // +Callback Scene00031: Normal(Talk, TargetCanMove), id=STARKWOAD
          }
          break;
        }
        if( param1 == 1021620 || param2 == 1021620 ) // ACTOR8 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021621 || param2 == 1021621 ) // ACTOR9 = ALISAIE
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021622 || param2 == 1021622 ) // ACTOR10 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021623 || param2 == 1021623 ) // ACTOR11 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2009013 || param2 == 2009013 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00037( player ); // Scene00037: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7021935 || param2 == 7021935 ) // ENEMY4 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021936 || param2 == 7021936 ) // ENEMY5 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020646 || param2 == 1020646 ) // ACTOR12 = STARKWOAD
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=STARKWOAD
          break;
        }
        if( param1 == 1021620 || param2 == 1021620 ) // ACTOR8 = ALPHINAUD
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021621 || param2 == 1021621 ) // ACTOR9 = ALISAIE
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021622 || param2 == 1021622 ) // ACTOR10 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021623 || param2 == 1021623 ) // ACTOR11 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 2008212 || param2 == 2008212 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00048( player ); // Scene00048: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1020646 || param2 == 1020646 ) // ACTOR12 = STARKWOAD
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=STARKWOAD
          break;
        }
        if( param1 == 1021620 || param2 == 1021620 ) // ACTOR8 = ALPHINAUD
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021621 || param2 == 1021621 ) // ACTOR9 = ALISAIE
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021622 || param2 == 1021622 ) // ACTOR10 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021623 || param2 == 1021623 ) // ACTOR11 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1023608 || param2 == 1023608 ) // ACTOR14 = ALPHINAUD
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1023609 || param2 == 1023609 ) // ACTOR15 = ALISAIE
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 7:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00056( player ); // Scene00056: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020647 || param2 == 1020647 ) // ACTOR16 = LYSE
        {
          Scene00057( player ); // Scene00057: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020648 || param2 == 1020648 ) // ACTOR17 = RAUBAHN
        {
          Scene00058( player ); // Scene00058: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020650 || param2 == 1020650 ) // ACTOR18 = SERPENTOFFICER
        {
          Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020651 || param2 == 1020651 ) // ACTOR19 = unknown
        {
          Scene00060( player ); // Scene00060: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020652 || param2 == 1020652 ) // ACTOR20 = unknown
        {
          Scene00061( player ); // Scene00061: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
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
    player.updateQuest( getId(), 7 );
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda618:68080 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00003: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00004: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00005: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00006: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00007: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00019: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00023: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00026: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00027: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00030: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00031( player );
    };
    player.playScene( getId(), 30, NONE, callback );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00031: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00033: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00037: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00039: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00041: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00042: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00044: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00048: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 48, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00049: Normal(Talk, TargetCanMove), id=STARKWOAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00050: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00051: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00052: Normal(None), id=unknown" );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00053: Normal(None), id=unknown" );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00054: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00056( player );
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00055: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00056: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 56, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00057: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
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
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00058: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00059: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00060: Normal(None), id=unknown" );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "StmBda618:68080 calling Scene00061: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda618 );
