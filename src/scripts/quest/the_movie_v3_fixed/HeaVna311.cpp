// FFXIVTheMovie.ParserV3.6
// param used:
//SCENE_4 = SEQ_1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna311 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna311() : Sapphire::ScriptAPI::EventScript( 67148 ){}; 
  ~HeaVna311() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1012628
  //ACTOR1 = 1012626
  //ACTOR2 = 1012627
  //ACTOR3 = 1011916
  //ACTOR4 = 1012629
  //ACTOR5 = 1012630
  //ACTOR6 = 1012631
  //ENEMY0 = 4467
  //ITEM0 = 2001580
  //LOCACTOR0 = 5856601
  //LOCACTOR1 = 5856602
  //LOCACTOR10 = 1011887
  //LOCACTOR11 = 1012443
  //LOCACTOR12 = 1012456
  //LOCACTOR13 = 1012457

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012628 || param2 == 1012628 ) // ACTOR0 = ICEHEART
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ICEHEART
          }
          break;
        }
        if( param1 == 1012626 || param2 == 1012626 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012627 || param2 == 1012627 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=SEQ_1
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 3
      case 2:
      {
        if( param1 == 4467 || param2 == 4467 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
            checkProgressSeq2( player );
          }
          break;
        }
        if( param1 == 1011916 || param2 == 1011916 ) // ACTOR3 = MARCECHAMP
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MARCECHAMP
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 3
      case 255:
      {
        if( param1 == 1012629 || param2 == 1012629 ) // ACTOR4 = unknown
        {
          Scene00006( player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00007: Normal(QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1012630 || param2 == 1012630 ) // ACTOR5 = ESTINIEN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012631 || param2 == 1012631 ) // ACTOR6 = ICEHEART
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ICEHEART
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
    player.sendDebug( "emote: {}", emoteId );
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
    /*
    player.updateQuest( getId(), 2 );
    */
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 3 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 3 )
    {
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 3 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, ENpcBind), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=SEQ_1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }


  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00005: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00007: Normal(QuestReward, QuestComplete), id=unknown" );
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

  void Scene00008( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00008: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna311:67148 calling Scene00009: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna311 );
