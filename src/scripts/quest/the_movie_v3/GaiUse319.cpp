// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_39 = MINFILIA
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse319 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse319() : Sapphire::ScriptAPI::EventScript( 66996 ){}; 
  ~GaiUse319() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 9 entries
  //SEQ_3, 9 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1006530
  //ACTOR1 = 1008997
  //ACTOR10 = 1009021
  //ACTOR11 = 1008969
  //ACTOR2 = 1009141
  //ACTOR3 = 1009142
  //ACTOR4 = 1009143
  //ACTOR5 = 1009144
  //ACTOR6 = 1009145
  //ACTOR7 = 1009146
  //ACTOR8 = 1009147
  //ACTOR9 = 1009148
  //BGMNOTHING = 1
  //CUTSCENEN01 = 539
  //CUTSCENEN02 = 540
  //CUTSCENEN03 = 543
  //CUTSCENEN04 = 544
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001315

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLAFBORN
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( actor == 1008997 || actorId == 1008997 ) // ACTOR1 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=TATARU
          }
        }
        if( actor == 1006530 || actorId == 1006530 ) // ACTOR0 = SLAFBORN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=SLAFBORN
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( actor == 1009141 || actorId == 1009141 ) // ACTOR2 = RIOL
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=RIOL
          }
          else
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RIOL
          }
        }
        if( actor == 1009142 || actorId == 1009142 ) // ACTOR3 = WILRED
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00007( player ); // Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=WILRED
          }
          else
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=WILRED
          }
        }
        if( actor == 1009143 || actorId == 1009143 ) // ACTOR4 = LAURENTIUS
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00010( player ); // Scene00010: NpcTrade(Talk), id=unknown
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=LAURENTIUS
          }
          else
          {
            Scene00012( player ); // Scene00012: Normal(Talk), id=LAURENTIUS
          }
        }
        if( actor == 1009144 || actorId == 1009144 ) // ACTOR5 = ALIANNE
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00013( player ); // Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=ALIANNE
          }
          else
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALIANNE
          }
        }
        if( actor == 1009145 || actorId == 1009145 ) // ACTOR6 = AERGMHUS
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00016( player ); // Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00017: Normal(Talk, TargetCanMove), id=AERGMHUS
          }
          else
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=AERGMHUS
          }
        }
        if( actor == 1009146 || actorId == 1009146 ) // ACTOR7 = EPHEMIE
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00019( player ); // Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00020: Normal(Talk, TargetCanMove), id=EPHEMIE
          }
          else
          {
            Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=EPHEMIE
          }
        }
        if( actor == 1009147 || actorId == 1009147 ) // ACTOR8 = YUYUHASE
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00022( player ); // Scene00022: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=YUYUHASE
          }
          else
          {
            Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YUYUHASE
          }
        }
        if( actor == 1009148 || actorId == 1009148 ) // ACTOR9 = ILBERD
        {
          if( player.getQuestUI8AL( getId() ) != 8 )
          {
            Scene00025( player ); // Scene00025: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00026: Normal(Talk, TargetCanMove), id=ILBERD
          }
          else
          {
            Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ILBERD
          }
        }
        if( actor == 1008997 || actorId == 1008997 ) // ACTOR1 = TATARU
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 3:
      {
        if( actor == 1009021 || actorId == 1009021 ) // ACTOR10 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00030: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1009141 || actorId == 1009141 ) // ACTOR2 = RIOL
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=RIOL
        }
        if( actor == 1009142 || actorId == 1009142 ) // ACTOR3 = WILRED
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=WILRED
        }
        if( actor == 1009143 || actorId == 1009143 ) // ACTOR4 = LAURENTIUS
        {
          Scene00033( player ); // Scene00033: Normal(Talk), id=LAURENTIUS
        }
        if( actor == 1009144 || actorId == 1009144 ) // ACTOR5 = ALIANNE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( actor == 1009145 || actorId == 1009145 ) // ACTOR6 = AERGMHUS
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=AERGMHUS
        }
        if( actor == 1009146 || actorId == 1009146 ) // ACTOR7 = EPHEMIE
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=EPHEMIE
        }
        if( actor == 1009147 || actorId == 1009147 ) // ACTOR8 = YUYUHASE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=YUYUHASE
        }
        if( actor == 1009148 || actorId == 1009148 ) // ACTOR9 = ILBERD
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=ILBERD
        }
        break;
      }
      case 255:
      {
        Scene00039( player ); // Scene00039: Normal(CutScene), id=MINFILIA
        // +Callback Scene00040: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        // +Callback Scene00041: Normal(CutScene), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 8 )
      if( player.getQuestUI8AL( getId() ) == 8 )
        if( player.getQuestUI8AL( getId() ) == 8 )
          if( player.getQuestUI8AL( getId() ) == 8 )
            if( player.getQuestUI8AL( getId() ) == 8 )
              if( player.getQuestUI8AL( getId() ) == 8 )
                if( player.getQuestUI8AL( getId() ) == 8 )
                  if( player.getQuestUI8AL( getId() ) == 8 )
                  {
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8BH( getId(), 0 );
                    player.updateQuest( getId(), 3 );
                  }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00002: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00003: Normal(Talk, TargetCanMove), id=SLAFBORN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00005( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchFalse]Scene00006: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00007: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00008( player );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00008: Normal(Talk, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchFalse]Scene00009: Normal(Talk, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00010: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00011: Normal(Talk, TargetCanMove), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchFalse]Scene00012: Normal(Talk), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00013: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00014: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchFalse]Scene00015: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00016: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00017( player );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00017: Normal(Talk, TargetCanMove), id=AERGMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchFalse]Scene00018: Normal(Talk, TargetCanMove), id=AERGMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00019: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00020( player );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00020: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchFalse]Scene00021: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00022: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00023( player );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00023: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchFalse]Scene00024: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00025: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00026( player );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00026: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchFalse]Scene00027: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00028: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00029: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00030( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00030: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00031: Normal(Talk, TargetCanMove), id=RIOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00032: Normal(Talk, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00033: Normal(Talk), id=LAURENTIUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00034: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00035: Normal(Talk, TargetCanMove), id=AERGMHUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00036: Normal(Talk, TargetCanMove), id=EPHEMIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00037: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00038: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling Scene00039: Normal(CutScene), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00040( player );
    };
    player.playScene( getId(), 39, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchTrue]Scene00040: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00041( player );
      }
    };
    player.playScene( getId(), 40, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUse319:66996 calling [BranchChain]Scene00041: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUse319 );
