// FFXIVTheMovie.ParserV3.6
// id hint used:
//SCENE_3 = TATARU
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse314 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse314() : Sapphire::ScriptAPI::EventScript( 66991 ){}; 
  ~GaiUse314() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 5 entries
  //SEQ_6, 2 entries
  //SEQ_7, 5 entries
  //SEQ_8, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006530
  //ACTOR1 = 1009058
  //ACTOR2 = 1000997
  //ACTOR3 = 1009059
  //ACTOR4 = 1009061
  //ACTOR5 = 1008974
  //ACTOR6 = 1009060
  //ENEMY0 = 4867473
  //EOBJECT0 = 2004146
  //EOBJECT1 = 2004147
  //EOBJECT2 = 2004148
  //EOBJECT3 = 2004135
  //EOBJECT4 = 2004145
  //EOBJECT5 = 2004149
  //EOBJECT6 = 2004150
  //EVENTRANGE0 = 4867472
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001314
  //LOCACTION0 = 258
  //LOCACTION1 = 905
  //LOCACTION2 = 256
  //LOCACTION3 = 839
  //LOCACTOR0 = 1009686
  //LOCACTOR1 = 1009687
  //LOCBGM0 = 101
  //LOCBGM1 = 114
  //LOCFACE0 = 605
  //LOCFACE1 = 612
  //LOCFACE2 = 620
  //LOCFACE3 = 618
  //LOCFACE4 = 615
  //LOCFACE5 = 614
  //LOCPOSACTOR0 = 4893404
  //LOCPOSACTOR1 = 4893497
  //LOCPOSACTOR2 = 4893704
  //LOCPOSACTOR3 = 4893705
  //LOCPOSACTOR4 = 4893706
  //LOCPOSACTOR5 = 4893708
  //LOCPOSACTOR6 = 4893846
  //LOCSE0 = 76
  //QSTCOMPCHK01 = 65827

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLAFBORN
        break;
      }
      case 1:
      {
        if( param1 == 1009058 || param2 == 1009058 ) // ACTOR1 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TATARU
            // +Callback Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=TATARU
          }
          break;
        }
        if( param1 == 1006530 || param2 == 1006530 ) // ACTOR0 = SLAFBORN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SLAFBORN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1000997 || param2 == 1000997 ) // ACTOR2 = BRITHAEL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=BRITHAEL
          }
          break;
        }
        if( param1 == 1009059 || param2 == 1009059 ) // ACTOR3 = TATARU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1009061 || param2 == 1009061 ) // ACTOR4 = DELIVERYMAN01455
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455
          }
          break;
        }
        if( param1 == 2004146 || param2 == 2004146 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004147 || param2 == 2004147 ) // EOBJECT1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004148 || param2 == 2004148 ) // EOBJECT2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004135 || param2 == 2004135 ) // EOBJECT3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1000997 || param2 == 1000997 ) // ACTOR2 = BRITHAEL
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=BRITHAEL
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 2004145 || param2 == 2004145 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2004146 || param2 == 2004146 ) // EOBJECT0 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004147 || param2 == 2004147 ) // EOBJECT1 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004148 || param2 == 2004148 ) // EOBJECT2 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004135 || param2 == 2004135 ) // EOBJECT3 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009061 || param2 == 1009061 ) // ACTOR4 = DELIVERYMAN01455
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      case 5:
      {
        if( param1 == 1008974 || param2 == 1008974 ) // ACTOR5 = FLHAMINN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00023: Normal(Talk, TargetCanMove, SystemTalk), id=FLHAMINN
          }
          break;
        }
        if( param1 == 2004146 || param2 == 2004146 ) // EOBJECT0 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004147 || param2 == 2004147 ) // EOBJECT1 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004148 || param2 == 2004148 ) // EOBJECT2 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009061 || param2 == 1009061 ) // ACTOR4 = DELIVERYMAN01455
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 2004149 || param2 == 2004149 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(SystemTalk), id=unknown
            // +Callback Scene00029: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown
          }
          break;
        }
        if( param1 == 1008974 || param2 == 1008974 ) // ACTOR5 = FLHAMINN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=FLHAMINN
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 4867472 || param2 == 4867472 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4867473 || param2 == 4867473 ) // ENEMY0 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009060 || param2 == 1009060 ) // ACTOR6 = TATARU
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1008974 || param2 == 1008974 ) // ACTOR5 = FLHAMINN
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=FLHAMINN
          break;
        }
        if( param1 == 2004150 || param2 == 2004150 ) // EOBJECT6 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 8:
      {
        if( type != 2 ) Scene00036( player ); // Scene00036: Normal(Talk, NpcDespawn, TargetCanMove), id=TATARU
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00037( player ); // Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU
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
    if( player.getQuestUI8AL( getId() ) == 1 )
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
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 8 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse314:66991 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00002: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00004: Normal(Talk, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00005: Normal(Talk, TargetCanMove), id=BRITHAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00006: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_3: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00007: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player ) //SEQ_3: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00008: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00009: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00014: Normal(Talk, TargetCanMove), id=BRITHAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_4: EOBJECT4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq4( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_4: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00018( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_4: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00021( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00021: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_5: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00022: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00023( player );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player ) //SEQ_5: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00023: Normal(Talk, TargetCanMove, SystemTalk), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_5: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00024: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00025( Entity::Player& player ) //SEQ_5: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00026( Entity::Player& player ) //SEQ_5: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00026: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00027( Entity::Player& player ) //SEQ_5: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00027: Normal(Talk, TargetCanMove), id=DELIVERYMAN01455" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_6: EOBJECT5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00028: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00029( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player ) //SEQ_6: EOBJECT5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00029: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_6: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00030: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_7: EVENTRANGE0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00031: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_7: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00032: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00033( Entity::Player& player ) //SEQ_7: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00033: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_7: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00034: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_7: EOBJECT6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00035: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00036( Entity::Player& player ) //SEQ_8: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00036: Normal(Talk, NpcDespawn, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse314:66991 calling Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU" );
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
    player.playScene( getId(), 37, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse314 );
