// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse204 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse204() : Sapphire::ScriptAPI::EventScript( 66884 ){}; 
  ~GaiUse204() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 6 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_5, 2 entries
  //SEQ_6, 7 entries
  //SEQ_7, 4 entries
  //SEQ_8, 2 entries
  //SEQ_9, 2 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEMOTEUPSET = 737
  //ACTIONTIMELINEEVENTTALKBIG = 950
  //ACTOR0 = 1008616
  //ACTOR1 = 1008612
  //ACTOR10 = 1008619
  //ACTOR11 = 1008618
  //ACTOR12 = 1008623
  //ACTOR13 = 1003889
  //ACTOR14 = 1008624
  //ACTOR15 = 1008625
  //ACTOR2 = 1008613
  //ACTOR3 = 1008614
  //ACTOR4 = 1008615
  //ACTOR5 = 1008617
  //ACTOR6 = 1008700
  //ACTOR7 = 1008620
  //ACTOR8 = 1008621
  //ACTOR9 = 1008622
  //ENEMY0 = 4630002
  //ENEMY1 = 4630003
  //ENEMY2 = 4630004
  //EOBJECT0 = 2003563
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001204
  //ITEM1 = 2001205
  //LEVELIDNPC01 = 4621005
  //LEVELIDNPC02 = 4621006
  //LEVELIDNPC03 = 4621007
  //LEVELIDNPC04 = 4621008
  //LEVELIDNPC05 = 4621009
  //LOCACTION1 = 1002
  //LOCACTOR0 = 4620901
  //LOCACTOR1 = 4620902
  //LOCACTOR10 = 3146810
  //LOCACTOR11 = 1008185
  //LOCACTOR12 = 1007097
  //LOCACTOR13 = 1007098
  //LOCACTOR14 = 1007099
  //LOCACTOR15 = 1008927
  //LOCACTOR2 = 4620903
  //LOCACTOR3 = 4620904
  //LOCACTOR4 = 4620905
  //LOCFACE1 = 605
  //LOCPOSACTOR1 = 4678739
  //LOCPOSACTOR2 = 4678741
  //LOCSE1 = 42

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1008616 || actorId == 1008616 ) // ACTOR0 = RAUBAHN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=RAUBAHN
        }
        if( actor == 1008612 || actorId == 1008612 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1008613 || actorId == 1008613 ) // ACTOR2 = YUGIRI
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008614 || actorId == 1008614 ) // ACTOR3 = KASASAGI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008615 || actorId == 1008615 ) // ACTOR4 = KIKYOU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        if( actor == 1008617 || actorId == 1008617 ) // ACTOR5 = TELEDJIADELEDJI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI
        }
        break;
      }
      case 1:
      {
        if( actor == 1008700 || actorId == 1008700 ) // ACTOR6 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=RAUBAHN
          }
        }
        if( actor == 1008620 || actorId == 1008620 ) // ACTOR7 = YUGIRI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008621 || actorId == 1008621 ) // ACTOR8 = KASASAGI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=KASASAGI
        }
        if( actor == 1008622 || actorId == 1008622 ) // ACTOR9 = KIKYOU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        if( actor == 1008619 || actorId == 1008619 ) // ACTOR10 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1008618 || actorId == 1008618 ) // ACTOR11 = TELEDJIADELEDJI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI
        }
        break;
      }
      case 2:
      {
        Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 3:
      {
        if( actor == 1003889 || actorId == 1003889 ) // ACTOR13 = GIGIYON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=GIGIYON
          }
        }
        if( actor == 1008623 || actorId == 1008623 ) // ACTOR12 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 4:
      {
        if( actor == 1008624 || actorId == 1008624 ) // ACTOR14 = GYOSHA01348
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=GYOSHA01348
          }
        }
        if( actor == 1008623 || actorId == 1008623 ) // ACTOR12 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 5:
      {
        if( actor == 1008624 || actorId == 1008624 ) // ACTOR14 = GYOSHA01348
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=GYOSHA01348
            // +Callback Scene00019: Normal(Talk, TargetCanMove), id=GYOSHA01348
          }
          else
          {
            Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=GYOSHA01348
          }
        }
        if( actor == 1008623 || actorId == 1008623 ) // ACTOR12 = ALPHINAUD
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 6:
      {
        if( actor == 1008625 || actorId == 1008625 ) // ACTOR15 = DOUJINDAN1348
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, Message, PopBNpc, TargetCanMove), id=DOUJINDAN1348
          }
        }
        if( actor == 4630002 || actorId == 4630002 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4630003 || actorId == 4630003 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 4630004 || actorId == 4630004 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 2003563 || actorId == 2003563 ) // EOBJECT0 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 1008623 || actorId == 1008623 ) // ACTOR12 = ALPHINAUD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1008624 || actorId == 1008624 ) // ACTOR14 = GYOSHA01348
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=GYOSHA01348
        }
        break;
      }
      //seq 7 event item ITEM0 = UI8BH max stack 3
      //seq 7 event item ITEM1 = UI8BL max stack 1
      case 7:
      {
        if( actor == 1008625 || actorId == 1008625 ) // ACTOR15 = DOUJINDAN1348
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=DOUJINDAN1348
          }
        }
        if( actor == 2003563 || actorId == 2003563 ) // EOBJECT0 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        if( actor == 1008623 || actorId == 1008623 ) // ACTOR12 = ALPHINAUD
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1008624 || actorId == 1008624 ) // ACTOR14 = GYOSHA01348
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=GYOSHA01348
        }
        break;
      }
      //seq 8 event item ITEM0 = UI8BH max stack 3
      //seq 8 event item ITEM1 = UI8BL max stack 1
      case 8:
      {
        if( actor == 1008624 || actorId == 1008624 ) // ACTOR14 = GYOSHA01348
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00030( player ); // Scene00030: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00031: Normal(Talk, NpcDespawn, TargetCanMove), id=GYOSHA01348
          }
        }
        if( actor == 1008623 || actorId == 1008623 ) // ACTOR12 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 9:
      {
        if( actor == 1003889 || actorId == 1003889 ) // ACTOR13 = GIGIYON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=GIGIYON
          }
        }
        if( actor == 1008623 || actorId == 1008623 ) // ACTOR12 = ALPHINAUD
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 255:
      {
        Scene00035( player ); // Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
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
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 8 );
      player.setQuestUI8BH( getId(), 3 );
      player.setQuestUI8BL( getId(), 1 );
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 9 );
    }
  }
  void checkProgressSeq9( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse204:66884 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00003: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00004: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00005: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00006: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00008: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00009: Normal(Talk, TargetCanMove), id=KASASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00010: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00011: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00012: Normal(Talk, TargetCanMove), id=TELEDJIADELEDJI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00013: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00014: Normal(Talk, TargetCanMove), id=GIGIYON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00016: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00018: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling [BranchTrue]Scene00019: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling [BranchFalse]Scene00020: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00021: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00022: Normal(Talk, Message, PopBNpc, TargetCanMove), id=DOUJINDAN1348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00023: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00025: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00026: Normal(Talk, NpcDespawn, TargetCanMove), id=DOUJINDAN1348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00027: Normal(None), id=unknown" );
    checkProgressSeq7( player );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00029: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00030: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00031( player );
      }
    };
    player.playScene( getId(), 30, NONE, callback );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling [BranchTrue]Scene00031: Normal(Talk, NpcDespawn, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00033: Normal(Talk, TargetCanMove), id=GIGIYON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq9( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse204:66884 calling Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 35, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse204 );
