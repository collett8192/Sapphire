// FFXIVTheMovie.ParserV3.6
// id hint used:
//SCENE_3 = URIANGER
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse118 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse118() : Sapphire::ScriptAPI::EventScript( 66728 ){}; 
  ~GaiUse118() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 8 entries
  //SEQ_4, 6 entries
  //SEQ_5, 7 entries
  //SEQ_6, 10 entries
  //SEQ_7, 4 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTTALKBIG = 950
  //ACTOR0 = 1006693
  //ACTOR1 = 1007478
  //ACTOR2 = 1007750
  //ACTOR3 = 1003785
  //ACTOR4 = 1007751
  //BGMNOTHING = 1
  //CUTSCENEN01 = 437
  //CUTSCENEN02 = 438
  //CUTSCENEN03 = 439
  //CUTSCENEN04 = 440
  //ENEMY0 = 4502922
  //ENEMY1 = 4502923
  //ENEMY2 = 4502924
  //ENEMY3 = 4502925
  //ENEMY4 = 4502927
  //ENEMY5 = 4502928
  //ENEMY6 = 4502929
  //ENEMY7 = 4502930
  //ENEMY8 = 4502931
  //ENEMY9 = 4502932
  //EOBJECT0 = 2002858
  //EOBJECT1 = 2002859
  //EOBJECT2 = 2002860
  //EOBJECT3 = 2002861
  //EVENTRANGE0 = 4502916
  //EVENTRANGE1 = 4502918
  //EVENTRANGE2 = 4502919
  //EVENTRANGE3 = 4502920
  //EVENTRANGE4 = 4502921
  //LOCACTOR0 = 1007769
  //LOCBGM0 = 94
  //LOCFACE0 = 617
  //LOCPOSACTOR0 = 4540187
  //LOCPOSACTOR1 = 4540190
  //POPRANGE0 = 4512284

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=URIANGER
        // +Callback Scene00003: Normal(CutScene, AutoFadeIn), id=URIANGER
        break;
      }
      case 2:
      {
        if( param1 == 4502916 || param2 == 4502916 ) // EVENTRANGE0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, Dismount), id=unknown
          break;
        }
        if( param1 == 1007750 || param2 == 1007750 ) // ACTOR2 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006693 || param2 == 1006693 ) // ACTOR0 = MINFILIA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR1 = URIANGER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1003785 || param2 == 1003785 ) // ACTOR3 = TATARU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 4502918 || param2 == 4502918 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4502922 || param2 == 4502922 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4502923 || param2 == 4502923 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4502924 || param2 == 4502924 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002858 || param2 == 2002858 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006693 || param2 == 1006693 ) // ACTOR0 = MINFILIA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR1 = URIANGER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1003785 || param2 == 1003785 ) // ACTOR3 = TATARU
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 4502919 || param2 == 4502919 ) // EVENTRANGE2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4502925 || param2 == 4502925 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002859 || param2 == 2002859 ) // EOBJECT1 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006693 || param2 == 1006693 ) // ACTOR0 = MINFILIA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR1 = URIANGER
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1003785 || param2 == 1003785 ) // ACTOR3 = TATARU
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 4502920 || param2 == 4502920 ) // EVENTRANGE3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00019( player ); // Scene00019: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4502927 || param2 == 4502927 ) // ENEMY4 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4502928 || param2 == 4502928 ) // ENEMY5 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002860 || param2 == 2002860 ) // EOBJECT2 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006693 || param2 == 1006693 ) // ACTOR0 = MINFILIA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR1 = URIANGER
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1003785 || param2 == 1003785 ) // ACTOR3 = TATARU
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 4502921 || param2 == 4502921 ) // EVENTRANGE4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00024( player ); // Scene00024: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4502929 || param2 == 4502929 ) // ENEMY6 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4502930 || param2 == 4502930 ) // ENEMY7 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4502931 || param2 == 4502931 ) // ENEMY8 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4502932 || param2 == 4502932 ) // ENEMY9 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002861 || param2 == 2002861 ) // EOBJECT3 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007751 || param2 == 1007751 ) // ACTOR4 = ELIDIBUSEORZEA
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ELIDIBUSEORZEA
          break;
        }
        if( param1 == 1006693 || param2 == 1006693 ) // ACTOR0 = MINFILIA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR1 = URIANGER
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1003785 || param2 == 1003785 ) // ACTOR3 = TATARU
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1007751 || param2 == 1007751 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00030( player ); // Scene00030: Normal(CutScene, NpcDespawn, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1006693 || param2 == 1006693 ) // ACTOR0 = MINFILIA
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR1 = URIANGER
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1003785 || param2 == 1003785 ) // ACTOR3 = TATARU
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006693 || param2 == 1006693 ) // ACTOR0 = MINFILIA
        {
          Scene00034( player ); // Scene00034: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA
          break;
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR1 = URIANGER
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1003785 || param2 == 1003785 ) // ACTOR3 = TATARU
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=TATARU
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestBitFlag8( getId(), 1, false );
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00002: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00003: Normal(CutScene, AutoFadeIn), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: EVENTRANGE0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00004: Normal(Talk, FadeIn, Dismount), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00006: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00007: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00008: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: EVENTRANGE1, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }




  void Scene00010( Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00011: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00012: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00013: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_4: EVENTRANGE2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }


  void Scene00015( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00016( Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00016: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_4: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00017: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00018: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_5: EVENTRANGE3, UI8AL = 2, Flag8(1)=True
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00019: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }



  void Scene00020( Entity::Player& player ) //SEQ_5: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00021( Entity::Player& player ) //SEQ_5: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00021: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_5: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00022: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00023: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_6: EVENTRANGE4, UI8AL = 4, Flag8(1)=True
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }





  void Scene00025( Entity::Player& player ) //SEQ_6: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00026( Entity::Player& player ) //SEQ_6: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00026: Normal(Talk, TargetCanMove), id=ELIDIBUSEORZEA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_6: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00027: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_6: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00028: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player ) //SEQ_6: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00029: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_7: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00030: Normal(CutScene, NpcDespawn, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_7: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00031: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_7: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00032: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_7: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00033: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00034: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA" );
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
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00035: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse118:66728 calling Scene00036: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse118 );
