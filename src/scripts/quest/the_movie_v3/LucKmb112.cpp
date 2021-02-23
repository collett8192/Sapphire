// FFXIVTheMovie.ParserV3.2
// id hint used:
//EVENTRANGE1 = dummyr1
//SCENE_14 = dummyr1
//SCENE_15 = dummyr1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb112 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb112() : Sapphire::ScriptAPI::EventScript( 68849 ){}; 
  ~LucKmb112() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 8 entries
  //SEQ_4, 14 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTADDLOOKLR = 5522
  //ACTIONTIMELINEEVENTMAGIC = 969
  //ACTIONTIMELINEEVENTTALKYES = 5627
  //ACTOR0 = 1029162
  //ACTOR1 = 1029163
  //ACTOR10 = 1030584
  //ACTOR11 = 1030585
  //ACTOR12 = 1029562
  //ACTOR13 = 1029563
  //ACTOR2 = 1029164
  //ACTOR3 = 1030577
  //ACTOR4 = 1030578
  //ACTOR5 = 1030579
  //ACTOR6 = 1030580
  //ACTOR7 = 1030581
  //ACTOR8 = 1030582
  //ACTOR9 = 1030583
  //BINDACTOR0 = 8004112
  //BINDACTOR1 = 8004113
  //BINDACTOR2 = 7922442
  //EOBJECT0 = 2010295
  //EOBJECT1 = 2010296
  //EVENTRANGE0 = 7959768
  //EVENTRANGE1 = 7955774
  //EVENTRANGE2 = 7955778
  //EVENTRANGE3 = 7955793
  //EVENTRANGE4 = 7955811
  //EVENTRANGE5 = 7955815
  //EVENTRANGE6 = 7955818
  //EVENTRANGE7 = 7955819
  //EVENTRANGE8 = 7955821
  //INVISACTOR0 = 1027674
  //INVISACTOR1 = 1027683
  //LCUTACTOR0 = 1029367
  //LCUTACTOR1 = 1026570
  //LCUTACTOR2 = 1026569
  //LCUTACTOR3 = 1026572
  //LCUTACTOR4 = 1029368
  //LCUTACTOR5 = 1029369
  //LCUTBGM0 = 573
  //LCUTPOS0 = 7955766
  //LCUTPOS1 = 8006590
  //LCUTPOS2 = 7956866
  //LCUTPOSHINT1 = 7956136
  //LCUTPOSHINT2 = 7956137
  //LCUTPOSHINT3 = 7956139
  //LCUTVFX0 = 300
  //POPRANGE0 = 7955841
  //POPRANGE1 = 7922513
  //STATUS0 = 1151

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029162 || param2 == 1029162 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029163 || param2 == 1029163 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029164 || param2 == 1029164 ) // ACTOR2 = RYNE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER
        break;
      }
      case 2:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, AutoFadeIn), id=unknown
        break;
      }
      case 3:
      {
        if( param1 == 1030579 || param2 == 1030579 ) // ACTOR5 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=URIANGER
          }
          break;
        }
        if( param1 == 1030580 || param2 == 1030580 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030581 || param2 == 1030581 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030582 || param2 == 1030582 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030583 || param2 == 1030583 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030584 || param2 == 1030584 ) // ACTOR10 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030585 || param2 == 1030585 ) // ACTOR11 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 7959768 || param2 == 7959768 ) // EVENTRANGE0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 7955774 || param2 == 7955774 ) // EVENTRANGE1 = dummyr1
        {
          Scene00015( player ); // Scene00015: Normal(Message), id=dummyr1
          break;
        }
        if( param1 == 7955778 || param2 == 7955778 ) // EVENTRANGE2 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 7955818 || param2 == 7955818 ) // EVENTRANGE6 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 7955819 || param2 == 7955819 ) // EVENTRANGE7 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 7955821 || param2 == 7955821 ) // EVENTRANGE8 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 2010295 || param2 == 2010295 ) // EOBJECT0 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010296 || param2 == 2010296 ) // EOBJECT1 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030579 || param2 == 1030579 ) // ACTOR5 = URIANGER
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030580 || param2 == 1030580 ) // ACTOR6 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030581 || param2 == 1030581 ) // ACTOR7 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030582 || param2 == 1030582 ) // ACTOR8 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030583 || param2 == 1030583 ) // ACTOR9 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030584 || param2 == 1030584 ) // ACTOR10 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030585 || param2 == 1030585 ) // ACTOR11 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029562 || param2 == 1029562 ) // ACTOR12 = THANCRED
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=THANCRED
          // +Callback Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete, Menu, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1029563 || param2 == 1029563 ) // ACTOR13 = RYNE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=RYNE
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmb112:68849 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00003: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00005: Normal(Talk, FadeIn, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00006: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00013: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00015: Normal(Message), id=dummyr1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00017: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00018: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00019: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00022: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00024: Normal(None), id=unknown" );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00029: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00030( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete, Menu, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
          player.eventFinish( getId(), 1 );
          player.forceZoneing();
        }
      }
    };
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmb112:68849 calling Scene00031: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb112 );
