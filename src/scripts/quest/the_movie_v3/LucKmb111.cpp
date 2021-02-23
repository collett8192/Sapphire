// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_8 = dummyBOSSOFFUATH
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb111 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb111() : Sapphire::ScriptAPI::EventScript( 68848 ){}; 
  ~LucKmb111() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 6 entries
  //SEQ_2, 5 entries
  //SEQ_3, 1 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTBASERESCUE2 = 4201
  //ACTOR0 = 1030535
  //ACTOR1 = 1029020
  //ACTOR10 = 1029161
  //ACTOR11 = 5010000
  //ACTOR12 = 1031669
  //ACTOR13 = 1029166
  //ACTOR2 = 1029021
  //ACTOR3 = 1029022
  //ACTOR4 = 1030872
  //ACTOR5 = 1030873
  //ACTOR6 = 1029157
  //ACTOR7 = 1029158
  //ACTOR8 = 1029159
  //ACTOR9 = 1029160
  //BGMTREMENDOUS01 = 190
  //BINDACTOR0 = 7921806
  //CUTSCENE0 = 1993
  //CUTSCENE1 = 1994
  //EOBJECT0 = 2009828
  //EVENTACTION0 = 1
  //INSTANCEDUNGEON0 = 65
  //LCUTACTOR0 = 1026570
  //LCUTACTOR1 = 1026569
  //LCUTACTOR2 = 1026572
  //LCUTACTOR3 = 1026568
  //LCUTACTOR4 = 1026567
  //LCUTACTOR5 = 1028134
  //POPRANGE0 = 7929756
  //SCREENIMAGE0 = 743
  //TERRITORYTYPE0 = 816

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030535 || param2 == 1030535 ) // ACTOR0 = SULUIN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=SULUIN
          break;
        }
        if( param1 == 1029020 || param2 == 1029020 ) // ACTOR1 = URIANGER
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029021 || param2 == 1029021 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029022 || param2 == 1029022 ) // ACTOR3 = RYNE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030872 || param2 == 1030872 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030873 || param2 == 1030873 ) // ACTOR5 = ALISAIE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009828 || param2 == 2009828 ) // EOBJECT0 = dummyBOSSOFFUATH
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=dummyBOSSOFFUATH
          }
          break;
        }
        if( param1 == 1029157 || param2 == 1029157 ) // ACTOR6 = URIANGER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029158 || param2 == 1029158 ) // ACTOR7 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029159 || param2 == 1029159 ) // ACTOR8 = RYNE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029160 || param2 == 1029160 ) // ACTOR9 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029161 || param2 == 1029161 ) // ACTOR10 = ALISAIE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1029157 || param2 == 1029157 ) // ACTOR6 = URIANGER
        {
          Scene00014( player ); // Scene00014: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER
          break;
        }
        if( param1 == 1029158 || param2 == 1029158 ) // ACTOR7 = THANCRED
        {
          Scene00015( player ); // Scene00015: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED
          break;
        }
        if( param1 == 1029159 || param2 == 1029159 ) // ACTOR8 = RYNE
        {
          Scene00016( player ); // Scene00016: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE
          break;
        }
        if( param1 == 1029160 || param2 == 1029160 ) // ACTOR9 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD
          break;
        }
        if( param1 == 1029161 || param2 == 1029161 ) // ACTOR10 = ALISAIE
        {
          Scene00018( player ); // Scene00018: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE
          break;
        }
        break;
      }
      case 3:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00019( player ); // Scene00019: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1031669 || param2 == 1031669 ) // ACTOR12 = URIANGER
        {
          Scene00020( player ); // Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=URIANGER
          break;
        }
        if( param1 == 1029166 || param2 == 1029166 ) // ACTOR13 = ALISAIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKmb111:68848 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=SULUIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00002: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00004: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00006: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove), id=dummyBOSSOFFUATH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00009: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00011: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00012: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00013: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00014: MsqDungeon(Talk, TargetCanMove, Menu), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00019( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00015: MsqDungeon(Talk, TargetCanMove, Menu), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00019( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00016: MsqDungeon(Talk, TargetCanMove, Menu), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00019( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00017: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00019( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00018: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00019( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmb111:68848 calling Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=URIANGER" );
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
    player.sendDebug( "LucKmb111:68848 calling Scene00021: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb111 );
