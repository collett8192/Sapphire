// FFXIVTheMovie.ParserV3
// id hint used:
//EOBJECT0 = dummy0
//EOBJECT1 = dummy1
//EOBJECT2 = dummy2
//EOBJECT3 = dummy3
//SCENE_8 = dummy0
//SCENE_10 = dummy1
//SCENE_12 = dummy2
//SCENE_24 = dummy3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna702 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna702() : Sapphire::ScriptAPI::EventScript( 67200 ){}; 
  ~HeaVna702() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 8 entries
  //SEQ_2, 5 entries
  //SEQ_3, 6 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1012792
  //ACTOR1 = 1013268
  //ACTOR10 = 1013266
  //ACTOR11 = 1015137
  //ACTOR12 = 1015135
  //ACTOR13 = 1015136
  //ACTOR14 = 1015134
  //ACTOR2 = 1012789
  //ACTOR3 = 1012790
  //ACTOR4 = 1012791
  //ACTOR5 = 1012793
  //ACTOR6 = 1014675
  //ACTOR7 = 1013267
  //ACTOR8 = 1013264
  //ACTOR9 = 1013265
  //CUTSCENEN01 = 891
  //CUTSCENEN02 = 892
  //EOBJECT0 = 2006236
  //EOBJECT1 = 2006237
  //EOBJECT2 = 2006238
  //EOBJECT3 = 2005565
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //LOCACTOR0 = 5867072
  //LOCACTOR1 = 5867073
  //LOCACTOR10 = 5867471
  //LOCACTOR11 = 5867474
  //LOCACTOR12 = 5867472
  //LOCACTOR2 = 5867074
  //LOCACTOR20 = 5938230
  //LOCACTOR21 = 5938226
  //LOCACTOR3 = 5867076
  //LOCACTOR4 = 5867468
  //LOCQUEST0 = 66849
  //POPRANGE0 = 5932751

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012792 || actorId == 1012792 ) // ACTOR0 = CID
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CID
        }
        if( actor == 1013268 || actorId == 1013268 ) // ACTOR1 = WEDGE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1012789 || actorId == 1012789 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012790 || actorId == 1012790 ) // ACTOR3 = ESTINIEN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012791 || actorId == 1012791 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1012793 || actorId == 1012793 ) // ACTOR5 = BIGGS
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=BIGGS
        }
        break;
      }
      case 1:
      {
        if( actor == 2006236 || actorId == 2006236 ) // EOBJECT0 = dummy0
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
            // +Callback Scene00008: Normal(Talk), id=dummy0
          }
        }
        if( actor == 2006237 || actorId == 2006237 ) // EOBJECT1 = dummy1
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(None), id=unknown
            // +Callback Scene00010: Normal(Talk), id=dummy1
          }
        }
        if( actor == 2006238 || actorId == 2006238 ) // EOBJECT2 = dummy2
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
            // +Callback Scene00012: Normal(Talk), id=dummy2
          }
        }
        if( actor == 1014675 || actorId == 1014675 ) // ACTOR6 = CID
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1013267 || actorId == 1013267 ) // ACTOR7 = BIGGS
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1013264 || actorId == 1013264 ) // ACTOR8 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013265 || actorId == 1013265 ) // ACTOR9 = ESTINIEN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013266 || actorId == 1013266 ) // ACTOR10 = YSHTOLA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 2:
      {
        if( actor == 1014675 || actorId == 1014675 ) // ACTOR6 = CID
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=CID
          }
        }
        if( actor == 1013267 || actorId == 1013267 ) // ACTOR7 = BIGGS
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1013264 || actorId == 1013264 ) // ACTOR8 = ALPHINAUD
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013265 || actorId == 1013265 ) // ACTOR9 = ESTINIEN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013266 || actorId == 1013266 ) // ACTOR10 = YSHTOLA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 3:
      {
        if( actor == 2005565 || actorId == 2005565 ) // EOBJECT3 = dummy3
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00023( player ); // Scene00023: Normal(None), id=unknown
            // +Callback Scene00024: Normal(CutScene), id=dummy3
          }
        }
        if( actor == 1014675 || actorId == 1014675 ) // ACTOR6 = CID
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1013267 || actorId == 1013267 ) // ACTOR7 = BIGGS
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1013264 || actorId == 1013264 ) // ACTOR8 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013265 || actorId == 1013265 ) // ACTOR9 = ESTINIEN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013266 || actorId == 1013266 ) // ACTOR10 = YSHTOLA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 255:
      {
        if( actor == 1014675 || actorId == 1014675 ) // ACTOR6 = CID
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=CID
          // +Callback Scene00031: Normal(CutScene), id=unknown
          // +Callback Scene00032: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1015137 || actorId == 1015137 ) // ACTOR11 = GUIDANCESYSTEM
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
        }
        if( actor == 1015135 || actorId == 1015135 ) // ACTOR12 = BIGGS
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1015136 || actorId == 1015136 ) // ACTOR13 = WEDGE
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1015134 || actorId == 1015134 ) // ACTOR14 = ALPHINAUD
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1013265 || actorId == 1013265 ) // ACTOR9 = ESTINIEN
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013266 || actorId == 1013266 ) // ACTOR10 = YSHTOLA
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=YSHTOLA
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna702:67200 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00002: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00004: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00006: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling [BranchTrue]Scene00008: Normal(Talk), id=dummy0" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling [BranchTrue]Scene00010: Normal(Talk), id=dummy1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling [BranchTrue]Scene00012: Normal(Talk), id=dummy2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00013: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00014: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00016: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00017: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00018: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00019: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00020: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00021: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00022: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00023: Normal(None), id=unknown" );
    Scene00024( player );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling [BranchTrue]Scene00024: Normal(CutScene), id=dummy3" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 402, -643.7, -176.4, -576.5, 2.65 );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00025: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00026: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00028: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00030: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00031( player );
    };
    player.playScene( getId(), 30, NONE, callback );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling [BranchTrue]Scene00031: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00032( player );
    };
    player.playScene( getId(), 31, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling [BranchChain]Scene00032: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00033: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00034: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00035: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00037: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVna702:67200 calling Scene00038: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna702 );
