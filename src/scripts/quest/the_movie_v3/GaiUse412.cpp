// FFXIVTheMovie.ParserV3.6
// id hint used:
//ACTOR2 = SHINOBI00080
//ACTOR4 = null
//ACTOR5 = null
//ACTOR7 = SHINOBI00080
//ACTOR8 = null
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse412 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse412() : Sapphire::ScriptAPI::EventScript( 65616 ){}; 
  ~GaiUse412() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 8 entries
  //SEQ_255, 13 entries

  //ACTOR0 = 1010017
  //ACTOR1 = 1010020
  //ACTOR10 = 1010024
  //ACTOR11 = 1010025
  //ACTOR12 = 1010026
  //ACTOR13 = 1010027
  //ACTOR14 = 1010028
  //ACTOR15 = 1010029
  //ACTOR16 = 1010030
  //ACTOR17 = 1010031
  //ACTOR18 = 1010032
  //ACTOR19 = 1010033
  //ACTOR2 = 1010021
  //ACTOR3 = 1009986
  //ACTOR4 = 1010022
  //ACTOR5 = 1010023
  //ACTOR6 = 1009975
  //ACTOR7 = 1010034
  //ACTOR8 = 1010035
  //ACTOR9 = 1010036
  //BGMNOTHING = 1
  //ENEMY0 = 5099974
  //ENEMY1 = 5099975
  //ENEMY2 = 5099976
  //EOBJECT0 = 2004660
  //EVENTRANGE0 = 5099945
  //LOCACTOR0 = 1007097
  //LOCBGM01 = 114
  //LOCPOSACTOR0 = 5249407
  //POPRANGE0 = 5249405

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ILBERD
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=ILBERD
        break;
      }
      case 2:
      {
        if( param1 == 1010021 || param2 == 1010021 ) // ACTOR2 = SHINOBI00080
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=SHINOBI00080
          }
          break;
        }
        if( param1 == 1009986 || param2 == 1009986 ) // ACTOR3 = ILBERD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ILBERD
          break;
        }
        if( param1 == 1010022 || param2 == 1010022 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010023 || param2 == 1010023 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009975 || param2 == 1009975 ) // ACTOR6 = YUGIRI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 5099945 || param2 == 5099945 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5099974 || param2 == 5099974 ) // ENEMY0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 5099975 || param2 == 5099975 ) // ENEMY1 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 5099976 || param2 == 5099976 ) // ENEMY2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004660 || param2 == 2004660 ) // EOBJECT0 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010021 || param2 == 1010021 ) // ACTOR2 = SHINOBI00080
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=SHINOBI00080
          break;
        }
        if( param1 == 1010022 || param2 == 1010022 ) // ACTOR4 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010023 || param2 == 1010023 ) // ACTOR5 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1010034 || param2 == 1010034 ) // ACTOR7 = SHINOBI00080
        {
          Scene00016( player ); // Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SHINOBI00080
          break;
        }
        if( param1 == 1010035 || param2 == 1010035 ) // ACTOR8 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010036 || param2 == 1010036 ) // ACTOR9 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010024 || param2 == 1010024 ) // ACTOR10 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010025 || param2 == 1010025 ) // ACTOR11 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010026 || param2 == 1010026 ) // ACTOR12 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010027 || param2 == 1010027 ) // ACTOR13 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010028 || param2 == 1010028 ) // ACTOR14 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010029 || param2 == 1010029 ) // ACTOR15 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010030 || param2 == 1010030 ) // ACTOR16 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010031 || param2 == 1010031 ) // ACTOR17 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010032 || param2 == 1010032 ) // ACTOR18 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010033 || param2 == 1010033 ) // ACTOR19 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
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
    player.updateQuest( getId(), 2 );
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse412:65616 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove, AutoFadeIn), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00003: Normal(Talk, TargetCanMove), id=SHINOBI00080" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00004: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00007: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: EVENTRANGE0, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_3: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00013: Normal(Talk, TargetCanMove), id=SHINOBI00080" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00016: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SHINOBI00080" );
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

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player ) //SEQ_255: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player ) //SEQ_255: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player ) //SEQ_255: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player ) //SEQ_255: ACTOR13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player ) //SEQ_255: ACTOR14, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player ) //SEQ_255: ACTOR15, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player ) //SEQ_255: ACTOR16, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player ) //SEQ_255: ACTOR17, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player ) //SEQ_255: ACTOR18, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player ) //SEQ_255: ACTOR19, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse412:65616 calling Scene00028: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUse412 );
