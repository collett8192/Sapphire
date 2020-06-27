// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa103 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa103() : Sapphire::ScriptAPI::EventScript( 66253 ){}; 
  ~GaiUsa103() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 8 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTBYEBYE = 962
  //ACTIONTIMELINEEVENTFIDGET = 968
  //ACTIONTIMELINEEVENTJOYBIG = 945
  //ACTIONTIMELINEEVENTLAUGH = 952
  //ACTIONTIMELINEEVENTTROUBLE = 944
  //ACTOR0 = 1006674
  //ACTOR1 = 1000563
  //ACTOR2 = 1000437
  //ACTOR3 = 1000576
  //ACTOR4 = 1000585
  //ACTOR5 = 1000584
  //ACTOR6 = 1000587
  //ACTOR7 = 1000578
  //ACTOR8 = 1000277

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=YDA
        break;
      }
      case 1:
      {
        if( actor == 1000563 || actorId == 1000563 ) // ACTOR1 = AMEEXIA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Talk, TargetCanMove), id=AMEEXIA
            // +Callback Scene00002: Normal(Talk, TargetCanMove), id=AMEEXIA
          }
          else
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=AMEEXIA
          }
        }
        if( actor == 1000437 || actorId == 1000437 ) // ACTOR2 = ZACHEUS
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ZACHEUS
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=ZACHEUS
          }
          else
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ZACHEUS
          }
        }
        if( actor == 1000576 || actorId == 1000576 ) // ACTOR3 = KNOLEXIA
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KNOLEXIA
            // +Callback Scene00008: Normal(Talk, TargetCanMove), id=KNOLEXIA
          }
          else
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=KNOLEXIA
          }
        }
        if( actor == 1000585 || actorId == 1000585 ) // ACTOR4 = PELIXIA
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=PELIXIA
            // +Callback Scene00011: Normal(Talk, TargetCanMove), id=PELIXIA
          }
          else
          {
            Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=PELIXIA
          }
        }
        if( actor == 1000584 || actorId == 1000584 ) // ACTOR5 = IMEDIA
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=IMEDIA
            // +Callback Scene00014: Normal(Talk, TargetCanMove), id=IMEDIA
          }
          else
          {
            Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=IMEDIA
          }
        }
        if( actor == 1000587 || actorId == 1000587 ) // ACTOR6 = DELLEXIA
        {
          if( player.getQuestUI8DH( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=DELLEXIA
            // +Callback Scene00017: Normal(Talk, TargetCanMove), id=DELLEXIA
          }
          else
          {
            Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=DELLEXIA
          }
        }
        if( actor == 1000578 || actorId == 1000578 ) // ACTOR7 = MARINTERRE
        {
          if( player.getQuestUI8DL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MARINTERRE
            // +Callback Scene00020: Normal(Talk, TargetCanMove), id=MARINTERRE
          }
          else
          {
            Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=MARINTERRE
          }
        }
        if( actor == 1000277 || actorId == 1000277 ) // ACTOR8 = NATHAXIO
        {
          if( player.getQuestUI8EH( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=NATHAXIO
            // +Callback Scene00023: Normal(Talk, TargetCanMove), id=NATHAXIO
          }
          else
          {
            Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=NATHAXIO
          }
        }
        break;
      }
      case 255:
      {
        Scene00025( player ); // Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YDA
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

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
          if( player.getQuestUI8CH( getId() ) == 1 )
            if( player.getQuestUI8CL( getId() ) == 1 )
              if( player.getQuestUI8DH( getId() ) == 1 )
                if( player.getQuestUI8DL( getId() ) == 1 )
                  if( player.getQuestUI8EH( getId() ) == 1 )
                  {
                    player.setQuestUI8AL( getId(), 0 );
                    player.setQuestUI8BH( getId(), 0 );
                    player.setQuestUI8BL( getId(), 0 );
                    player.setQuestUI8CH( getId(), 0 );
                    player.setQuestUI8CL( getId(), 0 );
                    player.setQuestUI8DH( getId(), 0 );
                    player.setQuestUI8DL( getId(), 0 );
                    player.setQuestUI8EH( getId(), 0 );
                    player.updateQuest( getId(), 255 );
                  }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00001: Normal(Talk, TargetCanMove), id=AMEEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchTrue]Scene00002: Normal(Talk, TargetCanMove), id=AMEEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchFalse]Scene00003: Normal(Talk, TargetCanMove), id=AMEEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00004: Normal(Talk, TargetCanMove), id=ZACHEUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=ZACHEUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchFalse]Scene00006: Normal(Talk, TargetCanMove), id=ZACHEUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00007: Normal(Talk, TargetCanMove), id=KNOLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchTrue]Scene00008: Normal(Talk, TargetCanMove), id=KNOLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchFalse]Scene00009: Normal(Talk, TargetCanMove), id=KNOLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00010: Normal(Talk, TargetCanMove), id=PELIXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00011( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }
  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchTrue]Scene00011: Normal(Talk, TargetCanMove), id=PELIXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchFalse]Scene00012: Normal(Talk, TargetCanMove), id=PELIXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00013: Normal(Talk, TargetCanMove), id=IMEDIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchTrue]Scene00014: Normal(Talk, TargetCanMove), id=IMEDIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchFalse]Scene00015: Normal(Talk, TargetCanMove), id=IMEDIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00016: Normal(Talk, TargetCanMove), id=DELLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchTrue]Scene00017: Normal(Talk, TargetCanMove), id=DELLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchFalse]Scene00018: Normal(Talk, TargetCanMove), id=DELLEXIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00019: Normal(Talk, TargetCanMove), id=MARINTERRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchTrue]Scene00020: Normal(Talk, TargetCanMove), id=MARINTERRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8DL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchFalse]Scene00021: Normal(Talk, TargetCanMove), id=MARINTERRE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00022: Normal(Talk, TargetCanMove), id=NATHAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00023( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchTrue]Scene00023: Normal(Talk, TargetCanMove), id=NATHAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8EH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling [BranchFalse]Scene00024: Normal(Talk, TargetCanMove), id=NATHAXIO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa103:66253 calling Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsa103 );
