// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda603 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda603() : Sapphire::ScriptAPI::EventScript( 68065 ){}; 
  ~StmBda603() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 18 entries
  //SEQ_2, 17 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1020568
  //ACTOR1 = 1020567
  //ACTOR10 = 1023776
  //ACTOR11 = 1020574
  //ACTOR12 = 1020575
  //ACTOR13 = 1020576
  //ACTOR14 = 1023583
  //ACTOR15 = 1023584
  //ACTOR16 = 1023585
  //ACTOR17 = 1023586
  //ACTOR18 = 1023587
  //ACTOR19 = 1023588
  //ACTOR2 = 1020569
  //ACTOR20 = 1020573
  //ACTOR21 = 1022089
  //ACTOR22 = 1022090
  //ACTOR3 = 1020570
  //ACTOR4 = 1020571
  //ACTOR5 = 1020572
  //ACTOR6 = 1022087
  //ACTOR7 = 1022088
  //ACTOR8 = 1023774
  //ACTOR9 = 1023775
  //BINDACTOR01 = 6853849
  //BINDACTOR02 = 6853850
  //ENEMY0 = 7021911
  //ENEMY1 = 7021912
  //ENEMY2 = 7021913
  //EOBJECT0 = 2009005
  //EOBJECT1 = 2009006
  //EVENTRANGE0 = 7021090
  //EVENTRANGE1 = 7021091
  //LOCIDLE01 = 4294
  //LOCIDLE02 = 4295

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020568 || param2 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020567 || param2 == 1020567 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020569 || param2 == 1020569 ) // ACTOR2 = ARENVALD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020570 || param2 == 1020570 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020571 || param2 == 1020571 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020572 || param2 == 1020572 ) // ACTOR5 = ANANTASOLDIER
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 1022087 || param2 == 1022087 ) // ACTOR6 = MNAAGO
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022088 || param2 == 1022088 ) // ACTOR7 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 7021090 || param2 == 7021090 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 7021911 || param2 == 7021911 ) // ENEMY0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7021091 || param2 == 7021091 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 7021912 || param2 == 7021912 ) // ENEMY1 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7021913 || param2 == 7021913 ) // ENEMY2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020568 || param2 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020567 || param2 == 1020567 ) // ACTOR1 = LYSE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022087 || param2 == 1022087 ) // ACTOR6 = MNAAGO
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022088 || param2 == 1022088 ) // ACTOR7 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020569 || param2 == 1020569 ) // ACTOR2 = ARENVALD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020570 || param2 == 1020570 ) // ACTOR3 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020571 || param2 == 1020571 ) // ACTOR4 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020572 || param2 == 1020572 ) // ACTOR5 = ANANTASOLDIER
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 2009005 || param2 == 2009005 ) // EOBJECT0 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1023774 || param2 == 1023774 ) // ACTOR8 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009006 || param2 == 2009006 ) // EOBJECT1 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1023775 || param2 == 1023775 ) // ACTOR9 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1023776 || param2 == 1023776 ) // ACTOR10 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020574 || param2 == 1020574 ) // ACTOR11 = RAUBAHN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, FadeIn, TargetCanMove), id=RAUBAHN
          }
          break;
        }
        if( param1 == 1020575 || param2 == 1020575 ) // ACTOR12 = ALPHINAUD
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020576 || param2 == 1020576 ) // ACTOR13 = ALISAIE
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020568 || param2 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020567 || param2 == 1020567 ) // ACTOR1 = LYSE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1022087 || param2 == 1022087 ) // ACTOR6 = MNAAGO
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=MNAAGO
          break;
        }
        if( param1 == 1022088 || param2 == 1022088 ) // ACTOR7 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020569 || param2 == 1020569 ) // ACTOR2 = ARENVALD
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ARENVALD
          break;
        }
        if( param1 == 1020570 || param2 == 1020570 ) // ACTOR3 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020571 || param2 == 1020571 ) // ACTOR4 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020572 || param2 == 1020572 ) // ACTOR5 = ANANTASOLDIER
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=ANANTASOLDIER
          break;
        }
        if( param1 == 1023583 || param2 == 1023583 ) // ACTOR14 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 1023584 || param2 == 1023584 ) // ACTOR15 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 1023585 || param2 == 1023585 ) // ACTOR16 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        if( param1 == 1023586 || param2 == 1023586 ) // ACTOR17 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 1023587 || param2 == 1023587 ) // ACTOR18 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          break;
        }
        if( param1 == 1023588 || param2 == 1023588 ) // ACTOR19 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020568 || param2 == 1020568 ) // ACTOR0 = CONRAD
        {
          Scene00044( player ); // Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CONRAD
          break;
        }
        if( param1 == 1020573 || param2 == 1020573 ) // ACTOR20 = RESISTANCEGATEGUARD
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD
          break;
        }
        if( param1 == 1022089 || param2 == 1022089 ) // ACTOR21 = ALPHINAUD
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1022090 || param2 == 1022090 ) // ACTOR22 = ALISAIE
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020567 || param2 == 1020567 ) // ACTOR1 = LYSE
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=LYSE
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
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 2 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 2 );
      }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda603:68065 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00003: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00006: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00007: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 2 );
    checkProgressSeq1( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00014: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00015: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00016: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00018: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00021: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00024: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00027: Normal(Talk, FadeIn, TargetCanMove), id=RAUBAHN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00028: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00029: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00030: Normal(Talk, TargetCanMove), id=CONRAD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00031: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00032: Normal(Talk, TargetCanMove), id=MNAAGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00034: Normal(Talk, TargetCanMove), id=ARENVALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00037: Normal(Talk, TargetCanMove), id=ANANTASOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CONRAD" );
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
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00045: Normal(Talk, TargetCanMove), id=RESISTANCEGATEGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda603:68065 calling Scene00048: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda603 );
