// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa308 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa308() : Sapphire::ScriptAPI::EventScript( 66276 ){}; 
  ~GaiUsa308() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 7 entries
  //SEQ_4, 2 entries
  //SEQ_5, 2 entries
  //SEQ_6, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000590
  //ACTOR1 = 1006199
  //ACTOR2 = 1006200
  //ACTOR3 = 1006201
  //ACTOR4 = 1006202
  //ACTOR5 = 1006203
  //ENEMY0 = 4293402
  //EOBJECT0 = 2001651
  //EOBJECT1 = 2001652
  //EOBJECT2 = 2001653
  //EOBJECT3 = 2001654
  //EOBJECT4 = 2001954
  //EOBJECT5 = 2002271
  //EVENTACTIONSEARCH = 1
  //QUESTBATTLE0 = 13
  //SEQ0ACTOR0LQ = 90
  //TERRITORYTYPE0 = 232

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00090: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BUSCARRON
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS
        break;
      }
      case 2:
      {
        if( param1 == 1006200 || param2 == 1006200 ) // ACTOR2 = LAURENTIUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS
          }
          break;
        }
        if( param1 == 2001651 || param2 == 2001651 ) // EOBJECT0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001652 || param2 == 2001652 ) // EOBJECT1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001653 || param2 == 2001653 ) // EOBJECT2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001654 || param2 == 2001654 ) // EOBJECT3 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1006201 || param2 == 1006201 ) // ACTOR3 = LAURENTIUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, Message, PopBNpc, TargetCanMove), id=LAURENTIUS
          }
          break;
        }
        if( param1 == 4293402 || param2 == 4293402 ) // ENEMY0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001954 || param2 == 2001954 ) // EOBJECT4 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001651 || param2 == 2001651 ) // EOBJECT0 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001652 || param2 == 2001652 ) // EOBJECT1 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001653 || param2 == 2001653 ) // EOBJECT2 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001654 || param2 == 2001654 ) // EOBJECT3 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1006201 || param2 == 1006201 ) // ACTOR3 = LAURENTIUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS
          }
          break;
        }
        if( param1 == 2001954 || param2 == 2001954 ) // EOBJECT4 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1006202 || param2 == 1006202 ) // ACTOR4 = LAURENTIUS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS
          }
          break;
        }
        if( param1 == 2001954 || param2 == 2001954 ) // EOBJECT4 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1006203 || param2 == 1006203 ) // ACTOR5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00029( player ); // Scene00029: Normal(QuestBattle, YesNo), id=unknown
          }
          break;
        }
        if( param1 == 2002271 || param2 == 2002271 ) // EOBJECT5 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00032( player ); // Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BUSCARRON
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
    player.sendDebug( "GaiUsa308:66276 calling Scene00000: Normal(QuestOffer), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00090( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00090( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00090: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=BUSCARRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 90, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00012: Normal(Talk, Message, PopBNpc, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00021( Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00022( Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_4: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00026( Entity::Player& player ) //SEQ_5: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_5: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00028: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00029( Entity::Player& player ) //SEQ_6: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00029: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        //quest battle
        player.eventFinish( getId(), 1 );
        auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
        pTeriMgr.createAndJoinQuestBattle( player, 13 );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_6: EOBJECT5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00031: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00032( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa308:66276 calling Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=BUSCARRON" );
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
    player.playScene( getId(), 32, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsa308 );
