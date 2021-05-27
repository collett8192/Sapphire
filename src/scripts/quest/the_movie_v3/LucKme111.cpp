// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme111 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme111() : Sapphire::ScriptAPI::EventScript( 69176 ){}; 
  ~LucKme111() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 5 entries
  //SEQ_2, 25 entries
  //SEQ_3, 23 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1030375
  //ACTOR1 = 1030376
  //ACTOR10 = 1030243
  //ACTOR11 = 1030244
  //ACTOR12 = 1030245
  //ACTOR13 = 1030246
  //ACTOR14 = 1030247
  //ACTOR15 = 1030248
  //ACTOR16 = 1030249
  //ACTOR17 = 1030595
  //ACTOR18 = 1030596
  //ACTOR19 = 1030597
  //ACTOR2 = 1030377
  //ACTOR20 = 1030598
  //ACTOR21 = 1030599
  //ACTOR22 = 1030600
  //ACTOR23 = 1030601
  //ACTOR24 = 1030602
  //ACTOR25 = 1030603
  //ACTOR26 = 1030604
  //ACTOR27 = 1030612
  //ACTOR3 = 1027296
  //ACTOR4 = 1030239
  //ACTOR5 = 1030292
  //ACTOR6 = 1030238
  //ACTOR7 = 1030240
  //ACTOR8 = 1030241
  //ACTOR9 = 1030242
  //BINDACTOR01 = 7943553
  //BINDACTOR02 = 7943557
  //BINDACTOR03 = 7943565
  //BINDACTOR04 = 7943567
  //BINDACTOR05 = 7943566
  //BINDACTOR06 = 7961263
  //BINDACTOR07 = 7961269
  //BINDACTOR08 = 7943560
  //BINDACTOR09 = 7943561
  //BINDACTOR10 = 7961271
  //BINDACTOR11 = 7961274
  //BINDACTOR12 = 7943564
  //BINDACTOR13 = 7961279
  //BINDACTOR14 = 7962912
  //BINDACTOR15 = 7961270
  //BINDACTOR16 = 7961272
  //BINDACTOR17 = 7961273
  //BINDACTOR18 = 7961276
  //BINDACTOR19 = 7961278
  //EOBJECT0 = 2010100
  //ITEM0 = 2002611

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030375 || param2 == 1030375 ) // ACTOR0 = MYSTERYVOICE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030376 || param2 == 1030376 ) // ACTOR1 = KORUTT
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KORUTT
          break;
        }
        if( param1 == 1030377 || param2 == 1030377 ) // ACTOR2 = GLAGG
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GLAGG
          break;
        }
        if( param1 == 2010100 || param2 == 2010100 ) // EOBJECT0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 5
      case 1:
      {
        if( param1 == 1027296 || param2 == 1027296 ) // ACTOR3 = XAMOTT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=XAMOTT
          }
          break;
        }
        if( param1 == 1030375 || param2 == 1030375 ) // ACTOR0 = MYSTERYVOICE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030377 || param2 == 1030377 ) // ACTOR2 = GLAGG
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=GLAGG
          break;
        }
        if( param1 == 2010100 || param2 == 2010100 ) // EOBJECT0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030239 || param2 == 1030239 ) // ACTOR4 = KORUTT
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=KORUTT
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 5
      case 2:
      {
        if( param1 == 1030292 || param2 == 1030292 ) // ACTOR5 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1027296 || param2 == 1027296 ) // ACTOR3 = XAMOTT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=XAMOTT
          break;
        }
        if( param1 == 1030239 || param2 == 1030239 ) // ACTOR4 = KORUTT
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=KORUTT
          break;
        }
        if( param1 == 1030238 || param2 == 1030238 ) // ACTOR6 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030240 || param2 == 1030240 ) // ACTOR7 = MAGNUS
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1030241 || param2 == 1030241 ) // ACTOR8 = THAFFE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1030242 || param2 == 1030242 ) // ACTOR9 = JERYK
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1030243 || param2 == 1030243 ) // ACTOR10 = RHONRON
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=RHONRON
          break;
        }
        if( param1 == 1030244 || param2 == 1030244 ) // ACTOR11 = KAISHIRR
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1030245 || param2 == 1030245 ) // ACTOR12 = JOURNEYSHEADNURSE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=JOURNEYSHEADNURSE
          break;
        }
        if( param1 == 1030246 || param2 == 1030246 ) // ACTOR13 = EMPLOYEE03287
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=EMPLOYEE03287
          break;
        }
        if( param1 == 1030247 || param2 == 1030247 ) // ACTOR14 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030248 || param2 == 1030248 ) // ACTOR15 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030249 || param2 == 1030249 ) // ACTOR16 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030595 || param2 == 1030595 ) // ACTOR17 = IRVITHE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=IRVITHE
          break;
        }
        if( param1 == 1030596 || param2 == 1030596 ) // ACTOR18 = GRITHIL
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=GRITHIL
          break;
        }
        if( param1 == 1030597 || param2 == 1030597 ) // ACTOR19 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030598 || param2 == 1030598 ) // ACTOR20 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030599 || param2 == 1030599 ) // ACTOR21 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030600 || param2 == 1030600 ) // ACTOR22 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030601 || param2 == 1030601 ) // ACTOR23 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030602 || param2 == 1030602 ) // ACTOR24 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030603 || param2 == 1030603 ) // ACTOR25 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030604 || param2 == 1030604 ) // ACTOR26 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030612 || param2 == 1030612 ) // ACTOR27 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8CH max stack 5
      case 3:
      {
        if( param1 == 1030240 || param2 == 1030240 ) // ACTOR7 = MAGNUS
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00036: Normal(Talk, FadeIn, TargetCanMove), id=MAGNUS
          }
          break;
        }
        if( param1 == 1030243 || param2 == 1030243 ) // ACTOR10 = RHONRON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00037( player ); // Scene00037: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00038: Normal(Talk, FadeIn, TargetCanMove), id=RHONRON
          }
          break;
        }
        if( param1 == 1030244 || param2 == 1030244 ) // ACTOR11 = KAISHIRR
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00039( player ); // Scene00039: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00040: Normal(Talk, FadeIn, TargetCanMove), id=KAISHIRR
          }
          break;
        }
        if( param1 == 1030241 || param2 == 1030241 ) // ACTOR8 = THAFFE
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1030242 || param2 == 1030242 ) // ACTOR9 = JERYK
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1030249 || param2 == 1030249 ) // ACTOR16 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030598 || param2 == 1030598 ) // ACTOR20 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030601 || param2 == 1030601 ) // ACTOR23 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030245 || param2 == 1030245 ) // ACTOR12 = JOURNEYSHEADNURSE
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=JOURNEYSHEADNURSE
          break;
        }
        if( param1 == 1030600 || param2 == 1030600 ) // ACTOR22 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030602 || param2 == 1030602 ) // ACTOR24 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030603 || param2 == 1030603 ) // ACTOR25 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030604 || param2 == 1030604 ) // ACTOR26 = unknown
        {
          Scene00050( player ); // Scene00050: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030612 || param2 == 1030612 ) // ACTOR27 = unknown
        {
          Scene00051( player ); // Scene00051: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030246 || param2 == 1030246 ) // ACTOR13 = EMPLOYEE03287
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=EMPLOYEE03287
          break;
        }
        if( param1 == 1030595 || param2 == 1030595 ) // ACTOR17 = IRVITHE
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=IRVITHE
          break;
        }
        if( param1 == 1030596 || param2 == 1030596 ) // ACTOR18 = GRITHIL
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=GRITHIL
          break;
        }
        if( param1 == 1030247 || param2 == 1030247 ) // ACTOR14 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030248 || param2 == 1030248 ) // ACTOR15 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030597 || param2 == 1030597 ) // ACTOR19 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030599 || param2 == 1030599 ) // ACTOR21 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030238 || param2 == 1030238 ) // ACTOR6 = ALPHINAUD
        {
          Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030292 || param2 == 1030292 ) // ACTOR5 = ALISAIE
        {
          Scene00060( player ); // Scene00060: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030292 || param2 == 1030292 ) // ACTOR5 = ALISAIE
        {
          Scene00061( player ); // Scene00061: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030238 || param2 == 1030238 ) // ACTOR6 = ALPHINAUD
        {
          Scene00062( player ); // Scene00062: Normal(Talk, TargetCanMove), id=ALPHINAUD
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 3 );
      player.setQuestUI8CH( getId(), 5 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme111:69176 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00002: Normal(Talk, TargetCanMove), id=KORUTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00003: Normal(Talk, TargetCanMove), id=GLAGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq0( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00005: Normal(Talk, TargetCanMove), id=XAMOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00006: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00007: Normal(Talk, TargetCanMove), id=GLAGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00009: Normal(Talk, TargetCanMove), id=KORUTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00011: Normal(Talk, TargetCanMove), id=XAMOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00012: Normal(Talk, TargetCanMove), id=KORUTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00014: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00015: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00016: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00017: Normal(Talk, TargetCanMove), id=RHONRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00018: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00019: Normal(Talk, TargetCanMove), id=JOURNEYSHEADNURSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00020: Normal(Talk, TargetCanMove), id=EMPLOYEE03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00024: Normal(Talk, TargetCanMove), id=IRVITHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00025: Normal(Talk, TargetCanMove), id=GRITHIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00035: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00036( player );
      }
    };
    player.playScene( getId(), 35, NONE, callback );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00036: Normal(Talk, FadeIn, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00037: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00038( player );
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00038: Normal(Talk, FadeIn, TargetCanMove), id=RHONRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 38, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00039: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00040( player );
      }
    };
    player.playScene( getId(), 39, NONE, callback );
  }
  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00040: Normal(Talk, FadeIn, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 40, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00041: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00042: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00046: Normal(Talk, TargetCanMove), id=JOURNEYSHEADNURSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00047: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00049: Normal(None), id=unknown" );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00050: Normal(None), id=unknown" );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00051: Normal(None), id=unknown" );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00052: Normal(Talk, TargetCanMove), id=EMPLOYEE03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00053: Normal(Talk, TargetCanMove), id=IRVITHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00054: Normal(Talk, TargetCanMove), id=GRITHIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00057: Normal(None), id=unknown" );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00058: Normal(None), id=unknown" );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00059: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00060: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "LucKme111:69176 calling Scene00061: Normal(Talk, NpcDespawn, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
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
    player.sendDebug( "LucKme111:69176 calling Scene00062: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 62, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKme111 );
