// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil129 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil129() : Sapphire::ScriptAPI::EventScript( 66110 ){}; 
  ~SubWil129() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1003929
  //ACTOR1 = 1003947
  //ACTOR2 = 1004325
  //ACTOR3 = 1004327
  //ACTOR4 = 1004506
  //ACTOR5 = 1004556
  //ACTOR6 = 1004324
  //ACTOR7 = 1004330
  //ACTOR8 = 1005116
  //LOCACTOR0 = 1005015
  //LOCACTOR1 = 1004580
  //LOCACTOR2 = 1004581
  //LOCACTOR3 = 1003932
  //LOCFACE0 = 604
  //LOCFACE1 = 617
  //LOCFACE2 = 605
  //LOCPOSACTOR1 = 3967322
  //RITEM0 = 2995
  //RITEM1 = 3306
  //SEQ0ACTOR0LQ = 90

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ISEMBARD
        break;
      }
      case 1:
      {
        if( param1 == 1003947 || param2 == 1003947 ) // ACTOR1 = KNERL
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KNERL
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=KNERL
            // +Callback Scene00004: Normal(Talk, TargetCanMove), id=KNERL
          }
          break;
        }
        if( param1 == 1004325 || param2 == 1004325 ) // ACTOR2 = SWAENHYLT
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SWAENHYLT
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=SWAENHYLT
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=SWAENHYLT
          }
          break;
        }
        if( param1 == 1004327 || param2 == 1004327 ) // ACTOR3 = AURILDIS
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=AURILDIS
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=AURILDIS
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=AURILDIS
          }
          break;
        }
        if( param1 == 1004506 || param2 == 1004506 ) // ACTOR4 = ERMEGARDE
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ERMEGARDE
            // +Callback Scene00012: Normal(Talk, TargetCanMove), id=ERMEGARDE
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=ERMEGARDE
          }
          break;
        }
        if( param1 == 1004556 || param2 == 1004556 ) // ACTOR5 = ADELSTAN
        {
          if( player.getQuestUI8AL( getId() ) != 5 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ADELSTAN
            // +Callback Scene00015: Normal(Talk, TargetCanMove), id=ADELSTAN
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=ADELSTAN
          }
          break;
        }
        if( param1 == 1004324 || param2 == 1004324 ) // ACTOR6 = THANCRED
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1003929 || param2 == 1003929 ) // ACTOR0 = ISEMBARD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ISEMBARD
          break;
        }
        break;
      }
      case 2:
      {
        if( type != 2 ) Scene00019( player ); // Scene00019: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED
        break;
      }
      case 3:
      {
        if( param1 == 1004330 || param2 == 1004330 ) // ACTOR7 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=THANCRED
            // +Callback Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=THANCRED
            // +Callback Scene00022: Normal(Talk, TargetCanMove), id=THANCRED
          }
          break;
        }
        if( param1 == 1003929 || param2 == 1003929 ) // ACTOR0 = ISEMBARD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ISEMBARD
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00024( player ); // Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 5 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.setQuestBitFlag8( getId(), 4, false );
      player.setQuestBitFlag8( getId(), 5, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil129:66110 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil129:66110 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 5, Flag8(1)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00002: Normal(Talk, TargetCanMove), id=KNERL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 5, Flag8(1)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00003: Normal(Talk, TargetCanMove), id=KNERL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 5, Flag8(1)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00004: Normal(Talk, TargetCanMove), id=KNERL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 5, Flag8(2)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00005: Normal(Talk, TargetCanMove), id=SWAENHYLT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 5, Flag8(2)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00006: Normal(Talk, TargetCanMove), id=SWAENHYLT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR2, UI8AL = 5, Flag8(2)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00007: Normal(Talk, TargetCanMove), id=SWAENHYLT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 5, Flag8(3)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00008: Normal(Talk, TargetCanMove), id=AURILDIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 5, Flag8(3)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00009: Normal(Talk, TargetCanMove), id=AURILDIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 5, Flag8(3)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00010: Normal(Talk, TargetCanMove), id=AURILDIS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 5, Flag8(4)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00011: Normal(Talk, TargetCanMove), id=ERMEGARDE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 5, Flag8(4)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00012: Normal(Talk, TargetCanMove), id=ERMEGARDE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR4, UI8AL = 5, Flag8(4)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00013: Normal(Talk, TargetCanMove), id=ERMEGARDE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 5, Flag8(5)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00014: Normal(Talk, TargetCanMove), id=ADELSTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 5, Flag8(5)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00015: Normal(Talk, TargetCanMove), id=ADELSTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player ) //SEQ_1: ACTOR5, UI8AL = 5, Flag8(5)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00016: Normal(Talk, TargetCanMove), id=ADELSTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_1: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil129:66110 calling Scene00017: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil129:66110 calling Scene00018: Normal(Talk, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_2: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil129:66110 calling Scene00019: Normal(Talk, NpcDespawn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00020: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00021: Normal(Talk, FadeIn, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00022( player );
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00022( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubWil129:66110 calling Scene00022: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil129:66110 calling Scene00023: Normal(Talk, TargetCanMove), id=ISEMBARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubWil129:66110 calling Scene00024: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
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
    player.playScene( getId(), 24, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil129 );
