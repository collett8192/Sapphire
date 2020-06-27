// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst209 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManFst209() : Sapphire::ScriptAPI::EventScript( 65879 ){}; 
  ~ManFst209() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 6 entries
  //SEQ_3, 13 entries
  //SEQ_4, 13 entries
  //SEQ_5, 11 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1005116
  //ACTOR1 = 1004584
  //ACTOR10 = 1004610
  //ACTOR11 = 1004611
  //ACTOR12 = 1005140
  //ACTOR13 = 1005141
  //ACTOR14 = 1005142
  //ACTOR15 = 1005143
  //ACTOR16 = 1005144
  //ACTOR17 = 1005145
  //ACTOR18 = 1005018
  //ACTOR2 = 1004585
  //ACTOR20 = 1005156
  //ACTOR21 = 1005146
  //ACTOR22 = 1005147
  //ACTOR23 = 1005148
  //ACTOR24 = 1005149
  //ACTOR25 = 1005150
  //ACTOR26 = 1005151
  //ACTOR27 = 1005152
  //ACTOR28 = 1005153
  //ACTOR29 = 1005154
  //ACTOR3 = 1004586
  //ACTOR30 = 1005155
  //ACTOR31 = 1005012
  //ACTOR4 = 1004587
  //ACTOR5 = 1005161
  //ACTOR6 = 1005017
  //ACTOR7 = 1004605
  //ACTOR8 = 1004606
  //ACTOR9 = 1004608
  //CUTMANFST20950 = 88
  //EOBJECT0 = 2001592
  //EVENTACTIONWAITINGSHOR = 11
  //INSTANCEDUNGEON0 = 20001
  //POPRANGE0 = 4165046
  //POPRANGE1 = 4156164
  //POPRANGE2 = 4148347
  //QUESTBATTLE0 = 45
  //TERRITORYTYPE0 = 275
  //TERRITORYTYPE1 = 146
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEON = 77

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( actor == 1004584 || actorId == 1004584 ) // ACTOR1 = FLAMESGT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=FLAMESGT
          }
        }
        if( actor == 1004585 || actorId == 1004585 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        if( actor == 1004586 || actorId == 1004586 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1004587 || actorId == 1004587 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 1005161 || actorId == 1005161 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 2001592 || actorId == 2001592 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 1004584 || actorId == 1004584 ) // ACTOR1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(QuestBattle, YesNo), id=unknown
        }
        if( actor == 1004585 || actorId == 1004585 ) // ACTOR2 = FLAMESGT
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=FLAMESGT
        }
        if( actor == 1004586 || actorId == 1004586 ) // ACTOR3 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1004587 || actorId == 1004587 ) // ACTOR4 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1005161 || actorId == 1005161 ) // ACTOR5 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1005017 || actorId == 1005017 ) // ACTOR6 = FLAMESGT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
            // +Callback Scene00014: Normal(Talk, Message), id=FLAMESGT
          }
        }
        if( actor == 1004605 || actorId == 1004605 ) // ACTOR7 = FLAMEPRIVATE2
        {
          Scene00015( player ); // Scene00015: Normal(Talk), id=FLAMEPRIVATE2
        }
        if( actor == 1004606 || actorId == 1004606 ) // ACTOR8 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( actor == 1004608 || actorId == 1004608 ) // ACTOR9 = FLAMEPRIVATE
        {
          Scene00017( player ); // Scene00017: Normal(Talk), id=FLAMEPRIVATE
        }
        if( actor == 1004610 || actorId == 1004610 ) // ACTOR10 = AMALJA
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=AMALJA
        }
        if( actor == 1004611 || actorId == 1004611 ) // ACTOR11 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 1005140 || actorId == 1005140 ) // ACTOR12 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( actor == 1005141 || actorId == 1005141 ) // ACTOR13 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( actor == 1005142 || actorId == 1005142 ) // ACTOR14 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( actor == 1005143 || actorId == 1005143 ) // ACTOR15 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 1005144 || actorId == 1005144 ) // ACTOR16 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
        }
        if( actor == 1005145 || actorId == 1005145 ) // ACTOR17 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        if( actor == 1005018 || actorId == 1005018 ) // ACTOR18 = ADALA
        {
          Scene00026( player ); // Scene00026: Normal(Talk, YesNo, TargetCanMove), id=ADALA
        }
        break;
      }
      case 4:
      {
        if( actor == 1004605 || actorId == 1004605 ) // ACTOR7 = FLAMEPRIVATE2
        {
          Scene00027( player ); // Scene00027: Normal(Talk), id=FLAMEPRIVATE2
        }
        if( actor == 1004606 || actorId == 1004606 ) // ACTOR8 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
        }
        if( actor == 1004608 || actorId == 1004608 ) // ACTOR9 = FLAMEPRIVATE
        {
          Scene00029( player ); // Scene00029: Normal(Talk), id=FLAMEPRIVATE
        }
        if( actor == 1004610 || actorId == 1004610 ) // ACTOR10 = AMALJA
        {
          Scene00030( player ); // Scene00030: Normal(Talk), id=AMALJA
        }
        if( actor == 1004611 || actorId == 1004611 ) // ACTOR11 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( actor == 1005017 || actorId == 1005017 ) // ACTOR6 = FLAMESGT
        {
          Scene00032( player ); // Scene00032: Normal(Talk), id=FLAMESGT
        }
        if( actor == 1005140 || actorId == 1005140 ) // ACTOR12 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        if( actor == 1005141 || actorId == 1005141 ) // ACTOR13 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        if( actor == 1005142 || actorId == 1005142 ) // ACTOR14 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        if( actor == 1005143 || actorId == 1005143 ) // ACTOR15 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
        }
        if( actor == 1005144 || actorId == 1005144 ) // ACTOR16 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
        }
        if( actor == 1005145 || actorId == 1005145 ) // ACTOR17 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
        }
        if( actor == 1005018 || actorId == 1005018 ) // ACTOR18 = ADALA
        {
          Scene00039( player ); // Scene00039: Normal(Talk, YesNo, TargetCanMove), id=ADALA
        }
        break;
      }
      case 5:
      {
        if( actor == 1005156 || actorId == 1005156 ) // ACTOR20 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00040( player ); // Scene00040: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
          }
        }
        if( actor == 1005146 || actorId == 1005146 ) // ACTOR21 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( actor == 1005147 || actorId == 1005147 ) // ACTOR22 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        if( actor == 1005148 || actorId == 1005148 ) // ACTOR23 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
        }
        if( actor == 1005149 || actorId == 1005149 ) // ACTOR24 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
        }
        if( actor == 1005150 || actorId == 1005150 ) // ACTOR25 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
        }
        if( actor == 1005151 || actorId == 1005151 ) // ACTOR26 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
        }
        if( actor == 1005152 || actorId == 1005152 ) // ACTOR27 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
        }
        if( actor == 1005153 || actorId == 1005153 ) // ACTOR28 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
        }
        if( actor == 1005154 || actorId == 1005154 ) // ACTOR29 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(None), id=unknown
        }
        if( actor == 1005155 || actorId == 1005155 ) // ACTOR30 = unknown
        {
          Scene00050( player ); // Scene00050: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1005012 || actorId == 1005012 ) // ACTOR31 = GUIDE
        {
          Scene00051( player ); // Scene00051: Normal(Talk, QuestReward, TargetCanMove), id=GUIDE
          // +Callback Scene00052: Normal(CutScene, QuestComplete), id=unknown
        }
        if( actor == 1005146 || actorId == 1005146 ) // ACTOR21 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
        }
        if( actor == 1005147 || actorId == 1005147 ) // ACTOR22 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
        }
        if( actor == 1005148 || actorId == 1005148 ) // ACTOR23 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
        }
        if( actor == 1005149 || actorId == 1005149 ) // ACTOR24 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
        }
        if( actor == 1005150 || actorId == 1005150 ) // ACTOR25 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
        }
        if( actor == 1005151 || actorId == 1005151 ) // ACTOR26 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(None), id=unknown
        }
        if( actor == 1005152 || actorId == 1005152 ) // ACTOR27 = unknown
        {
          Scene00059( player ); // Scene00059: Normal(None), id=unknown
        }
        if( actor == 1005153 || actorId == 1005153 ) // ACTOR28 = unknown
        {
          Scene00060( player ); // Scene00060: Normal(None), id=unknown
        }
        if( actor == 1005154 || actorId == 1005154 ) // ACTOR29 = unknown
        {
          Scene00061( player ); // Scene00061: Normal(None), id=unknown
        }
        if( actor == 1005155 || actorId == 1005155 ) // ACTOR30 = unknown
        {
          Scene00062( player ); // Scene00062: Normal(None), id=unknown
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
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
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
    player.sendDebug( "ManFst209:65879 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "ManFst209:65879 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00002: Normal(Talk, TargetCanMove), id=FLAMESGT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00008: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00009: Normal(Talk, TargetCanMove), id=FLAMESGT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling [BranchTrue]Scene00014: Normal(Talk, Message), id=FLAMESGT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00015: Normal(Talk), id=FLAMEPRIVATE2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00017: Normal(Talk), id=FLAMEPRIVATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00018: Normal(Talk), id=AMALJA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00026: Normal(Talk, YesNo, TargetCanMove), id=ADALA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00027: Normal(Talk), id=FLAMEPRIVATE2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00029: Normal(Talk), id=FLAMEPRIVATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00030: Normal(Talk), id=AMALJA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00032: Normal(Talk), id=FLAMESGT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00039: Normal(Talk, YesNo, TargetCanMove), id=ADALA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00040: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00045: Normal(None), id=unknown" );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00047: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00049: Normal(None), id=unknown" );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00050: Normal(None), id=unknown" );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00051: Normal(Talk, QuestReward, TargetCanMove), id=GUIDE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00052( player );
      }
    };
    player.playScene( getId(), 51, NONE, callback );
  }
  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling [BranchTrue]Scene00052: Normal(CutScene, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 52, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00053: Normal(None), id=unknown" );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00057: Normal(None), id=unknown" );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00058: Normal(None), id=unknown" );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00059: Normal(None), id=unknown" );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00060: Normal(None), id=unknown" );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00061: Normal(None), id=unknown" );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "ManFst209:65879 calling Scene00062: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( ManFst209 );
