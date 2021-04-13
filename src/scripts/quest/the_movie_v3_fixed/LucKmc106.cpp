// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc106 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc106() : Sapphire::ScriptAPI::EventScript( 68863 ){}; 
  ~LucKmc106() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_3, 2 entries
  //SEQ_4, 5 entries
  //SEQ_5, 2 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1029197
  //ACTOR1 = 1029201
  //ACTOR2 = 1029202
  //ACTOR3 = 1029203
  //ACTOR4 = 1029205
  //ACTOR5 = 1029206
  //ACTOR6 = 1031262
  //ACTOR7 = 1029207
  //ACTOR8 = 1029208
  //ACTOR9 = 1029209
  //ENEMY0 = 8005177
  //EOBJECT0 = 2009866
  //EOBJECT1 = 2009870
  //EOBJECT2 = 2009869
  //EOBJECT3 = 2009867
  //EOBJECT4 = 2009868
  //EVENTACTION0 = 50
  //EVENTACTION1 = 22
  //EVENTACTION2 = 21
  //EVENTRANGE0 = 7944200
  //ITEM0 = 2002545
  //LOCACTION0 = 6253
  //LOCACTION1 = 5665
  //LOCACTION2 = 4280
  //LOCACTION3 = 1048
  //LOCACTION4 = 4322
  //LOCACTION5 = 4323
  //LOCACTORMANOFNIGHT = 1029466
  //LOCACTORMINFILIA = 1026572
  //LOCACTORMINFILIAPAP = 1029346
  //LOCACTORRUNAR = 1028142
  //LOCACTORTUMIKUI = 1029402
  //LOCBGMMUSICEX3PATHOS01 = 649
  //LOCBINDACTOR0 = 7927393
  //LOCBINDACTOR1 = 7927392

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029197 || param2 == 1029197 ) // ACTOR0 = RUNAR
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=RUNAR
          break;
        }
        if( param1 == 1029201 || param2 == 1029201 ) // ACTOR1 = RYNE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 2009866 || param2 == 2009866 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, Menu), id=unknown
          }
          break;
        }
        if( param1 == 1029202 || param2 == 1029202 ) // ACTOR2 = RYNE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029203 || param2 == 1029203 ) // ACTOR3 = MANOFNIGHT03326
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MANOFNIGHT03326
          break;
        }
        if( param1 == 1029197 || param2 == 1029197 ) // ACTOR0 = RUNAR
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RUNAR
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 7944200 || param2 == 7944200 ) // EVENTRANGE0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message), id=unknown
          break;
        }
        if( param1 == 8005177 || param2 == 8005177 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq2( player );
          }
          break;
        }
        if( param1 == 2009870 || param2 == 2009870 ) // EOBJECT1 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1029205 || param2 == 1029205 ) // ACTOR4 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1029206 || param2 == 1029206 ) // ACTOR5 = RYNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=RYNE
          }
          break;
        }
        if( param1 == 1031262 || param2 == 1031262 ) // ACTOR6 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 2009869 || param2 == 2009869 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009867 || param2 == 2009867 ) // EOBJECT3 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2009868 || param2 == 2009868 ) // EOBJECT4 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 1029207 || param2 == 1029207 ) // ACTOR7 = RYNE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1031262 || param2 == 1031262 ) // ACTOR6 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 1
      case 5:
      {
        if( param1 == 1029207 || param2 == 1029207 ) // ACTOR7 = RYNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=RYNE
          }
          break;
        }
        if( param1 == 1031262 || param2 == 1031262 ) // ACTOR6 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1029197 || param2 == 1029197 ) // ACTOR0 = RUNAR
        {
          Scene00025( player ); // Scene00025: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1029208 || param2 == 1029208 ) // ACTOR8 = THANCRED
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029209 || param2 == 1029209 ) // ACTOR9 = RYNE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1031262 || param2 == 1031262 ) // ACTOR6 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
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
      player.setQuestUI8BH( getId(), 1 );
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
    player.sendDebug( "LucKmc106:68863 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc106:68863 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=RUNAR" );
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
    player.sendDebug( "LucKmc106:68863 calling Scene00002: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00004: Normal(Talk, FadeIn, Menu), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00005: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00006: Normal(Talk, TargetCanMove), id=MANOFNIGHT03326" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00007: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00008: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.getQuestUI8AL( getId() ) != 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }


  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00015: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00017: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00019: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00020: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00022: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00023( player );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00023: Normal(Talk, NpcDespawn, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00025: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00026( player );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RUNAR" );
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
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00027: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00028: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmc106:68863 calling Scene00029: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKmc106 );
