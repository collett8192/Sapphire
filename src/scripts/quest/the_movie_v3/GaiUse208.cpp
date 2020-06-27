// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse208 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse208() : Sapphire::ScriptAPI::EventScript( 66888 ){}; 
  ~GaiUse208() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 6 entries
  //SEQ_2, 8 entries
  //SEQ_3, 8 entries
  //SEQ_255, 12 entries

  //ACTOR0 = 1008639
  //ACTOR1 = 1008638
  //ACTOR10 = 1008643
  //ACTOR11 = 1008644
  //ACTOR12 = 1008645
  //ACTOR13 = 1008646
  //ACTOR14 = 1008623
  //ACTOR15 = 1008648
  //ACTOR16 = 1008649
  //ACTOR17 = 1008650
  //ACTOR18 = 1008651
  //ACTOR19 = 1008652
  //ACTOR2 = 1008632
  //ACTOR20 = 1008653
  //ACTOR21 = 1008654
  //ACTOR22 = 1008656
  //ACTOR23 = 1008657
  //ACTOR24 = 1008658
  //ACTOR3 = 1008647
  //ACTOR4 = 1008655
  //ACTOR5 = 1008703
  //ACTOR6 = 1008704
  //ACTOR7 = 1008640
  //ACTOR8 = 1008641
  //ACTOR9 = 1008642
  //CUTSCENEN01 = 463
  //ENEMY0 = 4622373
  //EOBJECT0 = 2003570
  //EOBJECT1 = 2003573
  //EOBJECT2 = 2003571
  //EOBJECT3 = 2003572
  //EVENTACTIONLOOKOUTMIDDLE = 50
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONSEARCHSHORT = 2
  //LEVELIDNPC01 = 4622300
  //POPRANGE0 = 4627351

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1008639 || actorId == 1008639 ) // ACTOR0 = HOUZAN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HOUZAN
        }
        if( actor == 1008638 || actorId == 1008638 ) // ACTOR1 = HOUMEI
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HOUMEI
        }
        break;
      }
      case 1:
      {
        if( actor == 1008632 || actorId == 1008632 ) // ACTOR2 = GYOSHA01348
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=GYOSHA01348
          }
        }
        if( actor == 1008647 || actorId == 1008647 ) // ACTOR3 = HOUZAN
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=HOUZAN
        }
        if( actor == 1008655 || actorId == 1008655 ) // ACTOR4 = HOUMEI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HOUMEI
        }
        if( actor == 1008703 || actorId == 1008703 ) // ACTOR5 = YOUZAN
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YOUZAN
        }
        if( actor == 1008704 || actorId == 1008704 ) // ACTOR6 = KOHARU
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=KOHARU
        }
        if( actor == 2003570 || actorId == 2003570 ) // EOBJECT0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          // +Callback Scene00009: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 2003573 || actorId == 2003573 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4622373 || actorId == 4622373 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 1008647 || actorId == 1008647 ) // ACTOR3 = HOUZAN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HOUZAN
        }
        if( actor == 1008655 || actorId == 1008655 ) // ACTOR4 = HOUMEI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=HOUMEI
        }
        if( actor == 1008703 || actorId == 1008703 ) // ACTOR5 = YOUZAN
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=YOUZAN
        }
        if( actor == 1008704 || actorId == 1008704 ) // ACTOR6 = KOHARU
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=KOHARU
        }
        if( actor == 1008632 || actorId == 1008632 ) // ACTOR2 = GYOSHA01348
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=GYOSHA01348
        }
        if( actor == 2003570 || actorId == 2003570 ) // EOBJECT0 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        break;
      }
      case 3:
      {
        if( actor == 1008640 || actorId == 1008640 ) // ACTOR7 = GYOSHA01348
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=GYOSHA01348
          }
        }
        if( actor == 1008641 || actorId == 1008641 ) // ACTOR8 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(CutScene), id=unknown
        }
        if( actor == 1008642 || actorId == 1008642 ) // ACTOR9 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 1008643 || actorId == 1008643 ) // ACTOR10 = HOUZAN
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(Talk, TargetCanMove), id=HOUZAN
        }
        if( actor == 1008644 || actorId == 1008644 ) // ACTOR11 = HOUMEI
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=HOUMEI
        }
        if( actor == 1008645 || actorId == 1008645 ) // ACTOR12 = YOUZAN
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=YOUZAN
        }
        if( actor == 1008646 || actorId == 1008646 ) // ACTOR13 = KOHARU
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=KOHARU
        }
        if( actor == 2003571 || actorId == 2003571 ) // EOBJECT2 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1008623 || actorId == 1008623 ) // ACTOR14 = ALPHINAUD
        {
          Scene00026( player ); // Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1008648 || actorId == 1008648 ) // ACTOR15 = GYOSHA01348
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=GYOSHA01348
        }
        if( actor == 1008649 || actorId == 1008649 ) // ACTOR16 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
        }
        if( actor == 1008650 || actorId == 1008650 ) // ACTOR17 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
        }
        if( actor == 1008651 || actorId == 1008651 ) // ACTOR18 = HOUZAN
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=HOUZAN
        }
        if( actor == 1008652 || actorId == 1008652 ) // ACTOR19 = HOUMEI
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=HOUMEI
        }
        if( actor == 1008653 || actorId == 1008653 ) // ACTOR20 = YOUZAN
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=YOUZAN
        }
        if( actor == 1008654 || actorId == 1008654 ) // ACTOR21 = KOHARU
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=KOHARU
        }
        if( actor == 1008656 || actorId == 1008656 ) // ACTOR22 = YUGIRI
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008657 || actorId == 1008657 ) // ACTOR23 = KSASAGI
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=KSASAGI
        }
        if( actor == 1008658 || actorId == 1008658 ) // ACTOR24 = KIKYOU
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=KIKYOU
        }
        if( actor == 2003572 || actorId == 2003572 ) // EOBJECT3 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
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
    player.sendDebug( "GaiUse208:66888 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse208:66888 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00002: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00003: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00004: Normal(Talk, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00005: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00006: Normal(Talk, TargetCanMove), id=YOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00007: Normal(Talk, TargetCanMove), id=KOHARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling [BranchTrue]Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00011: Normal(Talk, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00012: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00013: Normal(Talk, TargetCanMove), id=YOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00014: Normal(Talk, TargetCanMove), id=KOHARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00015: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00017: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00018: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling [BranchTrue]Scene00021: Normal(Talk, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00022: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00023: Normal(Talk, TargetCanMove), id=YOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00024: Normal(Talk, TargetCanMove), id=KOHARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00026: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00027: Normal(Talk, TargetCanMove), id=GYOSHA01348" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00030: Normal(Talk, TargetCanMove), id=HOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00031: Normal(Talk, TargetCanMove), id=HOUMEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00032: Normal(Talk, TargetCanMove), id=YOUZAN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00033: Normal(Talk, TargetCanMove), id=KOHARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00034: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00035: Normal(Talk, TargetCanMove), id=KSASAGI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00036: Normal(Talk, TargetCanMove), id=KIKYOU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse208:66888 calling Scene00037: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUse208 );
