// FFXIVTheMovie.ParserV3.2
// id hint used:
//ACTOR5 = CIRINA_3
//ACTOR6 = CIRINA_2
//ACTOR7 = LYSE
//ACTOR10 = dead1
//ACTOR11 = dead2
//ACTOR12 = dead3
//SCENE_7 = CIRINA_3
//SCENE_8 = CIRINA_2
//SCENE_18 = CIRINA_2
//SCENE_24 = CIRINA_2
//SCENE_34 = CIRINA_2
//SCENE_41 = CIRINA_2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda407 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda407() : Sapphire::ScriptAPI::EventScript( 68042 ){}; 
  ~StmBda407() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 5 entries
  //SEQ_4, 7 entries
  //SEQ_5, 8 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1020544
  //ACTOR1 = 1020501
  //ACTOR10 = 1020675
  //ACTOR11 = 1020676
  //ACTOR12 = 1020677
  //ACTOR13 = 1020673
  //ACTOR14 = 1020679
  //ACTOR15 = 1020680
  //ACTOR16 = 1020681
  //ACTOR2 = 1020545
  //ACTOR3 = 1020546
  //ACTOR4 = 1020670
  //ACTOR5 = 1020669
  //ACTOR6 = 1020539
  //ACTOR7 = 1020671
  //ACTOR8 = 1020672
  //ACTOR9 = 1020674
  //BINDGOSETSU1 = 6851401
  //BINDLISE1 = 6851397
  //ENEMY0 = 6873408
  //ENEMY1 = 6873409
  //ENEMY2 = 6873410
  //ENEMY3 = 6873412
  //ENEMY4 = 6873414
  //ENEMY5 = 6873415
  //EOBJECT0 = 2008929
  //EOBJECT1 = 2008930
  //EVENTACTION0 = 56
  //EVENTACTION1 = 1
  //LOCCIRINA = 6851868
  //LOCGOSETSU = 6862759
  //LOCGOSETSU003 = 6862759
  //LOCLISE = 6862760
  //LOCLISE003 = 6862760

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020544 || param2 == 1020544 ) // ACTOR0 = HIEN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR1 = CIRINA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020545 || param2 == 1020545 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020546 || param2 == 1020546 ) // ACTOR3 = GOSETSU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1020670 || param2 == 1020670 ) // ACTOR4 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR1 = CIRINA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020669 || param2 == 1020669 ) // ACTOR5 = CIRINA_3
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CIRINA_3
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR6 = CIRINA_2
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=CIRINA_2
          break;
        }
        if( param1 == 1020671 || param2 == 1020671 ) // ACTOR7 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE
          }
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2008929 || param2 == 2008929 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 6873408 || param2 == 6873408 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 6873409 || param2 == 6873409 ) // ENEMY1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6873410 || param2 == 6873410 ) // ENEMY2 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00017: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR6 = CIRINA_2
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CIRINA_2
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1020672 || param2 == 1020672 ) // ACTOR8 = LYSE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020674 || param2 == 1020674 ) // ACTOR9 = GOSETSU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020675 || param2 == 1020675 ) // ACTOR10 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020676 || param2 == 1020676 ) // ACTOR11 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020677 || param2 == 1020677 ) // ACTOR12 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR6 = CIRINA_2
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=CIRINA_2
          break;
        }
        if( param1 == 1020673 || param2 == 1020673 ) // ACTOR13 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 2008930 || param2 == 2008930 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00027( player ); // Scene00027: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 6873412 || param2 == 6873412 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 6873414 || param2 == 6873414 ) // ENEMY4 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6873415 || param2 == 6873415 ) // ENEMY5 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00033: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR6 = CIRINA_2
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=CIRINA_2
          break;
        }
        if( param1 == 1020675 || param2 == 1020675 ) // ACTOR10 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020676 || param2 == 1020676 ) // ACTOR11 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020677 || param2 == 1020677 ) // ACTOR12 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020679 || param2 == 1020679 ) // ACTOR14 = HIEN
        {
          Scene00038( player ); // Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020680 || param2 == 1020680 ) // ACTOR15 = LYSE
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020681 || param2 == 1020681 ) // ACTOR16 = GOSETSU
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020539 || param2 == 1020539 ) // ACTOR6 = CIRINA_2
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=CIRINA_2
          break;
        }
        if( param1 == 1020677 || param2 == 1020677 ) // ACTOR12 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020676 || param2 == 1020676 ) // ACTOR11 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          break;
        }
        if( param1 == 1020675 || param2 == 1020675 ) // ACTOR10 = unknown
        {
          Scene00044( player ); // Scene00044: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 3 )
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
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda407:68042 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00002: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00006: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00007: Normal(Talk, TargetCanMove), id=CIRINA_3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00008: Normal(Talk, TargetCanMove), id=CIRINA_2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00017: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00018: Normal(Talk, TargetCanMove), id=CIRINA_2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00019: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00020: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00024: Normal(Talk, TargetCanMove), id=CIRINA_2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00025: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00027: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00029: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00031: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00033( player );
    };
    player.playScene( getId(), 31, NONE, callback );
  }
  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00033: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00034: Normal(Talk, TargetCanMove), id=CIRINA_2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00038: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
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
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00039: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00040: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00041: Normal(Talk, TargetCanMove), id=CIRINA_2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda407:68042 calling Scene00044: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( StmBda407 );
