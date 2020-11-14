// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda302 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda302() : Sapphire::ScriptAPI::EventScript( 68014 ){}; 
  ~StmBda302() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 11 entries
  //SEQ_2, 3 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTJOY = 953
  //ACTIONTIMELINEEVENTSAD = 954
  //ACTOR0 = 1019898
  //ACTOR1 = 1019899
  //ACTOR10 = 1019908
  //ACTOR11 = 1019909
  //ACTOR12 = 1019910
  //ACTOR13 = 1019911
  //ACTOR14 = 1019912
  //ACTOR15 = 1019913
  //ACTOR16 = 1019914
  //ACTOR17 = 1023650
  //ACTOR18 = 1023647
  //ACTOR19 = 1023648
  //ACTOR2 = 1019900
  //ACTOR20 = 1023649
  //ACTOR3 = 1019901
  //ACTOR4 = 1019902
  //ACTOR5 = 1019903
  //ACTOR6 = 1019904
  //ACTOR7 = 1019905
  //ACTOR8 = 1019906
  //ACTOR9 = 1019907
  //BINDACTOR0 = 6793902
  //BINDACTOR1 = 6793903
  //BINDACTOR2 = 6793904
  //BINDACTOR3 = 6793905
  //BINDACTOR4 = 6794074
  //BINDACTOR5 = 6794073
  //CUTSCENEN01 = 1409
  //EOBJECT0 = 2007848
  //EOBJECT1 = 2007849
  //EVENTACTION0 = 41
  //LOCACTOR0 = 1021964
  //POPRANGE0 = 6794084

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1019898 || param2 == 1019898 ) // ACTOR0 = TANSUI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=TANSUI
        }
        if( param1 == 1019899 || param2 == 1019899 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019900 || param2 == 1019900 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019901 || param2 == 1019901 ) // ACTOR3 = GOSETSU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
        }
        if( param1 == 1019902 || param2 == 1019902 ) // ACTOR4 = SOROBAN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SOROBAN
        }
        break;
      }
      case 1:
      {
        if( param1 == 2007848 || param2 == 2007848 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1019903 || param2 == 1019903 ) // ACTOR5 = LYSE
        {
          Scene00008( player ); // Scene00008: Normal(Talk), id=LYSE
        }
        if( param1 == 1019904 || param2 == 1019904 ) // ACTOR6 = ALISAIE
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019905 || param2 == 1019905 ) // ACTOR7 = GOSETSU
        {
          Scene00010( player ); // Scene00010: Normal(Talk), id=GOSETSU
        }
        if( param1 == 1019906 || param2 == 1019906 ) // ACTOR8 = SOROBAN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1019907 || param2 == 1019907 ) // ACTOR9 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( param1 == 1019908 || param2 == 1019908 ) // ACTOR10 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( param1 == 1019909 || param2 == 1019909 ) // ACTOR11 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( param1 == 1019910 || param2 == 1019910 ) // ACTOR12 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1019911 || param2 == 1019911 ) // ACTOR13 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( param1 == 2007849 || param2 == 2007849 ) // EOBJECT1 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( param1 == 1019912 || param2 == 1019912 ) // ACTOR14 = GOSETSU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=GOSETSU
          }
        }
        if( param1 == 1019913 || param2 == 1019913 ) // ACTOR15 = ALISAIE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019914 || param2 == 1019914 ) // ACTOR16 = LYSE
        {
          Scene00020( player ); // Scene00020: Normal(Talk), id=LYSE
        }
        break;
      }
      case 255:
      {
        if( param1 == 1023650 || param2 == 1023650 ) // ACTOR17 = SOROBAN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SOROBAN
        }
        if( param1 == 1023647 || param2 == 1023647 ) // ACTOR18 = LYSE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1023648 || param2 == 1023648 ) // ACTOR19 = ALISAIE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1023649 || param2 == 1023649 ) // ACTOR20 = GOSETSU
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=GOSETSU
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
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda302:68014 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00005: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00007: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 613, 117.6, -0.5, 501.78, -2.574, false );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00008: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00009: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00010: Normal(Talk), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00011: Normal(Talk, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00018: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00020: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SOROBAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00022: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda302:68014 calling Scene00024: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda302 );
