// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsd203 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsd203() : Sapphire::ScriptAPI::EventScript( 66737 ){}; 
  ~GaiUsd203() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 8 entries
  //SEQ_4, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006725
  //ACTOR1 = 1000768
  //ACTOR2 = 1007760
  //ENEMY0 = 4502639
  //ENEMY1 = 4502640
  //ENEMY2 = 4502641
  //EOBJECT0 = 2002893
  //EOBJECT1 = 2002894
  //EOBJECT2 = 2002895
  //EOBJECT3 = 2002898
  //EOBJECT4 = 2002896
  //EVENTRANGE0 = 4499387
  //EVENTACTIONPROCESSUPPERLONG = 33
  //EVENTACTIONPROCESSUPPERMIDDLE = 32
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001100
  //ITEM1 = 2001101
  //LOCACTION0 = 81
  //LOCACTION1 = 82
  //LOCEOBJ1 = 2003014
  //LOCFACE0 = 604
  //LOCFACE1 = 617
  //LOCPOSACTOR0 = 4513214
  //LOCPOSCAM1 = 4513638
  //LOCPOSEOBJ1 = 4499380
  //LOCTALKSHAPE1 = 6
  //NCUTEVENTGAIUSD2031 = 444

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAMMBROES
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=PARSEMONTRET
        break;
      }
      case 2:
      {
        if( actor == 2002893 || actorId == 2002893 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
          }
        }
        if( actor == 1007760 || actorId == 1007760 ) // ACTOR2 = GRAHATIA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, FadeIn), id=GRAHATIA
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( actor == 4499387 || actorId == 4499387 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
        }
        if( actor == 2002894 || actorId == 2002894 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4502639 || actorId == 4502639 ) // ENEMY0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(Message), id=unknown
        }
        if( actor == 4502640 || actorId == 4502640 ) // ENEMY1 = GRAHATIA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, FadeIn), id=GRAHATIA
        }
        if( actor == 4502641 || actorId == 4502641 ) // ENEMY2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1007760 || actorId == 1007760 ) // ACTOR2 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 2002895 || actorId == 2002895 ) // EOBJECT2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 2002898 || actorId == 2002898 ) // EOBJECT3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      //seq 4 event item ITEM1 = UI8BL max stack 1
      case 4:
      {
        if( actor == 2002896 || actorId == 2002896 ) // EOBJECT4 = GRAHATIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, FadeIn), id=GRAHATIA
          }
        }
        if( actor == 2002898 || actorId == 2002898 ) // EOBJECT3 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        Scene00015( player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00016: Normal(Talk, QuestReward, QuestComplete), id=RAMMBROES
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
    player.updateQuest( getId(), 2 );
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
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
      {
        player.setQuestUI8AL( getId(), 0 );
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
      player.setQuestUI8BL( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsd203:66737 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00002: Normal(Talk, TargetCanMove), id=PARSEMONTRET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00003: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00004: Normal(Talk, FadeIn), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 3 );
    checkProgressSeq3( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00007: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00008: Normal(Talk, FadeIn), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00013: Normal(Talk, FadeIn), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd203:66737 calling [BranchTrue]Scene00016: Normal(Talk, QuestReward, QuestComplete), id=RAMMBROES" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd203 );
