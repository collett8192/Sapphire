// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_15 = GUIDANCESYSTEM
//fix: teleport device
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna703 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna703() : Sapphire::ScriptAPI::EventScript( 67201 ){}; 
  ~HeaVna703() = default; 

  //SEQ_0, 7 entries
  //SEQ_1, 6 entries
  //SEQ_2, 7 entries
  //SEQ_3, 8 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1012796
  //ACTOR1 = 1014675
  //ACTOR10 = 1012800
  //ACTOR11 = 1012802
  //ACTOR12 = 1012803
  //ACTOR13 = 1012804
  //ACTOR14 = 1012805
  //ACTOR2 = 1014676
  //ACTOR3 = 1012795
  //ACTOR4 = 1014677
  //ACTOR5 = 1014678
  //ACTOR6 = 1014679
  //ACTOR7 = 1012797
  //ACTOR8 = 1012798
  //ACTOR9 = 1012799
  //CUTSCENEN01 = 1019
  //CUTSCENEN02 = 1037
  //EOBJECT0 = 2006363
  //LOCACTOR0 = 5916698
  //LOCACTOR1 = 5916699
  //LOCACTOR10 = 5867519
  //LOCACTOR11 = 5867523
  //LOCACTOR12 = 5867521
  //LOCACTOR2 = 5916695
  //LOCACTOR3 = 5916696
  //LOCACTOR4 = 5867476
  //POPRANGE0 = 5890159

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012796 || actorId == 1012796 ) // ACTOR0 = GUIDANCESYSTEM
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM
        }
        if( actor == 1014675 || actorId == 1014675 ) // ACTOR1 = CID
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1014676 || actorId == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1012795 || actorId == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=WEDGE
        }
        if( actor == 1014677 || actorId == 1014677 ) // ACTOR4 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1014678 || actorId == 1014678 ) // ACTOR5 = ESTINIEN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1014679 || actorId == 1014679 ) // ACTOR6 = YSHTOLA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 1:
      {
        if( actor == 1014677 || actorId == 1014677 ) // ACTOR4 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1014678 || actorId == 1014678 ) // ACTOR5 = ESTINIEN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1014679 || actorId == 1014679 ) // ACTOR6 = YSHTOLA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1014675 || actorId == 1014675 ) // ACTOR1 = CID
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1014676 || actorId == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1012795 || actorId == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=WEDGE
        }
        break;
      }
      case 2:
      {
        if( actor == 1012797 || actorId == 1012797 ) // ACTOR7 = GUIDANCESYSTEM
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
            // +Callback Scene00015: Normal(CutScene), id=GUIDANCESYSTEM
          }
        }
        if( actor == 1012798 || actorId == 1012798 ) // ACTOR8 = ALPHINAUD
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012799 || actorId == 1012799 ) // ACTOR9 = ESTINIEN
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012800 || actorId == 1012800 ) // ACTOR10 = YSHTOLA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1014675 || actorId == 1014675 ) // ACTOR1 = CID
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1014676 || actorId == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1012795 || actorId == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=WEDGE
        }
        break;
      }
      case 3:
      {
        if( actor == 2006363 || actorId == 2006363 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1012797 || actorId == 1012797 ) // ACTOR7 = GUIDANCESYSTEM
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM
        }
        if( actor == 1012798 || actorId == 1012798 ) // ACTOR8 = ALPHINAUD
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012799 || actorId == 1012799 ) // ACTOR9 = ESTINIEN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012800 || actorId == 1012800 ) // ACTOR10 = YSHTOLA
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1014675 || actorId == 1014675 ) // ACTOR1 = CID
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1014676 || actorId == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1012795 || actorId == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=WEDGE
        }
        break;
      }
      case 255:
      {
        if( actor == 1012802 || actorId == 1012802 ) // ACTOR11 = GUIDANCESYSTEM
        {
          Scene00030( player ); // Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUIDANCESYSTEM
        }
        if( actor == 1012803 || actorId == 1012803 ) // ACTOR12 = ALPHINAUD
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012804 || actorId == 1012804 ) // ACTOR13 = ESTINIEN
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012805 || actorId == 1012805 ) // ACTOR14 = YSHTOLA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1014675 || actorId == 1014675 ) // ACTOR1 = CID
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=CID
        }
        if( actor == 1014676 || actorId == 1014676 ) // ACTOR2 = BIGGS
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=BIGGS
        }
        if( actor == 1012795 || actorId == 1012795 ) // ACTOR3 = WEDGE
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=WEDGE
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
    player.sendDebug( "HeaVna703:67201 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna703:67201 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00002: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00003: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00004: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00006: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00007: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00009: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00011: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00012: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00013: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00014: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling [BranchTrue]Scene00015: Normal(CutScene), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00017: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00019: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00020: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00021: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00022: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 402, 214.35, -66, -615.7, 2.97 );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00023: Normal(Talk, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00024: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00025: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00026: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00027: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00028: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00029: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00030: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=GUIDANCESYSTEM" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00031: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00032: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00033: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00034: Normal(Talk, TargetCanMove), id=CID" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00035: Normal(Talk, TargetCanMove), id=BIGGS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVna703:67201 calling Scene00036: Normal(Talk, TargetCanMove), id=WEDGE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna703 );
