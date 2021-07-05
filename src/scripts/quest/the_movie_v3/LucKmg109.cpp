// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmg109 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmg109() : Sapphire::ScriptAPI::EventScript( 69217 ){}; 
  ~LucKmg109() = default; 

  //SEQ_0, 11 entries
  //SEQ_1, 8 entries
  //SEQ_2, 5 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1031770
  //ACTOR1 = 1031769
  //ACTOR10 = 1032271
  //ACTOR11 = 1027549
  //ACTOR12 = 1031777
  //ACTOR13 = 1031778
  //ACTOR14 = 1031779
  //ACTOR15 = 1031780
  //ACTOR16 = 1031781
  //ACTOR2 = 1031771
  //ACTOR3 = 1031772
  //ACTOR4 = 1031773
  //ACTOR5 = 1031774
  //ACTOR6 = 1031775
  //ACTOR7 = 1031776
  //ACTOR8 = 1032262
  //ACTOR9 = 1032265
  //CUTSCENE0 = 2193
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORCHAINUZZ = 1028120
  //LOCACTORCHELETTE = 1029483
  //LOCACTORDULIACHAI = 1028119
  //LOCACTORHATHENBET = 1029482
  //LOCACTORKAISHIRR = 1028121
  //LOCACTORWRENDEN = 1029472
  //LOCBINDACTOR0 = 8134559
  //LOCBINDACTOR1 = 8134560
  //LOCBINDACTOR10 = 7796189
  //LOCBINDACTOR2 = 8134564
  //LOCBINDACTOR3 = 8134565
  //LOCBINDACTOR4 = 8134570
  //LOCBINDACTOR5 = 8134591
  //LOCBINDACTOR6 = 8134593
  //LOCBINDACTOR7 = 8134594
  //LOCBINDACTOR8 = 8134595
  //LOCBINDACTOR9 = 8134596
  //POPRANGE0 = 8136668

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1031770 || param2 == 1031770 ) // ACTOR0 = CHAINUZZ
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1031769 || param2 == 1031769 ) // ACTOR1 = WRENDEN
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=WRENDEN
          break;
        }
        if( param1 == 1031771 || param2 == 1031771 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031772 || param2 == 1031772 ) // ACTOR3 = KAISHIRR
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1031773 || param2 == 1031773 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031774 || param2 == 1031774 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031775 || param2 == 1031775 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031776 || param2 == 1031776 ) // ACTOR7 = DULIACHAI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1032262 || param2 == 1032262 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032265 || param2 == 1032265 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032271 || param2 == 1032271 ) // ACTOR10 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1027549 || param2 == 1027549 ) // ACTOR11 = CHADDEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=CHADDEN
            // +Callback Scene00013: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1031773 || param2 == 1031773 ) // ACTOR4 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031774 || param2 == 1031774 ) // ACTOR5 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031775 || param2 == 1031775 ) // ACTOR6 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1031772 || param2 == 1031772 ) // ACTOR3 = KAISHIRR
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1032262 || param2 == 1032262 ) // ACTOR8 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032265 || param2 == 1032265 ) // ACTOR9 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032271 || param2 == 1032271 ) // ACTOR10 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1031777 || param2 == 1031777 ) // ACTOR12 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1031778 || param2 == 1031778 ) // ACTOR13 = CHAINUZZ
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1031779 || param2 == 1031779 ) // ACTOR14 = DULIACHAI
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1031780 || param2 == 1031780 ) // ACTOR15 = WRENDEN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=WRENDEN
          break;
        }
        if( param1 == 1031781 || param2 == 1031781 ) // ACTOR16 = KAISHIRR
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=KAISHIRR
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1031781 || param2 == 1031781 ) // ACTOR16 = KAISHIRR
        {
          Scene00026( player ); // Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KAISHIRR
          break;
        }
        if( param1 == 1031777 || param2 == 1031777 ) // ACTOR12 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmg109:69217 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00002: Normal(Talk, TargetCanMove), id=WRENDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00004: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00008: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00012: Normal(Talk, TargetCanMove), id=CHADDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00013( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00013: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 13, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00017: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00020: Normal(None), id=unknown" );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00021: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00022: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00023: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00024: Normal(Talk, TargetCanMove), id=WRENDEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00025: Normal(Talk, TargetCanMove), id=KAISHIRR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=KAISHIRR" );
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
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmg109:69217 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmg109 );
