// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmh110 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmh110() : Sapphire::ScriptAPI::EventScript( 69306 ){}; 
  ~LucKmh110() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 9 entries
  //SEQ_4, 7 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1032539
  //ACTOR1 = 1032540
  //ACTOR10 = 1032558
  //ACTOR11 = 1031722
  //ACTOR12 = 1031723
  //ACTOR13 = 1032556
  //ACTOR14 = 1031724
  //ACTOR15 = 1032557
  //ACTOR16 = 1032122
  //ACTOR17 = 1032121
  //ACTOR18 = 1032712
  //ACTOR19 = 1030610
  //ACTOR2 = 1032541
  //ACTOR3 = 1032542
  //ACTOR4 = 1032544
  //ACTOR5 = 1032529
  //ACTOR6 = 1032551
  //ACTOR7 = 1032552
  //ACTOR8 = 1032530
  //ACTOR9 = 1032553
  //CUT16CHKQSTLUCKBA151 = 68784
  //CUT16CHKQSTLUCKBA251 = 68808
  //CUT16CHKQSTLUCKBA351 = 68814
  //CUT16CHKQSTLUCKBA451 = 69164
  //CUT16CHKQSTLUCKBZ001 = 69165
  //LOCACTORALISAIE = 1026567
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORBEQLUGG = 1029471
  //LOCACTORMYSTERYVOICE = 1028166
  //LOCACTORRYNE = 1027137
  //LOCACTORTHANCRED = 1026569
  //LOCACTORURIANGER = 1026570
  //LOCBINDALISAIE = 8260755
  //LOCBINDALPHINAUD = 8260754
  //LOCBINDMYSTERYVOICE = 8147080
  //LOCBINDRYNE = 8260758
  //LOCBINDSOLDIER01 = 8262629
  //LOCBINDSOLDIER02 = 8263405
  //LOCBINDTHANCRED = 8260756
  //NCUTLUCKMH00150 = 2246
  //NCUTLUCKMH00160 = 2228
  //NCUTLUCKMH00170 = 2247
  //NCUTLUCKMH00180 = 2248
  //NCUTLUCKMH00190 = 2249
  //POPRANGE0 = 8260799
  //POPRANGE1 = 8011405
  //QUESTLUCKRA206 = 69328
  //TERRITORYTYPE0 = 819

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1032539 || param2 == 1032539 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032540 || param2 == 1032540 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032541 || param2 == 1032541 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032542 || param2 == 1032542 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032544 || param2 == 1032544 ) // ACTOR4 = RYNE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00006( player ); // Scene00006: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1032529 || param2 == 1032529 ) // ACTOR5 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00008: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1032551 || param2 == 1032551 ) // ACTOR6 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032552 || param2 == 1032552 ) // ACTOR7 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032530 || param2 == 1032530 ) // ACTOR8 = URIANGER
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032553 || param2 == 1032553 ) // ACTOR9 = RYNE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1032558 || param2 == 1032558 ) // ACTOR10 = SOLDIER03608
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=SOLDIER03608
            // +Callback Scene00014: Normal(Talk, FadeIn, TargetCanMove), id=SOLDIER03608
          }
          break;
        }
        if( param1 == 1031722 || param2 == 1031722 ) // ACTOR11 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031723 || param2 == 1031723 ) // ACTOR12 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032556 || param2 == 1032556 ) // ACTOR13 = THANCRED
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR14 = URIANGER
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032557 || param2 == 1032557 ) // ACTOR15 = RYNE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR16 = BEQLUGG
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR17 = MYSTERYVOICE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1032712 || param2 == 1032712 ) // ACTOR18 = BRAVESOLDIER
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=BRAVESOLDIER
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR17 = MYSTERYVOICE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
            // +Callback Scene00024: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1031722 || param2 == 1031722 ) // ACTOR11 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031723 || param2 == 1031723 ) // ACTOR12 = ALISAIE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032556 || param2 == 1032556 ) // ACTOR13 = THANCRED
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR14 = URIANGER
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032557 || param2 == 1032557 ) // ACTOR15 = RYNE
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR16 = BEQLUGG
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030610 || param2 == 1030610 ) // ACTOR19 = GUIDEOFTHEPENDANTS
        {
          Scene00031( player ); // Scene00031: Normal(Talk, YesNo, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn, SystemTalk, CanCancel), id=GUIDEOFTHEPENDANTS
          // +Callback Scene00032: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR17 = MYSTERYVOICE
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1031722 || param2 == 1031722 ) // ACTOR11 = ALPHINAUD
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031723 || param2 == 1031723 ) // ACTOR12 = ALISAIE
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032556 || param2 == 1032556 ) // ACTOR13 = THANCRED
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR14 = URIANGER
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032557 || param2 == 1032557 ) // ACTOR15 = RYNE
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR16 = BEQLUGG
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=BEQLUGG
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
    player.updateQuest( getId(), 2 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmh110:69306 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00005: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00006: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00008: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00011: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00012: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00013: Normal(Talk, TargetCanMove), id=SOLDIER03608" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00014: Normal(Talk, FadeIn, TargetCanMove), id=SOLDIER03608" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00017: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00018: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00019: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00020: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00021: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00022: Normal(Talk, TargetCanMove), id=BRAVESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00023: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00024: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00027: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00028: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00029: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00030: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00031: Normal(Talk, YesNo, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn, SystemTalk, CanCancel), id=GUIDEOFTHEPENDANTS" );
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
    player.sendDebug( "LucKmh110:69306 calling Scene00032: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00033: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00035: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00036: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00037: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00038: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmh110:69306 calling Scene00039: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmh110 );
