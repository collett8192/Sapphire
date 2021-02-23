// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb116 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb116() : Sapphire::ScriptAPI::EventScript( 68853 ){}; 
  ~LucKmb116() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 4 entries
  //SEQ_3, 5 entries
  //SEQ_4, 6 entries
  //SEQ_5, 7 entries
  //SEQ_255, 7 entries

  //ACTIONTIMELINEEVENTBASESLEEP = 805
  //ACTIONTIMELINEEVENTLAUGH = 952
  //ACTOR0 = 1027672
  //ACTOR1 = 1027666
  //ACTOR10 = 1027692
  //ACTOR2 = 1029580
  //ACTOR3 = 1027693
  //ACTOR4 = 1027701
  //ACTOR5 = 1027691
  //ACTOR6 = 1027690
  //ACTOR7 = 1029577
  //ACTOR8 = 1029578
  //ACTOR9 = 1029579
  //BGMEX3FIELDLONELYVILLAGE01 = 676
  //EMOTE0 = 105
  //LCUTACTOR0 = 1026570
  //LCUTACTOR1 = 1026569
  //LCUTACTOR2 = 1026572
  //LCUTACTOR3 = 1028110
  //LCUTACTOR4 = 1028138
  //LCUTPOS0 = 7924118
  //LCUTPOS1 = 7924093
  //LOCACT01 = 5627
  //LOCACT02 = 4236
  //LOCMOTIONFEODEPOP = 4231
  //LOCMOTIONFEOHIDE = 1078
  //LOCMOTIONFEOPOP = 4230
  //POPRANGE0 = 8050071

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1027672 || param2 == 1027672 ) // ACTOR0 = WYDLAD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=WYDLAD
          break;
        }
        if( param1 == 1027666 || param2 == 1027666 ) // ACTOR1 = WYDAENC
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=WYDAENC
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1027666 || param2 == 1027666 ) // ACTOR1 = WYDAENC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=WYDAENC
            // +Callback Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=WYDAENC
          }
          break;
        }
        if( param1 == 1027672 || param2 == 1027672 ) // ACTOR0 = WYDLAD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=WYDLAD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029580 || param2 == 1029580 ) // ACTOR2 = SETO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove, Menu, SystemTalk, CanCancel), id=SETO
            // +Callback Scene00007: Normal(Talk, FadeIn, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1027693 || param2 == 1027693 ) // ACTOR3 = NIMBUS
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=NIMBUS
          break;
        }
        if( param1 == 1027701 || param2 == 1027701 ) // ACTOR4 = TRAVELLER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=TRAVELLER
          break;
        }
        if( param1 == 1027666 || param2 == 1027666 ) // ACTOR1 = WYDAENC
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=WYDAENC
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1027691 || param2 == 1027691 ) // ACTOR5 = RISPA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RISPA
            // +Callback Scene00012: Normal(Talk, TargetCanMove), id=RISPA
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=RISPA
          }
          break;
        }
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR6 = SETO
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SETO
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR7 = URIANGER
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029578 || param2 == 1029578 ) // ACTOR8 = THANCRED
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029579 || param2 == 1029579 ) // ACTOR9 = RYNE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1027692 || param2 == 1027692 ) // ACTOR10 = EOAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=EOAN
            // +Callback Scene00019: Normal(Talk, TargetCanMove), id=EOAN
            // +Callback Scene00020: Normal(Talk, TargetCanMove), id=EOAN
          }
          break;
        }
        if( param1 == 1027691 || param2 == 1027691 ) // ACTOR5 = RISPA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=RISPA
          break;
        }
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR6 = SETO
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=SETO
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR7 = URIANGER
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029578 || param2 == 1029578 ) // ACTOR8 = THANCRED
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029579 || param2 == 1029579 ) // ACTOR9 = RYNE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1027693 || param2 == 1027693 ) // ACTOR3 = NIMBUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=NIMBUS
            // +Callback Scene00027: Normal(Talk, TargetCanMove), id=NIMBUS
            // +Callback Scene00028: Normal(Talk, TargetCanMove), id=NIMBUS
          }
          break;
        }
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR6 = SETO
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=SETO
          break;
        }
        if( param1 == 1027691 || param2 == 1027691 ) // ACTOR5 = RISPA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=RISPA
          break;
        }
        if( param1 == 1027692 || param2 == 1027692 ) // ACTOR10 = EOAN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=EOAN
          break;
        }
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR7 = URIANGER
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029578 || param2 == 1029578 ) // ACTOR8 = THANCRED
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029579 || param2 == 1029579 ) // ACTOR9 = RYNE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029577 || param2 == 1029577 ) // ACTOR7 = URIANGER
        {
          Scene00035( player ); // Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029578 || param2 == 1029578 ) // ACTOR8 = THANCRED
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029579 || param2 == 1029579 ) // ACTOR9 = RYNE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1027690 || param2 == 1027690 ) // ACTOR6 = SETO
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=SETO
          break;
        }
        if( param1 == 1027691 || param2 == 1027691 ) // ACTOR5 = RISPA
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=RISPA
          break;
        }
        if( param1 == 1027692 || param2 == 1027692 ) // ACTOR10 = EOAN
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=EOAN
          break;
        }
        if( param1 == 1027693 || param2 == 1027693 ) // ACTOR3 = NIMBUS
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=NIMBUS
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmb116:68853 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=WYDLAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00002: Normal(Talk, TargetCanMove), id=WYDAENC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00003: Normal(Talk, TargetCanMove), id=WYDAENC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=WYDAENC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00005: Normal(Talk, TargetCanMove), id=WYDLAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00006: Normal(Talk, TargetCanMove, Menu, SystemTalk, CanCancel), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00007: Normal(Talk, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00008: Normal(Talk, TargetCanMove), id=NIMBUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00009: Normal(Talk, TargetCanMove), id=TRAVELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00010: Normal(Talk, TargetCanMove), id=WYDAENC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00011: Normal(Talk, TargetCanMove), id=RISPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00012: Normal(Talk, TargetCanMove), id=RISPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00013: Normal(Talk, TargetCanMove), id=RISPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00014: Normal(Talk, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00015: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00016: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00017: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00018: Normal(Talk, TargetCanMove), id=EOAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00019: Normal(Talk, TargetCanMove), id=EOAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00020: Normal(Talk, TargetCanMove), id=EOAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00021: Normal(Talk, TargetCanMove), id=RISPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00022: Normal(Talk, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00023: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00024: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00025: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00026: Normal(Talk, TargetCanMove), id=NIMBUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00027( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00027: Normal(Talk, TargetCanMove), id=NIMBUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00028( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00028: Normal(Talk, TargetCanMove), id=NIMBUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00029: Normal(Talk, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00030: Normal(Talk, TargetCanMove), id=RISPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00031: Normal(Talk, TargetCanMove), id=EOAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00032: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00033: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00034: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER" );
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
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00036: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00037: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00038: Normal(Talk, TargetCanMove), id=SETO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00039: Normal(Talk, TargetCanMove), id=RISPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00040: Normal(Talk, TargetCanMove), id=EOAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmb116:68853 calling Scene00041: Normal(Talk, TargetCanMove), id=NIMBUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb116 );
