// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKbb201 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKbb201() : Sapphire::ScriptAPI::EventScript( 68785 ){}; 
  ~LucKbb201() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1028721
  //ACTOR1 = 1028722
  //ACTOR2 = 1028723
  //ACTOR3 = 1028725
  //ACTOR4 = 1028724
  //ACTOR5 = 1028728
  //BINDACTOR01 = 7883451
  //BINDACTOR02 = 7883502
  //CLASSJOB = 38
  //EOBJECT0 = 2009763
  //EVENTACTION0 = 12
  //LOCACTOR01 = 1028170
  //LOCACTOR02 = 1028172
  //LOCACTOR03 = 1028173
  //LOCACTOR04 = 1028174
  //LOCACTOR05 = 1028175
  //LOCACTOR06 = 1006066
  //LOCACTOR07 = 1006068
  //LOCACTOR08 = 1006069
  //LOCIDLE01 = 873
  //LOCIDLE02 = 925
  //LOCIDLE03 = 799
  //LOCIDLE04 = 796
  //NCUTEVENTLUCKBB20101 = 2076
  //UNLOCKIMAGECLASS = 761

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1028721 || param2 == 1028721 ) // ACTOR0 = EXCITEDTOWNSMAN03249
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EXCITEDTOWNSMAN03249
        }
        if( param1 == 1028722 || param2 == 1028722 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
        }
        break;
      }
      case 1:
      {
        if( param1 == 1028723 || param2 == 1028723 ) // ACTOR2 = RANAAMIHGO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RANAAMIHGO
          }
        }
        if( param1 == 1028725 || param2 == 1028725 ) // ACTOR3 = KUIHLUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KUIHLUD
        }
        if( param1 == 1028721 || param2 == 1028721 ) // ACTOR0 = EXCITEDTOWNSMAN03249
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=EXCITEDTOWNSMAN03249
        }
        if( param1 == 1028722 || param2 == 1028722 ) // ACTOR1 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( param1 == 2009763 || param2 == 2009763 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(CutScene), id=unknown
            // +Callback Scene00009: Normal(FadeIn), id=unknown
          }
        }
        if( param1 == 1028723 || param2 == 1028723 ) // ACTOR2 = RANAAMIHGO
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=RANAAMIHGO
        }
        if( param1 == 1028725 || param2 == 1028725 ) // ACTOR3 = KUIHLUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=KUIHLUD
        }
        break;
      }
      case 255:
      {
        if( param1 == 1028724 || param2 == 1028724 ) // ACTOR4 = NASHMEIRA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, YesNo, QuestReward, QuestComplete, TargetCanMove), id=NASHMEIRA
        }
        if( param1 == 1028728 || param2 == 1028728 ) // ACTOR5 = RANAAMIHGO
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=RANAAMIHGO
        }
        if( param1 == 1028725 || param2 == 1028725 ) // ACTOR3 = KUIHLUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=KUIHLUD
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
    player.sendDebug( "LucKbb201:68785 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKbb201:68785 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EXCITEDTOWNSMAN03249" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00002: Normal(None), id=unknown" );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00003: Normal(Talk, TargetCanMove), id=RANAAMIHGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00004: Normal(Talk, TargetCanMove), id=KUIHLUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00005: Normal(Talk, TargetCanMove), id=EXCITEDTOWNSMAN03249" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00008: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling [BranchTrue]Scene00009: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00010: Normal(Talk, TargetCanMove), id=RANAAMIHGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00011: Normal(Talk, TargetCanMove), id=KUIHLUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00012: Normal(Talk, YesNo, QuestReward, QuestComplete, TargetCanMove), id=NASHMEIRA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00013: Normal(Talk, TargetCanMove), id=RANAAMIHGO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKbb201:68785 calling Scene00014: Normal(Talk, TargetCanMove), id=KUIHLUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKbb201 );
