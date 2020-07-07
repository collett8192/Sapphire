// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb107 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnb107() : Sapphire::ScriptAPI::EventScript( 67698 ){}; 
  ~HeaVnb107() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 14 entries
  //SEQ_2, 12 entries
  //SEQ_3, 11 entries
  //SEQ_4, 10 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1016008
  //ACTOR1 = 1016009
  //ACTOR10 = 1016025
  //ACTOR11 = 1016026
  //ACTOR12 = 1016015
  //ACTOR13 = 1016018
  //ACTOR14 = 1016019
  //ACTOR15 = 1016020
  //ACTOR16 = 1016016
  //ACTOR17 = 1016017
  //ACTOR18 = 1013167
  //ACTOR19 = 1016028
  //ACTOR2 = 1016010
  //ACTOR20 = 1016027
  //ACTOR21 = 1016031
  //ACTOR22 = 1016032
  //ACTOR23 = 1016033
  //ACTOR24 = 1016057
  //ACTOR25 = 1016059
  //ACTOR26 = 1012163
  //ACTOR3 = 1016011
  //ACTOR4 = 1016012
  //ACTOR5 = 1012384
  //ACTOR6 = 1016029
  //ACTOR7 = 1016030
  //ACTOR8 = 1016058
  //ACTOR9 = 1012385
  //LOCACTOR0 = 6080791
  //LOCACTOR1 = 6080792
  //LOCACTOR10 = 6081061
  //LOCACTOR11 = 6081062
  //LOCACTOR12 = 5895161
  //LOCACTOR2 = 6080793
  //LOCACTOR20 = 1015848
  //LOCACTOR21 = 1015858
  //LOCACTOR3 = 6080794
  //LOCACTOR30 = 6081083
  //LOCACTOR40 = 1011895
  //LOCACTOR41 = 1015842
  //LOCACTOR42 = 6081142
  //LOCACTOR43 = 6081693
  //LOCACTOR44 = 6081143
  //LOCACTOR50 = 1011893
  //LOCACTOR60 = 5838636
  //POPRANGE0 = 6163372

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016008 || param2 == 1016008 ) // ACTOR0 = LUCIA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016009 || param2 == 1016009 ) // ACTOR1 = HILDA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1016010 || param2 == 1016010 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016011 || param2 == 1016011 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016012 || param2 == 1016012 ) // ACTOR4 = THANCRED
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
        }
        break;
      }
      case 1:
      {
        if( param1 == 1012384 || param2 == 1012384 ) // ACTOR5 = EMMANELLAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=EMMANELLAIN
          }
        }
        if( param1 == 1016029 || param2 == 1016029 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016030 || param2 == 1016030 ) // ACTOR7 = TATARU
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1016058 || param2 == 1016058 ) // ACTOR8 = YSHTOLA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1012385 || param2 == 1012385 ) // ACTOR9 = HONOROIT
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( param1 == 1016025 || param2 == 1016025 ) // ACTOR10 = HILDA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1016026 || param2 == 1016026 ) // ACTOR11 = THANCRED
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016015 || param2 == 1016015 ) // ACTOR12 = BEAUTY02162
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=BEAUTY02162
        }
        if( param1 == 1016018 || param2 == 1016018 ) // ACTOR13 = MAELIE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=MAELIE
        }
        if( param1 == 1016019 || param2 == 1016019 ) // ACTOR14 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1016020 || param2 == 1016020 ) // ACTOR15 = ISHGARDIANPRIEST02162
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ISHGARDIANPRIEST02162
        }
        if( param1 == 1016016 || param2 == 1016016 ) // ACTOR16 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( param1 == 1016017 || param2 == 1016017 ) // ACTOR17 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR18 = LUCIA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LUCIA
        }
        break;
      }
      case 2:
      {
        if( param1 == 1016015 || param2 == 1016015 ) // ACTOR12 = BEAUTY02162
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=BEAUTY02162
            // +Callback Scene00021: Normal(Talk, TargetCanMove), id=BEAUTY02162
          }
        }
        if( param1 == 1016018 || param2 == 1016018 ) // ACTOR13 = MAELIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=MAELIE
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=MAELIE
          }
        }
        if( param1 == 1016020 || param2 == 1016020 ) // ACTOR15 = ISHGARDIANPRIEST02162
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=ISHGARDIANPRIEST02162
          }
        }
        if( param1 == 1016029 || param2 == 1016029 ) // ACTOR6 = ALPHINAUD
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016030 || param2 == 1016030 ) // ACTOR7 = TATARU
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1016058 || param2 == 1016058 ) // ACTOR8 = YSHTOLA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1012384 || param2 == 1012384 ) // ACTOR5 = EMMANELLAIN
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( param1 == 1012385 || param2 == 1012385 ) // ACTOR9 = HONOROIT
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( param1 == 1016019 || param2 == 1016019 ) // ACTOR14 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
        }
        if( param1 == 1016016 || param2 == 1016016 ) // ACTOR16 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( param1 == 1016017 || param2 == 1016017 ) // ACTOR17 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR18 = LUCIA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=LUCIA
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016028 || param2 == 1016028 ) // ACTOR19 = THANCRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=THANCRED
          }
        }
        if( param1 == 1016027 || param2 == 1016027 ) // ACTOR20 = HILDA
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1016029 || param2 == 1016029 ) // ACTOR6 = ALPHINAUD
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016030 || param2 == 1016030 ) // ACTOR7 = TATARU
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1016058 || param2 == 1016058 ) // ACTOR8 = YSHTOLA
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016015 || param2 == 1016015 ) // ACTOR12 = BEAUTY02162
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=BEAUTY02162
        }
        if( param1 == 1016018 || param2 == 1016018 ) // ACTOR13 = MAELIE
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=MAELIE
        }
        if( param1 == 1016019 || param2 == 1016019 ) // ACTOR14 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( param1 == 1016016 || param2 == 1016016 ) // ACTOR16 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        if( param1 == 1016017 || param2 == 1016017 ) // ACTOR17 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR18 = LUCIA
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=LUCIA
        }
        break;
      }
      case 4:
      {
        if( param1 == 1016031 || param2 == 1016031 ) // ACTOR21 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00045( player ); // Scene00045: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1016032 || param2 == 1016032 ) // ACTOR22 = TATARU
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1016033 || param2 == 1016033 ) // ACTOR23 = PYROMANIAC02162
        {
          Scene00047( player ); // Scene00047: Normal(Talk), id=PYROMANIAC02162
        }
        if( param1 == 1016057 || param2 == 1016057 ) // ACTOR24 = YSHTOLA
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016015 || param2 == 1016015 ) // ACTOR12 = BEAUTY02162
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=BEAUTY02162
        }
        if( param1 == 1016018 || param2 == 1016018 ) // ACTOR13 = MAELIE
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=MAELIE
        }
        if( param1 == 1016019 || param2 == 1016019 ) // ACTOR14 = unknown
        {
          Scene00051( player ); // Scene00051: Normal(None), id=unknown
        }
        if( param1 == 1016016 || param2 == 1016016 ) // ACTOR16 = unknown
        {
          Scene00052( player ); // Scene00052: Normal(None), id=unknown
        }
        if( param1 == 1016017 || param2 == 1016017 ) // ACTOR17 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR18 = LUCIA
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=LUCIA
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016008 || param2 == 1016008 ) // ACTOR0 = LUCIA
        {
          Scene00055( player ); // Scene00055: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016009 || param2 == 1016009 ) // ACTOR1 = HILDA
        {
          Scene00056( player ); // Scene00056: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1016010 || param2 == 1016010 ) // ACTOR2 = ALPHINAUD
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016011 || param2 == 1016011 ) // ACTOR3 = YSHTOLA
        {
          Scene00058( player ); // Scene00058: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016032 || param2 == 1016032 ) // ACTOR22 = TATARU
        {
          Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1016059 || param2 == 1016059 ) // ACTOR25 = THANCRED
        {
          Scene00060( player ); // Scene00060: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR26 = HANDELOUP
        {
          Scene00061( player ); // Scene00061: Normal(Talk, TargetCanMove), id=HANDELOUP
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
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
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnb107:67698 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 418, 85, 24, -6.53, -1.77 );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00002: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00006: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00008: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00009: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00010: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00011: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00012: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00013: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00014: Normal(Talk, TargetCanMove), id=MAELIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00016: Normal(Talk, TargetCanMove), id=ISHGARDIANPRIEST02162" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00019: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00020: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling [BranchTrue]Scene00021: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00022: Normal(Talk, TargetCanMove), id=MAELIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling [BranchTrue]Scene00023: Normal(Talk, TargetCanMove), id=MAELIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=ISHGARDIANPRIEST02162" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00025: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00026: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00027: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00028: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00029: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00033: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00034: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00035: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00037: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00038: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00039: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00040: Normal(Talk, TargetCanMove), id=MAELIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00043: Normal(None), id=unknown" );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00044: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00045: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 45, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00046: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00047: Normal(Talk), id=PYROMANIAC02162" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00048: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00049: Normal(Talk, TargetCanMove), id=BEAUTY02162" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00050: Normal(Talk, TargetCanMove), id=MAELIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00051: Normal(None), id=unknown" );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00052: Normal(None), id=unknown" );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00053: Normal(None), id=unknown" );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00054: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00055: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 55, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00056: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00057: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00058: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00059: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00060: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb107:67698 calling Scene00061: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 61, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb107 );
