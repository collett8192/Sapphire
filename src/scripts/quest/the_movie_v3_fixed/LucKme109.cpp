// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme109 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme109() : Sapphire::ScriptAPI::EventScript( 69174 ){}; 
  ~LucKme109() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1027296
  //ACTOR1 = 1030230
  //ACTOR2 = 1030239
  //ACTOR3 = 1030233
  //ACTOR4 = 1030234
  //BINDACTOR01 = 7935118
  //EOBJECT0 = 2010096
  //LOCACTION01 = 5625
  //LOCACTOR01 = 1029406
  //QUESTBATTLE0 = 192
  //TERRITORYTYPE0 = 864

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1027296 || param2 == 1027296 ) // ACTOR0 = XAMOTT
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=XAMOTT
          break;
        }
        if( param1 == 1030230 || param2 == 1030230 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030239 || param2 == 1030239 ) // ACTOR2 = KORUTT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, QuestBattle, YesNo, TargetCanMove, CanCancel), id=KORUTT
          }
          break;
        }
        if( param1 == 2010096 || param2 == 2010096 ) // EOBJECT0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1027296 || param2 == 1027296 ) // ACTOR0 = XAMOTT
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=XAMOTT
          break;
        }
        if( param1 == 1030230 || param2 == 1030230 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030233 || param2 == 1030233 ) // ACTOR3 = KORUTT
        {
          Scene00007( player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KORUTT
          break;
        }
        if( param1 == 1030234 || param2 == 1030234 ) // ACTOR4 = MYSTERYVOICE
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme109:69174 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme109:69174 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=XAMOTT" );
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
    player.sendDebug( "LucKme109:69174 calling Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme109:69174 calling Scene00003: Normal(Talk, QuestBattle, YesNo, TargetCanMove, CanCancel), id=KORUTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 814, 348, 314.44, -375.7, 1, false );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme109:69174 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme109:69174 calling Scene00005: Normal(Talk, TargetCanMove), id=XAMOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme109:69174 calling Scene00006: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme109:69174 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KORUTT" );
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
    player.sendDebug( "LucKme109:69174 calling Scene00008: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKme109 );
