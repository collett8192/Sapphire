// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmh103 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmh103() : Sapphire::ScriptAPI::EventScript( 69299 ){}; 
  ~LucKmh103() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_3, 8 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1031722
  //ACTOR1 = 1032121
  //ACTOR10 = 1032499
  //ACTOR11 = 1032500
  //ACTOR12 = 1032501
  //ACTOR13 = 1032502
  //ACTOR2 = 1031724
  //ACTOR3 = 1031725
  //ACTOR4 = 1032122
  //ACTOR5 = 1030370
  //ACTOR6 = 1032497
  //ACTOR7 = 1032648
  //ACTOR8 = 1032649
  //ACTOR9 = 1032498
  //EVENTPICTRUELUCKMH103001 = 881
  //LOCACTIONEVENTBASEROOKIE = 855
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORLYNA = 1028109
  //LOCACTORSOLDIER01 = 1029538
  //LOCACTORSOLDIER02 = 1029539
  //LOCACTORSOLDIER03 = 1029540
  //LOCACTORSOLDIER04 = 1032568
  //LOCBINDALPHINAUD = 8259156
  //LOCPOSLCUTSTART = 8272416
  //NCUTLUCKMH00030 = 2234
  //NCUTLUCKMH00040 = 2235

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1031722 || param2 == 1031722 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR2 = URIANGER
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031725 || param2 == 1031725 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR4 = BEQLUGG
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030370 || param2 == 1030370 ) // ACTOR5 = LYNA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=LYNA
          }
          break;
        }
        if( param1 == 1032497 || param2 == 1032497 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR2 = URIANGER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031725 || param2 == 1031725 ) // ACTOR3 = YSHTOLA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR4 = BEQLUGG
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1032648 || param2 == 1032648 ) // ACTOR7 = LYNA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=LYNA
            // +Callback Scene00013: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1032649 || param2 == 1032649 ) // ACTOR8 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR2 = URIANGER
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031725 || param2 == 1031725 ) // ACTOR3 = YSHTOLA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR4 = BEQLUGG
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1032498 || param2 == 1032498 ) // ACTOR9 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1032499 || param2 == 1032499 ) // ACTOR10 = BRAVESOLDIER
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=BRAVESOLDIER
          break;
        }
        if( param1 == 1032500 || param2 == 1032500 ) // ACTOR11 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032501 || param2 == 1032501 ) // ACTOR12 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR2 = URIANGER
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031725 || param2 == 1031725 ) // ACTOR3 = YSHTOLA
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR4 = BEQLUGG
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1032502 || param2 == 1032502 ) // ACTOR13 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1031724 || param2 == 1031724 ) // ACTOR2 = URIANGER
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031725 || param2 == 1031725 ) // ACTOR3 = YSHTOLA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032122 || param2 == 1032122 ) // ACTOR4 = BEQLUGG
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=BEQLUGG
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmh103:69299 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00003: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00005: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove, Menu), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00008: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00009: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00011: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00012: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00013: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00015: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00016: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00018: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00020: Normal(Talk, TargetCanMove), id=BRAVESOLDIER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00023: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00024: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00026: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00027: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00028: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00029: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00030: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmh103:69299 calling Scene00031: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmh103 );
