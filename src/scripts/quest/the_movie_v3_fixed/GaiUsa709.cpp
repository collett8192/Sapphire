// FFXIVTheMovie.ParserV3.3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa709 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa709() : Sapphire::ScriptAPI::EventScript( 66318 ){}; 
  ~GaiUsa709() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_2, 2 entries
  //SEQ_3, 8 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006215
  //ACTOR1 = 1006225
  //ACTOR10 = 1007605
  //ACTOR2 = 1007616
  //ACTOR3 = 1007617
  //ACTOR4 = 1007635
  //ACTOR5 = 1006230
  //ACTOR6 = 1006229
  //ACTOR7 = 1006231
  //ACTOR8 = 1006232
  //ACTOR9 = 1006233
  //EOBJECT0 = 2001980
  //EOBJECT1 = 2001981
  //EOBJECT2 = 2002272
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000974
  //ITEM1 = 2000973
  //LOCACTOR0 = 1008115
  //LOCACTOR1 = 1008116
  //LOCACTOR2 = 1006226
  //QUESTBATTLE0 = 58
  //SEQ0ACTOR0LQ = 90
  //TERRITORYTYPE0 = 306

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00090: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=GUNDOBALD
        break;
      }
      //seq 1 event item ITEM1 = UI8DH max stack 1
      //seq 1 event item ITEM0 = UI8DL max stack 1
      case 1:
      {
        if( param1 == 1006225 || param2 == 1006225 ) // ACTOR1 = WILRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=WILRED
          }
          break;
        }
        if( param1 == 4299289701 || param2 == 1007616 ) // ACTOR2 = NPCA
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCA
          }
          break;
        }
        if( param1 == 4299289705 || param2 == 1007617 ) // ACTOR3 = NPCB
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCB
          }
          break;
        }
        if( param1 == 2001980 || param2 == 2001980 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001981 || param2 == 2001981 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1007635 || param2 == 1007635 ) // ACTOR4 = BERTLIANA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=BERTLIANA
          break;
        }
        break;
      }
      //seq 2 event item ITEM1 = UI8BH max stack 1
      //seq 2 event item ITEM0 = UI8BL max stack 1
      case 2:
      {
        if( param1 == 1006215 || param2 == 1006215 ) // ACTOR0 = GUNDOBALD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=GUNDOBALD
          }
          break;
        }
        if( param1 == 1007635 || param2 == 1007635 ) // ACTOR4 = BERTLIANA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=BERTLIANA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1006230 || param2 == 1006230 ) // ACTOR5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 2002272 || param2 == 2002272 ) // EOBJECT2 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006229 || param2 == 1006229 ) // ACTOR6 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006231 || param2 == 1006231 ) // ACTOR7 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006232 || param2 == 1006232 ) // ACTOR8 = NPCA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=NPCA
          // +Callback Scene00018: Normal(Talk, TargetCanMove), id=NPCA
          break;
        }
        if( param1 == 1006233 || param2 == 1006233 ) // ACTOR9 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007605 || param2 == 1007605 ) // ACTOR10 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007635 || param2 == 1007635 ) // ACTOR4 = BERTLIANA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=BERTLIANA
          break;
        }
        break;
      }
      case 255:
      {
        Scene00022( player ); // Scene00022: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=GUNDOBALD
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
    //onProgress( player, npcId, 0, 2, 0 );
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
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
            if( player.getQuestUI8CL( getId() ) == 1 )
            {
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8BH( getId(), 0 );
              player.setQuestUI8BL( getId(), 0 );
              player.setQuestUI8CH( getId(), 0 );
              player.setQuestUI8CL( getId(), 0 );
              player.setQuestUI8DH( getId(), 0 );
              player.setQuestUI8DL( getId(), 0 );
              player.updateQuest( getId(), 2 );
              player.setQuestUI8BH( getId(), 1 );
              player.setQuestUI8BL( getId(), 1 );
            }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
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
    player.sendDebug( "GaiUsa709:66318 calling Scene00000: Normal(QuestOffer), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00090( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00090( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00090: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=GUNDOBALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 90, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00006: Normal(None), id=unknown" );
    player.setQuestUI8CH( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8CL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00009: Normal(Talk, TargetCanMove), id=BERTLIANA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00011: Normal(Talk, TargetCanMove), id=GUNDOBALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00012: Normal(Talk, TargetCanMove), id=BERTLIANA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00013: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        //quest battle
        player.eventFinish( getId(), 1 );
        auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
        pTeriMgr.createAndJoinQuestBattle( player, 58 );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00017: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00018: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00021: Normal(Talk, TargetCanMove), id=BERTLIANA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa709:66318 calling Scene00022: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=GUNDOBALD" );
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
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUsa709 );
