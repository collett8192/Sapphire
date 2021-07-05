// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmg102 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmg102() : Sapphire::ScriptAPI::EventScript( 69210 ){}; 
  ~LucKmg102() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 4 entries
  //SEQ_3, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1032121
  //ACTOR1 = 1029566
  //ACTOR10 = 1032451
  //ACTOR2 = 1029567
  //ACTOR3 = 1032218
  //ACTOR4 = 1032219
  //ACTOR5 = 1031726
  //ACTOR6 = 1031727
  //ACTOR7 = 1031728
  //ACTOR8 = 1031729
  //ACTOR9 = 5010000
  //CUTSCENE0 = 2187
  //INSTANCEDUNGEON0 = 73
  //LOCACTORALISAIE = 1026567
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORMYSTERYVOICE = 1028166
  //LOCACTORYSHTOLA = 1026571
  //LOCBINDACTOR0 = 8153168
  //LOCBINDACTOR1 = 8153169
  //LOCBINDACTOR2 = 8153170
  //LOCBINDACTOR3 = 8153171
  //LOCBINDACTOR4 = 8132063
  //LOCBINDACTOR5 = 8132064
  //LOCBINDACTOR6 = 8132065
  //POPRANGE0 = 8136667
  //QSTCHK00 = 68784
  //SCREENIMAGE0 = 834
  //TERRITORYTYPE0 = 813

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1032121 || param2 == 1032121 ) // ACTOR0 = MYSTERYVOICE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029566 || param2 == 1029566 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1029567 || param2 == 1029567 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1032218 || param2 == 1032218 ) // ACTOR3 = URIANGER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1032219 || param2 == 1032219 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1031726 || param2 == 1031726 ) // ACTOR5 = MYSTERYVOICE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=MYSTERYVOICE
          }
          break;
        }
        if( param1 == 1031727 || param2 == 1031727 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031728 || param2 == 1031728 ) // ACTOR7 = ALISAIE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1031729 || param2 == 1031729 ) // ACTOR8 = YSHTOLA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1032218 || param2 == 1032218 ) // ACTOR3 = URIANGER
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1031726 || param2 == 1031726 ) // ACTOR5 = MYSTERYVOICE
        {
          Scene00011( player ); // Scene00011: MsqDungeon(Talk, TargetCanMove, Menu), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1031727 || param2 == 1031727 ) // ACTOR6 = ALPHINAUD
        {
          Scene00012( player ); // Scene00012: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD
          break;
        }
        if( param1 == 1031728 || param2 == 1031728 ) // ACTOR7 = ALISAIE
        {
          Scene00013( player ); // Scene00013: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE
          break;
        }
        if( param1 == 1031729 || param2 == 1031729 ) // ACTOR8 = YSHTOLA
        {
          Scene00014( player ); // Scene00014: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA
          break;
        }
        break;
      }
      case 3:
      {
        Scene00015( player ); // Scene00015: Normal(CutScene), id=unknown
        break;
      }
      case 255:
      {
        Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=ALPHINAUD
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmg102:69210 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00004: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00008: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00010: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00011: MsqDungeon(Talk, TargetCanMove, Menu), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00015( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00012: MsqDungeon(Talk, TargetCanMove, Menu), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00015( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00013: MsqDungeon(Talk, TargetCanMove, Menu), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00015( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00014: MsqDungeon(Talk, TargetCanMove, Menu), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 768 ) // cancel
      {
        //dungeon auto skip
        Scene00015( player );
      }
      else
      {
        player.sendUrgent( "Select anyone and hit cancel to progress." );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00015: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmg102:69210 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=ALPHINAUD" );
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
    player.playScene( getId(), 16, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmg102 );
