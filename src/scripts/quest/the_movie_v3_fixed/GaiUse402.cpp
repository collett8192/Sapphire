// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse402 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse402() : Sapphire::ScriptAPI::EventScript( 65589 ){}; 
  ~GaiUse402() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 6 entries
  //SEQ_3, 6 entries
  //SEQ_4, 22 entries
  //SEQ_5, 1 entries
  //SEQ_255, 1 entries

  //ACTIONTIMELINEEVENTBASEKNEESEACH = 1014
  //ACTIONTIMELINEEVENTSALUTECRY = 1045
  //ACTOR0 = 1009961
  //ACTOR1 = 1010078
  //ACTOR10 = 1009969
  //ACTOR11 = 1009970
  //ACTOR12 = 1009971
  //ACTOR13 = 1009112
  //ACTOR2 = 1009962
  //ACTOR3 = 1009963
  //ACTOR4 = 1009964
  //ACTOR5 = 1009965
  //ACTOR6 = 1010535
  //ACTOR7 = 1009966
  //ACTOR8 = 1009967
  //ACTOR9 = 1009968
  //BGMNOTHING = 1
  //ENEMY0 = 5045805
  //ENEMY1 = 5045806
  //ENEMY10 = 5046039
  //ENEMY11 = 5046040
  //ENEMY12 = 5046042
  //ENEMY13 = 5046043
  //ENEMY2 = 5045807
  //ENEMY3 = 5045957
  //ENEMY4 = 5045960
  //ENEMY5 = 5045961
  //ENEMY6 = 5046029
  //ENEMY7 = 5046030
  //ENEMY8 = 5046031
  //ENEMY9 = 5046037
  //EOBJECT0 = 2004643
  //EOBJECT1 = 2004644
  //EOBJECT2 = 2004645
  //EOBJECT3 = 2004646
  //EVENTRANGE0 = 5045803
  //EVENTRANGE1 = 5045922
  //EVENTRANGE2 = 5046024
  //EVENTRANGE3 = 5046034
  //EVENTACTIONRESCUEUNDERMIDDLE = 35
  //EVENTACTIONSEARCH = 1
  //LEVELIDNPC01 = 5045514
  //LEVELIDNPC02 = 5045515
  //LEVELIDNPC03 = 5045516
  //LOCACTOR0 = 1008192
  //LOCACTOR1 = 1010066
  //LOCACTOR2 = 1010067
  //LOCACTOR3 = 1010068
  //LOCACTOR4 = 1010069
  //LOCBGM0 = 114

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ILBERD
        break;
      }
      case 1:
      {
        if( param1 == 1010078 || param2 == 1010078 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
          break;
        }
        if( param1 == 1009961 || param2 == 1009961 ) // ACTOR0 = ILBERD
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ILBERD
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1009962 || param2 == 1009962 ) // ACTOR2 = ALIANNE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=ALIANNE
          }
          break;
        }
        if( param1 == 1009963 || param2 == 1009963 ) // ACTOR3 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009964 || param2 == 1009964 ) // ACTOR4 = CRYSTALSOLDIER00053
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=CRYSTALSOLDIER00053
          break;
        }
        if( param1 == 1009965 || param2 == 1009965 ) // ACTOR5 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
          break;
        }
        if( param1 == 1010078 || param2 == 1010078 ) // ACTOR1 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1010535 || param2 == 1010535 ) // ACTOR6 = ILBERD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ILBERD
          break;
        }
        break;
      }
      case 3:
      {
        if( param1 == 5045803 || param2 == 5045803 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 1009966 || param2 == 1009966 ) // ACTOR7 = RHESHPOLAALI
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00011( player ); // Scene00011: Normal(Talk, Message, TargetCanMove), id=RHESHPOLAALI
            // +Callback Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=RHESHPOLAALI
          }
          break;
        }
        if( param1 == 5045805 || param2 == 5045805 ) // ENEMY0 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
          break;
        }
        if( param1 == 5045806 || param2 == 5045806 ) // ENEMY1 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
          break;
        }
        if( param1 == 5045807 || param2 == 5045807 ) // ENEMY2 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004643 || param2 == 2004643 ) // EOBJECT0 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
          break;
        }
        break;
      }
      case 4:
      {
        if( param1 == 5045922 || param2 == 5045922 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 3 )
          {
            Scene00017( player ); // Scene00017: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5045957 || param2 == 5045957 ) // ENEMY3 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
          break;
        }
        if( param1 == 5045960 || param2 == 5045960 ) // ENEMY4 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
          break;
        }
        if( param1 == 5045961 || param2 == 5045961 ) // ENEMY5 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          break;
        }
        if( param1 == 5046024 || param2 == 5046024 ) // EVENTRANGE2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00021( player ); // Scene00021: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5046029 || param2 == 5046029 ) // ENEMY6 = unknown
        {
          Scene00022( player ); // Scene00022: Normal(None), id=unknown
          break;
        }
        if( param1 == 5046030 || param2 == 5046030 ) // ENEMY7 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          break;
        }
        if( param1 == 5046031 || param2 == 5046031 ) // ENEMY8 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(None), id=unknown
          break;
        }
        if( param1 == 5046034 || param2 == 5046034 ) // EVENTRANGE3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 5 )
          {
            Scene00025( player ); // Scene00025: Normal(Message, PopBNpc), id=unknown
          }
          break;
        }
        if( param1 == 5046037 || param2 == 5046037 ) // ENEMY9 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          break;
        }
        if( param1 == 5046039 || param2 == 5046039 ) // ENEMY10 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
          break;
        }
        if( param1 == 5046040 || param2 == 5046040 ) // ENEMY11 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
          break;
        }
        if( param1 == 5046042 || param2 == 5046042 ) // ENEMY12 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          break;
        }
        if( param1 == 5046043 || param2 == 5046043 ) // ENEMY13 = unknown
        {
          Scene00030( player ); // Scene00030: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004644 || param2 == 2004644 ) // EOBJECT1 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004645 || param2 == 2004645 ) // EOBJECT2 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
          break;
        }
        if( param1 == 2004646 || param2 == 2004646 ) // EOBJECT3 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009967 || param2 == 1009967 ) // ACTOR8 = ALIANNE
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=ALIANNE
          break;
        }
        if( param1 == 1009968 || param2 == 1009968 ) // ACTOR9 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009969 || param2 == 1009969 ) // ACTOR10 = CRYSTALSOLDIER00053
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=CRYSTALSOLDIER00053
          break;
        }
        if( param1 == 1009970 || param2 == 1009970 ) // ACTOR11 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
          break;
        }
        if( param1 == 1009971 || param2 == 1009971 ) // ACTOR12 = RHESHPOLAALI
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=RHESHPOLAALI
          break;
        }
        break;
      }
      case 5:
      {
        if( type != 2 ) Scene00039( player ); // Scene00039: Normal(Talk, NpcDespawn, TargetCanMove), id=ALIANNE
        break;
      }
      case 255:
      {
        if( type != 2 ) Scene00040( player ); // Scene00040: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
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
    if( player.getQuestUI8AL( getId() ) == 3 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestBitFlag8( getId(), 1, false );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8BH( getId() ) == 5 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 2, false );
          player.setQuestBitFlag8( getId(), 3, false );
          player.updateQuest( getId(), 5 );
        }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse402:65589 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player ) //SEQ_1: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player ) //SEQ_1: ACTOR0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00003: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR2, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00004: Normal(Talk, NpcDespawn, TargetCanMove, ENpcBind), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player ) //SEQ_2: ACTOR4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00006: Normal(Talk, TargetCanMove), id=CRYSTALSOLDIER00053" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player ) //SEQ_2: ACTOR5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player ) //SEQ_2: ACTOR1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player ) //SEQ_2: ACTOR6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00009: Normal(Talk, TargetCanMove), id=ILBERD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player ) //SEQ_3: EVENTRANGE0, UI8AL = 3, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      //player.setQuestUI8AL( getId(), 3 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00011: Normal(Talk, Message, TargetCanMove), id=RHESHPOLAALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player ) //SEQ_3: ACTOR7, UI8AL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00012: Normal(Talk, FadeIn, TargetCanMove), id=RHESHPOLAALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00013( Entity::Player& player ) //SEQ_3: ENEMY0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00014( Entity::Player& player ) //SEQ_3: ENEMY1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00014: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00015( Entity::Player& player ) //SEQ_3: ENEMY2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00015: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player ) //SEQ_3: EOBJECT0, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00016: Normal(None), id=unknown" );
    checkProgressSeq3( player );
  }

  void Scene00017( Entity::Player& player ) //SEQ_4: EVENTRANGE1, UI8BL = 3, Flag8(1)=True
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00017: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player ) //SEQ_4: ENEMY3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00018: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00019( Entity::Player& player ) //SEQ_4: ENEMY4, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00019: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00020( Entity::Player& player ) //SEQ_4: ENEMY5, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00020: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00021( Entity::Player& player ) //SEQ_4: EVENTRANGE2, UI8AL = 3, Flag8(2)=True
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00021: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 3 );
      player.setQuestBitFlag8( getId(), 2, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player ) //SEQ_4: ENEMY6, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00022: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00023( Entity::Player& player ) //SEQ_4: ENEMY7, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00023: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00024( Entity::Player& player ) //SEQ_4: ENEMY8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00024: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00025( Entity::Player& player ) //SEQ_4: EVENTRANGE3, UI8BH = 5, Flag8(3)=True
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00025: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 5 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player ) //SEQ_4: ENEMY9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00026: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00027( Entity::Player& player ) //SEQ_4: ENEMY10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00027: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00028( Entity::Player& player ) //SEQ_4: ENEMY11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00028: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00029( Entity::Player& player ) //SEQ_4: ENEMY12, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00029: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00030( Entity::Player& player ) //SEQ_4: ENEMY13, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00030: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00031( Entity::Player& player ) //SEQ_4: EOBJECT1, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00031: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00032( Entity::Player& player ) //SEQ_4: EOBJECT2, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00032: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00033( Entity::Player& player ) //SEQ_4: EOBJECT3, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00033: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00034( Entity::Player& player ) //SEQ_4: ACTOR8, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00034: Normal(Talk, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player ) //SEQ_4: ACTOR9, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player ) //SEQ_4: ACTOR10, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00036: Normal(Talk, TargetCanMove), id=CRYSTALSOLDIER00053" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player ) //SEQ_4: ACTOR11, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player ) //SEQ_4: ACTOR12, <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00038: Normal(Talk, TargetCanMove), id=RHESHPOLAALI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player ) //SEQ_5: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00039: Normal(Talk, NpcDespawn, TargetCanMove), id=ALIANNE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "GaiUse402:65589 calling Scene00040: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.playScene( getId(), 40, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
};

EXPOSE_SCRIPT( GaiUse402 );
