// FFXIVTheMovie.ParserV3.6
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
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA
        break;
      }
      case 1:
      {
        if( param1 == 1006618 || param2 == 1006618 ) // ACTOR1 = URURUKOGURURU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=URURUKOGURURU
          }
          break;
        }
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=DAWSON
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=DAWSON
          }
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 2002452 || param2 == 2002452 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=DAWSON
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002666 || param2 == 2002666 ) // EOBJECT1 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002667 || param2 == 2002667 ) // EOBJECT2 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002668 || param2 == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 2002453 || param2 == 2002453 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=DAWSON
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002667 || param2 == 2002667 ) // EOBJECT2 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002668 || param2 == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002666 || param2 == 2002666 ) // EOBJECT1 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM1 = UI8BH max stack 1
      case 5:
      {
        if( param1 == 2002452 || param2 == 2002452 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00032( player ); // Scene00032: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=DAWSON
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002667 || param2 == 2002667 ) // EOBJECT2 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002668 || param2 == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002669 || param2 == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 6 event item ITEM1 = UI8BH max stack 1
      case 6:
      {
        if( param1 == 2002672 || param2 == 2002672 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00043( player ); // Scene00043: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=DAWSON
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002668 || param2 == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002669 || param2 == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00050( player ); // Scene00050: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002667 || param2 == 2002667 ) // EOBJECT2 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 7 event item ITEM2 = UI8BH max stack 1
      case 7:
      {
        if( param1 == 2002452 || param2 == 2002452 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00054( player ); // Scene00054: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00055( player ); // Scene00055: Normal(Talk, TargetCanMove), id=DAWSON
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002668 || param2 == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00059( player ); // Scene00059: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002669 || param2 == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00061( player ); // Scene00061: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002670 || param2 == 2002670 ) // EOBJECT7 = unknown
        {
          Scene00063( player ); // Scene00063: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 8 event item ITEM2 = UI8BH max stack 1
      case 8:
      {
        if( param1 == 2002673 || param2 == 2002673 ) // EOBJECT8 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00065( player ); // Scene00065: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00066( player ); // Scene00066: Normal(Talk, TargetCanMove), id=DAWSON
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00067( player ); // Scene00067: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00068( player ); // Scene00068: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002669 || param2 == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00070( player ); // Scene00070: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002670 || param2 == 2002670 ) // EOBJECT7 = unknown
        {
          Scene00072( player ); // Scene00072: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002668 || param2 == 2002668 ) // EOBJECT3 = unknown
        {
          Scene00074( player ); // Scene00074: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 9:
      {
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00075( player ); // Scene00075: Normal(Talk, TargetCanMove), id=DAWSON
          }
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00076( player ); // Scene00076: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00077( player ); // Scene00077: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002669 || param2 == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00079( player ); // Scene00079: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002670 || param2 == 2002670 ) // EOBJECT7 = unknown
        {
          Scene00081( player ); // Scene00081: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002671 || param2 == 2002671 ) // EOBJECT9 = unknown
        {
          Scene00083( player ); // Scene00083: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006618 || param2 == 1006618 ) // ACTOR1 = URURUKOGURURU
        {
          Scene00084( player ); // Scene00084: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URURUKOGURURU
          break;
        }
        if( param1 == 1006621 || param2 == 1006621 ) // ACTOR2 = DAWSON
        {
          Scene00085( player ); // Scene00085: Normal(Talk, TargetCanMove), id=DAWSON
          break;
        }
        if( param1 == 1007713 || param2 == 1007713 ) // ACTOR3 = unknown
        {
          Scene00086( player ); // Scene00086: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007714 || param2 == 1007714 ) // ACTOR4 = unknown
        {
          Scene00087( player ); // Scene00087: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002669 || param2 == 2002669 ) // EOBJECT5 = unknown
        {
          Scene00089( player ); // Scene00089: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002670 || param2 == 2002670 ) // EOBJECT7 = unknown
        {
          Scene00091( player ); // Scene00091: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002671 || param2 == 2002671 ) // EOBJECT9 = unknown
        {
          Scene00093( player ); // Scene00093: Normal(None), id=unknown
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
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
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
      player.setQuestUI8BH( getId(), 0 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 9 );
    }
  }
  void checkProgressSeq9( Entity::Player& player )
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
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00002: Normal(Talk, TargetCanMove), id=URURUKOGURURU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00003: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00006: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00011: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00021( Entity::Player& player ) //SEQ_4: EOBJECT4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00021: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq4( player );
  }

  void Scene00022( Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00022: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00026: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00028( Entity::Player& player ) //SEQ_4: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00028: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00030( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00030: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00032( Entity::Player& player ) //SEQ_5: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00032: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq5( player );
  }

  void Scene00033( Entity::Player& player ) //SEQ_5: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00033: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_5: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player ) //SEQ_5: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player ) //SEQ_5: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00039( Entity::Player& player ) //SEQ_5: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00039: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00041( Entity::Player& player ) //SEQ_5: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00041: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00043( Entity::Player& player ) //SEQ_6: EOBJECT6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00043: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq6( player );
  }

  void Scene00044( Entity::Player& player ) //SEQ_6: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00044: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player ) //SEQ_6: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player ) //SEQ_6: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player ) //SEQ_6: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00048: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00050( Entity::Player& player ) //SEQ_6: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00050: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00052( Entity::Player& player ) //SEQ_6: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00052: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00054( Entity::Player& player ) //SEQ_7: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00054: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq7( player );
  }

  void Scene00055( Entity::Player& player ) //SEQ_7: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00055: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 55, NONE, callback );
  }

  void Scene00056( Entity::Player& player ) //SEQ_7: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player ) //SEQ_7: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00057: Normal(None), id=unknown" );
  }

  void Scene00059( Entity::Player& player ) //SEQ_7: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00059: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00061( Entity::Player& player ) //SEQ_7: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00061: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00063( Entity::Player& player ) //SEQ_7: EOBJECT7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00063: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00065( Entity::Player& player ) //SEQ_8: EOBJECT8, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00065: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq8( player );
  }

  void Scene00066( Entity::Player& player ) //SEQ_8: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00066: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 66, NONE, callback );
  }

  void Scene00067( Entity::Player& player ) //SEQ_8: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00067: Normal(None), id=unknown" );
  }

  void Scene00068( Entity::Player& player ) //SEQ_8: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00068: Normal(None), id=unknown" );
  }

  void Scene00070( Entity::Player& player ) //SEQ_8: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00070: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00072( Entity::Player& player ) //SEQ_8: EOBJECT7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00072: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00074( Entity::Player& player ) //SEQ_8: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00074: Normal(None), id=unknown" );
    checkProgressSeq8( player );
  }

  void Scene00075( Entity::Player& player ) //SEQ_9: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00075: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq9( player );
    };
    player.playScene( getId(), 75, NONE, callback );
  }

  void Scene00076( Entity::Player& player ) //SEQ_9: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00076: Normal(None), id=unknown" );
  }

  void Scene00077( Entity::Player& player ) //SEQ_9: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00077: Normal(None), id=unknown" );
  }

  void Scene00079( Entity::Player& player ) //SEQ_9: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00079: Normal(None), id=unknown" );
    checkProgressSeq9( player );
  }

  void Scene00081( Entity::Player& player ) //SEQ_9: EOBJECT7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00081: Normal(None), id=unknown" );
    checkProgressSeq9( player );
  }

  void Scene00083( Entity::Player& player ) //SEQ_9: EOBJECT9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00083: Normal(None), id=unknown" );
    checkProgressSeq9( player );
  }

  void Scene00084( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00084: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URURUKOGURURU" );
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
    player.playScene( getId(), 84, NONE, callback );
  }

  void Scene00085( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00085: Normal(Talk, TargetCanMove), id=DAWSON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 85, NONE, callback );
  }

  void Scene00086( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00086: Normal(None), id=unknown" );
  }

  void Scene00087( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00087: Normal(None), id=unknown" );
  }

  void Scene00089( Entity::Player& player ) //SEQ_255: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00089: Normal(None), id=unknown" );
  }

  void Scene00091( Entity::Player& player ) //SEQ_255: EOBJECT7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00091: Normal(None), id=unknown" );
  }

  void Scene00093( Entity::Player& player ) //SEQ_255: EOBJECT9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc802:66562 calling Scene00093: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsc802 );
