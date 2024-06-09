// FFXIVTheMovie.ParserV3.12
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBdb109 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBdb109() : Sapphire::ScriptAPI::QuestScript( 68506 ){}; 
  ~StmBdb109() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_5, 3 entries
  //SEQ_6, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1024045
  //ACTOR1 = 1024046
  //ACTOR10 = 1024053
  //ACTOR11 = 1024341
  //ACTOR12 = 1024054
  //ACTOR2 = 1024047
  //ACTOR3 = 1024048
  //ACTOR4 = 1024049
  //ACTOR5 = 1023036
  //ACTOR6 = 1024050
  //ACTOR7 = 1024051
  //ACTOR8 = 1024052
  //ACTOR9 = 1024340
  //LOCACTSUFFERING = 961
  //LOCBGM01 = 459
  //LOCBGMBATTLE = 113
  //LOCBGMWINCHEAP = 23
  //LOCBINDALPH01 = 7074699
  //LOCBINDWIS01 = 7074698
  //LOCBINDWIS02 = 7074709
  //LOCENPCALPH01 = 1011887
  //LOCENPCAREN01 = 1019537
  //LOCENPCENEMY01 = 1024346
  //LOCENPCENEMY02 = 1024347
  //LOCENPCWIS01 = 1021992
  //LOCLEVELALPH01 = 7074675
  //LOCLEVELAREN01 = 7074677
  //LOCLEVELENEMYVS01 = 7154151
  //LOCLEVELENEMYVS02 = 7154152
  //LOCLEVELWIS01 = 7074678
  //LOCSEATK = 85
  //LOCSEWIN = 111
  //POPRANGE0 = 7091522
  //POPRANGE1 = 7091527
  //SNP0 = 17
  //SNP1 = 18

  static constexpr auto EVENT_ON_TALK = 0;
  static constexpr auto EVENT_ON_EMOTE = 1;
  static constexpr auto EVENT_ON_BNPC_KILL = 2;
  static constexpr auto EVENT_ON_WITHIN_RANGE = 3;
  static constexpr auto EVENT_ON_ENTER_TERRITORY = 4;
  static constexpr auto EVENT_ON_EVENT_ITEM = 5;
  static constexpr auto EVENT_ON_EOBJ_HIT = 6;
  static constexpr auto EVENT_ON_SAY = 7;

private:
  void onProgress( World::Quest& quest, Entity::Player& player, uint32_t type, uint64_t param1, uint32_t param2, uint32_t param3 )
  {
    switch( quest.getSeq() )
    {
      case 0:
      {
        if( type != EVENT_ON_BNPC_KILL ) Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NANAMOULNAMO
        break;
      }
      case 1:
      {
        if( param1 == 1024046 ) // ACTOR1 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00002( quest, player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1024045 ) // ACTOR0 = NANAMOULNAMO
        {
          Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove), id=NANAMOULNAMO
          break;
        }
        if( param1 == 1024047 ) // ACTOR2 = ALPHINAUD
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024048 ) // ACTOR3 = ARENVALD
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1024049 ) // ACTOR4 = WISCAR
        {
          Scene00006( quest, player ); // Scene00006: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1023036 ) // ACTOR5 = WATT
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove, ENpcBind), id=WATT
          }
          break;
        }
        if( param1 == 1024050 ) // ACTOR6 = WISCAR
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1024046 ) // ACTOR1 = LYSE
        {
          Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1024048 ) // ACTOR3 = ARENVALD
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1024052 ) // ACTOR8 = WISCAR
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove, SystemTalk), id=WISCAR
            // +Callback Scene00013: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00014: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, SystemTalk), id=WISCAR
          }
          break;
        }
        if( param1 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00015( quest, player ); // Scene00015: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        if( param1 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00016( quest, player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1024340 ) // ACTOR9 = WISCAR
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=WISCAR
          }
          break;
        }
        if( param1 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        if( param1 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1024053 ) // ACTOR10 = WISCAR
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove, SystemTalk), id=WISCAR
            // +Callback Scene00021: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00022: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, SystemTalk), id=WISCAR
          }
          break;
        }
        if( param1 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        if( param1 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00024( quest, player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1024341 ) // ACTOR11 = WISCAR
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00025( quest, player ); // Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=WISCAR
          }
          break;
        }
        if( param1 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=WATT
          break;
        }
        if( param1 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1023036 ) // ACTOR5 = WATT
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=WATT
          break;
        }
        if( param1 == 1024054 ) // ACTOR12 = WISCAR
        {
          Scene00029( quest, player ); // Scene00029: Normal(Talk, TargetCanMove), id=WISCAR
          break;
        }
        if( param1 == 1024051 ) // ACTOR7 = ALPHINAUD
        {
          Scene00030( quest, player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      default:
      {
        playerMgr().sendUrgent( player, "Sequence {} not defined.", quest.getSeq() );
        break;
      }
    }
  }

public:
  void onTalk( World::Quest& quest, Entity::Player& player, uint64_t actorId ) override
  {
    onProgress( quest, player, EVENT_ON_TALK, actorId, 0, 0 );
  }

  void onEmote( World::Quest& quest, uint64_t actorId, uint32_t emoteId, Sapphire::Entity::Player& player ) override
  {
    playerMgr().sendDebug( player, "emote: {}", emoteId );
    onProgress( quest, player, EVENT_ON_EMOTE, actorId, 0, emoteId );
  }

  void onBNpcKill( World::Quest& quest, Entity::BNpc& bnpc, Entity::Player& player ) override
  {
    onProgress( quest, player, EVENT_ON_BNPC_KILL, static_cast< uint64_t >( bnpc.getBNpcNameId() ), bnpc.getLayoutId(), 0 );
  }

  void onWithinRange( World::Quest& quest, Sapphire::Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( quest, player, EVENT_ON_WITHIN_RANGE, static_cast< uint64_t >( param1 ), 0, 0 );
  }

  void onEnterTerritory( World::Quest& quest, Sapphire::Entity::Player& player, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( quest, player, EVENT_ON_ENTER_TERRITORY, static_cast< uint64_t >( param1 ), static_cast< uint32_t >( param2 ), 0 );
  }
  void onEventItem( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId ) override
  {
    onProgress( quest, player, EVENT_ON_EVENT_ITEM, actorId, 0, 0 );
  }
  void onEObjHit( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t actionId ) override
  {
    onProgress( quest, player, EVENT_ON_EOBJ_HIT, actorId, actionId, 0 );
  }
  void onSay( World::Quest& quest, Sapphire::Entity::Player& player, uint64_t actorId, uint32_t sayId ) override
  {
    onProgress( quest, player, EVENT_ON_SAY, actorId, sayId, 0 );
  }

private:
  void checkProgressSeq0( World::Quest& quest, Entity::Player& player )
  {
    quest.setSeq( 1 );
  }
  void checkProgressSeq1( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 2 );
    }
  }
  void checkProgressSeq2( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 3 );
    }
  }
  void checkProgressSeq3( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 4 );
    }
  }
  void checkProgressSeq4( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 5 );
    }
  }
  void checkProgressSeq5( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 6 );
    }
  }
  void checkProgressSeq6( World::Quest& quest, Entity::Player& player )
  {
    if( quest.getUI8AL() == 1 )
    {
      quest.setUI8AL( 0 );
      quest.setBitFlag8( 1, false );
      quest.setSeq( 255 );
    }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00003: Normal(Talk, TargetCanMove), id=NANAMOULNAMO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00005: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00006: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00007: Normal(Talk, TargetCanMove, ENpcBind), id=WATT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00008: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00010: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00011: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00012: Normal(Talk, TargetCanMove, SystemTalk), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00013( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }
  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00013: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00014( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 13, INVIS_ENPC, callback );
  }
  void Scene00014( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00014: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, SystemTalk), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
        checkProgressSeq3( quest, player );
        playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
        eventMgr().eventFinish( player, result.eventId, 1 );
        warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
      }
    };
    eventMgr().playQuestScene( player, getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00015: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00016( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 16, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00017: Normal(Talk, NpcDespawn, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00018: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00020: Normal(Talk, TargetCanMove, SystemTalk), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00021( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }
  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00021: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        Scene00022( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 21, INVIS_ENPC, callback );
  }
  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR10, UI8AL = 1, Flag8(1)=True(Todo:4)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00022: Normal(Talk, FadeIn, TargetCanMove, Menu, AutoFadeIn, SystemTalk), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults == 1 || ( result.errorCode == 0 && result.numOfResults == 2 ) )
      {
        quest.setUI8AL( 1 );
        quest.setBitFlag8( 1, true );
        eventMgr().sendEventNotice( player, getId(), 4, 0, 0, 0 );
        checkProgressSeq5( quest, player );
        playerMgr().sendDebug( player, "Finished with AutoFadeIn scene, reloading zone..." );
        eventMgr().eventFinish( player, result.eventId, 1 );
        warpMgr().requestMoveTerritory( player, Common::WarpType::WARP_TYPE_NORMAL, teriMgr().getZoneByTerritoryTypeId( player.getTerritoryTypeId() )->getGuId(), player.getPos(), player.getRot() );
      }
    };
    eventMgr().playQuestScene( player, getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00023: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }

  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_5: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 24, HIDE_HOTBAR, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR11, UI8AL = 1, Flag8(1)=True(Todo:5)
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 5, 0, 0, 0 );
      checkProgressSeq6( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00026: Normal(Talk, TargetCanMove), id=WATT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_6: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=WATT" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }

  void Scene00029( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00029: Normal(Talk, TargetCanMove), id=WISCAR" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 29, HIDE_HOTBAR, callback );
  }

  void Scene00030( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBdb109:68506 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 30, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBdb109 );
