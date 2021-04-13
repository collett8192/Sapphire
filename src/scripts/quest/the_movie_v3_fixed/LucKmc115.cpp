// FFXIVTheMovie.ParserV3.2
// id hint used:
//EOBJECT2 = dummye2
//SCENE_12 = dummye2
//SCENE_13 = dummye2
//SCENE_14 = dummye2
//EOBJECT1 = dummye1
//SCENE_15 = dummye1
//SCENE_16 = dummye1
//EOBJECT0 = dummye0
//SCENE_17 = dummye0
//SCENE_18 = dummye0
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc115 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc115() : Sapphire::ScriptAPI::EventScript( 68872 ){}; 
  ~LucKmc115() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 4 entries
  //SEQ_3, 17 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1029240
  //ACTOR1 = 1030946
  //ACTOR2 = 1029242
  //ACTOR3 = 1029243
  //ACTOR4 = 1030572
  //ACTOR5 = 1030571
  //ACTOR6 = 1030573
  //ACTOR7 = 1030574
  //BGMEVENTTREMENDOUS01 = 190
  //CARRY0 = 20
  //EOBJECT0 = 2010219
  //EOBJECT1 = 2010218
  //EOBJECT2 = 2010217
  //EVENTACTION0 = 46
  //EVENTACTION1 = 45
  //EVENTACTION2 = 1
  //EVENTRANGE0 = 7952925
  //EVENTRANGE1 = 7952929
  //EVENTRANGE10 = 7952939
  //EVENTRANGE11 = 7952940
  //EVENTRANGE2 = 7952931
  //EVENTRANGE3 = 7952932
  //EVENTRANGE4 = 7952933
  //EVENTRANGE5 = 7952934
  //EVENTRANGE6 = 7952935
  //EVENTRANGE7 = 7952936
  //EVENTRANGE8 = 7952937
  //EVENTRANGE9 = 7952938
  //LOCACTORALMET = 1028139
  //LOCACTORYSHTOLA = 1026571
  //LOCBGMMUSICEX3FIELDRAKTIKADAY01 = 671
  //LOCBINDACTOR0 = 7984470
  //LOCBINDACTOR1 = 7927579
  //LOCBINDEOBJGATE = 7952923
  //LOCBINDEOBJSTATUEEAST01 = 7952910
  //LOCBINDEOBJSTATUEEAST02 = 7952912
  //LOCBINDEOBJSTATUEEAST03 = 7952913
  //LOCBINDEOBJSTATUEEAST04 = 7952914
  //LOCBINDEOBJSTATUENORTH01 = 7952915
  //LOCBINDEOBJSTATUENORTH02 = 7952916
  //LOCBINDEOBJSTATUENORTH03 = 7952917
  //LOCBINDEOBJSTATUENORTH04 = 7952918
  //LOCBINDEOBJSTATUESOUTH01 = 7952919
  //LOCBINDEOBJSTATUESOUTH02 = 7952920
  //LOCBINDEOBJSTATUESOUTH03 = 7952921
  //LOCBINDEOBJSTATUESOUTH04 = 7952922
  //LOCEOBJSTATUE = 2010655
  //LOCSELIGHTEMISSIONDOOR = 221
  //LOCSESTATUEWOBBLE = 220
  //STATUS0 = 404

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029240 || param2 == 1029240 ) // ACTOR0 = ALMET
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1030946 || param2 == 1030946 ) // ACTOR1 = YSHTOLA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 2010219 || param2 == 2010219 ) // EOBJECT0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029242 || param2 == 1029242 ) // ACTOR2 = ALMET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=ALMET
          }
          break;
        }
        if( param1 == 1029243 || param2 == 1029243 ) // ACTOR3 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 2010219 || param2 == 2010219 ) // EOBJECT0 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2010218 || param2 == 2010218 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, FadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2010219 || param2 == 2010219 ) // EOBJECT0 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1030572 || param2 == 1030572 ) // ACTOR4 = YSHTOLA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        if( param1 == 1030571 || param2 == 1030571 ) // ACTOR5 = ALMET
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        break;
      }
      case 3:
      {
        // need capture for proper implementation
        if( param1 == 2010217 || param2 == 2010217 ) // EOBJECT2 = dummye2
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            if( !player.getStatusEffectById( 404 ).second )
              Scene00012( player );
            else
              Scene00014( player );
          }
          break;
        }
        if( param1 == 2010218 || param2 == 2010218 ) // EOBJECT1 = dummye1
        {
          if( !player.getStatusEffectById( 404 ).second )
            Scene00016( player ); // Scene00016: Normal(SystemTalk), id=dummye1
          break;
        }
        if( param1 == 2010219 || param2 == 2010219 ) // EOBJECT0 = dummye0
        {
          Scene00018( player ); // Scene00018: Normal(None), id=dummye0
          break;
        }
        if( param1 == 7952925 || param2 == 7952925 ) // EVENTRANGE0 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00020( player );
          break;
        }
        if( param1 == 7952929 || param2 == 7952929 ) // EVENTRANGE1 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00022( player );
          break;
        }
        if( param1 == 7952931 || param2 == 7952931 ) // EVENTRANGE2 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00024( player );
          break;
        }
        if( param1 == 7952932 || param2 == 7952932 ) // EVENTRANGE3 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00026( player );
          break;
        }
        if( param1 == 7952933 || param2 == 7952933 ) // EVENTRANGE4 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00028( player );
          break;
        }
        if( param1 == 7952934 || param2 == 7952934 ) // EVENTRANGE5 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00030( player );
          break;
        }
        if( param1 == 7952935 || param2 == 7952935 ) // EVENTRANGE6 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00032( player );
          break;
        }
        if( param1 == 7952936 || param2 == 7952936 ) // EVENTRANGE7 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00034( player );
          break;
        }
        if( param1 == 7952937 || param2 == 7952937 ) // EVENTRANGE8 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00036( player );
          break;
        }
        if( param1 == 7952938 || param2 == 7952938 ) // EVENTRANGE9 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00038( player );
          break;
        }
        if( param1 == 7952939 || param2 == 7952939 ) // EVENTRANGE10 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00040( player );
          break;
        }
        if( param1 == 7952940 || param2 == 7952940 ) // EVENTRANGE11 = unknown
        {
          if( player.getStatusEffectById( 404 ).second )
            Scene00042( player );
          break;
        }
        if( param1 == 4302920190 || param2 == 1030573 ) // ACTOR6 = ALMET
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 4302920191 || param2 == 1030574 ) // ACTOR7 = YSHTOLA
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029242 || param2 == 1029242 ) // ACTOR2 = ALMET
        {
          Scene00045( player ); // Scene00045: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029243 || param2 == 1029243 ) // ACTOR3 = YSHTOLA
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=YSHTOLA
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc115:68872 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq0( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00008: Normal(Talk, FadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
      player.addStatusEffectByIdIfNotExist( 404, 120000, player, 0, true );
    };
    player.playScene( getId(), 8, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00010: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00011: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00012: Normal(AutoFadeIn, SystemTalk, CanCancel), id=dummye2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00013: Normal(AutoFadeIn), id=dummye2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00014: Normal(Talk, FadeIn, QuestGimmickReaction, SystemTalk), id=dummye2" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00016: Normal(SystemTalk), id=dummye1" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
      player.addStatusEffectByIdIfNotExist( 404, 120000, player, 0, true );
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00018: Normal(None), id=dummye0" );
    checkProgressSeq3( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00019: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00020( player );
      }
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00020: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00021: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00022( player );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00022: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00023: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00024( player );
      }
    };
    player.playScene( getId(), 23, NONE, callback );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00024: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00025: Normal(CanCancel), id=unknown" );
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
    player.sendDebug( "LucKmc115:68872 calling Scene00026: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00027: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00028( player );
      }
    };
    player.playScene( getId(), 27, NONE, callback );
  }
  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00028: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00029: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00030( player );
      }
    };
    player.playScene( getId(), 29, NONE, callback );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00030: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00031: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00032( player );
      }
    };
    player.playScene( getId(), 31, NONE, callback );
  }
  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00032: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00033: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00034( player );
      }
    };
    player.playScene( getId(), 33, NONE, callback );
  }
  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00034: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00035: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00036( player );
      }
    };
    player.playScene( getId(), 35, NONE, callback );
  }
  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00036: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00037: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00038( player );
      }
    };
    player.playScene( getId(), 37, NONE, callback );
  }
  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00038: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00039: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00040( player );
      }
    };
    player.playScene( getId(), 39, NONE, callback );
  }
  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00040: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00041: Normal(CanCancel), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        Scene00042( player );
      }
    };
    player.playScene( getId(), 41, NONE, callback );
  }
  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00042: Normal(QuestGimmickReaction, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.removeSingleStatusEffectById( 404 );
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00043: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00044: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00045: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALMET" );
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
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "LucKmc115:68872 calling Scene00046: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc115 );
