// FFXIVTheMovie.ParserV3.2
// id table disabled
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme110 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme110() : Sapphire::ScriptAPI::EventScript( 69175 ){}; 
  ~LucKme110() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1030233
  //ACTOR1 = 1030234
  //ACTOR2 = 1030375
  //ACTOR3 = 1030376
  //ACTOR4 = 1030235
  //ACTOR5 = 1030236
  //ACTOR6 = 1030237
  //BINDACTOR01 = 7935127
  //BINDACTOR02 = 7943553
  //ITEM0 = 2002610
  //LOCACTION01 = 5625
  //LOCACTION02 = 85
  //LOCACTION03 = 641
  //LOCACTION04 = 1
  //LOCACTION05 = 827
  //LOCACTION06 = 4798
  //LOCACTION07 = 5671
  //LOCACTION08 = 808
  //LOCACTION09 = 845
  //LOCACTION10 = 812
  //LOCACTION11 = 803
  //LOCACTOR01 = 1029406
  //LOCACTOR02 = 1029439
  //LOCACTOR03 = 1029447
  //LOCOBJECT01 = 2009845
  //LOCSE01 = 51
  //LOCSE02 = 121
  //LOCVFX01 = 293
  //STATUS0 = 416
  //VFXSMOKE = 76

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030233 || param2 == 1030233 ) // ACTOR0 = KORUTT
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KORUTT
          break;
        }
        if( param1 == 1030234 || param2 == 1030234 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030375 || param2 == 1030375 ) // ACTOR2 = MYSTERYVOICE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=MYSTERYVOICE
          }
          break;
        }
        if( param1 == 1030376 || param2 == 1030376 ) // ACTOR3 = KORUTT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KORUTT
          break;
        }
        if( param1 == 1030235 || param2 == 1030235 ) // ACTOR4 = KOGGDWARFA03639
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=KOGGDWARFA03639
          break;
        }
        if( param1 == 1030236 || param2 == 1030236 ) // ACTOR5 = KOGGDWARFC03639
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KOGGDWARFC03639
          break;
        }
        if( param1 == 1030237 || param2 == 1030237 ) // ACTOR6 = KOGGDWARFB0363
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KOGGDWARFB0363
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 1030375 || param2 == 1030375 ) // ACTOR2 = MYSTERYVOICE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          }
          break;
        }
        if( param1 == 1030235 || param2 == 1030235 ) // ACTOR4 = KOGGDWARFA03639
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=KOGGDWARFA03639
          break;
        }
        if( param1 == 1030236 || param2 == 1030236 ) // ACTOR5 = KOGGDWARFC03639
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=KOGGDWARFC03639
          break;
        }
        if( param1 == 1030237 || param2 == 1030237 ) // ACTOR6 = KOGGDWARFB0363
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=KOGGDWARFB0363
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 1030235 || param2 == 1030235 ) // ACTOR4 = KOGGDWARFA03639
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, Inventory, TargetCanMove, CanCancel), id=KOGGDWARFA03639
            // +Callback Scene00013: Normal(Talk, NpcDespawn, TargetCanMove, CanCancel), id=KOGGDWARFA03639
          }
          break;
        }
        if( param1 == 1030236 || param2 == 1030236 ) // ACTOR5 = KOGGDWARFC03639
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, Inventory, TargetCanMove, CanCancel), id=KOGGDWARFC03639
            // +Callback Scene00015: Normal(Talk, NpcDespawn, TargetCanMove, CanCancel), id=KOGGDWARFC03639
          }
          break;
        }
        if( param1 == 1030237 || param2 == 1030237 ) // ACTOR6 = KOGGDWARFB03639
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, Inventory, TargetCanMove, CanCancel), id=KOGGDWARFB03639
            // +Callback Scene00017: Normal(Talk, NpcDespawn, TargetCanMove, CanCancel), id=KOGGDWARFB03639
          }
          break;
        }
        if( param1 == 1030375 || param2 == 1030375 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 255:
      {
        Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
        // +Callback Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=MYSTERYVOICE
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme110:69175 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KORUTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00004: Normal(Talk, TargetCanMove), id=KORUTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00005: Normal(Talk, TargetCanMove), id=KOGGDWARFA03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00006: Normal(Talk, TargetCanMove), id=KOGGDWARFC03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00007: Normal(Talk, TargetCanMove), id=KOGGDWARFB0363" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00008: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00009: Normal(Talk, TargetCanMove), id=KOGGDWARFA03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00010: Normal(Talk, TargetCanMove), id=KOGGDWARFC03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00011: Normal(Talk, TargetCanMove), id=KOGGDWARFB0363" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00012: Normal(Talk, Inventory, TargetCanMove, CanCancel), id=KOGGDWARFA03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00013( player );
      }
    };
    player.addStatusEffectByIdIfNotExist( 416, 1000, player, 0, true );
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove, CanCancel), id=KOGGDWARFA03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00014: Normal(Talk, Inventory, TargetCanMove, CanCancel), id=KOGGDWARFC03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00015( player );
      }
    };
    player.addStatusEffectByIdIfNotExist( 416, 1000, player, 0, true );
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00015: Normal(Talk, NpcDespawn, TargetCanMove, CanCancel), id=KOGGDWARFC03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00016: Normal(Talk, Inventory, TargetCanMove, CanCancel), id=KOGGDWARFB03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00017( player );
      }
    };
    player.addStatusEffectByIdIfNotExist( 416, 1000, player, 0, true );
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove, CanCancel), id=KOGGDWARFB03639" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00018: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00019: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme110:69175 calling Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=MYSTERYVOICE" );
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
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( LucKme110 );
