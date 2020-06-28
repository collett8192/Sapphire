// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa105 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa105() : Sapphire::ScriptAPI::EventScript( 66255 ){}; 
  ~GaiUsa105() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 1 entries
  //SEQ_3, 7 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTJOYBIG = 945
  //ACTIONTIMELINEEVENTTALKENTREAT = 951
  //ACTIONTIMELINEEVENTTROUBLE = 944
  //ACTOR0 = 1000580
  //ACTOR1 = 1000585
  //ACTOR2 = 1000277
  //ACTOR3 = 1000553
  //ACTOR4 = 1000545
  //ENEMY0 = 4278151
  //ENEMY1 = 4278153
  //ENEMY2 = 4278162
  //ENEMY3 = 4278167
  //EOBJECT0 = 2001918
  //EOBJECT1 = 2002280
  //EVENTRANGE0 = 4289786
  //EVENTACTIONGATHERMIDDLE = 7
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000578

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=KOMUXIO
        // +Callback Scene00001: Normal(QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( actor == 1000585 || actorId == 1000585 ) // ACTOR1 = PELIXIA
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=PELIXIA
          }
        }
        if( actor == 1000277 || actorId == 1000277 ) // ACTOR2 = NATHAXIO
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=NATHAXIO
          }
        }
        if( actor == 1000553 || actorId == 1000553 ) // ACTOR3 = MONNE
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MONNE
          }
        }
        if( actor == 1000545 || actorId == 1000545 ) // ACTOR4 = VICTOR
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=VICTOR
          }
        }
        break;
      }
      case 2:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KOMUXIO
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( actor == 4289786 || actorId == 4289786 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00007( player ); // Scene00007: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 2001918 || actorId == 2001918 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00008( player ); // Scene00008: Normal(Message), id=unknown
            // +Callback Scene00009: Normal(None), id=unknown
          }
        }
        if( actor == 4278151 || actorId == 4278151 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4278153 || actorId == 4278153 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4278162 || actorId == 4278162 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4278167 || actorId == 4278167 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 2002280 || actorId == 2002280 ) // EOBJECT1 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( actor == 1000580 || actorId == 1000580 ) // ACTOR0 = KOMUXIO
        {
          Scene00012( player ); // Scene00012: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KOMUXIO
        }
        if( actor == 2001918 || actorId == 2001918 ) // EOBJECT0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          // +Callback Scene00015: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 4 )
      if( player.getQuestUI8AL( getId() ) == 4 )
        if( player.getQuestUI8AL( getId() ) == 4 )
          if( player.getQuestUI8AL( getId() ) == 4 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.updateQuest( getId(), 2 );
          }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 4 )
      if( player.getQuestUI8AL( getId() ) == 4 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 1 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=KOMUXIO" );
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
    player.sendDebug( "GaiUsa105:66255 calling [BranchTrue]Scene00001: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00002: Normal(Talk, TargetCanMove), id=PELIXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00003: Normal(Talk, TargetCanMove), id=NATHAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00004: Normal(Talk, TargetCanMove), id=MONNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00005: Normal(Talk, TargetCanMove), id=VICTOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00006: Normal(Talk, TargetCanMove), id=KOMUXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00008: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 4 );
    checkProgressSeq3( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling [BranchTrue]Scene00011: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00012: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling [BranchTrue]Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KOMUXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling Scene00014: Normal(None), id=unknown" );
    Scene00015( player );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa105:66255 calling [BranchTrue]Scene00015: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsa105 );
