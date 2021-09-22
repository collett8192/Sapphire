// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManWil007 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManWil007() : Sapphire::ScriptAPI::EventScript( 66087 ){}; 
  ~ManWil007() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1001353
  //ACTOR1 = 1004005
  //ACTOR2 = 1004002
  //ACTOR3 = 1004003
  //CUTMANWIL00710 = 193
  //CUTMANWIL00745 = 197
  //CUTMANWIL00750 = 143
  //CUTSCENEQIBAFTER01 = 196
  //EOBJECT0 = 2001427
  //EVENTACTIONWAITING3LONG = 13
  //ITEM0 = 2000398
  //POPRANGE0 = 4087066
  //QUESTBATTLE0 = 38
  //TERRITORYTYPE0 = 210
  //TERRITORYTYPE1 = 271
  //TERRITORYTYPE2 = 141

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=MOMODI
                              // +Callback Scene00001: Normal(CutScene), id=unknown
                              // +Callback Scene00002: Normal(QuestAccept), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( actor == 1004005 || actorId == 1004005 ) // ACTOR1 = SULTANSWORMA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, YesNo, TargetCanMove), id=SULTANSWORMA
        }
        if( actor == 1004002 || actorId == 1004002 ) // ACTOR2 = OWYNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown
                                  // +Callback Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=OWYNE
          }
        }
        break;
      }
      case 2:
      {
        if( actor == 2001427 || actorId == 2001427 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
          }
        }
        if( actor == 1004002 || actorId == 1004002 ) // ACTOR2 = unknown
        {
          Scene00009( player ); 
        }
        break;
      }
      case 3:
      {
        if( type != 2 ) Scene00010( player );
      }
      case 255:
      {
        if( actor == 1004005 || actorId == 1004005 )
        {
          Scene00011( player );
        }
        if( actor == 1004003 || actorId == 1004003 ) 
        {
          Scene00012( player );
        }
        if( actor == 1004002 || actorId == 1004002 ) 
        {
          Scene00014( player );
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
    player.setQuestUI8BH( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=MOMODI" );
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
    player.sendDebug( "ManWil007:66087 calling Scene00001: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00002: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00003: Normal(Talk, YesNo, TargetCanMove), id=SULTANSWORMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 210 );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=OWYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00006: Normal(None), id=unknown" );
    Scene00008( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00008: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        //quest battle
        player.eventFinish( getId(), 1 );
        auto& pTeriMgr = Common::Service< Sapphire::World::Manager::TerritoryMgr >::ref();
        pTeriMgr.createAndJoinQuestBattle( player, 38 );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00009: Normal(Talk, TargetCanMove), id=OWYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00010: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00011: Normal(Talk, YesNo, TargetCanMove), id=SULTANSWORMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 210 );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "ManWil007:66087 calling Scene00012: Normal(QuestReward), id=unknown" );
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
    player.sendDebug( "ManWil007:66087 calling Scene00013: Normal(CutScene, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.playScene( getId(), 14, NONE, nullptr );
  }
};

EXPOSE_SCRIPT( ManWil007 );
