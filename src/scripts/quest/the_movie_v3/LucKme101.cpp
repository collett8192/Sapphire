// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme101 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme101() : Sapphire::ScriptAPI::EventScript( 69166 ){}; 
  ~LucKme101() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 5 entries
  //SEQ_3, 8 entries
  //SEQ_255, 15 entries

  //ACTOR0 = 1027231
  //ACTOR1 = 1030165
  //ACTOR10 = 1030171
  //ACTOR11 = 1030172
  //ACTOR12 = 1030173
  //ACTOR13 = 1030174
  //ACTOR14 = 1030175
  //ACTOR15 = 1030176
  //ACTOR16 = 1030177
  //ACTOR17 = 1030178
  //ACTOR18 = 1030590
  //ACTOR19 = 1030591
  //ACTOR2 = 1030166
  //ACTOR20 = 1030592
  //ACTOR21 = 1030593
  //ACTOR22 = 1030594
  //ACTOR3 = 1028923
  //ACTOR4 = 1030163
  //ACTOR5 = 1030164
  //ACTOR6 = 1030169
  //ACTOR7 = 1030167
  //ACTOR8 = 1030168
  //ACTOR9 = 1030170
  //BINDACTOR01 = 7934809
  //CUTSCENE0 = 2038
  //ENEMY0 = 7943593
  //ENEMY1 = 7943594
  //POPRANGE0 = 7937639
  //TERRITORYTYPE0 = 844

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUIDEOFTHEPENDANTS
        break;
      }
      case 1:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00002( player ); // Scene00002: Normal(CutScene), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030165 || param2 == 1030165 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1030166 || param2 == 1030166 ) // ACTOR2 = RYNE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1028923 || param2 == 1028923 ) // ACTOR3 = MYSTERYVOICE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030163 || param2 == 1030163 ) // ACTOR4 = EMETSELCH
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove, Menu), id=EMETSELCH
          break;
        }
        if( param1 == 1030164 || param2 == 1030164 ) // ACTOR5 = LYNA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LYNA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030169 || param2 == 1030169 ) // ACTOR6 = SUSPICIOUSC03630
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=SUSPICIOUSC03630
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=SUSPICIOUSC03630
          }
          break;
        }
        if( param1 == 1030167 || param2 == 1030167 ) // ACTOR7 = SUSPICIOUSB03630
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=SUSPICIOUSB03630
          }
          break;
        }
        if( param1 == 7943593 || param2 == 7943593 ) // ENEMY0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00012: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7943594 || param2 == 7943594 ) // ENEMY1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1030168 || param2 == 1030168 ) // ACTOR8 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030170 || param2 == 1030170 ) // ACTOR9 = SUSPICIOUSA03630
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove, SystemTalk), id=SUSPICIOUSA03630
            // +Callback Scene00016: Normal(Talk, TargetCanMove), id=SUSPICIOUSA03630
          }
          break;
        }
        if( param1 == 1030165 || param2 == 1030165 ) // ACTOR1 = ALPHINAUD
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030166 || param2 == 1030166 ) // ACTOR2 = RYNE
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1030171 || param2 == 1030171 ) // ACTOR10 = THANCRED
        {
          Scene00019( player ); // Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030172 || param2 == 1030172 ) // ACTOR11 = URIANGER
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030173 || param2 == 1030173 ) // ACTOR12 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030174 || param2 == 1030174 ) // ACTOR13 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030175 || param2 == 1030175 ) // ACTOR14 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030176 || param2 == 1030176 ) // ACTOR15 = RESIDENT03630
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=RESIDENT03630
          break;
        }
        if( param1 == 1030177 || param2 == 1030177 ) // ACTOR16 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030178 || param2 == 1030178 ) // ACTOR17 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030169 || param2 == 1030169 ) // ACTOR6 = SUSPICIOUSC03630
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=SUSPICIOUSC03630
          break;
        }
        if( param1 == 1030170 || param2 == 1030170 ) // ACTOR9 = SUSPICIOUSA03630
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=SUSPICIOUSA03630
          break;
        }
        if( param1 == 1030590 || param2 == 1030590 ) // ACTOR18 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030591 || param2 == 1030591 ) // ACTOR19 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030592 || param2 == 1030592 ) // ACTOR20 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030593 || param2 == 1030593 ) // ACTOR21 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030594 || param2 == 1030594 ) // ACTOR22 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
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
    player.updateQuest( getId(), 2 );
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
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8BL( getId() ) == 2 )
        if( player.getQuestUI8AL( getId() ) == 1 )
        {
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme101:69166 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=GUIDEOFTHEPENDANTS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00002: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00004: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00005: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00006: Normal(Talk, TargetCanMove, Menu), id=EMETSELCH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00007: Normal(Talk, TargetCanMove), id=LYNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00008: Normal(Talk, TargetCanMove), id=SUSPICIOUSC03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00009: Normal(Talk, TargetCanMove), id=SUSPICIOUSC03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00010: Normal(Talk, TargetCanMove), id=SUSPICIOUSB03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 2 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00015: Normal(Talk, TargetCanMove, SystemTalk), id=SUSPICIOUSA03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00016( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00016: Normal(Talk, TargetCanMove), id=SUSPICIOUSA03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00017: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00018: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00019: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=THANCRED" );
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
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00020: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00023: Normal(None), id=unknown" );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00024: Normal(Talk, TargetCanMove), id=RESIDENT03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00026: Normal(None), id=unknown" );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00027: Normal(Talk, TargetCanMove), id=SUSPICIOUSC03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00028: Normal(Talk, TargetCanMove), id=SUSPICIOUSA03630" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKme101:69166 calling Scene00033: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKme101 );
