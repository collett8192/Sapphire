// FFXIVTheMovie.ParserV3.2
// id hint used:
//SCENE_6 = card1
//SCENE_7 = card1
//SCENE_8 = card2
//SCENE_9 = card2
//SCENE_10 = card2
//ACTOR4 = actor4
//SCENE_12 = actor4
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma207 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma207() : Sapphire::ScriptAPI::EventScript( 68824 ){}; 
  ~LucKma207() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 1 entries
  //SEQ_3, 1 entries
  //SEQ_4, 1 entries
  //SEQ_5, 4 entries
  //SEQ_6, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1029833
  //ACTOR1 = 1029836
  //ACTOR2 = 1027575
  //ACTOR3 = 1027574
  //ACTOR4 = 5010000
  //ACTOR5 = 1029830
  //ACTOR6 = 1029831
  //BGMGOLDSAUCERTRIPLE = 253
  //BGMTHEMEARMY = 77
  //BINDACTOR01 = 7929633
  //BINDACTOR02 = 7797955
  //CARD01 = 2010490
  //CARD02 = 2010491
  //CARD03 = 2010492
  //CARD04 = 2010493
  //CARD05 = 2010494
  //CARD06 = 2010495
  //CARD07 = 2010496
  //CARD08 = 2010497
  //CARD09 = 2010498
  //EOBJECT0 = 2009968
  //EOBJECT1 = 2009969
  //EVENTRANGE0 = 7929707
  //LOCACTION01 = 752
  //LOCACTION02 = 749
  //LOCACTOR01 = 1026568
  //LOCACTOR02 = 1028119
  //SCREENIMAGEGAMEDRAW = 788
  //SCREENIMAGEGAMELOSE = 787
  //SCREENIMAGEGAMEWIN = 786
  //SEAPPLAUSE = 142

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029833 || param2 == 1029833 ) // ACTOR0 = LADY03287
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LADY03287
          break;
        }
        if( param1 == 1029836 || param2 == 1029836 ) // ACTOR1 = EMPLOYEE03287
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=EMPLOYEE03287
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1027575 || param2 == 1027575 ) // ACTOR2 = TISTABIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TISTABIE
          }
          break;
        }
        if( param1 == 1029833 || param2 == 1029833 ) // ACTOR0 = LADY03287
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LADY03287
          break;
        }
        if( param1 == 1029836 || param2 == 1029836 ) // ACTOR1 = EMPLOYEE03287
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=EMPLOYEE03287
          break;
        }
        break;
      }
      case 2:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove, Menu, SystemTalk, CanCancel), id=card1
        // +Callback Scene00007: CardGame(Talk, YesNo, FadeIn, TargetCanMove, Menu, CanCancel), id=card1
        break;
      }
      case 3:
      {
        Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove, Menu, SystemTalk, CanCancel), id=card2
        // +Callback Scene00009: CardGame(Talk, YesNo, FadeIn, TargetCanMove, Menu, CanCancel), id=card2
        // +Callback Scene00010: Normal(Talk, TargetCanMove), id=card2
        break;
      }
      case 4:
      {
        Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ATHARN
        break;
      }
      case 5:
      {
        if( param1 == 5010000 || param2 == 5010000 ) // ACTOR4 = actor4
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=actor4
          }
          break;
        }
        if( type == 1 && param3 == 11 ) // EOBJECT0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Talk), id=unknown
          break;
        }
        if( param1 == 2009969 || param2 == 2009969 ) // EOBJECT1 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1027574 || param2 == 1027574 ) // ACTOR3 = ATHARN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ATHARN
          break;
        }
        break;
      }
      case 6:
      {
        Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove, SystemTalk), id=ATHARN
        break;
      }
      case 255:
      {
        if( param1 == 1029830 || param2 == 1029830 ) // ACTOR5 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(Talk, FadeIn, QuestReward, QuestComplete), id=unknown
          break;
        }
        if( param1 == 1029831 || param2 == 1029831 ) // ACTOR6 = CHAINUZZ
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=CHAINUZZ
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma207:68824 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LADY03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00002: Normal(Talk, TargetCanMove), id=EMPLOYEE03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00003: Normal(Talk, TargetCanMove), id=TISTABIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00004: Normal(Talk, TargetCanMove), id=LADY03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00005: Normal(Talk, TargetCanMove), id=EMPLOYEE03287" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00006: Normal(Talk, TargetCanMove, Menu, SystemTalk, CanCancel), id=card1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00007: CardGame(Talk, YesNo, FadeIn, TargetCanMove, Menu, CanCancel), id=card1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00008: Normal(Talk, TargetCanMove, Menu, SystemTalk, CanCancel), id=card2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00009: CardGame(Talk, YesNo, FadeIn, TargetCanMove, Menu, CanCancel), id=card2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00010: Normal(Talk, TargetCanMove), id=card2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00011: Normal(Talk, TargetCanMove), id=ATHARN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00012: Normal(None), id=actor4" );
    checkProgressSeq5( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00013: Normal(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00016: Normal(Talk, TargetCanMove), id=ATHARN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00017: Normal(Talk, TargetCanMove, SystemTalk), id=ATHARN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00018: Normal(Talk, FadeIn, QuestReward, QuestComplete), id=unknown" );
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
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKma207:68824 calling Scene00019: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma207 );
