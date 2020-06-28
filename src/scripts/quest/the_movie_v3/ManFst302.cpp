// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class ManFst302 : public Sapphire::ScriptAPI::EventScript
{
public:
  ManFst302() : Sapphire::ScriptAPI::EventScript( 66216 ){}; 
  ~ManFst302() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 12 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1004884
  //ACTOR1 = 1002394
  //ACTOR2 = 1004883
  //ACTOR3 = 1004885
  //ACTOR4 = 1004886
  //ACTOR5 = 1004991
  //ACTOR6 = 1004992
  //ACTOR7 = 1004993
  //ACTOR8 = 1004994
  //EOBJECT0 = 2001713
  //EOBJECT1 = 2001806
  //EVENTRANGE0 = 4126642
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1005104
  //NCUT0 = 217
  //QUESTBATTLE0 = 46
  //TERRITORYTYPE0 = 277

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, YesNo, QuestOffer, QuestAccept, TargetCanMove), id=SERPENTOFFICER
        break;
      }
      case 1:
      {
        if( actor == 1002394 || actorId == 1002394 ) // ACTOR1 = SERPENTPERSONNEL
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, FadeIn, TargetCanMove), id=SERPENTPERSONNEL
          }
        }
        if( actor == 1004883 || actorId == 1004883 ) // ACTOR2 = FLAMEOFFICER
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=FLAMEOFFICER
        }
        if( actor == 1004885 || actorId == 1004885 ) // ACTOR3 = STORMOFFICER
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=STORMOFFICER
        }
        if( actor == 1004884 || actorId == 1004884 ) // ACTOR0 = SERPENTOFFICER
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        break;
      }
      case 2:
      {
        if( actor == 1004886 || actorId == 1004886 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(QuestBattle, YesNo), id=unknown
          }
        }
        if( actor == 4126642 || actorId == 4126642 ) // EVENTRANGE0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(QuestBattle, YesNo), id=unknown
        }
        if( actor == 1004991 || actorId == 1004991 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1004992 || actorId == 1004992 ) // ACTOR6 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1004993 || actorId == 1004993 ) // ACTOR7 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1004994 || actorId == 1004994 ) // ACTOR8 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1004883 || actorId == 1004883 ) // ACTOR2 = FLAMEOFFICER
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=FLAMEOFFICER
        }
        if( actor == 1004884 || actorId == 1004884 ) // ACTOR0 = SERPENTOFFICER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        if( actor == 1004885 || actorId == 1004885 ) // ACTOR3 = STORMOFFICER
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=STORMOFFICER
        }
        if( actor == 1002394 || actorId == 1002394 ) // ACTOR1 = SERPENTPERSONNEL
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=SERPENTPERSONNEL
        }
        if( actor == 2001713 || actorId == 2001713 ) // EOBJECT0 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          // +Callback Scene00016: Normal(None), id=unknown
        }
        if( actor == 2001806 || actorId == 2001806 ) // EOBJECT1 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          // +Callback Scene00018: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1002394 || actorId == 1002394 ) // ACTOR1 = SERPENTPERSONNEL
        {
          Scene00019( player ); // Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SERPENTPERSONNEL
        }
        if( actor == 1004883 || actorId == 1004883 ) // ACTOR2 = FLAMEOFFICER
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=FLAMEOFFICER
        }
        if( actor == 1004884 || actorId == 1004884 ) // ACTOR0 = SERPENTOFFICER
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=SERPENTOFFICER
        }
        if( actor == 1004885 || actorId == 1004885 ) // ACTOR3 = STORMOFFICER
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=STORMOFFICER
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00000: Normal(Talk, YesNo, QuestOffer, QuestAccept, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00001: Normal(Talk, FadeIn, TargetCanMove), id=SERPENTPERSONNEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00002: Normal(Talk, TargetCanMove), id=FLAMEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00003: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00004: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00005: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00006: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00011: Normal(Talk, TargetCanMove), id=FLAMEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00012: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00013: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00014: Normal(Talk, TargetCanMove), id=SERPENTPERSONNEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00015: Normal(None), id=unknown" );
    Scene00016( player );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling [BranchTrue]Scene00016: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00017: Normal(None), id=unknown" );
    Scene00018( player );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling [BranchTrue]Scene00018: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SERPENTPERSONNEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00020: Normal(Talk, TargetCanMove), id=FLAMEOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00021: Normal(Talk, TargetCanMove), id=SERPENTOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "ManFst302:66216 calling Scene00022: Normal(Talk, TargetCanMove), id=STORMOFFICER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( ManFst302 );
