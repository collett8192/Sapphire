// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda410 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda410() : Sapphire::ScriptAPI::EventScript( 68045 ){}; 
  ~StmBda410() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 9 entries
  //SEQ_4, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1022078
  //ACTOR1 = 1021732
  //ACTOR2 = 1021731
  //ACTOR3 = 1021730
  //ACTOR4 = 1020687
  //ACTOR5 = 1023089
  //ACTOR6 = 1019417
  //EOBJECT0 = 2008250
  //EOBJECT1 = 2008251
  //EOBJECT2 = 2008252
  //EOBJECT3 = 2008253
  //EOBJECT4 = 2008254
  //EOBJECT5 = 2008255
  //EOBJECT6 = 2008256
  //EOBJECT7 = 2008257
  //EVENTACTION0 = 53
  //ITEM0 = 2002207
  //LOCAISHUBGM = 458
  //LOCAURA001 = 1021983
  //LOCAURA002 = 1021984
  //LOCBINDDUID = 6840981
  //LOCBINDGOUSETSU = 6872468
  //LOCBINDHIEN = 6872466
  //LOCBINDLISE = 6872467
  //LOCBINDMAGUNAI = 6840967
  //LOCTOHOBGM = 465
  //POPRANGE0 = 6913795
  //TERRITORYTYPE0 = 622

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1022078 || param2 == 1022078 ) // ACTOR0 = BAATU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BAATU
          break;
        }
        if( param1 == 1021732 || param2 == 1021732 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1021731 || param2 == 1021731 ) // ACTOR2 = GOSETSU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1021730 || param2 == 1021730 ) // ACTOR3 = HIEN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 1:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=BAATU
        break;
        break;
      }
      case 2:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=THEDAWNTHRONEUPPERKEEPER
        break;
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 8
      case 3:
      {
        if( param1 == 2008250 || param2 == 2008250 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008251 || param2 == 2008251 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008252 || param2 == 2008252 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008253 || param2 == 2008253 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008254 || param2 == 2008254 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008255 || param2 == 2008255 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00018( player ); // Scene00018: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008256 || param2 == 2008256 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00020( player ); // Scene00020: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008257 || param2 == 2008257 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00022( player ); // Scene00022: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1023089 || param2 == 1023089 ) // ACTOR5 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(YesNo), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 8
      case 4:
      {
        Scene00024( player ); // Scene00024: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=BAATU
        break;
        break;
      }
      case 255:
      {
        if( param1 == 1019417 || param2 == 1019417 ) // ACTOR6 = MAGNAI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MAGNAI
          break;
        }
        if( param1 == 1021730 || param2 == 1021730 ) // ACTOR3 = HIEN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1022078 || param2 == 1022078 ) // ACTOR0 = BAATU
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=BAATU
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 8 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
      player.setQuestUI8BH( getId(), 8 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda410:68045 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00003: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00004: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00006: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=THEDAWNTHRONEUPPERKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00008: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00014: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00018: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00020: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00022: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00023: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00024: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00025( player );
      }
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MAGNAI" );
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
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00028: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda410:68045 calling Scene00029: Normal(Talk, TargetCanMove), id=BAATU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda410 );
