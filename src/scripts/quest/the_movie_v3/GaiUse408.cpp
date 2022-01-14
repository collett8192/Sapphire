// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse408 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse408() : Sapphire::ScriptAPI::EventScript( 65611 ){}; 
  ~GaiUse408() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 6 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 1 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1006444
  //ACTOR1 = 1010001
  //ACTOR2 = 1009996
  //ACTOR3 = 1010002
  //ACTOR4 = 1009997
  //ACTOR5 = 1010054
  //ACTOR6 = 5010000
  //CUTSCENEN01 = 611
  //CUTSCENEN02 = 612
  //INSTANCEDUNGEON0 = 27
  //POPRANGE0 = 5039666
  //TERRITORYTYPE0 = 155
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKDUNGEONSNOWCLOAK = 254

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DRILLEMONT
        break;
      }
      case 1:
      {
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC
          }
          break;
        }
        if( param1 == 1009996 || param2 == 1009996 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR3 = LUCIA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1009997 || param2 == 1009997 ) // ACTOR4 = YUYUHASE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUYUHASE
          break;
        }
        if( param1 == 1010054 || param2 == 1010054 ) // ACTOR5 = TEMPLER00075
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=TEMPLER00075
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1009996 || param2 == 1009996 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR3 = LUCIA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1009997 || param2 == 1009997 ) // ACTOR4 = YUYUHASE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YUYUHASE
          break;
        }
        if( param1 == 1010054 || param2 == 1010054 ) // ACTOR5 = TEMPLER00075
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=TEMPLER00075
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1010054 || param2 == 1010054 ) // ACTOR5 = TEMPLER00075
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, Message, TargetCanMove), id=TEMPLER00075
          }
          break;
        }
        if( param1 == 1009996 || param2 == 1009996 ) // ACTOR2 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR3 = LUCIA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1009997 || param2 == 1009997 ) // ACTOR4 = YUYUHASE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=YUYUHASE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1009996 || param2 == 1009996 ) // ACTOR2 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR3 = LUCIA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1009997 || param2 == 1009997 ) // ACTOR4 = YUYUHASE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YUYUHASE
          break;
        }
        if( param1 == 1010054 || param2 == 1010054 ) // ACTOR5 = TEMPLER00075
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TEMPLER00075
          break;
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00026( player ); // Scene00026: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1009996 || param2 == 1009996 ) // ACTOR2 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1009997 || param2 == 1009997 ) // ACTOR4 = YUYUHASE
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=YUYUHASE
          break;
        }
        if( param1 == 1010054 || param2 == 1010054 ) // ACTOR5 = TEMPLER00075
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=TEMPLER00075
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR3 = LUCIA
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=LUCIA
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse408:65611 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00002: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00004: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00005: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00006: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00007: Normal(Talk, TargetCanMove), id=TEMPLER00075" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00008: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00009: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00010: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00011: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00012: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00013: Normal(Talk, TargetCanMove), id=TEMPLER00075" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00014: Normal(Talk, Message, TargetCanMove), id=TEMPLER00075" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00016: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00017: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00018: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00019: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_4: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00021: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00022: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00023: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00024: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00025: Normal(Talk, TargetCanMove), id=TEMPLER00075" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_5: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00026: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00027: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00028: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player ) //SEQ_255: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00029: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00030: Normal(Talk, TargetCanMove), id=TEMPLER00075" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00031: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_255: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse408:65611 calling Scene00032: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse408 );
