// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmh104 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmh104() : Sapphire::ScriptAPI::EventScript( 69300 ){}; 
  ~LucKmh104() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 5 entries
  //SEQ_2, 7 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1032502
  //ACTOR1 = 1031722
  //ACTOR10 = 1027322
  //ACTOR11 = 1032503
  //ACTOR12 = 1029558
  //ACTOR13 = 1029561
  //ACTOR2 = 1032121
  //ACTOR3 = 1031724
  //ACTOR4 = 1031725
  //ACTOR5 = 1032122
  //ACTOR6 = 1027224
  //ACTOR7 = 1027248
  //ACTOR8 = 1027226
  //ACTOR9 = 1027232
  //BGMMUSICEX3NEWTHEMESECRET01 = 652
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORBEQLUGG = 1029471
  //LOCACTORMYSTERYVOICE = 1028166
  //LOCACTORURIANGER = 1026570
  //LOCACTORYSHTOLA = 1026571
  //NCUTLUCKMH00050 = 2236
  //NCUTLUCKMH00060 = 2237
  //POPRANGE0 = 7929675
  //QSTCHKLUCKBZ001 = 69165

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1032502 || param2 == 1032502 ) // ACTOR0 = LYNA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1031722 || param2 == 1031722 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR3 = URIANGER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031725 || param2 == 1031725 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR5 = BEQLUGG
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1031722 || param2 == 1031722 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00008: Normal(Talk, FadeIn, Menu), id=unknown
          }
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR3 = URIANGER
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031725 || param2 == 1031725 ) // ACTOR4 = YSHTOLA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR5 = BEQLUGG
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR6 = BRAGI
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=BRAGI
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=BRAGI
          }
          break;
        }
        if( param1 == 1027248 || param2 == 1027248 ) // ACTOR7 = CHESSAMILE
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=CHESSAMILE
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=CHESSAMILE
          }
          break;
        }
        if( param1 == 1027226 || param2 == 1027226 ) // ACTOR8 = MOREN
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MOREN
            // +Callback Scene00018: Normal(Talk, TargetCanMove), id=MOREN
          }
          break;
        }
        if( param1 == 1027232 || param2 == 1027232 ) // ACTOR9 = KATLISS
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=KATLISS
            // +Callback Scene00020: Normal(Talk, TargetCanMove), id=KATLISS
          }
          break;
        }
        if( param1 == 1027322 || param2 == 1027322 ) // ACTOR10 = GLYNARD
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=GLYNARD
            // +Callback Scene00022: Normal(Talk, TargetCanMove), id=GLYNARD
          }
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR5 = BEQLUGG
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1032503 || param2 == 1032503 ) // ACTOR11 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1029558 || param2 == 1029558 ) // ACTOR12 = YSHTOLA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029561 || param2 == 1029561 ) // ACTOR13 = URIANGER
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR6 = BRAGI
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=BRAGI
          break;
        }
        if( param1 == 1027248 || param2 == 1027248 ) // ACTOR7 = CHESSAMILE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=CHESSAMILE
          break;
        }
        if( param1 == 1027226 || param2 == 1027226 ) // ACTOR8 = MOREN
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=MOREN
          break;
        }
        if( param1 == 1027232 || param2 == 1027232 ) // ACTOR9 = KATLISS
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=KATLISS
          break;
        }
        if( param1 == 1027322 || param2 == 1027322 ) // ACTOR10 = GLYNARD
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=GLYNARD
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR5 = BEQLUGG
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=BEQLUGG
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
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmh104:69300 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00003: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00006: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00008: Normal(Talk, FadeIn, Menu), id=unknown" );
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
    player.sendDebug( "LucKmh104:69300 calling Scene00009: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00010: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00012: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00013: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00014: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00015: Normal(Talk, TargetCanMove), id=CHESSAMILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00016: Normal(Talk, TargetCanMove), id=CHESSAMILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00017: Normal(Talk, TargetCanMove), id=MOREN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00018: Normal(Talk, TargetCanMove), id=MOREN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00019: Normal(Talk, TargetCanMove), id=KATLISS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00020: Normal(Talk, TargetCanMove), id=KATLISS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00021: Normal(Talk, TargetCanMove), id=GLYNARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00022( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00022: Normal(Talk, TargetCanMove), id=GLYNARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00023: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00024: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00026( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00026: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00028: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00029: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00030: Normal(Talk, TargetCanMove), id=CHESSAMILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00031: Normal(Talk, TargetCanMove), id=MOREN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00032: Normal(Talk, TargetCanMove), id=KATLISS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00033: Normal(Talk, TargetCanMove), id=GLYNARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00034: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmh104:69300 calling Scene00035: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmh104 );
