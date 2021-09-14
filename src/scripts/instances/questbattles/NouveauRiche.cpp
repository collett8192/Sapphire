#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 69398;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 4;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 1, 7, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class NouveauRiche : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_POP_1_LNC_01 = 4293092;
  static constexpr auto INIT_POP_1_LNC_02 = 4293093;
  static constexpr auto INIT_POP_1_LNC_03 = 4293095;
  static constexpr auto INIT_POP_1_KIK_01 = 4293096;
  static constexpr auto INIT_P_POP_1_RED_LEADER = 4293097;
  static constexpr auto INIT_P_POP_1_RED_LNC = 4293098;
  static constexpr auto INIT_POP_2_EXC_LEADER_01 = 4293099;
  static constexpr auto INIT_POP_2_LNC_01 = 4293109;
  static constexpr auto INIT_POP_2_THM_01 = 4293110;
  static constexpr auto INIT_POP_2_ARC_01 = 4293111;
  static constexpr auto INIT_P_POP_2_ARC_01 = 4293125;
  static constexpr auto INIT_P_POP_2_ARC_02 = 4293126;
  static constexpr auto INIT_P_POP_2_ARC_03 = 4293127;
  static constexpr auto POP_RANGE_DEPOP = 4295055;
  static constexpr auto LOC_ACTOR1 = 1008111;
  static constexpr auto LOC_ACTOR2 = 1007656;
  static constexpr auto LOC_ACTOR3 = 1007658;
  static constexpr auto LOC_ACTOR4 = 1007659;
  static constexpr auto LOC_ACTOR5 = 1007655;
  static constexpr auto LOC_ACTOR6 = 1007657;
  static constexpr auto LOC_POS_ACTOR0 = 4310117;
  static constexpr auto LOC_POS_ACTOR1 = 4310122;
  static constexpr auto LOC_POS_ACTOR2 = 4310125;
  static constexpr auto LOC_POS_ACTOR3 = 4310127;
  static constexpr auto LOC_ACTION1 = 961;
  static constexpr auto BGM_BATTLE = 39;
  static constexpr auto LOC_BGM1 = 117;

public:
  NouveauRiche() : Sapphire::ScriptAPI::QuestBattleScript( 13 )
  { }

  void onInit( QuestBattle& instance ) override
  {
    instance.registerEObj( "Entrance", 2000182, 5021407, 5, { 623.000000f, 23.872311f, 94.505638f }, 1.000000f, 0.000000f ); 
    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.registerEObj( "Exit", 2000139, 0, 4, { 623.000000f, 23.656260f, 61.956181f }, 1.000000f, 0.000000f ); 

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
        p->setPosAndNotifyClient( 32.85, 10.6, -10.46, -3.08 );
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

EXPOSE_SCRIPT( NouveauRiche );