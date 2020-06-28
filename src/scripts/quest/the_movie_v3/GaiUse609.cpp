// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_4 = THUBYRGEIM_2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse609 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse609() : Sapphire::ScriptAPI::EventScript( 65957 ){}; 
  ~GaiUse609() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1010897
  //ACTOR1 = 1010980
  //ACTOR2 = 1000909
  //ACTOR3 = 1010981
  //EOBJECT0 = 2005073
  //EOBJECT1 = 2005121
  //EVENTACTIONLOOKOUTLONG = 41
  //LOCACTION0 = 620
  //LOCACTOR0 = 1011633
  //LOCACTOR1 = 1011280
  //LOCACTOR2 = 1011634
  //LOCACTOR3 = 1011635
  //LOCACTOR4 = 1011649
  //LOCCAMERA0 = 5767050
  //LOCEOBJ0 = 2005152
  //LOCFACE0 = 605
  //LOCFACE1 = 607
  //LOCFACE2 = 615
  //LOCPOS0 = 5617120
  //LOCPOS1 = 5617123
  //LOCPOS2 = 5649380
  //LOCPOS3 = 5649381
  //QUESTCHECK01 = 65997
  //QUESTCHECK02 = 65990

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( actor == 1010980 || actorId == 1010980 ) // ACTOR1 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=TATARU
          }
        }
        if( actor == 1000909 || actorId == 1000909 ) // ACTOR2 = THUBYRGEIM
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THUBYRGEIM
        }
        break;
      }
      case 2:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THUBYRGEIM_2
        break;
      }
      case 3:
      {
        if( actor == 2005073 || actorId == 2005073 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
            // +Callback Scene00006: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown
          }
        }
        if( actor == 2005121 || actorId == 2005121 ) // EOBJECT1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( actor == 1010981 || actorId == 1010981 ) // ACTOR3 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=TATARU
          }
        }
        if( actor == 2005121 || actorId == 2005121 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1000909 || actorId == 1000909 ) // ACTOR2 = THUBYRGEIM
        {
          Scene00010( player ); // Scene00010: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=THUBYRGEIM
        }
        if( actor == 2005121 || actorId == 2005121 ) // EOBJECT1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
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
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse609:65957 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00003: Normal(Talk, TargetCanMove), id=THUBYRGEIM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00004: Normal(Talk, TargetCanMove), id=THUBYRGEIM_2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling [BranchTrue]Scene00006: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00010: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=THUBYRGEIM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse609:65957 calling Scene00011: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUse609 );
