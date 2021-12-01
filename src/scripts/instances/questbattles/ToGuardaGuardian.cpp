#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 65983;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 2;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 3;
const uint32_t SCENE_LIST[] = { 1, 6, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class ToGuardaGuardian : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_NOTAR_P_POP_1ST_01 = 3854583;
  static constexpr auto INIT_NOTAR_POP_1ST_01 = 3854586;
  static constexpr auto INIT_NOTAR_P_POP_2ST_01 = 3854588;
  static constexpr auto INIT_NOTAR_POP_2ST_01 = 3854584;
  static constexpr auto INIT_NOTAR_POP_2ST_02 = 3854721;
  static constexpr auto INIT_NOTAR_P_POP_3ST_01 = 3854673;
  static constexpr auto INIT_NOTAR_POP_3ST_01 = 3854720;
  static constexpr auto INIT_NOTAR_P_POP_4ST_01 = 3854674;
  static constexpr auto INIT_NOTAR_POP_4ST_01 = 3854719;
  static constexpr auto INIT_NOTAR_POP_4ST_02 = 3854724;
  static constexpr auto INIT_NOTAR_P_POP_5ST_01 = 3854675;
  static constexpr auto INIT_NOTAR_POP_5ST_01 = 3854715;
  static constexpr auto INIT_NOTAR_POP_5ST_02 = 3854723;
  static constexpr auto INIT_P_POP_1ST_01 = 4089300;
  static constexpr auto INIT_P_POP_1ST_02 = 4089305;
  static constexpr auto INIT_POP_1ST_BOSS = 4089289;
  static constexpr auto INIT_POP_1ST_EXC_01_01 = 4089296;
  static constexpr auto INIT_POP_1ST_EXC_01_02 = 4089297;
  static constexpr auto INIT_POP_1ST_EXC_01_03 = 4089298;
  static constexpr auto INIT_POP_1ST_LNC_01_04 = 4089292;
  static constexpr auto INIT_POP_1ST_LNC_01_05 = 4089293;
  static constexpr auto INIT_POP_1ST_LNC_01_06 = 4089294;
  static constexpr auto INIT_P_POP_1ST_03 = 3854581;
  static constexpr auto INIT_P_POP_1ST_04 = 3854582;
  static constexpr auto INIT_POP_1ST_CNJ_02_01 = 3803263;
  static constexpr auto INIT_POP_1ST_CNJ_02_02 = 3803264;
  static constexpr auto INIT_POP_1ST_EXC_02_03 = 4089325;
  static constexpr auto INIT_POP_1ST_EXC_02_04 = 3803269;
  static constexpr auto INIT_POP_1ST_LNC_02_05 = 3803267;
  static constexpr auto INIT_POP_1ST_LNC_02_06 = 3803268;
  static constexpr auto INIT_POP_1ST_MON_03_01 = 4089330;
  static constexpr auto INIT_POP_2ND_01 = 4089338;
  static constexpr auto INIT_POP_2ND_02 = 3854784;
  static constexpr auto INIT_P_POP_2ND_01 = 4018837;
  static constexpr auto INIT_P_POP_2ND_02 = 4018839;
  static constexpr auto WARP_01 = 3803262;
  static constexpr auto ACTION_CURE = 120;
  static constexpr auto ACTION_PRO = 123;
  static constexpr auto DEF_ACTION_MONSTER_SUMMON = 867;
  static constexpr auto DEF_ACTION_DOKUBARI = 619;
  static constexpr auto CUT_SCENE_01 = 58;
  static constexpr auto CUT_SCENE_02 = 59;
  static constexpr auto DEF_POISON = 18;
  static constexpr auto DEF_WEATHER_BOSS = 19;
  static constexpr auto DEF_WEATHER_RETURN = 2;
  static constexpr auto BGM_MASKED_BATTLE = 94;

public:
  ToGuardaGuardian() : Sapphire::ScriptAPI::QuestBattleScript( 12 )
  { }

  void onInit( QuestBattle& instance ) override
  {
    instance.registerEObj( "unknown_0", 2005192, 5760474, 4, { -51.493111f, 0.309087f, 71.436897f }, 1.000000f, -0.000006f ); 

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
        p->setPosAndNotifyClient( -301.8, 21.55, 127.48, -1.515 );
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

EXPOSE_SCRIPT( ToGuardaGuardian );