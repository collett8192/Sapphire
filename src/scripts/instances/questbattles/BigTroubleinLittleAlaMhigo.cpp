#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 66318;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 3;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 1, 8, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class BigTroubleinLittleAlaMhigo : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_P_POP_01 = 4251863;
  static constexpr auto INIT_P_POP_02 = 4251864;
  static constexpr auto INIT_P_POP_03 = 4251867;
  static constexpr auto INIT_P_POP_04 = 4251873;
  static constexpr auto INIT_P_POP_05 = 4251874;
  static constexpr auto INIT_POP_1ST_01 = 4252035;
  static constexpr auto INIT_POP_1ST_02 = 4252772;
  static constexpr auto INIT_POP_1ST_03 = 4252773;
  static constexpr auto INIT_POP_1ST_04 = 4252774;
  static constexpr auto INIT_POP_1ST_05 = 4252775;
  static constexpr auto INIT_POP_1ST_06 = 4252776;
  static constexpr auto INIT_POP_2ST_01 = 4252781;
  static constexpr auto INIT_POP_2ST_02 = 4252782;
  static constexpr auto INIT_POP_2ST_03 = 4252783;
  static constexpr auto INIT_POP_2ST_04 = 4252784;
  static constexpr auto INIT_POP_2ST_05 = 4252785;
  static constexpr auto INIT_POP_3ST_01 = 4252786;
  static constexpr auto INIT_POP_3ST_02 = 4252787;
  static constexpr auto INIT_POP_3ST_03 = 4252788;
  static constexpr auto INIT_POP_3ST_04 = 4252789;
  static constexpr auto INIT_POP_3ST_05 = 4252790;
  static constexpr auto YELL_QIB_01 = 1127;
  static constexpr auto YELL_QIB_02 = 1128;
  static constexpr auto LOC_ACTOR0 = 1006215;
  static constexpr auto LOC_ACTOR1 = 1008116;
  static constexpr auto LOC_ACTOR2 = 1007661;
  static constexpr auto LOC_ACTOR3 = 1007662;
  static constexpr auto LOC_ACTOR4 = 1007663;
  static constexpr auto LOC_ACTOR5 = 1003230;
  static constexpr auto LOC_ACTOR6 = 1003228;
  static constexpr auto LOC_ACTOR7 = 1003228;
  static constexpr auto LOC_POS_ACTOR0 = 4316733;
  static constexpr auto LOC_POS_ACTOR1 = 4316734;
  static constexpr auto LOC_POS_ACTOR2 = 4316737;
  static constexpr auto LOC_POS_ACTOR3 = 4316740;
  static constexpr auto LOC_POS_ACTOR4 = 4316745;
  static constexpr auto LOC_ACTION1 = 936;
  static constexpr auto LOC_ACTION2 = 985;
  static constexpr auto LOC_BGM1 = 83;

public:
  BigTroubleinLittleAlaMhigo() : Sapphire::ScriptAPI::QuestBattleScript( 58 )
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
        p->setPosAndNotifyClient( 34.8, 3.4, -346, 0 );
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

EXPOSE_SCRIPT( BigTroubleinLittleAlaMhigo );