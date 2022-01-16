#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 67124;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 1;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 2;
const uint32_t SCENE_LIST[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class AttheEndofOurHope : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto BNPC_ENEMY_GLADIATOR_HERETIC_01 = 5888456;
  static constexpr auto BNPC_ENEMY_GLADIATOR_HERETIC_02 = 5888460;
  static constexpr auto BNPC_ENEMY_CONJURER_HERETIC_03 = 5888461;
  static constexpr auto BNPC_ENEMY_LANCER_HERETIC_04 = 5888462;
  static constexpr auto BNPC_ENEMY_ARCANIST_HERETIC_05 = 5888463;
  static constexpr auto BNPC_ENEMY_GLADIATOR_HERETIC_06 = 5888464;
  static constexpr auto BNPC_ENEMY_GLADIATOR_HERETIC_07 = 5888465;
  static constexpr auto BNPC_ENEMY_CONJURER_HERETIC_08 = 5888466;
  static constexpr auto EOBJ_FOOTPRINT_01 = 5888470;
  static constexpr auto EOBJ_FOOTPRINT_02 = 5888471;
  static constexpr auto EOBJ_FOOTPRINT_03 = 5888472;
  static constexpr auto EOBJ_HIDING_PLACE_01 = 5888473;
  static constexpr auto ERANGE_HIDING_PLACE_01 = 5888476;
  static constexpr auto LOG_MESSAGE_EOBJ_01 = 3252;
  static constexpr auto LOG_MESSAGE_EOBJ_02 = 3253;
  static constexpr auto NPC_YELL_GLADIATOR_HERETIC_A_01 = 2640;
  static constexpr auto NPC_YELL_GLADIATOR_HERETIC_B_01 = 2641;
  static constexpr auto NPC_YELL_CONJURER_HERETIC_01 = 2642;
  static constexpr auto NPC_YELL_LANCER_HERETIC_01 = 2643;
  static constexpr auto NPC_YELL_LANCER_HERETIC_02 = 2644;
  static constexpr auto NPC_YELL_ARCANIST_HERETIC_01 = 2645;
  static constexpr auto NPC_YELL_ARCANIST_HERETIC_02 = 2646;
  static constexpr auto NPC_YELL_LANCER_HERETIC_DEAD = 2753;
  static constexpr auto EVENT_ACTION_FOOTPRINT = 21;
  static constexpr auto EVENT_ACTION_HIDING_PLACE = 50;
  static constexpr auto CUT_SCENE_N_01 = 792;
  static constexpr auto LOC_POS_ACTOR0 = 5908334;
  static constexpr auto LOC_POS_ACTOR1 = 5908335;
  static constexpr auto LOC_POS_ACTOR2 = 5908336;
  static constexpr auto LOC_POS_ACTOR3 = 5908337;
  static constexpr auto LOC_POS_ACTOR4 = 5908338;
  static constexpr auto LOC_POS_ACTOR5 = 5908339;
  static constexpr auto LOC_POS_ACTOR6 = 5908341;
  static constexpr auto LOC_ACTOR0 = 1012497;
  static constexpr auto LOC_ACTOR1 = 1012473;
  static constexpr auto LOC_ACTOR2 = 1012474;
  static constexpr auto LOC_ACTOR3 = 1012475;
  static constexpr auto LOC_ACTOR4 = 1012476;
  static constexpr auto ACTION_TIMELINE_EVENT_BASE_GUARD_STAND = 808;
  static constexpr auto ACTION_TIMELINE_EVENT_BASE_GUARD_LOOK_AWAY = 845;
  static constexpr auto ACTION_TIMELINE_BATTLE_CORPSE = 73;
  static constexpr auto BNPC_SPRIT = 4311;
  static constexpr auto BNPC_BOMB = 4312;
  static constexpr auto BNPC_FLOWER = 4313;
  static constexpr auto BNPC_COBLYN = 4314;
  static constexpr auto BNPC_BARD = 4840;
  static constexpr auto BNPC_GOLLILA_DORAGON = 4841;
  static constexpr auto POP_RANGE_ENEMY_HIDE_OUT = 5908743;
  static constexpr auto BGM_BOSS_BATTLE = 39;
  static constexpr auto BNPC_TOUMEI_HIDE_OUT = 5909462;
  static constexpr auto LOC_EOBJ0 = 2006171;
  static constexpr auto LOC_POS_ACTOR7 = 5910314;

public:
  AttheEndofOurHope() : Sapphire::ScriptAPI::QuestBattleScript( 111 )
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
        p->setPosAndNotifyClient( 101.9, 102.3, -39.9, 2.5 );
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

EXPOSE_SCRIPT( AttheEndofOurHope );