// FFXIVTheMovie.ParserV3
// simple method used
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
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WALTHEOF
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 1
      //seq 1 event item ITEM1 = UI8CL max stack 1
      //seq 1 event item ITEM2 = UI8DH max stack 1
      case 1:
      {
        if( actor == 2001013 || actorId == 2001013 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 2001014 || actorId == 2001014 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            player.setQuestUI8BH( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 2001015 || actorId == 2001015 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            player.setQuestUI8BL( getId(), 1 );
            checkProgressSeq1( player );
          }
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8CH max stack 1
      //seq 2 event item ITEM1 = UI8CL max stack 1
      //seq 2 event item ITEM2 = UI8DH max stack 1
      case 2:
      {
        if( actor == 1000502 || actorId == 1000502 ) // ACTOR1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            player.setQuestUI8AL( getId(), 1 );
            checkProgressSeq2( player );
          }
        }
        if( actor == 1000507 || actorId == 1000507 ) // ACTOR2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            player.setQuestUI8BH( getId(), 1 );
            checkProgressSeq2( player );
          }
        }
        if( actor == 1000505 || actorId == 1000505 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            player.setQuestUI8BL( getId(), 1 );
            checkProgressSeq2( player );
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 1
      //seq 255 event item ITEM2 = UI8CH max stack 1
      case 255:
      {
        Scene00007( player ); // Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WALTHEOF
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
          player.updateQuest( getId(), 2 );
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
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestUI8DH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst072:65922 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=WALTHEOF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubFst072:65922 calling Scene00007: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=WALTHEOF" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 7, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubFst072 );
