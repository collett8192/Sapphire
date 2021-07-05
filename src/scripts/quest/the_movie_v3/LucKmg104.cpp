// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmg104 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmg104() : Sapphire::ScriptAPI::EventScript( 69212 ){}; 
  ~LucKmg104() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 2 entries
  //SEQ_2, 5 entries
  //SEQ_3, 9 entries
  //SEQ_4, 7 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1031732
  //ACTOR1 = 1031733
  //ACTOR2 = 1031734
  //ACTOR3 = 1030386
  //ACTOR4 = 1031792
  //ACTOR5 = 1030881
  //ACTOR6 = 1030882
  //ACTOR7 = 1031735
  //ACTOR8 = 1032282
  //CUTSCENE0 = 2189
  //ENEMY0 = 8136782
  //EOBJECT0 = 2010809
  //EOBJECT1 = 2010810
  //EOBJECT2 = 2010811
  //EVENTACTION0 = 3
  //EVENTACTION1 = 1
  //ITEM0 = 2002905
  //LOCACTION0 = 5627
  //LOCACTORALISAIE = 1026567
  //LOCACTORALPHINAUD = 1026568
  //LOCACTORBEQLUGG = 1029471
  //LOCACTORHALRIC = 1028127
  //LOCACTORKAISHIRR = 1028121
  //LOCACTORMAGNUS = 1028147
  //LOCBINDACTOR0 = 8132193
  //LOCBINDACTOR1 = 8132194
  //LOCBINDACTOR2 = 8132192
  //LOCBINDACTOR3 = 7970635
  //LOCBINDACTOR4 = 7970636
  //LOCBINDACTOR5 = 8136877
  //LOCBINDACTOR6 = 8160746
  //LOCBINDACTOR7 = 7944340
  //QSTCHK00 = 68784

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1031732 || param2 == 1031732 ) // ACTOR0 = unknown
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, Menu), id=unknown
          break;
        }
        if( param1 == 1031733 || param2 == 1031733 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031734 || param2 == 1031734 ) // ACTOR2 = ALISAIE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1031732 || param2 == 1031732 ) // ACTOR0 = BEQLUGG
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove, Menu), id=BEQLUGG
          }
          break;
        }
        if( param1 == 1030386 || param2 == 1030386 ) // ACTOR3 = HALRIC
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1031792 || param2 == 1031792 ) // ACTOR4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=unknown
          }
          break;
        }
        if( param1 == 1030881 || param2 == 1030881 ) // ACTOR5 = THAFFE
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1030882 || param2 == 1030882 ) // ACTOR6 = JERYK
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1031732 || param2 == 1031732 ) // ACTOR0 = BEQLUGG
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        if( param1 == 1030386 || param2 == 1030386 ) // ACTOR3 = HALRIC
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8CH max stack 3
      case 3:
      {
        if( param1 == 2010809 || param2 == 2010809 ) // EOBJECT0 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 8136782 || param2 == 8136782 ) // ENEMY0 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
          break;
        }
        if( param1 == 2010810 || param2 == 2010810 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2010811 || param2 == 2010811 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00018( player ); // Scene00018: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1031792 || param2 == 1031792 ) // ACTOR4 = MAGNUS
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1030881 || param2 == 1030881 ) // ACTOR5 = THAFFE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1030882 || param2 == 1030882 ) // ACTOR6 = JERYK
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        if( param1 == 1031732 || param2 == 1031732 ) // ACTOR0 = BEQLUGG
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        if( param1 == 1030386 || param2 == 1030386 ) // ACTOR3 = HALRIC
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 3
      case 4:
      {
        if( param1 == 1031732 || param2 == 1031732 ) // ACTOR0 = BEQLUGG
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00025: Normal(Talk, TargetCanMove, Menu), id=BEQLUGG
            // +Callback Scene00026: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1031733 || param2 == 1031733 ) // ACTOR1 = ALPHINAUD
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031734 || param2 == 1031734 ) // ACTOR2 = ALISAIE
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE
          break;
        }
        if( param1 == 1030386 || param2 == 1030386 ) // ACTOR3 = HALRIC
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        if( param1 == 1031792 || param2 == 1031792 ) // ACTOR4 = MAGNUS
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1030881 || param2 == 1030881 ) // ACTOR5 = THAFFE
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1030882 || param2 == 1030882 ) // ACTOR6 = JERYK
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=JERYK
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1031734 || param2 == 1031734 ) // ACTOR2 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(Talk, FadeIn, QuestReward, QuestComplete, Menu), id=unknown
          break;
        }
        if( param1 == 1031732 || param2 == 1031732 ) // ACTOR0 = BEQLUGG
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=BEQLUGG
          break;
        }
        if( param1 == 1031733 || param2 == 1031733 ) // ACTOR1 = ALPHINAUD
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1031735 || param2 == 1031735 ) // ACTOR7 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1032282 || param2 == 1032282 ) // ACTOR8 = HALRIC
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=HALRIC
          break;
        }
        if( param1 == 1031792 || param2 == 1031792 ) // ACTOR4 = MAGNUS
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=MAGNUS
          break;
        }
        if( param1 == 1030881 || param2 == 1030881 ) // ACTOR5 = THAFFE
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=THAFFE
          break;
        }
        if( param1 == 1030882 || param2 == 1030882 ) // ACTOR6 = JERYK
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=JERYK
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
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 4 );
        player.setQuestUI8BH( getId(), 3 );
      }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmg104:69212 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, Menu), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00003: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00004: Normal(Talk, TargetCanMove, Menu), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00005: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00007: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00008: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00009: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00010: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00012: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00018: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00019: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00020: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00021: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00022: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00023: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00024: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00025( player );
      }
    };
    player.playScene( getId(), 24, NONE, callback );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00025: Normal(Talk, TargetCanMove, Menu), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00026( player );
      }
    };
    player.playScene( getId(), 25, NONE, callback );
  }
  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00026: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 26, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00027: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00028: Normal(Talk, TargetCanMove), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00029: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00030: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00031: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00032: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00033: Normal(Talk, FadeIn, QuestReward, QuestComplete, Menu), id=unknown" );
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
    player.playScene( getId(), 33, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00034: Normal(Talk, TargetCanMove), id=BEQLUGG" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00035: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00037: Normal(Talk, TargetCanMove), id=HALRIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00038: Normal(Talk, TargetCanMove), id=MAGNUS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00039: Normal(Talk, TargetCanMove), id=THAFFE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmg104:69212 calling Scene00040: Normal(Talk, TargetCanMove), id=JERYK" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmg104 );
