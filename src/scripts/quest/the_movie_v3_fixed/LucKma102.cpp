// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKma102 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKma102() : Sapphire::ScriptAPI::EventScript( 68816 ){}; 
  ~LucKma102() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 3 entries
  //SEQ_2, 5 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTADDLOOKLR = 5522
  //ACTOR0 = 1028924
  //ACTOR1 = 1029797
  //ACTOR2 = 1028925
  //ACTOR3 = 1027232
  //ACTOR4 = 1027226
  //ACTOR5 = 1027224
  //AETHERYTE0 = 133
  //BGMMUSICEX3PATHOS01 = 649
  //BGMMUSICEX3TOWNCRYSTARIUMDAY01 = 659
  //EVENTPICTURE0 = 789
  //EVENTPICTURE1 = 790
  //EVENTPICTURE2 = 791
  //INVISACTOR0 = 1027808
  //ITEM0 = 2002527
  //ITEM1 = 2002528
  //ITEM2 = 2002529
  //LCUTACTOR0 = 1029333
  //LCUTACTOR1 = 1029357
  //LCUTACTOR2 = 1029358
  //LCUTACTOR3 = 1029359
  //LCUTACTOR4 = 1029360
  //LCUTACTOR5 = 1029361
  //LCUTPOS0 = 7788917
  //LCUTPOS1 = 7981190
  //LCUTPOS2 = 7981194
  //LCUTPOS3 = 7981241
  //LCUTSECLOSETHEBOOK = 228
  //LCUTSETURNTHEPAGES = 227
  //POPRANGE0 = 8036159
  //TERRITORYTYPE0 = 813

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1028924 || param2 == 1028924 ) // ACTOR0 = MYSTERYVOICE
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00002( player ); // Scene00002: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 4302824955 || param2 == 4302824955 ) // AETHERYTE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1028925 || param2 == 1028925 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00006( player ); // Scene00006: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8CH max stack 1
      //seq 2 event item ITEM1 = UI8CL max stack 1
      //seq 2 event item ITEM2 = UI8DH max stack 1
      case 2:
      {
        if( param1 == 1027232 || param2 == 1027232 ) // ACTOR3 = KATLISS
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=KATLISS
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=KATLISS
          }
          break;
        }
        if( param1 == 1027226 || param2 == 1027226 ) // ACTOR4 = MOREN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=MOREN
          }
          break;
        }
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR5 = BRAGI
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, FadeIn, TargetCanMove, Menu, SystemTalk), id=BRAGI
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=BRAGI
          }
          break;
        }
        if( param1 == 1028925 || param2 == 1028925 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00013( player ); // Scene00013: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      //seq 255 event item ITEM2 = UI8CH max stack 1
      case 255:
      {
        if( param1 == 1028925 || param2 == 1028925 ) // ACTOR2 = MYSTERYVOICE
        {
          Scene00014( player ); // Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1027232 || param2 == 1027232 ) // ACTOR3 = KATLISS
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=KATLISS
          break;
        }
        if( param1 == 1027224 || param2 == 1027224 ) // ACTOR5 = BRAGI
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=BRAGI
          break;
        }
        if( param1 == 1029797 || param2 == 1029797 ) // ACTOR1 = GARLONDMAN03279
        {
          Scene00018( player ); // Scene00018: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestUI8DH( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 1 );
          player.setQuestUI8BL( getId(), 1 );
          player.setQuestUI8CH( getId(), 1 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKma102:68816 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, Menu), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00002: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00004: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00005: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00006: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=KATLISS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00008: Normal(Talk, TargetCanMove), id=KATLISS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00009: Normal(Talk, FadeIn, TargetCanMove, SystemTalk), id=MOREN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00010: Normal(Talk, FadeIn, TargetCanMove, Menu, SystemTalk), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00011( player );
      }
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00011: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00012: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00013: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00014: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00015: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MYSTERYVOICE" );
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
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00016: Normal(Talk, TargetCanMove), id=KATLISS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00017: Normal(Talk, TargetCanMove), id=BRAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKma102:68816 calling Scene00018: Normal(Talk, YesNo, TargetCanMove), id=GARLONDMAN03279" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
      }
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKma102 );
