// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVne107 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVne107() : Sapphire::ScriptAPI::EventScript( 67883 ){}; 
  ~HeaVne107() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1017750
  //ACTOR1 = 1017751
  //ACTOR10 = 1017756
  //ACTOR11 = 1017757
  //ACTOR12 = 1017758
  //ACTOR13 = 1017759
  //ACTOR2 = 1006224
  //ACTOR3 = 1006213
  //ACTOR4 = 1006223
  //ACTOR5 = 1017753
  //ACTOR6 = 1017752
  //ACTOR7 = 1006215
  //ACTOR8 = 1017754
  //ACTOR9 = 1017755
  //CUTSCENEN01 = 1261
  //LOCACTION0 = 1071
  //LOCACTOR0 = 6433884
  //LOCACTOR1 = 6433885
  //LOCACTOR2 = 6433796
  //LOCACTOR3 = 6433875
  //LOCACTOR4 = 6433876
  //LOCFACIAL0 = 607
  //POPRANGE0 = 6433886

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1017750 || param2 == 1017750 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017751 || param2 == 1017751 ) // ACTOR1 = ALISAIE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 1:
      {
        if( param1 == 1006224 || param2 == 1006224 ) // ACTOR2 = TALEBOT
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TALEBOT
            // +Callback Scene00004: Normal(Talk, TargetCanMove), id=TALEBOT
          }
        }
        if( param1 == 1006213 || param2 == 1006213 ) // ACTOR3 = OTELIN
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=OTELIN
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=OTELIN
          }
        }
        if( param1 == 1006223 || param2 == 1006223 ) // ACTOR4 = SIFRID
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=SIFRID
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=SIFRID
          }
        }
        if( param1 == 1017753 || param2 == 1017753 ) // ACTOR5 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017752 || param2 == 1017752 ) // ACTOR6 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        if( param1 == 1017750 || param2 == 1017750 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1017751 || param2 == 1017751 ) // ACTOR1 = ALISAIE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1006224 || param2 == 1006224 ) // ACTOR2 = TALEBOT
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=TALEBOT
        }
        if( param1 == 1006213 || param2 == 1006213 ) // ACTOR3 = OTELIN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=OTELIN
        }
        if( param1 == 1006223 || param2 == 1006223 ) // ACTOR4 = SIFRID
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=SIFRID
        }
        break;
      }
      case 3:
      {
        if( param1 == 1006215 || param2 == 1006215 ) // ACTOR7 = GUNDOBALD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=GUNDOBALD
          }
        }
        if( param1 == 1017754 || param2 == 1017754 ) // ACTOR8 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017755 || param2 == 1017755 ) // ACTOR9 = ALISAIE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1006224 || param2 == 1006224 ) // ACTOR2 = TALEBOT
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TALEBOT
        }
        if( param1 == 1006213 || param2 == 1006213 ) // ACTOR3 = OTELIN
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=OTELIN
        }
        if( param1 == 1006223 || param2 == 1006223 ) // ACTOR4 = SIFRID
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=SIFRID
        }
        break;
      }
      case 4:
      {
        if( param1 == 1017756 || param2 == 1017756 ) // ACTOR10 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00023: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1017755 || param2 == 1017755 ) // ACTOR9 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1006224 || param2 == 1006224 ) // ACTOR2 = TALEBOT
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TALEBOT
        }
        if( param1 == 1006213 || param2 == 1006213 ) // ACTOR3 = OTELIN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=OTELIN
        }
        if( param1 == 1006223 || param2 == 1006223 ) // ACTOR4 = SIFRID
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=SIFRID
        }
        if( param1 == 1006215 || param2 == 1006215 ) // ACTOR7 = GUNDOBALD
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=GUNDOBALD
        }
        break;
      }
      case 255:
      {
        if( param1 == 1017757 || param2 == 1017757 ) // ACTOR11 = ALPHINAUD
        {
          Scene00029( player ); // Scene00029: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1017755 || param2 == 1017755 ) // ACTOR9 = ALISAIE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1017758 || param2 == 1017758 ) // ACTOR12 = YDA
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=YDA
        }
        if( param1 == 1017759 || param2 == 1017759 ) // ACTOR13 = PAPALYMO
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=PAPALYMO
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
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVne107:67883 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00002: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00003: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling [BranchTrue]Scene00004: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00005: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling [BranchTrue]Scene00006: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00007: Normal(Talk, TargetCanMove), id=SIFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling [BranchTrue]Scene00008: Normal(Talk, TargetCanMove), id=SIFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00012: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00013: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00014: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00015: Normal(Talk, TargetCanMove), id=SIFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00016: Normal(Talk, TargetCanMove), id=GUNDOBALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00018: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00019: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00020: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00021: Normal(Talk, TargetCanMove), id=SIFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling [BranchTrue]Scene00023: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 23, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00025: Normal(Talk, TargetCanMove), id=TALEBOT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00026: Normal(Talk, TargetCanMove), id=OTELIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00027: Normal(Talk, TargetCanMove), id=SIFRID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00028: Normal(Talk, TargetCanMove), id=GUNDOBALD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00029: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00030: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00031: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVne107:67883 calling Scene00032: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVne107 );
