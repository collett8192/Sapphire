// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna323 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna323() : Sapphire::ScriptAPI::EventScript( 67160 ){}; 
  ~HeaVna323() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 8 entries
  //SEQ_2, 8 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1012078
  //ACTOR1 = 1012664
  //ACTOR10 = 1012684
  //ACTOR2 = 1012680
  //ACTOR3 = 1012681
  //ACTOR4 = 1013589
  //ACTOR5 = 1013591
  //ACTOR6 = 1013592
  //ACTOR7 = 1013593
  //ACTOR8 = 1012682
  //ACTOR9 = 1012683
  //LOCACTOR0 = 5858217
  //LOCACTOR1 = 5888400
  //LOCACTOR2 = 5888314
  //LOCACTOR3 = 5888313
  //LOCACTOR4 = 5858496
  //LOCBGM0 = 73

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012078 || actorId == 1012078 ) // ACTOR0 = MOGHAN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=MOGHAN
        }
        if( actor == 1012664 || actorId == 1012664 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012680 || actorId == 1012680 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012681 || actorId == 1012681 ) // ACTOR3 = KUPLOKOPP
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=KUPLOKOPP
        }
        if( actor == 1013589 || actorId == 1013589 ) // ACTOR4 = KANESENNA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=KANESENNA
        }
        if( actor == 1013591 || actorId == 1013591 ) // ACTOR5 = BODYGUARD01412
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=BODYGUARD01412
        }
        if( actor == 1013592 || actorId == 1013592 ) // ACTOR6 = BODYGUARD01623
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=BODYGUARD01623
        }
        if( actor == 1013593 || actorId == 1013593 ) // ACTOR7 = ICEHEART
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ICEHEART
        }
        break;
      }
      case 1:
      {
        if( actor == 1012664 || actorId == 1012664 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1012680 || actorId == 1012680 ) // ACTOR2 = ESTINIEN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012681 || actorId == 1012681 ) // ACTOR3 = KUPLOKOPP
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=KUPLOKOPP
        }
        if( actor == 1012682 || actorId == 1012682 ) // ACTOR8 = MOGHAN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MOGHAN
        }
        if( actor == 1013589 || actorId == 1013589 ) // ACTOR4 = KANESENNA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=KANESENNA
        }
        if( actor == 1013591 || actorId == 1013591 ) // ACTOR5 = BODYGUARD01412
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=BODYGUARD01412
        }
        if( actor == 1013592 || actorId == 1013592 ) // ACTOR6 = BODYGUARD01623
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=BODYGUARD01623
        }
        if( actor == 1013593 || actorId == 1013593 ) // ACTOR7 = ICEHEART
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ICEHEART
        }
        break;
      }
      case 2:
      {
        if( actor == 1013589 || actorId == 1013589 ) // ACTOR4 = KANESENNA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=KANESENNA
          }
        }
        if( actor == 1012664 || actorId == 1012664 ) // ACTOR1 = ALPHINAUD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012680 || actorId == 1012680 ) // ACTOR2 = ESTINIEN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012681 || actorId == 1012681 ) // ACTOR3 = KUPLOKOPP
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=KUPLOKOPP
        }
        if( actor == 1013591 || actorId == 1013591 ) // ACTOR5 = BODYGUARD01412
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=BODYGUARD01412
        }
        if( actor == 1013592 || actorId == 1013592 ) // ACTOR6 = BODYGUARD01623
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=BODYGUARD01623
        }
        if( actor == 1013593 || actorId == 1013593 ) // ACTOR7 = ICEHEART
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ICEHEART
        }
        if( actor == 1012682 || actorId == 1012682 ) // ACTOR8 = MOGHAN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=MOGHAN
        }
        break;
      }
      case 255:
      {
        if( actor == 1012682 || actorId == 1012682 ) // ACTOR8 = MOGHAN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOGHAN
        }
        if( actor == 1012680 || actorId == 1012680 ) // ACTOR2 = ESTINIEN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012683 || actorId == 1012683 ) // ACTOR9 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012684 || actorId == 1012684 ) // ACTOR10 = ICEHEART
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ICEHEART
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna323:67160 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00004: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00005: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00006: Normal(Talk, TargetCanMove), id=BODYGUARD01412" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00007: Normal(Talk, TargetCanMove), id=BODYGUARD01623" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00008: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00010: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00011: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00012: Normal(Talk, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00013: Normal(Talk, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00014: Normal(Talk, TargetCanMove), id=BODYGUARD01412" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00015: Normal(Talk, TargetCanMove), id=BODYGUARD01623" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00016: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=KANESENNA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00019: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00020: Normal(Talk, TargetCanMove), id=KUPLOKOPP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00021: Normal(Talk, TargetCanMove), id=BODYGUARD01412" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00022: Normal(Talk, TargetCanMove), id=BODYGUARD01623" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00023: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00024: Normal(Talk, TargetCanMove), id=MOGHAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MOGHAN" );
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

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00026: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna323:67160 calling Scene00028: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna323 );
