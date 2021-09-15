#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 66347;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 1;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 10, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class TheLominsanWay : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_POP_1_KAI_01 = 4295469;
  static constexpr auto INIT_POP_1_ROC_01 = 4295470;
  static constexpr auto INIT_POP_1_ROC_02 = 4295472;
  static constexpr auto INIT_POP_2_BOM_01 = 4295473;
  static constexpr auto INIT_ENPC_MIL_01 = 4295474;
  static constexpr auto DEF_PARALYSIS = 17;
  static constexpr auto POP_RANGE_ENEMY_MOVE_01 = 4295504;
  static constexpr auto LOGMESSAGE_QIB_01 = 3217;
  static constexpr auto LOGMESSAGE_QIB_02 = 3218;
  static constexpr auto LOGMESSAGE_QIB_03 = 3219;
  static constexpr auto QIB_YELL_01 = 1274;
  static constexpr auto QIB_YELL_02 = 1275;
  static constexpr auto QIB_YELL_03 = 1276;
  static constexpr auto QIB_YELL_04 = 1277;
  static constexpr auto QIB_YELL_05 = 1278;
  static constexpr auto QIB_YELL_06 = 1279;
  static constexpr auto QIB_YELL_07 = 1285;
  static constexpr auto BGM_BATTLE = 37;
  static constexpr auto LOC_ACTOR0 = 1006264;
  static constexpr auto LOC_ACTOR1 = 1005259;
  static constexpr auto LOC_POS_ACTOR0 = 4312558;
  static constexpr auto LOC_BGM1 = 87;

public:
  TheLominsanWay() : Sapphire::ScriptAPI::QuestBattleScript( 59 )
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
        p->setPosAndNotifyClient( 705.24, 65.8, -289.76, -1.05 );
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

EXPOSE_SCRIPT( TheLominsanWay );