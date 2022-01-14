// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse406 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse406() : Sapphire::ScriptAPI::EventScript( 65605 ){}; 
  ~GaiUse406() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 7 entries
  //SEQ_2, 4 entries
  //SEQ_3, 4 entries
  //SEQ_4, 3 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006444
  //ACTOR1 = 1009988
  //ACTOR2 = 1009984
  //ACTOR3 = 1009985
  //ACTOR4 = 1010065
  //ACTOR5 = 1006453
  //ACTOR6 = 1009989
  //ACTOR7 = 1009990
  //EOBJECT0 = 2004652
  //EOBJECT1 = 2004653
  //EOBJECT2 = 2004654
  //EOBJECT3 = 2004655
  //EVENTACTIONLOOKOUTLONG = 41
  //EVENTACTIONWAITING2MIDDLE = 12
  //LOCACTOR4 = 1009991
  //LOCACTOR5 = 1010577
  //LOCACTOR6 = 4262386
  //LOCMOTION0 = 725
  //LOCMUSIC0 = 78
  //LOCMUSICNO = 1
  //LUAACTORGAIUSE1414 = 5033612
  //LUAACTORGAIUSE1415 = 5033615
  //LUAACTORGAIUSE1416 = 5033620

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DRILLEMONT
        break;
      }
      case 1:
      {
        if( param1 == 2004652 || param2 == 2004652 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(FadeIn, QuestGimmickReaction, AutoFadeIn, ENpcBind), id=unknown
            // +Callback Scene00004: Normal(FadeIn, SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1009988 || param2 == 1009988 ) // ACTOR1 = HERETICLANCER00069
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=HERETICLANCER00069
          break;
        }
        if( param1 == 1009984 || param2 == 1009984 ) // ACTOR2 = ALPHINAUD
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1009985 || param2 == 1009985 ) // ACTOR3 = AYMERIC
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010065 || param2 == 1010065 ) // ACTOR4 = LUCIA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1006453 || param2 == 1006453 ) // ACTOR5 = JEANTREMONT
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove, ENpcBind), id=JEANTREMONT
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 2004653 || param2 == 2004653 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(SystemTalk, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1009989 || param2 == 1009989 ) // ACTOR6 = HERETICLANCER00069
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=HERETICLANCER00069
          break;
        }
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1006453 || param2 == 1006453 ) // ACTOR5 = JEANTREMONT
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=JEANTREMONT
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2004654 || param2 == 2004654 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(SystemTalk, ENpcBind), id=unknown
          }
          break;
        }
        if( param1 == 1009990 || param2 == 1009990 ) // ACTOR7 = HERETICLANCER00069
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=HERETICLANCER00069
          break;
        }
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1006453 || param2 == 1006453 ) // ACTOR5 = JEANTREMONT
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=JEANTREMONT
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 2004655 || param2 == 2004655 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00022( player ); // Scene00022: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown
          }
          break;
        }
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1006453 || param2 == 1006453 ) // ACTOR5 = JEANTREMONT
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=JEANTREMONT
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1006444 || param2 == 1006444 ) // ACTOR0 = DRILLEMONT
        {
          Scene00025( player ); // Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DRILLEMONT
          break;
        }
        if( param1 == 1006453 || param2 == 1006453 ) // ACTOR5 = JEANTREMONT
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=JEANTREMONT
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
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 2 );
    }
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
    player.sendDebug( "GaiUse406:65605 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse406:65605 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00003: Normal(FadeIn, QuestGimmickReaction, AutoFadeIn, ENpcBind), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00004: Normal(FadeIn, SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00005: Normal(Talk, TargetCanMove), id=HERETICLANCER00069" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00006: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00007: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_1: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00008: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00009: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_1: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00010: Normal(Talk, TargetCanMove, ENpcBind), id=JEANTREMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_2: EOBJECT1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00012: Normal(SystemTalk, ENpcBind), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00013: Normal(Talk, TargetCanMove), id=HERETICLANCER00069" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_2: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00014: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00015: Normal(Talk, TargetCanMove), id=JEANTREMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: EOBJECT2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00017: Normal(SystemTalk, ENpcBind), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ACTOR7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00018: Normal(Talk, TargetCanMove), id=HERETICLANCER00069" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_3: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00019: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_3: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00020: Normal(Talk, TargetCanMove), id=JEANTREMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_4: EOBJECT3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00022: Normal(Talk, FadeIn, QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00023: Normal(Talk, TargetCanMove), id=DRILLEMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_4: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00024: Normal(Talk, TargetCanMove), id=JEANTREMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_255: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00025: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=DRILLEMONT" );
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
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_255: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse406:65605 calling Scene00026: Normal(Talk, TargetCanMove), id=JEANTREMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse406 );
