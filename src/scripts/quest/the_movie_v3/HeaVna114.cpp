// FFXIVTheMovie.ParserV3.6
// param used:
//_ACTOR1 = E
//_ACTOR1E = 1|3,30
//_ACTOR3 = E
//_ACTOR3E = 1|3,30
//_ACTOR4 = E
//_ACTOR4E = 1|3,30
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna114 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna114() : Sapphire::ScriptAPI::EventScript( 67129 ){}; 
  ~HeaVna114() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINETALKJOKE = 4220
  //ACTOR0 = 1012060
  //ACTOR1 = 1013498
  //ACTOR2 = 1013499
  //ACTOR3 = 1012359
  //ACTOR4 = 1012360
  //QSTACTOR1 = 5885259
  //QSTACTOR2 = 5885258

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MARIELLE
        break;
      }
      case 1:
      {
        if( param1 == 1013498 || param2 == 1013498 ) // ACTOR1 = EMMANELLAIN, EB=3(emote=30)
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            if( type == 0 ) Scene00002( player ); // onTalk Scene00002: Normal(Talk, TargetCanMove), id=EMMANELLAIN
            if( type == 1 ) // onEmote
            {
              if( param3 == 30 ) Scene00003( player ); // Correct Scene00003: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=EMMANELLAIN
              else Scene00004( player ); // Incorrect Scene00004: Normal(Talk, TargetCanMove), id=EMMANELLAIN
            }
          }
          break;
        }
        if( param1 == 1013499 || param2 == 1013499 ) // ACTOR2 = HONOROIT
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=HONOROIT
          break;
        }
        if( param1 == 1012359 || param2 == 1012359 ) // ACTOR3 = KIGHTA01593, EB=3(emote=30)
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            if( type == 0 ) Scene00006( player ); // onTalk Scene00006: Normal(Talk, TargetCanMove), id=KIGHTA01593
            if( type == 1 ) // onEmote
            {
              if( param3 == 30 ) Scene00007( player ); // Correct Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=KIGHTA01593
              else Scene00008( player ); // Incorrect Scene00008: Normal(Talk, TargetCanMove), id=KIGHTA01593
            }
          }
          break;
        }
        if( param1 == 1012360 || param2 == 1012360 ) // ACTOR4 = KIGHTB01593, EB=3(emote=30)
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            if( type == 0 ) Scene00009( player ); // onTalk Scene00009: Normal(Talk, TargetCanMove), id=KIGHTB01593
            if( type == 1 ) // onEmote
            {
              if( param3 == 30 ) Scene00010( player ); // Correct Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=KIGHTB01593
              else Scene00011( player ); // Incorrect Scene00011: Normal(Talk, TargetCanMove), id=KIGHTB01593
            }
          }
          break;
        }
        if( param1 == 1012060 || param2 == 1012060 ) // ACTOR0 = MARIELLE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MARIELLE
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00013( player ); // Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MARIELLE
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 2, false );
          player.setQuestBitFlag8( getId(), 3, false );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna114:67129 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MARIELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8BL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00002: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    player.playScene( getId(), 2, NONE, nullptr );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8BL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR1, UI8BL = 1, Flag8(1)=True, Branch
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00004: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    player.playScene( getId(), 4, NONE, nullptr );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00005: Normal(Talk, TargetCanMove, ENpcBind), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(2)=True, Branch
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00006: Normal(Talk, TargetCanMove), id=KIGHTA01593" );
    player.playScene( getId(), 6, NONE, nullptr );
  }
  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(2)=True, Branch
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=KIGHTA01593" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(2)=True, Branch
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00008: Normal(Talk, TargetCanMove), id=KIGHTA01593" );
    player.playScene( getId(), 8, NONE, nullptr );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR4, UI8BH = 1, Flag8(3)=True, Branch
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00009: Normal(Talk, TargetCanMove), id=KIGHTB01593" );
    player.playScene( getId(), 9, NONE, nullptr );
  }
  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR4, UI8BH = 1, Flag8(3)=True, Branch
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=KIGHTB01593" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR4, UI8BH = 1, Flag8(3)=True, Branch
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00011: Normal(Talk, TargetCanMove), id=KIGHTB01593" );
    player.playScene( getId(), 11, NONE, nullptr );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00012: Normal(Talk, TargetCanMove), id=MARIELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna114:67129 calling Scene00013: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MARIELLE" );
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
    player.playScene( getId(), 13, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna114 );
