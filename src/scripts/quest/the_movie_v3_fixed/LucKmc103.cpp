// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc103 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc103() : Sapphire::ScriptAPI::EventScript( 68860 ){}; 
  ~LucKmc103() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 2 entries
  //SEQ_3, 5 entries
  //SEQ_4, 6 entries
  //SEQ_5, 5 entries
  //SEQ_6, 2 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1030889
  //ACTOR1 = 1028975
  //ACTOR10 = 1029183
  //ACTOR11 = 1029184
  //ACTOR12 = 1029185
  //ACTOR13 = 1029186
  //ACTOR14 = 1029187
  //ACTOR15 = 1029188
  //ACTOR16 = 1029189
  //ACTOR17 = 1029190
  //ACTOR18 = 1029191
  //ACTOR19 = 1029192
  //ACTOR2 = 1028979
  //ACTOR20 = 1029193
  //ACTOR3 = 1028303
  //ACTOR4 = 1029177
  //ACTOR5 = 1029178
  //ACTOR6 = 1029179
  //ACTOR7 = 1029180
  //ACTOR8 = 1029181
  //ACTOR9 = 1029182
  //EOBJECT0 = 2009862
  //EVENTACTION0 = 68
  //LOCACTION0 = 5618
  //LOCBINDACTOR0 = 7926558
  //LOCBINDACTOR1 = 7926559
  //LOCBINDACTOR2 = 7926564
  //LOCBINDACTOR3 = 7926565
  //LOCBINDACTOR4 = 7926566
  //LOCBINDACTOR5 = 7926568
  //LOCBINDACTOR6 = 7926569
  //LOCBINDACTOR7 = 7926570
  //NCUTEVENTLUCKMC10301 = 2002
  //NCUTEVENTLUCKMC10302 = 2003
  //NCUTEVENTLUCKMC10303 = 2004
  //POPRANGE0 = 7926739
  //POPRANGE1 = 7926696
  //TERRITORYTYPE0 = 817

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030889 || param2 == 1030889 ) // ACTOR0 = URIANGER
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1028975 || param2 == 1028975 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1028979 || param2 == 1028979 ) // ACTOR2 = RYNE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1028303 || param2 == 1028303 ) // ACTOR3 = MYRCANT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MYRCANT
          }
          break;
        }
        if( param1 == 1029177 || param2 == 1029177 ) // ACTOR4 = URIANGER
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029178 || param2 == 1029178 ) // ACTOR5 = THANCRED
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029179 || param2 == 1029179 ) // ACTOR6 = RYNE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00008( player ); // Scene00008: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1028303 || param2 == 1028303 ) // ACTOR3 = MYRCANT
        {
          Scene00009( player ); // Scene00009: Normal(Talk, YesNo, TargetCanMove), id=MYRCANT
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1029180 || param2 == 1029180 ) // ACTOR7 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER
          }
          break;
        }
        if( param1 == 1029181 || param2 == 1029181 ) // ACTOR8 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029182 || param2 == 1029182 ) // ACTOR9 = RYNE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029183 || param2 == 1029183 ) // ACTOR10 = EMETSELCH
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove, Menu), id=EMETSELCH
          break;
        }
        if( param1 == 1028303 || param2 == 1028303 ) // ACTOR3 = MYRCANT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=MYRCANT
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2009862 || param2 == 2009862 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1029184 || param2 == 1029184 ) // ACTOR11 = URIANGER
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029185 || param2 == 1029185 ) // ACTOR12 = THANCRED
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029186 || param2 == 1029186 ) // ACTOR13 = RYNE
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029187 || param2 == 1029187 ) // ACTOR14 = EMETSELCH
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=EMETSELCH
          break;
        }
        if( param1 == 1028303 || param2 == 1028303 ) // ACTOR3 = MYRCANT
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=MYRCANT
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1029188 || param2 == 1029188 ) // ACTOR15 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1029184 || param2 == 1029184 ) // ACTOR11 = URIANGER
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029185 || param2 == 1029185 ) // ACTOR12 = THANCRED
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029186 || param2 == 1029186 ) // ACTOR13 = RYNE
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1028303 || param2 == 1028303 ) // ACTOR3 = MYRCANT
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=MYRCANT
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1029189 || param2 == 1029189 ) // ACTOR16 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00027( player ); // Scene00027: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1028303 || param2 == 1028303 ) // ACTOR3 = MYRCANT
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=MYRCANT
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029190 || param2 == 1029190 ) // ACTOR17 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1029191 || param2 == 1029191 ) // ACTOR18 = URIANGER
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1029192 || param2 == 1029192 ) // ACTOR19 = THANCRED
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029193 || param2 == 1029193 ) // ACTOR20 = RYNE
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1028303 || param2 == 1028303 ) // ACTOR3 = MYRCANT
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=MYRCANT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
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
    player.sendDebug( "LucKmc103:68860 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc103:68860 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00003: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00004: Normal(Talk, TargetCanMove), id=MYRCANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 495, -720, 9.11, 681.26, 1.778, true );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00005: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00006: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00007: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00008: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00009: Normal(Talk, YesNo, TargetCanMove), id=MYRCANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.forceZoneing( 495, -720, 9.11, 681.26, 1.778, true );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00010: Normal(Talk, NpcDespawn, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00011: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00012: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00013: Normal(Talk, TargetCanMove, Menu), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00014: Normal(Talk, TargetCanMove), id=MYRCANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00016: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00017: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00018: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00019: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00020: Normal(Talk, TargetCanMove), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00021: Normal(Talk, TargetCanMove), id=MYRCANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00023: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00024: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00025: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00026: Normal(Talk, TargetCanMove), id=MYRCANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00027: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00028: Normal(Talk, TargetCanMove), id=MYRCANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00029: Normal(CutScene, FadeIn, QuestReward, QuestComplete, AutoFadeIn), id=unknown" );
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
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00030: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00031: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00032: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmc103:68860 calling Scene00033: Normal(Talk, TargetCanMove), id=MYRCANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc103 );
