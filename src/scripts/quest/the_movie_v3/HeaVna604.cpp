// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_13 = TATARU
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna604 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna604() : Sapphire::ScriptAPI::EventScript( 67189 ){}; 
  ~HeaVna604() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1012398
  //ACTOR1 = 1012399
  //ACTOR2 = 1006756
  //ACTOR3 = 1000691
  //ACTOR4 = 1000692
  //CUTSCENEN01 = 879
  //CUTSCENEN02 = 969
  //ITEM0 = 2001798
  //ITEM1 = 2001799
  //QSTCOMPCHECK01 = 65641
  //QSTCOMPCHECK02 = 65747
  //QSTCOMPCHECK03 = 65558

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012398 || actorId == 1012398 ) // ACTOR0 = TATARU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU
        }
        if( actor == 1012399 || actorId == 1012399 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1006756 || actorId == 1006756 ) // ACTOR2 = YMHITRA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YMHITRA
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BL max stack 1
      //seq 1 event item ITEM1 = UI8CH max stack 1
      case 1:
      {
        if( actor == 1000691 || actorId == 1000691 ) // ACTOR3 = GEVA
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GEVA
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=GEVA
          }
        }
        if( actor == 1012398 || actorId == 1012398 ) // ACTOR0 = TATARU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1012399 || actorId == 1012399 ) // ACTOR1 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1006756 || actorId == 1006756 ) // ACTOR2 = YMHITRA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YMHITRA
        }
        if( actor == 1000692 || actorId == 1000692 ) // ACTOR4 = ESUMIYAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ESUMIYAN
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=ESUMIYAN
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      case 255:
      {
        if( actor == 1012398 || actorId == 1012398 ) // ACTOR0 = TATARU
        {
          Scene00011( player ); // Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00012: Normal(Talk, QuestReward, TargetCanMove), id=TATARU
          // +Callback Scene00013: Normal(CutScene, QuestComplete), id=TATARU
        }
        if( actor == 1012399 || actorId == 1012399 ) // ACTOR1 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1000691 || actorId == 1000691 ) // ACTOR3 = GEVA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=GEVA
        }
        if( actor == 1000692 || actorId == 1000692 ) // ACTOR4 = ESUMIYAN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ESUMIYAN
        }
        if( actor == 1006756 || actorId == 1006756 ) // ACTOR2 = YMHITRA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=YMHITRA
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
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 255 );
        player.setQuestUI8BH( getId(), 1 );
        player.setQuestUI8BL( getId(), 1 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna604:67189 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00003: Normal(Talk, TargetCanMove), id=YMHITRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00004: Normal(Talk, TargetCanMove), id=GEVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=GEVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00006: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00008: Normal(Talk, TargetCanMove), id=YMHITRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00009: Normal(Talk, TargetCanMove), id=ESUMIYAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling [BranchTrue]Scene00010: Normal(Talk, TargetCanMove), id=ESUMIYAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00012( player );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling [BranchTrue]Scene00012: Normal(Talk, QuestReward, TargetCanMove), id=TATARU" );
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
    player.sendDebug( "HeaVna604:67189 calling [BranchChain]Scene00013: Normal(CutScene, QuestComplete), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00015: Normal(Talk, TargetCanMove), id=GEVA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00016: Normal(Talk, TargetCanMove), id=ESUMIYAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna604:67189 calling Scene00017: Normal(Talk, TargetCanMove), id=YMHITRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna604 );
