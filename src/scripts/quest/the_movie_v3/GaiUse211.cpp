// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse211 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse211() : Sapphire::ScriptAPI::EventScript( 66891 ){}; 
  ~GaiUse211() = default; 

  //SEQ_0, 15 entries
  //SEQ_1, 31 entries
  //SEQ_2, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1008663
  //ACTOR1 = 1008662
  //ACTOR10 = 1008672
  //ACTOR11 = 1008673
  //ACTOR12 = 1008674
  //ACTOR13 = 1008675
  //ACTOR14 = 1008541
  //ACTOR15 = 1008705
  //ACTOR16 = 1008565
  //ACTOR2 = 1008664
  //ACTOR3 = 1008665
  //ACTOR4 = 1008666
  //ACTOR5 = 1008667
  //ACTOR6 = 1008668
  //ACTOR7 = 1008669
  //ACTOR8 = 1008670
  //ACTOR9 = 1008671
  //BGMNOTHING = 1
  //CUTSCENEN01 = 464
  //CUTSCENEN02 = 465
  //CUTSCENEN03 = 466
  //ENEMY0 = 4622527
  //ENEMY1 = 4622528
  //ENEMY2 = 4622530
  //ENEMY3 = 4622531
  //ENEMY4 = 4622533
  //ENEMY5 = 4622534
  //ENEMY6 = 4622536
  //ENEMY7 = 4622537
  //ENEMY8 = 4622538
  //ENEMY9 = 4622539
  //EOBJECT0 = 2003579
  //EOBJECT1 = 2003580
  //EOBJECT2 = 2003581
  //EOBJECT3 = 2003582
  //EOBJECT4 = 2003583
  //EOBJECT5 = 2003584
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001212

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( actor == 1008663 || actorId == 1008663 ) // ACTOR0 = HONBUBOUKENSHA01354
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HONBUBOUKENSHA01354
        }
        if( actor == 1008662 || actorId == 1008662 ) // ACTOR1 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
        }
        if( actor == 1008664 || actorId == 1008664 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        if( actor == 1008665 || actorId == 1008665 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1008666 || actorId == 1008666 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 1008667 || actorId == 1008667 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( actor == 1008668 || actorId == 1008668 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1008669 || actorId == 1008669 ) // ACTOR7 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1008670 || actorId == 1008670 ) // ACTOR8 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
        }
        if( actor == 1008671 || actorId == 1008671 ) // ACTOR9 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1008672 || actorId == 1008672 ) // ACTOR10 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1008673 || actorId == 1008673 ) // ACTOR11 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 1008674 || actorId == 1008674 ) // ACTOR12 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1008675 || actorId == 1008675 ) // ACTOR13 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( actor == 1008541 || actorId == 1008541 ) // ACTOR14 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8DL max stack ?
      case 1:
      {
        if( actor == 2003579 || actorId == 2003579 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8DH( getId() ) != 2 )
          {
            Scene00016( player ); // Scene00016: Normal(Inventory), id=unknown
            // +Callback Scene00017: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4622527 || actorId == 4622527 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4622528 || actorId == 4622528 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2003580 || actorId == 2003580 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00018( player ); // Scene00018: Normal(Inventory), id=unknown
            // +Callback Scene00019: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4622530 || actorId == 4622530 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4622531 || actorId == 4622531 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 2003581 || actorId == 2003581 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00020( player ); // Scene00020: Normal(Inventory), id=unknown
            // +Callback Scene00021: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4622533 || actorId == 4622533 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        if( actor == 4622534 || actorId == 4622534 ) // ENEMY5 = unknown
        {
          // empty entry
        }
        if( actor == 2003582 || actorId == 2003582 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Inventory), id=unknown
            // +Callback Scene00023: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4622536 || actorId == 4622536 ) // ENEMY6 = unknown
        {
          // empty entry
        }
        if( actor == 2003583 || actorId == 2003583 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Inventory), id=unknown
            // +Callback Scene00025: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4622537 || actorId == 4622537 ) // ENEMY7 = unknown
        {
          // empty entry
        }
        if( actor == 2003584 || actorId == 2003584 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 2 )
          {
            Scene00026( player ); // Scene00026: Normal(Inventory), id=unknown
            // +Callback Scene00027: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4622538 || actorId == 4622538 ) // ENEMY8 = unknown
        {
          // empty entry
        }
        if( actor == 4622539 || actorId == 4622539 ) // ENEMY9 = unknown
        {
          // empty entry
        }
        if( actor == 1008662 || actorId == 1008662 ) // ACTOR1 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
        }
        if( actor == 1008663 || actorId == 1008663 ) // ACTOR0 = HONBUBOUKENSHA01354
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=HONBUBOUKENSHA01354
        }
        if( actor == 1008664 || actorId == 1008664 ) // ACTOR2 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
        }
        if( actor == 1008665 || actorId == 1008665 ) // ACTOR3 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( actor == 1008666 || actorId == 1008666 ) // ACTOR4 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( actor == 1008667 || actorId == 1008667 ) // ACTOR5 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        if( actor == 1008668 || actorId == 1008668 ) // ACTOR6 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        if( actor == 1008669 || actorId == 1008669 ) // ACTOR7 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        if( actor == 1008670 || actorId == 1008670 ) // ACTOR8 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
        }
        if( actor == 1008671 || actorId == 1008671 ) // ACTOR9 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
        }
        if( actor == 1008672 || actorId == 1008672 ) // ACTOR10 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
        }
        if( actor == 1008673 || actorId == 1008673 ) // ACTOR11 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
        }
        if( actor == 1008674 || actorId == 1008674 ) // ACTOR12 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        if( actor == 1008675 || actorId == 1008675 ) // ACTOR13 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( actor == 1008541 || actorId == 1008541 ) // ACTOR14 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        Scene00043( player ); // Scene00043: Normal(Talk, NpcDespawn, TargetCanMove), id=HONBUBOUKENSHA01354
        break;
      }
      case 255:
      {
        Scene00044( player ); // Scene00044: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown
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
    onProgress( player, param1, param1, 3, param1 );
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
    if( player.getQuestUI8DH( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 2 )
        if( player.getQuestUI8BH( getId() ) == 2 )
          if( player.getQuestUI8BL( getId() ) == 1 )
            if( player.getQuestUI8CH( getId() ) == 1 )
              if( player.getQuestUI8CL( getId() ) == 2 )
              {
                player.setQuestUI8DH( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8BH( getId(), 0 );
                player.setQuestUI8BL( getId(), 0 );
                player.setQuestUI8CH( getId(), 0 );
                player.setQuestUI8CL( getId(), 0 );
                player.setQuestUI8DL( getId(), 0 );
                player.updateQuest( getId(), 2 );
              }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse211:66891 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=HONBUBOUKENSHA01354" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00002: Normal(None), id=unknown" );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00008: Normal(None), id=unknown" );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00009: Normal(None), id=unknown" );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00016: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling [BranchTrue]Scene00017: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DH( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00018: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling [BranchTrue]Scene00019: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00020: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling [BranchTrue]Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00022: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling [BranchTrue]Scene00023: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00024: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00025( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling [BranchTrue]Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00026: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00027( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling [BranchTrue]Scene00027: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 2 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00029: Normal(Talk, TargetCanMove), id=HONBUBOUKENSHA01354" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00043: Normal(Talk, NpcDespawn, TargetCanMove), id=HONBUBOUKENSHA01354" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUse211:66891 calling Scene00044: Normal(CutScene, FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUse211 );
