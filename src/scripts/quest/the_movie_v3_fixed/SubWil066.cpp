// FFXIVTheMovie.ParserV3
//fix: skip quest battle
// id hint used:
//SCENE_5 = KODOMOA
//SCENE_8 = KODOMOB
//SCENE_11 = KODOMOC
//SCENE_14 = KODOMOD
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil066 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil066() : Sapphire::ScriptAPI::EventScript( 65856 ){}; 
  ~SubWil066() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 1 entries
  //SEQ_4, 8 entries
  //SEQ_5, 1 entries
  //SEQ_6, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1001578
  //ACTOR1 = 1002947
  //ACTOR10 = 1002956
  //ACTOR11 = 1002957
  //ACTOR12 = 1002958
  //ACTOR13 = 1001353
  //ACTOR15 = 1002990
  //ACTOR16 = 1002991
  //ACTOR17 = 1002992
  //ACTOR2 = 1002948
  //ACTOR3 = 1002949
  //ACTOR4 = 1002950
  //ACTOR5 = 1002951
  //ACTOR6 = 1002955
  //ACTOR7 = 1002952
  //ACTOR8 = 1002953
  //ACTOR9 = 1002954
  //CUTSCENE02 = 190
  //CUTSCENE03 = 191
  //CUTSCENE04 = 192
  //EOBJECT0 = 2001851
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000239
  //LOCACTOR20 = 1001976
  //LOCACTOR30 = 1001794
  //LOCPOSCAM1 = 4162159
  //LOCPOSCAM2 = 4162312
  //LOCPOSENPC1 = 3817003
  //LOCPOSENPC2 = 3817009
  //LOCPOSENPC3 = 3817004
  //LOCPOSENPC6 = 4162156
  //LOCPOSENPC7 = 4162311
  //LOGMESSAGERECOMMENDLISTUNLOCK = 3701
  //QUESTBATTLE0 = 18
  //REWARD0 = 9
  //REWARDLEVE = 5
  //TERRITORYTYPE0 = 248
  //TERRITORYTYPE1 = 141
  //UNLOCKCHECKINNREWARD = 2
  //UNLOCKIMAGEGEARSET = 29
  //UNLOCKIMAGEINN = 18
  //UNLOCKIMAGELEVE = 20

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=ZUZUMEDA
        // +Callback Scene00001: Normal(QuestAccept), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=WYSTAN
        break;
      }
      //seq 2 event item ITEM0 = UI8CL max stack 1
      case 2:
      {
        if( actor == 1002948 || actorId == 1002948 ) // ACTOR2 = KODOMOA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=KODOMOA
          }
          else
          {
            Scene00005( player ); // Scene00005: Normal(None), id=KODOMOA
          }
        }
        if( actor == 1002949 || actorId == 1002949 ) // ACTOR3 = KODOMOB
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=KODOMOB
          }
          else
          {
            Scene00008( player ); // Scene00008: Normal(None), id=KODOMOB
          }
        }
        if( actor == 1002950 || actorId == 1002950 ) // ACTOR4 = KODOMOC
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=KODOMOC
          }
          else
          {
            Scene00011( player ); // Scene00011: Normal(None), id=KODOMOC
          }
        }
        if( actor == 1002951 || actorId == 1002951 ) // ACTOR5 = KODOMOD
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=KODOMOD
          }
          else
          {
            Scene00014( player ); // Scene00014: Normal(None), id=KODOMOD
          }
        }
        if( actor == 1002947 || actorId == 1002947 ) // ACTOR1 = WYSTAN
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=WYSTAN
        }
        break;
      }
      case 3:
      {
        Scene00016( player ); // Scene00016: Normal(Talk, FadeIn, TargetCanMove), id=WYSTAN
        break;
      }
      case 4:
      {
        if( actor == 1002955 || actorId == 1002955 ) // ACTOR6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(QuestBattle, YesNo), id=unknown
          }
        }
        if( actor == 1002952 || actorId == 1002952 ) // ACTOR7 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( actor == 1002953 || actorId == 1002953 ) // ACTOR8 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 1002954 || actorId == 1002954 ) // ACTOR9 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        if( actor == 1002956 || actorId == 1002956 ) // ACTOR10 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( actor == 1002957 || actorId == 1002957 ) // ACTOR11 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( actor == 1002958 || actorId == 1002958 ) // ACTOR12 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 2001851 || actorId == 2001851 ) // EOBJECT0 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          // +Callback Scene00025: Normal(None), id=unknown
        }
        break;
      }
      case 5:
      {
        Scene00026( player ); // Scene00026: Normal(CutScene), id=unknown
        break;
      }
      case 6:
      {
        Scene00027( player ); // Scene00027: Normal(Talk, NpcDespawn, TargetCanMove), id=WYSTAN
        break;
      }
      case 255:
      {
        Scene00028( player ); // Scene00028: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MOMODI
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

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.updateQuest( getId(), 2 );
    player.setQuestUI8CL( getId(), 1 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8CL( getId(), 0 );
            player.updateQuest( getId(), 3 );
          }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
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
    player.updateQuest( getId(), 6 );
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=ZUZUMEDA" );
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
    player.sendDebug( "SubWil066:65856 calling [BranchTrue]Scene00001: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00002: Normal(Talk, TargetCanMove), id=WYSTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00003: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00004( player );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling [BranchTrue]Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=KODOMOA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling [BranchFalse]Scene00005: Normal(None), id=KODOMOA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling [BranchTrue]Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=KODOMOB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling [BranchFalse]Scene00008: Normal(None), id=KODOMOB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling [BranchTrue]Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=KODOMOC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling [BranchFalse]Scene00011: Normal(None), id=KODOMOC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00012: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling [BranchTrue]Scene00013: Normal(Talk, NpcDespawn, TargetCanMove), id=KODOMOD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling [BranchFalse]Scene00014: Normal(None), id=KODOMOD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00015: Normal(Talk, TargetCanMove), id=WYSTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00016: Normal(Talk, FadeIn, TargetCanMove), id=WYSTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00017: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00026( player );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00024: Normal(None), id=unknown" );
    Scene00025( player );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling [BranchTrue]Scene00025: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00026: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00027: Normal(Talk, NpcDespawn, TargetCanMove), id=WYSTAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "SubWil066:65856 calling Scene00028: Normal(Talk, Message, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=MOMODI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 28, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( SubWil066 );
