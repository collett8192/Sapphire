// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa103 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa103() : Sapphire::ScriptAPI::EventScript( 66253 ){}; 
  ~GaiUsa103() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTBYEBYE = 962
  //ACTIONTIMELINEEVENTFIDGET = 968
  //ACTIONTIMELINEEVENTJOYBIG = 945
  //ACTIONTIMELINEEVENTLAUGH = 952
  //ACTIONTIMELINEEVENTTROUBLE = 944
  //ACTOR0 = 1006674
  //ACTOR1 = 1000563
  //ACTOR2 = 1000437
  //ACTOR3 = 1000576
  //ACTOR4 = 1000585
  //ACTOR5 = 1000584
  //ACTOR6 = 1000587
  //ACTOR7 = 1000578
  //ACTOR8 = 1000277

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=YDA
        break;
      }
      case 1:
      {
        if( param1 == 1000563 || param2 == 1000563 ) // ACTOR1 = AMEEXIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=AMEEXIA
            // +Callback Scene00002: Normal(Talk, TargetCanMove), id=AMEEXIA
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=AMEEXIA
          }
          break;
        }
        if( param1 == 1000437 || param2 == 1000437 ) // ACTOR2 = ZACHEUS
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ZACHEUS
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=ZACHEUS
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=ZACHEUS
          }
          break;
        }
        if( param1 == 1000576 || param2 == 1000576 ) // ACTOR3 = KNOLEXIA
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KNOLEXIA
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=KNOLEXIA
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=KNOLEXIA
          }
          break;
        }
        if( param1 == 1000585 || param2 == 1000585 ) // ACTOR4 = PELIXIA
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=PELIXIA
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=PELIXIA
            // +Callback Scene00012: Normal(Talk, TargetCanMove), id=PELIXIA
          }
          break;
        }
        if( param1 == 1000584 || param2 == 1000584 ) // ACTOR5 = IMEDIA
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=IMEDIA
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=IMEDIA
            // +Callback Scene00015: Normal(Talk, TargetCanMove), id=IMEDIA
          }
          break;
        }
        if( param1 == 1000587 || param2 == 1000587 ) // ACTOR6 = DELLEXIA
        {
          if( player.getQuestUI8DH( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=DELLEXIA
            // +Callback Scene00017: Normal(Talk, TargetCanMove), id=DELLEXIA
            // +Callback Scene00018: Normal(Talk, TargetCanMove), id=DELLEXIA
          }
          break;
        }
        if( param1 == 1000578 || param2 == 1000578 ) // ACTOR7 = MARINTERRE
        {
          if( player.getQuestUI8DL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MARINTERRE
            // +Callback Scene00020: Normal(Talk, TargetCanMove), id=MARINTERRE
            // +Callback Scene00021: Normal(Talk, TargetCanMove), id=MARINTERRE
          }
          break;
        }
        if( param1 == 1000277 || param2 == 1000277 ) // ACTOR8 = NATHAXIO
        {
          if( player.getQuestUI8EH( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=NATHAXIO
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=NATHAXIO
            // +Callback Scene00024: Normal(Talk, TargetCanMove), id=NATHAXIO
          }
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00025( player ); // Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YDA
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
                if( player.getQuestUI8DL( getId() ) == 1 )
                  if( player.getQuestUI8EH( getId() ) == 1 )
                  {
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8BH( getId(), 0 );
                    player.setQuestUI8BL( getId(), 0 );
                    player.setQuestUI8CH( getId(), 0 );
                    player.setQuestUI8CL( getId(), 0 );
                    player.setQuestUI8DH( getId(), 0 );
                    player.setQuestUI8DL( getId(), 0 );
                    player.setQuestUI8EH( getId(), 0 );
                    player.setQuestBitFlag8( getId(), 1, false );
                    player.setQuestBitFlag8( getId(), 2, false );
                    player.setQuestBitFlag8( getId(), 3, false );
                    player.setQuestBitFlag8( getId(), 4, false );
                    player.setQuestBitFlag8( getId(), 5, false );
                    player.setQuestBitFlag8( getId(), 6, false );
                    player.setQuestBitFlag8( getId(), 7, false );
                    player.setQuestBitFlag8( getId(), 8, false );
                    player.updateQuest( getId(), 255 );
                  }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00001: Normal(Talk, TargetCanMove), id=AMEEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00002: Normal(Talk, TargetCanMove), id=AMEEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00003: Normal(Talk, TargetCanMove), id=AMEEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00004: Normal(Talk, TargetCanMove), id=ZACHEUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00005: Normal(Talk, TargetCanMove), id=ZACHEUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00006: Normal(Talk, TargetCanMove), id=ZACHEUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00007: Normal(Talk, TargetCanMove), id=KNOLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00008: Normal(Talk, TargetCanMove), id=KNOLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00009: Normal(Talk, TargetCanMove), id=KNOLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00010: Normal(Talk, TargetCanMove), id=PELIXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00011: Normal(Talk, TargetCanMove), id=PELIXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR4, UI8CH = 1, Flag8(4)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00012: Normal(Talk, TargetCanMove), id=PELIXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 4, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR5, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00013: Normal(Talk, TargetCanMove), id=IMEDIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player ) //SEQ_1: ACTOR5, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00014: Normal(Talk, TargetCanMove), id=IMEDIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player ) //SEQ_1: ACTOR5, UI8CL = 1, Flag8(5)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00015: Normal(Talk, TargetCanMove), id=IMEDIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 5, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_1: ACTOR6, UI8DH = 1, Flag8(6)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00016: Normal(Talk, TargetCanMove), id=DELLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player ) //SEQ_1: ACTOR6, UI8DH = 1, Flag8(6)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00017: Normal(Talk, TargetCanMove), id=DELLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player ) //SEQ_1: ACTOR6, UI8DH = 1, Flag8(6)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00018: Normal(Talk, TargetCanMove), id=DELLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 6, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_1: ACTOR7, UI8DL = 1, Flag8(7)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00019: Normal(Talk, TargetCanMove), id=MARINTERRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player ) //SEQ_1: ACTOR7, UI8DL = 1, Flag8(7)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00020: Normal(Talk, TargetCanMove), id=MARINTERRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player ) //SEQ_1: ACTOR7, UI8DL = 1, Flag8(7)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00021: Normal(Talk, TargetCanMove), id=MARINTERRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 7, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_1: ACTOR8, UI8EH = 1, Flag8(8)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00022: Normal(Talk, TargetCanMove), id=NATHAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player ) //SEQ_1: ACTOR8, UI8EH = 1, Flag8(8)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00023: Normal(Talk, TargetCanMove), id=NATHAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player ) //SEQ_1: ACTOR8, UI8EH = 1, Flag8(8)=True
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00024: Normal(Talk, TargetCanMove), id=NATHAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8EH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 8, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YDA" );
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
    player.playScene( getId(), 25, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsa103 );
