#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 67133;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 3;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class DivineIntervention : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto BNPC_COMPANION_ALPHINAUD = 5853419;
  static constexpr auto BNPC_ENEMY_GRINNAUX = 5853420;
  static constexpr auto BNPC_ENEMY_PAULECRAIN = 5853421;
  static constexpr auto BNPC_VFX_CHAIN_01 = 5853427;
  static constexpr auto BNPC_VFX_ELECTRON_01 = 5853422;
  static constexpr auto BNPC_VFX_ELECTRON_02 = 5853423;
  static constexpr auto BNPC_VFX_ELECTRON_03 = 5853424;
  static constexpr auto BNPC_VFX_ELECTRON_04 = 5853425;
  static constexpr auto BNPC_TOUMEI_PLAYER = 5853426;
  static constexpr auto BNPC_VFX_ELECTRON_06 = 5927949;
  static constexpr auto BNPC_VFX_ELECTRON_07 = 5927950;
  static constexpr auto BNPC_VFX_ELECTRON_08 = 5927951;
  static constexpr auto BNPC_VFX_ELECTRON_09 = 5927952;
  static constexpr auto INIT_ENPC_TATARU = 5853510;
  static constexpr auto QIB_YELL_01 = 2582;
  static constexpr auto CUT_SCENE_N_01 = 796;
  static constexpr auto STATUS_FETTERS = 667;
  static constexpr auto STATUS_PARAM_FETTERS = 1433;
  static constexpr auto CHANNELING_CHAIN = 10;
  static constexpr auto DEF_ACTION_CHAIN_GANG = 3991;
  static constexpr auto DEF_ACTION_LIGHTENING = 3992;
  static constexpr auto LOC_POS_ACTOR0 = 5908213;
  static constexpr auto LOC_POS_ACTOR1 = 5908214;
  static constexpr auto LOC_POS_ACTOR2 = 5908215;
  static constexpr auto LOC_POS_ACTOR3 = 5908216;
  static constexpr auto LOC_POS_ACTOR4 = 5908217;
  static constexpr auto LOC_POS_ACTOR5 = 5908218;
  static constexpr auto LOC_POS_ACTOR6 = 5908219;
  static constexpr auto LOC_ACTOR0 = 1008181;
  static constexpr auto LOC_ACTOR1 = 1012189;
  static constexpr auto LOC_ACTOR2 = 1012465;
  static constexpr auto LOC_ACTOR3 = 1012466;
  static constexpr auto LOC_ACTOR4 = 1012467;
  static constexpr auto LOC_ACTOR5 = 1012468;
  static constexpr auto LOC_ACTOR6 = 1012469;
  static constexpr auto ACTION_TIMELIN_EVENT_BASE_KNEE_SUFFERING = 936;
  static constexpr auto ACTION_TIMELIN_EVENT_BASE_FRIGHTENED3 = 4215;
  static constexpr auto ACTION_TIMELIN_EVENT_BASE_CHAIR_SIT = 788;
  static constexpr auto LOC_POS_CAM0 = 5908250;
  static constexpr auto BNPCBASE_CHAIN = 4140;
  static constexpr auto BNPCBASE_ELECTRON = 3780;

public:
  DivineIntervention() : Sapphire::ScriptAPI::QuestBattleScript( 105 )
  { }

  void onInit( QuestBattle& instance ) override
  {
    instance.registerEObj( "unknown_0", 2006981, 5656867, 4, { 0.000000f, 0.000000f, -15.851080f }, 1.000000f, 0.000000f ); 

  }

  void onUpdate( QuestBattle& instance, uint64_t tickCount ) override
  {
    //===========THE_MOVIE start============
    while( instance.getCustomVar( 0 ) < instance.getCustomVar( 1 ) )
    {
      auto p = instance.getPlayer( instance.getCustomVar( 2 + instance.getCustomVar( 0 ) ) );

      if( p && p->getEvent( instance.getDirectorId() ) )
        break;

      if( p && p->getQuestSeq( FFXIV_THE_MOVIE_INSTANCE_QUEST_ID ) == FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED )
      {
        p->sendUrgent( "skipping quest battle..." );
        p->setPosAndNotifyClient( 0, 0, 0, -3.1415 );
        p->eventStart( p->getId(), instance.getDirectorId(), Event::EventHandler::EnterTerritory, 1, p->getZoneId() );
        p->playScene( instance.getDirectorId(), SCENE_LIST[ 0 ], FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, 0, 0, 0,
          std::bind( &ScriptObject::the_movie_callback, this, std::placeholders::_1, std::placeholders::_2, FFXIV_THE_MOVIE_INSTANCE_QUEST_ID, FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET, SCENE_LIST, 0 ) );
      }

      instance.setCustomVar( 0, instance.getCustomVar( 0 ) + 1 );
    }
    //===========THE_MOVIE end============

  }

  void onEnterTerritory( QuestBattle& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {
    //===========THE_MOVIE start============
    instance.setCustomVar( 2 + instance.getCustomVar( 1 ), player.getId() );
    instance.setCustomVar( 1, instance.getCustomVar( 1 ) + 1 );
    //===========THE_MOVIE end============

  }
  //===========THE_MOVIE start============
  void onDebug( Entity::Player& player, uint32_t param ) override
  {
    auto instance = player.getCurrentQuestBattle();
    if( !instance || instance->getDirectorId() != getId() )
      return;

    player.eventStart( player.getId(), instance->getDirectorId(), Event::EventHandler::EnterTerritory, 1, player.getZoneId() );
    player.playScene( instance->getDirectorId(), param, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, 0, 0, 0, nullptr );
  }
  //===========THE_MOVIE end============

};

EXPOSE_SCRIPT( DivineIntervention );