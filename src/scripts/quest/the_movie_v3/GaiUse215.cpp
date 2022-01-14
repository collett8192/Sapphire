// FFXIVTheMovie.ParserV3.6
// id hint used:
//ACTOR1 = KOKKAGUNNSOU01359
//ACTOR2 = null
//ACTOR3 = null
//ACTOR4 = null
//ACTOR5 = null
//ACTOR6 = YSHTOLA
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse215 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse215() : Sapphire::ScriptAPI::EventScript( 66895 ){}; 
  ~GaiUse215() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 13 entries
  //SEQ_2, 17 entries
  //SEQ_3, 10 entries
  //SEQ_4, 6 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTBASEATTENTIONSTAND = 1013
  //ACTOR0 = 1006614
  //ACTOR1 = 1008698
  //ACTOR2 = 1008699
  //ACTOR3 = 1008688
  //ACTOR4 = 1008689
  //ACTOR5 = 1008928
  //ACTOR6 = 1008706
  //ACTOR7 = 1008803
  //BGMNOTHING = 1
  //CUTSCENEN01 = 467
  //CUTSCENEN02 = 468
  //ENEMY0 = 4628675
  //ENEMY1 = 4628676
  //ENEMY10 = 4628687
  //ENEMY11 = 4628688
  //ENEMY12 = 4628692
  //ENEMY13 = 4628693
  //ENEMY14 = 4628694
  //ENEMY2 = 4628678
  //ENEMY3 = 4628679
  //ENEMY4 = 4628680
  //ENEMY5 = 4628681
  //ENEMY6 = 4628682
  //ENEMY7 = 4628683
  //ENEMY8 = 4628684
  //ENEMY9 = 4628685
  //EOBJECT0 = 2003591
  //EOBJECT1 = 2003592
  //EOBJECT2 = 2003593
  //EOBJECT3 = 2003594
  //EOBJECT4 = 2003595
  //EVENTRANGE0 = 4628666
  //EVENTRANGE1 = 4628667
  //EVENTRANGE2 = 4628668
  //EVENTRANGE3 = 4628669
  //EVENTRANGE4 = 4628672
  //EVENTACTIONRESCUEUPPERMIDDLE = 39
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1008183
  //LOCACTOR1 = 1008175
  //LOCACTOR2 = 4628705
  //LOCACTOR3 = 4628706
  //LOCACTOR4 = 4628707
  //LOCACTOR5 = 4334136
  //LOCFACE0 = 617
  //LOCFACE1 = 605
  //LOCFACE2 = 612
  //LOCPOSACTOR1 = 4675591
  //POPRANGE0 = 4635439

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=FALKBRYDA
        break;
      }
      case 1:
      {
        if( param1 == 4628666 || param2 == 4628666 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00002( player ); // Scene00002: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4628675 || param2 == 4628675 ) // ENEMY0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628676 || param2 == 4628676 ) // ENEMY1 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628667 || param2 == 4628667 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00005( player ); // Scene00005: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4628678 || param2 == 4628678 ) // ENEMY2 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628679 || param2 == 4628679 ) // ENEMY3 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 2003591 || param2 == 2003591 ) // EOBJECT0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
          break;
        }
        if( param1 == 2003592 || param2 == 2003592 ) // EOBJECT1 = unknown
        {
          Scene00009( player ); // Scene00009: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008698 || param2 == 1008698 ) // ACTOR1 = KOKKAGUNNSOU01359
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=KOKKAGUNNSOU01359
          break;
        }
        if( param1 == 1008699 || param2 == 1008699 ) // ACTOR2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008688 || param2 == 1008688 ) // ACTOR3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008689 || param2 == 1008689 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008928 || param2 == 1008928 ) // ACTOR5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 4628668 || param2 == 4628668 ) // EVENTRANGE2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 4 )
          {
            Scene00015( player ); // Scene00015: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4628680 || param2 == 4628680 ) // ENEMY4 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628681 || param2 == 4628681 ) // ENEMY5 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628682 || param2 == 4628682 ) // ENEMY6 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628683 || param2 == 4628683 ) // ENEMY7 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628669 || param2 == 4628669 ) // EVENTRANGE3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00020( player ); // Scene00020: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4628684 || param2 == 4628684 ) // ENEMY8 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628685 || param2 == 4628685 ) // ENEMY9 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628687 || param2 == 4628687 ) // ENEMY10 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628688 || param2 == 4628688 ) // ENEMY11 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 2003593 || param2 == 2003593 ) // EOBJECT2 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(None), id=unknown
          break;
        }
        if( param1 == 2003594 || param2 == 2003594 ) // EOBJECT3 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008698 || param2 == 1008698 ) // ACTOR1 = KOKKAGUNNSOU01359
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=KOKKAGUNNSOU01359
          break;
        }
        if( param1 == 1008699 || param2 == 1008699 ) // ACTOR2 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008688 || param2 == 1008688 ) // ACTOR3 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008689 || param2 == 1008689 ) // ACTOR4 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008928 || param2 == 1008928 ) // ACTOR5 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 4628672 || param2 == 4628672 ) // EVENTRANGE4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00032( player ); // Scene00032: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 4628692 || param2 == 4628692 ) // ENEMY12 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628693 || param2 == 4628693 ) // ENEMY13 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
          break;
        }
        if( param1 == 4628694 || param2 == 4628694 ) // ENEMY14 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 2003595 || param2 == 2003595 ) // EOBJECT4 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008698 || param2 == 1008698 ) // ACTOR1 = KOKKAGUNNSOU01359
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=KOKKAGUNNSOU01359
          break;
        }
        if( param1 == 1008699 || param2 == 1008699 ) // ACTOR2 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008688 || param2 == 1008688 ) // ACTOR3 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008689 || param2 == 1008689 ) // ACTOR4 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008928 || param2 == 1008928 ) // ACTOR5 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1008706 || param2 == 1008706 ) // ACTOR6 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=YSHTOLA
            // +Callback Scene00044: Normal(CutScene, AutoFadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1008698 || param2 == 1008698 ) // ACTOR1 = KOKKAGUNNSOU01359
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=KOKKAGUNNSOU01359
          break;
        }
        if( param1 == 1008699 || param2 == 1008699 ) // ACTOR2 = unknown
        {
          Scene00046( player ); // Scene00046: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008688 || param2 == 1008688 ) // ACTOR3 = unknown
        {
          Scene00047( player ); // Scene00047: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008689 || param2 == 1008689 ) // ACTOR4 = unknown
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          break;
        }
        if( param1 == 1008928 || param2 == 1008928 ) // ACTOR5 = unknown
        {
          Scene00049( player ); // Scene00049: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00050( player ); // Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MERLWYB
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
    player.sendDebug( "emote: {}", emoteId );
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
    if( player.getQuestUI8BH( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 2 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestBitFlag8( getId(), 1, false );
        player.setQuestBitFlag8( getId(), 2, false );
        player.updateQuest( getId(), 2 );
      }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 4 )
      if( player.getQuestUI8AL( getId() ) == 4 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestBitFlag8( getId(), 1, false );
        player.setQuestBitFlag8( getId(), 2, false );
        player.updateQuest( getId(), 3 );
      }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove, ENpcBind), id=FALKBRYDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: EVENTRANGE0, UI8BH = 2, Flag8(1)=True
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00002: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00003: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player ) //SEQ_1: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00004: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: EVENTRANGE1, UI8AL = 2, Flag8(2)=True
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00006: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00007: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00010: Normal(Talk, TargetCanMove), id=KOKKAGUNNSOU01359" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: EVENTRANGE2, UI8BH = 4, Flag8(1)=True
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00015: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 4 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player ) //SEQ_2: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_2: ENEMY5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00017: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00018( Entity::Player& player ) //SEQ_2: ENEMY6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_2: ENEMY7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_2: EVENTRANGE3, UI8AL = 4, Flag8(2)=True
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00020: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 4 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player ) //SEQ_2: ENEMY8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00022( Entity::Player& player ) //SEQ_2: ENEMY9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00023( Entity::Player& player ) //SEQ_2: ENEMY10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00023: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00024( Entity::Player& player ) //SEQ_2: ENEMY11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00024: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00025( Entity::Player& player ) //SEQ_2: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00025: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00026( Entity::Player& player ) //SEQ_2: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00026: Normal(None), id=unknown" );
    checkProgressSeq2( player );
  }

  void Scene00027( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00027: Normal(Talk, TargetCanMove), id=KOKKAGUNNSOU01359" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00030: Normal(None), id=unknown" );
  }

  void Scene00031( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player ) //SEQ_3: EVENTRANGE4, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00032: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_3: ENEMY12, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00033: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00034( Entity::Player& player ) //SEQ_3: ENEMY13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00034: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00035( Entity::Player& player ) //SEQ_3: ENEMY14, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00035: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00036( Entity::Player& player ) //SEQ_3: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00036: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00037( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00037: Normal(Talk, TargetCanMove), id=KOKKAGUNNSOU01359" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player ) //SEQ_3: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player ) //SEQ_4: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00043: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00044( player );
    };
    player.playScene( getId(), 43, NONE, callback );
  }
  void Scene00044( Entity::Player& player ) //SEQ_4: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00044: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
      player.sendDebug( "Finished with AutoFadeIn scene, calling forceZoneing..." );
      player.eventFinish( getId(), 1 );
      player.forceZoneing();
    };
    player.playScene( getId(), 44, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00045( Entity::Player& player ) //SEQ_4: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00045: Normal(Talk, TargetCanMove), id=KOKKAGUNNSOU01359" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00046: Normal(None), id=unknown" );
  }

  void Scene00047( Entity::Player& player ) //SEQ_4: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00047: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player ) //SEQ_4: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00048: Normal(None), id=unknown" );
  }

  void Scene00049( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00049: Normal(None), id=unknown" );
  }

  void Scene00050( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse215:66895 calling Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MERLWYB" );
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
    player.playScene( getId(), 50, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse215 );
