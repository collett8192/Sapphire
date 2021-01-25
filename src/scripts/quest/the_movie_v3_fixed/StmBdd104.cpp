// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBdd104 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBdd104() : Sapphire::ScriptAPI::EventScript( 68609 ){}; 
  ~StmBdd104() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 1 entries
  //SEQ_2, 10 entries
  //SEQ_3, 8 entries
  //SEQ_255, 11 entries

  //ACTOR0 = 1024999
  //ACTOR1 = 1024998
  //ACTOR10 = 1025569
  //ACTOR11 = 1025570
  //ACTOR12 = 1025571
  //ACTOR13 = 1025568
  //ACTOR14 = 1024974
  //ACTOR2 = 1025009
  //ACTOR3 = 1025545
  //ACTOR4 = 1025354
  //ACTOR5 = 1021505
  //ACTOR6 = 1019935
  //ACTOR7 = 1025014
  //ACTOR8 = 1025013
  //ACTOR9 = 1025106
  //EOBJECT0 = 2009420
  //EOBJECT1 = 2009469
  //EVENTACTION0 = 3
  //EVENTACTION1 = 1
  //LOCACTANG01 = 664
  //LOCACTFACEFEEBLESMILE01 = 6215
  //LOCACTFACEMEDITATE01 = 6227
  //LOCACTLAUGHBIG = 4312
  //LOCENPCALISAIE01 = 1019541
  //LOCENPCALPH01 = 1011887
  //LOCENPCHIEN01 = 1019544
  //LOCENPCRASYO01 = 1018975
  //LOCENPCTANSUI01 = 1018976
  //LOCENPCYUU01 = 1019096
  //LOCLEVELALISAIE01 = 7227017
  //LOCLEVELALPH01 = 7227009
  //LOCLEVELYUUGIRI01 = 7343652
  //LOCSE01 = 171
  //LOCSE02 = 172
  //POPRANGE0 = 7226900
  //TERRITORYTYPE0 = 744

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1024999 || param2 == 1024999 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=HIEN
          break;
        }
        if( param1 == 1024998 || param2 == 1024998 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025009 || param2 == 1025009 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR3 = YUGIRI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1025354 || param2 == 1025354 ) // ACTOR4 = KIENKANGATEKEEPER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER
          break;
        }
        break;
      }
      case 1:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=RASHO
        break;
      }
      case 2:
      {
        if( param1 == 2009420 || param2 == 2009420 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00008( player ); // Scene00008: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009469 || param2 == 2009469 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00010( player ); // Scene00010: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR5 = RASHO
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1025014 || param2 == 1025014 ) // ACTOR7 = ALISAIE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025013 || param2 == 1025013 ) // ACTOR8 = HIEN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025106 || param2 == 1025106 ) // ACTOR9 = IHANASHI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=IHANASHI
          break;
        }
        if( param1 == 1025569 || param2 == 1025569 ) // ACTOR10 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025570 || param2 == 1025570 ) // ACTOR11 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025571 || param2 == 1025571 ) // ACTOR12 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1025106 || param2 == 1025106 ) // ACTOR9 = IHANASHI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, FadeIn, TargetCanMove), id=IHANASHI
          }
          break;
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR5 = RASHO
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1025014 || param2 == 1025014 ) // ACTOR7 = ALISAIE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025013 || param2 == 1025013 ) // ACTOR8 = HIEN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1025569 || param2 == 1025569 ) // ACTOR10 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025570 || param2 == 1025570 ) // ACTOR11 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025571 || param2 == 1025571 ) // ACTOR12 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1024999 || param2 == 1024999 ) // ACTOR0 = HIEN
        {
          Scene00027( player ); // Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR5 = RASHO
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=RASHO
          break;
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=TANSUI
          break;
        }
        if( param1 == 1025569 || param2 == 1025569 ) // ACTOR10 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025570 || param2 == 1025570 ) // ACTOR11 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025571 || param2 == 1025571 ) // ACTOR12 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1025568 || param2 == 1025568 ) // ACTOR13 = IHANASHI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=IHANASHI
          break;
        }
        if( param1 == 1024998 || param2 == 1024998 ) // ACTOR1 = ALPHINAUD
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1025009 || param2 == 1025009 ) // ACTOR2 = ALISAIE
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1025545 || param2 == 1025545 ) // ACTOR3 = YUGIRI
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1024974 || param2 == 1024974 ) // ACTOR14 = KIENKANGATEKEEPER
        {
          Scene00037( player ); // Scene00037: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER
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
    if( player.getQuestUI8AL( getId() ) == 2 )
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
    player.sendDebug( "StmBdd104:68609 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBdd104:68609 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00004: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00005: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00008: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00010: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00011: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00012: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00014: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00015: Normal(Talk, TargetCanMove), id=IHANASHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00019: Normal(Talk, FadeIn, TargetCanMove), id=IHANASHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00020: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00021: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00022: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00023: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
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
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00028: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00029: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00033: Normal(Talk, TargetCanMove), id=IHANASHI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00034: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00035: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00036: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBdd104:68609 calling Scene00037: Normal(Talk, YesNo, TargetCanMove), id=KIENKANGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 744 );
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBdd104 );
