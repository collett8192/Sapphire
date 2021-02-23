// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb101 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb101() : Sapphire::ScriptAPI::EventScript( 68838 ){}; 
  ~LucKmb101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 7 entries
  //SEQ_4, 4 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1027231
  //ACTOR1 = 1027226
  //ACTOR2 = 1028923
  //ACTOR3 = 1028937
  //ACTOR4 = 1028938
  //ACTOR5 = 1029845
  //ACTOR6 = 1028939
  //ACTOR7 = 1028940
  //ACTOR8 = 1028941
  //ACTOR9 = 1028942
  //BGMMUSICEX3NEWTHEMESECRET01 = 652
  //BGMTREMENDOUS01 = 190
  //BINDACTOR0 = 7921142
  //BINDACTOR1 = 7921145
  //BINDACTOR2 = 7921165
  //CUTSCENE0 = 1982
  //EOBJECT0 = 2009809
  //EOBJECT1 = 2009810
  //EOBJECT2 = 2009811
  //EVENTACTION0 = 54
  //EVENTPICTURE0 = 792
  //EVENTPICTURE1 = 793
  //ITEM0 = 2002530
  //LCUTACTOR0 = 1026568
  //LCUTACTOR1 = 1026567
  //LCUTACTOR2 = 1029333
  //LCUTACTOR3 = 1028108
  //LCUTSECLOSETHEBOOK = 228
  //LCUTSETURNTHEPAGES = 227
  //POPRANGE0 = 7929675
  //TERRITORYTYPE0 = 844

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUIDEOFTHEPENDANTS
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00002( player ); // Scene00002: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1027226 || param2 == 1027226 ) // ACTOR1 = MOREN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MOREN
          }
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1028937 || param2 == 1028937 ) // ACTOR3 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1028938 || param2 == 1028938 ) // ACTOR4 = ALISAIE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029845 || param2 == 1029845 ) // ACTOR5 = LYNA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( param1 == 2009809 || param2 == 2009809 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009810 || param2 == 2009810 ) // EOBJECT1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2009811 || param2 == 2009811 ) // EOBJECT2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1028939 || param2 == 1028939 ) // ACTOR6 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1028940 || param2 == 1028940 ) // ACTOR7 = ALISAIE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1027226 || param2 == 1027226 ) // ACTOR1 = MOREN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MOREN
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1027226 || param2 == 1027226 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00019: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          }
          break;
        }
        if( param1 == 1028939 || param2 == 1028939 ) // ACTOR6 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1028940 || param2 == 1028940 ) // ACTOR7 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1028941 || param2 == 1028941 ) // ACTOR8 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=ALPHINAUD
          break;
        }
        if( param1 == 1028942 || param2 == 1028942 ) // ACTOR9 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
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
    player.updateQuest( getId(), 2 );
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
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmb101:68838 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUIDEOFTHEPENDANTS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00002: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00003: Normal(Talk, TargetCanMove), id=MOREN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00004: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00007: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00009: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00011: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00013: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00015: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00016: Normal(Talk, TargetCanMove), id=MOREN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00017: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00019: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00022: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00023: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=ALPHINAUD" );
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
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmb101:68838 calling Scene00025: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb101 );
