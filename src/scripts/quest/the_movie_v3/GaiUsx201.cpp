// FFXIVTheMovie.ParserV3
// simple method used
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsx201 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsx201() : Sapphire::ScriptAPI::EventScript( 67245 ){}; 
  ~GaiUsx201() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 2 entries
  //SEQ_2, 1 entries
  //SEQ_3, 4 entries
  //SEQ_4, 1 entries
  //SEQ_5, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1007753
  //ACTOR1 = 1006725
  //ENEMY0 = 7625695
  //ENEMY1 = 7625884
  //ENEMY2 = 7625951
  //ENEMY3 = 7626039
  //EOBJECT0 = 2000075
  //EOBJECT1 = 2000076
  //EOBJECT2 = 2000077
  //EOBJECT3 = 2000078
  //EVENTACTION0 = 50
  //EVENTACTION1 = 1
  //ITEM0 = 2002484
  //ITEM1 = 2002485
  //ITEM2 = 2002486
  //ITEM3 = 2002487
  //LOCACTOR0 = 1003855
  //LOCPOSCAM1 = 4509927
  //NCUTEVENTGAIUSD2011 = 459

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NERO
        break;
      }
      case 1:
      {
        if( actor == 1006725 || actorId == 1006725 ) // ACTOR1 = RAMMBROES
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=RAMMBROES
          }
        }
        if( actor == 1007753 || actorId == 1007753 ) // ACTOR0 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(CutScene), id=unknown
        }
        break;
      }
      case 2:
      {
        Scene00004( player ); // Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=RAMMBROES
        break;
      }
      //seq 3 event item ITEM0 = UI8BL max stack 1
      //seq 3 event item ITEM1 = UI8CH max stack 1
      case 3:
      {
        if( actor == 2000075 || actorId == 2000075 ) // EOBJECT0 = NERO
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=NERO
          }
        }
        if( actor == 7625695 || actorId == 7625695 ) // ENEMY0 = RAMMBROES
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=RAMMBROES
        }
        if( actor == 2000076 || actorId == 2000076 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 7625884 || actorId == 7625884 ) // ENEMY1 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(Message, PopBNpc), id=unknown
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      //seq 4 event item ITEM1 = UI8BL max stack 1
      case 4:
      {
        Scene00009( player ); // Scene00009: Normal(None), id=unknown
        break;
      }
      //seq 5 event item ITEM2 = UI8BL max stack 1
      //seq 5 event item ITEM3 = UI8CH max stack 1
      case 5:
      {
        if( actor == 2000077 || actorId == 2000077 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 7625951 || actorId == 7625951 ) // ENEMY2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 2000078 || actorId == 2000078 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00012( player ); // Scene00012: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 7626039 || actorId == 7626039 ) // ENEMY3 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        break;
      }
      //seq 255 event item ITEM2 = UI8BH max stack 1
      //seq 255 event item ITEM3 = UI8BL max stack 1
      case 255:
      {
        Scene00014( player ); // Scene00014: Normal(Message, PopBNpc), id=unknown
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
    onProgress( player, param1, param1, 3, param1 );
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 4 );
      }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.setQuestUI8BH( getId(), 0 );
    player.setQuestUI8BL( getId(), 0 );
    player.updateQuest( getId(), 5 );
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8BH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
      {
        player.setQuestUI8BH( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8BL( getId(), 0 );
        player.setQuestUI8CH( getId(), 0 );
        player.updateQuest( getId(), 255 );
      }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsx201:67245 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NERO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00002: Normal(Talk, FadeIn, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00004: Normal(Talk, FadeIn, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00005: Normal(Talk, TargetCanMove), id=NERO" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00006: Normal(Talk, TargetCanMove), id=RAMMBROES" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00008: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00009: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00011: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00012: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00013: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsx201:67245 calling Scene00014: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsx201 );
