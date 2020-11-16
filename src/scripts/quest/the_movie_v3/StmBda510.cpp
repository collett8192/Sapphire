// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda510 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda510() : Sapphire::ScriptAPI::EventScript( 68483 ){}; 
  ~StmBda510() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 4 entries
  //SEQ_2, 6 entries
  //SEQ_3, 4 entries
  //SEQ_4, 9 entries
  //SEQ_255, 5 entries

  //ACTIONTIMELINEEVENTQUESTIONHEAD = 669
  //ACTOR0 = 1020232
  //ACTOR1 = 1020233
  //ACTOR2 = 1020234
  //ACTOR3 = 1020519
  //ACTOR4 = 1020523
  //BINDISSE001 = 6850943
  //BINDLYSE001 = 6850944
  //EOBJECT0 = 2007926
  //EOBJECT1 = 2007928
  //EOBJECT10 = 2008193
  //EOBJECT2 = 2007929
  //EOBJECT3 = 2007930
  //EOBJECT4 = 2007927
  //EOBJECT5 = 2008188
  //EOBJECT6 = 2008189
  //EOBJECT7 = 2008190
  //EOBJECT8 = 2008191
  //EOBJECT9 = 2008192
  //EVENTACTION0 = 4
  //EVENTACTION1 = 2
  //EVENTACTION2 = 3
  //ITEM0 = 2002176
  //ITEM1 = 2002177
  //LCUTBGM01 = 465

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack ?
      case 0:
      {
        if( param1 == 1020232 || param2 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020233 || param2 == 1020233 ) // ACTOR1 = ISSE
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1020234 || param2 == 1020234 ) // ACTOR2 = LYSE
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      //seq 1 event item ITEM0 = UI8BH max stack ?
      case 1:
      {
        if( param1 == 2007926 || param2 == 2007926 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Inventory), id=unknown
            // +Callback Scene00007: Normal(QuestGimmickReaction), id=unknown
          }
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020232 || param2 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8CH max stack ?
      //seq 2 event item ITEM1 = UI8CL max stack 15
      case 2:
      {
        if( param1 == 2007928 || param2 == 2007928 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 1020232 || param2 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 2007929 || param2 == 2007929 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2007930 || param2 == 2007930 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack ?
      //seq 3 event item ITEM1 = UI8BL max stack 15
      case 3:
      {
        if( param1 == 2007927 || param2 == 2007927 ) // EOBJECT4 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00020( player ); // Scene00020: Normal(Inventory), id=unknown
            // +Callback Scene00021: Normal(QuestGimmickReaction), id=unknown
          }
          break;
        }
        if( param1 == 1020232 || param2 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8DL max stack ?
      //seq 4 event item ITEM1 = UI8EH max stack 15
      case 4:
      {
        if( param1 == 2008188 || param2 == 2008188 ) // EOBJECT5 = unknown
        {
          if( player.getQuestUI8DH( getId() ) != 1 )
          {
            Scene00026( player ); // Scene00026: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008189 || param2 == 2008189 ) // EOBJECT6 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008190 || param2 == 2008190 ) // EOBJECT7 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00030( player ); // Scene00030: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1020232 || param2 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI
          break;
        }
        if( param1 == 2008191 || param2 == 2008191 ) // EOBJECT8 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00035( player ); // Scene00035: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008192 || param2 == 2008192 ) // EOBJECT9 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00037( player ); // Scene00037: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008193 || param2 == 2008193 ) // EOBJECT10 = unknown
        {
          if( player.getQuestUI8CL( getId() ) != 1 )
          {
            Scene00039( player ); // Scene00039: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack ?
      //seq 255 event item ITEM1 = UI8BL max stack 15
      case 255:
      {
        if( param1 == 1020232 || param2 == 1020232 ) // ACTOR0 = TSURANUKI
        {
          Scene00040( player ); // Scene00040: NpcTrade(Talk, TargetCanMove), id=unknown
          // +Callback Scene00041: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=TSURANUKI
          break;
        }
        if( param1 == 1020233 || param2 == 1020233 ) // ACTOR1 = ISSE
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=ISSE
          break;
        }
        if( param1 == 1020234 || param2 == 1020234 ) // ACTOR2 = LYSE
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020519 || param2 == 1020519 ) // ACTOR3 = ALPHINAUD
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=ALPHINAUD
          break;
        }
        if( param1 == 1020523 || param2 == 1020523 ) // ACTOR4 = YUGIRI
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=YUGIRI
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.updateQuest( getId(), 3 );
        }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8DH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
          if( player.getQuestUI8BL( getId() ) == 1 )
            if( player.getQuestUI8CH( getId() ) == 1 )
              if( player.getQuestUI8CL( getId() ) == 1 )
              {
                player.setQuestUI8DH( getId(), 0 );
                player.setQuestUI8AL( getId(), 0 );
                player.setQuestUI8BH( getId(), 0 );
                player.setQuestUI8BL( getId(), 0 );
                player.setQuestUI8CH( getId(), 0 );
                player.setQuestUI8CL( getId(), 0 );
                player.setQuestUI8DL( getId(), 0 );
                player.setQuestUI8EH( getId(), 0 );
                player.updateQuest( getId(), 255 );
                player.setQuestUI8BH( getId(), 1 );
                player.setQuestUI8BL( getId(), 15 );
              }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda510:68483 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00002: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00003: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00004: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00005: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00006: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00007: Normal(QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00009: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00010: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00012: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00013: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00014: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00015: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00017: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00019: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq2( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00020: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00021( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00021: Normal(QuestGimmickReaction), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00022: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00024: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00026: Normal(None), id=unknown" );
    player.setQuestUI8DH( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00028: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00030: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00031: Normal(Talk, TargetCanMove), id=TSURANUKI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00032: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00033: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00035: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00037: Normal(None), id=unknown" );
    player.setQuestUI8CH( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00039: Normal(None), id=unknown" );
    player.setQuestUI8CL( getId(), 1 );
    checkProgressSeq4( player );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00040: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00041( player );
      }
    };
    player.playScene( getId(), 40, NONE, callback );
  }
  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00041: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=TSURANUKI" );
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
    player.playScene( getId(), 41, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00042: Normal(Talk, TargetCanMove), id=ISSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00043: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00044: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "StmBda510:68483 calling Scene00045: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda510 );
