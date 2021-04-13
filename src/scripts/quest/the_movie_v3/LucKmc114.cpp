// FFXIVTheMovie.ParserV3.2
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class LucKmc114 : public Sapphire::ScriptAPI::EventScript
{
public:
  LucKmc114() : Sapphire::ScriptAPI::EventScript( 68871 ){}; 
  ~LucKmc114() = default; 

  //SEQ_0, 2 entries
  //SEQ_1, 2 entries
  //SEQ_2, 2 entries
  //SEQ_3, 6 entries
  //SEQ_4, 2 entries
  //SEQ_5, 8 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1029231
  //ACTOR1 = 1029234
  //ACTOR2 = 1029238
  //ACTOR3 = 1029239
  //ACTOR4 = 1030944
  //ACTOR5 = 1030943
  //ACTOR6 = 1030945
  //ACTOR7 = 1029241
  //ACTOR8 = 1030946
  //ACTOR9 = 1029240
  //BGMEVENTTREMENDOUS01 = 190
  //EOBJECT0 = 2009887
  //EOBJECT1 = 2009888
  //EOBJECT2 = 2009889
  //EOBJECT3 = 2009890
  //EOBJECT4 = 2010622
  //EOBJECT5 = 2010623
  //EOBJECT6 = 2010624
  //EOBJECT7 = 2010625
  //EOBJECT8 = 2010626
  //EOBJECT9 = 2010627
  //ITEM0 = 2002552
  //ITEM1 = 2002846
  //LOCACTIONMAGICONEHAND = 5657
  //LOCACTOR0 = 1026571
  //LOCACTOR1 = 1028139
  //LOCACTORALMET = 1028139
  //LOCACTORCYMET = 1028141
  //LOCACTORYSHTOLA = 1026571
  //LOCBINDACTOR0 = 7945496
  //LOCBINDACTOR1 = 7944513
  //LOCBINDACTOR2 = 7944517
  //LOCBINDACTOR3 = 7944515
  //LOCBINDACTOR4 = 7944489
  //LOCBINDACTOR5 = 7984467
  //LOCBINDACTOR6 = 7984468
  //LOCBINDACTOR7 = 7984470
  //LOCBINDACTOR8 = 7984471
  //LOCPOSLCUTCAT = 8025538
  //LOCPOSLCUTDOG = 8025541
  //LOCPOSLCUTMONKEY = 8025542
  //LOCPOSLCUTOWL = 8025539
  //LOCPOSLCUTPARROT = 8025540
  //LOCPOSLCUTSNAKE = 8025537
  //LOCPOSLCUTSTART = 8025543
  //LOCSEEARTHSOUND = 218
  //LOCSEREFLECTION = 219
  //LOCVFXREFLEC = 3

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1029231 || param2 == 1029231 ) // ACTOR0 = ALMET
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029234 || param2 == 1029234 ) // ACTOR1 = YSHTOLA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      case 1:
      {
        if( param1 == 1029238 || param2 == 1029238 ) // ACTOR2 = ALMET
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ALMET
          }
          break;
        }
        if( param1 == 1029239 || param2 == 1029239 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack ?
      case 2:
      {
        if( param1 == 1030944 || param2 == 1030944 ) // ACTOR4 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1030943 || param2 == 1030943 ) // ACTOR5 = ALMET
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8CL max stack ?
      //seq 3 event item ITEM1 = UI8DH max stack 4
      case 3:
      {
        if( param1 == 2009887 || param2 == 2009887 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8CH( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Inventory), id=unknown
            // +Callback Scene00008: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009888 || param2 == 2009888 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Inventory), id=unknown
            // +Callback Scene00010: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009889 || param2 == 2009889 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00011( player ); // Scene00011: Normal(Inventory), id=unknown
            // +Callback Scene00012: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 2009890 || param2 == 2009890 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00013( player ); // Scene00013: Normal(Inventory), id=unknown
            // +Callback Scene00014: Normal(SystemTalk), id=unknown
          }
          break;
        }
        if( param1 == 1030945 || param2 == 1030945 ) // ACTOR6 = ALMET
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1029241 || param2 == 1029241 ) // ACTOR7 = YSHTOLA
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA
          break;
        }
        break;
      }
      //seq 4 event item ITEM1 = UI8BH max stack 4
      case 4:
      {
        if( param1 == 1029241 || param2 == 1029241 ) // ACTOR7 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA
            // +Callback Scene00019: Normal(Talk, FadeIn), id=unknown
          }
          break;
        }
        if( param1 == 1030945 || param2 == 1030945 ) // ACTOR6 = ALMET
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        break;
      }
      case 5:
      {
        if( param1 == 1030946 || param2 == 1030946 ) // ACTOR8 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=YSHTOLA
            // +Callback Scene00022: Normal(Talk, FadeIn, TargetCanMove, Menu, CanCancel), id=YSHTOLA
          }
          break;
        }
        if( param1 == 1029240 || param2 == 1029240 ) // ACTOR9 = ALMET
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 2010622 || param2 == 2010622 ) // EOBJECT4 = unknown
        {
          Scene00024( player ); // Scene00024: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2010623 || param2 == 2010623 ) // EOBJECT5 = unknown
        {
          Scene00025( player ); // Scene00025: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2010624 || param2 == 2010624 ) // EOBJECT6 = unknown
        {
          Scene00026( player ); // Scene00026: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2010625 || param2 == 2010625 ) // EOBJECT7 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2010626 || param2 == 2010626 ) // EOBJECT8 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(SystemTalk), id=unknown
          break;
        }
        if( param1 == 2010627 || param2 == 2010627 ) // EOBJECT9 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(SystemTalk), id=unknown
          break;
        }
        break;
      }
      case 255:
      {
        if( param1 == 1029240 || param2 == 1029240 ) // ACTOR9 = ALMET
        {
          Scene00030( player ); // Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALMET
          break;
        }
        if( param1 == 1030946 || param2 == 1030946 ) // ACTOR8 = YSHTOLA
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=YSHTOLA
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
      player.setQuestUI8BH( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8CH( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
          if( player.getQuestUI8BL( getId() ) == 1 )
          {
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CL( getId(), 0 );
            player.setQuestUI8DH( getId(), 0 );
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
    player.sendDebug( "LucKmc114:68871 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "LucKmc114:68871 calling Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00003: Normal(Talk, NpcDespawn, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00005: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00006: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00007: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }
  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00008: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8CH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00009: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00010: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00011: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00012( player );
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00012: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00013: Normal(Inventory), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00014: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00015: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00016: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00017: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00018( player );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00018: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00019( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }
  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00019: Normal(Talk, FadeIn), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 19, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00020: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00021: Normal(Talk, YesNo, TargetCanMove, CanCancel), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 || ( result.param1 > 0 && result.param2 == 1 ) )
      {
        Scene00022( player );
      }
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00022: Normal(Talk, FadeIn, TargetCanMove, Menu, CanCancel), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 == 512 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq5( player );
      }
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00023: Normal(Talk, TargetCanMove), id=ALMET" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00024: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00025: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00026: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00027: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00028: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00029: Normal(SystemTalk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00030: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=ALMET" );
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
    player.playScene( getId(), 30, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "LucKmc114:68871 calling Scene00031: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }
};

EXPOSE_SCRIPT( LucKmc114 );
