// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmb103 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmb103() : Sapphire::ScriptAPI::EventScript( 68840 ){}; 
  ~LucKmb103() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 7 entries
  //SEQ_3, 11 entries
  //SEQ_4, 6 entries
  //SEQ_255, 6 entries

  //ACTIONTIMELINEEVENTBOUND = 967
  //ACTIONTIMELINEEVENTLAUGH = 952
  //ACTOR0 = 1027246
  //ACTOR1 = 1028945
  //ACTOR10 = 1028947
  //ACTOR11 = 1027395
  //ACTOR2 = 1028948
  //ACTOR3 = 1028949
  //ACTOR4 = 1028950
  //ACTOR5 = 1028946
  //ACTOR6 = 1028951
  //ACTOR7 = 1028952
  //ACTOR8 = 1028953
  //ACTOR9 = 1028954
  //BINDACTOR0 = 7921384
  //BINDACTOR1 = 7791282
  //EOBJECT0 = 2010711
  //EOBJECT1 = 2010712
  //EVENTRANGE0 = 7943934
  //EVENTRANGE1 = 7943955
  //MOUNT0 = 198
  //POPRANGE0 = 7943918

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=SZEMDJENMAI
        break;
      }
      case 1:
      {
        if( param1 == 1028945 || param2 == 1028945 ) // ACTOR1 = SZEMDJENMAI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=SZEMDJENMAI
          }
          break;
        }
        if( param1 == 1028948 || param2 == 1028948 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 7943934 || param2 == 7943934 ) // EVENTRANGE0 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(Talk, SystemTalk), id=unknown
          break;
        }
        if( param1 == 1028945 || param2 == 1028945 ) // ACTOR1 = SZEMDJENMAI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SZEMDJENMAI
          break;
        }
        if( param1 == 1028948 || param2 == 1028948 ) // ACTOR2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028949 || param2 == 1028949 ) // ACTOR3 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028950 || param2 == 1028950 ) // ACTOR4 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028946 || param2 == 1028946 ) // ACTOR5 = SOLDIEROFWATCHTOWER03304
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=SOLDIEROFWATCHTOWER03304
          break;
        }
        if( param1 == 2010711 || param2 == 2010711 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 7943955 || param2 == 7943955 ) // EVENTRANGE1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(Talk, Dismount, SystemTalk), id=unknown
          break;
        }
        if( param1 == 1028946 || param2 == 1028946 ) // ACTOR5 = SOLDIEROFWATCHTOWER03304
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=SOLDIEROFWATCHTOWER03304
          break;
        }
        if( param1 == 1028949 || param2 == 1028949 ) // ACTOR3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028950 || param2 == 1028950 ) // ACTOR4 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1028951 || param2 == 1028951 ) // ACTOR6 = AMAROA03304
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=AMAROA03304
          break;
        }
        if( param1 == 1028952 || param2 == 1028952 ) // ACTOR7 = AMAROB03304
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=AMAROB03304
          break;
        }
        if( param1 == 1028953 || param2 == 1028953 ) // ACTOR8 = AMAROC03304
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=AMAROC03304
          break;
        }
        if( param1 == 1028954 || param2 == 1028954 ) // ACTOR9 = AMAROD03304
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=AMAROD03304
          break;
        }
        if( param1 == 1028947 || param2 == 1028947 ) // ACTOR10 = LYNA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1027395 || param2 == 1027395 ) // ACTOR11 = SZELIVANTHEU
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=SZELIVANTHEU
          break;
        }
        if( param1 == 2010712 || param2 == 2010712 ) // EOBJECT1 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1027395 || param2 == 1027395 ) // ACTOR11 = SZELIVANTHEU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=SZELIVANTHEU
          }
          break;
        }
        if( param1 == 1028951 || param2 == 1028951 ) // ACTOR6 = AMAROA03304
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=AMAROA03304
          break;
        }
        if( param1 == 1028952 || param2 == 1028952 ) // ACTOR7 = AMAROB03304
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=AMAROB03304
          break;
        }
        if( param1 == 1028953 || param2 == 1028953 ) // ACTOR8 = AMAROC03304
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=AMAROC03304
          break;
        }
        if( param1 == 1028954 || param2 == 1028954 ) // ACTOR9 = AMAROD03304
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=AMAROD03304
          break;
        }
        if( param1 == 1028947 || param2 == 1028947 ) // ACTOR10 = LYNA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1028947 || param2 == 1028947 ) // ACTOR10 = LYNA
        {
          Scene00028( player ); // Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYNA
          break;
        }
        if( param1 == 1028951 || param2 == 1028951 ) // ACTOR6 = AMAROA03304
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=AMAROA03304
          break;
        }
        if( param1 == 1028952 || param2 == 1028952 ) // ACTOR7 = AMAROB03304
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=AMAROB03304
          break;
        }
        if( param1 == 1028953 || param2 == 1028953 ) // ACTOR8 = AMAROC03304
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=AMAROC03304
          break;
        }
        if( param1 == 1028954 || param2 == 1028954 ) // ACTOR9 = AMAROD03304
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=AMAROD03304
          break;
        }
        if( param1 == 1027395 || param2 == 1027395 ) // ACTOR11 = SZELIVANTHEU
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=SZELIVANTHEU
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
    player.updateQuest( getId(), 4 );
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
    player.sendDebug( "LucKmb103:68840 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmb103:68840 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove, AutoFadeIn), id=SZEMDJENMAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00002: Normal(Talk, TargetCanMove), id=SZEMDJENMAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
      player.eventFinish( getId(), 1 );
      player.mount( 198 );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00004: Normal(Talk, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00005: Normal(Talk, TargetCanMove), id=SZEMDJENMAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.eventFinish( getId(), 1 );
      player.mount( 198 );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00009: Normal(Talk, TargetCanMove), id=SOLDIEROFWATCHTOWER03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00011: Normal(Talk, Dismount, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00012: Normal(Talk, TargetCanMove), id=SOLDIEROFWATCHTOWER03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.eventFinish( getId(), 1 );
      player.mount( 198 );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00015: Normal(Talk, TargetCanMove), id=AMAROA03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00016: Normal(Talk, TargetCanMove), id=AMAROB03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00017: Normal(Talk, TargetCanMove), id=AMAROC03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00018: Normal(Talk, TargetCanMove), id=AMAROD03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00019: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00020: Normal(Talk, TargetCanMove), id=SZELIVANTHEU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00022: Normal(Talk, TargetCanMove), id=SZELIVANTHEU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00023: Normal(Talk, TargetCanMove), id=AMAROA03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00024: Normal(Talk, TargetCanMove), id=AMAROB03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00025: Normal(Talk, TargetCanMove), id=AMAROC03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00026: Normal(Talk, TargetCanMove), id=AMAROD03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00027: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00028: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=LYNA" );
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
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00029: Normal(Talk, TargetCanMove), id=AMAROA03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00030: Normal(Talk, TargetCanMove), id=AMAROB03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00031: Normal(Talk, TargetCanMove), id=AMAROC03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00032: Normal(Talk, TargetCanMove), id=AMAROD03304" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmb103:68840 calling Scene00033: Normal(Talk, TargetCanMove), id=SZELIVANTHEU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmb103 );
