// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_4 = KANESENNA
//SCENE_13 = YMHITRA
//fix: enter instance, black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna603 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna603() : Sapphire::ScriptAPI::EventScript( 67188 ){}; 
  ~HeaVna603() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_3, 2 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1012394
  //ACTOR1 = 1013157
  //ACTOR2 = 1003027
  //ACTOR3 = 1000460
  //ACTOR4 = 1012396
  //ACTOR5 = 1012395
  //ACTOR6 = 1006756
  //ACTOR7 = 1012398
  //ACTOR8 = 1012399
  //CUTSCENEN01 = 877
  //CUTSCENEN02 = 878
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1012493
  //LOCACTOR2 = 4065819
  //LOCACTOR3 = 4065820
  //LOCACTOR4 = 4065821
  //LOCACTOR5 = 4065822
  //LOCACTOR6 = 4065823
  //LOCBGM0 = 211
  //POPRANGE0 = 3877982
  //POPRANGE1 = 5861505
  //POPRANGE2 = 5862298
  //QSTACTOR0 = 5916152
  //QSTCOMPCHECK01 = 66627
  //TERRITORYTYPE0 = 205

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012394 || actorId == 1012394 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013157 || actorId == 1013157 ) // ACTOR1 = TATARU
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 1:
      {
        if( actor == 1003027 || actorId == 1003027 ) // ACTOR2 = KANESENNA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=KANESENNA
            // +Callback Scene00004: Normal(CutScene), id=KANESENNA
          }
        }
        if( actor == 1000460 || actorId == 1000460 ) // ACTOR3 = DOORMANLOTUS
        {
          Scene00005( player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove), id=DOORMANLOTUS
        }
        if( actor == 1012394 || actorId == 1012394 ) // ACTOR0 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013157 || actorId == 1013157 ) // ACTOR1 = TATARU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 2:
      {
        if( actor == 1012396 || actorId == 1012396 ) // ACTOR4 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=TATARU
          }
        }
        if( actor == 1012395 || actorId == 1012395 ) // ACTOR5 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1006756 || actorId == 1006756 ) // ACTOR6 = YMHITRA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YMHITRA
        }
        if( actor == 1000460 || actorId == 1000460 ) // ACTOR3 = DOORMANLOTUS
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=DOORMANLOTUS
        }
        break;
      }
      case 3:
      {
        if( actor == 1006756 || actorId == 1006756 ) // ACTOR6 = YMHITRA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=YMHITRA
            // +Callback Scene00013: Normal(CutScene), id=YMHITRA
          }
        }
        if( actor == 1000460 || actorId == 1000460 ) // ACTOR3 = DOORMANLOTUS
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=DOORMANLOTUS
        }
        break;
      }
      case 255:
      {
        if( actor == 1012398 || actorId == 1012398 ) // ACTOR7 = TATARU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU
        }
        if( actor == 1012399 || actorId == 1012399 ) // ACTOR8 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1006756 || actorId == 1006756 ) // ACTOR6 = YMHITRA
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna603:67188 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00002: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling [BranchTrue]Scene00004: Normal(CutScene), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00005: Normal(Talk, YesNo, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 205 );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00007: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00008: Normal(Talk, NpcDespawn, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00010: Normal(Talk, TargetCanMove), id=YMHITRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00011: Normal(Talk, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=YMHITRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling [BranchTrue]Scene00013: Normal(CutScene), id=YMHITRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 132, 37.15, -8, 99.24, -2.31 );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00014: Normal(Talk, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna603:67188 calling Scene00017: Normal(Talk, TargetCanMove), id=YMHITRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna603 );
