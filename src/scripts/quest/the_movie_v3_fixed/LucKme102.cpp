// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme102 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme102() : Sapphire::ScriptAPI::EventScript( 69167 ){}; 
  ~LucKme102() = default; 

  //SEQ_0, 13 entries
  //SEQ_1, 19 entries
  //SEQ_2, 2 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1030172
  //ACTOR1 = 1030171
  //ACTOR10 = 1030592
  //ACTOR11 = 1030593
  //ACTOR12 = 1030594
  //ACTOR13 = 1030179
  //ACTOR14 = 1030180
  //ACTOR15 = 1030181
  //ACTOR16 = 1030182
  //ACTOR17 = 1030183
  //ACTOR18 = 1030184
  //ACTOR19 = 1030185
  //ACTOR2 = 1030173
  //ACTOR20 = 1030186
  //ACTOR21 = 1030187
  //ACTOR22 = 1030188
  //ACTOR23 = 1030194
  //ACTOR24 = 1030195
  //ACTOR3 = 1030174
  //ACTOR4 = 1030175
  //ACTOR5 = 1030176
  //ACTOR6 = 1030177
  //ACTOR7 = 1030178
  //ACTOR8 = 1030590
  //ACTOR9 = 1030591
  //CUTSCENE0 = 2039
  //CUTSCENE1 = 2040
  //CUTSCENE2 = 2042
  //EOBJECT0 = 2010087
  //LOCACTION01 = 2
  //LOCACTOR01 = 1026567
  //LOCACTOR02 = 1026568
  //LOCACTOR03 = 1026569
  //LOCACTOR04 = 1026570
  //LOCACTOR05 = 1026571
  //LOCACTOR06 = 1027137
  //LOCACTOR07 = 1028187
  //LOCBGM01 = 662
  //POPRANGE0 = 7942183
  //QUESTBATTLE0 = 191
  //TERRITORYTYPE0 = 863
  //TERRITORYTYPE1 = 820

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030172 || param2 == 1030172 ) // ACTOR0 = unknown
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
          break;
        }
        if( param1 == 1030171 || param2 == 1030171 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030173 || param2 == 1030173 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030174 || param2 == 1030174 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030175 || param2 == 1030175 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030176 || param2 == 1030176 ) // ACTOR5 = RESIDENT03630
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RESIDENT03630
          break;
        }
        if( param1 == 1030177 || param2 == 1030177 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030178 || param2 == 1030178 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030590 || param2 == 1030590 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030591 || param2 == 1030591 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030592 || param2 == 1030592 ) // ACTOR10 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030593 || param2 == 1030593 ) // ACTOR11 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030594 || param2 == 1030594 ) // ACTOR12 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030179 || param2 == 1030179 ) // ACTOR13 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1030171 || param2 == 1030171 ) // ACTOR1 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1030172 || param2 == 1030172 ) // ACTOR0 = THANCRED
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030173 || param2 == 1030173 ) // ACTOR2 = URIANGER
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030174 || param2 == 1030174 ) // ACTOR3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030175 || param2 == 1030175 ) // ACTOR4 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030176 || param2 == 1030176 ) // ACTOR5 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030177 || param2 == 1030177 ) // ACTOR6 = RESIDENT03630
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=RESIDENT03630
          break;
        }
        if( param1 == 1030178 || param2 == 1030178 ) // ACTOR7 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030180 || param2 == 1030180 ) // ACTOR14 = ALISAIE
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030181 || param2 == 1030181 ) // ACTOR15 = YSHTOLA
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030182 || param2 == 1030182 ) // ACTOR16 = RYNE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030183 || param2 == 1030183 ) // ACTOR17 = KAISHIRR
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 2010087 || param2 == 2010087 ) // EOBJECT0 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030590 || param2 == 1030590 ) // ACTOR8 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030591 || param2 == 1030591 ) // ACTOR9 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030592 || param2 == 1030592 ) // ACTOR10 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030593 || param2 == 1030593 ) // ACTOR11 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030594 || param2 == 1030594 ) // ACTOR12 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00035( player ); // Scene00035: Normal(CutScene, AutoFadeIn), id=unknown
          break;
        }
        if( param1 == 1030179 || param2 == 1030179 ) // ACTOR13 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030184 || param2 == 1030184 ) // ACTOR18 = THANCRED
        {
          Scene00037( player ); // Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=THANCRED
          break;
        }
        if( param1 == 1030185 || param2 == 1030185 ) // ACTOR19 = ALPHINAUD
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030186 || param2 == 1030186 ) // ACTOR20 = ALISAIE
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030187 || param2 == 1030187 ) // ACTOR21 = YSHTOLA
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030188 || param2 == 1030188 ) // ACTOR22 = URIANGER
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030194 || param2 == 1030194 ) // ACTOR23 = RYNE
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030195 || param2 == 1030195 ) // ACTOR24 = PATIENT03631
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=PATIENT03631
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKme102:69167 calling Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00006: Normal(Talk, TargetCanMove), id=RESIDENT03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00014: Normal(Talk, QuestBattle, YesNo, TargetCanMove, AutoFadeIn, CanCancel), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
        //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
        //player.eventFinish( getId(), 1 );
        //player.forceZoneing();
        Scene00035( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00015: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00016: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00017: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00021: Normal(Talk, TargetCanMove), id=RESIDENT03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00024: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00025: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00026: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00027: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00029: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00034: Normal(Talk, FadeIn, Dismount, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00035: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
      //player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 820, 0, 82.83, 48.75, -3.14, false );
    };
    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00037: Normal(Talk, QuestReward, QuestComplete, TargetCanMove, SystemTalk), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00038: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00039: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00040: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00041: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00042: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKme102:69167 calling Scene00043: Normal(Talk, TargetCanMove), id=PATIENT03631" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKme102 );
