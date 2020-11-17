// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda704 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda704() : Sapphire::ScriptAPI::EventScript( 68087 ){}; 
  ~StmBda704() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 8 entries
  //SEQ_2, 8 entries
  //SEQ_3, 5 entries
  //SEQ_4, 11 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1021717
  //ACTOR1 = 1021718
  //ACTOR10 = 1021698
  //ACTOR11 = 1021699
  //ACTOR12 = 1021700
  //ACTOR13 = 1021719
  //ACTOR14 = 1021720
  //ACTOR15 = 1021701
  //ACTOR16 = 1022721
  //ACTOR17 = 1022722
  //ACTOR18 = 1022723
  //ACTOR19 = 1021702
  //ACTOR2 = 1022732
  //ACTOR20 = 1021703
  //ACTOR3 = 1022736
  //ACTOR4 = 1022737
  //ACTOR5 = 1022733
  //ACTOR6 = 1022734
  //ACTOR7 = 1022735
  //ACTOR8 = 1020606
  //ACTOR9 = 1020607
  //BINDACTOR01 = 6925979
  //BINDACTOR02 = 6870689
  //BINDACTOR03 = 6925981
  //BINDACTOR04 = 6925982
  //BINDACTOR05 = 6926030
  //BINDACTOR06 = 6926031
  //BINDACTOR07 = 6870599
  //BINDACTOR08 = 6870600
  //BINDACTOR09 = 6870601
  //CUTSCENEN01 = 1481
  //LOCACTOR01 = 1015915
  //LOCACTOR02 = 1015916
  //LOCBGM01 = 458

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1021717 || param2 == 1021717 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021718 || param2 == 1021718 ) // ACTOR1 = KRILE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1022732 || param2 == 1022732 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022736 || param2 == 1022736 ) // ACTOR3 = MNAAGO
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022737 || param2 == 1022737 ) // ACTOR4 = WISCAR
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1022733 || param2 == 1022733 ) // ACTOR5 = ARENVALD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ARENVALD
          }
          break;
        }
        if( param1 == 1022734 || param2 == 1022734 ) // ACTOR6 = VMAHTIA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022735 || param2 == 1022735 ) // ACTOR7 = JMOLDVA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        if( param1 == 1020606 || param2 == 1020606 ) // ACTOR8 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020607 || param2 == 1020607 ) // ACTOR9 = KRILE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1022732 || param2 == 1022732 ) // ACTOR2 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1022736 || param2 == 1022736 ) // ACTOR3 = MNAAGO
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022737 || param2 == 1022737 ) // ACTOR4 = WISCAR
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1021698 || param2 == 1021698 ) // ACTOR10 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1021699 || param2 == 1021699 ) // ACTOR11 = SERPENTOFFICER
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1021700 || param2 == 1021700 ) // ACTOR12 = STORMOFFICER
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1022736 || param2 == 1022736 ) // ACTOR3 = MNAAGO
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022737 || param2 == 1022737 ) // ACTOR4 = WISCAR
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1022733 || param2 == 1022733 ) // ACTOR5 = ARENVALD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1022734 || param2 == 1022734 ) // ACTOR6 = VMAHTIA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=VMAHTIA
          break;
        }
        if( param1 == 1022735 || param2 == 1022735 ) // ACTOR7 = JMOLDVA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=JMOLDVA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1021719 || param2 == 1021719 ) // ACTOR13 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1021720 || param2 == 1021720 ) // ACTOR14 = URIANGER
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1021698 || param2 == 1021698 ) // ACTOR10 = RAUBAHN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1021699 || param2 == 1021699 ) // ACTOR11 = SERPENTOFFICER
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1021700 || param2 == 1021700 ) // ACTOR12 = STORMOFFICER
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1021701 || param2 == 1021701 ) // ACTOR15 = KANESENNA
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=KANESENNA
            // +Callback Scene00028: Normal(Talk, TargetCanMove), id=KANESENNA
          }
          break;
        }
        if( param1 == 1022721 || param2 == 1022721 ) // ACTOR16 = BODYGUARD01623
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=BODYGUARD01623
          break;
        }
        if( param1 == 1022722 || param2 == 1022722 ) // ACTOR17 = EYNZAHRSLAFYRSYN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN
          break;
        }
        if( param1 == 1022723 || param2 == 1022723 ) // ACTOR18 = LUCIA
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1021698 || param2 == 1021698 ) // ACTOR10 = RAUBAHN
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1021699 || param2 == 1021699 ) // ACTOR11 = SERPENTOFFICER
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1021700 || param2 == 1021700 ) // ACTOR12 = STORMOFFICER
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1021719 || param2 == 1021719 ) // ACTOR13 = ALPHINAUD
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021720 || param2 == 1021720 ) // ACTOR14 = URIANGER
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1021702 || param2 == 1021702 ) // ACTOR19 = MERLWYB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=MERLWYB
            // +Callback Scene00038: Normal(Talk, TargetCanMove), id=MERLWYB
          }
          break;
        }
        if( param1 == 1021703 || param2 == 1021703 ) // ACTOR20 = AYMERIC
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC
            // +Callback Scene00040: Normal(Talk, TargetCanMove), id=AYMERIC
          }
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1021698 || param2 == 1021698 ) // ACTOR10 = RAUBAHN
        {
          Scene00041( player ); // Scene00041: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1021699 || param2 == 1021699 ) // ACTOR11 = SERPENTOFFICER
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
          break;
        }
        if( param1 == 1021700 || param2 == 1021700 ) // ACTOR12 = STORMOFFICER
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=STORMOFFICER
          break;
        }
        if( param1 == 1021701 || param2 == 1021701 ) // ACTOR15 = KANESENNA
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=KANESENNA
          break;
        }
        if( param1 == 1021702 || param2 == 1021702 ) // ACTOR19 = MERLWYB
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=MERLWYB
          break;
        }
        if( param1 == 1021703 || param2 == 1021703 ) // ACTOR20 = AYMERIC
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1022721 || param2 == 1022721 ) // ACTOR16 = BODYGUARD01623
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=BODYGUARD01623
          break;
        }
        if( param1 == 1022722 || param2 == 1022722 ) // ACTOR17 = EYNZAHRSLAFYRSYN
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN
          break;
        }
        if( param1 == 1022723 || param2 == 1022723 ) // ACTOR18 = LUCIA
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1021719 || param2 == 1021719 ) // ACTOR13 = ALPHINAUD
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1021720 || param2 == 1021720 ) // ACTOR14 = URIANGER
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=URIANGER
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda704:68087 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00002: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00004: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00005: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00006: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00007: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00008: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00010: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00012: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00013: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00014: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00015: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00016: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00017: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00018: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00019: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00020: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00021: Normal(Talk, TargetCanMove), id=JMOLDVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00023: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00024: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00025: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00026: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00027: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00028( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00028: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00029: Normal(Talk, TargetCanMove), id=BODYGUARD01623" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00030: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00031: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00032: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00033: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00034: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00036: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00037: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00038( player );
    };
    player.playScene( getId(), 37, NONE, callback );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00038: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00040( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }
  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00040: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00041: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAUBAHN" );
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
    player.playScene( getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00042: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00043: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00044: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00045: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00046: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00047: Normal(Talk, TargetCanMove), id=BODYGUARD01623" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00048: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00049: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00050: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "StmBda704:68087 calling Scene00051: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda704 );
