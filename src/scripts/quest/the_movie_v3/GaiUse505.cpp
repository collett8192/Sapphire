// FFXIVTheMovie.ParserV3
// id table disabled
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse505 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse505() : Sapphire::ScriptAPI::EventScript( 65903 ){}; 
  ~GaiUse505() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 7 entries
  //SEQ_3, 7 entries
  //SEQ_4, 5 entries
  //SEQ_5, 14 entries
  //SEQ_255, 10 entries

  //ACTOR0 = 1010858
  //ACTOR1 = 1010890
  //ACTOR10 = 1010883
  //ACTOR11 = 1010884
  //ACTOR12 = 1010885
  //ACTOR13 = 1010861
  //ACTOR14 = 1011125
  //ACTOR15 = 1010862
  //ACTOR16 = 1010863
  //ACTOR17 = 1011126
  //ACTOR18 = 1010864
  //ACTOR19 = 1010865
  //ACTOR2 = 1008969
  //ACTOR20 = 1010866
  //ACTOR21 = 1011787
  //ACTOR22 = 1006646
  //ACTOR3 = 1010886
  //ACTOR4 = 1010887
  //ACTOR5 = 1010888
  //ACTOR6 = 1010889
  //ACTOR7 = 1010860
  //ACTOR8 = 1010859
  //ACTOR9 = 1010882
  //CUTSCENEN01 = 700
  //EOBJECT0 = 2004584
  //EOBJECT1 = 2004585
  //EOBJECT2 = 2004586
  //EOBJECT3 = 2004587
  //EOBJECT4 = 2005162
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001548
  //LOCACTOR0 = 5578876
  //LOCACTOR1 = 5580469
  //LOCACTOR2 = 5580470
  //LOCACTOR3 = 1011648
  //LOCACTOR4 = 1008176
  //LOCACTOR5 = 1008179
  //LOCACTOR6 = 1008178
  //LOCACTOR7 = 4269938
  //LOCACTOR8 = 5580468
  //LOCACTOR9 = 5578877
  //LOCACTORDUMMY0 = 1011647
  //LOCFACIAL0 = 619
  //LOCMOTION0 = 724
  //LOCMOTION1 = 715
  //LOCMOTION2 = 708
  //LOCMOTION3 = 728
  //LOCMOTION4 = 707
  //POPRANGE0 = 5655567

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        break;
      }
      case 1:
      {
        if( actor == 1010890 || actorId == 1010890 ) // ACTOR1 = MOENBRYDA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MOENBRYDA
          }
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010886 || actorId == 1010886 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk), id=THANCRED
        }
        if( actor == 1010887 || actorId == 1010887 ) // ACTOR4 = YDA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010888 || actorId == 1010888 ) // ACTOR5 = PAPALYMO
        {
          Scene00006( player ); // Scene00006: Normal(Talk), id=PAPALYMO
        }
        if( actor == 1010889 || actorId == 1010889 ) // ACTOR6 = YSHTOLA
        {
          Scene00007( player ); // Scene00007: Normal(Talk), id=YSHTOLA
        }
        if( actor == 1010858 || actorId == 1010858 ) // ACTOR0 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 2:
      {
        if( actor == 1010860 || actorId == 1010860 ) // ACTOR7 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1010886 || actorId == 1010886 ) // ACTOR3 = THANCRED
        {
          Scene00011( player ); // Scene00011: Normal(Talk), id=THANCRED
        }
        if( actor == 1010887 || actorId == 1010887 ) // ACTOR4 = YDA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010888 || actorId == 1010888 ) // ACTOR5 = PAPALYMO
        {
          Scene00013( player ); // Scene00013: Normal(Talk), id=PAPALYMO
        }
        if( actor == 1010889 || actorId == 1010889 ) // ACTOR6 = YSHTOLA
        {
          Scene00014( player ); // Scene00014: Normal(Talk), id=YSHTOLA
        }
        if( actor == 1010858 || actorId == 1010858 ) // ACTOR0 = MINFILIA
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        break;
      }
      case 3:
      {
        if( actor == 1010858 || actorId == 1010858 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1010859 || actorId == 1010859 ) // ACTOR8 = TATARU
        {
          Scene00017( player ); // Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          // +Callback Scene00018: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1010882 || actorId == 1010882 ) // ACTOR9 = FLHAMINN
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=FLHAMINN
        }
        if( actor == 1010883 || actorId == 1010883 ) // ACTOR10 = HIGIRI
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=HIGIRI
        }
        if( actor == 1010884 || actorId == 1010884 ) // ACTOR11 = HOARYBOULDER
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HOARYBOULDER
        }
        if( actor == 1010885 || actorId == 1010885 ) // ACTOR12 = COULTENET
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=COULTENET
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        break;
      }
      case 4:
      {
        if( actor == 1010861 || actorId == 1010861 ) // ACTOR13 = WILRED
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=WILRED
          }
        }
        if( actor == 1010859 || actorId == 1010859 ) // ACTOR8 = TATARU
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1010883 || actorId == 1010883 ) // ACTOR10 = HIGIRI
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=HIGIRI
        }
        if( actor == 1011125 || actorId == 1011125 ) // ACTOR14 = ALIANNE
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        break;
      }
      //seq 5 event item ITEM0 = UI8BH max stack 4
      case 5:
      {
        if( actor == 2004584 || actorId == 2004584 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00029( player ); // Scene00029: Normal(None), id=unknown
            // +Callback Scene00030: Normal(None), id=unknown
          }
        }
        if( actor == 2004585 || actorId == 2004585 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00031( player ); // Scene00031: Normal(None), id=unknown
            // +Callback Scene00032: Normal(None), id=unknown
          }
        }
        if( actor == 2004586 || actorId == 2004586 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00033( player ); // Scene00033: Normal(None), id=unknown
            // +Callback Scene00034: Normal(None), id=unknown
          }
        }
        if( actor == 2004587 || actorId == 2004587 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00035( player ); // Scene00035: Normal(None), id=unknown
            // +Callback Scene00036: Normal(None), id=unknown
          }
        }
        if( actor == 1010862 || actorId == 1010862 ) // ACTOR15 = THANCRED
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010863 || actorId == 1010863 ) // ACTOR16 = PAPALYMO
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1011126 || actorId == 1011126 ) // ACTOR17 = WILRED
        {
          Scene00039( player ); // Scene00039: Normal(Talk), id=WILRED
        }
        if( actor == 1010864 || actorId == 1010864 ) // ACTOR18 = YDA
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010865 || actorId == 1010865 ) // ACTOR19 = YSHTOLA
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1010866 || actorId == 1010866 ) // ACTOR20 = MOENBRYDA
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=MOENBRYDA
        }
        if( actor == 2005162 || actorId == 2005162 ) // EOBJECT4 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
        }
        if( actor == 1011787 || actorId == 1011787 ) // ACTOR21 = ALIANNE
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1006646 || actorId == 1006646 ) // ACTOR22 = EDELSTEIN
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=EDELSTEIN
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 4
      case 255:
      {
        if( actor == 1006646 || actorId == 1006646 ) // ACTOR22 = EDELSTEIN
        {
          Scene00047( player ); // Scene00047: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00048: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EDELSTEIN
        }
        if( actor == 1010862 || actorId == 1010862 ) // ACTOR15 = THANCRED
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1010863 || actorId == 1010863 ) // ACTOR16 = PAPALYMO
        {
          Scene00050( player ); // Scene00050: Normal(Talk, TargetCanMove), id=PAPALYMO
        }
        if( actor == 1011126 || actorId == 1011126 ) // ACTOR17 = WILRED
        {
          Scene00051( player ); // Scene00051: Normal(Talk), id=WILRED
        }
        if( actor == 1010864 || actorId == 1010864 ) // ACTOR18 = YDA
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=YDA
        }
        if( actor == 1010865 || actorId == 1010865 ) // ACTOR19 = YSHTOLA
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1010866 || actorId == 1010866 ) // ACTOR20 = MOENBRYDA
        {
          Scene00054( player ); // Scene00054: Normal(Talk, TargetCanMove), id=MOENBRYDA
        }
        if( actor == 2005162 || actorId == 2005162 ) // EOBJECT4 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
        }
        if( actor == 1011787 || actorId == 1011787 ) // ACTOR21 = ALIANNE
        {
          Scene00056( player ); // Scene00056: Normal(Talk, TargetCanMove), id=ALIANNE
        }
        if( actor == 1008969 || actorId == 1008969 ) // ACTOR2 = MINFILIA
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=MINFILIA
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
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 4 )
      if( player.getQuestUI8AL( getId() ) == 4 )
        if( player.getQuestUI8AL( getId() ) == 4 )
          if( player.getQuestUI8AL( getId() ) == 4 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.updateQuest( getId(), 255 );
            player.setQuestUI8BH( getId(), 4 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse505:65903 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00002: Normal(Talk, NpcDespawn, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00004: Normal(Talk), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00005: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00006: Normal(Talk), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00007: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00009: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00010: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00011: Normal(Talk), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00012: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00013: Normal(Talk), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00014: Normal(Talk), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00015: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00016: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00017: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling [BranchTrue]Scene00018: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00019: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00020: Normal(Talk, TargetCanMove), id=HIGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00021: Normal(Talk, TargetCanMove), id=HOARYBOULDER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00022: Normal(Talk, TargetCanMove), id=COULTENET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00023: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00025: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00026: Normal(Talk, TargetCanMove), id=HIGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00027: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00028: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00029: Normal(None), id=unknown" );
    Scene00030( player );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling [BranchTrue]Scene00030: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq5( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00031: Normal(None), id=unknown" );
    Scene00032( player );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling [BranchTrue]Scene00032: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq5( player );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00033: Normal(None), id=unknown" );
    Scene00034( player );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling [BranchTrue]Scene00034: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq5( player );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00035: Normal(None), id=unknown" );
    Scene00036( player );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling [BranchTrue]Scene00036: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq5( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00037: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00038: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00039: Normal(Talk), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00040: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00041: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00042: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00043: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00044: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00045: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00046: Normal(Talk, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00047: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00048( player );
      }
    };
    player.playScene( getId(), 47, NONE, callback );
  }
  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling [BranchTrue]Scene00048: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=EDELSTEIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00049: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00050: Normal(Talk, TargetCanMove), id=PAPALYMO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00051: Normal(Talk), id=WILRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00052: Normal(Talk, TargetCanMove), id=YDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00053: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00054: Normal(Talk, TargetCanMove), id=MOENBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 54, NONE, callback );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00056: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 56, NONE, callback );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "GaiUse505:65903 calling Scene00057: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse505 );
