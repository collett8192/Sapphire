// FFXIVTheMovie.ParserV3.6
// id table disabled
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna301 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna301() : Sapphire::ScriptAPI::EventScript( 67138 ){}; 
  ~HeaVna301() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 10 entries
  //SEQ_2, 4 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1013038
  //ACTOR1 = 1012843
  //ACTOR10 = 1012584
  //ACTOR11 = 1012579
  //ACTOR12 = 1012586
  //ACTOR2 = 1003995
  //ACTOR3 = 1014644
  //ACTOR4 = 1014643
  //ACTOR5 = 1012581
  //ACTOR6 = 1012840
  //ACTOR7 = 1012841
  //ACTOR8 = 1012582
  //ACTOR9 = 1012583
  //LOCACTION1 = 1002
  //LOCACTOR0 = 5852743
  //LOCACTOR1 = 5852741
  //LOCACTOR2 = 5852742
  //LOCACTOR3 = 1008181
  //LOCACTOR4 = 1008182
  //LOCACTOR5 = 5852745
  //LOCSE1 = 42
  //POPRANGE0 = 5912489
  //TERRITORYTYPE0 = 433

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1013038 || param2 == 1013038 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012843 || param2 == 1012843 ) // ACTOR1 = PAPASHAN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        if( param1 == 1003995 || param2 == 1003995 ) // ACTOR2 = PAPASHAN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1014644 || param2 == 1014644 ) // ACTOR3 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=TATARU
          }
          break;
        }
        if( param1 == 1014643 || param2 == 1014643 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012843 || param2 == 1012843 ) // ACTOR1 = PAPASHAN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        if( param1 == 1003995 || param2 == 1003995 ) // ACTOR2 = PAPASHAN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        if( param1 == 1012581 || param2 == 1012581 ) // ACTOR5 = HAURCHEFANT
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1012840 || param2 == 1012840 ) // ACTOR6 = PIPPIN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=PIPPIN
          break;
        }
        if( param1 == 1012841 || param2 == 1012841 ) // ACTOR7 = DEWLALA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=DEWLALA
          break;
        }
        if( param1 == 1012582 || param2 == 1012582 ) // ACTOR8 = ARTOIREL
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1012583 || param2 == 1012583 ) // ACTOR9 = EMMANELLAIN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012584 || param2 == 1012584 ) // ACTOR10 = EDMONT
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=EDMONT
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00014( player ); // Scene00014: Normal(Talk, FadeIn, ENpcBind), id=unknown
          break;
        }
        if( param1 == 1012581 || param2 == 1012581 ) // ACTOR5 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1014643 || param2 == 1014643 ) // ACTOR4 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1014644 || param2 == 1014644 ) // ACTOR3 = TATARU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012579 || param2 == 1012579 ) // ACTOR11 = ALPHINAUD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu), id=ALPHINAUD
          break;
        }
        if( param1 == 1012581 || param2 == 1012581 ) // ACTOR5 = HAURCHEFANT
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=HAURCHEFANT
          break;
        }
        if( param1 == 1012586 || param2 == 1012586 ) // ACTOR12 = TATARU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1012582 || param2 == 1012582 ) // ACTOR8 = ARTOIREL
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ARTOIREL
          break;
        }
        if( param1 == 1012583 || param2 == 1012583 ) // ACTOR9 = EMMANELLAIN
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          break;
        }
        if( param1 == 1012584 || param2 == 1012584 ) // ACTOR10 = EDMONT
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=EDMONT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00002: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00003: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00004: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00006: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00007: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00008: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00009: Normal(Talk, TargetCanMove), id=PIPPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00010: Normal(Talk, TargetCanMove), id=DEWLALA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00011: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00012: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00013: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00014: Normal(Talk, FadeIn, ENpcBind), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00017: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00018: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, Menu), id=ALPHINAUD" );
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
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00019: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00020: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00021: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00022: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna301:67138 calling Scene00023: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna301 );
