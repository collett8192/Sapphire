// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_5 = ALPHINAUD
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna316 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna316() : Sapphire::ScriptAPI::EventScript( 67153 ){}; 
  ~HeaVna316() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1013584
  //ACTOR1 = 1014545
  //ACTOR10 = 1012660
  //ACTOR11 = 1012661
  //ACTOR12 = 1012662
  //ACTOR13 = 1012663
  //ACTOR2 = 1014201
  //ACTOR3 = 1012657
  //ACTOR4 = 1014104
  //ACTOR5 = 1014105
  //ACTOR6 = 1014106
  //ACTOR7 = 5010000
  //ACTOR8 = 1012658
  //ACTOR9 = 1012659
  //CUTSCENEN01 = 817
  //CUTSCENEN02 = 818
  //CUTSCENEN03 = 819
  //CUTSCENEN04 = 820
  //EOBJECT0 = 2005448
  //EVENTACTIONWAITING2MIDDLE = 12
  //INSTANCEDUNGEON0 = 37
  //LOCACTOR0 = 5899419
  //LOCACTOR1 = 5899424
  //LOCACTOR10 = 5911058
  //LOCACTOR11 = 5905908
  //LOCACTOR2 = 5899423
  //LOCSCREENIMAGE0 = 306
  //POPRANGE0 = 5858014
  //TERRITORYTYPE0 = 400

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1013584 || param2 == 1013584 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1014545 || param2 == 1014545 ) // ACTOR1 = ESTINIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1014201 || param2 == 1014201 ) // ACTOR2 = ICEHEART
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012657 || param2 == 1012657 ) // ACTOR3 = VIDOFNIR
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove, ENpcBind), id=VIDOFNIR
          }
          break;
        }
        if( param1 == 1014104 || param2 == 1014104 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1014105 || param2 == 1014105 ) // ACTOR5 = ESTINIEN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1014106 || param2 == 1014106 ) // ACTOR6 = ICEHEART
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2005448 || param2 == 2005448 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(CutScene), id=unknown
            // +Callback Scene00010: Normal(Message, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1012657 || param2 == 1012657 ) // ACTOR3 = VIDOFNIR
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=VIDOFNIR
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012658 || param2 == 1012658 ) // ACTOR8 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012659 || param2 == 1012659 ) // ACTOR9 = ESTINIEN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012660 || param2 == 1012660 ) // ACTOR10 = ICEHEART
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00015( player ); // Scene00015: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012661 || param2 == 1012661 ) // ACTOR11 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012662 || param2 == 1012662 ) // ACTOR12 = ESTINIEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012663 || param2 == 1012663 ) // ACTOR13 = ICEHEART
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ICEHEART
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna316:67153 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00002: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00003: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00004: Normal(Talk, TargetCanMove, ENpcBind), id=VIDOFNIR" );
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
    player.sendDebug( "HeaVna316:67153 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00006: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00007: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00009: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00010( Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00010: Normal(Message, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00011: Normal(Talk, TargetCanMove), id=VIDOFNIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00013: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00014: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00015: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00017: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna316:67153 calling Scene00018: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna316 );
