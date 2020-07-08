// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnc101 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnc101() : Sapphire::ScriptAPI::EventScript( 67767 ){}; 
  ~HeaVnc101() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 15 entries
  //SEQ_255, 15 entries

  //ACTOR0 = 1012580
  //ACTOR1 = 1013227
  //ACTOR10 = 1016541
  //ACTOR11 = 1016538
  //ACTOR12 = 1016542
  //ACTOR13 = 1016543
  //ACTOR14 = 1016540
  //ACTOR15 = 1016534
  //ACTOR16 = 1016535
  //ACTOR17 = 1016536
  //ACTOR18 = 1016537
  //ACTOR19 = 1016539
  //ACTOR2 = 1016531
  //ACTOR20 = 1016553
  //ACTOR21 = 1016554
  //ACTOR22 = 1016555
  //ACTOR23 = 1016556
  //ACTOR24 = 1016557
  //ACTOR3 = 1016532
  //ACTOR4 = 1016533
  //ACTOR5 = 1012692
  //ACTOR6 = 1012693
  //ACTOR7 = 1010388
  //ACTOR8 = 1010389
  //ACTOR9 = 1010390
  //CUTSCENEN01 = 1140
  //LOCACTOR0 = 6184280
  //LOCACTOR1 = 6184281
  //LOCACTOR10 = 6203498
  //LOCACTOR11 = 6203499
  //LOCACTOR12 = 6184224
  //LOCACTOR13 = 6184233
  //LOCACTOR14 = 6184253
  //LOCACTOR2 = 6184283
  //LOCACTOR20 = 6239638
  //LOCACTOR21 = 6239639
  //LOCACTOR3 = 6184246
  //LOCACTOR4 = 6184225
  //LOCACTOR5 = 1015842
  //LOCACTOR6 = 1015833
  //LOCACTOR7 = 5865011

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012580 || param2 == 1012580 ) // ACTOR0 = TATARU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=TATARU
        }
        if( param1 == 1013227 || param2 == 1013227 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016531 || param2 == 1016531 ) // ACTOR2 = FLHAMINN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=FLHAMINN
            // +Callback Scene00004: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1016532 || param2 == 1016532 ) // ACTOR3 = HOARYBOULDER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HOARYBOULDER
        }
        if( param1 == 1016533 || param2 == 1016533 ) // ACTOR4 = COULTENET
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=COULTENET
        }
        if( param1 == 1012692 || param2 == 1012692 ) // ACTOR5 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1012693 || param2 == 1012693 ) // ACTOR6 = TATARU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 2:
      {
        if( param1 == 1010388 || param2 == 1010388 ) // ACTOR7 = FLHAMINN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=FLHAMINN
          }
        }
        if( param1 == 1010389 || param2 == 1010389 ) // ACTOR8 = HOARYBOULDER
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HOARYBOULDER
        }
        if( param1 == 1010390 || param2 == 1010390 ) // ACTOR9 = COULTENET
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=COULTENET
        }
        if( param1 == 1012692 || param2 == 1012692 ) // ACTOR5 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1012693 || param2 == 1012693 ) // ACTOR6 = TATARU
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016541 || param2 == 1016541 ) // ACTOR10 = FLHAMINN
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=unknown
            // +Callback Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN
          }
        }
        if( param1 == 1016538 || param2 == 1016538 ) // ACTOR11 = AERGMHUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk), id=AERGMHUS
            // +Callback Scene00017: Normal(Talk), id=AERGMHUS
          }
        }
        if( param1 == 1016542 || param2 == 1016542 ) // ACTOR12 = HOARYBOULDER
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk), id=unknown
            // +Callback Scene00019: Normal(Talk), id=HOARYBOULDER
          }
        }
        if( param1 == 1016543 || param2 == 1016543 ) // ACTOR13 = COULTENET
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=COULTENET
            // +Callback Scene00021: Normal(Talk, TargetCanMove), id=COULTENET
          }
        }
        if( param1 == 1016540 || param2 == 1016540 ) // ACTOR14 = HOUMEI
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=HOUMEI
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=HOUMEI
          }
        }
        if( param1 == 1016534 || param2 == 1016534 ) // ACTOR15 = ALPHINAUD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016535 || param2 == 1016535 ) // ACTOR16 = TATARU
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1016536 || param2 == 1016536 ) // ACTOR17 = ALIANNE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( param1 == 1016537 || param2 == 1016537 ) // ACTOR18 = EPHEMIE
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=EPHEMIE
        }
        if( param1 == 1016539 || param2 == 1016539 ) // ACTOR19 = ISILDAURE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ISILDAURE
        }
        if( param1 == 1016553 || param2 == 1016553 ) // ACTOR20 = BLUOMWYDA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=BLUOMWYDA
        }
        if( param1 == 1016554 || param2 == 1016554 ) // ACTOR21 = OCHERBOULDER
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=OCHERBOULDER
        }
        if( param1 == 1016555 || param2 == 1016555 ) // ACTOR22 = VMAHTIA
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=VMAHTIA
        }
        if( param1 == 1016556 || param2 == 1016556 ) // ACTOR23 = AENOR
        {
          Scene00032( player ); // Scene00032: Normal(Talk), id=AENOR
        }
        if( param1 == 1016557 || param2 == 1016557 ) // ACTOR24 = CLEMENCE
        {
          Scene00033( player ); // Scene00033: Normal(Talk), id=CLEMENCE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016535 || param2 == 1016535 ) // ACTOR16 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown
        }
        if( param1 == 1016534 || param2 == 1016534 ) // ACTOR15 = ALPHINAUD
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016536 || param2 == 1016536 ) // ACTOR17 = ALIANNE
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( param1 == 1016537 || param2 == 1016537 ) // ACTOR18 = EPHEMIE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=EPHEMIE
        }
        if( param1 == 1016538 || param2 == 1016538 ) // ACTOR11 = AERGMHUS
        {
          Scene00038( player ); // Scene00038: Normal(Talk), id=AERGMHUS
        }
        if( param1 == 1016539 || param2 == 1016539 ) // ACTOR19 = ISILDAURE
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=ISILDAURE
        }
        if( param1 == 1016540 || param2 == 1016540 ) // ACTOR14 = HOUMEI
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=HOUMEI
        }
        if( param1 == 1016541 || param2 == 1016541 ) // ACTOR10 = FLHAMINN
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=FLHAMINN
        }
        if( param1 == 1016542 || param2 == 1016542 ) // ACTOR12 = HOARYBOULDER
        {
          Scene00042( player ); // Scene00042: Normal(Talk), id=HOARYBOULDER
        }
        if( param1 == 1016543 || param2 == 1016543 ) // ACTOR13 = COULTENET
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=COULTENET
        }
        if( param1 == 1016553 || param2 == 1016553 ) // ACTOR20 = BLUOMWYDA
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=BLUOMWYDA
        }
        if( param1 == 1016554 || param2 == 1016554 ) // ACTOR21 = OCHERBOULDER
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=OCHERBOULDER
        }
        if( param1 == 1016555 || param2 == 1016555 ) // ACTOR22 = VMAHTIA
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=VMAHTIA
        }
        if( param1 == 1016556 || param2 == 1016556 ) // ACTOR23 = AENOR
        {
          Scene00047( player ); // Scene00047: Normal(Talk), id=AENOR
        }
        if( param1 == 1016557 || param2 == 1016557 ) // ACTOR24 = CLEMENCE
        {
          Scene00048( player ); // Scene00048: Normal(Talk), id=CLEMENCE
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
    if( player.getQuestUI8CL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
          if( player.getQuestUI8BL( getId() ) == 1 )
            if( player.getQuestUI8CH( getId() ) == 1 )
            {
              player.setQuestUI8CL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8BH( getId(), 0 );
              player.setQuestUI8BL( getId(), 0 );
              player.setQuestUI8CH( getId(), 0 );
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnc101:67767 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling [BranchTrue]Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00005: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00006: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00008: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00009: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00010: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00011: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00013: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00014: Normal(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling [BranchTrue]Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00016: Normal(Talk), id=AERGMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling [BranchTrue]Scene00017: Normal(Talk), id=AERGMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00018: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling [BranchTrue]Scene00019: Normal(Talk), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00020: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling [BranchTrue]Scene00021: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00022: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling [BranchTrue]Scene00023: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00025: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00026: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00027: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00028: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00029: Normal(Talk, TargetCanMove), id=BLUOMWYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00030: Normal(Talk, TargetCanMove), id=OCHERBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00031: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00032: Normal(Talk), id=AENOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00033: Normal(Talk), id=CLEMENCE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00034: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00036: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00037: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00038: Normal(Talk), id=AERGMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00039: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00040: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00041: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00042: Normal(Talk), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00043: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00044: Normal(Talk, TargetCanMove), id=BLUOMWYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00045: Normal(Talk, TargetCanMove), id=OCHERBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00046: Normal(Talk, TargetCanMove), id=VMAHTIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00047: Normal(Talk), id=AENOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "HeaVnc101:67767 calling Scene00048: Normal(Talk), id=CLEMENCE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnc101 );
