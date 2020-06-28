// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse308 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse308() : Sapphire::ScriptAPI::EventScript( 66985 ){}; 
  ~GaiUse308() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 6 entries
  //SEQ_5, 7 entries
  //SEQ_6, 5 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTCRY = 956
  //ACTIONTIMELINEEVENTJOYBIG = 945
  //ACTIONTIMELINEEVENTLAUGH = 952
  //ACTIONTIMELINEEVENTSAD = 954
  //ACTOR0 = 1009097
  //ACTOR1 = 1009100
  //ACTOR2 = 1009101
  //ACTOR3 = 1009102
  //ACTOR4 = 1009098
  //ACTOR5 = 1009103
  //ACTOR6 = 1000580
  //ACTOR7 = 1009104
  //ACTOR8 = 1009099
  //EOBJECT0 = 2004139
  //EOBJECT1 = 2004140
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001310
  //ITEM1 = 2001311
  //LOCACTOR0 = 1009667
  //LOCACTOR1 = 1146516
  //LOCVFX01 = 293
  //STATUS0 = 416

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LIEUTENANT01448
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( actor == 1009100 || actorId == 1009100 ) // ACTOR1 = NAMIDA01449
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00002( player ); // Scene00002: Normal(Inventory), id=unknown
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=NAMIDA01449
          }
          else
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=NAMIDA01449
          }
        }
        if( actor == 1009101 || actorId == 1009101 ) // ACTOR2 = MODAE01449
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: Normal(Inventory), id=unknown
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=MODAE01449
          }
          else
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=MODAE01449
          }
        }
        if( actor == 1009102 || actorId == 1009102 ) // ACTOR3 = SEKI01449
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(Inventory), id=unknown
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=SEKI01449
          }
          else
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=SEKI01449
          }
        }
        if( actor == 1009098 || actorId == 1009098 ) // ACTOR4 = MAXIO
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MAXIO
        }
        if( actor == 1009103 || actorId == 1009103 ) // ACTOR5 = TEMPEREDSYLPH01449
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=TEMPEREDSYLPH01449
        }
        if( actor == 2004139 || actorId == 2004139 ) // EOBJECT0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1000580 || actorId == 1000580 ) // ACTOR6 = KOMUXIO
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=KOMUXIO
        }
        break;
      }
      case 2:
      {
        if( actor == 1009103 || actorId == 1009103 ) // ACTOR5 = TEMPEREDSYLPH01449
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=TEMPEREDSYLPH01449
          }
        }
        if( actor == 1009100 || actorId == 1009100 ) // ACTOR1 = NAMIDA01449
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=NAMIDA01449
        }
        if( actor == 1009101 || actorId == 1009101 ) // ACTOR2 = MODAE01449
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=MODAE01449
        }
        if( actor == 1009102 || actorId == 1009102 ) // ACTOR3 = SEKI01449
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=SEKI01449
        }
        if( actor == 1009098 || actorId == 1009098 ) // ACTOR4 = MAXIO
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MAXIO
        }
        if( actor == 2004139 || actorId == 2004139 ) // EOBJECT0 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack ?
      case 3:
      {
        if( actor == 1009098 || actorId == 1009098 ) // ACTOR4 = MAXIO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=MAXIO
          }
        }
        if( actor == 1009100 || actorId == 1009100 ) // ACTOR1 = NAMIDA01449
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=NAMIDA01449
        }
        if( actor == 1009101 || actorId == 1009101 ) // ACTOR2 = MODAE01449
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MODAE01449
        }
        if( actor == 1009102 || actorId == 1009102 ) // ACTOR3 = SEKI01449
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=SEKI01449
        }
        if( actor == 1009104 || actorId == 1009104 ) // ACTOR7 = TEMPEREDSYLPH01449
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TEMPEREDSYLPH01449
        }
        if( actor == 2004139 || actorId == 2004139 ) // EOBJECT0 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM1 = UI8BH max stack ?
      case 4:
      {
        if( actor == 1009098 || actorId == 1009098 ) // ACTOR4 = MAXIO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=MAXIO
          }
        }
        if( actor == 1009100 || actorId == 1009100 ) // ACTOR1 = NAMIDA01449
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=NAMIDA01449
        }
        if( actor == 1009101 || actorId == 1009101 ) // ACTOR2 = MODAE01449
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=MODAE01449
        }
        if( actor == 1009102 || actorId == 1009102 ) // ACTOR3 = SEKI01449
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=SEKI01449
        }
        if( actor == 1009104 || actorId == 1009104 ) // ACTOR7 = TEMPEREDSYLPH01449
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=TEMPEREDSYLPH01449
        }
        if( actor == 2004139 || actorId == 2004139 ) // EOBJECT0 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        break;
      }
      //seq 5 event item ITEM1 = UI8BH max stack ?
      case 5:
      {
        if( actor == 1009104 || actorId == 1009104 ) // ACTOR7 = TEMPEREDSYLPH01449
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00033( player ); // Scene00033: Normal(Talk, Inventory, TargetCanMove), id=TEMPEREDSYLPH01449
            // +Callback Scene00034: Normal(Talk, NpcDespawn, TargetCanMove), id=TEMPEREDSYLPH01449
          }
        }
        if( actor == 1009098 || actorId == 1009098 ) // ACTOR4 = MAXIO
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=MAXIO
        }
        if( actor == 1009100 || actorId == 1009100 ) // ACTOR1 = NAMIDA01449
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=NAMIDA01449
        }
        if( actor == 1009101 || actorId == 1009101 ) // ACTOR2 = MODAE01449
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=MODAE01449
        }
        if( actor == 1009102 || actorId == 1009102 ) // ACTOR3 = SEKI01449
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=SEKI01449
        }
        if( actor == 2004139 || actorId == 2004139 ) // EOBJECT0 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
        }
        if( actor == 2004140 || actorId == 2004140 ) // EOBJECT1 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(Message), id=unknown
        }
        break;
      }
      case 6:
      {
        if( actor == 1009099 || actorId == 1009099 ) // ACTOR8 = MAXIO
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=MAXIO
          }
        }
        if( actor == 1009100 || actorId == 1009100 ) // ACTOR1 = NAMIDA01449
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=NAMIDA01449
        }
        if( actor == 1009101 || actorId == 1009101 ) // ACTOR2 = MODAE01449
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=MODAE01449
        }
        if( actor == 1009102 || actorId == 1009102 ) // ACTOR3 = SEKI01449
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=SEKI01449
        }
        if( actor == 2004139 || actorId == 2004139 ) // EOBJECT0 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1009100 || actorId == 1009100 ) // ACTOR1 = NAMIDA01449
        {
          Scene00046( player ); // Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=NAMIDA01449
        }
        if( actor == 1009101 || actorId == 1009101 ) // ACTOR2 = MODAE01449
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=MODAE01449
        }
        if( actor == 1009102 || actorId == 1009102 ) // ACTOR3 = SEKI01449
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=SEKI01449
        }
        if( actor == 1009099 || actorId == 1009099 ) // ACTOR8 = MAXIO
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=MAXIO
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

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse308:66985 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LIEUTENANT01448" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00002: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling [BranchTrue]Scene00003: Normal(Talk, TargetCanMove), id=NAMIDA01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling [BranchFalse]Scene00004: Normal(Talk, TargetCanMove), id=NAMIDA01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00005: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling [BranchTrue]Scene00006: Normal(Talk, TargetCanMove), id=MODAE01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling [BranchFalse]Scene00007: Normal(Talk, TargetCanMove), id=MODAE01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00008: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling [BranchTrue]Scene00009: Normal(Talk, TargetCanMove), id=SEKI01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling [BranchFalse]Scene00010: Normal(Talk, TargetCanMove), id=SEKI01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00011: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00012: Normal(Talk, TargetCanMove), id=TEMPEREDSYLPH01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00014: Normal(Talk, TargetCanMove), id=KOMUXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00015: Normal(Talk, NpcDespawn, TargetCanMove), id=TEMPEREDSYLPH01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00016: Normal(Talk, TargetCanMove), id=NAMIDA01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00017: Normal(Talk, TargetCanMove), id=MODAE01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00018: Normal(Talk, TargetCanMove), id=SEKI01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00019: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00021: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00022: Normal(Talk, TargetCanMove), id=NAMIDA01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00023: Normal(Talk, TargetCanMove), id=MODAE01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00024: Normal(Talk, TargetCanMove), id=SEKI01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00025: Normal(Talk, TargetCanMove), id=TEMPEREDSYLPH01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00026: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00027: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00028: Normal(Talk, TargetCanMove), id=NAMIDA01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00029: Normal(Talk, TargetCanMove), id=MODAE01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00030: Normal(Talk, TargetCanMove), id=SEKI01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00031: Normal(Talk, TargetCanMove), id=TEMPEREDSYLPH01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00032: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00033: Normal(Talk, Inventory, TargetCanMove), id=TEMPEREDSYLPH01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00034( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling [BranchTrue]Scene00034: Normal(Talk, NpcDespawn, TargetCanMove), id=TEMPEREDSYLPH01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00035: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00036: Normal(Talk, TargetCanMove), id=NAMIDA01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00037: Normal(Talk, TargetCanMove), id=MODAE01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00038: Normal(Talk, TargetCanMove), id=SEKI01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00039: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00040: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00041: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00042: Normal(Talk, TargetCanMove), id=NAMIDA01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00043: Normal(Talk, TargetCanMove), id=MODAE01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00044: Normal(Talk, TargetCanMove), id=SEKI01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00045: Normal(None), id=unknown" );
    checkProgressSeq6( player );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=NAMIDA01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00047: Normal(Talk, TargetCanMove), id=MODAE01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00048: Normal(Talk, TargetCanMove), id=SEKI01449" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUse308:66985 calling Scene00049: Normal(Talk, TargetCanMove), id=MAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse308 );