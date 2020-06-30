// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna115 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna115() : Sapphire::ScriptAPI::EventScript( 67130 ){}; 
  ~HeaVna115() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_4, 9 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINETALKJOKE = 4220
  //ACTOR0 = 1012060
  //ACTOR1 = 1011952
  //ACTOR2 = 1012354
  //ACTOR3 = 1012355
  //ACTOR4 = 1012363
  //ACTOR5 = 1012364
  //ACTOR6 = 1012365
  //EOBJECT0 = 2005412
  //EOBJECT1 = 2005413
  //EOBJECT2 = 2005414
  //EOBJECT3 = 2005415
  //EOBJECT4 = 2005416
  //EOBJECT5 = 2005417
  //EOBJECT6 = 2005492
  //EVENTACTIONSEEKUPPERLONG = 55
  //EVENTACTIONSEEKUPPERMIDDLE = 54
  //ITEM0 = 2001574
  //QSTACTOR1 = 5857464

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MARIELLE
        break;
      }
      case 1:
      {
        if( actor == 1011952 || actorId == 1011952 ) // ACTOR1 = LANIAITTE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LANIAITTE
          }
        }
        if( actor == 1012354 || actorId == 1012354 ) // ACTOR2 = EMMANELLAIN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1012355 || actorId == 1012355 ) // ACTOR3 = HONOROIT
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( actor == 1012060 || actorId == 1012060 ) // ACTOR0 = MARIELLE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MARIELLE
        }
        break;
      }
      case 2:
      {
        if( actor == 1012354 || actorId == 1012354 ) // ACTOR2 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=EMMANELLAIN
          }
        }
        if( actor == 1012355 || actorId == 1012355 ) // ACTOR3 = HONOROIT
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( actor == 1011952 || actorId == 1011952 ) // ACTOR1 = LANIAITTE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LANIAITTE
        }
        break;
      }
      case 3:
      {
        if( actor == 1012363 || actorId == 1012363 ) // ACTOR4 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=EMMANELLAIN
          }
        }
        if( actor == 1011952 || actorId == 1011952 ) // ACTOR1 = LANIAITTE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LANIAITTE
        }
        if( actor == 1012364 || actorId == 1012364 ) // ACTOR5 = HONOROIT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( actor == 2005412 || actorId == 2005412 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
            // +Callback Scene00013: Normal(None), id=unknown
          }
        }
        if( actor == 1012365 || actorId == 1012365 ) // ACTOR6 = EMMANELLAIN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1012364 || actorId == 1012364 ) // ACTOR5 = HONOROIT
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( actor == 2005413 || actorId == 2005413 ) // EOBJECT1 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          // +Callback Scene00017: Normal(None), id=unknown
        }
        if( actor == 2005414 || actorId == 2005414 ) // EOBJECT2 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(None), id=unknown
        }
        if( actor == 2005415 || actorId == 2005415 ) // EOBJECT3 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(None), id=unknown
        }
        if( actor == 2005416 || actorId == 2005416 ) // EOBJECT4 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          // +Callback Scene00023: Normal(None), id=unknown
        }
        if( actor == 2005417 || actorId == 2005417 ) // EOBJECT5 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          // +Callback Scene00025: Normal(None), id=unknown
        }
        if( actor == 2005492 || actorId == 2005492 ) // EOBJECT6 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          // +Callback Scene00027: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        Scene00028( player ); // Scene00028: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HONOROIT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna115:67130 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MARIELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00002: Normal(Talk, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00003: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00004: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00005: Normal(Talk, TargetCanMove), id=MARIELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00007: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00008: Normal(Talk, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00010: Normal(Talk, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00011: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling [BranchTrue]Scene00013: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00014: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00015: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00016: Normal(None), id=unknown" );
    Scene00017( player );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling [BranchTrue]Scene00017: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling [BranchTrue]Scene00021: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00022: Normal(None), id=unknown" );
    Scene00023( player );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling [BranchTrue]Scene00023: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00024: Normal(None), id=unknown" );
    Scene00025( player );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling [BranchTrue]Scene00025: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00026: Normal(None), id=unknown" );
    Scene00027( player );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling [BranchTrue]Scene00027: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling Scene00028: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00029( player );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVna115:67130 calling [BranchTrue]Scene00029: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna115 );
