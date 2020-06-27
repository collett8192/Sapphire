// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse113 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse113() : Sapphire::ScriptAPI::EventScript( 66723 ){}; 
  ~GaiUse113() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 10 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTTALKBIG = 950
  //ACTOR0 = 1003785
  //ACTOR1 = 1006429
  //ACTOR2 = 1006428
  //ENEMY0 = 4495061
  //ENEMY1 = 4495062
  //ENEMY2 = 4495064
  //ENEMY3 = 4495065
  //EOBJECT0 = 2002854
  //EOBJECT1 = 2002855
  //EOBJECT2 = 2002856
  //EOBJECT3 = 2002857
  //EVENTACTIONLEVELSQUATMIDDLE = 21
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001081
  //LOCACTION0 = 860
  //LOCACTOR0 = 1007817
  //LOCBGM1 = 88
  //LOCFACE0 = 606
  //LOCPOSACTOR0 = 4529297
  //LOCPOSACTOR1 = 4535860

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU
        break;
      }
      case 1:
      {
        if( actor == 1006429 || actorId == 1006429 ) // ACTOR1 = MEDGUISTL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MEDGUISTL
          }
        }
        if( actor == 1003785 || actorId == 1003785 ) // ACTOR0 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 2:
      {
        if( actor == 1006428 || actorId == 1006428 ) // ACTOR2 = EMANUEL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=EMANUEL
          }
        }
        if( actor == 1003785 || actorId == 1003785 ) // ACTOR0 = TATARU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8DH max stack 4
      case 3:
      {
        if( actor == 2002854 || actorId == 2002854 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 2002855 || actorId == 2002855 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(None), id=unknown
          }
        }
        if( actor == 2002856 || actorId == 2002856 ) // EOBJECT2 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          // +Callback Scene00011: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4495061 || actorId == 4495061 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4495062 || actorId == 4495062 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002857 || actorId == 2002857 ) // EOBJECT3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          // +Callback Scene00013: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 4495064 || actorId == 4495064 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4495065 || actorId == 4495065 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 1003785 || actorId == 1003785 ) // ACTOR0 = TATARU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1006428 || actorId == 1006428 ) // ACTOR2 = EMANUEL
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=EMANUEL
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 4
      case 255:
      {
        Scene00016( player ); // Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00017: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
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
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8BL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8DH( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 4 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse113:66723 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00002: Normal(Talk, TargetCanMove), id=MEDGUISTL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00004: Normal(Talk, TargetCanMove), id=EMANUEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00005: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling [BranchTrue]Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00012: Normal(None), id=unknown" );
    Scene00013( player );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling [BranchTrue]Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00014: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00015: Normal(Talk, TargetCanMove), id=EMANUEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00017( player );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse113:66723 calling [BranchTrue]Scene00017: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUse113 );
