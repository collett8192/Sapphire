// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubSea118 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubSea118() : Sapphire::ScriptAPI::EventScript( 65951 ){}; 
  ~SubSea118() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 7 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002274
  //ACTOR1 = 1002456
  //ACTOR2 = 1002238
  //ENEMY0 = 3781826
  //ENEMY1 = 3781831
  //ENEMY2 = 3781834
  //EOBJECT0 = 2000769
  //EOBJECT1 = 2000770
  //EOBJECT2 = 2000771
  //EVENTACTIONGATHERSHORT = 6
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000222
  //ITEM1 = 2000223
  //ITEM2 = 2000224

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=HALDBRODA
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=FYRILSMYD
        break;
      }
      //seq 2 event item ITEM0 = UI8BL max stack 1
      //seq 2 event item ITEM1 = UI8CH max stack 1
      //seq 2 event item ITEM2 = UI8CL max stack 1
      case 2:
      {
        if( param1 == 2000769 || param2 == 2000769 ) // EOBJECT0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(Message), id=unknown
          break;
        }
        if( param1 == 3781826 || param2 == 3781826 ) // ENEMY0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(Message), id=unknown
          break;
        }
        if( param1 == 2000770 || param2 == 2000770 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Message), id=unknown
          break;
        }
        if( param1 == 3781831 || param2 == 3781831 ) // ENEMY1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(Message), id=unknown
          break;
        }
        if( param1 == 2000771 || param2 == 2000771 ) // EOBJECT2 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(Message), id=unknown
          break;
        }
        if( param1 == 3781834 || param2 == 3781834 ) // ENEMY2 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(Message), id=unknown
          break;
        }
        if( param1 == 1002456 || param2 == 1002456 ) // ACTOR1 = FYRILSMYD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=FYRILSMYD
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      //seq 3 event item ITEM1 = UI8BL max stack 1
      //seq 3 event item ITEM2 = UI8CH max stack 1
      case 3:
      {
        if( type != 2 ) Scene00021( player ); // Scene00021: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=FYRILSMYD
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      //seq 255 event item ITEM2 = UI8CH max stack 1
      case 255:
      {
        if( type != 2 ) Scene00024( player ); // Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AHTBYRM
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
    player.setQuestBitFlag8( getId(), 1, false );
    player.setQuestBitFlag8( getId(), 2, false );
    player.setQuestBitFlag8( getId(), 3, false );
    player.setQuestUI8BL( getId(), 0 );
    player.setQuestUI8CH( getId(), 0 );
    player.setQuestUI8CL( getId(), 0 );
    player.updateQuest( getId(), 3 );
    player.setQuestUI8BH( getId(), 1 );
    player.setQuestUI8BL( getId(), 1 );
    player.setQuestUI8CH( getId(), 1 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea118:65951 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=HALDBRODA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea118:65951 calling Scene00001: Normal(Talk, TargetCanMove), id=FYRILSMYD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_2: EOBJECT0, <No Var>, Flag8(1)=True
  {
    player.sendDebug( "SubSea118:65951 calling Scene00003: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea118:65951 calling Scene00006: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: EOBJECT1, <No Var>, Flag8(2)=True
  {
    player.sendDebug( "SubSea118:65951 calling Scene00009: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea118:65951 calling Scene00012: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: EOBJECT2, <No Var>, Flag8(3)=True
  {
    player.sendDebug( "SubSea118:65951 calling Scene00015: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea118:65951 calling Scene00018: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea118:65951 calling Scene00020: Normal(Talk, TargetCanMove), id=FYRILSMYD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea118:65951 calling Scene00021: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00022( player );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player ) //SEQ_3: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea118:65951 calling Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=FYRILSMYD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubSea118:65951 calling Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AHTBYRM" );
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
    player.playScene( getId(), 24, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubSea118 );
