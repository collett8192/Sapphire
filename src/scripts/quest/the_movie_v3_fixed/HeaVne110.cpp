// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVne110 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVne110() : Sapphire::ScriptAPI::EventScript( 67886 ){}; 
  ~HeaVne110() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 5 entries
  //SEQ_255, 16 entries

  //ACTOR0 = 1017767
  //ACTOR1 = 1017768
  //ACTOR10 = 1017793
  //ACTOR11 = 1017773
  //ACTOR12 = 1017776
  //ACTOR13 = 1017777
  //ACTOR14 = 1017778
  //ACTOR15 = 1017779
  //ACTOR16 = 1017780
  //ACTOR17 = 1017781
  //ACTOR18 = 1017782
  //ACTOR19 = 1017783
  //ACTOR2 = 1017769
  //ACTOR20 = 1017784
  //ACTOR21 = 1017794
  //ACTOR22 = 1017795
  //ACTOR23 = 1017796
  //ACTOR3 = 1017770
  //ACTOR4 = 1017771
  //ACTOR5 = 1017772
  //ACTOR6 = 1017417
  //ACTOR7 = 1017775
  //ACTOR8 = 1006215
  //ACTOR9 = 1017792
  //CUTSCENEN01 = 1268
  //CUTSCENEN02 = 1269
  //CUTSCENEN03 = 1270
  //CUTSCENEN04 = 1271
  //LOCACTOR0 = 1011887
  //LOCACTOR1 = 1017699
  //LOCACTOR2 = 6433909
  //LOCACTOR3 = 6433910
  //LOCACTOR4 = 6433912
  //LOCACTOR5 = 1016788
  //POPRANGE0 = 6445540
  //POPRANGE1 = 6584515

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1017767 || param2 == 1017767 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017768 || param2 == 1017768 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017769 || param2 == 1017769 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk), id=THANCRED
        }
        if( param1 == 1017770 || param2 == 1017770 ) // ACTOR3 = URIANGER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
        }
        break;
      }
      case 1:
      {
        if( param1 == 1017768 || param2 == 1017768 ) // ACTOR1 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
          }
        }
        if( param1 == 1017770 || param2 == 1017770 ) // ACTOR3 = URIANGER
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=URIANGER
        }
        break;
      }
      case 2:
      {
        if( param1 == 1017771 || param2 == 1017771 ) // ACTOR4 = PAPALYMO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=PAPALYMO
          }
        }
        if( param1 == 1017772 || param2 == 1017772 ) // ACTOR5 = YDA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YDA
        }
        if( param1 == 1017417 || param2 == 1017417 ) // ACTOR6 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 3:
      {
        if( param1 == 1017775 || param2 == 1017775 ) // ACTOR7 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00011: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1006215 || param2 == 1006215 ) // ACTOR8 = GUNDOBALD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=GUNDOBALD
        }
        if( param1 == 1017792 || param2 == 1017792 ) // ACTOR9 = HOARYBOULDER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HOARYBOULDER
        }
        if( param1 == 1017793 || param2 == 1017793 ) // ACTOR10 = COULTENET
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=COULTENET
        }
        if( param1 == 1017773 || param2 == 1017773 ) // ACTOR11 = FLHAMINN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017776 || param2 == 1017776 ) // ACTOR12 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017773 || param2 == 1017773 ) // ACTOR11 = FLHAMINN
        {
          Scene00017( player ); // Scene00017: Normal(CutScene), id=unknown
          // +Callback Scene00018: Normal(Talk, TargetCanMove), id=FLHAMINN
        }
        if( param1 == 1017777 || param2 == 1017777 ) // ACTOR13 = ALISAIE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017778 || param2 == 1017778 ) // ACTOR14 = TATARU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1017779 || param2 == 1017779 ) // ACTOR15 = THANCRED
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1017780 || param2 == 1017780 ) // ACTOR16 = YSHTOLA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1017781 || param2 == 1017781 ) // ACTOR17 = URIANGER
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=URIANGER
        }
        if( param1 == 1017782 || param2 == 1017782 ) // ACTOR18 = KRILE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1017783 || param2 == 1017783 ) // ACTOR19 = YDA
        {
          Scene00025( player ); // Scene00025: Normal(Talk), id=YDA
        }
        if( param1 == 1017784 || param2 == 1017784 ) // ACTOR20 = PAPALYMO
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( param1 == 1017792 || param2 == 1017792 ) // ACTOR9 = HOARYBOULDER
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=HOARYBOULDER
        }
        if( param1 == 1017793 || param2 == 1017793 ) // ACTOR10 = COULTENET
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=COULTENET
        }
        if( param1 == 1017794 || param2 == 1017794 ) // ACTOR21 = OCHERBOULDER
        {
          Scene00029( player ); // Scene00029: Normal(Talk), id=OCHERBOULDER
        }
        if( param1 == 1017795 || param2 == 1017795 ) // ACTOR22 = AENOR
        {
          Scene00030( player ); // Scene00030: Normal(Talk), id=AENOR
        }
        if( param1 == 1017796 || param2 == 1017796 ) // ACTOR23 = CLEMENCE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=CLEMENCE
        }
        if( param1 == 1006215 || param2 == 1006215 ) // ACTOR8 = GUNDOBALD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=GUNDOBALD
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
    player.sendDebug( "HeaVne110:67886 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVne110:67886 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00003: Normal(Talk), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00006: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00008: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling [BranchTrue]Scene00011: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00012: Normal(Talk, TargetCanMove), id=GUNDOBALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00013: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00014: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00015: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00017: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling [BranchTrue]Scene00018: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00020: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00021: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00023: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00024: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00025: Normal(Talk), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00026: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00027: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00028: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00029: Normal(Talk), id=OCHERBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00030: Normal(Talk), id=AENOR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00031: Normal(Talk, TargetCanMove), id=CLEMENCE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVne110:67886 calling Scene00032: Normal(Talk, TargetCanMove), id=GUNDOBALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne110 );
