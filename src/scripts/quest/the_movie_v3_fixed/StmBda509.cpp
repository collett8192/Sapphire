// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda509 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda509() : Sapphire::ScriptAPI::EventScript( 68482 ){}; 
  ~StmBda509() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 7 entries
  //SEQ_2, 6 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1023084
  //ACTOR1 = 1020520
  //ACTOR2 = 1020222
  //ACTOR3 = 1020221
  //ACTOR4 = 1020223
  //ACTOR5 = 1020622
  //ACTOR6 = 1020224
  //ACTOR7 = 1020225
  //ACTOR8 = 1020519
  //ACTOR9 = 1020523
  //BINDHANCOCK001 = 7021290
  //ITEM0 = 2002379
  //ITEM1 = 2002174
  //ITEM2 = 2002175
  //LCUTSE0 = 39
  //LCUTSE1 = 40

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      case 0:
      {
        if( param1 == 1023084 || param2 == 1023084 ) // ACTOR0 = TATARU
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      //seq 1 event item ITEM1 = UI8CH max stack 1
      //seq 1 event item ITEM0 = UI8CL max stack 1
      case 1:
      {
        if( param1 == 1020222 || param2 == 1020222 ) // ACTOR2 = MANC02946
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: NpcTrade(Talk), id=unknown
            // +Callback Scene00004: Normal(Talk, TargetCanMove), id=MANC02946
          }
          break;
        }
        if( param1 == 1020221 || param2 == 1020221 ) // ACTOR3 = MANA02946
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00006: Normal(Talk, TargetCanMove, CanCancel), id=MANA02946
          }
          break;
        }
        if( param1 == 1020223 || param2 == 1020223 ) // ACTOR4 = MANB02946
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00008: Normal(Talk, TargetCanMove, CanCancel), id=MANB02946
          }
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR5 = HANCOCK
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020224 || param2 == 1020224 ) // ACTOR6 = MAND02946
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=MAND02946
          break;
        }
        if( param1 == 1020225 || param2 == 1020225 ) // ACTOR7 = TATARU
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=TATARU
          break;
        }
        break;
      }
      //seq 2 event item ITEM1 = UI8BH max stack 1
      //seq 2 event item ITEM2 = UI8BL max stack 1
      case 2:
      {
        if( param1 == 1023084 || param2 == 1023084 ) // ACTOR0 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00014: Normal(Talk, FadeIn, TargetCanMove), id=TATARU
          }
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR5 = HANCOCK
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020221 || param2 == 1020221 ) // ACTOR3 = MANA02946
        {
          Scene00017( player ); // Scene00017: Normal(Talk), id=MANA02946
          break;
        }
        if( param1 == 1020222 || param2 == 1020222 ) // ACTOR2 = MANC02946
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=MANC02946
          break;
        }
        if( param1 == 1020223 || param2 == 1020223 ) // ACTOR4 = MANB02946
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MANB02946
          break;
        }
        break;
      }
      //seq 255 event item ITEM2 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR8 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020622 || param2 == 1020622 ) // ACTOR5 = HANCOCK
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=HANCOCK
          break;
        }
        if( param1 == 1023084 || param2 == 1023084 ) // ACTOR0 = TATARU
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        if( param1 == 1020520 || param2 == 1020520 ) // ACTOR1 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR9 = YUGIRI
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI
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
    player.setQuestUI8CH( getId(), 1 );
    player.setQuestUI8CL( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
    //  if( player.getQuestUI8AL( getId() ) == 1 )
    //    if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.updateQuest( getId(), 2 );
          player.setQuestUI8BH( getId(), 1 );
          player.setQuestUI8BL( getId(), 1 );
        }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda509:68482 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00003: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00004: Normal(Talk, TargetCanMove), id=MANC02946" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00006( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00006: Normal(Talk, TargetCanMove, CanCancel), id=MANA02946" );
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
    player.sendDebug( "StmBda509:68482 calling Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00008( player );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00008: Normal(Talk, TargetCanMove, CanCancel), id=MANB02946" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8BH( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00009: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00010: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00011: Normal(Talk), id=MAND02946" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00012: Normal(Talk), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00014: Normal(Talk, FadeIn, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00015: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00016: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00017: Normal(Talk), id=MANA02946" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00018: Normal(Talk, TargetCanMove), id=MANC02946" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00019: Normal(Talk, TargetCanMove), id=MANB02946" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda509:68482 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00022: Normal(Talk, TargetCanMove), id=HANCOCK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00023: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda509:68482 calling Scene00025: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda509 );
