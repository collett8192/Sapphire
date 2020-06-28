// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc406 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc406() : Sapphire::ScriptAPI::EventScript( 66517 ){}; 
  ~GaiUsc406() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 6 entries
  //SEQ_6, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1006518
  //ACTOR1 = 1006519
  //ACTOR2 = 1006521
  //EOBJECT0 = 2002196
  //EOBJECT1 = 2002681
  //EOBJECT2 = 2002682
  //EOBJECT3 = 2002683
  //EOBJECT4 = 2002684
  //EOBJECT5 = 2002685
  //EOBJECT6 = 2002197
  //EOBJECT7 = 2002198
  //EOBJECT8 = 2002199
  //EOBJECT9 = 2002200
  //EVENTACTIONLOOKOUTLONG = 41
  //EVENTACTIONSEARCH = 1
  //LOCACTION1 = 936
  //LOCACTION2 = 985
  //LOCACTION3 = 1002
  //LOCACTOR0 = 1003837
  //LOCACTOR1 = 1003855
  //LOCBGM1 = 93
  //LOCPOSACTOR0 = 4322708
  //LOCPOSACTOR1 = 4273899
  //LOCSE1 = 42
  //LOCTALKSHAPE1 = 6

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIERREMONS
        break;
      }
      case 1:
      {
        if( actor == 2002196 || actorId == 2002196 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 2002681 || actorId == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          // +Callback Scene00005: Normal(None), id=unknown
        }
        if( actor == 2002682 || actorId == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
        }
        if( actor == 2002683 || actorId == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          // +Callback Scene00009: Normal(None), id=unknown
        }
        if( actor == 2002684 || actorId == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(None), id=unknown
        }
        if( actor == 2002685 || actorId == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 2002197 || actorId == 2002197 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
            // +Callback Scene00015: Normal(None), id=unknown
          }
        }
        if( actor == 2002681 || actorId == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          // +Callback Scene00017: Normal(None), id=unknown
        }
        if( actor == 2002682 || actorId == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(None), id=unknown
        }
        if( actor == 2002683 || actorId == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(None), id=unknown
        }
        if( actor == 2002684 || actorId == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          // +Callback Scene00023: Normal(None), id=unknown
        }
        if( actor == 2002685 || actorId == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          // +Callback Scene00025: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 2002198 || actorId == 2002198 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(None), id=unknown
            // +Callback Scene00027: Normal(None), id=unknown
          }
        }
        if( actor == 2002681 || actorId == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          // +Callback Scene00029: Normal(None), id=unknown
        }
        if( actor == 2002682 || actorId == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          // +Callback Scene00031: Normal(None), id=unknown
        }
        if( actor == 2002683 || actorId == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          // +Callback Scene00033: Normal(None), id=unknown
        }
        if( actor == 2002684 || actorId == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          // +Callback Scene00035: Normal(None), id=unknown
        }
        if( actor == 2002685 || actorId == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          // +Callback Scene00037: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( actor == 2002199 || actorId == 2002199 ) // EOBJECT8 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00038( player ); // Scene00038: Normal(None), id=unknown
            // +Callback Scene00039: Normal(None), id=unknown
          }
        }
        if( actor == 2002681 || actorId == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          // +Callback Scene00041: Normal(None), id=unknown
        }
        if( actor == 2002682 || actorId == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          // +Callback Scene00043: Normal(None), id=unknown
        }
        if( actor == 2002683 || actorId == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
          // +Callback Scene00045: Normal(None), id=unknown
        }
        if( actor == 2002684 || actorId == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
          // +Callback Scene00047: Normal(None), id=unknown
        }
        if( actor == 2002685 || actorId == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          // +Callback Scene00049: Normal(None), id=unknown
        }
        break;
      }
      case 5:
      {
        if( actor == 2002200 || actorId == 2002200 ) // EOBJECT9 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00050( player ); // Scene00050: Normal(None), id=unknown
            // +Callback Scene00051: Normal(None), id=unknown
          }
        }
        if( actor == 2002681 || actorId == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
          // +Callback Scene00053: Normal(None), id=unknown
        }
        if( actor == 2002682 || actorId == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
          // +Callback Scene00055: Normal(None), id=unknown
        }
        if( actor == 2002683 || actorId == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
          // +Callback Scene00057: Normal(None), id=unknown
        }
        if( actor == 2002684 || actorId == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(None), id=unknown
          // +Callback Scene00059: Normal(None), id=unknown
        }
        if( actor == 2002685 || actorId == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00060( player ); // Scene00060: Normal(None), id=unknown
          // +Callback Scene00061: Normal(None), id=unknown
        }
        break;
      }
      case 6:
      {
        if( actor == 1006519 || actorId == 1006519 ) // ACTOR1 = WEDGE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00062( player ); // Scene00062: Normal(Talk, FadeIn, TargetCanMove), id=WEDGE
          }
        }
        if( actor == 2002681 || actorId == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00063( player ); // Scene00063: Normal(None), id=unknown
          // +Callback Scene00064: Normal(None), id=unknown
        }
        if( actor == 2002682 || actorId == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00065( player ); // Scene00065: Normal(None), id=unknown
          // +Callback Scene00066: Normal(None), id=unknown
        }
        if( actor == 2002683 || actorId == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00067( player ); // Scene00067: Normal(None), id=unknown
          // +Callback Scene00068: Normal(None), id=unknown
        }
        if( actor == 2002684 || actorId == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00069( player ); // Scene00069: Normal(None), id=unknown
          // +Callback Scene00070: Normal(None), id=unknown
        }
        if( actor == 2002685 || actorId == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00071( player ); // Scene00071: Normal(None), id=unknown
          // +Callback Scene00072: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006521 || actorId == 1006521 ) // ACTOR2 = ABELIE
        {
          Scene00073( player ); // Scene00073: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ABELIE
        }
        if( actor == 2002681 || actorId == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00074( player ); // Scene00074: Normal(None), id=unknown
          // +Callback Scene00075: Normal(None), id=unknown
        }
        if( actor == 2002682 || actorId == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00076( player ); // Scene00076: Normal(None), id=unknown
          // +Callback Scene00077: Normal(None), id=unknown
        }
        if( actor == 2002683 || actorId == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00078( player ); // Scene00078: Normal(None), id=unknown
          // +Callback Scene00079: Normal(None), id=unknown
        }
        if( actor == 2002684 || actorId == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00080( player ); // Scene00080: Normal(None), id=unknown
          // +Callback Scene00081: Normal(None), id=unknown
        }
        if( actor == 2002685 || actorId == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00082( player ); // Scene00082: Normal(None), id=unknown
          // +Callback Scene00083: Normal(None), id=unknown
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
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIERREMONS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00013: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00017: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00021: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00022: Normal(None), id=unknown" );
    Scene00023( player );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00023: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00024: Normal(None), id=unknown" );
    Scene00025( player );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00025: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00026: Normal(None), id=unknown" );
    Scene00027( player );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00027: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00028: Normal(None), id=unknown" );
    Scene00029( player );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00029: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00030: Normal(None), id=unknown" );
    Scene00031( player );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00031: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00032: Normal(None), id=unknown" );
    Scene00033( player );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00033: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00034: Normal(None), id=unknown" );
    Scene00035( player );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00035: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00036: Normal(None), id=unknown" );
    Scene00037( player );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00037: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00038: Normal(None), id=unknown" );
    Scene00039( player );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00039: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00040: Normal(None), id=unknown" );
    Scene00041( player );
  }
  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00041: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00042: Normal(None), id=unknown" );
    Scene00043( player );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00043: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00044: Normal(None), id=unknown" );
    Scene00045( player );
  }
  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00045: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00046: Normal(None), id=unknown" );
    Scene00047( player );
  }
  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00047: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00048: Normal(None), id=unknown" );
    Scene00049( player );
  }
  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00049: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00050: Normal(None), id=unknown" );
    Scene00051( player );
  }
  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00051: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq5( player );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00052: Normal(None), id=unknown" );
    Scene00053( player );
  }
  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00053: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00054: Normal(None), id=unknown" );
    Scene00055( player );
  }
  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00055: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00056: Normal(None), id=unknown" );
    Scene00057( player );
  }
  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00057: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00058: Normal(None), id=unknown" );
    Scene00059( player );
  }
  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00059: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00060: Normal(None), id=unknown" );
    Scene00061( player );
  }
  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00061: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00062: Normal(Talk, FadeIn, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 62, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00063: Normal(None), id=unknown" );
    Scene00064( player );
  }
  void Scene00064( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00064: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00065( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00065: Normal(None), id=unknown" );
    Scene00066( player );
  }
  void Scene00066( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00066: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00067( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00067: Normal(None), id=unknown" );
    Scene00068( player );
  }
  void Scene00068( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00068: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00069( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00069: Normal(None), id=unknown" );
    Scene00070( player );
  }
  void Scene00070( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00070: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00071( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00071: Normal(None), id=unknown" );
    Scene00072( player );
  }
  void Scene00072( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00072: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00073( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00073: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ABELIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 73, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00074( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00074: Normal(None), id=unknown" );
    Scene00075( player );
  }
  void Scene00075( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00075: Normal(None), id=unknown" );
  }

  void Scene00076( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00076: Normal(None), id=unknown" );
    Scene00077( player );
  }
  void Scene00077( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00077: Normal(None), id=unknown" );
  }

  void Scene00078( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00078: Normal(None), id=unknown" );
    Scene00079( player );
  }
  void Scene00079( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00079: Normal(None), id=unknown" );
  }

  void Scene00080( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00080: Normal(None), id=unknown" );
    Scene00081( player );
  }
  void Scene00081( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00081: Normal(None), id=unknown" );
  }

  void Scene00082( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00082: Normal(None), id=unknown" );
    Scene00083( player );
  }
  void Scene00083( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc406:66517 calling [BranchTrue]Scene00083: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsc406 );
