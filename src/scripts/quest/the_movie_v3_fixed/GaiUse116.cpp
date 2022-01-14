// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse116 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse116() : Sapphire::ScriptAPI::EventScript( 66726 ){}; 
  ~GaiUse116() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 2 entries
  //SEQ_4, 23 entries
  //SEQ_5, 2 entries
  //SEQ_6, 3 entries
  //SEQ_7, 2 entries
  //SEQ_8, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000692
  //ACTOR1 = 1008275
  //ACTOR2 = 1008279
  //ACTOR3 = 1008280
  //ACTOR4 = 1008281
  //ACTOR5 = 1008318
  //ACTOR6 = 1008276
  //ACTOR7 = 1008277
  //ACTOR9 = 1007862
  //BNPCNAME0 = 2358
  //ENEMY0 = 4515258
  //ENEMY1 = 4515416
  //ENEMY10 = 4515586
  //ENEMY11 = 4515582
  //ENEMY12 = 4515580
  //ENEMY13 = 4515581
  //ENEMY2 = 4515569
  //ENEMY3 = 4515570
  //ENEMY4 = 4515571
  //ENEMY5 = 4515572
  //ENEMY6 = 4515578
  //ENEMY7 = 4515579
  //ENEMY8 = 4515587
  //ENEMY9 = 4515588
  //EOBJECT0 = 2003347
  //EOBJECT1 = 2003057
  //EOBJECT2 = 2003046
  //EVENTRANGE0 = 4500856
  //EVENTRANGE1 = 4500863
  //EVENTRANGE2 = 4500869
  //EVENTRANGE3 = 4500872
  //EVENTRANGE4 = 4500873
  //EVENTRANGE5 = 4500875
  //EVENTRANGE6 = 4500877
  //EVENTACTIONSYMPATHY = 19
  //INSTANCEDUNGEON0 = 20011
  //LOCACTOR0 = 1008362
  //LOCACTOR1 = 1005771
  //LOCACTOR2 = 1005772
  //LOCACTOR3 = 1005773
  //LOCEOBJ0 = 2003434
  //LOCMOTION1 = 938
  //LOCMOTION2 = 945
  //LOCPOSACTOR1000 = 8450755
  //LOGMESSAGE0 = 3703
  //POPRANGE0 = 4504658
  //TERRITORYTYPE0 = 152
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKDUNGEONMOOGLEHARD = 145

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ESUMIYAN
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=KUPLOKOPP
        break;
      }
      case 2:
      {
        if( param1 == 4500856 || param2 == 4500856 ) // EVENTRANGE0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, Dismount), id=unknown
          break;
        }
        if( param1 == 1008279 || param2 == 1008279 ) // ACTOR2 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008280 || param2 == 1008280 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008281 || param2 == 1008281 ) // ACTOR4 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008318 || param2 == 1008318 ) // ACTOR5 = KUPLOKOPP
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove, SystemTalk), id=KUPLOKOPP
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1008276 || param2 == 1008276 ) // ACTOR6 = KUPLOKOPP
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=KUPLOKOPP
          break;
        }
        if( param1 == 4515258 || param2 == 4515258 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2003347 || param2 == 2003347 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 4500863 || param2 == 4500863 ) // EVENTRANGE1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 4515416 || param2 == 4515416 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4500869 || param2 == 4500869 ) // EVENTRANGE2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 4515569 || param2 == 4515569 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4515570 || param2 == 4515570 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4515571 || param2 == 4515571 ) // ENEMY4 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4500872 || param2 == 4500872 ) // EVENTRANGE3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 4515572 || param2 == 4515572 ) // ENEMY5 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4500873 || param2 == 4500873 ) // EVENTRANGE4 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 4515578 || param2 == 4515578 ) // ENEMY6 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4515579 || param2 == 4515579 ) // ENEMY7 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4500875 || param2 == 4500875 ) // EVENTRANGE5 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 4515587 || param2 == 4515587 ) // ENEMY8 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4515588 || param2 == 4515588 ) // ENEMY9 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4515586 || param2 == 4515586 ) // ENEMY10 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4500877 || param2 == 4500877 ) // EVENTRANGE6 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 4515582 || param2 == 4515582 ) // ENEMY11 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4515580 || param2 == 4515580 ) // ENEMY12 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4515581 || param2 == 4515581 ) // ENEMY13 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 1008276 || param2 == 1008276 ) // ACTOR6 = KUPLOKOPP
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove, SystemTalk), id=KUPLOKOPP
          break;
        }
        if( param1 == 4515258 || param2 == 4515258 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2003057 || param2 == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1008277 || param2 == 1008277 ) // ACTOR7 = KUPLOKOPP
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=KUPLOKOPP
          }
          break;
        }
        if( param1 == 2003057 || param2 == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 2003046 || param2 == 2003046 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(QuestGimmickReaction), id=unknown
            // +Callback Scene00025: Normal(Talk, Message, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1008277 || param2 == 1008277 ) // ACTOR7 = KUPLOKOPP
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=KUPLOKOPP
          break;
        }
        if( param1 == 2003057 || param2 == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1008277 || param2 == 1008277 ) // ACTOR7 = KUPLOKOPP
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=KUPLOKOPP
          break;
        }
        if( param1 == 2003057 || param2 == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 8:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00032( player ); // Scene00032: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          break;
        }
        if( param1 == 2003057 || param2 == 2003057 ) // EOBJECT1 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00035( player ); // Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KUPCHAKUPA
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
    player.setQuestBitFlag8( getId(), 1, false );
    player.updateQuest( getId(), 4 );
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
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    player.updateQuest( getId(), 8 );
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse116:66726 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ESUMIYAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_2: EVENTRANGE0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00003: Normal(Talk, FadeIn, Dismount), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00008: Normal(Talk, TargetCanMove, SystemTalk), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00009: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //player.setQuestBitFlag8( getId(), 1, true );
      player.sendUrgent( "Skipping to SEQ_4." );
      player.updateQuest( getId(), 4 );
    };
    player.playScene( getId(), 9, NONE, callback );
  }


  void Scene00010( Entity::Player& player ) //SEQ_4: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00010: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_4: EVENTRANGE1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }


  void Scene00012( Entity::Player& player ) //SEQ_4: EVENTRANGE2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }




  void Scene00013( Entity::Player& player ) //SEQ_4: EVENTRANGE3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }


  void Scene00014( Entity::Player& player ) //SEQ_4: EVENTRANGE4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }



  void Scene00015( Entity::Player& player ) //SEQ_4: EVENTRANGE5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }




  void Scene00016( Entity::Player& player ) //SEQ_4: EVENTRANGE6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }




  void Scene00017( Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00017: Normal(Talk, TargetCanMove, SystemTalk), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }


  void Scene00019( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_5: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00020: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_5: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00024( Entity::Player& player ) //SEQ_6: EOBJECT2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00024: Normal(QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player ) //SEQ_6: EOBJECT2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00025: Normal(Talk, Message, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_6: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00026: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_6: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00028: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00029( Entity::Player& player ) //SEQ_7: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00029: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_7: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00031: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00032( Entity::Player& player ) //SEQ_8: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00032: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_8: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00034: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00035( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse116:66726 calling Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KUPCHAKUPA" );
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
};

EXPOSE_SCRIPT( GaiUse116 );
