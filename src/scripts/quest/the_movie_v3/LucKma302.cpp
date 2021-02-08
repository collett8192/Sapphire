// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma302 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma302() : Sapphire::ScriptAPI::EventScript( 68828 ){}; 
  ~LucKma302() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1028963
  //ACTOR1 = 1027872
  //ACTOR2 = 1028974
  //ACTOR3 = 1027873
  //ITEM0 = 2002543
  //LOCACTOR0 = 1029334
  //LOCACTOR1 = 1029335
  //LOCACTOR2 = 1029336
  //LOCACTOR3 = 1028846
  //LOCEOBJ0 = 2010353
  //LOCEOBJ1 = 2010354
  //LOCEOBJ2 = 2010355
  //LOCEOBJ3 = 2010356
  //LOCSE0 = 190
  //LOCSE1 = 124
  //LOCSE2 = 142
  //LOCSEEATVIOLENTLY = 214
  //NCUTEVENTLUCKMA30201 = 1970
  //SNP0 = 27

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=CASSARD
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 1027872 || param2 == 1027872 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1028974 || param2 == 1028974 ) // ACTOR2 = CASSARD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=CASSARD
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 1027873 || param2 == 1027873 ) // ACTOR3 = RHONRON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove, SystemTalk), id=RHONRON
            // +Callback Scene00005: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00006: Normal(Talk, FadeIn, TargetCanMove, Menu), id=RHONRON
          }
          break;
        }
        if( param1 == 1028974 || param2 == 1028974 ) // ACTOR2 = CASSARD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CASSARD
          break;
        }
        if( param1 == 1027872 || param2 == 1027872 ) // ACTOR1 = GHENGEN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=GHENGEN
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      case 255:
      {
        if( param1 == 1027872 || param2 == 1027872 ) // ACTOR1 = GHENGEN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GHENGEN
          break;
        }
        if( param1 == 1028974 || param2 == 1028974 ) // ACTOR2 = CASSARD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CASSARD
          break;
        }
        if( param1 == 1027873 || param2 == 1027873 ) // ACTOR3 = RHONRON
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=RHONRON
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma302:68828 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00003: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00004: Normal(Talk, TargetCanMove, SystemTalk), id=RHONRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00005: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00006( player );
      }
    };
    player.playScene( getId(), 5, INVIS_ENPC, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove, Menu), id=RHONRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00007: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00008: Normal(Talk, TargetCanMove), id=GHENGEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GHENGEN" );
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
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00010: Normal(Talk, TargetCanMove), id=CASSARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma302:68828 calling Scene00011: Normal(Talk, TargetCanMove), id=RHONRON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma302 );
