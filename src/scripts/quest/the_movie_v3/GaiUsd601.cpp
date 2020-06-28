// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsd601 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsd601() : Sapphire::ScriptAPI::EventScript( 66030 ){}; 
  ~GaiUsd601() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 1 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1006725
  //ACTOR1 = 1011638
  //ACTOR2 = 1011639
  //ACTOR3 = 1007763
  //ACTOR4 = 1011640
  //ACTOR5 = 5010000
  //ACTOR6 = 1007754
  //ACTOR7 = 1007761
  //ACTOR8 = 1007762
  //BGMEVENTEVACUATION = 161
  //BINDACTOR01 = 4272589
  //EVENTARMS = 1041
  //EVENTSPIRIT = 1071
  //FACIALSMILE = 605
  //FACIALSMILESTRONG = 606
  //FACIALSPEWING = 617
  //INSTANCEDUNGEON0 = 30020
  //LOCACTOR0 = 1005518
  //LOCACTOR1 = 1003855
  //LOCACTOR2 = 1003836
  //LOCACTOR3 = 1003837
  //NCUTEVENTGAIUSD6011 = 760
  //NCUTEVENTGAIUSD6012 = 761
  //NCUTEVENTGAIUSD6013 = 762
  //NCUTEVENTGAIUSD6014 = 763
  //POPRANGE0 = 5649429
  //POPRANGE1 = 4585913
  //TERRITORYTYPE0 = 156
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEONCRYSTALTOWER3 = 271

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=RAMMBROES
        break;
      }
      case 1:
      {
        if( actor == 1011638 || actorId == 1011638 ) // ACTOR1 = WEDGE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=WEDGE
          }
        }
        if( actor == 1011639 || actorId == 1011639 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(CutScene), id=unknown
        }
        if( actor == 1007763 || actorId == 1007763 ) // ACTOR3 = BIGGS
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=BIGGS
        }
        break;
      }
      case 2:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=GRAHATIA
        break;
      }
      case 3:
      {
        if( actor == 1011640 || actorId == 1011640 ) // ACTOR4 = GRAHATIA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, Message, FadeIn, TargetCanMove), id=GRAHATIA
          // +Callback Scene00007: Normal(Talk, TargetCanMove), id=GRAHATIA
        }
        break;
      }
      case 4:
      {
        if( actor == /*UNKNOWN*/1 || actorId == /*UNKNOWN*/1 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00008( player ); // Scene00008: Normal(CutScene), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006725 || actorId == 1006725 ) // ACTOR0 = RAMMBROES
        {
          Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES
        }
        if( actor == 1007754 || actorId == 1007754 ) // ACTOR6 = CID
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1007761 || actorId == 1007761 ) // ACTOR7 = BIGGS
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1007762 || actorId == 1007762 ) // ACTOR8 = WEDGE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=WEDGE
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
    onProgress( player, param1, param1, 3, param1 );
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
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsd601:66030 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00002: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00004: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00005: Normal(Talk, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00006: Normal(Talk, Message, FadeIn, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling [BranchTrue]Scene00007: Normal(Talk, TargetCanMove), id=GRAHATIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00008: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00010: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00011: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsd601:66030 calling Scene00012: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsd601 );
