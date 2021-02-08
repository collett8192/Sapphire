// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma209 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma209() : Sapphire::ScriptAPI::EventScript( 68826 ){}; 
  ~LucKma209() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1028990
  //ACTOR1 = 1027549
  //ACTOR10 = 1029015
  //ACTOR2 = 1029830
  //ACTOR3 = 1029831
  //ACTOR4 = 1029839
  //ACTOR5 = 1029840
  //ACTOR6 = 1029841
  //ACTOR7 = 1029807
  //ACTOR8 = 1029842
  //ACTOR9 = 1028923
  //BINDACTOR01 = 7929632
  //BINDACTOR02 = 7929633
  //BINDACTOR03 = 7929718
  //CUTSCENE0 = 1968
  //LOCACTOR01 = 1028116
  //LOCACTOR02 = 1028117
  //LOCACTOR03 = 1028119
  //LOCACTOR04 = 1028120
  //LOCACTOR05 = 1028587
  //LOCACTOR06 = 1028588
  //LOCACTOR07 = 1028591
  //LOCBGM01 = 362
  //LOCBGM02 = 716
  //LOCSE01 = 232
  //LOCSE02 = 124
  //POPRANGE0 = 7929719
  //POPRANGE1 = 7984633
  //POPRANGE2 = 7929726
  //QUESTLUCKMA309 = 68835

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( param1 == 1027549 || param2 == 1027549 ) // ACTOR1 = CHADDEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CHADDEN
            // +Callback Scene00003: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029830 || param2 == 1029830 ) // ACTOR2 = DULIACHAI
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1029831 || param2 == 1029831 ) // ACTOR3 = CHAINUZZ
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029839 || param2 == 1029839 ) // ACTOR4 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1029840 || param2 == 1029840 ) // ACTOR5 = KAISHIRR
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1029830 || param2 == 1029830 ) // ACTOR2 = DULIACHAI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1029831 || param2 == 1029831 ) // ACTOR3 = CHAINUZZ
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1029841 || param2 == 1029841 ) // ACTOR6 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove, AutoFadeIn), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1029830 || param2 == 1029830 ) // ACTOR2 = DULIACHAI
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1029831 || param2 == 1029831 ) // ACTOR3 = CHAINUZZ
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1029807 || param2 == 1029807 ) // ACTOR7 = SZEMDJENMAI
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=SZEMDJENMAI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029842 || param2 == 1029842 ) // ACTOR8 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029830 || param2 == 1029830 ) // ACTOR2 = DULIACHAI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1029831 || param2 == 1029831 ) // ACTOR3 = CHAINUZZ
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR9 = MYSTERYVOICE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029015 || param2 == 1029015 ) // ACTOR10 = ALISAIE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE
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
    player.sendDebug( "LucKma209:68826 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKma209:68826 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00002: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CHADDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00003: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00004: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00005: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00007: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00008: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00009: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00010: Normal(Talk, TargetCanMove, AutoFadeIn), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00011: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00012: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00013: Normal(Talk, TargetCanMove), id=SZEMDJENMAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00015: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00016: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00017: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma209:68826 calling Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma209 );
