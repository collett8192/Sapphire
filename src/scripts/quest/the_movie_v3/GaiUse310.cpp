// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse310 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse310() : Sapphire::ScriptAPI::EventScript( 66987 ){}; 
  ~GaiUse310() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_4, 9 entries
  //SEQ_5, 6 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEVENTBASEKNEESUFFERING = 936
  //ACTIONTIMELINEEVENTJOY = 953
  //ACTIONTIMELINEEVENTSAD = 954
  //ACTIONTIMELINEFACIALSPEWING = 617
  //ACTOR0 = 1009414
  //ACTOR1 = 1009106
  //ACTOR2 = 1009118
  //ACTOR3 = 1009121
  //ACTOR4 = 1009122
  //ACTOR5 = 1009116
  //ACTOR6 = 1009117
  //ACTOR7 = 1009123
  //ACTOR8 = 1009119
  //ACTOR9 = 1009120
  //BNPCNAME0 = 2878
  //ENEMY0 = 4868024
  //EOBJECT0 = 2004143
  //EVENTRANGE0 = 4868023
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001313
  //LEVELIDNPC01 = 4868019
  //LEVELIDNPC02 = 4868020
  //LEVELIDNPC03 = 4868008
  //LOCACTOR0 = 1009668
  //LOCACTOR1 = 1008176
  //LOCACTOR2 = 4868019
  //LOCACTOR3 = 4868015
  //LOCACTOR4 = 4868016
  //LOCACTOR5 = 4868020
  //LOCPOSACTOR0 = 4892562
  //LOCVFX01 = 300

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1009414 || param2 == 1009414 ) // ACTOR0 = YDA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=YDA
          break;
        }
        if( param1 == 1009106 || param2 == 1009106 ) // ACTOR1 = MAXIO
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MAXIO
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1009118 || param2 == 1009118 ) // ACTOR2 = PAPALYMO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=PAPALYMO
          }
          break;
        }
        if( param1 == 1009121 || param2 == 1009121 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1009122 || param2 == 1009122 ) // ACTOR4 = DUMMYYSHTOLA01451
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=DUMMYYSHTOLA01451
          break;
        }
        if( param1 == 1009116 || param2 == 1009116 ) // ACTOR5 = YDA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1009117 || param2 == 1009117 ) // ACTOR6 = MAXIO
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MAXIO
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 1009117 || param2 == 1009117 ) // ACTOR6 = MAXIO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MAXIO
          }
          break;
        }
        if( param1 == 1009118 || param2 == 1009118 ) // ACTOR2 = PAPALYMO
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1009121 || param2 == 1009121 ) // ACTOR3 = YSHTOLA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1009122 || param2 == 1009122 ) // ACTOR4 = DUMMYYSHTOLA01451
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=DUMMYYSHTOLA01451
          break;
        }
        if( param1 == 1009116 || param2 == 1009116 ) // ACTOR5 = YDA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 1009118 || param2 == 1009118 ) // ACTOR2 = PAPALYMO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, Inventory, TargetCanMove), id=PAPALYMO
            // +Callback Scene00014: Normal(TargetCanMove, ENpcBind), id=unknown
            // +Callback Scene00015: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=PAPALYMO
          }
          break;
        }
        if( param1 == 1009116 || param2 == 1009116 ) // ACTOR5 = YDA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1009117 || param2 == 1009117 ) // ACTOR6 = MAXIO
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MAXIO
          break;
        }
        if( param1 == 1009121 || param2 == 1009121 ) // ACTOR3 = YSHTOLA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1009122 || param2 == 1009122 ) // ACTOR4 = DUMMYYSHTOLA01451
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=DUMMYYSHTOLA01451
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 4868023 || param2 == 4868023 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4868024 || param2 == 4868024 ) // ENEMY0 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009123 || param2 == 1009123 ) // ACTOR7 = DUMMYYSHTOLA01451
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=DUMMYYSHTOLA01451
          break;
        }
        if( param1 == 1009116 || param2 == 1009116 ) // ACTOR5 = YDA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, Message, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1009117 || param2 == 1009117 ) // ACTOR6 = MAXIO
        {
          Scene00024( player ); // Scene00024: Normal(Talk, Message, TargetCanMove), id=MAXIO
          break;
        }
        if( param1 == 1009119 || param2 == 1009119 ) // ACTOR8 = PAPALYMO
        {
          Scene00025( player ); // Scene00025: Normal(Talk, Message, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1009120 || param2 == 1009120 ) // ACTOR9 = THANCRED
        {
          Scene00026( player ); // Scene00026: Normal(Talk, Message, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1009121 || param2 == 1009121 ) // ACTOR3 = YSHTOLA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, Message, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 2004143 || param2 == 2004143 ) // EOBJECT0 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1009123 || param2 == 1009123 ) // ACTOR7 = DUMMYYSHTOLA01451
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00029( player ); // Scene00029: Normal(Talk, NpcDespawn, TargetCanMove), id=DUMMYYSHTOLA01451
          }
          break;
        }
        if( param1 == 1009116 || param2 == 1009116 ) // ACTOR5 = YDA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1009117 || param2 == 1009117 ) // ACTOR6 = MAXIO
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=MAXIO
          break;
        }
        if( param1 == 1009119 || param2 == 1009119 ) // ACTOR8 = PAPALYMO
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1009120 || param2 == 1009120 ) // ACTOR9 = THANCRED
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1009121 || param2 == 1009121 ) // ACTOR3 = YSHTOLA
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1009119 || param2 == 1009119 ) // ACTOR8 = PAPALYMO
        {
          Scene00035( player ); // Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1009116 || param2 == 1009116 ) // ACTOR5 = YDA
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1009117 || param2 == 1009117 ) // ACTOR6 = MAXIO
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=MAXIO
          break;
        }
        if( param1 == 1009120 || param2 == 1009120 ) // ACTOR9 = THANCRED
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1009121 || param2 == 1009121 ) // ACTOR3 = YSHTOLA
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse310:66987 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00002: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00003: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00005: Normal(Talk, TargetCanMove), id=DUMMYYSHTOLA01451" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00006: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00007: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00008: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00009: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00011: Normal(Talk, TargetCanMove), id=DUMMYYSHTOLA01451" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00012: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00013: Normal(Talk, Inventory, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player ) //SEQ_3: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00014: Normal(TargetCanMove, ENpcBind), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player ) //SEQ_3: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00015: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00016: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00017: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00019: Normal(Talk, TargetCanMove), id=DUMMYYSHTOLA01451" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_4: EVENTRANGE0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_4: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00022( Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00022: Normal(Talk, TargetCanMove), id=DUMMYYSHTOLA01451" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00023: Normal(Talk, Message, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00024: Normal(Talk, Message, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00025: Normal(Talk, Message, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00026: Normal(Talk, Message, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00027: Normal(Talk, Message, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_4: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00028: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00029( Entity::Player& player ) //SEQ_5: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00029: Normal(Talk, NpcDespawn, TargetCanMove), id=DUMMYYSHTOLA01451" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_5: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00030: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00031: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_5: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00032: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_5: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00033: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00034: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAPALYMO" );
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

  void Scene00036( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00036: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00037: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00038: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse310:66987 calling Scene00039: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse310 );
