// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb913 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb913() : Sapphire::ScriptAPI::EventScript( 66472 ){}; 
  ~GaiUsb913() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 12 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006460
  //ENEMY0 = 4293236
  //ENEMY1 = 4293237
  //ENEMY2 = 4293238
  //ENEMY3 = 4293239
  //ENEMY4 = 4293240
  //ENEMY5 = 4293241
  //ENEMY6 = 4293242
  //ENEMY7 = 4293243
  //ENEMY8 = 4293244
  //ENEMY9 = 4293246
  //EOBJECT0 = 2002166
  //EOBJECT1 = 2002167
  //EOBJECT2 = 2002168
  //EOBJECT3 = 2002169
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONSEARCHMIDDLE = 3

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FOUSQUENET
        break;
      }
      case 1:
      {
        if( param1 == 2002166 || param2 == 2002166 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00003( player ); // Scene00003: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4293236 || param2 == 4293236 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4293237 || param2 == 4293237 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4293238 || param2 == 4293238 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002167 || param2 == 2002167 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4293239 || param2 == 4293239 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4293240 || param2 == 4293240 ) // ENEMY4 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4293241 || param2 == 4293241 ) // ENEMY5 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 2002168 || param2 == 2002168 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4293242 || param2 == 4293242 ) // ENEMY6 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4293243 || param2 == 4293243 ) // ENEMY7 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 4293244 || param2 == 4293244 ) // ENEMY8 = unknown
        {
          // empty entry
          break;
        }
        break;
      }
      case 2:
      {
        if( type != 2 ) Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=FOUSQUENET
        break;
      }
      case 3:
      {
        if( param1 == 2002169 || param2 == 2002169 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4293246 || param2 == 4293246 ) // ENEMY9 = unknown
        {
          // empty entry
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00011( player ); // Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FOUSQUENET
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
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8BH( getId() ) == 3 )
        if( player.getQuestUI8BL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 2, false );
          player.setQuestBitFlag8( getId(), 3, false );
          player.updateQuest( getId(), 2 );
        }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
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
    player.sendDebug( "GaiUsb913:66472 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb913:66472 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=FOUSQUENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb913:66472 calling Scene00003: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }




  void Scene00005( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8BH = 3, Flag8(2)=True
  {
    player.sendDebug( "GaiUsb913:66472 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 3 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }




  void Scene00007( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8BL = 3, Flag8(3)=True
  {
    player.sendDebug( "GaiUsb913:66472 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }




  void Scene00008( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb913:66472 calling Scene00008: Normal(Talk, TargetCanMove), id=FOUSQUENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: EOBJECT3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb913:66472 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }


  void Scene00011( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb913:66472 calling Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=FOUSQUENET" );
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
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb913 );
