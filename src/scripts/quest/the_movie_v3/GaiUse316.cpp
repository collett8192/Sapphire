// FFXIVTheMovie.ParserV3
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
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 2:
      {
        if( actor == 1009133 || actorId == 1009133 ) // ACTOR2 = RIOL
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=RIOL
          }
        }
        if( actor == 1003282 || actorId == 1003282 ) // ACTOR3 = REYNER
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=REYNER
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=REYNER
          }
        }
        if( actor == 1000915 || actorId == 1000915 ) // ACTOR4 = CARVALLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CARVALLAIN
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=CARVALLAIN
          }
        }
        if( actor == 1000918 || actorId == 1000918 ) // ACTOR5 = RHOSWEN
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=RHOSWEN
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=RHOSWEN
          }
        }
        if( actor == 1001000 || actorId == 1001000 ) // ACTOR6 = HNAANZA
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HNAANZA
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=HNAANZA
          }
        }
        break;
      }
      case 3:
      {
        Scene00012( player ); // Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 4:
      {
        Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 5:
      {
        if( actor == 1009138 || actorId == 1009138 ) // ACTOR9 = LAURENTIUS
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS
          }
        }
        if( actor == 1009139 || actorId == 1009139 ) // ACTOR10 = ALIANNE
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALIANNE
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=ALIANNE
          }
        }
        if( actor == 1000248 || actorId == 1000248 ) // ACTOR11 = CEINGULED
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=CEINGULED
            // +Callback Scene00018: Normal(Talk, TargetCanMove), id=CEINGULED
          }
        }
        if( actor == 1006263 || actorId == 1006263 ) // ACTOR12 = URSANDEL
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=URSANDEL
            // +Callback Scene00020: Normal(Talk, TargetCanMove), id=URSANDEL
          }
        }
        if( actor == 1009140 || actorId == 1009140 ) // ACTOR13 = ISILDAURE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ISILDAURE
        }
        break;
      }
      case 6:
      {
        if( actor == 1009131 || actorId == 1009131 ) // ACTOR14 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1009139 || actorId == 1009139 ) // ACTOR10 = ALIANNE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( actor == 1009140 || actorId == 1009140 ) // ACTOR13 = ISILDAURE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ISILDAURE
        }
        break;
      }
      case 7:
      {
        Scene00025( player ); // Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 8:
      {
        if( actor == 1009135 || actorId == 1009135 ) // ACTOR16 = WILRED
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=WILRED
          }
        }
        if( actor == 1009136 || actorId == 1009136 ) // ACTOR17 = OURCEN
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=OURCEN
            // +Callback Scene00028: Normal(Talk, TargetCanMove), id=OURCEN
          }
        }
        if( actor == 1001679 || actorId == 1001679 ) // ACTOR18 = SYNTGOHT
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=SYNTGOHT
            // +Callback Scene00030: Normal(Talk, TargetCanMove), id=SYNTGOHT
          }
        }
        if( actor == 1001657 || actorId == 1001657 ) // ACTOR19 = LANDEBERT
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=LANDEBERT
            // +Callback Scene00032: Normal(Talk, TargetCanMove), id=LANDEBERT
          }
        }
        if( actor == 1001691 || actorId == 1001691 ) // ACTOR20 = YELLOWMOON
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YELLOWMOON
            // +Callback Scene00034: Normal(Talk, TargetCanMove), id=YELLOWMOON
          }
        }
        break;
      }
      case 9:
      {
        if( actor == 1009132 || actorId == 1009132 ) // ACTOR15 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00036: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1009136 || actorId == 1009136 ) // ACTOR17 = OURCEN
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=OURCEN
        }
        break;
      }
      case 255:
      {
        Scene00038( player ); // Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 5 )
      if( player.getQuestUI8AL( getId() ) == 5 )
        if( player.getQuestUI8AL( getId() ) == 5 )
          if( player.getQuestUI8AL( getId() ) == 5 )
            if( player.getQuestUI8AL( getId() ) == 5 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
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
      if( player.getQuestUI8AL( getId() ) == 4 )
        if( player.getQuestUI8AL( getId() ) == 4 )
          if( player.getQuestUI8AL( getId() ) == 4 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.updateQuest( getId(), 6 );
          }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
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
      if( player.getQuestUI8AL( getId() ) == 5 )
        if( player.getQuestUI8AL( getId() ) == 5 )
          if( player.getQuestUI8AL( getId() ) == 5 )
            if( player.getQuestUI8AL( getId() ) == 5 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
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
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00004: Normal(Talk, TargetCanMove), id=REYNER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=REYNER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00006: Normal(Talk, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00007: Normal(Talk, TargetCanMove), id=CARVALLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00008: Normal(Talk, TargetCanMove), id=RHOSWEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00009: Normal(Talk, TargetCanMove), id=RHOSWEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00010: Normal(Talk, TargetCanMove), id=HNAANZA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00011: Normal(Talk, TargetCanMove), id=HNAANZA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00015: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00016: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00017: Normal(Talk, TargetCanMove), id=CEINGULED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00018: Normal(Talk, TargetCanMove), id=CEINGULED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00019: Normal(Talk, TargetCanMove), id=URSANDEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00020: Normal(Talk, TargetCanMove), id=URSANDEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00021: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00023: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00024: Normal(Talk, TargetCanMove), id=ISILDAURE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00027: Normal(Talk, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00028( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00028: Normal(Talk, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00029: Normal(Talk, TargetCanMove), id=SYNTGOHT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00030( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00030: Normal(Talk, TargetCanMove), id=SYNTGOHT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00031: Normal(Talk, TargetCanMove), id=LANDEBERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00032( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00032: Normal(Talk, TargetCanMove), id=LANDEBERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00033: Normal(Talk, TargetCanMove), id=YELLOWMOON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00034( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00034: Normal(Talk, TargetCanMove), id=YELLOWMOON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00035: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00036( player );
    };
    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling [BranchTrue]Scene00036: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq9( player );
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00037: Normal(Talk, TargetCanMove), id=OURCEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse316:66993 calling Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 38, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse316 );
