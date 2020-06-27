// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse315 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse315() : Sapphire::ScriptAPI::EventScript( 66992 ){}; 
  ~GaiUse315() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 7 entries
  //SEQ_255, 17 entries

  //ACTIONTIMELINEFACIALLAUGHSTRONG = 609
  //ACTIONTIMELINEFACIALSMILE = 605
  //ACTOR0 = 1009058
  //ACTOR1 = 1008980
  //ACTOR10 = 1008993
  //ACTOR11 = 1008994
  //ACTOR12 = 1008995
  //ACTOR13 = 1008996
  //ACTOR14 = 1008997
  //ACTOR15 = 1008998
  //ACTOR16 = 1008999
  //ACTOR17 = 1009000
  //ACTOR18 = 1009001
  //ACTOR19 = 1009002
  //ACTOR2 = 1009282
  //ACTOR20 = 1009003
  //ACTOR21 = 1009004
  //ACTOR22 = 1009005
  //ACTOR23 = 1009006
  //ACTOR24 = 1009007
  //ACTOR3 = 1009283
  //ACTOR4 = 1009284
  //ACTOR5 = 1009285
  //ACTOR6 = 1009286
  //ACTOR7 = 1009287
  //ACTOR8 = 1009021
  //ACTOR9 = 1008969
  //EOBJECT0 = 2004306
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 4725232
  //LOCACTOR1 = 4725233
  //LOCACTOR2 = 4725234
  //LOCACTOR3 = 4725226
  //LOCACTOR4 = 4725227
  //QUESTBATTLE0 = 89
  //TERRITORYTYPE0 = 379

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU
        break;
      }
      case 1:
      {
        if( actor == 1008980 || actorId == 1008980 ) // ACTOR1 = YOUZAN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=YOUZAN
          }
        }
        if( actor == 1009058 || actorId == 1009058 ) // ACTOR0 = TATARU
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=TATARU
        }
        break;
      }
      case 2:
      {
        if( actor == 1009282 || actorId == 1009282 ) // ACTOR2 = HOARYBOULDER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=HOARYBOULDER
          }
        }
        if( actor == 1009283 || actorId == 1009283 ) // ACTOR3 = COULTENET
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=COULTENET
        }
        if( actor == 1009284 || actorId == 1009284 ) // ACTOR4 = YOUZAN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YOUZAN
        }
        if( actor == 1009285 || actorId == 1009285 ) // ACTOR5 = KOHARU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KOHARU
        }
        if( actor == 1009286 || actorId == 1009286 ) // ACTOR6 = SHIUN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=SHIUN
        }
        if( actor == 1009287 || actorId == 1009287 ) // ACTOR7 = ROKKA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ROKKA
        }
        if( actor == 2004306 || actorId == 2004306 ) // EOBJECT0 = unknown
        {
          Scene00010( player ); // Scene00010: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1009021 || actorId == 1009021 ) // ACTOR8 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR9 = MINFILIA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1008993 || actorId == 1008993 ) // ACTOR10 = THANCRED
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1008994 || actorId == 1008994 ) // ACTOR11 = YDA
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1008995 || actorId == 1008995 ) // ACTOR12 = PAPALYMO
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1008996 || actorId == 1008996 ) // ACTOR13 = YSHTOLA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1008997 || actorId == 1008997 ) // ACTOR14 = TATARU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1008998 || actorId == 1008998 ) // ACTOR15 = FLHAMINN
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=FLHAMINN
        }
        if( actor == 1008999 || actorId == 1008999 ) // ACTOR16 = HOARYBOULDER
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=HOARYBOULDER
        }
        if( actor == 1009000 || actorId == 1009000 ) // ACTOR17 = COULTENET
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=COULTENET
        }
        if( actor == 1009001 || actorId == 1009001 ) // ACTOR18 = HOUZAN
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HOUZAN
        }
        if( actor == 1009002 || actorId == 1009002 ) // ACTOR19 = DOUWARE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=DOUWARE
        }
        if( actor == 1009003 || actorId == 1009003 ) // ACTOR20 = HIGIRI
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=HIGIRI
        }
        if( actor == 1009004 || actorId == 1009004 ) // ACTOR21 = YOUZAN
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YOUZAN
        }
        if( actor == 1009005 || actorId == 1009005 ) // ACTOR22 = KOHARU
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=KOHARU
        }
        if( actor == 1009006 || actorId == 1009006 ) // ACTOR23 = SHIUN
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=SHIUN
        }
        if( actor == 1009007 || actorId == 1009007 ) // ACTOR24 = ROKKA
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ROKKA
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse315:66992 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=YOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00003: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00004: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq2( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00005: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00006: Normal(Talk, TargetCanMove), id=YOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00007: Normal(Talk, TargetCanMove), id=KOHARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00008: Normal(Talk, TargetCanMove), id=SHIUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00009: Normal(Talk, TargetCanMove), id=ROKKA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00010: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00012: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00013: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00014: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00015: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00017: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00018: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00019: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00020: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00021: Normal(Talk, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00022: Normal(Talk, TargetCanMove), id=DOUWARE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00023: Normal(Talk, TargetCanMove), id=HIGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00024: Normal(Talk, TargetCanMove), id=YOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00025: Normal(Talk, TargetCanMove), id=KOHARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00026: Normal(Talk, TargetCanMove), id=SHIUN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse315:66992 calling Scene00027: Normal(Talk, TargetCanMove), id=ROKKA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse315 );
