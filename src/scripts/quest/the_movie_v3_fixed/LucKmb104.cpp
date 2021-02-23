// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb104 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb104() : Sapphire::ScriptAPI::EventScript( 68841 ){}; 
  ~LucKmb104() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 6 entries
  //SEQ_2, 5 entries
  //SEQ_3, 5 entries
  //SEQ_4, 9 entries
  //SEQ_5, 2 entries
  //SEQ_255, 4 entries

  //ACTIONTIMELINEEVENTBOUND = 967
  //ACTIONTIMELINEEVENTEAT = 963
  //ACTIONTIMELINEEVENTLAUGH = 952
  //ACTIONTIMELINEEVENTSALUTECLM = 5618
  //ACTOR0 = 1028947
  //ACTOR1 = 1028951
  //ACTOR10 = 1028958
  //ACTOR11 = 1028959
  //ACTOR2 = 1028952
  //ACTOR3 = 1028953
  //ACTOR4 = 1028954
  //ACTOR5 = 1028955
  //ACTOR6 = 1030608
  //ACTOR7 = 1030609
  //ACTOR8 = 1028956
  //ACTOR9 = 1028957
  //BINDACTOR0 = 7921478
  //BINDACTOR1 = 7921480
  //BINDACTOR2 = 7921481
  //CUTSCENE0 = 1984
  //CUTSCENE1 = 1985
  //CUTSCENE2 = 1986
  //EOBJECT0 = 2009814
  //EOBJECT1 = 2009815
  //EVENTACTION0 = 32
  //ITEM0 = 2002532
  //POPRANGE0 = 7920350
  //QUESTBATTLE0 = 185
  //QUESTEQUIPARM = 43
  //QUESTEQUIPBODY = 42
  //QUESTEQUIPFOOT = 45
  //QUESTEQUIPHEAD = 41
  //QUESTEQUIPLEG = 44
  //TERRITORYTYPE0 = 861
  //TERRITORYTYPE1 = 816

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1028947 || param2 == 1028947 ) // ACTOR0 = LYNA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1028951 || param2 == 1028951 ) // ACTOR1 = AMAROA03304
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=AMAROA03304
          break;
        }
        if( param1 == 1028952 || param2 == 1028952 ) // ACTOR2 = AMAROB03304
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=AMAROB03304
          break;
        }
        if( param1 == 1028953 || param2 == 1028953 ) // ACTOR3 = AMAROC03304
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=AMAROC03304
          break;
        }
        if( param1 == 1028954 || param2 == 1028954 ) // ACTOR4 = AMAROD03304
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=AMAROD03304
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack 1
      case 1:
      {
        if( param1 == 2009814 || param2 == 2009814 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1028947 || param2 == 1028947 ) // ACTOR0 = LYNA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1028951 || param2 == 1028951 ) // ACTOR1 = AMAROA03304
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=AMAROA03304
          break;
        }
        if( param1 == 1028952 || param2 == 1028952 ) // ACTOR2 = AMAROB03304
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=AMAROB03304
          break;
        }
        if( param1 == 1028953 || param2 == 1028953 ) // ACTOR3 = AMAROC03304
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=AMAROC03304
          break;
        }
        if( param1 == 1028954 || param2 == 1028954 ) // ACTOR4 = AMAROD03304
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=AMAROD03304
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8CL max stack 1
      case 2:
      {
        if( param1 == 1028951 || param2 == 1028951 ) // ACTOR1 = AMAROA03304
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00014: Normal(Talk, TargetCanMove, SystemTalk), id=AMAROA03304
            // +Callback Scene00015: Normal(Talk, TargetCanMove), id=AMAROA03304
          }
          break;
        }
        if( param1 == 1028952 || param2 == 1028952 ) // ACTOR2 = AMAROB03304
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00017: Normal(Talk, TargetCanMove, SystemTalk), id=AMAROB03304
            // +Callback Scene00018: Normal(Talk, TargetCanMove), id=AMAROB03304
          }
          break;
        }
        if( param1 == 1028953 || param2 == 1028953 ) // ACTOR3 = AMAROC03304
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00020: Normal(Talk, TargetCanMove, SystemTalk), id=AMAROC03304
            // +Callback Scene00021: Normal(Talk, TargetCanMove), id=AMAROC03304
          }
          break;
        }
        if( param1 == 1028954 || param2 == 1028954 ) // ACTOR4 = AMAROD03304
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: NpcTrade(TargetCanMove), id=unknown
            // +Callback Scene00023: Normal(Talk, TargetCanMove, SystemTalk), id=AMAROD03304
            // +Callback Scene00024: Normal(Talk, TargetCanMove), id=AMAROD03304
          }
          break;
        }
        if( param1 == 1028947 || param2 == 1028947 ) // ACTOR0 = LYNA
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1028947 || param2 == 1028947 ) // ACTOR0 = LYNA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=LYNA
          }
          break;
        }
        if( param1 == 1028951 || param2 == 1028951 ) // ACTOR1 = AMAROA03304
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=AMAROA03304
          break;
        }
        if( param1 == 1028952 || param2 == 1028952 ) // ACTOR2 = AMAROB03304
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=AMAROB03304
          break;
        }
        if( param1 == 1028953 || param2 == 1028953 ) // ACTOR3 = AMAROC03304
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=AMAROC03304
          break;
        }
        if( param1 == 1028954 || param2 == 1028954 ) // ACTOR4 = AMAROD03304
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=AMAROD03304
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1028955 || param2 == 1028955 ) // ACTOR5 = CRYSTARIUMGARDPICKET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00031( player ); // Scene00031: Normal(Talk, QuestBattle, YesNo, TargetCanMove, SystemTalk, CanCancel), id=CRYSTARIUMGARDPICKET
            // +Callback Scene00032: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1028947 || param2 == 1028947 ) // ACTOR0 = LYNA
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1028951 || param2 == 1028951 ) // ACTOR1 = AMAROA03304
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=AMAROA03304
          break;
        }
        if( param1 == 1028952 || param2 == 1028952 ) // ACTOR2 = AMAROB03304
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=AMAROB03304
          break;
        }
        if( param1 == 1028953 || param2 == 1028953 ) // ACTOR3 = AMAROC03304
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=AMAROC03304
          break;
        }
        if( param1 == 1028954 || param2 == 1028954 ) // ACTOR4 = AMAROD03304
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=AMAROD03304
          break;
        }
        if( param1 == 1030608 || param2 == 1030608 ) // ACTOR6 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030609 || param2 == 1030609 ) // ACTOR7 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009815 || param2 == 2009815 ) // EOBJECT1 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 5:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00041( player ); // Scene00041: Normal(CutScene, AutoFadeIn), id=unknown
          // +42
          break;
        }
        if( param1 == 1028955 || param2 == 1028955 ) // ACTOR5 = unknown
        {
          Scene00043( player );
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1028956 || param2 == 1028956 ) // ACTOR8 = THANCRED
        {
          Scene00044( player ); // Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1028957 || param2 == 1028957 ) // ACTOR9 = RYNE
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1028958 || param2 == 1028958 ) // ACTOR10 = ALPHINAUD
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1028959 || param2 == 1028959 ) // ACTOR11 = ALISAIE
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 2 );
      player.setQuestUI8CL( getId(), 1 );
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
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmb104:68841 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00002: Normal(Talk, TargetCanMove), id=AMAROA03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00003: Normal(Talk, TargetCanMove), id=AMAROB03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00004: Normal(Talk, TargetCanMove), id=AMAROC03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00005: Normal(Talk, TargetCanMove), id=AMAROD03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00008: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00009: Normal(Talk, TargetCanMove), id=AMAROA03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00010: Normal(Talk, TargetCanMove), id=AMAROB03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00011: Normal(Talk, TargetCanMove), id=AMAROC03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00012: Normal(Talk, TargetCanMove), id=AMAROD03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00013: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00014( player );
      }
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00014: Normal(Talk, TargetCanMove, SystemTalk), id=AMAROA03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00015: Normal(Talk, TargetCanMove), id=AMAROA03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00016: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00017( player );
      }
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00017: Normal(Talk, TargetCanMove, SystemTalk), id=AMAROB03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00018: Normal(Talk, TargetCanMove), id=AMAROB03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00019: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00020( player );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00020: Normal(Talk, TargetCanMove, SystemTalk), id=AMAROC03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00021: Normal(Talk, TargetCanMove), id=AMAROC03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00022: NpcTrade(TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00023( player );
      }
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00023: Normal(Talk, TargetCanMove, SystemTalk), id=AMAROD03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00024( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00024: Normal(Talk, TargetCanMove), id=AMAROD03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00025: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00026: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00027: Normal(Talk, TargetCanMove), id=AMAROA03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00028: Normal(Talk, TargetCanMove), id=AMAROB03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00029: Normal(Talk, TargetCanMove), id=AMAROC03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00030: Normal(Talk, TargetCanMove), id=AMAROD03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00031: Normal(Talk, QuestBattle, YesNo, TargetCanMove, SystemTalk, CanCancel), id=CRYSTARIUMGARDPICKET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00032( player );
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00032: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
      Scene00041( player );
    };
    player.playScene( getId(), 32, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00033: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00034: Normal(Talk, TargetCanMove), id=AMAROA03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00035: Normal(Talk, TargetCanMove), id=AMAROB03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00036: Normal(Talk, TargetCanMove), id=AMAROC03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00037: Normal(Talk, TargetCanMove), id=AMAROD03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00040: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00041: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
      Scene00042( player );
    };
    player.playScene( getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00042: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 816, -639.5, 126.3, 700, 2.33, false );
    };
    player.playScene( getId(), 42, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00043: Normal(YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.forceZoneing( 816, -639.5, 126.3, 700, 2.33, false );
      }
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00044: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
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
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00045: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00046: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "LucKmb104:68841 calling Scene00047: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb104 );
