// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse210 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse210() : Sapphire::ScriptAPI::EventScript( 66890 ){}; 
  ~GaiUse210() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 3 entries
  //SEQ_3, 2 entries
  //SEQ_4, 4 entries
  //SEQ_255, 16 entries

  //ACTOR0 = 1008554
  //ACTOR1 = 1008559
  //ACTOR10 = 1008669
  //ACTOR11 = 1008670
  //ACTOR12 = 1008671
  //ACTOR13 = 1008672
  //ACTOR14 = 1008673
  //ACTOR15 = 1008674
  //ACTOR16 = 1008675
  //ACTOR17 = 1008541
  //ACTOR2 = 1006950
  //ACTOR3 = 1008663
  //ACTOR4 = 1008662
  //ACTOR5 = 1008664
  //ACTOR6 = 1008665
  //ACTOR7 = 1008666
  //ACTOR8 = 1008667
  //ACTOR9 = 1008668
  //EOBJECT0 = 2003574
  //EOBJECT1 = 2003575
  //EOBJECT2 = 2003576
  //EOBJECT3 = 2003577
  //EOBJECT4 = 2003578
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONTOUCHSHORT = 45
  //ITEM0 = 2001210
  //ITEM1 = 2001211

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA
        break;
      }
      case 1:
      {
        if( param1 == 1008559 || param2 == 1008559 ) // ACTOR1 = FLHAMINN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=FLHAMINN
          }
          break;
        }
        if( param1 == 1008554 || param2 == 1008554 ) // ACTOR0 = MINFILIA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 2
      case 2:
      {
        if( param1 == 2003574 || param2 == 2003574 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2003575 || param2 == 2003575 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1008559 || param2 == 1008559 ) // ACTOR1 = FLHAMINN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=FLHAMINN
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 2
      case 3:
      {
        if( param1 == 1006950 || param2 == 1006950 ) // ACTOR2 = ALYS
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALYS
          }
          break;
        }
        if( param1 == 1008559 || param2 == 1008559 ) // ACTOR1 = FLHAMINN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=FLHAMINN
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 2
      //seq 4 event item ITEM1 = UI8BL max stack 3
      case 4:
      {
        if( param1 == 2003576 || param2 == 2003576 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2003577 || param2 == 2003577 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2003578 || param2 == 2003578 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1006950 || param2 == 1006950 ) // ACTOR2 = ALYS
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALYS
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 2
      //seq 255 event item ITEM1 = UI8BL max stack 3
      case 255:
      {
        if( param1 == 1008663 || param2 == 1008663 ) // ACTOR3 = HONBUBOUKENSHA01354
        {
          Scene00018( player ); // Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HONBUBOUKENSHA01354
          break;
        }
        if( param1 == 1008662 || param2 == 1008662 ) // ACTOR4 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008664 || param2 == 1008664 ) // ACTOR5 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008665 || param2 == 1008665 ) // ACTOR6 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008666 || param2 == 1008666 ) // ACTOR7 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008667 || param2 == 1008667 ) // ACTOR8 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008668 || param2 == 1008668 ) // ACTOR9 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008669 || param2 == 1008669 ) // ACTOR10 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008670 || param2 == 1008670 ) // ACTOR11 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008671 || param2 == 1008671 ) // ACTOR12 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008672 || param2 == 1008672 ) // ACTOR13 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008673 || param2 == 1008673 ) // ACTOR14 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008674 || param2 == 1008674 ) // ACTOR15 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008675 || param2 == 1008675 ) // ACTOR16 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1006950 || param2 == 1006950 ) // ACTOR2 = ALYS
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=ALYS
          break;
        }
        if( param1 == 1008541 || param2 == 1008541 ) // ACTOR17 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.setQuestBitFlag8( getId(), 2, false );
      player.setQuestBitFlag8( getId(), 3, false );
      player.updateQuest( getId(), 255 );
      player.setQuestUI8BH( getId(), 2 );
      player.setQuestUI8BL( getId(), 3 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse210:66890 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00002: Normal(Talk, TargetCanMove), id=FLHAMINN" );
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
    player.sendDebug( "GaiUse210:66890 calling Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: EOBJECT0, UI8AL = 2, Flag8(1)=True
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00005: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq2( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 2, Flag8(2)=True
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00008: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00009: Normal(Talk, TargetCanMove), id=ALYS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00010: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_4: EOBJECT2, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq4( player );
  }

  void Scene00014( Entity::Player& player ) //SEQ_4: EOBJECT3, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00014: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq4( player );
  }

  void Scene00016( Entity::Player& player ) //SEQ_4: EOBJECT4, UI8AL = 3, Flag8(3)=True
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq4( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00017: Normal(Talk, TargetCanMove), id=ALYS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00018: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HONBUBOUKENSHA01354" );
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
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00033: Normal(Talk, TargetCanMove), id=ALYS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse210:66890 calling Scene00034: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUse210 );
