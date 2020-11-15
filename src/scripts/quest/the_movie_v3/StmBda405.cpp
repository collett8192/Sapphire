// FFXIVTheMovie.ParserV3.2
// id hint used:
//ENEMY10 = e10
//ENEMY11 = e11
//SCENE_40 = e10
//SCENE_42 = e11
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda405 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda405() : Sapphire::ScriptAPI::EventScript( 68040 ){}; 
  ~StmBda405() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 3 entries
  //SEQ_2, 18 entries
  //SEQ_3, 1 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1020501
  //ACTOR1 = 1020545
  //ACTOR2 = 1020544
  //ACTOR3 = 1020546
  //ACTOR4 = 1020548
  //ACTOR5 = 1020547
  //ENEMY0 = 6873256
  //ENEMY1 = 6873257
  //ENEMY10 = 6907331
  //ENEMY11 = 6907332
  //ENEMY2 = 6873263
  //ENEMY3 = 6873264
  //ENEMY4 = 6905012
  //ENEMY5 = 6905013
  //ENEMY6 = 6907208
  //ENEMY7 = 6907206
  //ENEMY8 = 6907344
  //ENEMY9 = 6907346
  //EOBJECT0 = 2008128
  //EOBJECT1 = 2008129
  //EOBJECT2 = 2008131
  //EOBJECT3 = 2008456
  //EOBJECT4 = 2008457
  //ITEM0 = 2002199
  //ITEM1 = 2002196
  //ITEM2 = 2002197
  //LOCGOSETSU001 = 6851401
  //LOCHIEN001 = 6851400
  //LOCHIEN002 = 1019544
  //LOCLAUGHBIG = 4312
  //LOCLISE001 = 6851397

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020545 || param2 == 1020545 ) // ACTOR1 = LYSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020544 || param2 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020546 || param2 == 1020546 ) // ACTOR3 = GOSETSU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 1020548 || param2 == 1020548 ) // ACTOR4 = HIEN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN
          }
          break;
        }
        if( param1 == 1020547 || param2 == 1020547 ) // ACTOR5 = GOSETSU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        break;
      }
      //seq 2 event item ITEM1 = UI8DH max stack ?
      //seq 2 event item ITEM0 = UI8DL max stack ?
      case 2:
      {
        if( param1 == 2008128 || param2 == 2008128 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
            // +Callback Scene00009: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 6873256 || param2 == 6873256 ) // ENEMY0 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 6873257 || param2 == 6873257 ) // ENEMY1 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6873263 || param2 == 6873263 ) // ENEMY2 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00015: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1020547 || param2 == 1020547 ) // ACTOR5 = GOSETSU
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU
          }
          break;
        }
        if( param1 == 2008129 || param2 == 2008129 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00017( player ); // Scene00017: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
            // +Callback Scene00018: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 6873264 || param2 == 6873264 ) // ENEMY3 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 6905012 || param2 == 6905012 ) // ENEMY4 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6905013 || param2 == 6905013 ) // ENEMY5 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2008131 || param2 == 2008131 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            Scene00024( player ); // Scene00024: Normal(Message, PopBNpc), id=unknown
            // +Callback Scene00025: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
          }
          break;
        }
        if( param1 == 6907208 || param2 == 6907208 ) // ENEMY6 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6907206 || param2 == 6907206 ) // ENEMY7 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2008456 || param2 == 2008456 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 2 )
          {
            Scene00030( player ); // Scene00030: Normal(Message, PopBNpc), id=unknown
            // +Callback Scene00031: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
          }
          break;
        }
        if( param1 == 6907344 || param2 == 6907344 ) // ENEMY8 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 6907346 || param2 == 6907346 ) // ENEMY9 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2008457 || param2 == 2008457 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00036( player ); // Scene00036: Normal(Message, PopBNpc), id=unknown
            // +Callback Scene00037: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown
          }
          break;
        }
        if( param1 == 6907331 || param2 == 6907331 ) // ENEMY10 = e10
        {
          Scene00038( player ); // Scene00038: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00040: Normal(Message, PopBNpc), id=e10
          break;
        }
        if( param1 == 6907332 || param2 == 6907332 ) // ENEMY11 = e11
        {
          Scene00042( player ); // Scene00042: Normal(Message, PopBNpc), id=e11
          break;
        }
        break;
      }
      //seq 3 event item ITEM1 = UI8BH max stack ?
      //seq 3 event item ITEM2 = UI8BL max stack 1
      case 3:
      {
        Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=GOSETSU
        // +Callback Scene00044: Normal(Talk, FadeIn, TargetCanMove), id=GOSETSU
        break;
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack ?
      //seq 255 event item ITEM2 = UI8BL max stack 1
      case 255:
      {
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00045( player ); // Scene00045: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020546 || param2 == 1020546 ) // ACTOR3 = GOSETSU
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020544 || param2 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=HIEN
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
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8CL( getId() ) == 3 )
      if( player.getQuestUI8BH( getId() ) == 3 )
        if( player.getQuestUI8BL( getId() ) == 2 )
          if( player.getQuestUI8CH( getId() ) == 2 )
            if( player.getQuestUI8AL( getId() ) == 2 )
            {
              player.setQuestUI8CL( getId(), 0 );
              player.setQuestUI8BH( getId(), 0 );
              player.setQuestUI8BL( getId(), 0 );
              player.setQuestUI8CH( getId(), 0 );
              player.setQuestUI8AL( getId(), 0 );
              player.setQuestUI8DH( getId(), 0 );
              player.setQuestUI8DL( getId(), 0 );
              player.updateQuest( getId(), 3 );
            }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 1 );
    player.setQuestUI8BL( getId(), 1 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda405:68040 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00002: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00003: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00004: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00007: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00008: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 3 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00011: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00013: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00016: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 3 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00017: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00018( player );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00018: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 3 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00022: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00025: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8BL( getId(), 2 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00026: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00028: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00030: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00031( player );
    };
    player.playScene( getId(), 30, NONE, callback );
  }
  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00031: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8CH( getId(), 2 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00032: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00034: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00036: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00037( player );
    };
    player.playScene( getId(), 36, NONE, callback );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00037: Normal(YesNo, Message, Inventory, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 2 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00038: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00040( player );
    };
    player.playScene( getId(), 38, NONE, callback );
  }
  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00040: Normal(Message, PopBNpc), id=e10" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00042: Normal(Message, PopBNpc), id=e11" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00043: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00044( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }
  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00044: Normal(Talk, FadeIn, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00045: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00046( player );
      }
    };
    player.playScene( getId(), 45, NONE, callback );
  }
  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00046: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=CIRINA" );
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
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00047: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "StmBda405:68040 calling Scene00048: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda405 );
