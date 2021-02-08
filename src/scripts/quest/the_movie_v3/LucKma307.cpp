// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma307 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma307() : Sapphire::ScriptAPI::EventScript( 68833 ){}; 
  ~LucKma307() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 5 entries
  //SEQ_4, 5 entries
  //SEQ_5, 6 entries
  //SEQ_6, 3 entries
  //SEQ_7, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1029001
  //ACTOR1 = 1029176
  //ACTOR2 = 1027909
  //ACTOR3 = 1027910
  //ACTOR4 = 1030386
  //ACTOR5 = 1027873
  //ACTOR6 = 1030607
  //ACTOR7 = 1029007
  //ACTOR8 = 1027882
  //EVENTACTION0 = 32
  //ITEM0 = 2002452
  //LOCACTOR0 = 1028127
  //LOCACTOR1 = 1026567
  //LOCACTOR2 = 1028846
  //LOCBINDACTOR0 = 7929636
  //LOCBINDACTOR1 = 7810836
  //LOCBINDACTOR2 = 7961204
  //LOCSEWIPECLOTH = 215
  //NCUTEVENTLUCKMA30701 = 1972

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029001 || param2 == 1029001 ) // ACTOR0 = TESLEEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TESLEEN
          break;
        }
        if( param1 == 1029176 || param2 == 1029176 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR2 = PAWNIL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=PAWNIL
          }
          break;
        }
        if( param1 == 1029176 || param2 == 1029176 ) // ACTOR1 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029001 || param2 == 1029001 ) // ACTOR0 = TESLEEN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=TESLEEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR3 = TODDEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove, SystemTalk), id=TODDEN
          }
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR2 = PAWNIL
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1029176 || param2 == 1029176 ) // ACTOR1 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029001 || param2 == 1029001 ) // ACTOR0 = TESLEEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=TESLEEN
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030386 || param2 == 1030386 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(FadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR2 = PAWNIL
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR3 = TODDEN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1029176 || param2 == 1029176 ) // ACTOR1 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1029001 || param2 == 1029001 ) // ACTOR0 = TESLEEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=TESLEEN
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1029001 || param2 == 1029001 ) // ACTOR0 = TESLEEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=TESLEEN
          }
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR2 = PAWNIL
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR3 = TODDEN
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1030386 || param2 == 1030386 ) // ACTOR4 = HALRIC
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        if( param1 == 1029176 || param2 == 1029176 ) // ACTOR1 = ALISAIE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      case 5:
      {
        if( param1 == 1027873 || param2 == 1027873 ) // ACTOR5 = RHONRON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(Talk, FadeIn, TargetCanMove), id=RHONRON
          }
          break;
        }
        if( param1 == 1029001 || param2 == 1029001 ) // ACTOR0 = TESLEEN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=TESLEEN
          break;
        }
        if( param1 == 1030607 || param2 == 1030607 ) // ACTOR6 = ALISAIE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1027909 || param2 == 1027909 ) // ACTOR2 = PAWNIL
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=PAWNIL
          break;
        }
        if( param1 == 1027910 || param2 == 1027910 ) // ACTOR3 = TODDEN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=TODDEN
          break;
        }
        if( param1 == 1030386 || param2 == 1030386 ) // ACTOR4 = HALRIC
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        break;
      }
      //seq 6 event item ITEM0 = UI8BH max stack 1
      case 6:
      {
        if( param1 == 1029007 || param2 == 1029007 ) // ACTOR7 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE
            // +Callback Scene00030: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1027882 || param2 == 1027882 ) // ACTOR8 = MORDGUARD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=MORDGUARD
          break;
        }
        if( param1 == 1027873 || param2 == 1027873 ) // ACTOR5 = RHONRON
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=RHONRON
          break;
        }
        break;
      }
      //seq 7 event item ITEM0 = UI8BH max stack 1
      case 7:
      {
        Scene00033( player ); // Scene00033: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1029001 || param2 == 1029001 ) // ACTOR0 = TESLEEN
        {
          Scene00034( player ); // Scene00034: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TESLEEN
          break;
        }
        if( param1 == 1029176 || param2 == 1029176 ) // ACTOR1 = ALISAIE
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 1 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma307:68833 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00004: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00006: Normal(Talk, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00008: Normal(Talk, TargetCanMove, SystemTalk), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00009: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00011: Normal(Talk, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00013: Normal(FadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00014: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00015: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00017: Normal(Talk, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00018: Normal(Talk, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00019: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00020: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00021: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00023: Normal(Talk, FadeIn, TargetCanMove), id=RHONRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00024: Normal(Talk, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00025: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00026: Normal(Talk, TargetCanMove), id=PAWNIL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00027: Normal(Talk, TargetCanMove), id=TODDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00028: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00030( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00030: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00031: Normal(Talk, TargetCanMove), id=MORDGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00032: Normal(Talk, TargetCanMove), id=RHONRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00033: Normal(Talk, NpcDespawn, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00034: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00035( player );
      }
    };
    player.playScene( getId(), 34, NONE, callback );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00035: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=TESLEEN" );
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
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKma307:68833 calling Scene00036: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma307 );
