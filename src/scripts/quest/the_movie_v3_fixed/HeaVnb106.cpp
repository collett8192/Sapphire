// FFXIVTheMovie.ParserV3
//fix: black screen, wrong scene chain at seq 1
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb106 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnb106() : Sapphire::ScriptAPI::EventScript( 67697 ){}; 
  ~HeaVnb106() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 1 entries
  //SEQ_2, 9 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1016000
  //ACTOR1 = 1016001
  //ACTOR10 = 1011192
  //ACTOR11 = 1012326
  //ACTOR12 = 1012163
  //ACTOR2 = 1016002
  //ACTOR3 = 1016003
  //ACTOR4 = 1011935
  //ACTOR5 = 1012401
  //ACTOR6 = 1012402
  //ACTOR7 = 1016007
  //ACTOR8 = 1016008
  //ACTOR9 = 1016009
  //CUTSCENEN01 = 1053
  //LOCACTOR0 = 6081180
  //LOCACTOR1 = 6081178
  //LOCACTOR10 = 1011887
  //LOCACTOR11 = 1011889
  //LOCACTOR12 = 1015842
  //LOCACTOR2 = 6081179
  //LOCACTOR20 = 5859948
  //LOCACTOR21 = 6082269
  //LOCACTOR30 = 6080791
  //LOCACTOR40 = 5838636
  //LOCMUSIC01 = 314
  //POPRANGE0 = 6082247
  //POPRANGE1 = 6165607

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016000 || param2 == 1016000 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016001 || param2 == 1016001 ) // ACTOR1 = YSHTOLA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016002 || param2 == 1016002 ) // ACTOR2 = THANCRED
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016003 || param2 == 1016003 ) // ACTOR3 = KRILE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KRILE
        }
        break;
      }
      case 1:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=VIDOFNIR
        break;
      }
      case 2:
      {
        if( param1 == 1012401 || param2 == 1012401 ) // ACTOR5 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player );
          }
        }
        if( param1 == 1012402 || param2 == 1012402 ) // ACTOR6 = YSHTOLA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016007 || param2 == 1016007 ) // ACTOR7 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1011935 || param2 == 1011935 ) // ACTOR4 = VIDOFNIR
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=VIDOFNIR
        }
        if( param1 == 1016008 || param2 == 1016008 ) // ACTOR8 = LUCIA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016009 || param2 == 1016009 ) // ACTOR9 = HILDA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1011192 || param2 == 1011192 ) // ACTOR10 = GIBRILLONT
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GIBRILLONT
        }
        if( param1 == 1012326 || param2 == 1012326 ) // ACTOR11 = TATARU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR12 = HANDELOUP
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016008 || param2 == 1016008 ) // ACTOR8 = LUCIA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016009 || param2 == 1016009 ) // ACTOR9 = HILDA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1011935 || param2 == 1011935 ) // ACTOR4 = VIDOFNIR
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=VIDOFNIR
        }
        if( param1 == 1011192 || param2 == 1011192 ) // ACTOR10 = GIBRILLONT
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=GIBRILLONT
        }
        if( param1 == 1012326 || param2 == 1012326 ) // ACTOR11 = TATARU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR12 = HANDELOUP
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HANDELOUP
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnb106:67697 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 398, -234.8, -28.69, 161, -2.651 );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00003: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00004: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=VIDOFNIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00006: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 418, -10.34, 5.47, 42.52, 2.34 );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00010: Normal(Talk, TargetCanMove), id=VIDOFNIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00011: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00012: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00013: Normal(Talk, TargetCanMove), id=GIBRILLONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00014: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00015: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00017: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00018: Normal(Talk, TargetCanMove), id=VIDOFNIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00019: Normal(Talk, TargetCanMove), id=GIBRILLONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00020: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb106:67697 calling Scene00021: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb106 );
