// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class StmBda406 : public Sapphire::ScriptAPI::EventScript
{
public:
  StmBda406() : Sapphire::ScriptAPI::EventScript( 68041 ){}; 
  ~StmBda406() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 4 entries
  //SEQ_2, 5 entries
  //SEQ_3, 11 entries
  //SEQ_4, 7 entries
  //SEQ_5, 2 entries
  //SEQ_255, 5 entries

  //ACTOR0 = 1020501
  //ACTOR1 = 1020546
  //ACTOR2 = 1020544
  //ACTOR3 = 1019396
  //ACTOR4 = 1020549
  //ACTOR5 = 1021741
  //ACTOR6 = 1021742
  //ACTOR7 = 1021743
  //ACTOR8 = 1021744
  //ACTOR9 = 1020545
  //EOBJECT0 = 2008245
  //EOBJECT1 = 2008246
  //EOBJECT2 = 2008247
  //EOBJECT3 = 2008248
  //EVENTACTION0 = 1
  //EVENTPLAYLIGHT = 914
  //ITEM0 = 2002203
  //LOCBGMEVENTEASTSAD = 489
  //LOCKODOMO1 = 1021969
  //LOCKODOMO2 = 1021970
  //LOCKODOMO3 = 1021971
  //LOCKODOMO4 = 1021972
  //NCUTEVENT04040 = 1439
  //POPRANGE0 = 6975820

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020546 || param2 == 1020546 ) // ACTOR1 = GOSETSU
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020544 || param2 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR3 = DORBEI
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=DORBEI
          }
          break;
        }
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020546 || param2 == 1020546 ) // ACTOR1 = GOSETSU
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020544 || param2 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        break;
      }
      case 2:
      {
        if( param1 == 1020549 || param2 == 1020549 ) // ACTOR4 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1020546 || param2 == 1020546 ) // ACTOR1 = GOSETSU
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020544 || param2 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 4
      case 3:
      {
        if( param1 == 2008245 || param2 == 2008245 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00014( player ); // Scene00014: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008246 || param2 == 2008246 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00016( player ); // Scene00016: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008247 || param2 == 2008247 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00018( player ); // Scene00018: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2008248 || param2 == 2008248 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 4 )
          {
            Scene00020( player ); // Scene00020: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1020549 || param2 == 1020549 ) // ACTOR4 = LYSE
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021741 || param2 == 1021741 ) // ACTOR5 = 01GIRL02505
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=01GIRL02505
          break;
        }
        if( param1 == 1021742 || param2 == 1021742 ) // ACTOR6 = 02BOY02505
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=02BOY02505
          break;
        }
        if( param1 == 1021743 || param2 == 1021743 ) // ACTOR7 = 03BOY02505
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=03BOY02505
          break;
        }
        if( param1 == 1021744 || param2 == 1021744 ) // ACTOR8 = 04GIRL02505
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=04GIRL02505
          break;
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 4
      case 4:
      {
        if( param1 == 1020549 || param2 == 1020549 ) // ACTOR4 = LYSE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00028( player ); // Scene00028: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00029: Normal(Talk, FadeIn, TargetCanMove), id=LYSE
          }
          break;
        }
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1021741 || param2 == 1021741 ) // ACTOR5 = 01GIRL02505
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=01GIRL02505
          break;
        }
        if( param1 == 1021742 || param2 == 1021742 ) // ACTOR6 = 02BOY02505
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=02BOY02505
          break;
        }
        if( param1 == 1021743 || param2 == 1021743 ) // ACTOR7 = 03BOY02505
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=03BOY02505
          break;
        }
        if( param1 == 1021744 || param2 == 1021744 ) // ACTOR8 = 04GIRL02505
        {
          Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=04GIRL02505
          break;
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00035( player ); // Scene00035: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=CIRINA
            // +Callback Scene00037: Normal(CutScene), id=unknown
          }
          break;
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=DORBEI
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1020544 || param2 == 1020544 ) // ACTOR2 = HIEN
        {
          Scene00039( player ); // Scene00039: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN
          break;
        }
        if( param1 == 1020546 || param2 == 1020546 ) // ACTOR1 = GOSETSU
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=GOSETSU
          break;
        }
        if( param1 == 1020545 || param2 == 1020545 ) // ACTOR9 = LYSE
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=LYSE
          break;
        }
        if( param1 == 1020501 || param2 == 1020501 ) // ACTOR0 = CIRINA
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=CIRINA
          break;
        }
        if( param1 == 1019396 || param2 == 1019396 ) // ACTOR3 = DORBEI
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=DORBEI
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
    if( player.getQuestUI8AL( getId() ) == 4 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
      player.setQuestUI8BH( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "StmBda406:68041 calling Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00002: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00003: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00004: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00005: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00006: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00007: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00008: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00009: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00010: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00011: Normal(Talk, TargetCanMove), id=HIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00012: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00014: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00016: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00018: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00020: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00021: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00022: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00023: Normal(Talk, TargetCanMove), id=01GIRL02505" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00024: Normal(Talk, TargetCanMove), id=02BOY02505" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00025: Normal(Talk, TargetCanMove), id=03BOY02505" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00026: Normal(Talk, TargetCanMove), id=04GIRL02505" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00027: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00028: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00029( player );
      }
    };
    player.playScene( getId(), 28, NONE, callback );
  }
  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00029: Normal(Talk, FadeIn, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 29, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00030: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00031: Normal(Talk, TargetCanMove), id=01GIRL02505" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00032: Normal(Talk, TargetCanMove), id=02BOY02505" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00033: Normal(Talk, TargetCanMove), id=03BOY02505" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00034: Normal(Talk, TargetCanMove), id=04GIRL02505" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 34, NONE, callback );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00035: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 35, NONE, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00036: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00037( player );
    };
    player.playScene( getId(), 36, NONE, callback );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00037: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 37, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00038: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00039: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=HIEN" );
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
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00040: Normal(Talk, TargetCanMove), id=GOSETSU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00041: Normal(Talk, TargetCanMove), id=LYSE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00042: Normal(Talk, TargetCanMove), id=CIRINA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "StmBda406:68041 calling Scene00043: Normal(Talk, TargetCanMove), id=DORBEI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }
};

EXPOSE_SCRIPT( StmBda406 );
