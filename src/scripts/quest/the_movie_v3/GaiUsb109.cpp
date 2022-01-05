// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb109 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb109() : Sapphire::ScriptAPI::EventScript( 66364 ){}; 
  ~GaiUsb109() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006296
  //ACTOR1 = 1006297
  //ACTOR2 = 1006298
  //ACTOR3 = 1006299
  //ACTOR4 = 1006300
  //ACTOR5 = 1006301
  //ACTOR6 = 1006302

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URAHTALO
        break;
      }
      case 1:
      {
        if( param1 == 1006297 || param2 == 1006297 ) // ACTOR1 = PEEPA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=PEEPA
            // +Callback Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPA
            // +Callback Scene00004: Normal(Talk, TargetCanMove), id=PEEPA
          }
          break;
        }
        if( param1 == 1006298 || param2 == 1006298 ) // ACTOR2 = PEEPB
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=PEEPB
            // +Callback Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPB
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=PEEPB
          }
          break;
        }
        if( param1 == 1006299 || param2 == 1006299 ) // ACTOR3 = PEEPC
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=PEEPC
            // +Callback Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPC
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=PEEPC
          }
          break;
        }
        if( param1 == 1006300 || param2 == 1006300 ) // ACTOR4 = PEEPD
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=PEEPD
            // +Callback Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPD
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=PEEPD
          }
          break;
        }
        if( param1 == 1006301 || param2 == 1006301 ) // ACTOR5 = PEEPE
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=PEEPE
            // +Callback Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPE
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=PEEPE
          }
          break;
        }
        if( param1 == 1006302 || param2 == 1006302 ) // ACTOR6 = PEEPF
        {
          if( player.getQuestUI8DH( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=PEEPF
            // +Callback Scene00018: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPF
            // +Callback Scene00019: Normal(Talk, TargetCanMove), id=PEEPF
          }
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URAHTALO
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
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
            if( player.getQuestUI8CL( getId() ) == 1 )
              if( player.getQuestUI8DH( getId() ) == 1 )
              {
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8BH( getId(), 0 );
                player.setQuestUI8BL( getId(), 0 );
                player.setQuestUI8CH( getId(), 0 );
                player.setQuestUI8CL( getId(), 0 );
                player.setQuestUI8DH( getId(), 0 );
                player.setQuestBitFlag8( getId(), 1, false );
                player.setQuestBitFlag8( getId(), 2, false );
                player.setQuestBitFlag8( getId(), 3, false );
                player.setQuestBitFlag8( getId(), 4, false );
                player.setQuestBitFlag8( getId(), 5, false );
                player.setQuestBitFlag8( getId(), 6, false );
                player.updateQuest( getId(), 255 );
              }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb109:66364 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=URAHTALO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00002: Normal(Talk, TargetCanMove), id=PEEPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00004: Normal(Talk, TargetCanMove), id=PEEPA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00005: Normal(Talk, TargetCanMove), id=PEEPB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00007: Normal(Talk, TargetCanMove), id=PEEPB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00008: Normal(Talk, TargetCanMove), id=PEEPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00010: Normal(Talk, TargetCanMove), id=PEEPC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00011: Normal(Talk, TargetCanMove), id=PEEPD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00013: Normal(Talk, TargetCanMove), id=PEEPD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_1: ACTOR5, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00014: Normal(Talk, TargetCanMove), id=PEEPE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player ) //SEQ_1: ACTOR5, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player ) //SEQ_1: ACTOR5, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00016: Normal(Talk, TargetCanMove), id=PEEPE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_1: ACTOR6, UI8DH = 1, Flag8(6)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00017: Normal(Talk, TargetCanMove), id=PEEPF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player ) //SEQ_1: ACTOR6, UI8DH = 1, Flag8(6)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00018: Normal(Talk, NpcDespawn, TargetCanMove), id=PEEPF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player ) //SEQ_1: ACTOR6, UI8DH = 1, Flag8(6)=True
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00019: Normal(Talk, TargetCanMove), id=PEEPF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 6, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsb109:66364 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=URAHTALO" );
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
    player.playScene( getId(), 20, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsb109 );
