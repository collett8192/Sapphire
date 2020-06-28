// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse402 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse402() : Sapphire::ScriptAPI::EventScript( 65589 ){}; 
  ~GaiUse402() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 22 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTBASEKNEESEACH = 1014
  //ACTIONTIMELINEEVENTSALUTECRY = 1045
  //ACTOR0 = 1009961
  //ACTOR1 = 1010078
  //ACTOR10 = 1009969
  //ACTOR11 = 1009970
  //ACTOR12 = 1009971
  //ACTOR13 = 1009112
  //ACTOR2 = 1009962
  //ACTOR3 = 1009963
  //ACTOR4 = 1009964
  //ACTOR5 = 1009965
  //ACTOR6 = 1010535
  //ACTOR7 = 1009966
  //ACTOR8 = 1009967
  //ACTOR9 = 1009968
  //BGMNOTHING = 1
  //ENEMY0 = 5045805
  //ENEMY1 = 5045806
  //ENEMY10 = 5046039
  //ENEMY11 = 5046040
  //ENEMY12 = 5046042
  //ENEMY13 = 5046043
  //ENEMY2 = 5045807
  //ENEMY3 = 5045957
  //ENEMY4 = 5045960
  //ENEMY5 = 5045961
  //ENEMY6 = 5046029
  //ENEMY7 = 5046030
  //ENEMY8 = 5046031
  //ENEMY9 = 5046037
  //EOBJECT0 = 2004643
  //EOBJECT1 = 2004644
  //EOBJECT2 = 2004645
  //EOBJECT3 = 2004646
  //EVENTRANGE0 = 5045803
  //EVENTRANGE1 = 5045922
  //EVENTRANGE2 = 5046024
  //EVENTRANGE3 = 5046034
  //EVENTACTIONRESCUEUNDERMIDDLE = 35
  //EVENTACTIONSEARCH = 1
  //LEVELIDNPC01 = 5045514
  //LEVELIDNPC02 = 5045515
  //LEVELIDNPC03 = 5045516
  //LOCACTOR0 = 1008192
  //LOCACTOR1 = 1010066
  //LOCACTOR2 = 1010067
  //LOCACTOR3 = 1010068
  //LOCACTOR4 = 1010069
  //LOCBGM0 = 114

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ILBERD
        break;
      }
      case 1:
      {
        if( actor == 1010078 || actorId == 1010078 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1009961 || actorId == 1009961 ) // ACTOR0 = ILBERD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ILBERD
        }
        break;
      }
      case 2:
      {
        if( actor == 1009962 || actorId == 1009962 ) // ACTOR2 = ALIANNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALIANNE
          }
        }
        if( actor == 1009963 || actorId == 1009963 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 1009964 || actorId == 1009964 ) // ACTOR4 = CRYSTALSOLDIER00053
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CRYSTALSOLDIER00053
        }
        if( actor == 1009965 || actorId == 1009965 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1010078 || actorId == 1010078 ) // ACTOR1 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1010535 || actorId == 1010535 ) // ACTOR6 = ILBERD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ILBERD
        }
        break;
      }
      case 3:
      {
        if( actor == 5045803 || actorId == 5045803 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 1009966 || actorId == 1009966 ) // ACTOR7 = RHESHPOLAALI
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, Message, TargetCanMove), id=RHESHPOLAALI
            // +Callback Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=RHESHPOLAALI
          }
        }
        if( actor == 5045805 || actorId == 5045805 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 5045806 || actorId == 5045806 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 5045807 || actorId == 5045807 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 2004643 || actorId == 2004643 ) // EOBJECT0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          // +Callback Scene00014: Normal(None), id=unknown
        }
        break;
      }
      case 4:
      {
        if( actor == 5045922 || actorId == 5045922 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
          }
        }
        if( actor == 5045957 || actorId == 5045957 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 5045960 || actorId == 5045960 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        if( actor == 5045961 || actorId == 5045961 ) // ENEMY5 = unknown
        {
          // empty entry
        }
        if( actor == 5046024 || actorId == 5046024 ) // EVENTRANGE2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
          }
        }
        if( actor == 5046029 || actorId == 5046029 ) // ENEMY6 = unknown
        {
          // empty entry
        }
        if( actor == 5046030 || actorId == 5046030 ) // ENEMY7 = unknown
        {
          // empty entry
        }
        if( actor == 5046031 || actorId == 5046031 ) // ENEMY8 = unknown
        {
          // empty entry
        }
        if( actor == 5046034 || actorId == 5046034 ) // EVENTRANGE3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 5 )
          {
            Scene00017( player ); // Scene00017: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 5046037 || actorId == 5046037 ) // ENEMY9 = unknown
        {
          // empty entry
        }
        if( actor == 5046039 || actorId == 5046039 ) // ENEMY10 = unknown
        {
          // empty entry
        }
        if( actor == 5046040 || actorId == 5046040 ) // ENEMY11 = unknown
        {
          // empty entry
        }
        if( actor == 5046042 || actorId == 5046042 ) // ENEMY12 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( actor == 5046043 || actorId == 5046043 ) // ENEMY13 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          // +Callback Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 2004644 || actorId == 2004644 ) // EOBJECT1 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          // +Callback Scene00023: Normal(None), id=unknown
        }
        if( actor == 2004645 || actorId == 2004645 ) // EOBJECT2 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          // +Callback Scene00025: Normal(Message, PopBNpc), id=unknown
        }
        if( actor == 2004646 || actorId == 2004646 ) // EOBJECT3 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          // +Callback Scene00027: Normal(None), id=unknown
        }
        if( actor == 1009967 || actorId == 1009967 ) // ACTOR8 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          // +Callback Scene00029: Normal(None), id=unknown
        }
        if( actor == 1009968 || actorId == 1009968 ) // ACTOR9 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          // +Callback Scene00031: Normal(None), id=unknown
          // +Callback Scene00032: Normal(None), id=unknown
        }
        if( actor == 1009969 || actorId == 1009969 ) // ACTOR10 = ALIANNE
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          // +Callback Scene00034: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( actor == 1009970 || actorId == 1009970 ) // ACTOR11 = CRYSTALSOLDIER00053
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          // +Callback Scene00036: Normal(Talk, TargetCanMove), id=CRYSTALSOLDIER00053
        }
        if( actor == 1009971 || actorId == 1009971 ) // ACTOR12 = RHESHPOLAALI
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          // +Callback Scene00038: Normal(Talk, TargetCanMove), id=RHESHPOLAALI
        }
        break;
      }
      case 5:
      {
        Scene00039( player ); // Scene00039: Normal(Talk, NpcDespawn, TargetCanMove), id=ALIANNE
        break;
      }
      case 255:
      {
        Scene00040( player ); // Scene00040: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 4 );
      }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8BH( getId() ) == 5 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 5 );
        }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00003: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00006: Normal(Talk, TargetCanMove), id=CRYSTALSOLDIER00053" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00009: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00011: Normal(Talk, Message, TargetCanMove), id=RHESHPOLAALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=RHESHPOLAALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00014: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00015: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 3 );
    checkProgressSeq4( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 3 );
    checkProgressSeq4( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00017: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 5 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00019: Normal(None), id=unknown" );
    Scene00020( player );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchChain]Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00022: Normal(None), id=unknown" );
    Scene00023( player );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00023: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00024: Normal(None), id=unknown" );
    Scene00025( player );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00026: Normal(None), id=unknown" );
    Scene00027( player );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00027: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00028: Normal(None), id=unknown" );
    Scene00029( player );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00030: Normal(None), id=unknown" );
    Scene00031( player );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00031: Normal(None), id=unknown" );
    Scene00032( player );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchChain]Scene00032: Normal(None), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00033: Normal(None), id=unknown" );
    Scene00034( player );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00034: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00035: Normal(None), id=unknown" );
    Scene00036( player );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00036: Normal(Talk, TargetCanMove), id=CRYSTALSOLDIER00053" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00037: Normal(None), id=unknown" );
    Scene00038( player );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling [BranchTrue]Scene00038: Normal(Talk, TargetCanMove), id=RHESHPOLAALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00039: Normal(Talk, NpcDespawn, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00040: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 40, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUse402 );
