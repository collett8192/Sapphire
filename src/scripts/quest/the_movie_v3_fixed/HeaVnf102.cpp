// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_3 = dummy0
//SCENE_7 = AYMERIC
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnf102 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnf102() : Sapphire::ScriptAPI::EventScript( 67888 ){}; 
  ~HeaVnf102() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1016008
  //ACTOR1 = 1016075
  //ACTOR2 = 1012163
  //ACTOR3 = 1018013
  //ACTOR4 = 1018014
  //ACTOR5 = 1018015
  //ACTOR6 = 1018016
  //ACTOR7 = 1018035
  //ACTOR8 = 1018036
  //ACTOR9 = 1018219
  //BINDACTOR1 = 6198443
  //BINDACTOR2 = 6449949
  //EOBJECT0 = 2007472
  //EVENTACTION0 = 11
  //EVENTACTIONTIMELINESTOPCALL = 4255
  //LOCACTOR0 = 1009751
  //LOCACTOR1 = 1008193
  //LOCACTOR2 = 1013876
  //LOCACTOR3 = 1019689
  //LOCBGM0 = 320
  //LOCFACIALBOSSY = 607
  //POPRANGE0 = 6528650
  //POPRANGE1 = 6528657

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LUCIA
        break;
      }
      case 1:
      {
        if( param1 == 2007472 || param2 == 2007472 ) // EOBJECT0 = dummy0
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00003: Normal(Talk, FadeIn), id=dummy0
          }
        }
        if( param1 == 1016075 || param2 == 1016075 ) // ACTOR1 = LUCIA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR2 = HANDELOUP
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        break;
      }
      case 2:
      {
        if( param1 == 1018013 || param2 == 1018013 ) // ACTOR3 = AYMERIC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=AYMERIC
            // +Callback Scene00007: Normal(Talk, FadeIn), id=AYMERIC
          }
        }
        if( param1 == 1018014 || param2 == 1018014 ) // ACTOR4 = LUCIA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LUCIA
        }
        break;
      }
      case 255:
      {
        if( param1 == 1018015 || param2 == 1018015 ) // ACTOR5 = AYMERIC
        {
          Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AYMERIC
        }
        if( param1 == 1018016 || param2 == 1018016 ) // ACTOR6 = LUCIA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1018035 || param2 == 1018035 ) // ACTOR7 = EMMANELLAIN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( param1 == 1018036 || param2 == 1018036 ) // ACTOR8 = HONOROIT
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( param1 == 1018219 || param2 == 1018219 ) // ACTOR9 = SERPENTHONORGUARD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=SERPENTHONORGUARD
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
    player.sendDebug( "HeaVnf102:67888 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnf102:67888 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00002: Normal(None), id=unknown" );
    Scene00003( player );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling [BranchTrue]Scene00003: Normal(Talk, FadeIn), id=dummy0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00004: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00005: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00006: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling [BranchTrue]Scene00007: Normal(Talk, FadeIn), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00008: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00010: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00011: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00012: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf102:67888 calling Scene00013: Normal(Talk, TargetCanMove), id=SERPENTHONORGUARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnf102 );
