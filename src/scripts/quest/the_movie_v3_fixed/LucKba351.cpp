// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba351 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba351() : Sapphire::ScriptAPI::EventScript( 68814 ){}; 
  ~LucKba351() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_4, 2 entries
  //SEQ_5, 2 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1030144
  //ACTOR1 = 1030145
  //ACTOR2 = 1027253
  //ACTOR3 = 1030153
  //ACTOR4 = 1030990
  //ACTOR5 = 1030964
  //CUTSCENE00 = 2106
  //CUTSCENE01 = 2107
  //EOBJECT0 = 2010406
  //EOBJECT1 = 2010407
  //EVENTACTION0 = 12
  //EVENTACTION1 = 1
  //LEVELENPCID0 = 7963559
  //LEVELENPCID1 = 7964664
  //LEVELENPCID2 = 7963557
  //LEVELEOBJID0 = 7964571
  //LOCACTOR0 = 1030128
  //LOCACTOR1 = 1030991
  //LOCEOBJ0 = 2010731
  //LOCMOTION0 = 6229
  //LOCMOTION1 = 5464
  //LOCMOTION2 = 5465
  //LOCMOTION3 = 5468
  //LOCMOTION4 = 5471
  //LOCMOTION5 = 5473
  //LOCMOTION6 = 5476
  //LOCMOTION7 = 800
  //LOCMOTION8 = 5469
  //LOCSE0 = 190
  //LOGMES00 = 3744
  //QUEST0 = 69168
  //QUESTBATTLE0 = 196
  //TERRITORYTYPE0 = 871
  //TERRITORYTYPE1 = 817

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030144 || param2 == 1030144 ) // ACTOR0 = LUEREEQ
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=LUEREEQ
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR1 = OLVARA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=OLVARA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1027253 || param2 == 1027253 ) // ACTOR2 = LOYTHE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LOYTHE
          }
          break;
        }
        if( param1 == 1030153 || param2 == 1030153 ) // ACTOR3 = LUEREEQ
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LUEREEQ
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR1 = OLVARA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=OLVARA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2010406 || param2 == 2010406 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR1 = OLVARA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=OLVARA
          break;
        }
        if( param1 == 1027253 || param2 == 1027253 ) // ACTOR2 = LOYTHE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=LOYTHE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030990 || param2 == 1030990 ) // ACTOR4 = LUEREEQ
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, QuestBattle, YesNo, Message, TargetCanMove, CanCancel), id=LUEREEQ
            // +Callback Scene00011: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR1 = OLVARA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=OLVARA
          break;
        }
        if( param1 == 2010407 || param2 == 2010407 ) // EOBJECT1 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00015( player ); // Scene00015: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR1 = OLVARA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=OLVARA
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR1 = OLVARA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=OLVARA
          }
          break;
        }
        if( param1 == 1030144 || param2 == 1030144 ) // ACTOR0 = LUEREEQ
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=LUEREEQ
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030964 || param2 == 1030964 ) // ACTOR5 = LUEREEQ
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LUEREEQ
          // +Callback Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, CanCancel), id=LUEREEQ
          break;
        }
        if( param1 == 1030145 || param2 == 1030145 ) // ACTOR1 = OLVARA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=OLVARA
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
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKba351:68814 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=LUEREEQ" );
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
    player.sendDebug( "LucKba351:68814 calling Scene00002: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00003: Normal(Talk, TargetCanMove), id=LOYTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00004: Normal(Talk, TargetCanMove), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00005: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00007: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00008: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00009: Normal(Talk, TargetCanMove), id=LOYTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00010: Normal(Talk, QuestBattle, YesNo, Message, TargetCanMove, CanCancel), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00011: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00012: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00015: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00016: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00017: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00018: Normal(Talk, TargetCanMove), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00019: Normal(Talk, TargetCanMove), id=LUEREEQ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, CanCancel), id=LUEREEQ" );
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
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKba351:68814 calling Scene00021: Normal(Talk, TargetCanMove), id=OLVARA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKba351 );
