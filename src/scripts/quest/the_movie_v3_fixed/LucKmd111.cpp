// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmd111 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmd111() : Sapphire::ScriptAPI::EventScript( 69152 ){}; 
  ~LucKmd111() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 2 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 9 entries
  //SEQ_5, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1029755
  //ACTOR1 = 1029649
  //ACTOR2 = 1029650
  //ACTOR3 = 1029651
  //ACTOR4 = 1029754
  //ACTOR5 = 1029756
  //ACTOR6 = 1029757
  //ACTOR7 = 1029758
  //EOBJECT0 = 2010541
  //EOBJECT1 = 2010542
  //EOBJECT2 = 2010543
  //EOBJECT3 = 2009913
  //EOBJECT4 = 2009914
  //EOBJECT5 = 2009915
  //EVENTACTION0 = 21
  //ITEM0 = 2002561
  //LOCACTORGUTHJON = 1028148
  //LOCACTORTHANCRED = 1026569
  //LOCBINDACTOR0 = 7937274
  //LOCBINDACTOR1 = 7935071
  //STATUS0 = 1152

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029755 || param2 == 1029755 ) // ACTOR0 = THANCRED
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029649 || param2 == 1029649 ) // ACTOR1 = URIANGER
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029650 || param2 == 1029650 ) // ACTOR2 = RYNE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029651 || param2 == 1029651 ) // ACTOR3 = THAFFE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029754 || param2 == 1029754 ) // ACTOR4 = MAGNUS
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029756 || param2 == 1029756 ) // ACTOR5 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1029754 || param2 == 1029754 ) // ACTOR4 = MAGNUS
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029757 || param2 == 1029757 ) // ACTOR6 = GUTHJON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=GUTHJON
          }
          break;
        }
        if( param1 == 1029754 || param2 == 1029754 ) // ACTOR4 = MAGNUS
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029758 || param2 == 1029758 ) // ACTOR7 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2010541 || param2 == 2010541 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010542 || param2 == 2010542 ) // EOBJECT1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010543 || param2 == 2010543 ) // EOBJECT2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1029758 || param2 == 1029758 ) // ACTOR7 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1029754 || param2 == 1029754 ) // ACTOR4 = MAGNUS
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029757 || param2 == 1029757 ) // ACTOR6 = GUTHJON
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=GUTHJON
          break;
        }
        if( param1 == 2010541 || param2 == 2010541 ) // EOBJECT0 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010542 || param2 == 2010542 ) // EOBJECT1 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010543 || param2 == 2010543 ) // EOBJECT2 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 2009913 || param2 == 2009913 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(SystemTalk, CanCancel), id=unknown
          }
          break;
        }
        if( param1 == 1029758 || param2 == 1029758 ) // ACTOR7 = THANCRED
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029754 || param2 == 1029754 ) // ACTOR4 = MAGNUS
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029757 || param2 == 1029757 ) // ACTOR6 = GUTHJON
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=GUTHJON
          break;
        }
        if( param1 == 2009914 || param2 == 2009914 ) // EOBJECT4 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(SystemTalk, CanCancel), id=unknown
          break;
        }
        if( param1 == 2009915 || param2 == 2009915 ) // EOBJECT5 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(SystemTalk, CanCancel), id=unknown
          break;
        }
        if( param1 == 2010541 || param2 == 2010541 ) // EOBJECT0 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010542 || param2 == 2010542 ) // EOBJECT1 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010543 || param2 == 2010543 ) // EOBJECT2 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      case 5:
      {
        if( param1 == 1029758 || param2 == 1029758 ) // ACTOR7 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00032( player ); // Scene00032: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00033: Normal(Talk, TargetCanMove, Menu), id=THANCRED
          }
          break;
        }
        if( param1 == 1029754 || param2 == 1029754 ) // ACTOR4 = MAGNUS
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029757 || param2 == 1029757 ) // ACTOR6 = GUTHJON
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=GUTHJON
          break;
        }
        if( param1 == 2010541 || param2 == 2010541 ) // EOBJECT0 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010542 || param2 == 2010542 ) // EOBJECT1 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010543 || param2 == 2010543 ) // EOBJECT2 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1029757 || param2 == 1029757 ) // ACTOR6 = GUTHJON
        {
          Scene00039( player ); // Scene00039: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00040: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUTHJON
          break;
        }
        if( param1 == 1029754 || param2 == 1029754 ) // ACTOR4 = MAGNUS
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029758 || param2 == 1029758 ) // ACTOR7 = THANCRED
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2010541 || param2 == 2010541 ) // EOBJECT0 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010542 || param2 == 2010542 ) // EOBJECT1 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010543 || param2 == 2010543 ) // EOBJECT2 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
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
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmd111:69152 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00002: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00003: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00004: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00005: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00007: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00009: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00014: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00015: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00016: Normal(Talk, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00021: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq4( player );
      }
    };
    player.addStatusEffectByIdIfNotExist( 1152, 1000, player, 0, true );
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00022: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00023: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00024: Normal(Talk, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00026: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq4( player );
      }
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00028: Normal(SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq4( player );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00029: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00030: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00031: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00032: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00033( player );
      }
    };
    player.playScene( getId(), 32, NONE, callback );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00033: Normal(Talk, TargetCanMove, Menu), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq5( player );
      }
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00034: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00035: Normal(Talk, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00036: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00038: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00039: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00040( player );
      }
    };
    player.playScene( getId(), 39, NONE, callback );
  }
  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00040: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUTHJON" );
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
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00041: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00042: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKmd111:69152 calling Scene00045: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKmd111 );
