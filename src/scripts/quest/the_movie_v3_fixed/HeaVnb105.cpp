// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb105 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnb105() : Sapphire::ScriptAPI::EventScript( 67696 ){}; 
  ~HeaVnb105() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 2 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEFACIALCOMEON = 608
  //ACTOR0 = 1015998
  //ACTOR1 = 1015997
  //ACTOR2 = 1015999
  //ACTOR3 = 1011928
  //ACTOR4 = 1016002
  //ACTOR5 = 1016000
  //ACTOR6 = 1016001
  //ACTOR7 = 1016003
  //BINDACTOR1 = 6081170
  //BINDACTOR2 = 6082121
  //BINDACTOR3 = 6081179
  //BNPCNAME0 = 3574
  //BNPCNAME1 = 3573
  //CUTSCENEN01 = 1049
  //CUTSCENEN02 = 1050
  //CUTSCENEN03 = 1051
  //CUTSCENEN035 = 1098
  //CUTSCENEN04 = 1052
  //ENEMY0 = 6082114
  //ENEMY1 = 6082115
  //EOBJECT0 = 2006606
  //EOBJECT1 = 2006607
  //EVENTRANGE0 = 6082117
  //EVENTACTIONWAITINGSHOR = 11
  //LOCACTOR1 = 1011887
  //LOCACTOR2 = 1011889
  //LOCACTOR3 = 1015833
  //LOCACTOR4 = 1012458
  //POPRANGE0 = 6082257

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1015998 || param2 == 1015998 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1015997 || param2 == 1015997 ) // ACTOR1 = KRILE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1015999 || param2 == 1015999 ) // ACTOR2 = YSHTOLA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 1:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=VATHSTORYTELLER
        break;
      }
      case 2:
      {
        if( param1 == 6082117 || param2 == 6082117 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( param1 == 6082114 || param2 == 6082114 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( param1 == 6082115 || param2 == 6082115 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( param1 == 2006606 || param2 == 2006606 ) // EOBJECT0 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          // +Callback Scene00007: Normal(None), id=unknown
        }
        if( param1 == 1011928 || param2 == 1011928 ) // ACTOR3 = VATHSTORYTELLER
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          // +Callback Scene00009: Normal(Talk, TargetCanMove), id=VATHSTORYTELLER
        }
        break;
      }
      case 3:
      {
        if( param1 == 2006607 || param2 == 2006607 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
            // +Callback Scene00011: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1011928 || param2 == 1011928 ) // ACTOR3 = VATHSTORYTELLER
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=VATHSTORYTELLER
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016002 || param2 == 1016002 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(CutScene), id=unknown
          // +Callback Scene00014: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( param1 == 1016000 || param2 == 1016000 ) // ACTOR5 = ALPHINAUD
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016001 || param2 == 1016001 ) // ACTOR6 = YSHTOLA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016003 || param2 == 1016003 ) // ACTOR7 = KRILE
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1011928 || param2 == 1011928 ) // ACTOR3 = VATHSTORYTELLER
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=VATHSTORYTELLER
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
    if( player.getQuestUI8AL( getId() ) == 2 )
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
    player.sendDebug( "HeaVnb105:67696 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnb105:67696 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00002: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=VATHSTORYTELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling [BranchTrue]Scene00007: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling [BranchTrue]Scene00009: Normal(Talk, TargetCanMove), id=VATHSTORYTELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00010: Normal(None), id=unknown" );
    Scene00011( player );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling [BranchTrue]Scene00011: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 398, 223.3, -116.9, 507.2, 2.7 );
    };
    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00012: Normal(Talk, TargetCanMove), id=VATHSTORYTELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00013: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling [BranchTrue]Scene00014: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00015: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00017: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb105:67696 calling Scene00018: Normal(Talk, TargetCanMove), id=VATHSTORYTELLER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb105 );
