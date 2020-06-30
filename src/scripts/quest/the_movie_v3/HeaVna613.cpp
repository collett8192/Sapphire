// FFXIVTheMovie.ParserV3
// id hint used:
//SCENE_35 = EDMONT
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna613 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna613() : Sapphire::ScriptAPI::EventScript( 67198 ){}; 
  ~HeaVna613() = default; 

  //SEQ_0, 8 entries
  //SEQ_1, 8 entries
  //SEQ_2, 14 entries
  //SEQ_3, 15 entries
  //SEQ_255, 15 entries

  //ACTOR0 = 1012430
  //ACTOR1 = 1012431
  //ACTOR10 = 1012251
  //ACTOR11 = 1012377
  //ACTOR12 = 1012252
  //ACTOR13 = 1012253
  //ACTOR14 = 1012397
  //ACTOR15 = 1013173
  //ACTOR16 = 1013174
  //ACTOR17 = 1013175
  //ACTOR2 = 1012432
  //ACTOR3 = 1013166
  //ACTOR4 = 1012407
  //ACTOR5 = 1013104
  //ACTOR6 = 1013105
  //ACTOR7 = 1013176
  //ACTOR8 = 1013167
  //ACTOR9 = 1013161
  //CUTSCENEN01 = 1039

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012430 || actorId == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012431 || actorId == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1012432 || actorId == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013166 || actorId == 1013166 ) // ACTOR3 = AYMERIC
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 1012407 || actorId == 1012407 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 1013104 || actorId == 1013104 ) // ACTOR5 = unknown
        {
          Scene00006( player ); // Scene00006: Normal(None), id=unknown
        }
        if( actor == 1013105 || actorId == 1013105 ) // ACTOR6 = unknown
        {
          Scene00007( player ); // Scene00007: Normal(None), id=unknown
        }
        if( actor == 1013176 || actorId == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
        }
        break;
      }
      case 1:
      {
        if( actor == 1013166 || actorId == 1013166 ) // ACTOR3 = AYMERIC
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=AYMERIC
          }
        }
        if( actor == 1012430 || actorId == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012431 || actorId == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1012432 || actorId == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1012407 || actorId == 1012407 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1013104 || actorId == 1013104 ) // ACTOR5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( actor == 1013105 || actorId == 1013105 ) // ACTOR6 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 1013176 || actorId == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
        }
        break;
      }
      case 2:
      {
        if( actor == 1013167 || actorId == 1013167 ) // ACTOR8 = LUCIA
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=LUCIA
            // +Callback Scene00018: Normal(Talk, TargetCanMove), id=LUCIA
          }
        }
        if( actor == 1013161 || actorId == 1013161 ) // ACTOR9 = TATARU
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=TATARU
            // +Callback Scene00020: Normal(Talk, TargetCanMove), id=TATARU
          }
        }
        if( actor == 1012251 || actorId == 1012251 ) // ACTOR10 = HILDA
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=HILDA
            // +Callback Scene00022: Normal(Talk, TargetCanMove), id=HILDA
          }
        }
        if( actor == 1012430 || actorId == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00023( player ); // Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012431 || actorId == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00024( player ); // Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1012432 || actorId == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00025( player ); // Scene00025: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013166 || actorId == 1013166 ) // ACTOR3 = AYMERIC
        {
          Scene00026( player ); // Scene00026: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 1012407 || actorId == 1012407 ) // ACTOR4 = unknown
        {
          Scene00027( player ); // Scene00027: Normal(None), id=unknown
        }
        if( actor == 1013104 || actorId == 1013104 ) // ACTOR5 = unknown
        {
          Scene00028( player ); // Scene00028: Normal(None), id=unknown
        }
        if( actor == 1013105 || actorId == 1013105 ) // ACTOR6 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
        }
        if( actor == 1013176 || actorId == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00030( player ); // Scene00030: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
        }
        if( actor == 1012377 || actorId == 1012377 ) // ACTOR11 = BUTLER01580
        {
          Scene00031( player ); // Scene00031: Normal(Talk, TargetCanMove), id=BUTLER01580
        }
        if( actor == 1012252 || actorId == 1012252 ) // ACTOR12 = SYMME
        {
          Scene00032( player ); // Scene00032: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( actor == 1012253 || actorId == 1012253 ) // ACTOR13 = EUDESTAND
        {
          Scene00033( player ); // Scene00033: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        break;
      }
      case 3:
      {
        if( actor == 1012397 || actorId == 1012397 ) // ACTOR14 = EDMONT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00034( player ); // Scene00034: Normal(Talk, TargetCanMove), id=EDMONT
            // +Callback Scene00035: Normal(CutScene), id=EDMONT
          }
        }
        if( actor == 1012430 || actorId == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00036( player ); // Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012431 || actorId == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00037( player ); // Scene00037: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1012432 || actorId == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00038( player ); // Scene00038: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013166 || actorId == 1013166 ) // ACTOR3 = AYMERIC
        {
          Scene00039( player ); // Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 1012407 || actorId == 1012407 ) // ACTOR4 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        if( actor == 1013104 || actorId == 1013104 ) // ACTOR5 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( actor == 1013105 || actorId == 1013105 ) // ACTOR6 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        if( actor == 1013176 || actorId == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00043( player ); // Scene00043: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
        }
        if( actor == 1012377 || actorId == 1012377 ) // ACTOR11 = BUTLER01580
        {
          Scene00044( player ); // Scene00044: Normal(Talk, TargetCanMove), id=BUTLER01580
        }
        if( actor == 1012252 || actorId == 1012252 ) // ACTOR12 = SYMME
        {
          Scene00045( player ); // Scene00045: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( actor == 1012253 || actorId == 1012253 ) // ACTOR13 = EUDESTAND
        {
          Scene00046( player ); // Scene00046: Normal(Talk, TargetCanMove), id=EUDESTAND
        }
        if( actor == 1013167 || actorId == 1013167 ) // ACTOR8 = LUCIA
        {
          Scene00047( player ); // Scene00047: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1013161 || actorId == 1013161 ) // ACTOR9 = TATARU
        {
          Scene00048( player ); // Scene00048: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1012251 || actorId == 1012251 ) // ACTOR10 = HILDA
        {
          Scene00049( player ); // Scene00049: Normal(Talk, TargetCanMove), id=HILDA
        }
        break;
      }
      case 255:
      {
        if( actor == 1012430 || actorId == 1012430 ) // ACTOR0 = ALPHINAUD
        {
          Scene00050( player ); // Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012431 || actorId == 1012431 ) // ACTOR1 = YSHTOLA
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1012432 || actorId == 1012432 ) // ACTOR2 = ESTINIEN
        {
          Scene00052( player ); // Scene00052: Normal(Talk, TargetCanMove), id=ESTINIEN
        }
        if( actor == 1013166 || actorId == 1013166 ) // ACTOR3 = AYMERIC
        {
          Scene00053( player ); // Scene00053: Normal(Talk, TargetCanMove), id=AYMERIC
        }
        if( actor == 1013173 || actorId == 1013173 ) // ACTOR15 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
        }
        if( actor == 1013174 || actorId == 1013174 ) // ACTOR16 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
        }
        if( actor == 1013175 || actorId == 1013175 ) // ACTOR17 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
        }
        if( actor == 1013176 || actorId == 1013176 ) // ACTOR7 = NOTRELCHAMPS
        {
          Scene00057( player ); // Scene00057: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS
        }
        if( actor == 1012397 || actorId == 1012397 ) // ACTOR14 = EDMONT
        {
          Scene00058( player ); // Scene00058: Normal(Talk, TargetCanMove), id=EDMONT
        }
        if( actor == 1013167 || actorId == 1013167 ) // ACTOR8 = LUCIA
        {
          Scene00059( player ); // Scene00059: Normal(Talk, TargetCanMove), id=LUCIA
        }
        if( actor == 1013161 || actorId == 1013161 ) // ACTOR9 = TATARU
        {
          Scene00060( player ); // Scene00060: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1012251 || actorId == 1012251 ) // ACTOR10 = HILDA
        {
          Scene00061( player ); // Scene00061: Normal(Talk, TargetCanMove), id=HILDA
        }
        if( actor == 1012377 || actorId == 1012377 ) // ACTOR11 = BUTLER01580
        {
          Scene00062( player ); // Scene00062: Normal(Talk, TargetCanMove), id=BUTLER01580
        }
        if( actor == 1012252 || actorId == 1012252 ) // ACTOR12 = SYMME
        {
          Scene00063( player ); // Scene00063: Normal(Talk, TargetCanMove), id=SYMME
        }
        if( actor == 1012253 || actorId == 1012253 ) // ACTOR13 = EUDESTAND
        {
          Scene00064( player ); // Scene00064: Normal(Talk, TargetCanMove), id=EUDESTAND
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
    if( player.getQuestUI8BL( getId() ) == 1 )
      if( player.getQuestUI8AL( getId() ) == 1 )
        if( player.getQuestUI8BH( getId() ) == 1 )
        {
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 3 );
        }
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
    player.sendDebug( "HeaVna613:67198 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna613:67198 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00002: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00003: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00004: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00006: Normal(None), id=unknown" );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00007: Normal(None), id=unknown" );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00008: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00009: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00012: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00016: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00017: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00018( player );
    };
    player.playScene( getId(), 17, NONE, callback );
  }
  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling [BranchTrue]Scene00018: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00019: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00020( player );
    };
    player.playScene( getId(), 19, NONE, callback );
  }
  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling [BranchTrue]Scene00020: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00021: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00022( player );
    };
    player.playScene( getId(), 21, NONE, callback );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling [BranchTrue]Scene00022: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 22, NONE, callback );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00023: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 23, NONE, callback );
  }

  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00024: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 24, NONE, callback );
  }

  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00025: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 25, NONE, callback );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00026: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 26, NONE, callback );
  }

  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00027: Normal(None), id=unknown" );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00028: Normal(None), id=unknown" );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00029: Normal(None), id=unknown" );
  }

  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00030: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 30, NONE, callback );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00031: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 31, NONE, callback );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00032: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 32, NONE, callback );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00033: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 33, NONE, callback );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00034: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00035( player );
    };
    player.playScene( getId(), 34, NONE, callback );
  }
  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling [BranchTrue]Scene00035: Normal(CutScene), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 35, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00036: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 36, NONE, callback );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00037: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 37, NONE, callback );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00038: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 38, NONE, callback );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00039: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 39, NONE, callback );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00043: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 43, NONE, callback );
  }

  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00044: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 44, NONE, callback );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00045: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 45, NONE, callback );
  }

  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00046: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 46, NONE, callback );
  }

  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00047: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 47, NONE, callback );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00048: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 48, NONE, callback );
  }

  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00049: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 49, NONE, callback );
  }

  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00050: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 50, NONE, callback );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00051: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00052: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00053: Normal(Talk, TargetCanMove), id=AYMERIC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 53, NONE, callback );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00057: Normal(Talk, TargetCanMove), id=NOTRELCHAMPS" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 57, NONE, callback );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00058: Normal(Talk, TargetCanMove), id=EDMONT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 58, NONE, callback );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00059: Normal(Talk, TargetCanMove), id=LUCIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 59, NONE, callback );
  }

  void Scene00060( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00060: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 60, NONE, callback );
  }

  void Scene00061( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00061: Normal(Talk, TargetCanMove), id=HILDA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 61, NONE, callback );
  }

  void Scene00062( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00062: Normal(Talk, TargetCanMove), id=BUTLER01580" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 62, NONE, callback );
  }

  void Scene00063( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00063: Normal(Talk, TargetCanMove), id=SYMME" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 63, NONE, callback );
  }

  void Scene00064( Entity::Player& player )
  {
    player.sendDebug( "HeaVna613:67198 calling Scene00064: Normal(Talk, TargetCanMove), id=EUDESTAND" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 64, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna613 );
