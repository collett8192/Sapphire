// FFXIVTheMovie.ParserV3
//fix: black screen
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb101 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnb101() : Sapphire::ScriptAPI::EventScript( 67692 ){}; 
  ~HeaVnb101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 7 entries
  //SEQ_3, 7 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1012857
  //ACTOR1 = 1011223
  //ACTOR2 = 1012326
  //ACTOR3 = 1015979
  //ACTOR4 = 1015978
  //ACTOR5 = 1012163
  //ACTOR6 = 1012251
  //ACTOR7 = 1012252
  //ACTOR8 = 1012253
  //ACTOR9 = 1013128
  //CUTSCENEN01 = 1044
  //CUTSCENEN02 = 1045
  //CUTSCENEN03 = 1046
  //LOCACTOR0 = 5912494
  //LOCACTOR1 = 6080492
  //LOCACTOR2 = 5859640
  //POPRANGE0 = 5827750
  //POPRANGE1 = 5827491

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( param1 == 1011223 || param2 == 1011223 ) // ACTOR1 = TEMPLEKIGHTGATE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKIGHTGATE
            // +Callback Scene00003: Normal(CutScene), id=unknown
          }
        }
        if( param1 == 1012326 || param2 == 1012326 ) // ACTOR2 = TATARU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1015979 || param2 == 1015979 ) // ACTOR3 = ALPHINAUD
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        if( param1 == 1015978 || param2 == 1015978 ) // ACTOR4 = LUCIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=LUCIA
          }
        }
        if( param1 == 1012326 || param2 == 1012326 ) // ACTOR2 = TATARU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1015979 || param2 == 1015979 ) // ACTOR3 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR5 = HANDELOUP
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR6 = HILDA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR7 = SYMME
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR8 = EUDESTAND
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        break;
      }
      case 3:
      {
        if( param1 == 1012326 || param2 == 1012326 ) // ACTOR2 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=TATARU
          }
        }
        if( param1 == 1013128 || param2 == 1013128 ) // ACTOR9 = ALPHINAUD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1015978 || param2 == 1015978 ) // ACTOR4 = LUCIA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR5 = HANDELOUP
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR6 = HILDA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR7 = SYMME
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR8 = EUDESTAND
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        break;
      }
      case 255:
      {
        if( param1 == 1015978 || param2 == 1015978 ) // ACTOR4 = LUCIA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LUCIA
        }
        if( param1 == 1012326 || param2 == 1012326 ) // ACTOR2 = TATARU
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( param1 == 1015979 || param2 == 1015979 ) // ACTOR3 = ALPHINAUD
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR5 = HANDELOUP
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR6 = HILDA
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR7 = SYMME
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR8 = EUDESTAND
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=EUDESTAND
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
    player.sendDebug( "HeaVnb101:67692 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnb101:67692 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.exitInstance();
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00002: Normal(Talk, YesNo, TargetCanMove), id=TEMPLEKIGHTGATE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 != 50 )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling [BranchTrue]Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 418, 113, 24.4, -4.65, -0.856 );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00004: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00006: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00007: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00009: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00010: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00011: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00012: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00013: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00014: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00015: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00016: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00017: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00018: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00019: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00020: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00021: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00022: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00023: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00024: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00025: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb101:67692 calling Scene00026: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb101 );
