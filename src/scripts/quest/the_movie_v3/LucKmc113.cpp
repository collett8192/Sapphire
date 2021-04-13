// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc113 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc113() : Sapphire::ScriptAPI::EventScript( 68870 ){}; 
  ~LucKmc113() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 7 entries
  //SEQ_255, 7 entries

  //ACTOR0 = 1030374
  //ACTOR1 = 1029231
  //ACTOR10 = 1027712
  //ACTOR11 = 1027719
  //ACTOR2 = 1029232
  //ACTOR3 = 1029233
  //ACTOR4 = 1029234
  //ACTOR5 = 1029235
  //ACTOR6 = 1029236
  //ACTOR7 = 1029237
  //ACTOR8 = 1027717
  //ACTOR9 = 1027711
  //ITEM0 = 2002551
  //LOCACTORALMET = 1028139
  //LOCACTORCYMET = 1028141
  //LOCACTORMINFILIA = 1026572
  //LOCACTORTHANCRED = 1026569
  //LOCACTORUIMET = 1028140
  //LOCACTORURIANGER = 1026570
  //LOCACTORYSHTOLA = 1026571
  //LOCBGMMUSICEX3PATHOS01 = 649

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=CYMET
        break;
      }
      case 1:
      {
        if( param1 == 1029231 || param2 == 1029231 ) // ACTOR1 = ALMET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALMET
          }
          break;
        }
        if( param1 == 1029232 || param2 == 1029232 ) // ACTOR2 = UIMET
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029233 || param2 == 1029233 ) // ACTOR3 = CYMET
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029234 || param2 == 1029234 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029235 || param2 == 1029235 ) // ACTOR5 = THANCRED
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029236 || param2 == 1029236 ) // ACTOR6 = RYNE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029237 || param2 == 1029237 ) // ACTOR7 = URIANGER
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8CL max stack 1
      case 2:
      {
        if( param1 == 1027717 || param2 == 1027717 ) // ACTOR8 = KORILLE
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove, SystemTalk), id=KORILLE
            // +Callback Scene00010: Normal(Talk, TargetCanMove), id=KORILLE
          }
          break;
        }
        if( param1 == 1027711 || param2 == 1027711 ) // ACTOR9 = NYMET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=NYMET
            // +Callback Scene00012: Normal(Talk, TargetCanMove), id=NYMET
          }
          break;
        }
        if( param1 == 1027712 || param2 == 1027712 ) // ACTOR10 = LOYMET
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=LOYMET
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=LOYMET
          }
          break;
        }
        if( param1 == 1027719 || param2 == 1027719 ) // ACTOR11 = SHOINA
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=SHOINA
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=SHOINA
          }
          break;
        }
        if( param1 == 1029231 || param2 == 1029231 ) // ACTOR1 = ALMET
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029232 || param2 == 1029232 ) // ACTOR2 = UIMET
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029233 || param2 == 1029233 ) // ACTOR3 = CYMET
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        if( param1 == 1029231 || param2 == 1029231 ) // ACTOR1 = ALMET
        {
          Scene00020( player ); // Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00021: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=ALMET
          break;
        }
        if( param1 == 1029232 || param2 == 1029232 ) // ACTOR2 = UIMET
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=UIMET
          break;
        }
        if( param1 == 1029233 || param2 == 1029233 ) // ACTOR3 = CYMET
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=CYMET
          break;
        }
        if( param1 == 1029234 || param2 == 1029234 ) // ACTOR4 = YSHTOLA
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1029235 || param2 == 1029235 ) // ACTOR5 = THANCRED
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1029236 || param2 == 1029236 ) // ACTOR6 = RYNE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1029237 || param2 == 1029237 ) // ACTOR7 = URIANGER
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=URIANGER
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
    if( player.getQuestUI8CH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
          if( player.getQuestUI8BL( getId() ) == 1 )
          {
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CL( getId(), 0 );
            player.updateQuest( getId(), 255 );
            player.setQuestUI8BH( getId(), 1 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc113:68870 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00003: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00004: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00006: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00007: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00008: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00009: Normal(Talk, TargetCanMove, SystemTalk), id=KORILLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00010: Normal(Talk, TargetCanMove), id=KORILLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00011: Normal(Talk, TargetCanMove), id=NYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00012: Normal(Talk, TargetCanMove), id=NYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00013: Normal(Talk, TargetCanMove), id=LOYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00014: Normal(Talk, TargetCanMove), id=LOYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00015: Normal(Talk, TargetCanMove), id=SHOINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00016: Normal(Talk, TargetCanMove), id=SHOINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00017: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00018: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00019: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00020: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00021( player );
      }
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00021: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, Menu), id=ALMET" );
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
    player.playScene( getId(), 21, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00022: Normal(Talk, TargetCanMove), id=UIMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00023: Normal(Talk, TargetCanMove), id=CYMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00025: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00026: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmc113:68870 calling Scene00027: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc113 );
