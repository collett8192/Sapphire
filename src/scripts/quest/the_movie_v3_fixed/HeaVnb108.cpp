// FFXIVTheMovie.ParserV3
//fix: black screen, skip quest battle, cutscene position at seq 255.
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVnb108 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVnb108() : Sapphire::ScriptAPI::EventScript( 67699 ){}; 
  ~HeaVnb108() = default; 

  //SEQ_0, 5 entries
  //SEQ_1, 16 entries
  //SEQ_2, 2 entries
  //SEQ_3, 10 entries
  //SEQ_255, 9 entries

  //ACTOR0 = 1016008
  //ACTOR1 = 1016009
  //ACTOR10 = 1016042
  //ACTOR11 = 1016043
  //ACTOR12 = 1016044
  //ACTOR13 = 1016045
  //ACTOR14 = 1016046
  //ACTOR15 = 1016047
  //ACTOR16 = 1016039
  //ACTOR17 = 1016040
  //ACTOR18 = 1016041
  //ACTOR19 = 1012163
  //ACTOR2 = 1016010
  //ACTOR20 = 1016049
  //ACTOR21 = 1013167
  //ACTOR22 = 1012251
  //ACTOR23 = 1012252
  //ACTOR24 = 1012253
  //ACTOR25 = 1016060
  //ACTOR26 = 1016061
  //ACTOR27 = 1012337
  //ACTOR28 = 1012377
  //ACTOR29 = 1016050
  //ACTOR3 = 1016011
  //ACTOR30 = 1016051
  //ACTOR4 = 1016012
  //ACTOR5 = 1016034
  //ACTOR6 = 1016035
  //ACTOR7 = 1016036
  //ACTOR8 = 1016037
  //ACTOR9 = 1016038
  //CUTSCENEN01 = 1054
  //CUTSCENEN02 = 1055
  //CUTSCENEN03 = 1056
  //CUTSCENEN04 = 1057
  //CUTSCENEN05 = 1058
  //CUTSCENEN06 = 1059
  //CUTSCENEN07 = 1060
  //EOBJECT0 = 2006608
  //LOCACTOR0 = 6093732
  //LOCACTOR1 = 6093733
  //LOCACTOR10 = 6081119
  //LOCACTOR11 = 6081115
  //LOCACTOR12 = 6081116
  //LOCACTOR13 = 6081117
  //POPRANGE0 = 6163372
  //POPRANGE1 = 5827750
  //QUESTBATTLE0 = 150
  //TERRITORYTYPE0 = 513
  //TERRITORYTYPE1 = 419

private:
  void onProgress( Entity::Player& player, uint64_t param1, uint32_t param2, uint32_t type, uint32_t param3 )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( param1 == 1016008 || param2 == 1016008 ) // ACTOR0 = unknown
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(CutScene, QuestAccept), id=unknown
        }
        if( param1 == 1016009 || param2 == 1016009 ) // ACTOR1 = HILDA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1016010 || param2 == 1016010 ) // ACTOR2 = ALPHINAUD
        {
          Scene00003( player ); // Scene00003: Normal(Talk), id=ALPHINAUD
        }
        if( param1 == 1016011 || param2 == 1016011 ) // ACTOR3 = YSHTOLA
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016012 || param2 == 1016012 ) // ACTOR4 = THANCRED
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=THANCRED
        }
        break;
      }
      case 1:
      {
        if( param1 == 1016034 || param2 == 1016034 ) // ACTOR5 = AYMERIC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=AYMERIC
          }
        }
        if( param1 == 1016035 || param2 == 1016035 ) // ACTOR6 = ALPHINAUD
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( param1 == 1016036 || param2 == 1016036 ) // ACTOR7 = YSHTOLA
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016037 || param2 == 1016037 ) // ACTOR8 = THANCRED
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1016038 || param2 == 1016038 ) // ACTOR9 = ARTOIREL
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ARTOIREL
        }
        if( param1 == 1016042 || param2 == 1016042 ) // ACTOR10 = LUCIA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1016043 || param2 == 1016043 ) // ACTOR11 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( param1 == 1016044 || param2 == 1016044 ) // ACTOR12 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( param1 == 1016045 || param2 == 1016045 ) // ACTOR13 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( param1 == 1016046 || param2 == 1016046 ) // ACTOR14 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( param1 == 1016047 || param2 == 1016047 ) // ACTOR15 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( param1 == 2006608 || param2 == 2006608 ) // EOBJECT0 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( param1 == 1016039 || param2 == 1016039 ) // ACTOR16 = HILDA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1016040 || param2 == 1016040 ) // ACTOR17 = EUDESTAND
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        if( param1 == 1016041 || param2 == 1016041 ) // ACTOR18 = SYMME
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR19 = HANDELOUP
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        break;
      }
      case 2:
      {
        if( type == 4 ) // BASE_ID_TERRITORY_TYPE = unknown
        {
          Scene00022( player ); // Scene00022: Normal(CutScene), id=unknown
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR19 = HANDELOUP
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        break;
      }
      case 3:
      {
        if( param1 == 1016049 || param2 == 1016049 ) // ACTOR20 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00024( player ); // Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR21 = LUCIA
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR22 = HILDA
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR23 = SYMME
        {
          Scene00027( player ); // Scene00027: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR24 = EUDESTAND
        {
          Scene00028( player ); // Scene00028: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        if( param1 == 1016060 || param2 == 1016060 ) // ACTOR25 = YSHTOLA
        {
          Scene00029( player ); // Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( param1 == 1016061 || param2 == 1016061 ) // ACTOR26 = THANCRED
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR19 = HANDELOUP
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        if( param1 == 1012337 || param2 == 1012337 ) // ACTOR27 = BUTLER01580
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=BUTLER01580
        }
        if( param1 == 1012377 || param2 == 1012377 ) // ACTOR28 = STEWARD
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=STEWARD
        }
        break;
      }
      case 255:
      {
        if( param1 == 1016050 || param2 == 1016050 ) // ACTOR29 = unknown
        {
          Scene00034( player );
        }
        if( param1 == 1016051 || param2 == 1016051 ) // ACTOR30 = TATARU
        {
          Scene00037( player );
        }
        if( param1 == 1013167 || param2 == 1013167 ) // ACTOR21 = LUCIA
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( param1 == 1012251 || param2 == 1012251 ) // ACTOR22 = HILDA
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( param1 == 1012252 || param2 == 1012252 ) // ACTOR23 = SYMME
        {
          Scene00040( player ); // Scene00040: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( param1 == 1012253 || param2 == 1012253 ) // ACTOR24 = EUDESTAND
        {
          Scene00041( player ); // Scene00041: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        if( param1 == 1012163 || param2 == 1012163 ) // ACTOR19 = HANDELOUP
        {
          Scene00042( player ); // Scene00042: Normal(Talk, TargetCanMove), id=HANDELOUP
        }
        if( param1 == 1012337 || param2 == 1012337 ) // ACTOR27 = BUTLER01580
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=BUTLER01580
        }
        if( param1 == 1012377 || param2 == 1012377 ) // ACTOR28 = STEWARD
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=STEWARD
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
  /*
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  */
  void checkProgressSeq2( Entity::Player& player )
  {
    player.setQuestUI8AL( getId(), 0 );
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVnb108:67699 calling [BranchTrue]Scene00001: Normal(CutScene, QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
      player.eventFinish( getId(), 1 );
      player.forceZoneing( 418, 85, 24, -6.53, -1.77 );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00002: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00003: Normal(Talk), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00004: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00005: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00006: Normal(Talk, QuestBattle, YesNo, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        Scene00022( player );
      }
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00007: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00008: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00009: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00010: Normal(Talk, TargetCanMove), id=ARTOIREL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00011: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00018: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00019: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00020: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00021: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00022: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 22, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00023: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00024: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 24, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00025: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00026: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00027: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00028: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00029: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 29, NONE, callback );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00030: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00031: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00032: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00033: Normal(Talk, TargetCanMove), id=STEWARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00034: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00035( player );
    };
    player.playScene( getId(), 34, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling [BranchTrue]Scene00035: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00036( player );
      }
    };
    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00036: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
      {
        player.finishQuest( getId() );
        player.eventFinish( getId(), 1 );
        player.exitInstance();
      }
    };
    player.playScene( getId(), 36, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00037: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00038: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00039: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00040: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 40, NONE, callback );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00041: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 41, NONE, callback );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00042: Normal(Talk, TargetCanMove), id=HANDELOUP" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 42, NONE, callback );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00043: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVnb108:67699 calling Scene00044: Normal(Talk, TargetCanMove), id=STEWARD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVnb108 );
