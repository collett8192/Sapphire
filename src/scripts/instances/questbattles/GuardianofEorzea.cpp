#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 66992;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 2;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 1, 7, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class GuardianofEorzea : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_POP_1ST_01 = 4755440;
  static constexpr auto INIT_POP_2ST_01 = 4755441;
  static constexpr auto INIT_ENPC_01 = 4759673;
  static constexpr auto INIT_ENPC_02 = 4759674;
  static constexpr auto INIT_ENPC_03 = 4759676;
  static constexpr auto INIT_ENPC_04 = 4759677;
  static constexpr auto QIB_YELL_01 = 2240;
  static constexpr auto QIB_YELL_02 = 2241;
  static constexpr auto QIB_YELL_03 = 2242;
  static constexpr auto INIT_ENPC_05 = 4759678;
  static constexpr auto INIT_ENPC_06 = 4759679;
  static constexpr auto INIT_ENPC_07 = 4868546;
  static constexpr auto CUT_SCENE_01 = 580;
  static constexpr auto LOC_ACTOR0 = 1009412;
  static constexpr auto LOC_ACTOR1 = 1009413;
  static constexpr auto LOC_ACTOR2 = 1009688;
  static constexpr auto LOC_ACTOR3 = 1009689;
  static constexpr auto LOC_ACTOR4 = 1008176;
  static constexpr auto LOC_ACTOR5 = 1008178;
  static constexpr auto LOC_ACTOR6 = 1009690;
  static constexpr auto LOC_ACTOR7 = 1009691;
  static constexpr auto LOC_POS_ACTOR0 = 4887579;
  static constexpr auto LOC_POS_ACTOR1 = 4887580;
  static constexpr auto ACTION_TIMELINE_FACIAL_COMEON = 608;
  static constexpr auto ACTION_TIMELINE_EVENT_BASE_IDLE4 = 787;

public:
  GuardianofEorzea() : Sapphire::ScriptAPI::QuestBattleScript( 89 )
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
        p->setPosAndNotifyClient( 130.68, -3.31, -553.15, 2.51 );
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

EXPOSE_SCRIPT( GuardianofEorzea );