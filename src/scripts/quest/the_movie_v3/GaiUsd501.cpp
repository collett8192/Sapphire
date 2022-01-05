// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsd501 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsd501() : Sapphire::ScriptAPI::EventScript( 65579 ){}; 
  ~GaiUsd501() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 5 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1007478
  //ACTOR1 = 1009769
  //ACTOR2 = 1009770
  //ACTOR3 = 1009771
  //ACTOR4 = 1010765
  //ACTOR5 = 1009772
  //ACTOR6 = 1009773
  //ACTOR7 = 1009774
  //ACTOR8 = 1009775
  //ACTOR9 = 1009768
  //BINDACTOR0 = 4999998
  //EMOTEANGRYADD = 639
  //EMOTELOOKOUTADD = 665
  //EOBJECT0 = 2004607
  //EVENTACTIONRESCUEUPPERMIDDLE = 39
  //EVENTARMS = 1041
  //EVENTBASEKNEESUFFERING = 936
  //FACIALANGRYSTRONG = 610
  //FACIALFSORRY = 613
  //FACIALSMILE = 605
  //FACIALSPEWING = 617
  //FACIALWHAT = 619
  //LOCACTION1 = 1002
  //LOCACTOR0 = 1004145
  //LOCACTOR1 = 1004146
  //LOCACTOR2 = 1008180
  //LOCACTOR3 = 1009768
  //LOCEOBJECT0 = 2004609
  //LOCEOBJECT0POS = 5000001
  //LOCMUSICEVENTFUAN01 = 130
  //LOCMUSICEVENTTHEMEFACEWAR = 83
  //LOCMUSICEVENTTHEMESECRET = 97
  //LOCMUSICFIELDSANDHOME01 = 66
  //LOCPOSCAM1 = 5349079
  //LOCPOSCAM2 = 5358070
  //LOCPOSCAM3 = 5375026
  //LOCSE1 = 42
  //LOCTALKSHAPE1 = 6
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKIMAGEDUNGEON = 257

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, TargetCanMove), id=URIANGER
        // +Callback Scene00002: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=URIANGER
        break;
      }
      case 1:
      {
        if( type != 2 ) Scene00003( player ); // Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=INVESTIGATORA00043
        break;
      }
      case 2:
      {
        if( param1 == 1009770 || param2 == 1009770 ) // ACTOR2 = INVESTIGATORB00043
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=INVESTIGATORB00043
          }
          break;
        }
        if( param1 == 1009769 || param2 == 1009769 ) // ACTOR1 = INVESTIGATORA00043
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=INVESTIGATORA00043
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 1009771 || param2 == 1009771 ) // ACTOR3 = URIANGER
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=URIANGER
          }
          break;
        }
        if( param1 == 1010765 || param2 == 1010765 ) // ACTOR4 = INVESTIGATORB00043
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=INVESTIGATORB00043
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1009772 || param2 == 1009772 ) // ACTOR5 = ALISAIE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALISAIE
          }
          break;
        }
        if( param1 == 1009773 || param2 == 1009773 ) // ACTOR6 = URIANGER
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=URIANGER
          break;
        }
        if( param1 == 2004607 || param2 == 2004607 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009774 || param2 == 1009774 ) // ACTOR7 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009775 || param2 == 1009775 ) // ACTOR8 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1009768 || param2 == 1009768 ) // ACTOR9 = ERKENRAD
        {
          Scene00014( player ); // Scene00014: Normal(Talk, Message, QuestReward, QuestComplete, TargetCanMove), id=ERKENRAD
          break;
        }
        if( param1 == 2004607 || param2 == 2004607 ) // EOBJECT0 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009774 || param2 == 1009774 ) // ACTOR7 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009775 || param2 == 1009775 ) // ACTOR8 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
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
    player.sendDebug( "GaiUsd501:65579 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsd501:65579 calling Scene00001: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00002: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00003: Normal(Talk, FadeIn, TargetCanMove), id=INVESTIGATORA00043" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00005: Normal(Talk, FadeIn, TargetCanMove), id=INVESTIGATORB00043" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00006: Normal(Talk, TargetCanMove), id=INVESTIGATORA00043" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_3: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00008: Normal(Talk, TargetCanMove), id=INVESTIGATORB00043" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_4: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00009: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=ALISAIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_4: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00010: Normal(Talk, TargetCanMove), id=URIANGER" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_4: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00012( Entity::Player& player ) //SEQ_4: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00014: Normal(Talk, Message, QuestReward, QuestComplete, TargetCanMove), id=ERKENRAD" );
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
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_255: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player ) //SEQ_255: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player ) //SEQ_255: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUsd501:65579 calling Scene00017: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUsd501 );
