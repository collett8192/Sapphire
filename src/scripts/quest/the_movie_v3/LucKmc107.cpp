// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc107 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc107() : Sapphire::ScriptAPI::EventScript( 68864 ){}; 
  ~LucKmc107() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 4 entries
  //SEQ_4, 5 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1029197
  //ACTOR1 = 1029208
  //ACTOR2 = 1029209
  //ACTOR3 = 1028989
  //ACTOR4 = 1029194
  //ACTOR5 = 1029195
  //ACTOR6 = 1029196
  //ACTOR7 = 1029211
  //EOBJECT0 = 2009871
  //EOBJECT1 = 2009872
  //EVENTACTION0 = 12
  //EVENTACTION1 = 1
  //ITEM0 = 2002546
  //LOCACTION0 = 5533
  //LOCBINDACTOR0 = 7927393
  //LOCBINDACTOR1 = 7927392
  //LOCBINDACTOR2 = 7926659
  //LOCBINDACTOR3 = 7926662
  //LOCBINDACTOR4 = 7927402
  //NCUTEVENTLUCKMC10701 = 2005

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
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=RUNAR
          break;
        }
        if( param1 == 1029208 || param2 == 1029208 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029209 || param2 == 1029209 ) // ACTOR2 = RYNE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029209 || param2 == 1029209 ) // ACTOR2 = RYNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RYNE
          }
          break;
        }
        if( param1 == 1029208 || param2 == 1029208 ) // ACTOR1 = THANCRED
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 1028989 || param2 == 1028989 ) // ACTOR3 = OLDWOMAN03325
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove, SystemTalk), id=OLDWOMAN03325
          }
          break;
        }
        if( param1 == 1029208 || param2 == 1029208 ) // ACTOR1 = THANCRED
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029209 || param2 == 1029209 ) // ACTOR2 = RYNE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 2009871 || param2 == 2009871 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Inventory), id=unknown
          }
          break;
        }
        if( param1 == 1028989 || param2 == 1028989 ) // ACTOR3 = OLDWOMAN03325
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=OLDWOMAN03325
          break;
        }
        if( param1 == 1029208 || param2 == 1029208 ) // ACTOR1 = THANCRED
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029209 || param2 == 1029209 ) // ACTOR2 = RYNE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2009872 || param2 == 2009872 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1028989 || param2 == 1028989 ) // ACTOR3 = OLDWOMAN03325
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=OLDWOMAN03325
          break;
        }
        if( param1 == 1029208 || param2 == 1029208 ) // ACTOR1 = THANCRED
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029209 || param2 == 1029209 ) // ACTOR2 = RYNE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 2009871 || param2 == 2009871 ) // EOBJECT0 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029194 || param2 == 1029194 ) // ACTOR4 = YSHTOLA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029195 || param2 == 1029195 ) // ACTOR5 = URIANGER
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029196 || param2 == 1029196 ) // ACTOR6 = RYNE
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029211 || param2 == 1029211 ) // ACTOR7 = THANCRED
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029197 || param2 == 1029197 ) // ACTOR0 = RUNAR
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=RUNAR
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc107:68864 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00003: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00004: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00006: Normal(Talk, TargetCanMove, SystemTalk), id=OLDWOMAN03325" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00007: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00008: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00009: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00011: Normal(Talk, TargetCanMove), id=OLDWOMAN03325" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00012: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00013: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00015: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00016: Normal(Talk, TargetCanMove), id=OLDWOMAN03325" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00017: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00018: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YSHTOLA" );
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
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00022: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00023: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00024: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmc107:68864 calling Scene00025: Normal(Talk, TargetCanMove), id=RUNAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc107 );
