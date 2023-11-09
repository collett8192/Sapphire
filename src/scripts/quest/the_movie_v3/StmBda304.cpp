// FFXIVTheMovie.ParserV3.11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"
#include "Territory/Territory.h"
#include "Actor/BNpc.h"

using namespace Sapphire;

class StmBda304 : public Sapphire::ScriptAPI::QuestScript
{
public:
  StmBda304() : Sapphire::ScriptAPI::QuestScript( 68016 ){}; 
  ~StmBda304() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 7 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEVENTSPIRIT = 1071
  //ACTOR0 = 1019929
  //ACTOR1 = 1019930
  //ACTOR10 = 1019939
  //ACTOR11 = 1019940
  //ACTOR12 = 1019941
  //ACTOR13 = 1021508
  //ACTOR2 = 1019931
  //ACTOR3 = 1019933
  //ACTOR4 = 1019932
  //ACTOR5 = 1021505
  //ACTOR6 = 1019935
  //ACTOR7 = 1019936
  //ACTOR8 = 1019937
  //ACTOR9 = 1019938
  //BINDACTOR0 = 6829396
  //BINDACTOR1 = 6829410
  //BINDACTOR2 = 6829411
  //BINDACTOR3 = 6829413
  //BINDACTOR4 = 6829414
  //BINDACTOR5 = 6829415
  //BINDACTOR6 = 6829417
  //EOBJECT0 = 2007852
  //EOBJECT1 = 2007854
  //EVENTACTION0 = 54
  //LOCACTOR0 = 1018509
  //LOCACTOR1 = 1019541

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
        if( param1 == 1019929 ) // ACTOR0 = ALISAIE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00000( quest, player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE
          }
          break;
        }
        if( param1 == 1019930 ) // ACTOR1 = LYSE
        {
          Scene00002( quest, player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019931 ) // ACTOR2 = TANSUI
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00003( quest, player ); // Scene00003: Normal(Talk, TargetCanMove, ENpcBind), id=TANSUI
          }
          break;
        }
        if( param1 == 1019933 ) // ACTOR3 = LYSE
        {
          Scene00004( quest, player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019932 ) // ACTOR4 = ALISAIE
        {
          Scene00005( quest, player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1021505 ) // ACTOR5 = RASHO
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00006( quest, player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=RASHO
          }
          break;
        }
        if( param1 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00007( quest, player ); // Scene00007: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1019936 ) // ACTOR7 = ALISAIE
        {
          Scene00008( quest, player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019937 ) // ACTOR8 = LYSE
        {
          Scene00009( quest, player ); // Scene00009: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1019938 ) // ACTOR9 = LYSE
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00010( quest, player ); // Scene00010: Normal(Talk, TargetCanMove, ENpcBind), id=LYSE
          }
          break;
        }
        if( param1 == 1019939 ) // ACTOR10 = ALISAIE
        {
          Scene00011( quest, player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00012( quest, player ); // Scene00012: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1021505 ) // ACTOR5 = RASHO
        {
          Scene00013( quest, player ); // Scene00013: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2007852 ) // EOBJECT0 = unknown
        {
          if( quest.getUI8BL() != 1 )
          {
            Scene00015( quest, player ); // Scene00015: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2007854 ) // EOBJECT1 = unknown
        {
          if( quest.getUI8BH() != 1 )
          {
            Scene00017( quest, player ); // Scene00017: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1019940 ) // ACTOR11 = LYSE
        {
          Scene00018( quest, player ); // Scene00018: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1019941 ) // ACTOR12 = ALISAIE
        {
          Scene00019( quest, player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1021505 ) // ACTOR5 = RASHO
        {
          Scene00020( quest, player ); // Scene00020: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00021( quest, player ); // Scene00021: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1021508 ) // ACTOR13 = NAWASHIRO
        {
          if( quest.getUI8AL() != 1 )
          {
            Scene00022( quest, player ); // Scene00022: Normal(Talk, TargetCanMove), id=NAWASHIRO
          }
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019939 ) // ACTOR10 = ALISAIE
        {
          Scene00023( quest, player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          // +Callback Scene00024: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, SystemTalk), id=ALISAIE
          break;
        }
        if( param1 == 1019940 ) // ACTOR11 = LYSE
        {
          Scene00025( quest, player ); // Scene00025: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021505 ) // ACTOR5 = RASHO
        {
          Scene00026( quest, player ); // Scene00026: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00027( quest, player ); // Scene00027: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1021508 ) // ACTOR13 = NAWASHIRO
        {
          Scene00028( quest, player ); // Scene00028: Normal(Talk, TargetCanMove), id=NAWASHIRO
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
    if( quest.getUI8BL() == 1 )
      if( quest.getUI8BH() == 1 )
        if( quest.getUI8AL() == 1 )
        {
          quest.setUI8BL( 0 );
          quest.setUI8BH( 0 );
          quest.setUI8AL( 0 );
          quest.setBitFlag8( 1, false );
          quest.setBitFlag8( 2, false );
          quest.setBitFlag8( 3, false );
          quest.setSeq( 255 );
        }
  }

  void Scene00000( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        Scene00001( quest, player );
      }
    };
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, callback );
  }
  void Scene00001( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      checkProgressSeq0( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, callback );
  }

  void Scene00002( World::Quest& quest, Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 2, HIDE_HOTBAR, callback );
  }

  void Scene00003( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True(Todo:0)
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00003: Normal(Talk, TargetCanMove, ENpcBind), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 0, 0, 0, 0 );
      checkProgressSeq1( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, callback );
  }

  void Scene00004( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, callback );
  }

  void Scene00005( World::Quest& quest, Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, callback );
  }

  void Scene00006( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 1, Flag8(1)=True(Todo:1)
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=RASHO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 1, 0, 0, 0 );
      checkProgressSeq2( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00007: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, callback );
  }

  void Scene00008( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, callback );
  }

  void Scene00009( World::Quest& quest, Entity::Player& player ) //SEQ_2: ACTOR8, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00009: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 9, HIDE_HOTBAR, callback );
  }

  void Scene00010( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR9, UI8AL = 1, Flag8(1)=True(Todo:2)
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00010: Normal(Talk, TargetCanMove, ENpcBind), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 2, 0, 0, 0 );
      checkProgressSeq3( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 10, HIDE_HOTBAR, callback );
  }

  void Scene00011( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 11, HIDE_HOTBAR, callback );
  }

  void Scene00012( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00012: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 12, HIDE_HOTBAR, callback );
  }

  void Scene00013( World::Quest& quest, Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00013: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 13, HIDE_HOTBAR, callback );
  }

  void Scene00015( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT0, UI8BL = 1, Flag8(1)=True(Todo:3)
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00015: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BL( 1 );
      quest.setBitFlag8( 1, true );
      eventMgr().sendEventNotice( player, getId(), 3, 0, 0, 0 );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 15, HIDE_HOTBAR, callback );
  }

  void Scene00017( World::Quest& quest, Entity::Player& player ) //SEQ_4: EOBJECT1, UI8BH = 1, Flag8(2)=True
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00017: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8BH( 1 );
      quest.setBitFlag8( 2, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 17, HIDE_HOTBAR, callback );
  }

  void Scene00018( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00018: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 18, HIDE_HOTBAR, callback );
  }

  void Scene00019( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 19, HIDE_HOTBAR, callback );
  }

  void Scene00020( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00020: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 20, HIDE_HOTBAR, callback );
  }

  void Scene00021( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00021: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 21, HIDE_HOTBAR, callback );
  }

  void Scene00022( World::Quest& quest, Entity::Player& player ) //SEQ_4: ACTOR13, UI8AL = 1, Flag8(3)=True
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00022: Normal(Talk, TargetCanMove), id=NAWASHIRO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      quest.setUI8AL( 1 );
      quest.setBitFlag8( 3, true );
      checkProgressSeq4( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 22, HIDE_HOTBAR, callback );
  }

  void Scene00023( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      Scene00024( quest, player );
    };
    eventMgr().playQuestScene( player, getId(), 23, HIDE_HOTBAR, callback );
  }
  void Scene00024( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00024: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, SystemTalk), id=ALISAIE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
      if( result.numOfResults > 0 && result.getResult( 0 ) == 1 )
      {
        player.finishQuest( getId(), result.getResult( 1 ) );
      }
    };
    eventMgr().playQuestScene( player, getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00025: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 25, HIDE_HOTBAR, callback );
  }

  void Scene00026( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00026: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 26, HIDE_HOTBAR, callback );
  }

  void Scene00027( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00027: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 27, HIDE_HOTBAR, callback );
  }

  void Scene00028( World::Quest& quest, Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    playerMgr().sendDebug( player, "StmBda304:68016 calling Scene00028: Normal(Talk, TargetCanMove), id=NAWASHIRO" );
    auto callback = [ & ]( World::Quest& quest, Entity::Player& player , const Event::SceneResult& result )
    {
    };
    eventMgr().playQuestScene( player, getId(), 28, HIDE_HOTBAR, callback );
  }
};

EXPOSE_SCRIPT( StmBda304 );
