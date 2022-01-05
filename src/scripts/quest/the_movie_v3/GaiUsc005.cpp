// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc005 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc005() : Sapphire::ScriptAPI::EventScript( 66478 ){}; 
  ~GaiUsc005() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_2, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006473
  //ACTOR1 = 1006445
  //ACTOR2 = 1006451
  //ACTOR3 = 1007565
  //EOBJECT0 = 2002176
  //EOBJECT1 = 2002177
  //EOBJECT2 = 2002178
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000734

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LIAUTROIX
        break;
      }
      //seq 1 event item ITEM0 = UI8DH max stack 5
      case 1:
      {
        if( param1 == 1006445 || param2 == 1006445 ) // ACTOR1 = BENEDICT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=BENEDICT
          }
          break;
        }
        if( param1 == 1006451 || param2 == 1006451 ) // ACTOR2 = IGNEMORTEL
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=IGNEMORTEL
          }
          break;
        }
        if( param1 == 2002176 || param2 == 2002176 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002177 || param2 == 2002177 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002178 || param2 == 2002178 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 5
      case 2:
      {
        if( type != 2 ) Scene00010( player ); // Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00011: Normal(Talk, TargetCanMove), id=TUATKK
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 5
      case 255:
      {
        if( type != 2 ) Scene00012( player ); // Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LIAUTROIX
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
              player.setQuestBitFlag8( getId(), 1, false );
              player.setQuestBitFlag8( getId(), 2, false );
              player.setQuestBitFlag8( getId(), 3, false );
              player.setQuestBitFlag8( getId(), 4, false );
              player.setQuestBitFlag8( getId(), 5, false );
              player.setQuestUI8DH( getId(), 0 );
              player.updateQuest( getId(), 2 );
              player.setQuestUI8BH( getId(), 5 );
            }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LIAUTROIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00002: Normal(Talk, TargetCanMove), id=BENEDICT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00003: Normal(Talk, TargetCanMove), id=IGNEMORTEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8CH( getId(), 1 );
    player.setQuestBitFlag8( getId(), 4, true );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8CL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 5, true );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00010: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00011: Normal(Talk, TargetCanMove), id=TUATKK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsc005:66478 calling Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LIAUTROIX" );
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
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc005 );
