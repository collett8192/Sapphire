// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc116 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc116() : Sapphire::ScriptAPI::EventScript( 68873 ){}; 
  ~LucKmc116() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 1 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1029242
  //ACTOR1 = 1029243
  //ACTOR2 = 1029244
  //ACTOR3 = 1029245
  //ACTOR4 = 1029246
  //ACTOR5 = 1029247
  //ACTOR6 = 1029248
  //EOBJECT0 = 2009891
  //LOCBINDACTOR0 = 7927573
  //LOCBINDACTOR1 = 7927587
  //LOCBINDACTOR2 = 7927591
  //LOCBINDACTOR3 = 7927593
  //LOCBINDACTOR4 = 7927594
  //LOCBINDACTOR5 = 7927579
  //NCUTEVENTLUCKMC11601 = 2011
  //POPRANGE0 = 7927583
  //QUESTBATTLE0 = 5032
  //TERRITORYTYPE0 = 859
  //TERRITORYTYPE1 = 817

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029242 || param2 == 1029242 ) // ACTOR0 = ALMET
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029243 || param2 == 1029243 ) // ACTOR1 = YSHTOLA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029243 || param2 == 1029243 ) // ACTOR1 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1029242 || param2 == 1029242 ) // ACTOR0 = ALMET
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 2009891 || param2 == 2009891 ) // EOBJECT0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00006( player ); // Scene00006: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029244 || param2 == 1029244 ) // ACTOR2 = THANCRED
        {
          Scene00007( player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029245 || param2 == 1029245 ) // ACTOR3 = RYNE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029246 || param2 == 1029246 ) // ACTOR4 = URIANGER
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029247 || param2 == 1029247 ) // ACTOR5 = ALMET
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029248 || param2 == 1029248 ) // ACTOR6 = CYMET
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=CYMET
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc116:68873 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00003: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00006( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00004: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 817, 169.75, -19.74, -536.26, 0, false );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
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
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00008: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00009: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00010: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc116:68873 calling Scene00011: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc116 );
