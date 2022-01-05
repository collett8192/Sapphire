// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst028 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst028() : Sapphire::ScriptAPI::EventScript( 65707 ){}; 
  ~SubFst028() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000629
  //ACTOR1 = 1000612
  //ENEMY0 = 2653890
  //EOBJECT0 = 2000140
  //EOBJECT1 = 2000142
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000144
  //SEQ0ACTOR0 = 0
  //SEQ1EOBJECT0 = 1
  //SEQ1EOBJECT0EVENTACTIONNO = 99
  //SEQ1EOBJECT0EVENTACTIONOK = 100
  //SEQ2EOBJECT1 = 2
  //SEQ2EOBJECT1EVENTACTIONNO = 97
  //SEQ2EOBJECT1EVENTACTIONOK = 98
  //SEQ3ACTOR1 = 3
  //SEQ3ACTOR1NPCTRADENO = 95
  //SEQ3ACTOR1NPCTRADEOK = 96

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BODWINE
        break;
      }
      case 1:
      {
        if( param1 == 2000140 || param2 == 2000140 ) // EOBJECT0 = unknown
        {
          Scene00100( player ); // Scene00100: Normal(Message), id=unknown
          break;
        }
        if( param1 == 2653890 || param2 == 2653890 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( type != 2 ) Scene00097( player ); // Scene00097: Normal(None), id=unknown
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( type != 2 ) Scene00003( player ); // Scene00003: NpcTrade(Talk, TargetCanMove), id=GUITHRIT
        // +Callback Scene00096: Normal(QuestReward, QuestComplete), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 1 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst028:65707 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=BODWINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00100( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "SubFst028:65707 calling Scene00100: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 100, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ENEMY0, UI8AL = 1, <No Flag>
  {
    player.sendDebug( "SubFst028:65707 calling Scene00002: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00097( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst028:65707 calling Scene00097: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00003( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst028:65707 calling Scene00003: NpcTrade(Talk, TargetCanMove), id=GUITHRIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00096( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00096( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst028:65707 calling Scene00096: Normal(QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 96, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst028 );
