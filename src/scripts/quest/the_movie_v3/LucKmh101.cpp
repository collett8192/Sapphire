// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmh101 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmh101() : Sapphire::ScriptAPI::EventScript( 69297 ){}; 
  ~LucKmh101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1031783
  //ACTOR1 = 1032495
  //ACTOR2 = 1032494
  //ACTOR3 = 1032081
  //ACTOR4 = 1032581
  //LOCACTORALIANNE = 1012478
  //LOCACTORISILDAURE = 1026574
  //LOCACTORKRILE = 1015833
  //LOCACTORMAXIMA = 1026800
  //LOCACTORTATARU = 1012189
  //LOCBINDKRILE = 8259150
  //LOCBINDSOLDIERS = 8250368
  //LOCBINDTATARU = 8147802
  //LOCEVENTBASETABLEELBOW = 822
  //NCUTLUCKMH00010 = 2232

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( param1 == 1032495 || param2 == 1032495 ) // ACTOR1 = MAXIMA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MAXIMA
            // +Callback Scene00003: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1032494 || param2 == 1032494 ) // ACTOR2 = KRILE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1032081 || param2 == 1032081 ) // ACTOR3 = TATARU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=TATARU
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1032494 || param2 == 1032494 ) // ACTOR2 = KRILE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KRILE
          break;
        }
        if( param1 == 1032581 || param2 == 1032581 ) // ACTOR4 = RESISTANCEOFFICER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RESISTANCEOFFICER
          break;
        }
        if( param1 == 1032081 || param2 == 1032081 ) // ACTOR3 = TATARU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TATARU
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
    player.sendDebug( "LucKmh101:69297 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmh101:69297 calling Scene00001: Normal(Talk, FadeIn, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmh101:69297 calling Scene00002: Normal(Talk, TargetCanMove), id=MAXIMA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmh101:69297 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmh101:69297 calling Scene00004: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmh101:69297 calling Scene00005: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmh101:69297 calling Scene00006: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KRILE" );
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
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmh101:69297 calling Scene00007: Normal(Talk, TargetCanMove), id=RESISTANCEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmh101:69297 calling Scene00008: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmh101 );
