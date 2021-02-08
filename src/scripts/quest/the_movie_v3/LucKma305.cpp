// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_10 = dummye3
//SCENE_14 = dummye5
//SCENE_18 = dummye7
//EOBJECT0 = dummye0
//EOBJECT1 = dummye1
//EOBJECT2 = dummye2
//EOBJECT3 = dummye3
//EOBJECT4 = dummye4
//EOBJECT5 = dummye5
//EOBJECT6 = dummye6
//EOBJECT7 = dummye7
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma305 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma305() : Sapphire::ScriptAPI::EventScript( 68831 ){}; 
  ~LucKma305() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_5, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1029001
  //ACTOR1 = 1029002
  //EOBJECT0 = 2009849
  //EOBJECT1 = 2010647
  //EOBJECT2 = 2009850
  //EOBJECT3 = 2009851
  //EOBJECT4 = 2010648
  //EOBJECT5 = 2009852
  //EOBJECT6 = 2010649
  //EOBJECT7 = 2009853
  //EOBJECT8 = 2010650
  //EVENTACTION0 = 50
  //EVENTACTION1 = 21
  //NCUTEVENTLUCKMA30501 = 1971
  //POPRANGE0 = 7926837

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TESLEEN
        break;
      }
      case 1:
      {
        if( param1 == 2009849 || param2 == 2009849 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1029001 || param2 == 1029001 ) // ACTOR0 = TESLEEN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=TESLEEN
          break;
        }
        if( param1 == 2010647 || param2 == 2010647 ) // EOBJECT1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2009850 || param2 == 2009850 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010647 || param2 == 2010647 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2009851 || param2 == 2009851 ) // EOBJECT3 = dummye3
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(SystemTalk), id=dummye3
          }
          break;
        }
        if( param1 == 2010647 || param2 == 2010647 ) // EOBJECT1 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010648 || param2 == 2010648 ) // EOBJECT4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2009852 || param2 == 2009852 ) // EOBJECT5 = dummye5
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(SystemTalk), id=dummye5
          }
          break;
        }
        if( param1 == 2010648 || param2 == 2010648 ) // EOBJECT4 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010649 || param2 == 2010649 ) // EOBJECT6 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 2009853 || param2 == 2009853 ) // EOBJECT7 = dummye7
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(SystemTalk), id=dummye7
            // +Callback Scene00019: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 2010649 || param2 == 2010649 ) // EOBJECT6 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010650 || param2 == 2010650 ) // EOBJECT8 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        Scene00022( player ); // Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE
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
    player.sendDebug( "LucKma305:68831 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma305:68831 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00003: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00004: Normal(Talk, TargetCanMove), id=TESLEEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00007: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00010: Normal(SystemTalk), id=dummye3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00014: Normal(SystemTalk), id=dummye5" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00018: Normal(SystemTalk), id=dummye7" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00019: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma305:68831 calling Scene00022: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALISAIE" );
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
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma305 );
