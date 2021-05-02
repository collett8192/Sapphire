// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmd109 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmd109() : Sapphire::ScriptAPI::EventScript( 69150 ){}; 
  ~LucKmd109() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 5 entries
  //SEQ_2, 5 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1029643
  //ACTOR1 = 1029635
  //ACTOR2 = 1029639
  //ACTOR3 = 1029645
  //ACTOR4 = 1029761
  //ACTOR5 = 1030569
  //ENEMY0 = 10347
  //EVENTACTION0 = 53
  //ITEM0 = 2002560
  //LOCACTIONCORPSE = 67
  //LOCACTORJERICK = 1028871
  //LOCACTORMINFILIA = 1026572
  //LOCACTORTALOS = 1029421
  //LOCACTORTHANCRED = 1026569
  //LOCACTORURIANGER = 1026570
  //LOCBASEACTIONAETTOUCHLOOP = 170
  //LOCBASEACTIONRACKCHECK = 811
  //LOCBINDACTOR0 = 8051944
  //LOCBINDACTOR1 = 7934886
  //LOCBINDACTOR2 = 8051947

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029643 || param2 == 1029643 ) // ACTOR0 = JERYK
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR1 = MAGNUS
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR2 = THAFFE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029645 || param2 == 1029645 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR1 = MAGNUS
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR2 = THAFFE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029761 || param2 == 1029761 ) // ACTOR4 = URIANGER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030569 || param2 == 1030569 ) // ACTOR5 = JERYK
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 3
      case 2:
      {
        if( param1 == 10347 || param2 == 10347 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
            checkProgressSeq2( player );
          }
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR1 = MAGNUS
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR2 = THAFFE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1029761 || param2 == 1029761 ) // ACTOR4 = URIANGER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030569 || param2 == 1030569 ) // ACTOR5 = JERYK
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( param1 == 1029761 || param2 == 1029761 ) // ACTOR4 = URIANGER
        {
          Scene00014( player ); // Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00015: Normal(Talk, TargetCanMove), id=URIANGER
          // +Callback Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029635 || param2 == 1029635 ) // ACTOR1 = MAGNUS
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1029639 || param2 == 1029639 ) // ACTOR2 = THAFFE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1030569 || param2 == 1030569 ) // ACTOR5 = JERYK
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=JERYK
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
    //if( player.getQuestUI8BH( getId() ) == 3 )
    {
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 3 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmd109:69150 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00002: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00003: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00005: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00006: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00007: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00008: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00009: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }


  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00010: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00011: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00012: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00013: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00015: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=URIANGER" );
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
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00017: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00018: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmd109:69150 calling Scene00019: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmd109 );
