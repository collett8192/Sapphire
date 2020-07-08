// FFXIVTheMovie.ParserV3
//fix: skip dungeon
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVne105 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVne105() : Sapphire::ScriptAPI::EventScript( 67881 ){}; 
  ~HeaVne105() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_3, 8 entries
  //SEQ_4, 6 entries
  //SEQ_5, 3 entries
  //SEQ_6, 2 entries
  //SEQ_7, 3 entries
  //SEQ_8, 3 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTBASEKNEEL = 1014
  //ACTIONTIMELINEEVENTBASESITRELAX = 789
  //ACTOR0 = 1016815
  //ACTOR1 = 1017736
  //ACTOR10 = 1017873
  //ACTOR11 = 1017868
  //ACTOR12 = 1017869
  //ACTOR13 = 1017870
  //ACTOR14 = 1018112
  //ACTOR15 = 1018111
  //ACTOR16 = 1018113
  //ACTOR17 = 1017739
  //ACTOR18 = 1017740
  //ACTOR19 = 1017741
  //ACTOR2 = 1017737
  //ACTOR20 = 1017742
  //ACTOR21 = 1017743
  //ACTOR22 = 5010000
  //ACTOR23 = 1017744
  //ACTOR24 = 1017745
  //ACTOR25 = 1017746
  //ACTOR3 = 1017865
  //ACTOR4 = 1017866
  //ACTOR5 = 1017867
  //ACTOR6 = 1018109
  //ACTOR7 = 1018110
  //ACTOR8 = 1017871
  //ACTOR9 = 1017872
  //BINDACTOR1 = 6433069
  //BINDACTOR2 = 6433070
  //BINDACTOR3 = 6433683
  //BINDACTOR4 = 6433684
  //BINDACTOR5 = 6433685
  //BINDACTOR6 = 6481755
  //BINDACTOR7 = 6481757
  //EOBJECT0 = 2007458
  //EOBJECT1 = 2007415
  //EOBJECT2 = 2007416
  //EOBJECT3 = 2007460
  //EOBJECT4 = 2007459
  //EOBJECT5 = 2007462
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //EVENTACTIONSEARCH = 1
  //INSTANCEDUNGEON0 = 20005
  //ITEM0 = 2002012
  //LCUTEOBJ1 = 2007461
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1017687
  //LOCACTOR2 = 1017689
  //NCUT01 = 1258

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016815 || param2 == 1016815 ) // ACTOR0 = GABU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GABU
        }
        if( param1 == 1017736 || param2 == 1017736 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017737 || param2 == 1017737 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 1:
      {
        if( param1 == 1017865 || param2 == 1017865 ) // ACTOR3 = GABU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GABU
          }
        }
        if( param1 == 1017866 || param2 == 1017866 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017867 || param2 == 1017867 ) // ACTOR5 = ALISAIE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1018109 || param2 == 1018109 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( param1 == 1018110 || param2 == 1018110 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( param1 == 2007458 || param2 == 2007458 ) // EOBJECT0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          // +Callback Scene00010: Normal(None), id=unknown
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 2
      case 2:
      {
        if( param1 == 2007415 || param2 == 2007415 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, QuestGimmickReaction), id=unknown
          }
        }
        if( param1 == 1017866 || param2 == 1017866 ) // ACTOR4 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017867 || param2 == 1017867 ) // ACTOR5 = ALISAIE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017865 || param2 == 1017865 ) // ACTOR3 = GABU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=GABU
        }
        if( param1 == 1018109 || param2 == 1018109 ) // ACTOR6 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1018110 || param2 == 1018110 ) // ACTOR7 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 2
      case 3:
      {
        if( param1 == 2007416 || param2 == 2007416 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(None), id=unknown
            // +Callback Scene00018: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown
          }
        }
        if( param1 == 1017871 || param2 == 1017871 ) // ACTOR8 = GABU
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=GABU
        }
        if( param1 == 1017872 || param2 == 1017872 ) // ACTOR9 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk), id=ALPHINAUD
        }
        if( param1 == 1017873 || param2 == 1017873 ) // ACTOR10 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 2007460 || param2 == 2007460 ) // EOBJECT3 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          // +Callback Scene00023: Normal(None), id=unknown
        }
        if( param1 == 1018109 || param2 == 1018109 ) // ACTOR6 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
        }
        if( param1 == 1018110 || param2 == 1018110 ) // ACTOR7 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        if( param1 == 2007415 || param2 == 2007415 ) // EOBJECT1 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          // +Callback Scene00027: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 2
      case 4:
      {
        if( param1 == 2007459 || param2 == 2007459 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(None), id=unknown
          }
        }
        if( param1 == 1017868 || param2 == 1017868 ) // ACTOR11 = GABU
        {
          Scene00029( player ); // Scene00029: Normal(Talk, FadeIn), id=unknown
          // +Callback Scene00030: Normal(Talk, TargetCanMove), id=GABU
        }
        if( param1 == 1017869 || param2 == 1017869 ) // ACTOR12 = ALPHINAUD
        {
          Scene00031( player ); // Scene00031: Normal(Talk), id=ALPHINAUD
        }
        if( param1 == 1017870 || param2 == 1017870 ) // ACTOR13 = ALISAIE
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 2007462 || param2 == 2007462 ) // EOBJECT5 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          // +Callback Scene00034: Normal(None), id=unknown
        }
        if( param1 == 2007416 || param2 == 2007416 ) // EOBJECT2 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 2
      case 5:
      {
        if( param1 == 1018112 || param2 == 1018112 ) // ACTOR14 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00036( player ); // Scene00036: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00037: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1018111 || param2 == 1018111 ) // ACTOR15 = GABU
        {
          Scene00038( player ); // Scene00038: Normal(Talk), id=GABU
        }
        if( param1 == 1018113 || param2 == 1018113 ) // ACTOR16 = ALISAIE
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 6:
      {
        if( param1 == 1017739 || param2 == 1017739 ) // ACTOR17 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=ALISAIE
            // +Callback Scene00041: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1017740 || param2 == 1017740 ) // ACTOR18 = GABU
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=GABU
        }
        break;
      }
      case 7:
      {
        if( param1 == 1017741 || param2 == 1017741 ) // ACTOR19 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1017742 || param2 == 1017742 ) // ACTOR20 = ALISAIE
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017743 || param2 == 1017743 ) // ACTOR21 = GABU
        {
          Scene00045( player ); // Scene00045: Normal(Talk), id=GABU
        }
        break;
      }
      case 8:
      {
        if( param1 == 1017741 || param2 == 1017741 ) // ACTOR19 = ALPHINAUD
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017742 || param2 == 1017742 ) // ACTOR20 = ALISAIE
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017743 || param2 == 1017743 ) // ACTOR21 = GABU
        {
          Scene00048( player ); // Scene00048: Normal(Talk), id=GABU
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017744 || param2 == 1017744 ) // ACTOR23 = ALPHINAUD
        {
          Scene00049( player ); // Scene00049: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017745 || param2 == 1017745 ) // ACTOR24 = ALISAIE
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017746 || param2 == 1017746 ) // ACTOR25 = GABU
        {
          Scene00051( player ); // Scene00051: Normal(Talk), id=GABU
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
      player.setQuestUI8BH( getId(), 2 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
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
    }
  }
  void checkProgressSeq8( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVne105:67881 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00004: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00011: Normal(Talk, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00014: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling [BranchTrue]Scene00018: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00019: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00020: Normal(Talk), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00022: Normal(None), id=unknown" );
    Scene00023( player );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling [BranchTrue]Scene00023: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00026: Normal(None), id=unknown" );
    Scene00027( player );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling [BranchTrue]Scene00027: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00028: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00029: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00030( player );
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling [BranchTrue]Scene00030: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00031: Normal(Talk), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00032: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00033: Normal(None), id=unknown" );
    Scene00034( player );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling [BranchTrue]Scene00034: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00035: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00036: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00037( player );
      }
    };
    player.playScene( getId(), 36, NONE, callback );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling [BranchTrue]Scene00037: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00038: Normal(Talk), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00040: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00041( player );
    };
    player.playScene( getId(), 40, NONE, callback );
  }
  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling [BranchTrue]Scene00041: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00042: Normal(Talk, TargetCanMove), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00043: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00044: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00045: Normal(Talk), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq8( player );
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00048: Normal(Talk), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00049: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 49, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00050: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "HeaVne105:67881 calling Scene00051: Normal(Talk), id=GABU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne105 );
