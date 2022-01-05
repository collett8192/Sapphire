// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb411 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb411() : Sapphire::ScriptAPI::EventScript( 66403 ){}; 
  ~GaiUsb411() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006333
  //ACTOR1 = 1006334
  //ACTOR2 = 1006335
  //ACTOR3 = 1006336
  //ACTOR4 = 1006337
  //EOBJECT0 = 2002096
  //EOBJECT1 = 2002260
  //EVENTACTIONSEARCHLONG = 4
  //ITEM0 = 2000674
  //ITEM1 = 2000675

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ARHUNLIKA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
        break;
      }
      //seq 2 event item ITEM1 = UI8BH max stack 1
      case 2:
      {
        if( type != 2 ) Scene00005( player ); // Scene00005: Normal(None), id=unknown
        break;
      }
      //seq 3 event item ITEM1 = UI8CL max stack 1
      case 3:
      {
        if( param1 == 1006334 || param2 == 1006334 ) // ACTOR1 = IMUMU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: NpcTrade(Talk), id=unknown
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=IMUMU
          }
          break;
        }
        if( param1 == 1006335 || param2 == 1006335 ) // ACTOR2 = HBHOWAKA
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: NpcTrade(Talk), id=unknown
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=HBHOWAKA
          }
          break;
        }
        if( param1 == 1006336 || param2 == 1006336 ) // ACTOR3 = OSTSYGG
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: NpcTrade(Talk), id=unknown
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=OSTSYGG
          }
          break;
        }
        if( param1 == 1006337 || param2 == 1006337 ) // ACTOR4 = SWAENLONA
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: NpcTrade(Talk), id=unknown
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=SWAENLONA
          }
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ARHUNLIKA
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
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 3 );
    player.setQuestUI8CL( getId(), 1 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestBitFlag8( getId(), 1, false );
            player.setQuestBitFlag8( getId(), 2, false );
            player.setQuestBitFlag8( getId(), 3, false );
            player.setQuestBitFlag8( getId(), 4, false );
            player.setQuestUI8CL( getId(), 0 );
            player.updateQuest( getId(), 255 );
          }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb411:66403 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ARHUNLIKA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00006( Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00006: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_3: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00007: Normal(Talk, TargetCanMove), id=IMUMU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00008: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00009: Normal(Talk, TargetCanMove), id=HBHOWAKA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00010: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00011: Normal(Talk, TargetCanMove), id=OSTSYGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00012: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00013: Normal(Talk, TargetCanMove), id=SWAENLONA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb411:66403 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ARHUNLIKA" );
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
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb411 );
