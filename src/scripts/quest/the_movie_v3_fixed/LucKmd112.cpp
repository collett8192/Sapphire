// FFXIVTheMovie.ParserV3.2
// id hint used:
//ACTOR2 = GUTHJON
//_ACTOR2 SET!!
//SCENE_86 = GUTHJON
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmd112 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmd112() : Sapphire::ScriptAPI::EventScript( 69153 ){}; 
  ~LucKmd112() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 5 entries
  //SEQ_2, 2 entries
  //SEQ_3, 4 entries
  //SEQ_4, 32 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1029757
  //ACTOR1 = 1029758
  //ACTOR2 = 1029759
  //ACTOR3 = 1029760
  //ENEMY0 = 7969448
  //ENEMY1 = 7969452
  //ENEMY10 = 7969469
  //ENEMY11 = 7969470
  //ENEMY12 = 7969471
  //ENEMY13 = 7969472
  //ENEMY14 = 7969474
  //ENEMY15 = 7969437
  //ENEMY16 = 7969441
  //ENEMY17 = 7969443
  //ENEMY18 = 7969444
  //ENEMY19 = 7969445
  //ENEMY2 = 7969453
  //ENEMY20 = 7969447
  //ENEMY3 = 7969454
  //ENEMY4 = 7969457
  //ENEMY5 = 7969460
  //ENEMY6 = 7969461
  //ENEMY7 = 7969464
  //ENEMY8 = 7969465
  //ENEMY9 = 7969466
  //EOBJECT0 = 2010546
  //EOBJECT1 = 2010547
  //EOBJECT10 = 2010281
  //EOBJECT11 = 2010283
  //EOBJECT12 = 2010274
  //EOBJECT13 = 2010275
  //EOBJECT2 = 2010548
  //EOBJECT3 = 2010009
  //EOBJECT4 = 2009916
  //EOBJECT5 = 2009917
  //EOBJECT6 = 2009918
  //EOBJECT7 = 2010276
  //EOBJECT8 = 2010277
  //EOBJECT9 = 2010279
  //EVENTACTION0 = 54
  //EVENTACTION1 = 2
  //EVENTACTION2 = 1
  //ITEM0 = 2002562
  //ITEM1 = 2002563
  //LOCACTORTHANCRED = 1026569
  //LOCBINDACTOR0 = 7935071
  //LOCBINDACTOR1 = 7935095
  //NCUTEVENTLUCKMD11201 = 2026

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029757 || param2 == 1029757 ) // ACTOR0 = GUTHJON
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUTHJON
          break;
        }
        if( param1 == 1029758 || param2 == 1029758 ) // ACTOR1 = THANCRED
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2010546 || param2 == 2010546 ) // EOBJECT0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010547 || param2 == 2010547 ) // EOBJECT1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010548 || param2 == 2010548 ) // EOBJECT2 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029759 || param2 == 1029759 ) // ACTOR2 = GUTHJON
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=GUTHJON
          }
          break;
        }
        if( param1 == 1029760 || param2 == 1029760 ) // ACTOR3 = THANCRED
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2010546 || param2 == 2010546 ) // EOBJECT0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010547 || param2 == 2010547 ) // EOBJECT1 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
          break;
        }
        if( param1 == 2010548 || param2 == 2010548 ) // EOBJECT2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 2010009 || param2 == 2010009 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1029759 || param2 == 1029759 ) // ACTOR2 = GUTHJON
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GUTHJON
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      case 3:
      {
        if( param1 == 2009916 || param2 == 2009916 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00014( player ); // Scene00014: Normal(Inventory), id=unknown
            // +Callback Scene00015: Normal(QuestGimmickReaction, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009917 || param2 == 2009917 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00016( player ); // Scene00016: Normal(Inventory), id=unknown
            // +Callback Scene00017: Normal(QuestGimmickReaction, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009918 || param2 == 2009918 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00018( player ); // Scene00018: Normal(Inventory), id=unknown
            // +Callback Scene00019: Normal(QuestGimmickReaction, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1029759 || param2 == 1029759 ) // ACTOR2 = GUTHJON
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=GUTHJON
          break;
        }
        break;
      }
      //seq 4 event item ITEM1 = UI8EH max stack 7
      case 4:
      {
        if( param1 == 2010276 || param2 == 2010276 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8DL( getId() ) != 2 )
          {
            Scene00022( player ); // Scene00022: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 7969448 || param2 == 7969448 ) // ENEMY0 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7969452 || param2 == 7969452 ) // ENEMY1 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2010277 || param2 == 2010277 ) // EOBJECT8 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00028( player ); // Scene00028: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 7969453 || param2 == 7969453 ) // ENEMY2 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7969454 || param2 == 7969454 ) // ENEMY3 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7969457 || param2 == 7969457 ) // ENEMY4 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00034: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2010279 || param2 == 2010279 ) // EOBJECT9 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 3 )
          {
            Scene00036( player ); // Scene00036: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 7969460 || param2 == 7969460 ) // ENEMY5 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7969461 || param2 == 7969461 ) // ENEMY6 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7969464 || param2 == 7969464 ) // ENEMY7 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00042: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2010281 || param2 == 2010281 ) // EOBJECT10 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            Scene00044( player ); // Scene00044: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 7969465 || param2 == 7969465 ) // ENEMY8 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7969466 || param2 == 7969466 ) // ENEMY9 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7969469 || param2 == 7969469 ) // ENEMY10 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00050: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2010283 || param2 == 2010283 ) // EOBJECT11 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 4 )
          {
            Scene00052( player ); // Scene00052: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 7969470 || param2 == 7969470 ) // ENEMY11 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7969471 || param2 == 7969471 ) // ENEMY12 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7969472 || param2 == 7969472 ) // ENEMY13 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7969474 || param2 == 7969474 ) // ENEMY14 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00060: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 1029759 || param2 == 1029759 ) // ACTOR2 = GUTHJON
        {
          if( player.getQuestUI8CL( getId() ) != 2 )
          {
            Scene00061( player ); // Scene00061: Normal(Talk, TargetCanMove), id=GUTHJON
          }
          break;
        }
        if( param1 == 2009916 || param2 == 2009916 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 2 )
          {
            Scene00063( player ); // Scene00063: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2009917 || param2 == 2009917 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8DH( getId() ) != 4 )
          {
            Scene00065( player ); // Scene00065: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2009918 || param2 == 2009918 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8DH( getId() ) != 4 )
          {
            Scene00067( player ); // Scene00067: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2010274 || param2 == 2010274 ) // EOBJECT12 = unknown
        {
          if( player.getQuestUI8DH( getId() ) != 4 )
          {
            Scene00069( player ); // Scene00069: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 7969437 || param2 == 7969437 ) // ENEMY15 = unknown
        {
          Scene00071( player ); // Scene00071: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7969441 || param2 == 7969441 ) // ENEMY16 = unknown
        {
          Scene00073( player ); // Scene00073: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2010275 || param2 == 2010275 ) // EOBJECT13 = unknown
        {
          if( player.getQuestUI8DH( getId() ) != 4 )
          {
            Scene00075( player ); // Scene00075: Normal(Message), id=unknown
          }
          break;
        }
        if( param1 == 7969443 || param2 == 7969443 ) // ENEMY17 = unknown
        {
          // empty entry
          break;
        }
        if( param1 == 7969444 || param2 == 7969444 ) // ENEMY18 = unknown
        {
          Scene00077( player ); // Scene00077: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7969445 || param2 == 7969445 ) // ENEMY19 = unknown
        {
          Scene00079( player ); // Scene00079: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 7969447 || param2 == 7969447 ) // ENEMY20 = unknown
        {
          Scene00081( player ); // Scene00081: Normal(Message, PopBNpc), id=unknown
          // +Callback Scene00083: Normal(Message, PopBNpc), id=unknown
          break;
        }
        break;
      }
      //seq 255 event item ITEM1 = UI8BH max stack 7
      case 255:
      {
        if( param1 == 1029759 || param2 == 1029759 ) // ACTOR2 = GUTHJON
        {
          Scene00084( player ); // Scene00084: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00085: Normal(Talk, TargetCanMove), id=GUTHJON
          // +Callback Scene00086: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=GUTHJON
          break;
        }
        if( param1 == 1029760 || param2 == 1029760 ) // ACTOR3 = THANCRED
        {
          Scene00087( player ); // Scene00087: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 2009916 || param2 == 2009916 ) // EOBJECT4 = unknown
        {
          Scene00089( player ); // Scene00089: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009917 || param2 == 2009917 ) // EOBJECT5 = unknown
        {
          Scene00091( player ); // Scene00091: Normal(None), id=unknown
          break;
        }
        if( param1 == 2009918 || param2 == 2009918 ) // EOBJECT6 = unknown
        {
          Scene00093( player ); // Scene00093: Normal(None), id=unknown
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
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    //if( player.getQuestUI8DL( getId() ) == 2 )
      //if( player.getQuestUI8AL( getId() ) == 3 )
        //if( player.getQuestUI8BH( getId() ) == 3 )
          //if( player.getQuestUI8BL( getId() ) == 3 )
            //if( player.getQuestUI8CH( getId() ) == 4 )
              //if( player.getQuestUI8CL( getId() ) == 2 )
                //if( player.getQuestUI8DH( getId() ) == 4 )
                {
                  player.setQuestUI8DL( getId(), 0 );
                  player.setQuestUI8AL( getId(), 0 );
                  player.setQuestUI8BH( getId(), 0 );
                  player.setQuestUI8BL( getId(), 0 );
                  player.setQuestUI8CH( getId(), 0 );
                  player.setQuestUI8CL( getId(), 0 );
                  player.setQuestUI8DH( getId(), 0 );
                  player.setQuestUI8EH( getId(), 0 );
                  player.updateQuest( getId(), 255 );
                  player.setQuestUI8BH( getId(), 7 );
                }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmd112:69153 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00002: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq0( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq0( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq0( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00007: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00013: Normal(Talk, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00014: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00015: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00016: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00017: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00018: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00019: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00020: Normal(Talk, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00022: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DL( getId(), 2 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00024: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00026: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00028: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }


  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00030: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00032: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00034( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00034: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00036: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 3 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 36, NONE, callback );
  }


  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00038: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00040: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00042( player );
    };
    player.playScene( getId(), 40, NONE, callback );
  }
  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00042: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00044: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 3 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 44, NONE, callback );
  }


  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00046: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00048: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00050( player );
    };
    player.playScene( getId(), 48, NONE, callback );
  }
  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00050: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00052: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 4 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 52, NONE, callback );
  }


  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00054: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00056: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00058: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00060( player );
    };
    player.playScene( getId(), 58, NONE, callback );
  }
  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00060: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00061: Normal(Talk, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 2 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00063: Normal(None), id=unknown" );
    player.setQuestUI8CL( getId(), 2 );
    checkProgressSeq4( player );
  }

  void Scene00065( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00065: Normal(None), id=unknown" );
    player.setQuestUI8DH( getId(), 4 );
    checkProgressSeq4( player );
  }

  void Scene00067( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00067: Normal(None), id=unknown" );
    player.setQuestUI8DH( getId(), 4 );
    checkProgressSeq4( player );
  }

  void Scene00069( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00069: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DH( getId(), 4 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 69, NONE, callback );
  }

  void Scene00071( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00071: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 71, NONE, callback );
  }

  void Scene00073( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00073: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 73, NONE, callback );
  }

  void Scene00075( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00075: Normal(Message), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DH( getId(), 4 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 75, NONE, callback );
  }


  void Scene00077( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00077: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 77, NONE, callback );
  }

  void Scene00079( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00079: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 79, NONE, callback );
  }

  void Scene00081( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00081: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00083( player );
    };
    player.playScene( getId(), 81, NONE, callback );
  }
  void Scene00083( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00083: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 83, NONE, callback );
  }

  void Scene00084( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00084: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00085( player );
      }
    };
    player.playScene( getId(), 84, NONE, callback );
  }
  void Scene00085( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00085: Normal(Talk, TargetCanMove), id=GUTHJON" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00086( player );
    };
    player.playScene( getId(), 85, NONE, callback );
  }
  void Scene00086( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00086: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=GUTHJON" );
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
    player.playScene( getId(), 86, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00087( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00087: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 87, NONE, callback );
  }

  void Scene00089( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00089: Normal(None), id=unknown" );
  }

  void Scene00091( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00091: Normal(None), id=unknown" );
  }

  void Scene00093( Entity::Player& player )
  {
    player.sendDebug( "LucKmd112:69153 calling Scene00093: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( LucKmd112 );
