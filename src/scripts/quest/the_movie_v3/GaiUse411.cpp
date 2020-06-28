// FFXIVTheMovie.ParserV3
// id hint used:
//ACTOR6 = ACTOR6
//ACTOR7 = ACTOR7
//ACTOR8 = ACTOR8
//ACTOR9 = ACTOR9
//SCENE_11 = ACTOR6
//SCENE_12 = ACTOR6
//SCENE_13 = ACTOR7
//SCENE_14 = ACTOR7
//SCENE_15 = ACTOR8
//SCENE_16 = ACTOR8
//SCENE_17 = ACTOR9
//SCENE_18 = ACTOR9
//SCENE_22 = ACTOR6
//SCENE_23 = ACTOR7
//SCENE_24 = ACTOR8
//SCENE_25 = ACTOR9
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse411 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse411() : Sapphire::ScriptAPI::EventScript( 65615 ){}; 
  ~GaiUse411() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 2 entries
  //SEQ_4, 2 entries
  //SEQ_5, 5 entries
  //SEQ_255, 6 entries

  //ACTIONTIMELINEEVENTBASESTANDPOSE2 = 1053
  //ACTIONTIMELINEEVENTSALUTECRY = 1045
  //ACTOR0 = 1010010
  //ACTOR1 = 1010011
  //ACTOR2 = 1010017
  //ACTOR3 = 1010019
  //ACTOR4 = 1010018
  //ACTOR5 = 1010012
  //ACTOR6 = 1010013
  //ACTOR7 = 1010014
  //ACTOR8 = 1010015
  //ACTOR9 = 1010016
  //BGMNOTHING = 1
  //CUTSCENEN01 = 618
  //LEVELIDNPC01 = 5098064
  //LOCACTOR0 = 1009972
  //LOCBGM01 = 85

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1010010 || actorId == 1010010 ) // ACTOR0 = unknown
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(CutScene), id=unknown
          // +Callback Scene00002: Normal(NpcDespawn, QuestAccept, TargetCanMove), id=unknown
        }
        if( actor == 1010011 || actorId == 1010011 ) // ACTOR1 = ROAILLE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ROAILLE
        }
        break;
      }
      case 1:
      {
        if( actor == 1010017 || actorId == 1010017 ) // ACTOR2 = ILBERD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ILBERD
          }
        }
        if( actor == 1010019 || actorId == 1010019 ) // ACTOR3 = ROAILLE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ROAILLE
        }
        break;
      }
      case 2:
      {
        Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ILBERD
        break;
      }
      case 3:
      {
        if( actor == 1010012 || actorId == 1010012 ) // ACTOR5 = EPHEMIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=EPHEMIE
          }
        }
        if( actor == 1010018 || actorId == 1010018 ) // ACTOR4 = ILBERD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ILBERD
        }
        break;
      }
      case 4:
      {
        if( actor == 1010018 || actorId == 1010018 ) // ACTOR4 = ILBERD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=ILBERD
          }
        }
        if( actor == 1010012 || actorId == 1010012 ) // ACTOR5 = EPHEMIE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=EPHEMIE
        }
        break;
      }
      case 5:
      {
        if( actor == 1010013 || actorId == 1010013 ) // ACTOR6 = ACTOR6
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ACTOR6
            // +Callback Scene00012: Normal(Talk, TargetCanMove), id=ACTOR6
          }
        }
        if( actor == 1010014 || actorId == 1010014 ) // ACTOR7 = ACTOR7
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ACTOR7
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=ACTOR7
          }
        }
        if( actor == 1010015 || actorId == 1010015 ) // ACTOR8 = ACTOR8
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ACTOR8
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=ACTOR8
          }
        }
        if( actor == 1010016 || actorId == 1010016 ) // ACTOR9 = ACTOR9
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ACTOR9
            // +Callback Scene00018: Normal(Talk, TargetCanMove), id=ACTOR9
          }
        }
        if( actor == 1010012 || actorId == 1010012 ) // ACTOR5 = EPHEMIE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=EPHEMIE
        }
        break;
      }
      case 255:
      {
        if( actor == 1010017 || actorId == 1010017 ) // ACTOR2 = ILBERD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ILBERD
        }
        if( actor == 1010012 || actorId == 1010012 ) // ACTOR5 = EPHEMIE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=EPHEMIE
        }
        if( actor == 1010013 || actorId == 1010013 ) // ACTOR6 = ACTOR6
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ACTOR6
        }
        if( actor == 1010014 || actorId == 1010014 ) // ACTOR7 = ACTOR7
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ACTOR7
        }
        if( actor == 1010015 || actorId == 1010015 ) // ACTOR8 = ACTOR8
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ACTOR8
        }
        if( actor == 1010016 || actorId == 1010016 ) // ACTOR9 = ACTOR9
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ACTOR9
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
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, param1 );
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
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 2 )
      if( player.getQuestUI8BH( getId() ) == 2 )
        if( player.getQuestUI8AL( getId() ) == 2 )
          if( player.getQuestUI8AL( getId() ) == 2 )
          {
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.updateQuest( getId(), 255 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling [BranchTrue]Scene00001: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling [BranchFalse]Scene00002: Normal(NpcDespawn, QuestAccept, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00003: Normal(Talk, TargetCanMove), id=ROAILLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00005: Normal(Talk, TargetCanMove), id=ROAILLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00006: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00007: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00008: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00010: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00011: Normal(Talk, TargetCanMove), id=ACTOR6" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling [BranchTrue]Scene00012: Normal(Talk, TargetCanMove), id=ACTOR6" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00013: Normal(Talk, TargetCanMove), id=ACTOR7" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling [BranchTrue]Scene00014: Normal(Talk, TargetCanMove), id=ACTOR7" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00015: Normal(Talk, TargetCanMove), id=ACTOR8" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling [BranchTrue]Scene00016: Normal(Talk, TargetCanMove), id=ACTOR8" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00017: Normal(Talk, TargetCanMove), id=ACTOR9" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling [BranchTrue]Scene00018: Normal(Talk, TargetCanMove), id=ACTOR9" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00019: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00020: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 20, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00021: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00022: Normal(Talk, TargetCanMove), id=ACTOR6" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00023: Normal(Talk, TargetCanMove), id=ACTOR7" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00024: Normal(Talk, TargetCanMove), id=ACTOR8" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse411:65615 calling Scene00025: Normal(Talk, TargetCanMove), id=ACTOR9" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse411 );
