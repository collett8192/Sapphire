// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma103 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma103() : Sapphire::ScriptAPI::EventScript( 68817 ){}; 
  ~LucKma103() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 3 entries
  //SEQ_4, 4 entries
  //SEQ_5, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1028925
  //ACTOR1 = 1029797
  //ACTOR2 = 1030533
  //ACTOR3 = 1028926
  //ACTOR4 = 1028927
  //ACTOR5 = 1030610
  //ACTOR6 = 1028923
  //CUTSCENE0 = 1958
  //CUTSCENE1 = 1959
  //CUTSCENE2 = 1960
  //CUTSCENE3 = 1961
  //POPRANGE0 = 7996298
  //POPRANGE1 = 8036159
  //POPRANGE2 = 7925167
  //POPRANGE3 = 7925168
  //POPRANGE4 = 8011405
  //POPRANGE5 = 8011414
  //QSTGAIUSD602 = 66031
  //TERRITORYTYPE0 = 813
  //TERRITORYTYPE1 = 844

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1028925 || param2 == 1028925 ) // ACTOR0 = MYSTERYVOICE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030533 || param2 == 1030533 ) // ACTOR2 = CRYSTALGATEKEEPER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CRYSTALGATEKEEPER
            // +Callback Scene00004: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00005( player ); // Scene00005: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1028925 || param2 == 1028925 ) // ACTOR0 = MYSTERYVOICE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=MYSTERYVOICE
          }
          break;
        }
        if( param1 == 1030533 || param2 == 1030533 ) // ACTOR2 = CRYSTALGATEKEEPER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CRYSTALGATEKEEPER
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00008( player ); // Scene00008: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1028926 || param2 == 1028926 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(CutScene, FadeIn, AutoFadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1030533 || param2 == 1030533 ) // ACTOR2 = CRYSTALGATEKEEPER
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CRYSTALGATEKEEPER
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00011( player ); // Scene00011: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1028927 || param2 == 1028927 ) // ACTOR4 = MYSTERYVOICE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=MYSTERYVOICE
          }
          break;
        }
        if( param1 == 1030533 || param2 == 1030533 ) // ACTOR2 = CRYSTALGATEKEEPER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=CRYSTALGATEKEEPER
          break;
        }
        if( param1 == 1030610 || param2 == 1030610 ) // ACTOR5 = GUIDEOFTHEPENDANTS
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=GUIDEOFTHEPENDANTS
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00015( player ); // Scene00015: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1030610 || param2 == 1030610 ) // ACTOR5 = GUIDEOFTHEPENDANTS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=GUIDEOFTHEPENDANTS
            // +Callback Scene00017: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1030533 || param2 == 1030533 ) // ACTOR2 = CRYSTALGATEKEEPER
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CRYSTALGATEKEEPER
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00019( player ); // Scene00019: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR6 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1030533 || param2 == 1030533 ) // ACTOR2 = CRYSTALGATEKEEPER
        {
          Scene00021( player ); // Scene00021: Normal(Talk, YesNo, TargetCanMove), id=CRYSTALGATEKEEPER
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma103:68817 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, Menu), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00002: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00003: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=CRYSTALGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00004: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00005: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00007: Normal(Talk, TargetCanMove), id=CRYSTALGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00008: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00009: Normal(CutScene, FadeIn, AutoFadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00010: Normal(Talk, TargetCanMove), id=CRYSTALGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00011: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00013: Normal(Talk, TargetCanMove), id=CRYSTALGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00014: Normal(Talk, TargetCanMove), id=GUIDEOFTHEPENDANTS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00015: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00016: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=GUIDEOFTHEPENDANTS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00017( player );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00017: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00018: Normal(Talk, TargetCanMove), id=CRYSTALGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00019: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKma103:68817 calling Scene00020: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.sendDebug( "LucKma103:68817 calling Scene00021: Normal(Talk, YesNo, TargetCanMove), id=CRYSTALGATEKEEPER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 844 );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma103 );
