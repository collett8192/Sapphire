// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda204 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda204() : Sapphire::ScriptAPI::EventScript( 68009 ){}; 
  ~StmBda204() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 3 entries
  //SEQ_5, 5 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEMOTEWELCOMEUPPER = 591
  //ACTOR0 = 1020465
  //ACTOR1 = 1020464
  //ACTOR10 = 1020470
  //ACTOR11 = 1020471
  //ACTOR12 = 1020472
  //ACTOR2 = 1020466
  //ACTOR3 = 1020467
  //ACTOR4 = 1020468
  //ACTOR5 = 1022086
  //ACTOR6 = 5010000
  //ACTOR7 = 1018982
  //ACTOR8 = 1019002
  //ACTOR9 = 1020469
  //BINDACTOR0 = 6843430
  //BINDACTOR1 = 6843431
  //BINDACTOR2 = 6843427
  //BINDACTOR3 = 6843429
  //BINDACTOR4 = 6654180
  //BINDACTOR5 = 6654205
  //BINDACTOR6 = 7005898
  //EVENTRANGE0 = 7005899
  //EVENTPICTRUEMAINQUEST4002 = 531
  //ITEM0 = 2002099
  //LOCACTOR0 = 1018509
  //LOCBGMTOHO = 465
  //POPRANGE0 = 6958867

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020465 || param2 == 1020465 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1020464 || param2 == 1020464 ) // ACTOR1 = HANCOCK
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HANCOCK
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR2 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020467 || param2 == 1020467 ) // ACTOR3 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1020468 || param2 == 1020468 ) // ACTOR4 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 1022086 || param2 == 1022086 ) // ACTOR5 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=LYSE
          }
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR2 = TATARU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020464 || param2 == 1020464 ) // ACTOR1 = HANCOCK
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HANCOCK
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk), id=unknown
          }
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR2 = TATARU
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020464 || param2 == 1020464 ) // ACTOR1 = HANCOCK
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HANCOCK
        }
        if( param1 == 1022086 || param2 == 1022086 ) // ACTOR5 = LYSE
        {
          //Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LYSE
          Scene00009( player );
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 1018982 || param2 == 1018982 ) // ACTOR7 = KARAKU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00015: Normal(Talk, FadeIn, TargetCanMove), id=KARAKU
          }
        }
        if( param1 == 1020466 || param2 == 1020466 ) // ACTOR2 = TATARU
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1020464 || param2 == 1020464 ) // ACTOR1 = HANCOCK
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HANCOCK
        }
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR6 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1019002 || param2 == 1019002 ) // ACTOR8 = KOTOKAZE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=KOTOKAZE
          }
        }
        if( param1 == 1018982 || param2 == 1018982 ) // ACTOR7 = KARAKU
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=KARAKU
        }
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8CH max stack 1
      case 5:
      {
        if( param1 == 1020469 || param2 == 1020469 ) // ACTOR9 = KUGANEFERRYMAN
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00026: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN
          }
          else
          {
            Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN
          }
        }
        if( param1 == 1020470 || param2 == 1020470 ) // ACTOR10 = KUGANECAPTAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00029: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN
          }
          else
          {
            Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN
          }
        }
        if( param1 == 1020471 || param2 == 1020471 ) // ACTOR11 = RADZATHANMERCHANT
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00032: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT
          }
          else
          {
            Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT
          }
        }
        if( param1 == 1019002 || param2 == 1019002 ) // ACTOR8 = KOTOKAZE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=KOTOKAZE
        }
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR6 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1020472 || param2 == 1020472 ) // ACTOR12 = LYSE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE
        }
        if( param1 == 1020469 || param2 == 1020469 ) // ACTOR9 = KUGANEFERRYMAN
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN
        }
        if( param1 == 1020470 || param2 == 1020470 ) // ACTOR10 = KUGANECAPTAIN
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN
        }
        if( param1 == 1020471 || param2 == 1020471 ) // ACTOR11 = RADZATHANMERCHANT
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT
        }
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR6 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
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
      player.setQuestUI8BH( getId(), 1 );
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 5 );
      player.setQuestUI8CH( getId(), 1 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
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
    player.sendDebug( "StmBda204:68009 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda204:68009 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.exitInstance();
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00002: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00006: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00007: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00008: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00009: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00011: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00012: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00013: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling [BranchTrue]Scene00015: Normal(Talk, FadeIn, TargetCanMove), id=KARAKU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00016: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00017: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00021( player );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling [BranchTrue]Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=KOTOKAZE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00022: Normal(Talk, TargetCanMove), id=KARAKU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00025: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00026( player );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling [BranchTrue]Scene00026: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling [BranchFalse]Scene00027: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00028: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00029( player );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling [BranchTrue]Scene00029: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling [BranchFalse]Scene00030: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00031: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00032( player );
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling [BranchTrue]Scene00032: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling [BranchFalse]Scene00033: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00034: Normal(Talk, TargetCanMove), id=KOTOKAZE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00038: Normal(Talk, TargetCanMove), id=KUGANEFERRYMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00039: Normal(Talk, TargetCanMove), id=KUGANECAPTAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00040: Normal(Talk, TargetCanMove), id=RADZATHANMERCHANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda204:68009 calling Scene00041: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda204 );
