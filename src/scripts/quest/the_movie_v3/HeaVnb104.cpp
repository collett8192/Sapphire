// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb104 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnb104() : Sapphire::ScriptAPI::EventScript( 67695 ){}; 
  ~HeaVnb104() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 1 entries
  //SEQ_2, 4 entries
  //SEQ_3, 7 entries
  //SEQ_4, 7 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1015992
  //ACTOR1 = 1012422
  //ACTOR10 = 1015994
  //ACTOR11 = 1015995
  //ACTOR12 = 1015996
  //ACTOR13 = 1015997
  //ACTOR2 = 1012423
  //ACTOR3 = 1012405
  //ACTOR4 = 1012406
  //ACTOR5 = 1015993
  //ACTOR6 = 1012138
  //ACTOR7 = 1011916
  //ACTOR8 = 1011917
  //ACTOR9 = 1011922
  //CUTSCENEN01 = 1048
  //EOBJECT0 = 2006610
  //EVENTACTIONWAITING2MIDDLE = 12
  //ITEM0 = 2001899
  //LOCACTOR1 = 1011887
  //LOCACTOR10 = 5860039
  //LOCACTOR11 = 6081187
  //LOCACTOR2 = 1011889
  //LOCACTOR20 = 5860123
  //LOCACTOR21 = 5860124
  //LOCACTOR3 = 6081170
  //POPRANGE0 = 6080829
  //TERRITORYTYPE0 = 463

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1015992 || param2 == 1015992 ) // ACTOR0 = KRILE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KRILE
        }
        if( param1 == 1012422 || param2 == 1012422 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1012423 || param2 == 1012423 ) // ACTOR2 = YSHTOLA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00004( player ); // Scene00004: Normal(CutScene), id=unknown
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( param1 == 1012405 || param2 == 1012405 ) // ACTOR3 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1012406 || param2 == 1012406 ) // ACTOR4 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1015993 || param2 == 1015993 ) // ACTOR5 = KRILE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1012138 || param2 == 1012138 ) // ACTOR6 = MATOYA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MATOYA
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8CH max stack 1
      case 3:
      {
        if( param1 == 1011916 || param2 == 1011916 ) // ACTOR7 = MARCECHAMP
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=MARCECHAMP
          }
          else
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MARCECHAMP
          }
        }
        if( param1 == 1011917 || param2 == 1011917 ) // ACTOR8 = LOUPARD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=LOUPARD
          }
          else
          {
            Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=LOUPARD
          }
        }
        if( param1 == 1011922 || param2 == 1011922 ) // ACTOR9 = GRIMOLD
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=GRIMOLD
          }
          else
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=GRIMOLD
          }
        }
        if( param1 == 1015994 || param2 == 1015994 ) // ACTOR10 = KRILE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1015995 || param2 == 1015995 ) // ACTOR11 = ALPHINAUD
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1015996 || param2 == 1015996 ) // ACTOR12 = YSHTOLA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1012138 || param2 == 1012138 ) // ACTOR6 = MATOYA
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=MATOYA
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        if( param1 == 1015994 || param2 == 1015994 ) // ACTOR10 = KRILE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=KRILE
          }
        }
        if( param1 == 1015995 || param2 == 1015995 ) // ACTOR11 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1015996 || param2 == 1015996 ) // ACTOR12 = YSHTOLA
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1011916 || param2 == 1011916 ) // ACTOR7 = MARCECHAMP
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=MARCECHAMP
        }
        if( param1 == 1011917 || param2 == 1011917 ) // ACTOR8 = LOUPARD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=LOUPARD
        }
        if( param1 == 1011922 || param2 == 1011922 ) // ACTOR9 = GRIMOLD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=GRIMOLD
        }
        if( param1 == 1012138 || param2 == 1012138 ) // ACTOR6 = MATOYA
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=MATOYA
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 2006610 || param2 == 2006610 ) // EOBJECT0 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          // +Callback Scene00030: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( param1 == 1015997 || param2 == 1015997 ) // ACTOR13 = KRILE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=KRILE
        }
        if( param1 == 1011916 || param2 == 1011916 ) // ACTOR7 = MARCECHAMP
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=MARCECHAMP
        }
        if( param1 == 1011917 || param2 == 1011917 ) // ACTOR8 = LOUPARD
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=LOUPARD
        }
        if( param1 == 1011922 || param2 == 1011922 ) // ACTOR9 = GRIMOLD
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=GRIMOLD
        }
        if( param1 == 1012138 || param2 == 1012138 ) // ACTOR6 = MATOYA
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=MATOYA
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 3 );
      player.setQuestUI8CH( getId(), 1 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
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
    player.sendDebug( "HeaVnb104:67695 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnb104:67695 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00005: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00007: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00008: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00009: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00010( player );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling [BranchTrue]Scene00010: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling [BranchFalse]Scene00011: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00012: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling [BranchTrue]Scene00013: Normal(Talk, TargetCanMove), id=LOUPARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling [BranchFalse]Scene00014: Normal(Talk, TargetCanMove), id=LOUPARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00015: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00016( player );
      }
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling [BranchTrue]Scene00016: Normal(Talk, TargetCanMove), id=GRIMOLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling [BranchFalse]Scene00017: Normal(Talk, TargetCanMove), id=GRIMOLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00018: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00019: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00021: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00022: Normal(Talk, NpcDespawn, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00025: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00026: Normal(Talk, TargetCanMove), id=LOUPARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00027: Normal(Talk, TargetCanMove), id=GRIMOLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00028: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00029: Normal(None), id=unknown" );
    Scene00030( player );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling [BranchTrue]Scene00030: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00031: Normal(Talk, TargetCanMove), id=KRILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00032: Normal(Talk, TargetCanMove), id=MARCECHAMP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00033: Normal(Talk, TargetCanMove), id=LOUPARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00034: Normal(Talk, TargetCanMove), id=GRIMOLD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb104:67695 calling Scene00035: Normal(Talk, TargetCanMove), id=MATOYA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb104 );
