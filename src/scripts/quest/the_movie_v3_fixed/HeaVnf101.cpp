// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_2 = TATARU
//SCENE_4 = dummy0
//won't mention fix point any more if just black screen.
//se really like to use it from 3.0 and the fix is simple adding zoneing code
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnf101 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnf101() : Sapphire::ScriptAPI::EventScript( 67887 ){}; 
  ~HeaVnf101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1017788
  //ACTOR1 = 1013167
  //ACTOR2 = 1018037
  //ACTOR3 = 1018038
  //ACTOR4 = 1009220
  //ACTOR5 = 1006988
  //CUTSCENEN01 = 1297
  //EOBJECT0 = 2007563
  //EVENTACTION0 = 12
  //EVENTACTIONTIMELINEEMOTESALUTE = 725
  //FACIALSPEWING = 617
  //LCUTSE0 = 95
  //LOCACTION0 = 1043
  //LOCACTION1 = 936
  //LOCACTION2 = 4229
  //LOCACTOR0 = 1009751
  //LOCACTOR1 = 1014558
  //LOCACTOR2 = 1012189
  //LOCACTOR3 = 1018387
  //LOCACTOR4 = 1018388
  //LOCACTOR5 = 1018389
  //LOCACTOR6 = 1008178
  //LOCACTOR7 = 1018390
  //LOCBGM0 = 101
  //LOCFACE0 = 607
  //LOCFACE1 = 608
  //LOCFACE3 = 622
  //LOCFACE4 = 614
  //LOCSE1 = 72
  //LOCSE2 = 94
  //LOCSE3 = 90
  //LOCSE4 = 80
  //LOCSE5 = 39
  //POPRANGE0 = 6526732
  //POPRANGE1 = 6728836

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU
        // +Callback Scene00002: Normal(None), id=TATARU
        break;
      }
      case 1:
      {
        if( param1 == 2007563 || param2 == 2007563 ) // EOBJECT0 = dummy0
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(FadeIn), id=unknown
            // +Callback Scene00004: Normal(CutScene), id=dummy0
          }
        }
        if( param1 == 1017788 || param2 == 1017788 ) // ACTOR0 = TATARU
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 255:
      {
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR1 = LUCIA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=LUCIA
          // +Callback Scene00007: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LUCIA
        }
        if( param1 == 1018037 || param2 == 1018037 ) // ACTOR2 = YDA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YDA
        }
        if( param1 == 1018038 || param2 == 1018038 ) // ACTOR3 = PAPALYMO
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( param1 == 1009220 || param2 == 1009220 ) // ACTOR4 = FYRBRYDA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=FYRBRYDA
        }
        if( param1 == 1006988 || param2 == 1006988 ) // ACTOR5 = EGINOLF
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=EGINOLF
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
    player.sendDebug( "HeaVnf101:67887 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnf101:67887 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling [BranchChain]Scene00002: Normal(None), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling Scene00003: Normal(FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling [BranchTrue]Scene00004: Normal(CutScene), id=dummy0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 156, 22.1, 21.3, -634.4, 2.78 );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling Scene00005: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling Scene00006: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling [BranchTrue]Scene00007: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling Scene00008: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling Scene00009: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling Scene00010: Normal(Talk, TargetCanMove), id=FYRBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnf101:67887 calling Scene00011: Normal(Talk, TargetCanMove), id=EGINOLF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnf101 );
