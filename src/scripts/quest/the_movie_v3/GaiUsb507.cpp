// FFXIVTheMovie.ParserV3.3
// id hint used:
//ACTOR17 = NPCB
//_ACTOR17 SET!!
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb507 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb507() : Sapphire::ScriptAPI::EventScript( 66412 ){}; 
  ~GaiUsb507() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 9 entries
  //SEQ_2, 12 entries
  //SEQ_3, 8 entries
  //SEQ_4, 12 entries
  //SEQ_5, 8 entries
  //SEQ_255, 13 entries

  //ACTOR0 = 1003958
  //ACTOR1 = 1006361
  //ACTOR10 = 1006345
  //ACTOR11 = 1006346
  //ACTOR12 = 1006347
  //ACTOR13 = 1006348
  //ACTOR14 = 1007587
  //ACTOR15 = 1007588
  //ACTOR16 = 1007589
  //ACTOR17 = 1006362
  //ACTOR18 = 1006349
  //ACTOR19 = 1006344
  //ACTOR2 = 1006353
  //ACTOR20 = 1007591
  //ACTOR21 = 1007592
  //ACTOR22 = 1007593
  //ACTOR23 = 1007594
  //ACTOR24 = 1006350
  //ACTOR25 = 1006351
  //ACTOR26 = 1007590
  //ACTOR27 = 1007595
  //ACTOR28 = 1007596
  //ACTOR29 = 1007597
  //ACTOR3 = 1006354
  //ACTOR4 = 1007586
  //ACTOR5 = 1007599
  //ACTOR6 = 1007600
  //ACTOR7 = 1007601
  //ACTOR8 = 1007618
  //ACTOR9 = 1007619
  //EVENTACTIONPROCESSLONG = 17
  //EVENTACTIONPROCESSMIDDLE = 16
  //EVENTACTIONPROCESSSHOR = 15
  //ITEM0 = 2000685
  //ITEM1 = 2001067
  //ITEM2 = 2000686
  //QSTACCEPTCHECK = 66417

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=ELUNED
        // +Callback Scene00001: Normal(QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 1006361 || param2 == 1006361 ) // ACTOR1 = NPCA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCA
          }
          break;
        }
        if( param1 == 1006353 || param2 == 1006353 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006354 || param2 == 1006354 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007586 || param2 == 1007586 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007599 || param2 == 1007599 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007600 || param2 == 1007600 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007601 || param2 == 1007601 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007618 || param2 == 1007618 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007619 || param2 == 1007619 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 4
      case 2:
      {
        if( param1 == 1006345 || param2 == 1006345 ) // ACTOR10 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006346 || param2 == 1006346 ) // ACTOR11 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006347 || param2 == 1006347 ) // ACTOR12 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006348 || param2 == 1006348 ) // ACTOR13 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006353 || param2 == 1006353 ) // ACTOR2 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007601 || param2 == 1007601 ) // ACTOR7 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007618 || param2 == 1007618 ) // ACTOR8 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007619 || param2 == 1007619 ) // ACTOR9 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007587 || param2 == 1007587 ) // ACTOR14 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007588 || param2 == 1007588 ) // ACTOR15 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007589 || param2 == 1007589 ) // ACTOR16 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006362 || param2 == 1006362 ) // ACTOR17 = NPCB
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=NPCB
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 4
      case 3:
      {
        if( param1 == 1006362 || param2 == 1006362 ) // ACTOR17 = NPCB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00028: Normal(Talk, TargetCanMove), id=NPCB
          }
          break;
        }
        if( param1 == 1006353 || param2 == 1006353 ) // ACTOR2 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007601 || param2 == 1007601 ) // ACTOR7 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007618 || param2 == 1007618 ) // ACTOR8 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007619 || param2 == 1007619 ) // ACTOR9 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007587 || param2 == 1007587 ) // ACTOR14 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007588 || param2 == 1007588 ) // ACTOR15 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007589 || param2 == 1007589 ) // ACTOR16 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM2 = UI8CL max stack 1
      //seq 4 event item ITEM1 = UI8DH max stack 3
      case 4:
      {
        if( param1 == 1006349 || param2 == 1006349 ) // ACTOR18 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00036( player ); // Scene00036: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006344 || param2 == 1006344 ) // ACTOR19 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00037( player ); // Scene00037: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1007591 || param2 == 1007591 ) // ACTOR20 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007592 || param2 == 1007592 ) // ACTOR21 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007593 || param2 == 1007593 ) // ACTOR22 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007594 || param2 == 1007594 ) // ACTOR23 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007587 || param2 == 1007587 ) // ACTOR14 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007588 || param2 == 1007588 ) // ACTOR15 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007589 || param2 == 1007589 ) // ACTOR16 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006362 || param2 == 1006362 ) // ACTOR17 = NPCB
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=NPCB
          break;
        }
        if( param1 == 1006350 || param2 == 1006350 ) // ACTOR24 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00048( player ); // Scene00048: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006351 || param2 == 1006351 ) // ACTOR25 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00051( player ); // Scene00051: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 5 event item ITEM2 = UI8BH max stack 1
      //seq 5 event item ITEM1 = UI8BL max stack 3
      case 5:
      {
        if( param1 == 1006362 || param2 == 1006362 ) // ACTOR17 = NPCB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00052( player ); // Scene00052: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00053: Normal(Talk, TargetCanMove), id=NPCB
          }
          break;
        }
        if( param1 == 1007591 || param2 == 1007591 ) // ACTOR20 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007592 || param2 == 1007592 ) // ACTOR21 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007593 || param2 == 1007593 ) // ACTOR22 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007594 || param2 == 1007594 ) // ACTOR23 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007587 || param2 == 1007587 ) // ACTOR14 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007588 || param2 == 1007588 ) // ACTOR15 = unknown
        {
          Scene00059( player ); // Scene00059: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007589 || param2 == 1007589 ) // ACTOR16 = unknown
        {
          Scene00060( player ); // Scene00060: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1003958 || param2 == 1003958 ) // ACTOR0 = ELUNED
        {
          Scene00061( player ); // Scene00061: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ELUNED
          break;
        }
        if( param1 == 1007590 || param2 == 1007590 ) // ACTOR26 = unknown
        {
          Scene00062( player ); // Scene00062: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007591 || param2 == 1007591 ) // ACTOR20 = unknown
        {
          Scene00063( player ); // Scene00063: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007592 || param2 == 1007592 ) // ACTOR21 = unknown
        {
          Scene00064( player ); // Scene00064: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007593 || param2 == 1007593 ) // ACTOR22 = unknown
        {
          Scene00065( player ); // Scene00065: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007594 || param2 == 1007594 ) // ACTOR23 = unknown
        {
          Scene00066( player ); // Scene00066: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007595 || param2 == 1007595 ) // ACTOR27 = unknown
        {
          Scene00067( player ); // Scene00067: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007596 || param2 == 1007596 ) // ACTOR28 = unknown
        {
          Scene00068( player ); // Scene00068: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007597 || param2 == 1007597 ) // ACTOR29 = unknown
        {
          Scene00069( player ); // Scene00069: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007587 || param2 == 1007587 ) // ACTOR14 = unknown
        {
          Scene00070( player ); // Scene00070: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007588 || param2 == 1007588 ) // ACTOR15 = unknown
        {
          Scene00071( player ); // Scene00071: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007589 || param2 == 1007589 ) // ACTOR16 = unknown
        {
          Scene00072( player ); // Scene00072: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006362 || param2 == 1006362 ) // ACTOR17 = NPCB
        {
          Scene00073( player ); // Scene00073: Normal(Talk, TargetCanMove), id=NPCB
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
    //onProgress( player, npcId, 0, 2, 0 );
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
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
      player.setQuestUI8BH( getId(), 4 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8CL( getId(), 0 );
            player.setQuestUI8DH( getId(), 0 );
            player.updateQuest( getId(), 5 );
            player.setQuestUI8BH( getId(), 1 );
            player.setQuestUI8BL( getId(), 3 );
          }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=ELUNED" );
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
    player.sendDebug( "GaiUsb507:66412 calling Scene00001: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00011: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00014: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00026: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00027: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00028( player );
      }
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00028: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00036: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00037: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00047: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00048: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00051: Normal(None), id=unknown" );
    player.setQuestUI8CH( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00052: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00053( player );
      }
    };
    player.playScene( getId(), 52, NONE, callback );
  }
  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00053: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00057: Normal(None), id=unknown" );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00058: Normal(None), id=unknown" );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00059: Normal(None), id=unknown" );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00060: Normal(None), id=unknown" );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00061: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ELUNED" );
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
    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00062: Normal(None), id=unknown" );
  }

  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00063: Normal(None), id=unknown" );
  }

  void Scene00064( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00064: Normal(None), id=unknown" );
  }

  void Scene00065( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00065: Normal(None), id=unknown" );
  }

  void Scene00066( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00066: Normal(None), id=unknown" );
  }

  void Scene00067( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00067: Normal(None), id=unknown" );
  }

  void Scene00068( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00068: Normal(None), id=unknown" );
  }

  void Scene00069( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00069: Normal(None), id=unknown" );
  }

  void Scene00070( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00070: Normal(None), id=unknown" );
  }

  void Scene00071( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00071: Normal(None), id=unknown" );
  }

  void Scene00072( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00072: Normal(None), id=unknown" );
  }

  void Scene00073( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb507:66412 calling Scene00073: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 73, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb507 );
