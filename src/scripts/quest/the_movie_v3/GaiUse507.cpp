// FFXIVTheMovie.ParserV3.6
// id hint used:
//SCENE_4 = dummyt0
//SCENE_5 REMOVED!!
//SCENE_6 = dummyt0
//SCENE_7 = dummyt0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse507 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse507() : Sapphire::ScriptAPI::EventScript( 65905 ){}; 
  ~GaiUse507() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 6 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1006646
  //ACTOR1 = 1010879
  //ACTOR10 = 1010900
  //ACTOR11 = 1010901
  //ACTOR2 = 1010870
  //ACTOR3 = 5010000
  //ACTOR4 = 1010880
  //ACTOR5 = 1008278
  //ACTOR6 = 1006950
  //ACTOR7 = 1011000
  //ACTOR8 = 1010898
  //ACTOR9 = 1010899
  //CUTSCENEN01 = 701
  //CUTSCENEN02 = 702
  //CUTSCENEN03 = 703
  //CUTSCENEN04 = 704
  //INSTANCEDUNGEON0 = 20029
  //LOCACTOR1 = 1011654
  //LOCACTOR2 = 5580859
  //LOCACTOR3 = 5580857
  //LOCACTOR4 = 5580858
  //LOCACTOR5 = 5580860
  //LOCMUSIC0 = 94
  //LOCSE0 = 44
  //POPRANGE0 = 5585579
  //TERRITORYTYPE0 = 351
  //UNLOCKDUNGEONASIENBATTLE0 = 270

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EDELSTEIN
        break;
      }
      case 1:
      {
        if( param1 == 1010879 || param2 == 1010879 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1006646 || param2 == 1006646 ) // ACTOR0 = EDELSTEIN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=EDELSTEIN
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = dummyt0
        {
          Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, AutoFadeIn), id=dummyt0
          // +Callback Scene00006: Normal(CutScene, AutoFadeIn), id=dummyt0
          // +Callback Scene00007: Normal(Message, FadeIn), id=dummyt0
          break;
        }
        if( param1 == 1010870 || param2 == 1010870 ) // ACTOR2 = MOENBRYDA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MOENBRYDA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1010880 || param2 == 1010880 ) // ACTOR4 = MOENBRYDA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MOENBRYDA
          break;
        }
        if( param1 == 1008278 || param2 == 1008278 ) // ACTOR5 = WANDERINGMINSTREL
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=WANDERINGMINSTREL
          break;
        }
        if( param1 == 1006950 || param2 == 1006950 ) // ACTOR6 = ALYS
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALYS
          break;
        }
        break;
      }
      case 4:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00012( player ); // Scene00012: Normal(CutScene), id=unknown
          break;
        }
        if( param1 == 1011000 || param2 == 1011000 ) // ACTOR7 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010898 || param2 == 1010898 ) // ACTOR8 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010899 || param2 == 1010899 ) // ACTOR9 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010900 || param2 == 1010900 ) // ACTOR10 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010901 || param2 == 1010901 ) // ACTOR11 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1011000 || param2 == 1011000 ) // ACTOR7 = MINFILIA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=MINFILIA
          break;
        }
        if( param1 == 1010898 || param2 == 1010898 ) // ACTOR8 = THANCRED
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1010899 || param2 == 1010899 ) // ACTOR9 = YDA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YDA
          break;
        }
        if( param1 == 1010900 || param2 == 1010900 ) // ACTOR10 = PAPALYMO
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=PAPALYMO
          break;
        }
        if( param1 == 1010901 || param2 == 1010901 ) // ACTOR11 = YSHTOLA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse507:65905 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00003: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00004: Normal(Talk, FadeIn, AutoFadeIn), id=dummyt0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00006( Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00006: Normal(CutScene, AutoFadeIn), id=dummyt0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_2: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00007: Normal(Message, FadeIn), id=dummyt0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00008: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00009: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00010: Normal(Talk, TargetCanMove), id=WANDERINGMINSTREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00011: Normal(Talk, TargetCanMove), id=ALYS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_4: BASE_ID_TERRITORY_TYPE, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00012: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00018: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, ENpcBind), id=MINFILIA" );
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

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00019: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00020: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00021: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse507:65905 calling Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse507 );
