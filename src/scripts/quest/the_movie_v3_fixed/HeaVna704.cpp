// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_35 = dummy
//SCENE_36 = dummy
//SCENE_38 = GUIDANCESYSTEM
//fix: teleport device
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna704 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna704() : Sapphire::ScriptAPI::EventScript( 67202 ){}; 
  ~HeaVna704() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 18 entries
  //SEQ_3, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1012802
  //ACTOR1 = 1012803
  //ACTOR10 = 1012816
  //ACTOR11 = 1012817
  //ACTOR12 = 1012818
  //ACTOR13 = 1012819
  //ACTOR14 = 1012820
  //ACTOR2 = 1012804
  //ACTOR3 = 1012805
  //ACTOR4 = 1012807
  //ACTOR5 = 1012808
  //ACTOR6 = 1012809
  //ACTOR7 = 1012810
  //ACTOR8 = 1012814
  //ACTOR9 = 1012815
  //CUTSCENEN01 = 893
  //CUTSCENEN02 = 1020
  //CUTSCENEN03 = 1020
  //ENEMY0 = 5868108
  //ENEMY1 = 5868109
  //ENEMY2 = 5868110
  //ENEMY3 = 5868111
  //ENEMY4 = 5868112
  //ENEMY5 = 5868113
  //ENEMY6 = 5868114
  //EOBJECT0 = 2005567
  //EOBJECT1 = 2005568
  //EOBJECT2 = 2005569
  //EOBJECT3 = 2006364
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 5867516
  //LOCACTOR1 = 5867517
  //LOCACTOR10 = 5867543
  //LOCACTOR11 = 5867544
  //LOCACTOR12 = 5867545
  //LOCACTOR2 = 5867518
  //POPRANGE0 = 5918521

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012802 || actorId == 1012802 ) // ACTOR0 = GUIDANCESYSTEM
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM
        }
        if( actor == 1012803 || actorId == 1012803 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012804 || actorId == 1012804 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012805 || actorId == 1012805 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 1:
      {
        if( actor == 1012807 || actorId == 1012807 ) // ACTOR4 = GUIDANCESYSTEM
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
          }
        }
        if( actor == 1012808 || actorId == 1012808 ) // ACTOR5 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012809 || actorId == 1012809 ) // ACTOR6 = ESTINIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012810 || actorId == 1012810 ) // ACTOR7 = YSHTOLA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 2:
      {
        if( actor == 2005567 || actorId == 2005567 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
            // +Callback Scene00010: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 5868108 || actorId == 5868108 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 5868109 || actorId == 5868109 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2005568 || actorId == 2005568 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
            // +Callback Scene00012: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 5868110 || actorId == 5868110 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 5868111 || actorId == 5868111 ) // ENEMY3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          // +Callback Scene00014: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 2005569 || actorId == 2005569 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
            // +Callback Scene00016: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 5868112 || actorId == 5868112 ) // ENEMY4 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          // +Callback Scene00018: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5868113 || actorId == 5868113 ) // ENEMY5 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          // +Callback Scene00020: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 5868114 || actorId == 5868114 ) // ENEMY6 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          // +Callback Scene00022: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1012807 || actorId == 1012807 ) // ACTOR4 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          // +Callback Scene00024: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1012814 || actorId == 1012814 ) // ACTOR8 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1012815 || actorId == 1012815 ) // ACTOR9 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          // +Callback Scene00028: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 1012816 || actorId == 1012816 ) // ACTOR10 = GUIDANCESYSTEM
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
        }
        if( actor == 1012817 || actorId == 1012817 ) // ACTOR11 = ALPHINAUD
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012818 || actorId == 1012818 ) // ACTOR12 = ESTINIEN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012819 || actorId == 1012819 ) // ACTOR13 = YSHTOLA
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=YSHTOLA
          // +Callback Scene00033: Normal(None), id=unknown
        }
        if( actor == 1012820 || actorId == 1012820 ) // ACTOR14 = dummy
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          // +Callback Scene00035: Normal(None), id=dummy
          // +Callback Scene00036: Normal(None), id=dummy
        }
        break;
      }
      case 3:
      {
        if( actor == 1012807 || actorId == 1012807 ) // ACTOR4 = GUIDANCESYSTEM
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
            // +Callback Scene00038: Normal(CutScene), id=GUIDANCESYSTEM
          }
        }
        if( actor == 1012808 || actorId == 1012808 ) // ACTOR5 = ALPHINAUD
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012809 || actorId == 1012809 ) // ACTOR6 = ESTINIEN
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012810 || actorId == 1012810 ) // ACTOR7 = YSHTOLA
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 255:
      {
        if( actor == 2006364 || actorId == 2006364 ) // EOBJECT3 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(CutScene), id=unknown
          // +Callback Scene00043: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1012807 || actorId == 1012807 ) // ACTOR4 = GUIDANCESYSTEM
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
        }
        if( actor == 1012808 || actorId == 1012808 ) // ACTOR5 = ALPHINAUD
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012809 || actorId == 1012809 ) // ACTOR6 = ESTINIEN
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012810 || actorId == 1012810 ) // ACTOR7 = YSHTOLA
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    if( player.getQuestUI8BL( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 2 )
        if( player.getQuestUI8BH( getId() ) == 3 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 3 );
        }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00005: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00007: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00015: Normal(None), id=unknown" );
    Scene00016( player );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 3 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00019: Normal(None), id=unknown" );
    Scene00020( player );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00023: Normal(None), id=unknown" );
    Scene00024( player );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00026: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00027: Normal(None), id=unknown" );
    Scene00028( player );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00028: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00029: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00030: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00031: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00032: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00033( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00034: Normal(None), id=unknown" );
    Scene00035( player );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00035: Normal(None), id=dummy" );
    Scene00036( player );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchChain]Scene00036: Normal(None), id=dummy" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00037: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00038( player );
    };
    player.playScene( getId(), 37, NONE, callback );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00038: Normal(CutScene), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 38, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00039: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00040: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00042: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00043( player );
    };
    player.playScene( getId(), 42, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling [BranchTrue]Scene00043: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.eventFinish( getId(), 1 );
          player.forceZoneing( 402, 633.6, 10.62, 73.6, 1 );
        }
      }
    };
    player.playScene( getId(), 43, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00044: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00045: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00046: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "HeaVna704:67202 calling Scene00047: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna704 );
