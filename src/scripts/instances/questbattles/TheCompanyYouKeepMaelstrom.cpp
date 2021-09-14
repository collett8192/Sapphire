#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 66217;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 2;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 1, 9, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class TheCompanyYouKeepMaelstrom : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_P_POP_A = 4105799;
  static constexpr auto INIT_P_POP_B = 4105800;
  static constexpr auto INIT_P_POP_C = 4105801;
  static constexpr auto INIT_POP_TOP = 4105802;
  static constexpr auto INIT_POP_THM1_1 = 4105803;
  static constexpr auto INIT_POP_LNC1_2 = 4105805;
  static constexpr auto INIT_POP_LNC1_3 = 4105804;
  static constexpr auto INIT_POP_ARC1_4 = 4105807;
  static constexpr auto INIT_POP_ARC1_5 = 4105806;
  static constexpr auto INIT_POP_ARC2_1 = 4105863;
  static constexpr auto INIT_POP_ARC2_2 = 4105864;
  static constexpr auto INIT_POP_MAC2_3 = 4105862;
  static constexpr auto DEF_ACTION_MONSTER_WHISTLE = 983;
  static constexpr auto CUT_SCENE_01 = 218;
  static constexpr auto LOC_ACTOR0 = 1003836;
  static constexpr auto LOC_ACTOR1 = 1003837;
  static constexpr auto LOC_ACTOR2 = 1005028;
  static constexpr auto LOC_POS_ACTOR0 = 4163777;
  static constexpr auto POP_RANGE_BOSS_01 = 4165248;
  static constexpr auto POP_RANGE_BOSS_02 = 4165249;
  static constexpr auto POP_RANGE_BOSS_03 = 4165250;
  static constexpr auto DEF_ACTION_DRILL_ROCKET = 525;
  static constexpr auto LOC_ACTION1 = 961;
  static constexpr auto LOC_ACTOR9 = 1006151;

public:
  TheCompanyYouKeepMaelstrom() : Sapphire::ScriptAPI::QuestBattleScript( 48 )
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
        p->setPosAndNotifyClient( 377, 78.66, -353.656, -2.7237 );
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

EXPOSE_SCRIPT( TheCompanyYouKeepMaelstrom );