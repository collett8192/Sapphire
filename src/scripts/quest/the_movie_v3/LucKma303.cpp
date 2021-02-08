// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_3 = dummye0
//SCENE_5 = dummye1
//SCENE_7 = dummye2
//EOBJECT0 = dummye0
//EOBJECT1 = dummye1
//EOBJECT2 = dummye2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma303 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma303() : Sapphire::ScriptAPI::EventScript( 68829 ){}; 
  ~LucKma303() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 11 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1028974
  //ACTOR1 = 1030383
  //ACTOR2 = 1030384
  //ACTOR3 = 1030385
  //ACTOR4 = 5010000
  //ACTOR5 = 1028976
  //ACTOR6 = 1030871
  //EOBJECT0 = 2009934
  //EOBJECT1 = 2009935
  //EOBJECT2 = 2009936
  //EOBJECT3 = 2010198
  //EOBJECT4 = 2010199
  //EOBJECT5 = 2010200
  //EOBJECT6 = 2010201
  //EVENTACTION0 = 16
  //EVENTACTION1 = 32
  //EVENTACTION2 = 15
  //EVENTACTION3 = 31
  //ITEM0 = 2002717
  //ITEM1 = 2002618
  //LOCACTOR0 = 1028124
  //LOCACTOR1 = 1028126
  //LOCACTOR2 = 1029337
  //LOCBINDACTOR0 = 7810839
  //LOCBINDACTOR1 = 7810825
  //LOCBINDACTOR2 = 7810850
  //LOCBINDACTOR3 = 7810832
  //LOCBINDACTOR4 = 7943702
  //LOCBINDACTOR5 = 7943706
  //LOCBINDACTOR6 = 7943707
  //LOCBINDACTOR7 = 7967845

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, SystemTalk), id=CASSARD
        break;
      }
      //seq 1 event item ITEM1 = UI8BH max stack 3
      //seq 1 event item ITEM0 = UI8BL max stack ?
      case 1:
      {
        if( param1 == 2009934 || param2 == 2009934 ) // EOBJECT0 = dummye0
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk), id=dummye0
          }
          break;
        }
        if( param1 == 2009935 || param2 == 2009935 ) // EOBJECT1 = dummye1
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, Menu, CanCancel), id=dummye1
          }
          break;
        }
        if( param1 == 2009936 || param2 == 2009936 ) // EOBJECT2 = dummye2
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk), id=dummye2
          }
          break;
        }
        if( param1 == 1030383 || param2 == 1030383 ) // ACTOR1 = THONTON
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=THONTON
          break;
        }
        if( param1 == 1030384 || param2 == 1030384 ) // ACTOR2 = THOLTOL
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THOLTOL
          break;
        }
        if( param1 == 1030385 || param2 == 1030385 ) // ACTOR3 = MHULMUL
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MHULMUL
          break;
        }
        if( param1 == 2010198 || param2 == 2010198 ) // EOBJECT3 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010199 || param2 == 2010199 ) // EOBJECT4 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 2010200 || param2 == 2010200 ) // EOBJECT5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 2010201 || param2 == 2010201 ) // EOBJECT6 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR4 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(Talk), id=unknown
          // +Callback Scene00019: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 3
      //seq 255 event item ITEM0 = UI8BL max stack ?
      case 255:
      {
        if( param1 == 1028976 || param2 == 1028976 ) // ACTOR5 = CASSARD
        {
          Scene00021( player ); // Scene00021: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00022: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CASSARD
          break;
        }
        if( param1 == 1030383 || param2 == 1030383 ) // ACTOR1 = THONTON
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=THONTON
          break;
        }
        if( param1 == 1030384 || param2 == 1030384 ) // ACTOR2 = THOLTOL
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=THOLTOL
          break;
        }
        if( param1 == 1030385 || param2 == 1030385 ) // ACTOR3 = MHULMUL
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=MHULMUL
          break;
        }
        if( param1 == 1030871 || param2 == 1030871 ) // ACTOR6 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 3 );
      player.setQuestUI8BL( getId(), 1 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma303:68829 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove, SystemTalk), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00003: Normal(Talk), id=dummye0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00005: Normal(Talk, Menu, CanCancel), id=dummye1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00007: Normal(Talk), id=dummye2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00008: Normal(Talk, TargetCanMove), id=THONTON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00009: Normal(Talk, TargetCanMove), id=THOLTOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00010: Normal(Talk, TargetCanMove), id=MHULMUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00012: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00014: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00016: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00018: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00019: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00021: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00022( player );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00022: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=CASSARD" );
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
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00023: Normal(Talk, TargetCanMove), id=THONTON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00024: Normal(Talk, TargetCanMove), id=THOLTOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00025: Normal(Talk, TargetCanMove), id=MHULMUL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKma303:68829 calling Scene00026: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKma303 );
