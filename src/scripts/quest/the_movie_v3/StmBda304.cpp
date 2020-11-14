// FFXIVTheMovie.ParserV3.1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda304 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda304() : Sapphire::ScriptAPI::EventScript( 68016 ){}; 
  ~StmBda304() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 7 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEVENTSPIRIT = 1071
  //ACTOR0 = 1019929
  //ACTOR1 = 1019930
  //ACTOR10 = 1019939
  //ACTOR11 = 1019940
  //ACTOR12 = 1019941
  //ACTOR13 = 1021508
  //ACTOR2 = 1019931
  //ACTOR3 = 1019933
  //ACTOR4 = 1019932
  //ACTOR5 = 1021505
  //ACTOR6 = 1019935
  //ACTOR7 = 1019936
  //ACTOR8 = 1019937
  //ACTOR9 = 1019938
  //BINDACTOR0 = 6829396
  //BINDACTOR1 = 6829410
  //BINDACTOR2 = 6829411
  //BINDACTOR3 = 6829413
  //BINDACTOR4 = 6829414
  //BINDACTOR5 = 6829415
  //BINDACTOR6 = 6829417
  //EOBJECT0 = 2007852
  //EOBJECT1 = 2007854
  //EVENTACTION0 = 54
  //LOCACTOR0 = 1018509
  //LOCACTOR1 = 1019541

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1019929 || param2 == 1019929 ) // ACTOR0 = ALISAIE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019930 || param2 == 1019930 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk), id=LYSE
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019931 || param2 == 1019931 ) // ACTOR2 = TANSUI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TANSUI
          }
        }
        if( param1 == 1019933 || param2 == 1019933 ) // ACTOR3 = LYSE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019932 || param2 == 1019932 ) // ACTOR4 = ALISAIE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        break;
      }
      case 2:
      {
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR5 = RASHO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=RASHO
          }
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=TANSUI
        }
        if( param1 == 1019936 || param2 == 1019936 ) // ACTOR7 = ALISAIE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019937 || param2 == 1019937 ) // ACTOR8 = LYSE
        {
          Scene00009( player ); // Scene00009: Normal(Talk), id=LYSE
        }
        break;
      }
      case 3:
      {
        if( param1 == 1019938 || param2 == 1019938 ) // ACTOR9 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LYSE
          }
        }
        if( param1 == 1019939 || param2 == 1019939 ) // ACTOR10 = ALISAIE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=TANSUI
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR5 = RASHO
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=RASHO
        }
        break;
      }
      case 4:
      {
        if( param1 == 2007852 || param2 == 2007852 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(SystemTalk), id=unknown
          }
        }
        if( param1 == 2007854 || param2 == 2007854 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(SystemTalk), id=unknown
          }
        }
        if( param1 == 1019940 || param2 == 1019940 ) // ACTOR11 = LYSE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1019941 || param2 == 1019941 ) // ACTOR12 = ALISAIE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR5 = RASHO
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=RASHO
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=TANSUI
        }
        if( param1 == 1021508 || param2 == 1021508 ) // ACTOR13 = NAWASHIRO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=NAWASHIRO
          }
        }
        break;
      }
      case 255:
      {
        if( param1 == 1019939 || param2 == 1019939 ) // ACTOR10 = ALISAIE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE
          // +Callback Scene00024: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, SystemTalk), id=ALISAIE
        }
        if( param1 == 1019940 || param2 == 1019940 ) // ACTOR11 = LYSE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=LYSE
        }
        if( param1 == 1021505 || param2 == 1021505 ) // ACTOR5 = RASHO
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RASHO
        }
        if( param1 == 1019935 || param2 == 1019935 ) // ACTOR6 = TANSUI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=TANSUI
        }
        if( param1 == 1021508 || param2 == 1021508 ) // ACTOR13 = NAWASHIRO
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=NAWASHIRO
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8AL( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda304:68016 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00002: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00003: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00004: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00005: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00007: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00009: Normal(Talk), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00010: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00011: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00012: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00013: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00015: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00017: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00018: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00019: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00020: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00021: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00022: Normal(Talk, TargetCanMove), id=NAWASHIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00023: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00024: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu, SystemTalk), id=ALISAIE" );
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
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00025: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00026: Normal(Talk, TargetCanMove), id=RASHO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00027: Normal(Talk, TargetCanMove), id=TANSUI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda304:68016 calling Scene00028: Normal(Talk, TargetCanMove), id=NAWASHIRO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda304 );
