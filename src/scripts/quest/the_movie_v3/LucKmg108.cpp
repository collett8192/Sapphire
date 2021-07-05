// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmg108 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmg108() : Sapphire::ScriptAPI::EventScript( 69216 ){}; 
  ~LucKmg108() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 7 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1031760
  //ACTOR1 = 1031757
  //ACTOR10 = 1031767
  //ACTOR11 = 1031768
  //ACTOR12 = 1031798
  //ACTOR13 = 1031799
  //ACTOR14 = 1031800
  //ACTOR15 = 1031769
  //ACTOR16 = 1031770
  //ACTOR17 = 1031771
  //ACTOR18 = 1031772
  //ACTOR19 = 1031773
  //ACTOR2 = 1031758
  //ACTOR20 = 1031774
  //ACTOR21 = 1031775
  //ACTOR22 = 1031776
  //ACTOR23 = 1032262
  //ACTOR24 = 1032265
  //ACTOR25 = 1032271
  //ACTOR3 = 1031759
  //ACTOR4 = 1031761
  //ACTOR5 = 1031762
  //ACTOR6 = 1031763
  //ACTOR7 = 1031764
  //ACTOR8 = 1031765
  //ACTOR9 = 1031766
  //CUTSCENE0 = 2192
  //EOBJECT0 = 2010812
  //EOBJECT1 = 2010813
  //LOCACTIONAUTOATTACK1MONA = 121
  //LOCACTIONBATTLEDEAD = 72
  //LOCACTIONEMOTESPTHROWSNOWNOVFX = 641
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORCHAINUZZ = 1028120
  //LOCACTORKAISHIRR = 1028121
  //LOCACTORMON01 = 1029531
  //LOCACTORMON02 = 1029532
  //LOCACTORTALOS = 1028844
  //LOCACTORWRENDEN = 1029472
  //LOCBINDACTOR0 = 8132813
  //LOCBINDACTOR1 = 8132836
  //LOCBINDACTOR2 = 8132838
  //LOCMUSICSYSFANFARESHORT01 = 20
  //LOCPOSLCUT3START = 8203027
  //LOCSEPOSTINGITEM = 217
  //LOCVFXGENBUHENSIN = 598
  //POPRANGE0 = 8171175
  //POPRANGE1 = 8136669
  //SNP0 = 39
  //SNP1 = 45

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1031760 || param2 == 1031760 ) // ACTOR0 = CHAINUZZ
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1031757 || param2 == 1031757 ) // ACTOR1 = WRENDEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=WRENDEN
          break;
        }
        if( param1 == 1031758 || param2 == 1031758 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031759 || param2 == 1031759 ) // ACTOR3 = KAISHIRR
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1031761 || param2 == 1031761 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, Menu, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1031762 || param2 == 1031762 ) // ACTOR5 = WRENDEN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=WRENDEN
          break;
        }
        if( param1 == 1031763 || param2 == 1031763 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031764 || param2 == 1031764 ) // ACTOR7 = KAISHIRR
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 2010812 || param2 == 2010812 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(SystemTalk), id=unknown
          // +Callback Scene00011: Snipe(AutoFadeIn, CanCancel), id=unknown
          // +Callback Scene00012: Normal(Talk, FadeIn), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2010813 || param2 == 2010813 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00014: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1031765 || param2 == 1031765 ) // ACTOR8 = CHAINUZZ
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1031766 || param2 == 1031766 ) // ACTOR9 = WRENDEN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=WRENDEN
          break;
        }
        if( param1 == 1031767 || param2 == 1031767 ) // ACTOR10 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031768 || param2 == 1031768 ) // ACTOR11 = KAISHIRR
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 2010812 || param2 == 2010812 ) // EOBJECT0 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1031765 || param2 == 1031765 ) // ACTOR8 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, FadeIn, AutoFadeIn), id=unknown
            // +Callback Scene00021: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1031766 || param2 == 1031766 ) // ACTOR9 = WRENDEN
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=WRENDEN
          break;
        }
        if( param1 == 1031767 || param2 == 1031767 ) // ACTOR10 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031768 || param2 == 1031768 ) // ACTOR11 = KAISHIRR
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1031798 || param2 == 1031798 ) // ACTOR12 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031799 || param2 == 1031799 ) // ACTOR13 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031800 || param2 == 1031800 ) // ACTOR14 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1031769 || param2 == 1031769 ) // ACTOR15 = WRENDEN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WRENDEN
          break;
        }
        if( param1 == 1031770 || param2 == 1031770 ) // ACTOR16 = CHAINUZZ
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1031771 || param2 == 1031771 ) // ACTOR17 = ALPHINAUD
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031772 || param2 == 1031772 ) // ACTOR18 = KAISHIRR
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1031773 || param2 == 1031773 ) // ACTOR19 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031774 || param2 == 1031774 ) // ACTOR20 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031775 || param2 == 1031775 ) // ACTOR21 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031776 || param2 == 1031776 ) // ACTOR22 = DULIACHAI
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1032262 || param2 == 1032262 ) // ACTOR23 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032265 || param2 == 1032265 ) // ACTOR24 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032271 || param2 == 1032271 ) // ACTOR25 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmg108:69216 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00002: Normal(Talk, TargetCanMove), id=WRENDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00004: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00005: Normal(Talk, FadeIn, Menu, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
        player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        player.eventFinish( getId(), 1 );
        player.forceZoneing();
      }
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00006: Normal(Talk, TargetCanMove), id=WRENDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00008: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00010: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00011: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00012( player );
      }
    };
    player.playScene( getId(), 11, INVIS_ENPC, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00012: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00013: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, INVIS_ENPC, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00014: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00015: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00016: Normal(Talk, TargetCanMove), id=WRENDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00018: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00020: Normal(Talk, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00021: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00022: Normal(Talk, TargetCanMove), id=WRENDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00024: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WRENDEN" );
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
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00029: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00031: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00035: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmg108:69216 calling Scene00038: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKmg108 );
