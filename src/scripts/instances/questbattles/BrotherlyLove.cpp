#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 66260;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 3;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 1, 8, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class BrotherlyLove : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_P_POP_IDA = 4255892;
  static constexpr auto INIT_P_POP_PAPARIMO = 4255894;
  static constexpr auto INIT_POP_BOSS = 4255868;
  static constexpr auto INIT_POP_1_THM_01 = 4255869;
  static constexpr auto INIT_POP_1_THM_02 = 4255870;
  static constexpr auto INIT_POP_1_THM_03 = 4255871;
  static constexpr auto INIT_POP_2_CNJ_01 = 4255896;
  static constexpr auto INIT_POP_2_GLA_01 = 4255897;
  static constexpr auto INIT_POP_2_GLA_02 = 4255898;
  static constexpr auto INIT_POP_2_MOL_01 = 4255903;
  static constexpr auto INIT_POP_2_MOL_02 = 4255904;
  static constexpr auto INIT_POP_3_MOL_01 = 4261134;
  static constexpr auto INIT_POP_3_THM_01 = 4261155;
  static constexpr auto INIT_ENPC_01 = 4256371;
  static constexpr auto LOC_ACTOR0 = 1003005;
  static constexpr auto LOC_ACTOR1 = 1008117;
  static constexpr auto LOC_ACTOR2 = 1002275;
  static constexpr auto LOC_ACTOR3 = 1002276;
  static constexpr auto LOC_ACTOR4 = 1007007;
  static constexpr auto LOC_POS_ACTOR0 = 4307105;
  static constexpr auto LOC_POS_ACTOR1 = 4307106;
  static constexpr auto LOC_POS_ACTOR2 = 4307107;
  static constexpr auto LOC_POS_ACTOR3 = 4307108;
  static constexpr auto LOC_ACTION1 = 956;
  static constexpr auto LOC_ACTION2 = 954;
  static constexpr auto LOC_ACTION3 = 962;
  static constexpr auto POP_RANGE_MONSTER_DEPOP = 4332127;
  static constexpr auto LOC_ACTOR5 = 1008173;
  static constexpr auto LOC_BGM1 = 39;
  static constexpr auto LOC_BGM2 = 93;

public:
  BrotherlyLove() : Sapphire::ScriptAPI::QuestBattleScript( 57 )
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
        p->setPosAndNotifyClient( -280.9, 12.12, -37.25, -2.1 );
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

EXPOSE_SCRIPT( BrotherlyLove );