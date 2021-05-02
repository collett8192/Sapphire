// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmd113 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmd113() : Sapphire::ScriptAPI::EventScript( 69154 ){}; 
  ~LucKmd113() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 6 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1029759
  //ACTOR1 = 1029760
  //ACTOR10 = 1031250
  //ACTOR11 = 1031251
  //ACTOR12 = 1031252
  //ACTOR13 = 1029765
  //ACTOR14 = 1029766
  //ACTOR15 = 1029767
  //ACTOR2 = 1029754
  //ACTOR3 = 1030371
  //ACTOR4 = 1029761
  //ACTOR5 = 1029647
  //ACTOR6 = 1029646
  //ACTOR7 = 1029648
  //ACTOR8 = 1029763
  //ACTOR9 = 1029638
  //ITEM0 = 2002565
  //LOCACTION0 = 5662
  //LOCACTORMAGNUS = 1028147
  //LOCACTORTHANCRED = 1026569
  //LOCBGM0 = 647
  //LOCBINDACTOR0 = 7935095
  //LOCBINDACTOR1 = 7934689
  //LOCBINDACTOR2 = 7934686
  //LOCBINDACTOR3 = 7934688
  //LOCBINDACTOR4 = 8051944
  //LOCBINDACTOR5 = 7934886
  //LOCBINDACTOR6 = 7934949
  //LOCBINDACTOR7 = 7934987
  //LOCBINDACTOR8 = 7934993
  //LOCBINDACTOR9 = 7935143
  //NCUTEVENTLUCKMD11301 = 2027
  //NCUTEVENTLUCKMD11302 = 2028
  //POPRANGE0 = 7955086
  //QUESTGAIUSD602 = 66031
  //QUESTHEAVNR305 = 67875
  //QUESTSTMBDR304 = 68693

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029759 || param2 == 1029759 ) // ACTOR0 = GUTHJON
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUTHJON
          break;
        }
        if( param1 == 1029760 || param2 == 1029760 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 1029754 || param2 == 1029754 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029759 || param2 == 1029759 ) // ACTOR0 = GUTHJON
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GUTHJON
          break;
        }
        if( param1 == 1030371 || param2 == 1030371 ) // ACTOR3 = THANCRED
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 1029761 || param2 == 1029761 ) // ACTOR4 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=URIANGER
            // +Callback Scene00008: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029647 || param2 == 1029647 ) // ACTOR5 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029754 || param2 == 1029754 ) // ACTOR2 = MAGNUS
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029646 || param2 == 1029646 ) // ACTOR6 = JERYK
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029648 || param2 == 1029648 ) // ACTOR7 = RYNE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029763 || param2 == 1029763 ) // ACTOR8 = THAFFE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029638 || param2 == 1029638 ) // ACTOR9 = URIANGER
        {
          Scene00014( player ); // Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1031250 || param2 == 1031250 ) // ACTOR10 = THANCRED
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1031251 || param2 == 1031251 ) // ACTOR11 = RYNE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1031252 || param2 == 1031252 ) // ACTOR12 = JERYK
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029765 || param2 == 1029765 ) // ACTOR13 = MAGNUS
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029766 || param2 == 1029766 ) // ACTOR14 = THAFFE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029767 || param2 == 1029767 ) // ACTOR15 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
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
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmd113:69154 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00003: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00004: Normal(Talk, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00007: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00008: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00010: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00011: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00012: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00013: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00014: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER" );
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
    player.sendDebug( "LucKmd113:69154 calling Scene00015: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00016: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00017: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00018: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00019: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmd113:69154 calling Scene00020: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKmd113 );
