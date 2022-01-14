// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse409 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse409() : Sapphire::ScriptAPI::EventScript( 65613 ){}; 
  ~GaiUse409() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_3, 7 entries
  //SEQ_4, 6 entries
  //SEQ_5, 8 entries
  //SEQ_6, 3 entries
  //SEQ_7, 5 entries
  //SEQ_255, 3 entries

  //ACTOR0 = 1009996
  //ACTOR1 = 1010001
  //ACTOR2 = 1010002
  //ACTOR3 = 1009997
  //ACTOR4 = 1010148
  //ACTOR5 = 1010149
  //ACTOR6 = 1010150
  //ACTOR7 = 1010151
  //ACTOR8 = 1010152
  //ACTOR9 = 1010191
  //CUTSCENEN01 = 613
  //ENEMY0 = 5040708
  //ENEMY1 = 5040710
  //EOBJECT0 = 2004657
  //EOBJECT1 = 2004658
  //EOBJECT2 = 2004992
  //EOBJECT3 = 2004993
  //EOBJECT4 = 2004659
  //EVENTRANGE0 = 5040702
  //EVENTACTIONSEARCH = 1
  //LOCACTOR0 = 1009811
  //LOCACTOR1 = 1007097
  //LOCACTOR2 = 1004145
  //LOCACTOR3 = 1008190
  //LOCACTOR4 = 5040291
  //LOCFACIAL0 = 617
  //LOCMOTION0 = 718
  //LOCMOTION1 = 1008
  //LOCMOTION2 = 996
  //LOCMUSIC0 = 85
  //LOCMUSIC1 = 223

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1009996 || param2 == 1009996 ) // ACTOR0 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
            // +Callback Scene00001: Normal(CutScene, AutoFadeIn), id=unknown
            // +Callback Scene00002: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR2 = LUCIA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1009997 || param2 == 1009997 ) // ACTOR3 = YUYUHASE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=YUYUHASE
          }
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR2 = LUCIA
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1010148 || param2 == 1010148 ) // ACTOR4 = THIRDSQUADRON00077
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=THIRDSQUADRON00077
          }
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR2 = LUCIA
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 2004657 || param2 == 2004657 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1010148 || param2 == 1010148 ) // ACTOR4 = THIRDSQUADRON00077
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=THIRDSQUADRON00077
          break;
        }
        if( param1 == 2004658 || param2 == 2004658 ) // EOBJECT1 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004992 || param2 == 2004992 ) // EOBJECT2 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004993 || param2 == 2004993 ) // EOBJECT3 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR2 = LUCIA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 1010149 || param2 == 1010149 ) // ACTOR5 = THIRDSQUADRON00077
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THIRDSQUADRON00077
          }
          break;
        }
        if( param1 == 2004658 || param2 == 2004658 ) // EOBJECT1 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004992 || param2 == 2004992 ) // EOBJECT2 = unknown
        {
          Scene00021( player ); // Scene00021: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004993 || param2 == 2004993 ) // EOBJECT3 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR2 = LUCIA
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 5040702 || param2 == 5040702 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00025( player ); // Scene00025: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5040708 || param2 == 5040708 ) // ENEMY0 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 5040710 || param2 == 5040710 ) // ENEMY1 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004659 || param2 == 2004659 ) // EOBJECT4 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010149 || param2 == 1010149 ) // ACTOR5 = THIRDSQUADRON00077
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=THIRDSQUADRON00077
          break;
        }
        if( param1 == 1010150 || param2 == 1010150 ) // ACTOR6 = YUYUHASE
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=YUYUHASE
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR2 = LUCIA
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 6:
      {
        if( param1 == 1010150 || param2 == 1010150 ) // ACTOR6 = YUYUHASE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUYUHASE
          }
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR2 = LUCIA
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 7:
      {
        if( param1 == 1010151 || param2 == 1010151 ) // ACTOR7 = HERETIC00077
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00036( player ); // Scene00036: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=HERETIC00077
          }
          break;
        }
        if( param1 == 1010150 || param2 == 1010150 ) // ACTOR6 = YUYUHASE
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=YUYUHASE
          break;
        }
        if( param1 == 1010152 || param2 == 1010152 ) // ACTOR8 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR2 = LUCIA
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=LUCIA
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1010191 || param2 == 1010191 ) // ACTOR9 = ALPHINAUD
        {
          Scene00041( player ); // Scene00041: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1010001 || param2 == 1010001 ) // ACTOR1 = AYMERIC
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=AYMERIC
          break;
        }
        if( param1 == 1010002 || param2 == 1010002 ) // ACTOR2 = LUCIA
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=LUCIA
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
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 2 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 6 );
    }
  }
  void checkProgressSeq6( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 7 );
    }
  }
  void checkProgressSeq7( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00001: Normal(CutScene, AutoFadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00002( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00002( Entity::Player& player ) //SEQ_0: ACTOR0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00002: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_0: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00003: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_0: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00004: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_1: ACTOR3, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_1: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00006: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_1: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00007: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR4, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00008: Normal(Talk, TargetCanMove), id=THIRDSQUADRON00077" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00009: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_2: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00010: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player ) //SEQ_3: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00012: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00013: Normal(Talk, TargetCanMove), id=THIRDSQUADRON00077" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_3: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00017: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_3: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00018: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player ) //SEQ_4: ACTOR5, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00019: Normal(Talk, TargetCanMove), id=THIRDSQUADRON00077" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00021( Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00021: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00022( Entity::Player& player ) //SEQ_4: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00023: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player ) //SEQ_4: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00024: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player ) //SEQ_5: EVENTRANGE0, UI8AL = 2, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 2 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_5: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00026: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00027( Entity::Player& player ) //SEQ_5: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00027: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00028( Entity::Player& player ) //SEQ_5: EOBJECT4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00028: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00029( Entity::Player& player ) //SEQ_5: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00029: Normal(Talk, TargetCanMove), id=THIRDSQUADRON00077" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player ) //SEQ_5: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00030: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player ) //SEQ_5: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00031: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player ) //SEQ_5: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00032: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player ) //SEQ_6: ACTOR6, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00033: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq6( player );
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player ) //SEQ_6: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00034: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_6: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00035: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player ) //SEQ_7: ACTOR7, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00036: Normal(Talk, FadeIn, TargetCanMove, ENpcBind), id=HERETIC00077" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq7( player );
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_7: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00037: Normal(Talk, TargetCanMove), id=YUYUHASE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player ) //SEQ_7: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player ) //SEQ_7: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player ) //SEQ_7: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00040: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player ) //SEQ_255: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00041: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player ) //SEQ_255: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00042: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player ) //SEQ_255: ACTOR2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse409:65613 calling Scene00043: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse409 );
