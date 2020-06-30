// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_3 = ESTINIEN
//SCENE_7 = dummy0
//SCENE_8 = dummy1
//SCENE_9 = dummy2
//SCENE_10 = dummy3
//SCENE_11 = dummy4
//SCENE_12 = dummy5
//SCENE_13 = dummy6
//SCENE_14 = dummye0
//ENEMY0 = dummy0
//ENEMY1 = dummy1
//ENEMY2 = dummy2
//ENEMY3 = dummy3
//ENEMY4 = dummy4
//ENEMY5 = dummy5
//ENEMY6 = dummy6
//EOBJECT0 = dummye0
//fix: skip quest battle
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna705 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna705() : Sapphire::ScriptAPI::EventScript( 67203 ){}; 
  ~HeaVna705() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 9 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1014850
  //ACTOR1 = 1012829
  //ACTOR2 = 1012828
  //ACTOR3 = 1012830
  //ACTOR4 = 1012827
  //ACTOR5 = 1012834
  //CUTSCENEN01 = 894
  //CUTSCENEN02 = 895
  //CUTSCENEN03 = 896
  //ENEMY0 = 5867945
  //ENEMY1 = 5867947
  //ENEMY2 = 5867948
  //ENEMY3 = 5867949
  //ENEMY4 = 5867950
  //ENEMY5 = 5867951
  //ENEMY6 = 5867952
  //EOBJECT0 = 2006357
  //EOBJECT1 = 2005764
  //QUESTBATTLE0 = 110
  //TERRITORYTYPE0 = 459

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM
        break;
      }
      case 1:
      {
        if( actor == 1012829 || actorId == 1012829 ) // ACTOR1 = ESTINIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN
            // +Callback Scene00003: Normal(CutScene), id=ESTINIEN
          }
        }
        if( actor == 1012828 || actorId == 1012828 ) // ACTOR2 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012830 || actorId == 1012830 ) // ACTOR3 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 2:
      {
        if( actor == 1012827 || actorId == 1012827 ) // ACTOR4 = GUIDANCESYSTEM
        {
          if( player.getQuestUI8AL( getId() ) != 7 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GUIDANCESYSTEM
          }
        }
        if( actor == 5867945 || actorId == 5867945 ) // ENEMY0 = dummy0
        {
          Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=dummy0
        }
        if( actor == 5867947 || actorId == 5867947 ) // ENEMY1 = dummy1
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=dummy1
        }
        if( actor == 5867948 || actorId == 5867948 ) // ENEMY2 = dummy2
        {
          Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=dummy2
        }
        if( actor == 5867949 || actorId == 5867949 ) // ENEMY3 = dummy3
        {
          Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=dummy3
        }
        if( actor == 5867950 || actorId == 5867950 ) // ENEMY4 = dummy4
        {
          Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=dummy4
        }
        if( actor == 5867951 || actorId == 5867951 ) // ENEMY5 = dummy5
        {
          Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=dummy5
        }
        if( actor == 5867952 || actorId == 5867952 ) // ENEMY6 = dummy6
        {
          Scene00013( player ); // Scene00013: Normal(Message, PopBNpc), id=dummy6
        }
        if( actor == 2006357 || actorId == 2006357 ) // EOBJECT0 = dummye0
        {
          Scene00014( player ); // Scene00014: Normal(None), id=dummye0
        }
        break;
      }
      case 3:
      {
        if( actor == 1012827 || actorId == 1012827 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(QuestBattle, YesNo), id=unknown
          }
        }
        if( actor == 2005764 || actorId == 2005764 ) // EOBJECT1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        Scene00017( player ); // Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUIDANCESYSTEM
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
    if( player.getQuestUI8AL( getId() ) == 7 )
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna705:67203 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling [BranchTrue]Scene00003: Normal(CutScene), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00006: Normal(Talk, Message, PopBNpc, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 7 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00007: Normal(Message, PopBNpc), id=dummy0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00008: Normal(Message, PopBNpc), id=dummy1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00009: Normal(Message, PopBNpc), id=dummy2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00010: Normal(Message, PopBNpc), id=dummy3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00011: Normal(Message, PopBNpc), id=dummy4" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00012: Normal(Message, PopBNpc), id=dummy5" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00013: Normal(Message, PopBNpc), id=dummy6" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00014: Normal(None), id=dummye0" );
    checkProgressSeq2( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00015: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq3( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 402, -177.5, -95.1, 468.3, -0.43 );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna705:67203 calling Scene00017: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna705 );
