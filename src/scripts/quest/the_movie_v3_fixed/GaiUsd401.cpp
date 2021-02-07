// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsd401 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsd401() : Sapphire::ScriptAPI::EventScript( 67010 ){}; 
  ~GaiUsd401() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 7 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 1 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1006725
  //ACTOR1 = 1009372
  //ACTOR10 = 1007754
  //ACTOR11 = 1007761
  //ACTOR12 = 1007762
  //ACTOR13 = 5010000
  //ACTOR14 = 1007763
  //ACTOR2 = 1009373
  //ACTOR3 = 1009374
  //ACTOR4 = 1009375
  //ACTOR5 = 1009376
  //ACTOR6 = 1009377
  //ACTOR7 = 1009378
  //ACTOR8 = 1009379
  //ACTOR9 = 1009380
  //EVENTACTIONSEARCH = 1
  //INSTANCEDUNGEON0 = 30011
  //LOCACTION1 = 1047
  //LOCACTOR0 = 1005518
  //LOCACTOR1 = 1009149
  //LOCACTOR2 = 1009150
  //LOCACTOR3 = 1003855
  //LOCACTOR4 = 1023900
  //LOCACTOR5 = 1023901
  //LOCACTOR6 = 1023902
  //LOCSE1 = 75
  //MUSICEVENTUNEDOGA01 = 212
  //NCUTEVENTGAIUSD4011 = 546
  //NCUTEVENTGAIUSD4012 = 547
  //NCUTEVENTGAIUSD4013 = 548
  //NCUTEVENTGAIUSD4014 = 549
  //NCUTEVENTGAIUSD4015 = 574
  //NCUTEVENTGAIUSD4016 = 575
  //NCUTEVENTGAIUSD4017 = 576
  //POPRANGE0 = 4833641
  //POPRANGE1 = 4585913
  //QUESTCOMPCHECK = 66899
  //TERRITORYTYPE0 = 156
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEONCRYSTALTOWER2 = 226

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=RAMMBROES
        break;
      }
      case 1:
      {
        if( param1 == 1009372 || param2 == 1009372 ) // ACTOR1 = BIGGS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=BIGGS
            // +Callback Scene00003: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1009373 || param2 == 1009373 ) // ACTOR2 = WEDGE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1009374 || param2 == 1009374 ) // ACTOR3 = DOGA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=DOGA
            // +Callback Scene00006: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1009375 || param2 == 1009375 ) // ACTOR4 = UNEI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=UNEI
          break;
        }
        if( param1 == 1009376 || param2 == 1009376 ) // ACTOR5 = GRAHATIA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=GRAHATIA
          break;
        }
        if( param1 == 1009377 || param2 == 1009377 ) // ACTOR6 = CID
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1009378 || param2 == 1009378 ) // ACTOR7 = NERO
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=NERO
          break;
        }
        if( param1 == 1009379 || param2 == 1009379 ) // ACTOR8 = BIGGS
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1009380 || param2 == 1009380 ) // ACTOR9 = WEDGE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1009376 || param2 == 1009376 ) // ACTOR5 = GRAHATIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, Message, FadeIn, TargetCanMove), id=GRAHATIA
          }
          break;
        }
        if( param1 == 1009374 || param2 == 1009374 ) // ACTOR3 = DOGA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=DOGA
          break;
        }
        if( param1 == 1009375 || param2 == 1009375 ) // ACTOR4 = UNEI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=UNEI
          break;
        }
        if( param1 == 1007754 || param2 == 1007754 ) // ACTOR10 = CID
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1007761 || param2 == 1007761 ) // ACTOR11 = BIGGS
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1007762 || param2 == 1007762 ) // ACTOR12 = WEDGE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1009376 || param2 == 1009376 ) // ACTOR5 = GRAHATIA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=GRAHATIA
          break;
        }
        if( param1 == 1009374 || param2 == 1009374 ) // ACTOR3 = DOGA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=DOGA
          break;
        }
        if( param1 == 1009375 || param2 == 1009375 ) // ACTOR4 = UNEI
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=UNEI
          break;
        }
        if( param1 == 1007754 || param2 == 1007754 ) // ACTOR10 = CID
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1007761 || param2 == 1007761 ) // ACTOR11 = BIGGS
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1007762 || param2 == 1007762 ) // ACTOR12 = WEDGE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=WEDGE
          break;
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00025( player ); // Scene00025: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006725 || param2 == 1006725 ) // ACTOR0 = RAMMBROES
        {
          Scene00026( player ); // Scene00026: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES
          break;
        }
        if( param1 == 1007763 || param2 == 1007763 ) // ACTOR14 = GRAHATIA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=GRAHATIA
          break;
        }
        if( param1 == 1007754 || param2 == 1007754 ) // ACTOR10 = CID
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=CID
          break;
        }
        if( param1 == 1007761 || param2 == 1007761 ) // ACTOR11 = BIGGS
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=BIGGS
          break;
        }
        if( param1 == 1007762 || param2 == 1007762 ) // ACTOR12 = WEDGE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=WEDGE
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
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsd401:67010 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00002: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00003: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00004: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00005: Normal(Talk, TargetCanMove), id=DOGA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00007: Normal(Talk, TargetCanMove), id=UNEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00008: Normal(Talk, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00009: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00010: Normal(Talk, TargetCanMove), id=NERO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00011: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00012: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00013: Normal(Talk, Message, FadeIn, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00014: Normal(Talk, TargetCanMove), id=DOGA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00015: Normal(Talk, TargetCanMove), id=UNEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00016: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00017: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00018: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00019: Normal(Talk, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00020: Normal(Talk, TargetCanMove), id=DOGA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00021: Normal(Talk, TargetCanMove), id=UNEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00022: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00023: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00024: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00025: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 25, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00026: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES" );
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
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00027: Normal(Talk, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00028: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00029: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd401:67010 calling Scene00030: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd401 );
