// FFXIVTheMovie.ParserV3
//fix: add code to enter instance
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse117 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse117() : Sapphire::ScriptAPI::EventScript( 66727 ){}; 
  ~GaiUse117() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1006751
  //ACTOR1 = 1003027
  //ACTOR2 = 1008274
  //ACTOR3 = 1008272
  //ACTOR4 = 1008273
  //ACTOR5 = 1000460
  //ACTOR6 = 1006693
  //EVENTACTIONSEARCH = 1
  //LOCACTION0 = 787
  //LOCACTOR01 = 1005013
  //LOCACTOR02 = 1005014
  //LOCACTOR03 = 1003069
  //LOCACTOR11 = 1004396
  //LOCACTOR12 = 1004397
  //LOCACTOR13 = 1004398
  //LOCACTOR14 = 1004399
  //LOCACTOR15 = 1004400
  //LOCPOSITION01 = 4491673
  //LOCPOSITION02 = 4491674
  //LOCPOSITION03 = 4491675
  //LOCPOSITION11 = 4065819
  //LOCPOSITION12 = 4065820
  //LOCPOSITION13 = 4065821
  //LOCPOSITION14 = 4065822
  //LOCPOSITION15 = 4065823
  //MOTEVENTJOYBIG = 945
  //POPRANGE0 = 3877982
  //PUBACTORL = 4307833
  //PUBACTORR = 4307834
  //TERRITORYTYPE0 = 205

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAYAOSENNA
        break;
      }
      case 1:
      {
        if( actor == 1003027 || actorId == 1003027 ) // ACTOR1 = KANESENNA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=KANESENNA
          }
        }
        if( actor == 1008274 || actorId == 1008274 ) // ACTOR2 = KUPLOKOPP
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=KUPLOKOPP
        }
        if( actor == 1008272 || actorId == 1008272 ) // ACTOR3 = YDA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1008273 || actorId == 1008273 ) // ACTOR4 = PAPALYMO
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1000460 || actorId == 1000460 ) // ACTOR5 = DOORMANLOTUS
        {
          Scene00006( player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove), id=DOORMANLOTUS
        }
        if( actor == 1006751 || actorId == 1006751 ) // ACTOR0 = RAYAOSENNA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RAYAOSENNA
        }
        break;
      }
      case 255:
      {
        if( actor == 1006693 || actorId == 1006693 ) // ACTOR6 = MINFILIA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA
        }
        if( actor == 1003027 || actorId == 1003027 ) // ACTOR1 = KANESENNA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=KANESENNA
        }
        if( actor == 1008274 || actorId == 1008274 ) // ACTOR2 = KUPLOKOPP
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=KUPLOKOPP
        }
        if( actor == 1008272 || actorId == 1008272 ) // ACTOR3 = YDA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1008273 || actorId == 1008273 ) // ACTOR4 = PAPALYMO
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1000460 || actorId == 1000460 ) // ACTOR5 = DOORMANLOTUS
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=DOORMANLOTUS
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
    onProgress( player, 1, 1, 3, param1 );
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
    player.sendDebug( "GaiUse117:66727 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse117:66727 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=RAYAOSENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00003: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00004: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00005: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00006: Normal(Talk, YesNo, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 205 );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00007: Normal(Talk, TargetCanMove), id=RAYAOSENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00008: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00009: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00010: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00011: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00012: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse117:66727 calling Scene00013: Normal(Talk, TargetCanMove), id=DOORMANLOTUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse117 );
