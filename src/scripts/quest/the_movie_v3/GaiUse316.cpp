// FFXIVTheMovie.ParserV3.6
// id hint used:
//_ACTOR3 = B
//_ACTOR3B = 2|2
//_ACTOR4 = B
//_ACTOR4B = 2|2
//_ACTOR5 = B
//_ACTOR5B = 2|2
//_ACTOR6 = B
//_ACTOR6B = 2|2
//_ACTOR10 = B
//_ACTOR10B = 5|2
//_ACTOR11 = B
//_ACTOR11B = 5|2
//_ACTOR12 = B
//_ACTOR12B = 5|2
//_ACTOR17 = B
//_ACTOR17B = 8|2
//_ACTOR18 = B
//_ACTOR18B = 8|2
//_ACTOR19 = B
//_ACTOR19B = 8|2
//_ACTOR20 = B
//_ACTOR20B = 8|2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse316 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse316() : Sapphire::ScriptAPI::EventScript( 66993 ){}; 
  ~GaiUse316() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 1 entries
  //SEQ_4, 1 entries
  //SEQ_5, 5 entries
  //SEQ_6, 3 entries
  //SEQ_7, 1 entries
  //SEQ_8, 5 entries
  //SEQ_9, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1009021
  //ACTOR1 = 1009128
  //ACTOR10 = 1009139
  //ACTOR11 = 1000248
  //ACTOR12 = 1006263
  //ACTOR13 = 1009140
  //ACTOR14 = 1009131
  //ACTOR15 = 1009132
  //ACTOR16 = 1009135
  //ACTOR17 = 1009136
  //ACTOR18 = 1001679
  //ACTOR19 = 1001657
  //ACTOR2 = 1009133
  //ACTOR20 = 1001691
  //ACTOR3 = 1003282
  //ACTOR4 = 1000915
  //ACTOR5 = 1000918
  //ACTOR6 = 1001000
  //ACTOR7 = 1009129
  //ACTOR8 = 1009130
  //ACTOR9 = 1009138
  //CUTSCENEN01 = 538
  //LOCACTION1 = 1041
  //LOCACTOR0 = 1004145
  //LOCFACE1 = 605
  //LOCFACE2 = 617

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 2:
      {
        if( param1 == 1009133 || param2 == 1009133 ) // ACTOR2 = RIOL
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=RIOL
          }
          break;
        }
        if( param1 == 1003282 || param2 == 1003282 ) // ACTOR3 = REYNER, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=REYNER
          }
          else
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=REYNER
          }
          break;
        }
        if( param1 == 1000915 || param2 == 1000915 ) // ACTOR4 = CARVALLAIN, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CARVALLAIN
          }
          else
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CARVALLAIN
          }
          break;
        }
        if( param1 == 1000918 || param2 == 1000918 ) // ACTOR5 = RHOSWEN, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=RHOSWEN
          }
          else
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=RHOSWEN
          }
          break;
        }
        if( param1 == 1001000 || param2 == 1001000 ) // ACTOR6 = HNAANZA, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HNAANZA
          }
          else
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HNAANZA
          }
          break;
        }
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00012( player ); // Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 4:
      {
        if( type != 2 ) Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 5:
      {
        if( param1 == 1009138 || param2 == 1009138 ) // ACTOR9 = LAURENTIUS
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=LAURENTIUS
          }
          break;
        }
        if( param1 == 1009139 || param2 == 1009139 ) // ACTOR10 = ALIANNE, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALIANNE
          }
          else
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALIANNE
          }
          break;
        }
        if( param1 == 1000248 || param2 == 1000248 ) // ACTOR11 = CEINGULED, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=CEINGULED
          }
          else
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CEINGULED
          }
          break;
        }
        if( param1 == 1006263 || param2 == 1006263 ) // ACTOR12 = URSANDEL, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=URSANDEL
          }
          else
          {
            Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=URSANDEL
          }
          break;
        }
        if( param1 == 1009140 || param2 == 1009140 ) // ACTOR13 = ISILDAURE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ISILDAURE
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1009131 || param2 == 1009131 ) // ACTOR14 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1009139 || param2 == 1009139 ) // ACTOR10 = ALIANNE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1009140 || param2 == 1009140 ) // ACTOR13 = ISILDAURE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ISILDAURE
          break;
        }
        break;
      }
      case 7:
      {
        if( type != 2 ) Scene00025( player ); // Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 8:
      {
        if( param1 == 1009135 || param2 == 1009135 ) // ACTOR16 = WILRED
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=WILRED
          }
          break;
        }
        if( param1 == 1009136 || param2 == 1009136 ) // ACTOR17 = OURCEN, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=OURCEN
          }
          else
          {
            Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=OURCEN
          }
          break;
        }
        if( param1 == 1001679 || param2 == 1001679 ) // ACTOR18 = SYNTGOHT, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=SYNTGOHT
          }
          else
          {
            Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=SYNTGOHT
          }
          break;
        }
        if( param1 == 1001657 || param2 == 1001657 ) // ACTOR19 = LANDEBERT, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=LANDEBERT
          }
          else
          {
            Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=LANDEBERT
          }
          break;
        }
        if( param1 == 1001691 || param2 == 1001691 ) // ACTOR20 = YELLOWMOON, CB=2
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YELLOWMOON
          }
          else
          {
            Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=YELLOWMOON
          }
          break;
        }
        break;
      }
      case 9:
      {
        if( param1 == 1009132 || param2 == 1009132 ) // ACTOR15 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00036: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1009136 || param2 == 1009136 ) // ACTOR17 = OURCEN
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=OURCEN
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00038( player ); // Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
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
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.setQuestBitFlag8( getId(), 5, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
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
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.setQuestBitFlag8( getId(), 5, false );
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
    player.sendDebug( "GaiUse316:66993 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse316:66993 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, AutoFadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 5, Flag8(1)=True
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 5, Flag8(2)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00004: Normal(Talk, TargetCanMove), id=REYNER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR3, UI8AL = 5, Flag8(2)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00005: Normal(Talk, TargetCanMove), id=REYNER" );
    player.playScene( getId(), 5, NONE, nullptr );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 5, Flag8(3)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00006: Normal(Talk, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 5, Flag8(3)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00007: Normal(Talk, TargetCanMove), id=CARVALLAIN" );
    player.playScene( getId(), 7, NONE, nullptr );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 5, Flag8(4)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00008: Normal(Talk, TargetCanMove), id=RHOSWEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR5, UI8AL = 5, Flag8(4)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00009: Normal(Talk, TargetCanMove), id=RHOSWEN" );
    player.playScene( getId(), 9, NONE, nullptr );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 5, Flag8(5)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00010: Normal(Talk, TargetCanMove), id=HNAANZA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR6, UI8AL = 5, Flag8(5)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00011: Normal(Talk, TargetCanMove), id=HNAANZA" );
    player.playScene( getId(), 11, NONE, nullptr );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_4: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_5: ACTOR9, UI8AL = 4, Flag8(1)=True
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00014: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
        player.setQuestBitFlag8( getId(), 1, true );
        checkProgressSeq5( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_5: ACTOR10, UI8AL = 4, Flag8(2)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00015: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player ) //SEQ_5: ACTOR10, UI8AL = 4, Flag8(2)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00016: Normal(Talk, TargetCanMove), id=ALIANNE" );
    player.playScene( getId(), 16, NONE, nullptr );
  }

  void Scene00017( Entity::Player& player ) //SEQ_5: ACTOR11, UI8AL = 4, Flag8(3)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00017: Normal(Talk, TargetCanMove), id=CEINGULED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player ) //SEQ_5: ACTOR11, UI8AL = 4, Flag8(3)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00018: Normal(Talk, TargetCanMove), id=CEINGULED" );
    player.playScene( getId(), 18, NONE, nullptr );
  }

  void Scene00019( Entity::Player& player ) //SEQ_5: ACTOR12, UI8AL = 4, Flag8(4)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00019: Normal(Talk, TargetCanMove), id=URSANDEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player ) //SEQ_5: ACTOR12, UI8AL = 4, Flag8(4)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00020: Normal(Talk, TargetCanMove), id=URSANDEL" );
    player.playScene( getId(), 20, NONE, nullptr );
  }

  void Scene00021( Entity::Player& player ) //SEQ_5: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00021: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_6: ACTOR14, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_6: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00023: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_6: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00024: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_7: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_8: ACTOR16, UI8AL = 5, Flag8(1)=True
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_8: ACTOR17, UI8AL = 5, Flag8(2)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00027: Normal(Talk, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player ) //SEQ_8: ACTOR17, UI8AL = 5, Flag8(2)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00028: Normal(Talk, TargetCanMove), id=OURCEN" );
    player.playScene( getId(), 28, NONE, nullptr );
  }

  void Scene00029( Entity::Player& player ) //SEQ_8: ACTOR18, UI8AL = 5, Flag8(3)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00029: Normal(Talk, TargetCanMove), id=SYNTGOHT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00030( Entity::Player& player ) //SEQ_8: ACTOR18, UI8AL = 5, Flag8(3)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00030: Normal(Talk, TargetCanMove), id=SYNTGOHT" );
    player.playScene( getId(), 30, NONE, nullptr );
  }

  void Scene00031( Entity::Player& player ) //SEQ_8: ACTOR19, UI8AL = 5, Flag8(4)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00031: Normal(Talk, TargetCanMove), id=LANDEBERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }
  void Scene00032( Entity::Player& player ) //SEQ_8: ACTOR19, UI8AL = 5, Flag8(4)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00032: Normal(Talk, TargetCanMove), id=LANDEBERT" );
    player.playScene( getId(), 32, NONE, nullptr );
  }

  void Scene00033( Entity::Player& player ) //SEQ_8: ACTOR20, UI8AL = 5, Flag8(5)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00033: Normal(Talk, TargetCanMove), id=YELLOWMOON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }
  void Scene00034( Entity::Player& player ) //SEQ_8: ACTOR20, UI8AL = 5, Flag8(5)=True, Branch
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00034: Normal(Talk, TargetCanMove), id=YELLOWMOON" );
    player.playScene( getId(), 34, NONE, nullptr );
  }

  void Scene00035( Entity::Player& player ) //SEQ_9: ACTOR15, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00035: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00036( player );
    };
    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00036( Entity::Player& player ) //SEQ_9: ACTOR15, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00036: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq9( player );
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_9: ACTOR17, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00037: Normal(Talk, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 38, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse316 );
