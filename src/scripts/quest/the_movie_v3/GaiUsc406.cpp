// FFXIVTheMovie.ParserV3.6
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
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIERREMONS
        break;
      }
      case 1:
      {
        if( param1 == 2002196 || param2 == 2002196 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002681 || param2 == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002682 || param2 == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002683 || param2 == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002684 || param2 == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002685 || param2 == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2002197 || param2 == 2002197 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002681 || param2 == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002682 || param2 == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002683 || param2 == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002684 || param2 == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002685 || param2 == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2002198 || param2 == 2002198 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002681 || param2 == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002682 || param2 == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002683 || param2 == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002684 || param2 == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002685 || param2 == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2002199 || param2 == 2002199 ) // EOBJECT8 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00039( player ); // Scene00039: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002681 || param2 == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002682 || param2 == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002683 || param2 == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002684 || param2 == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002685 || param2 == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 2002200 || param2 == 2002200 ) // EOBJECT9 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00051( player ); // Scene00051: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002681 || param2 == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002682 || param2 == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002683 || param2 == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002684 || param2 == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00059( player ); // Scene00059: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002685 || param2 == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00061( player ); // Scene00061: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1006519 || param2 == 1006519 ) // ACTOR1 = WEDGE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00062( player ); // Scene00062: Normal(Talk, FadeIn, TargetCanMove), id=WEDGE
          }
          break;
        }
        if( param1 == 2002681 || param2 == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00064( player ); // Scene00064: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002682 || param2 == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00066( player ); // Scene00066: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002683 || param2 == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00068( player ); // Scene00068: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002684 || param2 == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00070( player ); // Scene00070: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002685 || param2 == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00072( player ); // Scene00072: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006521 || param2 == 1006521 ) // ACTOR2 = ABELIE
        {
          Scene00073( player ); // Scene00073: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ABELIE
          break;
        }
        if( param1 == 2002681 || param2 == 2002681 ) // EOBJECT1 = unknown
        {
          Scene00075( player ); // Scene00075: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002682 || param2 == 2002682 ) // EOBJECT2 = unknown
        {
          Scene00077( player ); // Scene00077: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002683 || param2 == 2002683 ) // EOBJECT3 = unknown
        {
          Scene00079( player ); // Scene00079: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002684 || param2 == 2002684 ) // EOBJECT4 = unknown
        {
          Scene00081( player ); // Scene00081: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002685 || param2 == 2002685 ) // EOBJECT5 = unknown
        {
          Scene00083( player ); // Scene00083: Normal(None), id=unknown
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
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
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PIERREMONS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: EOBJECT6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq2( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_2: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00021( Entity::Player& player ) //SEQ_2: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00023( Entity::Player& player ) //SEQ_2: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00023: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00025( Entity::Player& player ) //SEQ_2: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00027( Entity::Player& player ) //SEQ_3: EOBJECT7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00027: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq3( player );
  }

  void Scene00029( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00029: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00031( Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00031: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00033( Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00033: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00035( Entity::Player& player ) //SEQ_3: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00035: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00037( Entity::Player& player ) //SEQ_3: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00039( Entity::Player& player ) //SEQ_4: EOBJECT8, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00039: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq4( player );
  }

  void Scene00041( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00041: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00043( Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00043: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00045( Entity::Player& player ) //SEQ_4: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00045: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00047( Entity::Player& player ) //SEQ_4: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00047: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00049( Entity::Player& player ) //SEQ_4: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00049: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00051( Entity::Player& player ) //SEQ_5: EOBJECT9, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00051: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq5( player );
  }

  void Scene00053( Entity::Player& player ) //SEQ_5: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00053: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00055( Entity::Player& player ) //SEQ_5: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00055: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00057( Entity::Player& player ) //SEQ_5: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00057: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00059( Entity::Player& player ) //SEQ_5: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00059: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00061( Entity::Player& player ) //SEQ_5: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00061: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00062( Entity::Player& player ) //SEQ_6: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00062: Normal(Talk, FadeIn, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 62, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00064( Entity::Player& player ) //SEQ_6: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00064: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00066( Entity::Player& player ) //SEQ_6: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00066: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00068( Entity::Player& player ) //SEQ_6: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00068: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00070( Entity::Player& player ) //SEQ_6: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00070: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00072( Entity::Player& player ) //SEQ_6: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00072: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00073( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00073: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ABELIE" );
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
    player.playScene( getId(), 73, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00075( Entity::Player& player ) //SEQ_255: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00075: Normal(None), id=unknown" );
  }

  void Scene00077( Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00077: Normal(None), id=unknown" );
  }

  void Scene00079( Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00079: Normal(None), id=unknown" );
  }

  void Scene00081( Entity::Player& player ) //SEQ_255: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00081: Normal(None), id=unknown" );
  }

  void Scene00083( Entity::Player& player ) //SEQ_255: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc406:66517 calling Scene00083: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsc406 );
