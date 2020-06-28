// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse404 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse404() : Sapphire::ScriptAPI::EventScript( 65593 ){}; 
  ~GaiUse404() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 4 entries
  //SEQ_2, 9 entries
  //SEQ_3, 11 entries
  //SEQ_255, 6 entries

  //ACTOR0 = 1009976
  //ACTOR1 = 1009978
  //ACTOR2 = 1006384
  //ACTOR3 = 1009977
  //ACTOR4 = 1006401
  //ACTOR5 = 1009979
  //ACTOR6 = 1009980
  //ACTOR7 = 1009981
  //ACTOR8 = 1009982
  //ACTOR9 = 1009983
  //EOBJECT0 = 2004647
  //EOBJECT1 = 2004648
  //LOCACTOR0 = 5032467
  //LOCACTOR1 = 5032468
  //LOCACTOR2 = 4261335
  //LOCACTOR3 = 1014660
  //LOCMUSIC0 = 78
  //LOCMUSICNO = 1

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1009976 || actorId == 1009976 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1009978 || actorId == 1009978 ) // ACTOR1 = LUCIA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=LUCIA
        }
        break;
      }
      case 1:
      {
        if( actor == 1006384 || actorId == 1006384 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(FadeIn, TargetCanMove), id=unknown
          }
        }
        if( actor == 1009977 || actorId == 1009977 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1009978 || actorId == 1009978 ) // ACTOR1 = LUCIA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1006401 || actorId == 1006401 ) // ACTOR4 = YAELLE
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YAELLE
        }
        break;
      }
      case 2:
      {
        if( actor == 1009979 || actorId == 1009979 ) // ACTOR5 = FORTEMPSGUARD00057
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=FORTEMPSGUARD00057
          }
        }
        if( actor == 1009977 || actorId == 1009977 ) // ACTOR3 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1009978 || actorId == 1009978 ) // ACTOR1 = LUCIA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1009980 || actorId == 1009980 ) // ACTOR6 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        if( actor == 1009981 || actorId == 1009981 ) // ACTOR7 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 2004647 || actorId == 2004647 ) // EOBJECT0 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 2004648 || actorId == 2004648 ) // EOBJECT1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1006384 || actorId == 1006384 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1006401 || actorId == 1006401 ) // ACTOR4 = YAELLE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=YAELLE
        }
        break;
      }
      case 3:
      {
        if( actor == 1009982 || actorId == 1009982 ) // ACTOR8 = INJUREDSENTRY00057
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=INJUREDSENTRY00057
          }
        }
        if( actor == 1009983 || actorId == 1009983 ) // ACTOR9 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( actor == 1009977 || actorId == 1009977 ) // ACTOR3 = ALPHINAUD
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1009978 || actorId == 1009978 ) // ACTOR1 = LUCIA
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1009979 || actorId == 1009979 ) // ACTOR5 = FORTEMPSGUARD00057
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=FORTEMPSGUARD00057
        }
        if( actor == 1009980 || actorId == 1009980 ) // ACTOR6 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
        }
        if( actor == 1009981 || actorId == 1009981 ) // ACTOR7 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
        }
        if( actor == 2004647 || actorId == 2004647 ) // EOBJECT0 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
        }
        if( actor == 2004648 || actorId == 2004648 ) // EOBJECT1 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
        }
        if( actor == 1006384 || actorId == 1006384 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1006401 || actorId == 1006401 ) // ACTOR4 = YAELLE
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=YAELLE
        }
        break;
      }
      case 255:
      {
        if( actor == 1009977 || actorId == 1009977 ) // ACTOR3 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1009982 || actorId == 1009982 ) // ACTOR8 = INJUREDSENTRY00057
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=INJUREDSENTRY00057
        }
        if( actor == 1009983 || actorId == 1009983 ) // ACTOR9 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
        }
        if( actor == 1009978 || actorId == 1009978 ) // ACTOR1 = LUCIA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1006384 || actorId == 1006384 ) // ACTOR2 = HAURCHEFANT
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1006401 || actorId == 1006401 ) // ACTOR4 = YAELLE
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=YAELLE
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
    player.sendDebug( "GaiUse404:65593 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse404:65593 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00002: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00003: Normal(FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00005: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00006: Normal(Talk, TargetCanMove), id=YAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00007: Normal(Talk, TargetCanMove), id=FORTEMPSGUARD00057" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00009: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00010: Normal(None), id=unknown" );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00014: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00015: Normal(Talk, TargetCanMove), id=YAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00016: Normal(Talk, TargetCanMove), id=INJUREDSENTRY00057" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00018: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00019: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00020: Normal(Talk, TargetCanMove), id=FORTEMPSGUARD00057" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00021: Normal(None), id=unknown" );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00023: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00024: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00025: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00026: Normal(Talk, TargetCanMove), id=YAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00027: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 27, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00028: Normal(Talk, TargetCanMove), id=INJUREDSENTRY00057" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00030: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00031: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse404:65593 calling Scene00032: Normal(Talk, TargetCanMove), id=YAELLE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse404 );
