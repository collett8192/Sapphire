// FFXIVTheMovie.ParserV3.6
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst072 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst072() : Sapphire::ScriptAPI::EventScript( 65922 ){}; 
  ~SubFst072() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000501
  //ACTOR1 = 1000502
  //ACTOR2 = 1000507
  //ACTOR3 = 1000505
  //EOBJECT0 = 2001013
  //EOBJECT1 = 2001014
  //EOBJECT2 = 2001015
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000246
  //ITEM1 = 2000247
  //ITEM2 = 2000248
  //SEQ0ACTOR0 = 0
  //SEQ1EOBJECT0 = 1
  //SEQ1EOBJECT0EVENTACTIONNO = 99
  //SEQ1EOBJECT0EVENTACTIONOK = 100
  //SEQ1EOBJECT1 = 2
  //SEQ1EOBJECT1EVENTACTIONNO = 97
  //SEQ1EOBJECT1EVENTACTIONOK = 98
  //SEQ1EOBJECT2 = 3
  //SEQ1EOBJECT2EVENTACTIONNO = 95
  //SEQ1EOBJECT2EVENTACTIONOK = 96
  //SEQ2ACTOR1 = 4
  //SEQ2ACTOR1NPCTRADENO = 93
  //SEQ2ACTOR1NPCTRADEOK = 94
  //SEQ2ACTOR2 = 5
  //SEQ2ACTOR2NPCTRADENO = 91
  //SEQ2ACTOR2NPCTRADEOK = 92
  //SEQ2ACTOR3 = 6
  //SEQ2ACTOR3NPCTRADENO = 89
  //SEQ2ACTOR3NPCTRADEOK = 90
  //SEQ3ACTOR0 = 7

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( type != 2 ) Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WALTHEOF
        // +Callback Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WALTHEOF
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 1
      //seq 1 event item ITEM1 = UI8CL max stack 1
      //seq 1 event item ITEM2 = UI8DH max stack 1
      case 1:
      {
        if( param1 == 2001013 || param2 == 2001013 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00099( player ); // Scene00099: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001014 || param2 == 2001014 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00097( player ); // Scene00097: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 2001015 || param2 == 2001015 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00095( player ); // Scene00095: Normal(None), id=unknown
          }
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8CH max stack 1
      //seq 2 event item ITEM1 = UI8CL max stack 1
      //seq 2 event item ITEM2 = UI8DH max stack 1
      case 2:
      {
        if( param1 == 1000502 || param2 == 1000502 ) // ACTOR1 = BERTHE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: NpcTrade(Talk, TargetCanMove), id=BERTHE
            // +Callback Scene00094: Normal(Talk, TargetCanMove), id=BERTHE
          }
          break;
        }
        if( param1 == 1000507 || param2 == 1000507 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00093( player ); // Scene00093: Normal(None), id=unknown
          }
          break;
        }
        if( param1 == 1000505 || param2 == 1000505 ) // ACTOR3 = KEILEIGH
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=KEILEIGH
            // +Callback Scene00092: Normal(Talk, TargetCanMove), id=KEILEIGH
          }
          break;
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      //seq 255 event item ITEM2 = UI8CH max stack 1
      case 255:
      {
        if( type != 2 ) Scene00006( player ); // Scene00006: NpcTrade(Talk, TargetCanMove), id=DARANMERT
        // +Callback Scene00090: Normal(Talk, TargetCanMove), id=DARANMERT
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
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 2, false );
          player.setQuestBitFlag8( getId(), 3, false );
          player.updateQuest( getId(), 2 );
          player.setQuestUI8CH( getId(), 1 );
          player.setQuestUI8CL( getId(), 1 );
          player.setQuestUI8DH( getId(), 1 );
        }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestBitFlag8( getId(), 1, false );
          player.setQuestBitFlag8( getId(), 2, false );
          player.setQuestBitFlag8( getId(), 3, false );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestUI8DH( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 1 );
          player.setQuestUI8BL( getId(), 1 );
          player.setQuestUI8CH( getId(), 1 );
        }
  }

  void Scene00000( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst072:65922 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WALTHEOF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00007( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00007( Entity::Player& player ) //SEQ_0: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst072:65922 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WALTHEOF" );
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
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00099( Entity::Player& player ) //SEQ_1: EOBJECT0, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubFst072:65922 calling Scene00099: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 1, true );
    checkProgressSeq1( player );
  }

  void Scene00097( Entity::Player& player ) //SEQ_1: EOBJECT1, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "SubFst072:65922 calling Scene00097: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq1( player );
  }

  void Scene00095( Entity::Player& player ) //SEQ_1: EOBJECT2, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "SubFst072:65922 calling Scene00095: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    player.setQuestBitFlag8( getId(), 3, true );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player ) //SEQ_2: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubFst072:65922 calling Scene00004: NpcTrade(Talk, TargetCanMove), id=BERTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00094( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00094( Entity::Player& player ) //SEQ_2: ACTOR1, UI8AL = 1, Flag8(1)=True
  {
    player.sendDebug( "SubFst072:65922 calling Scene00094: Normal(Talk, TargetCanMove), id=BERTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 1, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 94, NONE, callback );
  }

  void Scene00093( Entity::Player& player ) //SEQ_2: ACTOR2, UI8BH = 1, Flag8(2)=True
  {
    player.sendDebug( "SubFst072:65922 calling Scene00093: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), 1 );
    player.setQuestBitFlag8( getId(), 2, true );
    checkProgressSeq2( player );
  }

  void Scene00005( Entity::Player& player ) //SEQ_2: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "SubFst072:65922 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=KEILEIGH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00092( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00092( Entity::Player& player ) //SEQ_2: ACTOR3, UI8BL = 1, Flag8(3)=True
  {
    player.sendDebug( "SubFst072:65922 calling Scene00092: Normal(Talk, TargetCanMove), id=KEILEIGH" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      player.setQuestBitFlag8( getId(), 3, true );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 92, NONE, callback );
  }

  void Scene00006( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst072:65922 calling Scene00006: NpcTrade(Talk, TargetCanMove), id=DARANMERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00090( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00090( Entity::Player& player ) //SEQ_255: , <No Var>, <No Flag>
  {
    player.sendDebug( "SubFst072:65922 calling Scene00090: Normal(Talk, TargetCanMove), id=DARANMERT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 90, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst072 );
