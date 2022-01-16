// FFXIVTheMovie.ParserV3.6
// param used:
//EOBJECT0 = dummyESTINIEN
//EOBJECT1 = dummy
//EOBJECT2 = dummyICEHEART
//SCENE_8 = dummyESTINIEN
//SCENE_12 = dummyICEHEART
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna317 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna317() : Sapphire::ScriptAPI::EventScript( 67154 ){}; 
  ~HeaVna317() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 6 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1012661
  //ACTOR1 = 1012662
  //ACTOR2 = 1012663
  //ACTOR3 = 1013195
  //ACTOR4 = 1012665
  //ACTOR5 = 1012666
  //ACTOR6 = 1012664
  //EOBJECT0 = 2005450
  //EOBJECT1 = 2005451
  //EOBJECT2 = 2005452
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //LOCACTION1 = 965
  //LOCACTIONWATCH = 973
  //LOCACTOR0 = 1012446
  //LOCACTOR1 = 5857906
  //LOCACTOR10 = 5858218
  //LOCACTOR11 = 5858219
  //LOCACTOR2 = 5857907
  //LOCBGMKU = 322
  //LOCMAKERSKY = 5901636
  //LOCMAKERSKYSHUPA = 5905865
  //LOCSEKUPO = 99

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1012661 || param2 == 1012661 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012662 || param2 == 1012662 ) // ACTOR1 = ESTINIEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove, ENpcBind), id=ESTINIEN
          break;
        }
        if( param1 == 1012663 || param2 == 1012663 ) // ACTOR2 = ICEHEART
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1013195 || param2 == 1013195 ) // ACTOR3 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1012665 || param2 == 1012665 ) // ACTOR4 = ESTINIEN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012666 || param2 == 1012666 ) // ACTOR5 = ICEHEART
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2005450 || param2 == 2005450 ) // EOBJECT0 = dummyESTINIEN
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, ENpcBind), id=dummyESTINIEN
          }
          break;
        }
        if( param1 == 2005451 || param2 == 2005451 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2005452 || param2 == 2005452 ) // EOBJECT2 = dummyICEHEART
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, ENpcBind), id=dummyICEHEART
          }
          break;
        }
        if( param1 == 1012664 || param2 == 1012664 ) // ACTOR6 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1012665 || param2 == 1012665 ) // ACTOR4 = ESTINIEN
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ESTINIEN
          break;
        }
        if( param1 == 1012666 || param2 == 1012666 ) // ACTOR5 = ICEHEART
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ICEHEART
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
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

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna317:67154 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00002: Normal(Talk, TargetCanMove, ENpcBind), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00003: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00006: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: EOBJECT0, UI8BL = 1, Flag8(1)=True
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00008: Normal(Talk, ENpcBind), id=dummyESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 1, Flag8(2)=True
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00010: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: EOBJECT2, UI8BH = 1, Flag8(3)=True
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00012: Normal(Talk, ENpcBind), id=dummyICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00014: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00015: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "HeaVna317:67154 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 16, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna317 );
