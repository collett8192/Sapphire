// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_3 = dummye0
//SCENE_4 = dummye0
//SCENE_5 = dummye1
//SCENE_6 = dummye1
//SCENE_9 = dummye2
//SCENE_10 = dummye2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmf106 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmf106() : Sapphire::ScriptAPI::EventScript( 69185 ){}; 
  ~LucKmf106() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 3 entries
  //SEQ_3, 1 entries
  //SEQ_4, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1030517
  //ACTOR1 = 1030518
  //ACTOR2 = 5010000
  //ACTOR3 = 1030225
  //EOBJECT0 = 2010141
  //EOBJECT1 = 2010142
  //EOBJECT2 = 2010143
  //EVENTACTION0 = 50
  //EVENTPICTURE01 = 731
  //ITEM0 = 2002673
  //ITEM1 = 2002674
  //LOCACTOR01 = 1026571
  //LOCBGM01 = 649
  //SNIPE0 = 36

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA
        break;
      }
      //seq 2 event item ITEM0 = UI8BL max stack ?
      case 2:
      {
        if( param1 == 2010141 || param2 == 2010141 ) // EOBJECT0 = dummye0
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(SystemTalk), id=dummye0
            // +Callback Scene00004: Snipe(CanCancel), id=dummye0
          }
          break;
        }
        if( param1 == 2010142 || param2 == 2010142 ) // EOBJECT1 = dummye1
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Inventory), id=dummye1
            // +Callback Scene00006: Normal(SystemTalk), id=dummye1
          }
          break;
        }
        if( param1 == 1030518 || param2 == 1030518 ) // ACTOR1 = YSHTOLA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack ?
      case 3:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, TargetCanMove, Menu, SystemTalk), id=YSHTOLA
        break;
      }
      //seq 4 event item ITEM1 = UI8BH max stack ?
      case 4:
      {
        if( param1 == 2010143 || param2 == 2010143 ) // EOBJECT2 = dummye2
        {
          Scene00010( player ); // Scene00010: Normal(Talk, FadeIn), id=dummye2
          break;
        }
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack ?
      case 255:
      {
        Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA
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
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.updateQuest( getId(), 3 );
      }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmf106:69185 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00003: Normal(SystemTalk), id=dummye0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00004: Snipe(CanCancel), id=dummye0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 4, INVIS_ENPC, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00005: Normal(Inventory), id=dummye1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00006: Normal(SystemTalk), id=dummye1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00008: Normal(Talk, FadeIn, TargetCanMove, Menu, SystemTalk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq3( player );
      }
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00010: Normal(Talk, FadeIn), id=dummye2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00011: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmf106:69185 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA" );
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
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmf106 );
