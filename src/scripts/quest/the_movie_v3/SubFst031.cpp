// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst031 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst031() : Sapphire::ScriptAPI::EventScript( 65661 ){}; 
  ~SubFst031() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000685
  //ACTOR1 = 1000408
  //ENEMY0 = 142
  //EOBJECT0 = 2000010
  //EOBJECT1 = 2000011
  //EOBJECT2 = 2000012
  //EOBJECT3 = 2000013
  //EOBJECT4 = 2000014
  //EOBJECT5 = 2000150
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000071

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=PAULINE
        // +Callback Scene00007: Normal(Talk, TargetCanMove), id=PAULINE
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack 4
      case 1:
      {
        if( param1 == 2000010 || param2 == 2000010 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00100( player ); // Scene00100: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2000011 || param2 == 2000011 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2000012 || param2 == 2000012 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00097( player ); // Scene00097: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2000013 || param2 == 2000013 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00096( player ); // Scene00096: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2000014 || param2 == 2000014 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2000150 || param2 == 2000150 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00093( player ); // Scene00093: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 142 || param2 == 142 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00091( player ); // Scene00091: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 4
      case 2:
      {
        if( type != 2 ) Scene00089( player ); // Scene00089: Normal(None), id=unknown
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 4
      case 255:
      {
        if( type != 2 ) Scene00008( player ); // Scene00008: NpcTrade(Talk, TargetCanMove), id=TSUBHKHAMAZOM
        // +Callback Scene00088: Normal(QuestReward, QuestComplete), id=unknown
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
    if( player.getQuestUI8BH( getId() ) == 4 )
      if( player.getQuestUI8AL( getId() ) == 6 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestBitFlag8( getId(), 1, false );
        player.setQuestBitFlag8( getId(), 2, false );
        player.setQuestBitFlag8( getId(), 3, false );
        player.setQuestBitFlag8( getId(), 4, false );
        player.setQuestBitFlag8( getId(), 5, false );
        player.setQuestBitFlag8( getId(), 6, false );
        player.setQuestUI8BL( getId(), 0 );
        player.updateQuest( getId(), 2 );
      }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 4 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst031:65661 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=PAULINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst031:65661 calling Scene00007: Normal(Talk, TargetCanMove), id=PAULINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00100( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8BH = 4, Flag8(1)=True
  {
    player.sendDebug( "SubFst031:65661 calling Scene00100: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8BH = 4, Flag8(2)=True
  {
    player.sendDebug( "SubFst031:65661 calling Scene00002: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq1( player );
  }

  void Scene00097( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8BH = 4, Flag8(3)=True
  {
    player.sendDebug( "SubFst031:65661 calling Scene00097: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00096( Entity::Player& player ) //SEQ_1: EOBJECT3, UI8BH = 4, Flag8(4)=True
  {
    player.sendDebug( "SubFst031:65661 calling Scene00096: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 4, true );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: EOBJECT4, UI8BH = 4, Flag8(5)=True
  {
    player.sendDebug( "SubFst031:65661 calling Scene00004: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 5, true );
    checkProgressSeq1( player );
  }

  void Scene00093( Entity::Player& player ) //SEQ_1: EOBJECT5, UI8BH = 4, Flag8(6)=True
  {
    player.sendDebug( "SubFst031:65661 calling Scene00093: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 6, true );
    checkProgressSeq1( player );
  }

  void Scene00091( Entity::Player& player ) //SEQ_1: ENEMY0, UI8AL = 6, <No Flag>
  {
    player.sendDebug( "SubFst031:65661 calling Scene00091: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00089( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst031:65661 calling Scene00089: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst031:65661 calling Scene00008: NpcTrade(Talk, TargetCanMove), id=TSUBHKHAMAZOM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00088( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00088( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst031:65661 calling Scene00088: Normal(QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 88, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst031 );
