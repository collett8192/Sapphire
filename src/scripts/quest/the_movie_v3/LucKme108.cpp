// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKme108 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKme108() : Sapphire::ScriptAPI::EventScript( 69173 ){}; 
  ~LucKme108() = default; 

  //SEQ_0, 4 entries
  //SEQ_1, 4 entries
  //SEQ_2, 2 entries
  //SEQ_3, 3 entries
  //SEQ_4, 3 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1027462
  //ACTOR1 = 1030226
  //ACTOR2 = 1030227
  //ACTOR3 = 1030228
  //ACTOR4 = 1030229
  //ACTOR5 = 1027296
  //ACTOR6 = 1030230
  //ACTOR7 = 1030231
  //BINDACTOR01 = 7935108
  //BINDACTOR02 = 7935110
  //BINDACTOR03 = 7935111
  //GEARDWARFHEADCASTER = 26322
  //GEARDWARFHEADDRA = 26292
  //GEARDWARFHEADHEALER = 26316
  //GEARDWARFHEADMELLE = 26298
  //GEARDWARFHEADRANGE = 26304
  //GEARDWARFHEADROGUE = 26310
  //GEARDWARFHEADTANK = 26286
  //LOCACTION01 = 5625
  //LOCACTOR01 = 1029327
  //LOCBGM01 = 108
  //LOCSE01 = 185
  //LOCSE02 = 174
  //QUEST01 = 68803
  //SNIPE0 = 34
  //SNIPE1 = 35

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1027462 || param2 == 1027462 ) // ACTOR0 = TRISTOL
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TRISTOL
          break;
        }
        if( param1 == 1030226 || param2 == 1030226 ) // ACTOR1 = CHAINUZZ
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030227 || param2 == 1030227 ) // ACTOR2 = DULIACHAI
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1030228 || param2 == 1030228 ) // ACTOR3 = MYSTERYVOICE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1030229 || param2 == 1030229 ) // ACTOR4 = MYSTERYVOICE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove, Menu), id=MYSTERYVOICE
          }
          break;
        }
        if( param1 == 1030226 || param2 == 1030226 ) // ACTOR1 = CHAINUZZ
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CHAINUZZ
          break;
        }
        if( param1 == 1030227 || param2 == 1030227 ) // ACTOR2 = DULIACHAI
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=DULIACHAI
          break;
        }
        if( param1 == 1027462 || param2 == 1027462 ) // ACTOR0 = TRISTOL
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=TRISTOL
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1027296 || param2 == 1027296 ) // ACTOR5 = XAMOTT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=XAMOTT
          }
          break;
        }
        if( param1 == 1030230 || param2 == 1030230 ) // ACTOR6 = MYSTERYVOICE
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1030231 || param2 == 1030231 ) // ACTOR7 = GUIDEDWARF03637
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=GUIDEDWARF03637
            // +Callback Scene00012: Snipe(CanCancel), id=unknown
            // +Callback Scene00013: Normal(Talk, TargetCanMove), id=GUIDEDWARF03637
          }
          break;
        }
        if( param1 == 1027296 || param2 == 1027296 ) // ACTOR5 = XAMOTT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=XAMOTT
          break;
        }
        if( param1 == 1030230 || param2 == 1030230 ) // ACTOR6 = MYSTERYVOICE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1030231 || param2 == 1030231 ) // ACTOR7 = GUIDEDWARF03637
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove, SystemTalk), id=GUIDEDWARF03637
            // +Callback Scene00017: Snipe(CanCancel), id=unknown
            // +Callback Scene00018: Normal(Talk, TargetCanMove), id=GUIDEDWARF03637
          }
          break;
        }
        if( param1 == 1027296 || param2 == 1027296 ) // ACTOR5 = XAMOTT
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=XAMOTT
          break;
        }
        if( param1 == 1030230 || param2 == 1030230 ) // ACTOR6 = MYSTERYVOICE
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1027296 || param2 == 1027296 ) // ACTOR5 = XAMOTT
        {
          Scene00021( player ); // Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=XAMOTT
          break;
        }
        if( param1 == 1030230 || param2 == 1030230 ) // ACTOR6 = MYSTERYVOICE
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=MYSTERYVOICE
          break;
        }
        if( param1 == 1030231 || param2 == 1030231 ) // ACTOR7 = GUIDEDWARF03637
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=GUIDEDWARF03637
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKme108:69173 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TRISTOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00002: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00003: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00004: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove, Menu), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00006: Normal(Talk, TargetCanMove), id=CHAINUZZ" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00007: Normal(Talk, TargetCanMove), id=DULIACHAI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00008: Normal(Talk, TargetCanMove), id=TRISTOL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00009: Normal(Talk, TargetCanMove), id=XAMOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00010: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00011: Normal(Talk, TargetCanMove, SystemTalk), id=GUIDEDWARF03637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00012: Snipe(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00013( player );
      }
    };
    player.playScene( getId(), 12, INVIS_ENPC, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00013: Normal(Talk, TargetCanMove), id=GUIDEDWARF03637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00014: Normal(Talk, TargetCanMove), id=XAMOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00015: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00016: Normal(Talk, TargetCanMove, SystemTalk), id=GUIDEDWARF03637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00017( player );
    };
    player.playScene( getId(), 16, NONE, callback );
  }
  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00017: Snipe(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00018( player );
      }
    };
    player.playScene( getId(), 17, INVIS_ENPC, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00018: Normal(Talk, TargetCanMove), id=GUIDEDWARF03637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00019: Normal(Talk, TargetCanMove), id=XAMOTT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00020: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00021: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=XAMOTT" );
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
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00022: Normal(Talk, TargetCanMove), id=MYSTERYVOICE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKme108:69173 calling Scene00023: Normal(Talk, TargetCanMove), id=GUIDEDWARF03637" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKme108 );
