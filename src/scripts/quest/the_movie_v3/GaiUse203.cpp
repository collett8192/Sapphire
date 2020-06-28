// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse203 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse203() : Sapphire::ScriptAPI::EventScript( 66883 ){}; 
  ~GaiUse203() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 5 entries
  //SEQ_3, 4 entries
  //SEQ_4, 3 entries
  //SEQ_5, 4 entries
  //SEQ_6, 5 entries
  //SEQ_7, 4 entries
  //SEQ_8, 3 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1008597
  //ACTOR1 = 1008600
  //ACTOR10 = 1008608
  //ACTOR11 = 1008609
  //ACTOR12 = 1008610
  //ACTOR13 = 1001353
  //ACTOR14 = 1001966
  //ACTOR15 = 1001968
  //ACTOR16 = 1008616
  //ACTOR17 = 1008612
  //ACTOR18 = 1008613
  //ACTOR19 = 1008614
  //ACTOR2 = 1008602
  //ACTOR20 = 1008615
  //ACTOR21 = 1008617
  //ACTOR3 = 1008603
  //ACTOR4 = 1001821
  //ACTOR5 = 1008601
  //ACTOR6 = 1008604
  //ACTOR7 = 1008605
  //ACTOR8 = 1008606
  //ACTOR9 = 1008607
  //CUTSCENEN01 = 461
  //CUTSCENEN02 = 462
  //EVENTRANGE0 = 4663959
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001202
  //ITEM1 = 2001203
  //LOCACTOR1 = 1007768
  //LOCACTOR2 = 1007098
  //LOCACTOR3 = 1007099
  //LOCACTOR4 = 1001821
  //LOCACTOR5 = 1007097
  //LOCFACE0 = 605
  //LOCPOSACTOR0 = 4678064
  //LOCPOSACTOR1 = 4635471
  //LOCPOSACTOR2 = 4635472
  //LOCPOSACTOR3 = 4635473

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=THANCRED
        break;
      }
      case 1:
      {
        if( actor == 1008600 || actorId == 1008600 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1008597 || actorId == 1008597 ) // ACTOR0 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
        }
        break;
      }
      case 2:
      {
        if( actor == 4663959 || actorId == 4663959 ) // EVENTRANGE0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Talk, FadeIn), id=unknown
        }
        if( actor == 1008602 || actorId == 1008602 ) // ACTOR2 = KASASAGI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008603 || actorId == 1008603 ) // ACTOR3 = KIKYOU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        if( actor == 1001821 || actorId == 1001821 ) // ACTOR4 = BARTHOLOMEW
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=BARTHOLOMEW
        }
        if( actor == 1008601 || actorId == 1008601 ) // ACTOR5 = YUGIRI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        break;
      }
      case 3:
      {
        if( actor == 1008604 || actorId == 1008604 ) // ACTOR6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1008605 || actorId == 1008605 ) // ACTOR7 = YUGIRI
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008606 || actorId == 1008606 ) // ACTOR8 = KASASAGI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008607 || actorId == 1008607 ) // ACTOR9 = KIKYOU
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        break;
      }
      case 4:
      {
        if( actor == 1008608 || actorId == 1008608 ) // ACTOR10 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YUGIRI
          }
        }
        if( actor == 1008609 || actorId == 1008609 ) // ACTOR11 = KASASAGI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008610 || actorId == 1008610 ) // ACTOR12 = KIKYOU
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      //seq 5 event item ITEM1 = UI8BL max stack ?
      case 5:
      {
        if( actor == 1001353 || actorId == 1001353 ) // ACTOR13 = MOMODI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOMODI
          }
        }
        if( actor == 1008608 || actorId == 1008608 ) // ACTOR10 = YUGIRI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008609 || actorId == 1008609 ) // ACTOR11 = KASASAGI
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008610 || actorId == 1008610 ) // ACTOR12 = KIKYOU
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        break;
      }
      //seq 6 event item ITEM0 = UI8BL max stack 1
      //seq 6 event item ITEM1 = UI8CH max stack ?
      case 6:
      {
        if( actor == 1001966 || actorId == 1001966 ) // ACTOR14 = FRIDURIH
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00021: Normal(Talk, TargetCanMove), id=FRIDURIH
          }
        }
        if( actor == 1001968 || actorId == 1001968 ) // ACTOR15 = KATHERINE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=KATHERINE
          }
        }
        if( actor == 1008608 || actorId == 1008608 ) // ACTOR10 = YUGIRI
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008609 || actorId == 1008609 ) // ACTOR11 = KASASAGI
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008610 || actorId == 1008610 ) // ACTOR12 = KIKYOU
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        break;
      }
      case 7:
      {
        if( actor == 1001353 || actorId == 1001353 ) // ACTOR13 = MOMODI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=MOMODI
          }
        }
        if( actor == 1008608 || actorId == 1008608 ) // ACTOR10 = YUGIRI
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008609 || actorId == 1008609 ) // ACTOR11 = KASASAGI
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008610 || actorId == 1008610 ) // ACTOR12 = KIKYOU
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        break;
      }
      case 8:
      {
        if( actor == 1008608 || actorId == 1008608 ) // ACTOR10 = YUGIRI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=YUGIRI
            // +Callback Scene00032: Normal(Talk, FadeIn, TargetCanMove), id=YUGIRI
          }
        }
        if( actor == 1008609 || actorId == 1008609 ) // ACTOR11 = KASASAGI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008610 || actorId == 1008610 ) // ACTOR12 = KIKYOU
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        break;
      }
      case 255:
      {
        if( actor == 1008616 || actorId == 1008616 ) // ACTOR16 = RAUBAHN
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=RAUBAHN
          // +Callback Scene00036: Normal(CutScene), id=unknown
          // +Callback Scene00037: Normal(FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown
        }
        if( actor == 1008612 || actorId == 1008612 ) // ACTOR17 = ALPHINAUD
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1008613 || actorId == 1008613 ) // ACTOR18 = YUGIRI
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008614 || actorId == 1008614 ) // ACTOR19 = KASASAGI
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008615 || actorId == 1008615 ) // ACTOR20 = KIKYOU
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        if( actor == 1008617 || actorId == 1008617 ) // ACTOR21 = TELEDJIADELEDJI
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI
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
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 6 );
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestUI8CH( getId(), 1 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 7 );
      }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 8 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse203:66883 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00004: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00005: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00006: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00007: Normal(Talk, TargetCanMove), id=BARTHOLOMEW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00009: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00010: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00011: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00012: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00013: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00014: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00015: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00016: Normal(Talk, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00017: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00018: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00019: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00021( player );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling [BranchTrue]Scene00021: Normal(Talk, TargetCanMove), id=FRIDURIH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00022: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00023( player );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling [BranchTrue]Scene00023: Normal(Talk, TargetCanMove), id=KATHERINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00025: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00026: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00027: Normal(Talk, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00028: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00029: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00030: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00031: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00032( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling [BranchTrue]Scene00032: Normal(Talk, FadeIn, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00033: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00034: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00035: Normal(Talk, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00036( player );
    };
    player.playScene( getId(), 35, NONE, callback );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling [BranchTrue]Scene00036: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00037( player );
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling [BranchChain]Scene00037: Normal(FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 37, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00039: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00040: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00041: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUse203:66883 calling Scene00042: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse203 );
