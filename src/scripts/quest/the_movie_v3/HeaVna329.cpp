// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna329 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna329() : Sapphire::ScriptAPI::EventScript( 67166 ){}; 
  ~HeaVna329() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 11 entries
  //SEQ_4, 9 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1012721
  //ACTOR1 = 1012716
  //ACTOR10 = 1012723
  //ACTOR11 = 1012724
  //ACTOR12 = 1012725
  //ACTOR13 = 1012726
  //ACTOR14 = 1012727
  //ACTOR15 = 1013153
  //ACTOR16 = 1013158
  //ACTOR17 = 1013392
  //ACTOR18 = 1012729
  //ACTOR19 = 1012730
  //ACTOR2 = 1013154
  //ACTOR3 = 1012722
  //ACTOR4 = 1007478
  //ACTOR5 = 1012845
  //ACTOR6 = 1003995
  //ACTOR7 = 1002014
  //ACTOR8 = 1002030
  //ACTOR9 = 1002047
  //CUTSCENEN01 = 831
  //CUTSCENEN02 = 832
  //LOCACTOR0 = 5859589
  //LOCACTOR1 = 5859847
  //LOCQUEST0 = 65766
  //POPRANGE0 = 5908181
  //TERRITORYTYPE0 = 212

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012721 || param2 == 1012721 ) // ACTOR0 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=TATARU
          }
          break;
        }
        if( param1 == 1012716 || param2 == 1012716 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00003( player ); // Scene00003: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1013154 || param2 == 1013154 ) // ACTOR2 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
          }
          break;
        }
        if( param1 == 1012722 || param2 == 1012722 ) // ACTOR3 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1007478 || param2 == 1007478 ) // ACTOR4 = URIANGER
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1012845 || param2 == 1012845 ) // ACTOR5 = HIGIRI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HIGIRI
          break;
        }
        if( param1 == 1003995 || param2 == 1003995 ) // ACTOR6 = PAPASHAN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1002014 || param2 == 1002014 ) // ACTOR7 = KIKIPU
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=KIKIPU
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=KIKIPU
          }
          break;
        }
        if( param1 == 1002030 || param2 == 1002030 ) // ACTOR8 = DANYELL
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=DANYELL
            // +Callback Scene00012: Normal(Talk, TargetCanMove), id=DANYELL
          }
          break;
        }
        if( param1 == 1002047 || param2 == 1002047 ) // ACTOR9 = SPOTTEDMEADOW
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=SPOTTEDMEADOW
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=SPOTTEDMEADOW
          }
          break;
        }
        if( param1 == 1012723 || param2 == 1012723 ) // ACTOR10 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012724 || param2 == 1012724 ) // ACTOR11 = YUGIRI
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1012725 || param2 == 1012725 ) // ACTOR12 = RAUBAHN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1012726 || param2 == 1012726 ) // ACTOR13 = PIPPIN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=PIPPIN
          break;
        }
        if( param1 == 1012727 || param2 == 1012727 ) // ACTOR14 = PAPASHAN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        if( param1 == 1013153 || param2 == 1013153 ) // ACTOR15 = DEWLALA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=DEWLALA
          break;
        }
        if( param1 == 1013158 || param2 == 1013158 ) // ACTOR16 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003995 || param2 == 1003995 ) // ACTOR6 = PAPASHAN
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1013392 || param2 == 1013392 ) // ACTOR17 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1012723 || param2 == 1012723 ) // ACTOR10 = ALPHINAUD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012724 || param2 == 1012724 ) // ACTOR11 = YUGIRI
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1012725 || param2 == 1012725 ) // ACTOR12 = RAUBAHN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN
          break;
        }
        if( param1 == 1012726 || param2 == 1012726 ) // ACTOR13 = PIPPIN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=PIPPIN
          break;
        }
        if( param1 == 1012727 || param2 == 1012727 ) // ACTOR14 = PAPASHAN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        if( param1 == 1013153 || param2 == 1013153 ) // ACTOR15 = DEWLALA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=DEWLALA
          break;
        }
        if( param1 == 1013158 || param2 == 1013158 ) // ACTOR16 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1003995 || param2 == 1003995 ) // ACTOR6 = PAPASHAN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=PAPASHAN
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1012729 || param2 == 1012729 ) // ACTOR18 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012730 || param2 == 1012730 ) // ACTOR19 = YUGIRI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1003995 || param2 == 1003995 ) // ACTOR6 = PAPASHAN
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=PAPASHAN
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
    player.updateQuest( getId(), 2 );
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna329:67166 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, ENpcBind), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00006: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00007: Normal(Talk, TargetCanMove), id=HIGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00008: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00009: Normal(Talk, TargetCanMove), id=KIKIPU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00010: Normal(Talk, TargetCanMove), id=KIKIPU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00011: Normal(Talk, TargetCanMove), id=DANYELL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR8, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00012: Normal(Talk, TargetCanMove), id=DANYELL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR9, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00013: Normal(Talk, TargetCanMove), id=SPOTTEDMEADOW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player ) //SEQ_3: ACTOR9, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00014: Normal(Talk, TargetCanMove), id=SPOTTEDMEADOW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00016: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00017: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00018: Normal(Talk, TargetCanMove), id=PIPPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00019: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_3: ACTOR15, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00020: Normal(Talk, TargetCanMove), id=DEWLALA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_3: ACTOR16, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00022: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: ACTOR17, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00023: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00026: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_4: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00027: Normal(Talk, TargetCanMove), id=PIPPIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_4: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00028: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player ) //SEQ_4: ACTOR15, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00029: Normal(Talk, TargetCanMove), id=DEWLALA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_4: ACTOR16, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00031: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00032: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna329:67166 calling Scene00034: Normal(Talk, TargetCanMove), id=PAPASHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna329 );
