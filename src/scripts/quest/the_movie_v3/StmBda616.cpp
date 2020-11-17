// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda616 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda616() : Sapphire::ScriptAPI::EventScript( 68078 ){}; 
  ~StmBda616() = default; 

  //SEQ_0, 11 entries
  //SEQ_1, 11 entries
  //SEQ_2, 7 entries
  //SEQ_3, 9 entries
  //SEQ_4, 8 entries
  //SEQ_255, 9 entries

  //ACTOR0 = 1020629
  //ACTOR1 = 1020604
  //ACTOR10 = 1022341
  //ACTOR11 = 1020408
  //ACTOR12 = 1020409
  //ACTOR13 = 1020410
  //ACTOR14 = 1021616
  //ACTOR15 = 1021617
  //ACTOR16 = 1021618
  //ACTOR17 = 1021619
  //ACTOR18 = 1022343
  //ACTOR19 = 1022344
  //ACTOR2 = 1020632
  //ACTOR20 = 1020636
  //ACTOR21 = 1020637
  //ACTOR3 = 1020630
  //ACTOR4 = 1020628
  //ACTOR5 = 1020631
  //ACTOR6 = 1020638
  //ACTOR7 = 1020639
  //ACTOR8 = 1022339
  //ACTOR9 = 1022340
  //BINDACTOR01 = 6858255
  //BINDACTOR02 = 6858257
  //BINDACTOR03 = 6858247
  //BINDACTOR04 = 6865593
  //BINDACTOR05 = 6905280
  //BINDACTOR06 = 6905230
  //BINDACTOR07 = 7021950
  //BINDACTOR08 = 7021951
  //BINDACTOR09 = 7021952
  //ENEMY0 = 7021929
  //ENEMY1 = 7021930
  //ENEMY2 = 7005949
  //EOBJECT0 = 2009008
  //EOBJECT1 = 2009009
  //EOBJECT2 = 2009010
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020629 || param2 == 1020629 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
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
        if( param1 == 1020630 || param2 == 1020630 ) // ACTOR3 = ALISAIE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020628 || param2 == 1020628 ) // ACTOR4 = MNAAGO
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1020631 || param2 == 1020631 ) // ACTOR5 = LYSE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020638 || param2 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 || param2 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1022339 || param2 == 1022339 ) // ACTOR8 = ARENVALD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022340 || param2 == 1022340 ) // ACTOR9 = VMAHTIA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022341 || param2 == 1022341 ) // ACTOR10 = JMOLDVA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009008 || param2 == 2009008 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk), id=unknown
          }
          break;
        }
        if( param1 == 1020604 || param2 == 1020604 ) // ACTOR1 = RAUBAHN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 || param2 == 1020632 ) // ACTOR2 = PIPIN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020638 || param2 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 || param2 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1022339 || param2 == 1022339 ) // ACTOR8 = ARENVALD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022340 || param2 == 1022340 ) // ACTOR9 = VMAHTIA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022341 || param2 == 1022341 ) // ACTOR10 = JMOLDVA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1020408 || param2 == 1020408 ) // ACTOR11 = ALPHINAUD
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020409 || param2 == 1020409 ) // ACTOR12 = ALISAIE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020410 || param2 == 1020410 ) // ACTOR13 = LYSE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2009009 || param2 == 2009009 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00025( player ); // Scene00025: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7021929 || param2 == 7021929 ) // ENEMY0 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021930 || param2 == 7021930 ) // ENEMY1 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020604 || param2 == 1020604 ) // ACTOR1 = RAUBAHN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 || param2 == 1020632 ) // ACTOR2 = PIPIN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020638 || param2 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 || param2 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1021616 || param2 == 1021616 ) // ACTOR14 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1020604 || param2 == 1020604 ) // ACTOR1 = RAUBAHN
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 || param2 == 1020632 ) // ACTOR2 = PIPIN
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1021617 || param2 == 1021617 ) // ACTOR15 = ALISAIE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021618 || param2 == 1021618 ) // ACTOR16 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021619 || param2 == 1021619 ) // ACTOR17 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020638 || param2 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 || param2 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1022343 || param2 == 1022343 ) // ACTOR18 = LYSE
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2009010 || param2 == 2009010 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00044( player ); // Scene00044: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 7005949 || param2 == 7005949 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1020604 || param2 == 1020604 ) // ACTOR1 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020632 || param2 == 1020632 ) // ACTOR2 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1021618 || param2 == 1021618 ) // ACTOR16 = RAUBAHN
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1021619 || param2 == 1021619 ) // ACTOR17 = PIPIN
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020638 || param2 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 || param2 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1022344 || param2 == 1022344 ) // ACTOR19 = LYSE
        {
          Scene00053( player ); // Scene00053: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020604 || param2 == 1020604 ) // ACTOR1 = RAUBAHN
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1020632 || param2 == 1020632 ) // ACTOR2 = PIPIN
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=PIPIN
          break;
        }
        if( param1 == 1020636 || param2 == 1020636 ) // ACTOR20 = ALPHINAUD
        {
          Scene00056( player ); // Scene00056: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020638 || param2 == 1020638 ) // ACTOR6 = SERPENTOFFICER
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1020639 || param2 == 1020639 ) // ACTOR7 = STORMOFFICER
        {
          Scene00058( player ); // Scene00058: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1020637 || param2 == 1020637 ) // ACTOR21 = ALISAIE
        {
          Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021618 || param2 == 1021618 ) // ACTOR16 = unknown
        {
          Scene00060( player ); // Scene00060: Normal(None), id=unknown
          break;
        }
        if( param1 == 1021619 || param2 == 1021619 ) // ACTOR17 = unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "StmBda616:68078 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00002: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00003: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00004: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00005: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00006: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00007: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00008: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00009: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00010: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00011: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00013: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00014: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00015: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00016: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00017: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00018: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00019: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00020: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00023: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00027: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00029: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00030: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00031: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00032: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00033: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00035: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00036: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00037: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00040: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00041: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00042: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00044: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00046: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00047: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00048: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00051: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00052: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00053: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
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
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00054: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00055: Normal(Talk, TargetCanMove), id=PIPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00056: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00057: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00058: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00059: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00060: Normal(None), id=unknown" );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "StmBda616:68078 calling Scene00061: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda616 );
