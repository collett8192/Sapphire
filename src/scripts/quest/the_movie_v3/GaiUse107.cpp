// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse107 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse107() : Sapphire::ScriptAPI::EventScript( 66717 ){}; 
  ~GaiUse107() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 6 entries
  //SEQ_3, 10 entries
  //SEQ_4, 9 entries
  //SEQ_255, 9 entries

  //ACTOR0 = 1006544
  //ACTOR1 = 1007741
  //ACTOR2 = 1007742
  //ACTOR3 = 1007743
  //ACTOR4 = 1007744
  //ACTOR5 = 1007745
  //ACTOR6 = 1007746
  //ACTOR7 = 1007747
  //ACTOR8 = 1007748
  //ACTOR9 = 1007749
  //EOBJECT0 = 2002844
  //EOBJECT1 = 2002845
  //EOBJECT2 = 2002846
  //EOBJECT3 = 2002920
  //EOBJECT4 = 2002921
  //EVENTACTIONPROCESSMIDDLE = 16
  //EVENTACTIONRESCUEUNDERMIDDLE = 35

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUOLGEIM
        break;
      }
      case 1:
      {
        if( param1 == 1007741 || param2 == 1007741 ) // ACTOR1 = WOODWAILERA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=WOODWAILERA
          }
          break;
        }
        if( param1 == 1006544 || param2 == 1006544 ) // ACTOR0 = GUOLGEIM
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GUOLGEIM
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1007742 || param2 == 1007742 ) // ACTOR2 = WOODWAILERB
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=WOODWAILERB
          }
          break;
        }
        if( param1 == 1007743 || param2 == 1007743 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007744 || param2 == 1007744 ) // ACTOR4 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007745 || param2 == 1007745 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006544 || param2 == 1006544 ) // ACTOR0 = GUOLGEIM
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=GUOLGEIM
          break;
        }
        if( param1 == 1007741 || param2 == 1007741 ) // ACTOR1 = WOODWAILERA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=WOODWAILERA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1007746 || param2 == 1007746 ) // ACTOR6 = ELEZENCOACHMAN
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=ELEZENCOACHMAN
          }
          break;
        }
        if( param1 == 1007747 || param2 == 1007747 ) // ACTOR7 = HYURCOACHMAN
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=HYURCOACHMAN
          }
          break;
        }
        if( param1 == 2002844 || param2 == 2002844 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002845 || param2 == 2002845 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            Scene00017( player ); // Scene00017: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2002846 || param2 == 2002846 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            Scene00019( player ); // Scene00019: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1007743 || param2 == 1007743 ) // ACTOR3 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007744 || param2 == 1007744 ) // ACTOR4 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007745 || param2 == 1007745 ) // ACTOR5 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007742 || param2 == 1007742 ) // ACTOR2 = WOODWAILERB
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=WOODWAILERB
          break;
        }
        if( param1 == 1006544 || param2 == 1006544 ) // ACTOR0 = GUOLGEIM
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=GUOLGEIM
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1007748 || param2 == 1007748 ) // ACTOR8 = ELEZENCOACHMAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ELEZENCOACHMAN
          }
          break;
        }
        if( param1 == 1007743 || param2 == 1007743 ) // ACTOR3 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007744 || param2 == 1007744 ) // ACTOR4 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007745 || param2 == 1007745 ) // ACTOR5 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007742 || param2 == 1007742 ) // ACTOR2 = WOODWAILERB
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=WOODWAILERB
          break;
        }
        if( param1 == 2002920 || param2 == 2002920 ) // EOBJECT3 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002921 || param2 == 2002921 ) // EOBJECT4 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007749 || param2 == 1007749 ) // ACTOR9 = HYURCOACHMAN
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=HYURCOACHMAN
          break;
        }
        if( param1 == 1006544 || param2 == 1006544 ) // ACTOR0 = GUOLGEIM
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=GUOLGEIM
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006544 || param2 == 1006544 ) // ACTOR0 = GUOLGEIM
        {
          Scene00034( player ); // Scene00034: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUOLGEIM
          break;
        }
        if( param1 == 1007743 || param2 == 1007743 ) // ACTOR3 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007744 || param2 == 1007744 ) // ACTOR4 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007745 || param2 == 1007745 ) // ACTOR5 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007749 || param2 == 1007749 ) // ACTOR9 = HYURCOACHMAN
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=HYURCOACHMAN
          break;
        }
        if( param1 == 2002920 || param2 == 2002920 ) // EOBJECT3 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 2002921 || param2 == 2002921 ) // EOBJECT4 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        if( param1 == 1007742 || param2 == 1007742 ) // ACTOR2 = WOODWAILERB
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=WOODWAILERB
          break;
        }
        if( param1 == 1007748 || param2 == 1007748 ) // ACTOR8 = ELEZENCOACHMAN
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=ELEZENCOACHMAN
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 2 )
      if( player.getQuestUI8BL( getId() ) == 3 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestBitFlag16( getId(), 1, false );
        player.setQuestBitFlag16( getId(), 2, false );
        player.setQuestBitFlag16( getId(), 3, false );
        player.setQuestBitFlag16( getId(), 4, false );
        player.setQuestBitFlag16( getId(), 5, false );
        player.updateQuest( getId(), 4 );
      }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag16( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse107:66717 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUOLGEIM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00002: Normal(Talk, TargetCanMove), id=WOODWAILERA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00003: Normal(Talk, TargetCanMove), id=GUOLGEIM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00004: Normal(Talk, TargetCanMove), id=WOODWAILERB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00008: Normal(Talk, TargetCanMove), id=GUOLGEIM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00009: Normal(Talk, TargetCanMove), id=WOODWAILERA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR6, UI8BH = 2, Flag16(1)=True
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00011: Normal(Talk, NpcDespawn, TargetCanMove), id=ELEZENCOACHMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
      player.setQuestBitFlag16( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR7, UI8BH = 2, Flag16(2)=True
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=HYURCOACHMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
      player.setQuestBitFlag16( getId(), 2, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: EOBJECT0, UI8BL = 3, Flag16(3)=True
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
    player.setQuestBitFlag16( getId(), 3, true );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: EOBJECT1, UI8BL = 3, Flag16(4)=True
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00017: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
    player.setQuestBitFlag16( getId(), 4, true );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: EOBJECT2, UI8BL = 3, Flag16(5)=True
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00019: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
    player.setQuestBitFlag16( getId(), 5, true );
    checkProgressSeq3( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00023: Normal(Talk, TargetCanMove), id=WOODWAILERB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00024: Normal(Talk, TargetCanMove), id=GUOLGEIM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_4: ACTOR8, UI8AL = 1, Flag16(1)=True
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00025: Normal(Talk, TargetCanMove), id=ELEZENCOACHMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag16( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00029: Normal(Talk, TargetCanMove), id=WOODWAILERB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_4: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00030: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00031( Entity::Player& player ) //SEQ_4: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00031: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00032( Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00032: Normal(Talk, TargetCanMove), id=HYURCOACHMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00033: Normal(Talk, TargetCanMove), id=GUOLGEIM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00034: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUOLGEIM" );
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
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00038: Normal(Talk, TargetCanMove), id=HYURCOACHMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player ) //SEQ_255: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player ) //SEQ_255: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00041: Normal(Talk, TargetCanMove), id=WOODWAILERB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse107:66717 calling Scene00042: Normal(Talk, TargetCanMove), id=ELEZENCOACHMAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse107 );
