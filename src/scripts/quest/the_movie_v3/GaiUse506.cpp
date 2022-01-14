// FFXIVTheMovie.ParserV3.6
// id hint used:
//ACTOR11 = YUYUHASE
//ACTOR12 = null
//ACTOR13 = null
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse506 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse506() : Sapphire::ScriptAPI::EventScript( 65904 ){}; 
  ~GaiUse506() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 8 entries
  //SEQ_2, 4 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006646
  //ACTOR1 = 1010924
  //ACTOR10 = 1010869
  //ACTOR11 = 1010876
  //ACTOR12 = 1010877
  //ACTOR13 = 1010878
  //ACTOR2 = 1011131
  //ACTOR3 = 1010871
  //ACTOR4 = 1010872
  //ACTOR5 = 1010873
  //ACTOR6 = 1010874
  //ACTOR7 = 1010875
  //ACTOR8 = 1010867
  //ACTOR9 = 1010868
  //ENEMY0 = 5589314
  //ENEMY1 = 5589315
  //ENEMY2 = 5589318
  //ENEMY3 = 5589325
  //ENEMY4 = 5589332
  //ENEMY5 = 5654263
  //EOBJECT0 = 2005043
  //EOBJECT1 = 2005044
  //EVENTRANGE0 = 5584274
  //EVENTRANGE1 = 5584276
  //LOCACTOR0 = 1008191
  //LOCACTOR1 = 5580235
  //LOCACTOR10 = 5580256
  //LOCACTOR11 = 5580234
  //LOCACTOR2 = 5580219
  //LOCACTOR3 = 5580218
  //LOCACTOR4 = 5580220
  //LOCACTOR5 = 5580221
  //LOCACTOR6 = 5580222
  //LOCACTOR7 = 5579278
  //LOCACTOR8 = 5579279
  //LOCACTOR9 = 5580255
  //LOCMOTION0 = 1045

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1006646 || param2 == 1006646 ) // ACTOR0 = EDELSTEIN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EDELSTEIN
          break;
        }
        if( param1 == 1010924 || param2 == 1010924 ) // ACTOR1 = ALIANNE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1011131 || param2 == 1011131 ) // ACTOR2 = WILRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=WILRED
          break;
        }
        if( param1 == 1010871 || param2 == 1010871 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1010872 || param2 == 1010872 ) // ACTOR4 = PAPALYMO
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1010873 || param2 == 1010873 ) // ACTOR5 = YDA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1010874 || param2 == 1010874 ) // ACTOR6 = YSHTOLA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1010875 || param2 == 1010875 ) // ACTOR7 = MOENBRYDA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MOENBRYDA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1010924 || param2 == 1010924 ) // ACTOR1 = ALIANNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALIANNE
          }
          break;
        }
        if( param1 == 1006646 || param2 == 1006646 ) // ACTOR0 = EDELSTEIN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=EDELSTEIN
          break;
        }
        if( param1 == 1011131 || param2 == 1011131 ) // ACTOR2 = WILRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=WILRED
          break;
        }
        if( param1 == 1010871 || param2 == 1010871 ) // ACTOR3 = THANCRED
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1010872 || param2 == 1010872 ) // ACTOR4 = PAPALYMO
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1010873 || param2 == 1010873 ) // ACTOR5 = YDA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1010874 || param2 == 1010874 ) // ACTOR6 = YSHTOLA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1010875 || param2 == 1010875 ) // ACTOR7 = MOENBRYDA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOENBRYDA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1010867 || param2 == 1010867 ) // ACTOR8 = YUYUHASE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=YUYUHASE
          }
          break;
        }
        if( param1 == 1010868 || param2 == 1010868 ) // ACTOR9 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010869 || param2 == 1010869 ) // ACTOR10 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006646 || param2 == 1006646 ) // ACTOR0 = EDELSTEIN
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=EDELSTEIN
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 5584274 || param2 == 5584274 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00021( player ); // Scene00021: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5589314 || param2 == 5589314 ) // ENEMY0 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 5589315 || param2 == 5589315 ) // ENEMY1 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 5589318 || param2 == 5589318 ) // ENEMY2 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005043 || param2 == 2005043 ) // EOBJECT0 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006646 || param2 == 1006646 ) // ACTOR0 = EDELSTEIN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=EDELSTEIN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 5584276 || param2 == 5584276 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00027( player ); // Scene00027: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5589325 || param2 == 5589325 ) // ENEMY3 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 5589332 || param2 == 5589332 ) // ENEMY4 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 5654263 || param2 == 5654263 ) // ENEMY5 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 2005044 || param2 == 2005044 ) // EOBJECT1 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006646 || param2 == 1006646 ) // ACTOR0 = EDELSTEIN
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=EDELSTEIN
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1010876 || param2 == 1010876 ) // ACTOR11 = YUYUHASE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUYUHASE
          }
          break;
        }
        if( param1 == 1010877 || param2 == 1010877 ) // ACTOR12 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010878 || param2 == 1010878 ) // ACTOR13 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006646 || param2 == 1006646 ) // ACTOR0 = EDELSTEIN
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=EDELSTEIN
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00037( player ); // Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EDELSTEIN
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
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
    player.sendDebug( "GaiUse506:65904 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse506:65904 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00002: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00003: Normal(Talk, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_0: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00005: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_0: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00006: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_0: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_0: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00008: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00009: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00010: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00011: Normal(Talk, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00012: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00013: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00014: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00015: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00016: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR8, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00017: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player ) //SEQ_2: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00020: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_3: EVENTRANGE0, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_3: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00023( Entity::Player& player ) //SEQ_3: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00023: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00024( Entity::Player& player ) //SEQ_3: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00024: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00025( Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00026( Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00026: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_4: EVENTRANGE1, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00027: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_4: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00028: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00029( Entity::Player& player ) //SEQ_4: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00029: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00030( Entity::Player& player ) //SEQ_4: ENEMY5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00030: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00031( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00031: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00032( Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00032: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_5: ACTOR11, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00033: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_5: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player ) //SEQ_5: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player ) //SEQ_5: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00036: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse506:65904 calling Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EDELSTEIN" );
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

EXPOSE_SCRIPT( GaiUse506 );
