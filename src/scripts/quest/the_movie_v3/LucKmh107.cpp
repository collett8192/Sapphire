// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmh107 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmh107() : Sapphire::ScriptAPI::EventScript( 69303 ){}; 
  ~LucKmh107() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 7 entries
  //SEQ_2, 23 entries
  //SEQ_255, 16 entries

  //ACTOR0 = 1032518
  //ACTOR1 = 1032519
  //ACTOR10 = 1032525
  //ACTOR11 = 1032526
  //ACTOR12 = 1032527
  //ACTOR13 = 1032650
  //ACTOR14 = 1032651
  //ACTOR15 = 1032652
  //ACTOR16 = 1032653
  //ACTOR17 = 1032654
  //ACTOR18 = 1032655
  //ACTOR19 = 1032657
  //ACTOR2 = 1032520
  //ACTOR20 = 1032658
  //ACTOR3 = 1032264
  //ACTOR4 = 1032521
  //ACTOR5 = 1032266
  //ACTOR6 = 1027757
  //ACTOR7 = 1032522
  //ACTOR8 = 1032523
  //ACTOR9 = 1032524
  //EOBJECT0 = 2010814
  //EOBJECT1 = 2010815
  //EOBJECT10 = 2011040
  //EOBJECT11 = 2011042
  //EOBJECT12 = 2011043
  //EOBJECT13 = 2011044
  //EOBJECT2 = 2010816
  //EOBJECT3 = 2011041
  //EOBJECT4 = 2010208
  //EOBJECT5 = 2010817
  //EOBJECT6 = 2010818
  //EOBJECT7 = 2010819
  //EOBJECT8 = 2010820
  //EOBJECT9 = 2010821
  //EVENTACTION0 = 53
  //ITEM0 = 2002971
  //LOCACTORALISAIE = 1026567
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORRYNE = 1027137
  //LOCACTORTHANCRED = 1026569
  //LOCACTORTOLSHSAATH = 1028165
  //LOCACTORURIANGER = 1026570
  //LOCACTORYSHTOLA = 1026571
  //LOCBINDALISAIE = 8260027
  //LOCBINDALPHINAUD = 8260026
  //LOCBINDRYNE = 8267174
  //LOCBINDTHANCRED = 8267173
  //LOCBINDURIANGER = 8260034

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1032518 || param2 == 1032518 ) // ACTOR0 = YSHTOLA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032519 || param2 == 1032519 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032520 || param2 == 1032520 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032264 || param2 == 1032264 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032521 || param2 == 1032521 ) // ACTOR4 = URIANGER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032266 || param2 == 1032266 ) // ACTOR5 = RYNE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR6 = TOLSHSAATH
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=TOLSHSAATH
            // +Callback Scene00008: Normal(Talk, FadeIn, Menu), id=unknown
          }
          break;
        }
        if( param1 == 1032522 || param2 == 1032522 ) // ACTOR7 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032523 || param2 == 1032523 ) // ACTOR8 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032524 || param2 == 1032524 ) // ACTOR9 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032525 || param2 == 1032525 ) // ACTOR10 = YSHTOLA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032526 || param2 == 1032526 ) // ACTOR11 = URIANGER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032527 || param2 == 1032527 ) // ACTOR12 = RYNE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 2010814 || param2 == 2010814 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010815 || param2 == 2010815 ) // EOBJECT1 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(Talk, FadeIn), id=unknown
          break;
        }
        if( param1 == 2010816 || param2 == 2010816 ) // EOBJECT2 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2011041 || param2 == 2011041 ) // EOBJECT3 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1032650 || param2 == 1032650 ) // ACTOR13 = TOLSHSAATH
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=TOLSHSAATH
          break;
        }
        if( param1 == 1032651 || param2 == 1032651 ) // ACTOR14 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032652 || param2 == 1032652 ) // ACTOR15 = ALISAIE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032653 || param2 == 1032653 ) // ACTOR16 = THANCRED
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032654 || param2 == 1032654 ) // ACTOR17 = YSHTOLA
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032655 || param2 == 1032655 ) // ACTOR18 = URIANGER
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032657 || param2 == 1032657 ) // ACTOR19 = RYNE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1032658 || param2 == 1032658 ) // ACTOR20 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2010208 || param2 == 2010208 ) // EOBJECT4 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010817 || param2 == 2010817 ) // EOBJECT5 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010818 || param2 == 2010818 ) // EOBJECT6 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010819 || param2 == 2010819 ) // EOBJECT7 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010820 || param2 == 2010820 ) // EOBJECT8 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010821 || param2 == 2010821 ) // EOBJECT9 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 2011040 || param2 == 2011040 ) // EOBJECT10 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 2011042 || param2 == 2011042 ) // EOBJECT11 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        if( param1 == 2011043 || param2 == 2011043 ) // EOBJECT12 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        if( param1 == 2011044 || param2 == 2011044 ) // EOBJECT13 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1027757 || param2 == 1027757 ) // ACTOR6 = unknown
        {
          Scene00043( player ); // Scene00043: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00044: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown
          break;
        }
        if( param1 == 1032522 || param2 == 1032522 ) // ACTOR7 = ALPHINAUD
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032523 || param2 == 1032523 ) // ACTOR8 = ALISAIE
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032524 || param2 == 1032524 ) // ACTOR9 = THANCRED
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1032525 || param2 == 1032525 ) // ACTOR10 = YSHTOLA
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032526 || param2 == 1032526 ) // ACTOR11 = URIANGER
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032527 || param2 == 1032527 ) // ACTOR12 = RYNE
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 2010817 || param2 == 2010817 ) // EOBJECT5 = unknown
        {
          Scene00051( player ); // Scene00051: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010818 || param2 == 2010818 ) // EOBJECT6 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010819 || param2 == 2010819 ) // EOBJECT7 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010820 || param2 == 2010820 ) // EOBJECT8 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010821 || param2 == 2010821 ) // EOBJECT9 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
          break;
        }
        if( param1 == 2011040 || param2 == 2011040 ) // EOBJECT10 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
          break;
        }
        if( param1 == 2011042 || param2 == 2011042 ) // EOBJECT11 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
          break;
        }
        if( param1 == 2011043 || param2 == 2011043 ) // EOBJECT12 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(None), id=unknown
          break;
        }
        if( param1 == 2011044 || param2 == 2011044 ) // EOBJECT13 = unknown
        {
          Scene00059( player ); // Scene00059: Normal(None), id=unknown
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
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmh107:69303 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00005: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00006: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00007: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00008: Normal(Talk, FadeIn, Menu), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00012: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00013: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00014: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00016: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00017: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00019: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00021: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00023: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00024: Normal(Talk, TargetCanMove), id=TOLSHSAATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00026: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00027: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00028: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00029: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00030: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00031: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00033: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00034: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00035: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00036: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00037: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00038: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00039: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00040: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00041: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00042: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00043: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00044( player );
      }
    };
    player.playScene( getId(), 43, NONE, callback );
  }
  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00044: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
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
    player.playScene( getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00045: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00046: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00047: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00048: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00049: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00050: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00051: Normal(None), id=unknown" );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00052: Normal(None), id=unknown" );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00053: Normal(None), id=unknown" );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00057: Normal(None), id=unknown" );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00058: Normal(None), id=unknown" );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "LucKmh107:69303 calling Scene00059: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKmh107 );
