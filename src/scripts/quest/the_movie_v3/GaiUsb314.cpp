// FFXIVTheMovie.ParserV3
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
  //LOCEOBJ1 = 2002687
  //LOCPOSACTOR0 = 4374246
  //LOCPOSACTOR1 = 4258358
  //LOCPOSCAM1 = 4374251
  //LOCPOSEOBJ1 = 4373897

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, TargetCanMove), id=YSHTOLA
        // +Callback Scene00002: Normal(CutScene, QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( actor == 1006314 || actorId == 1006314 ) // ACTOR1 = NPC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=NPC
          }
        }
        if( actor == 1006313 || actorId == 1006313 ) // ACTOR2 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1006315 || actorId == 1006315 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 1006316 || actorId == 1006316 ) // ACTOR4 = UODHNUN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=UODHNUN
        }
        if( actor == 1006317 || actorId == 1006317 ) // ACTOR5 = LANDENEL
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LANDENEL
        }
        if( actor == 1006318 || actorId == 1006318 ) // ACTOR6 = BRAYFLOX
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=BRAYFLOX
        }
        if( actor == 1006319 || actorId == 1006319 ) // ACTOR7 = SHAMANILOHMANI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
        }
        if( actor == 2002075 || actorId == 2002075 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(None), id=unknown
        }
        if( actor == 2002076 || actorId == 2002076 ) // EOBJECT1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(None), id=unknown
        }
        if( actor == 2002077 || actorId == 2002077 ) // EOBJECT2 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          // +Callback Scene00015: Normal(None), id=unknown
        }
        if( actor == 2002078 || actorId == 2002078 ) // EOBJECT3 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          // +Callback Scene00017: Normal(None), id=unknown
        }
        if( actor == 2002079 || actorId == 2002079 ) // EOBJECT4 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(None), id=unknown
        }
        if( actor == 2002080 || actorId == 2002080 ) // EOBJECT5 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(None), id=unknown
        }
        if( actor == 2002081 || actorId == 2002081 ) // EOBJECT6 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          // +Callback Scene00023: Normal(None), id=unknown
        }
        if( actor == 2002082 || actorId == 2002082 ) // EOBJECT7 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          // +Callback Scene00025: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 2002598 || actorId == 2002598 ) // EOBJECT8 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(None), id=unknown
          }
        }
        if( actor == 1006313 || actorId == 1006313 ) // ACTOR2 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(FadeIn), id=unknown
        }
        if( actor == 1006314 || actorId == 1006314 ) // ACTOR1 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
        }
        if( actor == 1006315 || actorId == 1006315 ) // ACTOR3 = NPC
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=NPC
        }
        if( actor == 1006316 || actorId == 1006316 ) // ACTOR4 = UODHNUN
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          // +Callback Scene00031: Normal(Talk, TargetCanMove), id=UODHNUN
        }
        if( actor == 1006317 || actorId == 1006317 ) // ACTOR5 = LANDENEL
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=LANDENEL
        }
        if( actor == 1006318 || actorId == 1006318 ) // ACTOR6 = BRAYFLOX
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=BRAYFLOX
        }
        if( actor == 1006319 || actorId == 1006319 ) // ACTOR7 = SHAMANILOHMANI
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
        }
        if( actor == 2002075 || actorId == 2002075 ) // EOBJECT0 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          // +Callback Scene00036: Normal(None), id=unknown
        }
        if( actor == 2002076 || actorId == 2002076 ) // EOBJECT1 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          // +Callback Scene00038: Normal(None), id=unknown
        }
        if( actor == 2002077 || actorId == 2002077 ) // EOBJECT2 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          // +Callback Scene00040: Normal(None), id=unknown
        }
        if( actor == 2002078 || actorId == 2002078 ) // EOBJECT3 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          // +Callback Scene00042: Normal(None), id=unknown
        }
        if( actor == 2002079 || actorId == 2002079 ) // EOBJECT4 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          // +Callback Scene00044: Normal(None), id=unknown
        }
        if( actor == 2002080 || actorId == 2002080 ) // EOBJECT5 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
          // +Callback Scene00046: Normal(None), id=unknown
        }
        if( actor == 2002081 || actorId == 2002081 ) // EOBJECT6 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
          // +Callback Scene00048: Normal(None), id=unknown
        }
        if( actor == 2002082 || actorId == 2002082 ) // EOBJECT7 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(None), id=unknown
          // +Callback Scene00050: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1006266 || actorId == 1006266 ) // ACTOR8 = WHEISKAET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=WHEISKAET
          }
        }
        if( actor == 1006317 || actorId == 1006317 ) // ACTOR5 = LANDENEL
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00052( player ); // Scene00052: Normal(None), id=unknown
            // +Callback Scene00053: Normal(Talk, TargetCanMove), id=LANDENEL
          }
          else
          {
            Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=LANDENEL
          }
        }
        if( actor == 1006316 || actorId == 1006316 ) // ACTOR4 = UODHNUN
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=UODHNUN
            // +Callback Scene00056: Normal(Talk, TargetCanMove), id=UODHNUN
          }
        }
        if( actor == 1006318 || actorId == 1006318 ) // ACTOR6 = BRAYFLOX
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=BRAYFLOX
            // +Callback Scene00058: Normal(Talk, TargetCanMove), id=BRAYFLOX
          }
        }
        if( actor == 1006319 || actorId == 1006319 ) // ACTOR7 = SHAMANILOHMANI
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
          }
        }
        if( actor == 1006313 || actorId == 1006313 ) // ACTOR2 = SHAMANILOHMANI
        {
          Scene00060( player ); // Scene00060: Normal(None), id=unknown
          // +Callback Scene00061: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
        }
        if( actor == 1006314 || actorId == 1006314 ) // ACTOR1 = unknown
        {
          Scene00062( player ); // Scene00062: Normal(None), id=unknown
        }
        if( actor == 1006315 || actorId == 1006315 ) // ACTOR3 = NPC
        {
          Scene00063( player ); // Scene00063: Normal(Talk, TargetCanMove), id=NPC
        }
        if( actor == 2002078 || actorId == 2002078 ) // EOBJECT3 = unknown
        {
          Scene00064( player ); // Scene00064: Normal(None), id=unknown
          // +Callback Scene00065: Normal(None), id=unknown
        }
        if( actor == 2002079 || actorId == 2002079 ) // EOBJECT4 = unknown
        {
          Scene00066( player ); // Scene00066: Normal(None), id=unknown
          // +Callback Scene00067: Normal(None), id=unknown
        }
        if( actor == 2002080 || actorId == 2002080 ) // EOBJECT5 = unknown
        {
          Scene00068( player ); // Scene00068: Normal(None), id=unknown
          // +Callback Scene00069: Normal(None), id=unknown
        }
        if( actor == 2002081 || actorId == 2002081 ) // EOBJECT6 = unknown
        {
          Scene00070( player ); // Scene00070: Normal(None), id=unknown
          // +Callback Scene00071: Normal(None), id=unknown
        }
        if( actor == 2002082 || actorId == 2002082 ) // EOBJECT7 = unknown
        {
          Scene00072( player ); // Scene00072: Normal(None), id=unknown
          // +Callback Scene00073: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006676 || actorId == 1006676 ) // ACTOR0 = YSHTOLA
        {
          Scene00074( player ); // Scene00074: Normal(None), id=unknown
          // +Callback Scene00075: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1006313 || actorId == 1006313 ) // ACTOR2 = unknown
        {
          Scene00076( player ); // Scene00076: Normal(None), id=unknown
        }
        if( actor == 1006314 || actorId == 1006314 ) // ACTOR1 = NPC
        {
          Scene00077( player ); // Scene00077: Normal(Talk, TargetCanMove), id=NPC
        }
        if( actor == 1006315 || actorId == 1006315 ) // ACTOR3 = unknown
        {
          Scene00078( player ); // Scene00078: Normal(None), id=unknown
        }
        if( actor == 1006316 || actorId == 1006316 ) // ACTOR4 = UODHNUN
        {
          Scene00079( player ); // Scene00079: Normal(Talk, TargetCanMove), id=UODHNUN
        }
        if( actor == 1006317 || actorId == 1006317 ) // ACTOR5 = LANDENEL
        {
          Scene00080( player ); // Scene00080: Normal(Talk, TargetCanMove), id=LANDENEL
        }
        if( actor == 1006318 || actorId == 1006318 ) // ACTOR6 = BRAYFLOX
        {
          Scene00081( player ); // Scene00081: Normal(Talk, TargetCanMove), id=BRAYFLOX
        }
        if( actor == 1006319 || actorId == 1006319 ) // ACTOR7 = SHAMANILOHMANI
        {
          Scene00082( player ); // Scene00082: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
        }
        if( actor == 2002078 || actorId == 2002078 ) // EOBJECT3 = unknown
        {
          Scene00083( player ); // Scene00083: Normal(None), id=unknown
          // +Callback Scene00084: Normal(None), id=unknown
        }
        if( actor == 2002079 || actorId == 2002079 ) // EOBJECT4 = unknown
        {
          Scene00085( player ); // Scene00085: Normal(None), id=unknown
          // +Callback Scene00086: Normal(None), id=unknown
        }
        if( actor == 2002080 || actorId == 2002080 ) // EOBJECT5 = unknown
        {
          Scene00087( player ); // Scene00087: Normal(None), id=unknown
          // +Callback Scene00088: Normal(None), id=unknown
        }
        if( actor == 2002081 || actorId == 2002081 ) // EOBJECT6 = unknown
        {
          Scene00089( player ); // Scene00089: Normal(None), id=unknown
          // +Callback Scene00090: Normal(None), id=unknown
        }
        if( actor == 2002082 || actorId == 2002082 ) // EOBJECT7 = unknown
        {
          Scene00091( player ); // Scene00091: Normal(None), id=unknown
          // +Callback Scene00092: Normal(None), id=unknown
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
    onProgress( player, param1, param1, 3, param1 );
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
              player.updateQuest( getId(), 255 );
            }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00001: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchChain]Scene00002: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00003: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00006: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00007: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00008: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00009: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00013: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00017: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00021: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00022: Normal(None), id=unknown" );
    Scene00023( player );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00023: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00024: Normal(None), id=unknown" );
    Scene00025( player );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00025: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00026: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00027: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00029: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00030: Normal(None), id=unknown" );
    Scene00031( player );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00031: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00032: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00033: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00034: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00035: Normal(None), id=unknown" );
    Scene00036( player );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00036: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00037: Normal(None), id=unknown" );
    Scene00038( player );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00038: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00039: Normal(None), id=unknown" );
    Scene00040( player );
  }
  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00040: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00041: Normal(None), id=unknown" );
    Scene00042( player );
  }
  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00042: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00043: Normal(None), id=unknown" );
    Scene00044( player );
  }
  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00044: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00045: Normal(None), id=unknown" );
    Scene00046( player );
  }
  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00046: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00047: Normal(None), id=unknown" );
    Scene00048( player );
  }
  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00048: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00049: Normal(None), id=unknown" );
    Scene00050( player );
  }
  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00050: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00051: Normal(Talk, TargetCanMove), id=WHEISKAET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00052: Normal(None), id=unknown" );
    Scene00053( player );
  }
  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00053: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 53, NONE, callback );
  }
  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchFalse]Scene00054: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00055: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00056( player );
    };
    player.playScene( getId(), 55, NONE, callback );
  }
  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00056: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00057: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00058( player );
    };
    player.playScene( getId(), 57, NONE, callback );
  }
  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00058: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00059: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00060: Normal(None), id=unknown" );
    Scene00061( player );
  }
  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00061: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00062: Normal(None), id=unknown" );
  }

  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00063: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 63, NONE, callback );
  }

  void Scene00064( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00064: Normal(None), id=unknown" );
    Scene00065( player );
  }
  void Scene00065( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00065: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00066( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00066: Normal(None), id=unknown" );
    Scene00067( player );
  }
  void Scene00067( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00067: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00068( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00068: Normal(None), id=unknown" );
    Scene00069( player );
  }
  void Scene00069( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00069: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00070( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00070: Normal(None), id=unknown" );
    Scene00071( player );
  }
  void Scene00071( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00071: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00072( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00072: Normal(None), id=unknown" );
    Scene00073( player );
  }
  void Scene00073( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00073: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00074( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00074: Normal(None), id=unknown" );
    Scene00075( player );
  }
  void Scene00075( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00075: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 75, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00076( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00076: Normal(None), id=unknown" );
  }

  void Scene00077( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00077: Normal(Talk, TargetCanMove), id=NPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 77, NONE, callback );
  }

  void Scene00078( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00078: Normal(None), id=unknown" );
  }

  void Scene00079( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00079: Normal(Talk, TargetCanMove), id=UODHNUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 79, NONE, callback );
  }

  void Scene00080( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00080: Normal(Talk, TargetCanMove), id=LANDENEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 80, NONE, callback );
  }

  void Scene00081( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00081: Normal(Talk, TargetCanMove), id=BRAYFLOX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 81, NONE, callback );
  }

  void Scene00082( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00082: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 82, NONE, callback );
  }

  void Scene00083( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00083: Normal(None), id=unknown" );
    Scene00084( player );
  }
  void Scene00084( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00084: Normal(None), id=unknown" );
  }

  void Scene00085( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00085: Normal(None), id=unknown" );
    Scene00086( player );
  }
  void Scene00086( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00086: Normal(None), id=unknown" );
  }

  void Scene00087( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00087: Normal(None), id=unknown" );
    Scene00088( player );
  }
  void Scene00088( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00088: Normal(None), id=unknown" );
  }

  void Scene00089( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00089: Normal(None), id=unknown" );
    Scene00090( player );
  }
  void Scene00090( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00090: Normal(None), id=unknown" );
  }

  void Scene00091( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling Scene00091: Normal(None), id=unknown" );
    Scene00092( player );
  }
  void Scene00092( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb314:66391 calling [BranchTrue]Scene00092: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb314 );
