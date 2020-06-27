// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc802 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc802() : Sapphire::ScriptAPI::EventScript( 66562 ){}; 
  ~GaiUsc802() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_3, 7 entries
  //SEQ_4, 7 entries
  //SEQ_5, 7 entries
  //SEQ_6, 7 entries
  //SEQ_7, 7 entries
  //SEQ_8, 7 entries
  //SEQ_9, 6 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1006614
  //ACTOR1 = 1006618
  //ACTOR2 = 1006621
  //ACTOR3 = 1007713
  //ACTOR4 = 1007714
  //EOBJECT0 = 2002452
  //EOBJECT1 = 2002666
  //EOBJECT2 = 2002667
  //EOBJECT3 = 2002668
  //EOBJECT4 = 2002453
  //EOBJECT5 = 2002669
  //EOBJECT6 = 2002672
  //EOBJECT7 = 2002670
  //EOBJECT8 = 2002673
  //EOBJECT9 = 2002671
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000781
  //ITEM1 = 2000869
  //ITEM2 = 2000870

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA
        break;
      }
      case 1:
      {
        if( actor == 1006618 || actorId == 1006618 ) // ACTOR1 = URURUKOGURURU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=URURUKOGURURU
          }
        }
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=DAWSON
          }
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( actor == 2002452 || actorId == 2002452 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
            // +Callback Scene00010: Normal(None), id=unknown
          }
        }
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 2002666 || actorId == 2002666 ) // EOBJECT1 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          // +Callback Scene00015: Normal(None), id=unknown
        }
        if( actor == 2002667 || actorId == 2002667 ) // EOBJECT2 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          // +Callback Scene00017: Normal(None), id=unknown
        }
        if( actor == 2002668 || actorId == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( actor == 2002453 || actorId == 2002453 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: NpcTrade(None), id=unknown
            // +Callback Scene00021: Normal(None), id=unknown
          }
        }
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
        }
        if( actor == 2002667 || actorId == 2002667 ) // EOBJECT2 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(None), id=unknown
        }
        if( actor == 2002668 || actorId == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          // +Callback Scene00028: Normal(None), id=unknown
        }
        if( actor == 2002666 || actorId == 2002666 ) // EOBJECT1 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          // +Callback Scene00030: Normal(None), id=unknown
        }
        break;
      }
      //seq 5 event item ITEM1 = UI8BH max stack 1
      case 5:
      {
        if( actor == 2002452 || actorId == 2002452 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: Normal(None), id=unknown
            // +Callback Scene00032: Normal(None), id=unknown
          }
        }
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        if( actor == 2002667 || actorId == 2002667 ) // EOBJECT2 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          // +Callback Scene00037: Normal(None), id=unknown
        }
        if( actor == 2002668 || actorId == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          // +Callback Scene00039: Normal(None), id=unknown
        }
        if( actor == 2002669 || actorId == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          // +Callback Scene00041: Normal(None), id=unknown
        }
        break;
      }
      //seq 6 event item ITEM1 = UI8BH max stack 1
      case 6:
      {
        if( actor == 2002672 || actorId == 2002672 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00042( player ); // Scene00042: NpcTrade(None), id=unknown
            // +Callback Scene00043: Normal(None), id=unknown
          }
        }
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
        }
        if( actor == 2002668 || actorId == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
          // +Callback Scene00048: Normal(None), id=unknown
        }
        if( actor == 2002669 || actorId == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(None), id=unknown
          // +Callback Scene00050: Normal(None), id=unknown
        }
        if( actor == 2002667 || actorId == 2002667 ) // EOBJECT2 = unknown
        {
          Scene00051( player ); // Scene00051: Normal(None), id=unknown
          // +Callback Scene00052: Normal(None), id=unknown
        }
        break;
      }
      //seq 7 event item ITEM2 = UI8BH max stack 1
      case 7:
      {
        if( actor == 2002452 || actorId == 2002452 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00053( player ); // Scene00053: Normal(None), id=unknown
            // +Callback Scene00054: Normal(None), id=unknown
          }
        }
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
        }
        if( actor == 2002668 || actorId == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(None), id=unknown
          // +Callback Scene00059: Normal(None), id=unknown
        }
        if( actor == 2002669 || actorId == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00060( player ); // Scene00060: Normal(None), id=unknown
          // +Callback Scene00061: Normal(None), id=unknown
        }
        if( actor == 2002670 || actorId == 2002670 ) // EOBJECT7 = unknown
        {
          Scene00062( player ); // Scene00062: Normal(None), id=unknown
          // +Callback Scene00063: Normal(None), id=unknown
        }
        break;
      }
      //seq 8 event item ITEM2 = UI8BH max stack 1
      case 8:
      {
        if( actor == 2002673 || actorId == 2002673 ) // EOBJECT8 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00064( player ); // Scene00064: NpcTrade(None), id=unknown
            // +Callback Scene00065: Normal(None), id=unknown
          }
        }
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00066( player ); // Scene00066: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00067( player ); // Scene00067: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00068( player ); // Scene00068: Normal(None), id=unknown
        }
        if( actor == 2002669 || actorId == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00069( player ); // Scene00069: Normal(None), id=unknown
          // +Callback Scene00070: Normal(None), id=unknown
        }
        if( actor == 2002670 || actorId == 2002670 ) // EOBJECT7 = unknown
        {
          Scene00071( player ); // Scene00071: Normal(None), id=unknown
          // +Callback Scene00072: Normal(None), id=unknown
        }
        if( actor == 2002668 || actorId == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00073( player ); // Scene00073: Normal(None), id=unknown
          // +Callback Scene00074: Normal(None), id=unknown
        }
        break;
      }
      case 9:
      {
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00075( player ); // Scene00075: Normal(Talk, TargetCanMove), id=DAWSON
          }
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00076( player ); // Scene00076: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00077( player ); // Scene00077: Normal(None), id=unknown
        }
        if( actor == 2002669 || actorId == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00078( player ); // Scene00078: Normal(None), id=unknown
          // +Callback Scene00079: Normal(None), id=unknown
        }
        if( actor == 2002670 || actorId == 2002670 ) // EOBJECT7 = unknown
        {
          Scene00080( player ); // Scene00080: Normal(None), id=unknown
          // +Callback Scene00081: Normal(None), id=unknown
        }
        if( actor == 2002671 || actorId == 2002671 ) // EOBJECT9 = unknown
        {
          Scene00082( player ); // Scene00082: Normal(None), id=unknown
          // +Callback Scene00083: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006618 || actorId == 1006618 ) // ACTOR1 = URURUKOGURURU
        {
          Scene00084( player ); // Scene00084: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URURUKOGURURU
        }
        if( actor == 1006621 || actorId == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00085( player ); // Scene00085: Normal(Talk, TargetCanMove), id=DAWSON
        }
        if( actor == 1007713 || actorId == 1007713 ) // ACTOR3 = unknown
        {
          Scene00086( player ); // Scene00086: Normal(None), id=unknown
        }
        if( actor == 1007714 || actorId == 1007714 ) // ACTOR4 = unknown
        {
          Scene00087( player ); // Scene00087: Normal(None), id=unknown
        }
        if( actor == 2002669 || actorId == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00088( player ); // Scene00088: Normal(None), id=unknown
          // +Callback Scene00089: Normal(None), id=unknown
        }
        if( actor == 2002670 || actorId == 2002670 ) // EOBJECT7 = unknown
        {
          Scene00090( player ); // Scene00090: Normal(None), id=unknown
          // +Callback Scene00091: Normal(None), id=unknown
        }
        if( actor == 2002671 || actorId == 2002671 ) // EOBJECT9 = unknown
        {
          Scene00092( player ); // Scene00092: Normal(None), id=unknown
          // +Callback Scene00093: Normal(None), id=unknown
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
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 6 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 8 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 9 );
    }
  }
  void checkProgressSeq9( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00002: Normal(Talk, TargetCanMove), id=URURUKOGURURU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00003: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00006: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00011: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00017: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00020: NpcTrade(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00021: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00022: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00026: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00027: Normal(None), id=unknown" );
    Scene00028( player );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00028: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00029: Normal(None), id=unknown" );
    Scene00030( player );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00030: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00031: Normal(None), id=unknown" );
    Scene00032( player );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00032: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq5( player );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00033: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00036: Normal(None), id=unknown" );
    Scene00037( player );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00037: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00038: Normal(None), id=unknown" );
    Scene00039( player );
  }
  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00039: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00040: Normal(None), id=unknown" );
    Scene00041( player );
  }
  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00041: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00042: NpcTrade(None), id=unknown" );
    Scene00043( player );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00043: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq6( player );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00044: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00047: Normal(None), id=unknown" );
    Scene00048( player );
  }
  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00048: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00049: Normal(None), id=unknown" );
    Scene00050( player );
  }
  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00050: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00051: Normal(None), id=unknown" );
    Scene00052( player );
  }
  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00052: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00053: Normal(None), id=unknown" );
    Scene00054( player );
  }
  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00054: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq7( player );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00055: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00057: Normal(None), id=unknown" );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00058: Normal(None), id=unknown" );
    Scene00059( player );
  }
  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00059: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00060: Normal(None), id=unknown" );
    Scene00061( player );
  }
  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00061: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00062: Normal(None), id=unknown" );
    Scene00063( player );
  }
  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00063: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00064( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00064: NpcTrade(None), id=unknown" );
    Scene00065( player );
  }
  void Scene00065( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00065: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq8( player );
  }

  void Scene00066( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00066: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 66, NONE, callback );
  }

  void Scene00067( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00067: Normal(None), id=unknown" );
  }

  void Scene00068( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00068: Normal(None), id=unknown" );
  }

  void Scene00069( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00069: Normal(None), id=unknown" );
    Scene00070( player );
  }
  void Scene00070( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00070: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00071( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00071: Normal(None), id=unknown" );
    Scene00072( player );
  }
  void Scene00072( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00072: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00073( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00073: Normal(None), id=unknown" );
    Scene00074( player );
  }
  void Scene00074( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00074: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00075( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00075: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq9( player );
    };
    player.playScene( getId(), 75, NONE, callback );
  }

  void Scene00076( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00076: Normal(None), id=unknown" );
  }

  void Scene00077( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00077: Normal(None), id=unknown" );
  }

  void Scene00078( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00078: Normal(None), id=unknown" );
    Scene00079( player );
  }
  void Scene00079( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00079: Normal(None), id=unknown" );
    checkProgressSeq9( player );
  }

  void Scene00080( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00080: Normal(None), id=unknown" );
    Scene00081( player );
  }
  void Scene00081( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00081: Normal(None), id=unknown" );
    checkProgressSeq9( player );
  }

  void Scene00082( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00082: Normal(None), id=unknown" );
    Scene00083( player );
  }
  void Scene00083( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00083: Normal(None), id=unknown" );
    checkProgressSeq9( player );
  }

  void Scene00084( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00084: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URURUKOGURURU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 84, NONE, callback );
  }

  void Scene00085( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00085: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 85, NONE, callback );
  }

  void Scene00086( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00086: Normal(None), id=unknown" );
  }

  void Scene00087( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00087: Normal(None), id=unknown" );
  }

  void Scene00088( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00088: Normal(None), id=unknown" );
    Scene00089( player );
  }
  void Scene00089( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00089: Normal(None), id=unknown" );
  }

  void Scene00090( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00090: Normal(None), id=unknown" );
    Scene00091( player );
  }
  void Scene00091( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00091: Normal(None), id=unknown" );
  }

  void Scene00092( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00092: Normal(None), id=unknown" );
    Scene00093( player );
  }
  void Scene00093( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc802:66562 calling [BranchTrue]Scene00093: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsc802 );
