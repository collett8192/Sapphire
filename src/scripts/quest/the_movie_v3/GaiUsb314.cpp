// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb314 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb314() : Sapphire::ScriptAPI::EventScript( 66391 ){}; 
  ~GaiUsb314() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 15 entries
  //SEQ_2, 16 entries
  //SEQ_3, 13 entries
  //SEQ_255, 13 entries

  //ACTOR0 = 1006676
  //ACTOR1 = 1006314
  //ACTOR2 = 1006313
  //ACTOR3 = 1006315
  //ACTOR4 = 1006316
  //ACTOR5 = 1006317
  //ACTOR6 = 1006318
  //ACTOR7 = 1006319
  //ACTOR8 = 1006266
  //BGMLVUP = 23
  //CUTSCENE01 = 369
  //EOBJECT0 = 2002075
  //EOBJECT1 = 2002076
  //EOBJECT2 = 2002077
  //EOBJECT3 = 2002078
  //EOBJECT4 = 2002079
  //EOBJECT5 = 2002080
  //EOBJECT6 = 2002081
  //EOBJECT7 = 2002082
  //EOBJECT8 = 2002598
  //EVENTACTIONSEARCH = 1
  //LOCACTION0 = 788
  //LOCACTION1 = 1016
  //LOCACTION2 = 683
  //LOCACTOR1 = 1006272
  //LOCACTOR100 = 1007014
  //LOCBINDEOBJ100 = 4293459
  //LOCBINDEOBJ101 = 4293460
  //LOCBINDEOBJ102 = 4293461
  //LOCEOBJ1 = 2002687
  //LOCPOSACTOR0 = 4374246
  //LOCPOSACTOR1 = 4258358
  //LOCPOSCAM1 = 4374251
  //LOCPOSEOBJ1 = 4373897
  //QSTACCEPTCHECK = 66390

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown
        // +Callback Scene00001: Normal(Talk, TargetCanMove), id=YSHTOLA
        // +Callback Scene00002: Normal(CutScene, QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 1006314 || param2 == 1006314 ) // ACTOR1 = NPC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=NPC
          }
          break;
        }
        if( param1 == 1006313 || param2 == 1006313 ) // ACTOR2 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006315 || param2 == 1006315 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006316 || param2 == 1006316 ) // ACTOR4 = UODHNUN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=UODHNUN
          break;
        }
        if( param1 == 1006317 || param2 == 1006317 ) // ACTOR5 = LANDENEL
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LANDENEL
          break;
        }
        if( param1 == 1006318 || param2 == 1006318 ) // ACTOR6 = BRAYFLOX
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=BRAYFLOX
          break;
        }
        if( param1 == 1006319 || param2 == 1006319 ) // ACTOR7 = SHAMANILOHMANI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
          break;
        }
        if( param1 == 2002075 || param2 == 2002075 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002076 || param2 == 2002076 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002077 || param2 == 2002077 ) // EOBJECT2 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002078 || param2 == 2002078 ) // EOBJECT3 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002079 || param2 == 2002079 ) // EOBJECT4 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002080 || param2 == 2002080 ) // EOBJECT5 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002081 || param2 == 2002081 ) // EOBJECT6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002082 || param2 == 2002082 ) // EOBJECT7 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2002598 || param2 == 2002598 ) // EOBJECT8 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(FadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1006313 || param2 == 1006313 ) // ACTOR2 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006314 || param2 == 1006314 ) // ACTOR1 = NPC
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=NPC
          break;
        }
        if( param1 == 1006315 || param2 == 1006315 ) // ACTOR3 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006316 || param2 == 1006316 ) // ACTOR4 = UODHNUN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=UODHNUN
          break;
        }
        if( param1 == 1006317 || param2 == 1006317 ) // ACTOR5 = LANDENEL
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=LANDENEL
          break;
        }
        if( param1 == 1006318 || param2 == 1006318 ) // ACTOR6 = BRAYFLOX
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=BRAYFLOX
          break;
        }
        if( param1 == 1006319 || param2 == 1006319 ) // ACTOR7 = SHAMANILOHMANI
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
          break;
        }
        if( param1 == 2002075 || param2 == 2002075 ) // EOBJECT0 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002076 || param2 == 2002076 ) // EOBJECT1 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002077 || param2 == 2002077 ) // EOBJECT2 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002078 || param2 == 2002078 ) // EOBJECT3 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002079 || param2 == 2002079 ) // EOBJECT4 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002080 || param2 == 2002080 ) // EOBJECT5 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002081 || param2 == 2002081 ) // EOBJECT6 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002082 || param2 == 2002082 ) // EOBJECT7 = unknown
        {
          Scene00050( player ); // Scene00050: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1006266 || param2 == 1006266 ) // ACTOR8 = WHEISKAET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=WHEISKAET
          }
          break;
        }
        if( param1 == 1006317 || param2 == 1006317 ) // ACTOR5 = LANDENEL
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=LANDENEL
            // +Callback Scene00054: Normal(Talk, TargetCanMove), id=LANDENEL
          }
          break;
        }
        if( param1 == 1006316 || param2 == 1006316 ) // ACTOR4 = UODHNUN
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=UODHNUN
            // +Callback Scene00056: Normal(Talk, TargetCanMove), id=UODHNUN
          }
          break;
        }
        if( param1 == 1006318 || param2 == 1006318 ) // ACTOR6 = BRAYFLOX
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=BRAYFLOX
            // +Callback Scene00058: Normal(Talk, TargetCanMove), id=BRAYFLOX
          }
          break;
        }
        if( param1 == 1006319 || param2 == 1006319 ) // ACTOR7 = SHAMANILOHMANI
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
          }
          break;
        }
        if( param1 == 1006313 || param2 == 1006313 ) // ACTOR2 = SHAMANILOHMANI
        {
          Scene00061( player ); // Scene00061: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
          break;
        }
        if( param1 == 1006314 || param2 == 1006314 ) // ACTOR1 = unknown
        {
          Scene00062( player ); // Scene00062: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006315 || param2 == 1006315 ) // ACTOR3 = NPC
        {
          Scene00063( player ); // Scene00063: Normal(Talk, TargetCanMove), id=NPC
          break;
        }
        if( param1 == 2002078 || param2 == 2002078 ) // EOBJECT3 = unknown
        {
          Scene00065( player ); // Scene00065: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002079 || param2 == 2002079 ) // EOBJECT4 = unknown
        {
          Scene00067( player ); // Scene00067: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002080 || param2 == 2002080 ) // EOBJECT5 = unknown
        {
          Scene00069( player ); // Scene00069: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002081 || param2 == 2002081 ) // EOBJECT6 = unknown
        {
          Scene00071( player ); // Scene00071: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002082 || param2 == 2002082 ) // EOBJECT7 = unknown
        {
          Scene00073( player ); // Scene00073: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006676 || param2 == 1006676 ) // ACTOR0 = YSHTOLA
        {
          Scene00075( player ); // Scene00075: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1006313 || param2 == 1006313 ) // ACTOR2 = unknown
        {
          Scene00076( player ); // Scene00076: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006314 || param2 == 1006314 ) // ACTOR1 = NPC
        {
          Scene00077( player ); // Scene00077: Normal(Talk, TargetCanMove), id=NPC
          break;
        }
        if( param1 == 1006315 || param2 == 1006315 ) // ACTOR3 = unknown
        {
          Scene00078( player ); // Scene00078: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006316 || param2 == 1006316 ) // ACTOR4 = UODHNUN
        {
          Scene00079( player ); // Scene00079: Normal(Talk, TargetCanMove), id=UODHNUN
          break;
        }
        if( param1 == 1006317 || param2 == 1006317 ) // ACTOR5 = LANDENEL
        {
          Scene00080( player ); // Scene00080: Normal(Talk, TargetCanMove), id=LANDENEL
          break;
        }
        if( param1 == 1006318 || param2 == 1006318 ) // ACTOR6 = BRAYFLOX
        {
          Scene00081( player ); // Scene00081: Normal(Talk, TargetCanMove), id=BRAYFLOX
          break;
        }
        if( param1 == 1006319 || param2 == 1006319 ) // ACTOR7 = SHAMANILOHMANI
        {
          Scene00082( player ); // Scene00082: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
          break;
        }
        if( param1 == 2002078 || param2 == 2002078 ) // EOBJECT3 = unknown
        {
          Scene00084( player ); // Scene00084: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002079 || param2 == 2002079 ) // EOBJECT4 = unknown
        {
          Scene00086( player ); // Scene00086: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002080 || param2 == 2002080 ) // EOBJECT5 = unknown
        {
          Scene00088( player ); // Scene00088: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002081 || param2 == 2002081 ) // EOBJECT6 = unknown
        {
          Scene00090( player ); // Scene00090: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002082 || param2 == 2002082 ) // EOBJECT7 = unknown
        {
          Scene00092( player ); // Scene00092: Normal(None), id=unknown
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
      player.setQuestBitFlag16( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag16( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
            if( player.getQuestUI8CL( getId() ) == 1 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8BH( getId(), 0 );
              player.setQuestUI8BL( getId(), 0 );
              player.setQuestUI8CH( getId(), 0 );
              player.setQuestUI8CL( getId(), 0 );
              player.setQuestBitFlag16( getId(), 1, false );
              player.setQuestBitFlag16( getId(), 2, false );
              player.setQuestBitFlag16( getId(), 3, false );
              player.setQuestBitFlag16( getId(), 4, false );
              player.setQuestBitFlag16( getId(), 5, false );
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00000: Normal(QuestOffer, TargetCanMove, SystemTalk, CanCancel), id=unknown" );
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
    player.sendDebug( "GaiUsb314:66391 calling Scene00001: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00002: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag16(1)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00003: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag16( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00006: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00007: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00008: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00009: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_1: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_1: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00021( Entity::Player& player ) //SEQ_1: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00023( Entity::Player& player ) //SEQ_1: EOBJECT6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00023: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00025( Entity::Player& player ) //SEQ_1: EOBJECT7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00027( Entity::Player& player ) //SEQ_2: EOBJECT8, UI8AL = 1, Flag16(1)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00027: Normal(FadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag16( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00029: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00031: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00032: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00033: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_2: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00034: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00036( Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00036: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00038( Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00038: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00040( Entity::Player& player ) //SEQ_2: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00040: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00042( Entity::Player& player ) //SEQ_2: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00042: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00044( Entity::Player& player ) //SEQ_2: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00044: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00046( Entity::Player& player ) //SEQ_2: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00046: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00048( Entity::Player& player ) //SEQ_2: EOBJECT6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00048: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00050( Entity::Player& player ) //SEQ_2: EOBJECT7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00050: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00051( Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 1, Flag16(1)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00051: Normal(Talk, TargetCanMove), id=WHEISKAET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag16( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00053( Entity::Player& player ) //SEQ_3: ACTOR5, UI8BH = 1, Flag16(2)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00053: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00054( player );
    };
    player.playScene( getId(), 53, NONE, callback );
  }
  void Scene00054( Entity::Player& player ) //SEQ_3: ACTOR5, UI8BH = 1, Flag16(2)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00054: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag16( getId(), 2, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player ) //SEQ_3: ACTOR4, UI8BL = 1, Flag16(3)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00055: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00056( player );
    };
    player.playScene( getId(), 55, NONE, callback );
  }
  void Scene00056( Entity::Player& player ) //SEQ_3: ACTOR4, UI8BL = 1, Flag16(3)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00056: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag16( getId(), 3, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player ) //SEQ_3: ACTOR6, UI8CH = 1, Flag16(4)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00057: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00058( player );
    };
    player.playScene( getId(), 57, NONE, callback );
  }
  void Scene00058( Entity::Player& player ) //SEQ_3: ACTOR6, UI8CH = 1, Flag16(4)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00058: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      player.setQuestBitFlag16( getId(), 4, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player ) //SEQ_3: ACTOR7, UI8CL = 1, Flag16(5)=True
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00059: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      player.setQuestBitFlag16( getId(), 5, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00061( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00061: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00062: Normal(None), id=unknown" );
  }

  void Scene00063( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00063: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 63, NONE, callback );
  }

  void Scene00065( Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00065: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00067( Entity::Player& player ) //SEQ_3: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00067: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00069( Entity::Player& player ) //SEQ_3: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00069: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00071( Entity::Player& player ) //SEQ_3: EOBJECT6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00071: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00073( Entity::Player& player ) //SEQ_3: EOBJECT7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00073: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00075( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00075: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA" );
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
    player.playScene( getId(), 75, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00076( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00076: Normal(None), id=unknown" );
  }

  void Scene00077( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00077: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 77, NONE, callback );
  }

  void Scene00078( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00078: Normal(None), id=unknown" );
  }

  void Scene00079( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00079: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 79, NONE, callback );
  }

  void Scene00080( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00080: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 80, NONE, callback );
  }

  void Scene00081( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00081: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 81, NONE, callback );
  }

  void Scene00082( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00082: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 82, NONE, callback );
  }

  void Scene00084( Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00084: Normal(None), id=unknown" );
  }

  void Scene00086( Entity::Player& player ) //SEQ_255: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00086: Normal(None), id=unknown" );
  }

  void Scene00088( Entity::Player& player ) //SEQ_255: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00088: Normal(None), id=unknown" );
  }

  void Scene00090( Entity::Player& player ) //SEQ_255: EOBJECT6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00090: Normal(None), id=unknown" );
  }

  void Scene00092( Entity::Player& player ) //SEQ_255: EOBJECT7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00092: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb314 );
