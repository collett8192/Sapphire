#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 66079;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 1;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 2;
const uint32_t SCENE_LIST[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class LurkersintheGrotto : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_POP_BOSS = 4083604;
  static constexpr auto INIT_POP_01_01 = 4083606;
  static constexpr auto INIT_POP_01_02 = 4083607;
  static constexpr auto INIT_POP_02_01 = 4083608;
  static constexpr auto INIT_POP_02_02 = 4083609;
  static constexpr auto INIT_POP_02_03 = 4083610;
  static constexpr auto INIT_POP_02_04 = 4083611;
  static constexpr auto INIT_P_POP_01 = 4083622;
  static constexpr auto CUT_SCENE_01 = 133;
  static constexpr auto HOW_TO_QIB = 79;

public:
  LurkersintheGrotto() : Sapphire::ScriptAPI::QuestBattleScript( 35 )
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
        p->setPosAndNotifyClient( -59, 26, -139, 3.14f );
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

EXPOSE_SCRIPT( LurkersintheGrotto );