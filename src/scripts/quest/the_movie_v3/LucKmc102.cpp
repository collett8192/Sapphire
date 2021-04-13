// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc102 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc102() : Sapphire::ScriptAPI::EventScript( 68859 ){}; 
  ~LucKmc102() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1029167
  //ACTOR1 = 1029168
  //ACTOR10 = 1028975
  //ACTOR11 = 1028979
  //ACTOR2 = 1029169
  //ACTOR3 = 1029170
  //ACTOR4 = 1029171
  //ACTOR5 = 1029172
  //ACTOR6 = 1029174
  //ACTOR7 = 1029175
  //ACTOR8 = 1029173
  //ACTOR9 = 1030889
  //EOBJECT0 = 2009861
  //EOBJECT1 = 2010512
  //EVENTACTION0 = 50
  //LOCACTORMINFILIA = 1026572
  //LOCACTORTHANCRED = 1026569
  //LOCACTORURIANGER = 1026570
  //LOCBINDACTOR0 = 7926515
  //LOCBINDACTOR1 = 7926516
  //LOCEOBJLITHOGRAPH = 2010654
  //SNP0 = 28

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029167 || param2 == 1029167 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029168 || param2 == 1029168 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029169 || param2 == 1029169 ) // ACTOR2 = RYNE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009861 || param2 == 2009861 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029170 || param2 == 1029170 ) // ACTOR3 = URIANGER
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029171 || param2 == 1029171 ) // ACTOR4 = THANCRED
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029172 || param2 == 1029172 ) // ACTOR5 = RYNE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2010512 || param2 == 2010512 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(SystemTalk), id=unknown
            // +Callback Scene00010: Snipe(AutoFadeIn, CanCancel), id=unknown
            // +Callback Scene00011: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1029174 || param2 == 1029174 ) // ACTOR6 = THANCRED
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029175 || param2 == 1029175 ) // ACTOR7 = RYNE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029173 || param2 == 1029173 ) // ACTOR8 = URIANGER
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030889 || param2 == 1030889 ) // ACTOR9 = URIANGER
        {
          Scene00015( player ); // Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1028975 || param2 == 1028975 ) // ACTOR10 = THANCRED
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1028979 || param2 == 1028979 ) // ACTOR11 = RYNE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=RYNE
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
    player.sendDebug( "LucKmc102:68859 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc102:68859 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00003: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00005: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00006: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00007: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00008: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00009: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00010: Snipe(AutoFadeIn, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, INVIS_ENPC, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00011: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00012: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00013: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00014: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URIANGER" );
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
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00016: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmc102:68859 calling Scene00017: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc102 );
