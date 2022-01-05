// FFXIVTheMovie.ParserV3.6
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
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=IANNA
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack 4
      //seq 1 event item ITEM1 = UI8CH max stack 2
      case 1:
      {
        if( param1 == 3 || param2 == 3 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 4 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        if( param1 == 23 || param2 == 23 ) // ENEMY1 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 2 )
          {
            player.setQuestUI8CH( getId(), player.getQuestUI8CH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 4
      //seq 2 event item ITEM1 = UI8BL max stack 2
      case 2:
      {
        // empty entry
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack 2
      case 3:
      {
        if( param1 == 2002258 || param2 == 2002258 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001930 || param2 == 2001930 ) // EOBJECT1 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2002258 || param2 == 2002258 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001930 || param2 == 2001930 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001931 || param2 == 2001931 ) // EOBJECT2 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1000594 || param2 == 1000594 ) // ACTOR0 = IANNA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=IANNA
          break;
        }
        if( param1 == 2001930 || param2 == 2001930 ) // EOBJECT1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 2001931 || param2 == 2001931 ) // EOBJECT2 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
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
    if( player.getQuestUI8BL( getId() ) == 4 )
      if( player.getQuestUI8CH( getId() ) == 2 )
      {
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 3 );
      }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.setQuestUI8BL( getId(), 0 );
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
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
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=IANNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }




  void Scene00003( Entity::Player& player ) //SEQ_3: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq3( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_4: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq4( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=IANNA" );
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

  void Scene00016( Entity::Player& player ) //SEQ_255: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa205:66264 calling Scene00018: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsa205 );
