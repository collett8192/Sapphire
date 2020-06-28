// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa205 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa205() : Sapphire::ScriptAPI::EventScript( 66264 ){}; 
  ~GaiUsa205() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_4, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1000594
  //ENEMY0 = 3
  //ENEMY1 = 23
  //EOBJECT0 = 2002258
  //EOBJECT1 = 2001930
  //EOBJECT2 = 2001931
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000582
  //ITEM1 = 2000583

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=IANNA
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack 4
      //seq 1 event item ITEM1 = UI8CH max stack 2
      case 1:
      {
        if( actor == 3 || actorId == 3 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 4 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 23 || actorId == 23 ) // ENEMY1 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 2 )
          {
            player.setQuestUI8CH( getId(), player.getQuestUI8CH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 4
      //seq 2 event item ITEM1 = UI8BL max stack 2
      case 2:
      {
        Scene00002( player ); // Scene00002: NpcTrade(None), id=unknown
        // +Callback Scene00003: Normal(None), id=unknown
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack 2
      case 3:
      {
        if( actor == 2002258 || actorId == 2002258 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: NpcTrade(None), id=unknown
            // +Callback Scene00005: Normal(None), id=unknown
          }
        }
        if( actor == 2001930 || actorId == 2001930 ) // EOBJECT1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( actor == 2002258 || actorId == 2002258 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(None), id=unknown
          }
        }
        if( actor == 2001930 || actorId == 2001930 ) // EOBJECT1 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(None), id=unknown
        }
        if( actor == 2001931 || actorId == 2001931 ) // EOBJECT2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1000594 || actorId == 1000594 ) // ACTOR0 = IANNA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=IANNA
        }
        if( actor == 2001930 || actorId == 2001930 ) // EOBJECT1 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          // +Callback Scene00016: Normal(None), id=unknown
        }
        if( actor == 2001931 || actorId == 2001931 ) // EOBJECT2 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          // +Callback Scene00018: Normal(None), id=unknown
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
    if( player.getQuestUI8BL( getId() ) == 4 )
      if( player.getQuestUI8CH( getId() ) == 2 )
      {
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 2 );
        player.setQuestUI8BH( getId(), 4 );
        player.setQuestUI8BL( getId(), 2 );
      }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.setQuestUI8BL( getId(), 0 );
    player.updateQuest( getId(), 3 );
    player.setQuestUI8BH( getId(), 2 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsa205:66264 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=IANNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00002: NpcTrade(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling [BranchTrue]Scene00003: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00004: NpcTrade(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling [BranchTrue]Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling [BranchTrue]Scene00013: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=IANNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00015: Normal(None), id=unknown" );
    Scene00016( player );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling [BranchTrue]Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa205:66264 calling [BranchTrue]Scene00018: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsa205 );
