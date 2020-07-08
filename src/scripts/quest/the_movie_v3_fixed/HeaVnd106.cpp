// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_9 = ALPHINAUD
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnd106 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnd106() : Sapphire::ScriptAPI::EventScript( 67783 ){}; 
  ~HeaVnd106() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1012380
  //ACTOR1 = 1016823
  //ACTOR2 = 1016827
  //ACTOR3 = 1013167
  //ACTOR4 = 1012163
  //ACTOR5 = 1016828
  //ACTOR6 = 1012857
  //ACTOR7 = 1012858
  //CUTSCENEN01 = 1182
  //CUTSCENEN02 = 1183
  //CUTSCENEN03 = 1184
  //CUTSCENEN04 = 1185
  //CUTSCENEN05 = 1186
  //CUTSCENEN06 = 1187
  //CUTSCENEN07 = 1188
  //CUTSCENEN08 = 1252
  //LOCACTION0 = 1022
  //LOCACTOR0 = 1015889
  //LOCACTOR1 = 1014558
  //LOCACTOR2 = 1016820
  //LOCACTOR3 = 1017117
  //LOCBGM0 = 313
  //LOCQUEST0 = 66608
  //LOCSE0 = 95
  //POPRANGE0 = 6212250
  //POPRANGE1 = 6388919

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=AYMERIC
        break;
      }
      case 1:
      {
        if( param1 == 1016823 || param2 == 1016823 ) // ACTOR1 = AYMERIC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove), id=AYMERIC
            // +Callback Scene00003: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1016827 || param2 == 1016827 ) // ACTOR2 = TEMPLEKNIGHT02247
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT02247
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR3 = LUCIA
        {
          Scene00005( player ); // Scene00005: Normal(Talk), id=LUCIA
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR4 = HANDELOUP
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        break;
      }
      case 2:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=AYMERIC
        break;
      }
      case 255:
      {
        if( param1 == 1012857 || param2 == 1012857 ) // ACTOR6 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          // +Callback Scene00009: Normal(CutScene), id=ALPHINAUD
        }
        if( param1 == 1012858 || param2 == 1012858 ) // ACTOR7 = TATARU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TATARU
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnd106:67783 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling Scene00002: Normal(Talk, YesNo, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling [BranchTrue]Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 419, 169.5, -14.5, 39.1, -3.1415 );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling Scene00004: Normal(Talk, TargetCanMove), id=TEMPLEKNIGHT02247" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling Scene00005: Normal(Talk), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling Scene00006: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling [BranchTrue]Scene00009: Normal(CutScene), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
        player.eventFinish( getId(), 1 );
        player.exitInstance();
      }
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnd106:67783 calling Scene00010: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnd106 );
