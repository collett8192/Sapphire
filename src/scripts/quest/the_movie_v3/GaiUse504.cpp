// FFXIVTheMovie.ParserV3.6
// id hint used:
//SCENE_19 = dummyr0
//SCENE_20 = dummyr0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse504 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse504() : Sapphire::ScriptAPI::EventScript( 65902 ){}; 
  ~GaiUse504() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 5 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 1 entries
  //SEQ_5, 4 entries
  //SEQ_6, 6 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1010891
  //ACTOR1 = 1010855
  //ACTOR10 = 1010856
  //ACTOR11 = 1010858
  //ACTOR2 = 1011122
  //ACTOR3 = 1011123
  //ACTOR4 = 1008969
  //ACTOR5 = 1010854
  //ACTOR6 = 1010881
  //ACTOR7 = 5010000
  //ACTOR8 = 1010857
  //ACTOR9 = 1011124
  //COMPANION0 = 119
  //CUTSCENEN01 = 695
  //CUTSCENEN02 = 697
  //CUTSCENEN03 = 698
  //CUTSCENEN04 = 699
  //INSTANCEDUNGEON0 = 32
  //LOCACTOR0 = 4725177
  //LOCACTOR1 = 5578843
  //LOCACTOR2 = 5578845
  //LOCACTOR3 = 5578846
  //LOCACTOR4 = 5578574
  //LOCEOBJECT0 = 2005157
  //LOCMOTION0 = 731
  //LOCMOTION1 = 707
  //LOCMOTION2 = 719
  //POPRANGE0 = 5582034
  //POPRANGE1 = 5589530
  //TERRITORYTYPE0 = 156
  //UNLOCKDUNGEONTOWEROFSECRET = 266

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1010891 || param2 == 1010891 ) // ACTOR0 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=TATARU
          }
          break;
        }
        if( param1 == 1010855 || param2 == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1011122 || param2 == 1011122 ) // ACTOR2 = MOENBRYDA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MOENBRYDA
          break;
        }
        if( param1 == 1011123 || param2 == 1011123 ) // ACTOR3 = URIANGER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1010855 || param2 == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=unknown
          // +Callback Scene00007: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1011122 || param2 == 1011122 ) // ACTOR2 = MOENBRYDA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MOENBRYDA
          break;
        }
        if( param1 == 1011123 || param2 == 1011123 ) // ACTOR3 = URIANGER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1010854 || param2 == 1010854 ) // ACTOR5 = TATARU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1010881 || param2 == 1010881 ) // ACTOR6 = DOMANPEOPLE00366
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, Message, FadeIn, TargetCanMove), id=DOMANPEOPLE00366
          }
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1010855 || param2 == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1010891 || param2 == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1010855 || param2 == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1010891 || param2 == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1010881 || param2 == 1010881 ) // ACTOR6 = DOMANPEOPLE00366
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = dummyr0
        {
          Scene00019( player ); // Scene00019: Normal(CutScene, AutoFadeIn), id=dummyr0
          // +Callback Scene00020: Normal(FadeIn, SystemTalk), id=dummyr0
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1010881 || param2 == 1010881 ) // ACTOR6 = DOMANPEOPLE00366
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366
          }
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1010855 || param2 == 1010855 ) // ACTOR1 = LUCIA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1010891 || param2 == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1010857 || param2 == 1010857 ) // ACTOR8 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00026: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1010891 || param2 == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1011124 || param2 == 1011124 ) // ACTOR9 = URIANGER
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1010856 || param2 == 1010856 ) // ACTOR10 = LUCIA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1010881 || param2 == 1010881 ) // ACTOR6 = DOMANPEOPLE00366
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1010858 || param2 == 1010858 ) // ACTOR11 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1008969 || param2 == 1008969 ) // ACTOR4 = MINFILIA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1010891 || param2 == 1010891 ) // ACTOR0 = TATARU
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=TATARU
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
    player.sendDebug( "emote: {}", emoteId );
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
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00002: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00003: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00005: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00007: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00008: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00009: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00011: Normal(Talk, Message, FadeIn, TargetCanMove), id=DOMANPEOPLE00366" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00012: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00013: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00014: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00015: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00016: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00017: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00018: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00019: Normal(CutScene, AutoFadeIn), id=dummyr0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00020( Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00020: Normal(FadeIn, SystemTalk), id=dummyr0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_5: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00021: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_5: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00022: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_5: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00023: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_5: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00024: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_6: ACTOR8, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00026( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player ) //SEQ_6: ACTOR8, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00026: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq6( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_6: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00027: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_6: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00028: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player ) //SEQ_6: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00029: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_6: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00030: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_6: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00031: Normal(Talk, TargetCanMove), id=DOMANPEOPLE00366" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00033: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse504:65902 calling Scene00034: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse504 );
