#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 66087;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 2;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 3;
const uint32_t SCENE_LIST[] = { 1, 6, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class DutyHonorCountry : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_P_POP_1ST_01 = 4087433;
  static constexpr auto INIT_P_POP_1ST_02 = 4087434;
  static constexpr auto INIT_POP_1ST_BOSS = 4087437;
  static constexpr auto INIT_POP_1ST_ARC_01_01 = 4087440;
  static constexpr auto INIT_POP_1ST_ARC_01_02 = 4087443;
  static constexpr auto INIT_POP_1ST_ARC_01_03 = 4087445;
  static constexpr auto INIT_POP_1ST_PGL_01_04 = 4087449;
  static constexpr auto INIT_POP_1ST_PGL_01_05 = 4087451;
  static constexpr auto INIT_POP_1ST_PGL_01_06 = 4087452;
  static constexpr auto INIT_P_POP_1ST_03 = 4087459;
  static constexpr auto INIT_P_POP_1ST_04 = 4087460;
  static constexpr auto INIT_POP_1ST_CNJ_02_01 = 4087493;
  static constexpr auto INIT_POP_1ST_THM_02_02 = 4087494;
  static constexpr auto INIT_POP_1ST_ARC_02_03 = 4087498;
  static constexpr auto INIT_POP_1ST_ARC_02_04 = 4087499;
  static constexpr auto INIT_POP_1ST_PGL_02_05 = 4087502;
  static constexpr auto INIT_POP_1ST_PGL_02_06 = 4087504;
  static constexpr auto INIT_POP_1ST_MON_03_01 = 4087563;
  static constexpr auto INIT_POP_2ND_01 = 4087572;
  static constexpr auto INIT_POP_2ND_02 = 4087573;
  static constexpr auto INIT_P_POP_2ND_01 = 4087577;
  static constexpr auto WARP_01 = 4087657;
  static constexpr auto ACTION_CURE = 120;
  static constexpr auto ACTION_PRO = 123;
  static constexpr auto INIT_NOTAR_P_POP_1ST_01 = 4089037;
  static constexpr auto INIT_NOTAR_P_POP_1ST_02 = 4089038;
  static constexpr auto INIT_NOTAR_P_POP_1ST_03 = 4089039;
  static constexpr auto INIT_NOTAR_P_POP_1ST_04 = 4089040;
  static constexpr auto INIT_NOTAR_P_POP_1ST_05 = 4089041;
  static constexpr auto INIT_NOTAR_P_POP_1ST_06 = 4089043;
  static constexpr auto INIT_NOTAR_P_POP_1ST_07 = 4089044;
  static constexpr auto INIT_NOTAR_P_POP_1ST_08 = 4089045;
  static constexpr auto INIT_NOTAR_P_POP_1ST_09 = 4089046;
  static constexpr auto INIT_NOTAR_POP_1ST_01 = 4089052;
  static constexpr auto INIT_NOTAR_POP_1ST_02 = 4089055;
  static constexpr auto INIT_NOTAR_POP_1ST_03 = 4089053;
  static constexpr auto INIT_NOTAR_POP_1ST_04 = 4089054;
  static constexpr auto INIT_NOTAR_POP_1ST_05 = 4089050;
  static constexpr auto INIT_NOTAR_POP_1ST_06 = 4089051;
  static constexpr auto INIT_NOTAR_POP_1ST_07 = 4089048;
  static constexpr auto INIT_NOTAR_POP_1ST_08 = 4089049;
  static constexpr auto INIT_NOTAR_POP_1ST_09 = 4089047;
  static constexpr auto DEF_ACTION_MONSTER_SUMMON = 867;
  static constexpr auto DEF_WEATHER_RETURN = 2;
  static constexpr auto DEF_POISON = 18;
  static constexpr auto CUT_SCENE_01 = 194;
  static constexpr auto CUT_SCENE_02 = 195;
  static constexpr auto CUT_SCENE_03 = 196;
  static constexpr auto BGM_MASKED_BATTLE = 94;
  static constexpr auto DEF_WEATHER_BOSS = 19;

public:
  DutyHonorCountry() : Sapphire::ScriptAPI::QuestBattleScript( 38 )
  { }

  void onInit( QuestBattle& instance ) override
  {

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
        p->setPosAndNotifyClient( 244.3, -16.58, -130.8, 1.81 );
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

EXPOSE_SCRIPT( DutyHonorCountry );