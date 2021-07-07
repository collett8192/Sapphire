// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKba201 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKba201() : Sapphire::ScriptAPI::EventScript( 68803 ){}; 
  ~LucKba201() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1029998
  //ACTOR1 = 1029999
  //ACTOR2 = 1030001
  //ACTOR3 = 1030000
  //ACTOR4 = 1031158
  //ENEMY0 = 7935099
  //EOBJECT0 = 2009998
  //EVENTACTION0 = 1
  //EVENTACTION1 = 73
  //EVENTRANGE0 = 7935103
  //LOCACTOR0 = 1030002
  //LOCACTOR1 = 1030003
  //LOCDWARFMET = 26316
  //LOCMOTION0 = 5625
  //LOCMOTION1 = 845
  //LOCMOTION2 = 5671
  //LOCMOTIONASTROLOGIAN0 = 5689
  //LOCMOTIONASTROLOGIAN1 = 5690
  //LOCMOTIONSCHOLAR0 = 5686
  //LOCMOTIONSCHOLAR1 = 5687
  //LOCMOTIONWHITE0 = 5683
  //LOCMOTIONWHITE1 = 5684
  //LOCSE0 = 71
  //LOCSE1 = 80
  //LOCVFXASTROLOGIAN0 = 761
  //LOCVFXSCHOLAR0 = 763
  //LOCVFXWHITE0 = 762
  //QSTPIC0 = 821

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=GIOTT
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=GIOTT
        break;
      }
      case 2:
      {
        if( param1 == 7935103 || param2 == 7935103 ) // EVENTRANGE0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(Message), id=unknown
          break;
        }
        if( param1 == 7935099 || param2 == 7935099 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq2( player );
          }
          break;
        }
        if( param1 == 1030001 || param2 == 1030001 ) // ACTOR2 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009998 || param2 == 2009998 ) // EOBJECT0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030000 || param2 == 1030000 ) // ACTOR3 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        Scene00010( player ); // Scene00009: Normal(None), id=unknown
        break;
      }
      case 255:
      {
        Scene00011( player );
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
    player.updateQuest( getId(), 2 );
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKba201:68803 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKba201:68803 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=GIOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKba201:68803 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=GIOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKba201:68803 calling Scene00003: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }


  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKba201:68803 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKba201:68803 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKba201:68803 calling Scene00008: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKba201:68803 calling Scene00009: Normal(None), id=unknown" );

  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKba201:68803 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove, CanCancel), id=GIOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKba201:68803 calling Scene00011: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=GIOTT" );
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
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( LucKba201 );