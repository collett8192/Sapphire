// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsb811 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsb811() : Sapphire::ScriptAPI::EventScript( 66456 ){}; 
  ~GaiUsb811() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 13 entries
  //SEQ_3, 4 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1006438
  //ACTOR1 = 1006718
  //ENEMY0 = 4293195
  //ENEMY1 = 4293196
  //ENEMY2 = 4293197
  //ENEMY3 = 4293198
  //ENEMY4 = 4293199
  //ENEMY5 = 4293200
  //EOBJECT0 = 2002620
  //EOBJECT1 = 2002621
  //EOBJECT2 = 2002622
  //EOBJECT3 = 2002153
  //EOBJECT4 = 2002154
  //EOBJECT5 = 2002155
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONSEARCHMIDDLE = 3
  //EVENTACTIONSEARCHSHORT = 2

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PAPAWAZU
        break;
      }
      case 1:
      {
        if( actor == 1006718 || actorId == 1006718 ) // ACTOR1 = NPCA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=NPCA
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=NPCA
          }
          else
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=NPCA
          }
        }
        if( actor == 2002620 || actorId == 2002620 ) // EOBJECT0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          // +Callback Scene00006: Normal(None), id=unknown
        }
        if( actor == 2002621 || actorId == 2002621 ) // EOBJECT1 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          // +Callback Scene00008: Normal(None), id=unknown
        }
        if( actor == 2002622 || actorId == 2002622 ) // EOBJECT2 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          // +Callback Scene00010: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 2002153 || actorId == 2002153 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00011( player ); // Scene00011: Normal(None), id=unknown
            // +Callback Scene00012: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4293195 || actorId == 4293195 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 4293196 || actorId == 4293196 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002154 || actorId == 2002154 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00013( player ); // Scene00013: Normal(None), id=unknown
            // +Callback Scene00014: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4293197 || actorId == 4293197 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 4293198 || actorId == 4293198 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 2002155 || actorId == 2002155 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            Scene00015( player ); // Scene00015: Normal(None), id=unknown
            // +Callback Scene00016: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4293199 || actorId == 4293199 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        if( actor == 4293200 || actorId == 4293200 ) // ENEMY5 = unknown
        {
          // empty entry
        }
        if( actor == 1006718 || actorId == 1006718 ) // ACTOR1 = NPCA
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=NPCA
        }
        if( actor == 2002620 || actorId == 2002620 ) // EOBJECT0 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          // +Callback Scene00019: Normal(None), id=unknown
        }
        if( actor == 2002621 || actorId == 2002621 ) // EOBJECT1 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(None), id=unknown
        }
        if( actor == 2002622 || actorId == 2002622 ) // EOBJECT2 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          // +Callback Scene00023: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1006718 || actorId == 1006718 ) // ACTOR1 = NPCA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=NPCA
          }
        }
        if( actor == 2002620 || actorId == 2002620 ) // EOBJECT0 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          // +Callback Scene00026: Normal(None), id=unknown
        }
        if( actor == 2002621 || actorId == 2002621 ) // EOBJECT1 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          // +Callback Scene00028: Normal(None), id=unknown
        }
        if( actor == 2002622 || actorId == 2002622 ) // EOBJECT2 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          // +Callback Scene00030: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1006438 || actorId == 1006438 ) // ACTOR0 = PAPAWAZU
        {
          Scene00031( player ); // Scene00031: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAPAWAZU
        }
        if( actor == 1006718 || actorId == 1006718 ) // ACTOR1 = NPCA
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=NPCA
        }
        if( actor == 2002620 || actorId == 2002620 ) // EOBJECT0 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          // +Callback Scene00034: Normal(None), id=unknown
        }
        if( actor == 2002621 || actorId == 2002621 ) // EOBJECT1 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          // +Callback Scene00036: Normal(None), id=unknown
        }
        if( actor == 2002622 || actorId == 2002622 ) // EOBJECT2 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          // +Callback Scene00038: Normal(None), id=unknown
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
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
      if( player.getQuestUI8BH( getId() ) == 2 )
        if( player.getQuestUI8BL( getId() ) == 2 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.updateQuest( getId(), 3 );
        }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=PAPAWAZU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00002: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00003: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchFalse]Scene00004: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00005: Normal(None), id=unknown" );
    Scene00006( player );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00007: Normal(None), id=unknown" );
    Scene00008( player );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00008: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00009: Normal(None), id=unknown" );
    Scene00010( player );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00010: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00013: Normal(None), id=unknown" );
    Scene00014( player );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00015: Normal(None), id=unknown" );
    Scene00016( player );
  }
  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00016: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 2 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00017: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00018: Normal(None), id=unknown" );
    Scene00019( player );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00021: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00022: Normal(None), id=unknown" );
    Scene00023( player );
  }
  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00023: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00024: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00025: Normal(None), id=unknown" );
    Scene00026( player );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00026: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00027: Normal(None), id=unknown" );
    Scene00028( player );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00028: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00029: Normal(None), id=unknown" );
    Scene00030( player );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00030: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00031: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAPAWAZU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00032: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00033: Normal(None), id=unknown" );
    Scene00034( player );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00035: Normal(None), id=unknown" );
    Scene00036( player );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling Scene00037: Normal(None), id=unknown" );
    Scene00038( player );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUsb811:66456 calling [BranchTrue]Scene00038: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsb811 );
