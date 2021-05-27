// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme107 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme107() : Sapphire::ScriptAPI::EventScript( 69172 ){}; 
  ~LucKme107() = default; 

  //SEQ_0, 9 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1030216
  //ACTOR1 = 1030217
  //ACTOR2 = 1030218
  //ACTOR3 = 1030219
  //ACTOR4 = 1030220
  //ACTOR5 = 1030221
  //ACTOR6 = 1030222
  //ACTOR7 = 1030223
  //ACTOR8 = 1030224
  //ACTOR9 = 1027462
  //BINDACTOR01 = 7935052
  //BINDACTOR02 = 7935059
  //BINDACTOR03 = 7935060
  //CUTSCENE0 = 2046
  //LOCACTION0 = 5665
  //LOCACTION1 = 4674
  //LOCACTOR01 = 1028108
  //LOCACTOR02 = 1028119
  //LOCACTOR03 = 1028120
  //LOCBGM01 = 99
  //LOCBGM02 = 711
  //LOCBGM03 = 18
  //LOCBGM04 = 651
  //LOCVFX01 = 60
  //LOCVFX02 = 61
  //QUEST01 = 66031
  //SCREENIMAGEFAILED = 5
  //SCREENIMAGESTART = 3
  //SCREENIMAGESUCCESS = 4

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1030216 || param2 == 1030216 ) // ACTOR0 = unknown
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer), id=unknown
          // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
          break;
        }
        if( param1 == 1030217 || param2 == 1030217 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030218 || param2 == 1030218 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1030219 || param2 == 1030219 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
          break;
        }
        if( param1 == 1030220 || param2 == 1030220 ) // ACTOR4 = RYNE
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=RYNE
          break;
        }
        if( param1 == 1030221 || param2 == 1030221 ) // ACTOR5 = YSHTOLA
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030222 || param2 == 1030222 ) // ACTOR6 = URIANGER
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 1030223 || param2 == 1030223 ) // ACTOR7 = DULIACHAI
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030224 || param2 == 1030224 ) // ACTOR8 = CHAINUZZ
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030224 || param2 == 1030224 ) // ACTOR8 = CHAINUZZ
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=CHAINUZZ
          }
          break;
        }
        if( param1 == 1030217 || param2 == 1030217 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030223 || param2 == 1030223 ) // ACTOR7 = DULIACHAI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1030223 || param2 == 1030223 ) // ACTOR7 = DULIACHAI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=DULIACHAI
            // +Callback Scene00014: Normal(Talk, Message, FadeIn, Menu, AutoFadeIn, SystemTalk, CanCancel), id=unknown
            // +Callback Scene00015: Normal(Talk, FadeIn, TargetCanMove), id=DULIACHAI
          }
          break;
        }
        if( param1 == 1030217 || param2 == 1030217 ) // ACTOR1 = MYSTERYVOICE
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030224 || param2 == 1030224 ) // ACTOR8 = CHAINUZZ
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        break;
      }
      case 255:
      {
        Scene00018( player ); // Scene00018: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=TRISTOL
        // +Callback Scene00019: Normal(Talk, FadeIn, TargetCanMove, Menu), id=unknown
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00000: Normal(QuestOffer), id=unknown" );
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
    player.sendDebug( "LucKme107:69172 calling Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00002: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00003: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00005: Normal(Talk, TargetCanMove), id=RYNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00006: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00007: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00008: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00009: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00010: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00011: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00012: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00013: Normal(Talk, TargetCanMove, SystemTalk), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00014: Normal(Talk, Message, FadeIn, Menu, AutoFadeIn, SystemTalk, CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00015: Normal(Talk, FadeIn, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00016: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00017: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00018: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove, AutoFadeIn), id=TRISTOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00019( player );
      }
    };
    player.playScene( getId(), 18, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme107:69172 calling Scene00019: Normal(Talk, FadeIn, TargetCanMove, Menu), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( LucKme107 );
