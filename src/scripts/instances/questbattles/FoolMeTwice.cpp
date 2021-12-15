#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 66540;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 2;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 1, 6, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class FoolMeTwice : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_P_POP_CID = 4270049;
  static constexpr auto INIT_POP_1_ARC_01 = 4270002;
  static constexpr auto INIT_POP_1_ARC_02 = 4270003;
  static constexpr auto INIT_POP_1_LNC_01 = 4270007;
  static constexpr auto INIT_POP_1_LNC_02 = 4270008;
  static constexpr auto INIT_POP_1_GLA_01 = 4270011;
  static constexpr auto INIT_POP_1_ARMOR_01 = 4270036;
  static constexpr auto INIT_POP_2_CNJ_01 = 4270059;
  static constexpr auto INIT_POP_2_LNC_01 = 4270060;
  static constexpr auto INIT_POP_2_ARC_01 = 4270061;
  static constexpr auto LOC_ACTOR0 = 1003855;
  static constexpr auto LOC_ACTOR1 = 1007668;
  static constexpr auto LOC_ACTOR2 = 1007669;
  static constexpr auto LOC_ACTOR3 = 1007669;
  static constexpr auto LOC_ACTOR4 = 1002908;
  static constexpr auto LOC_ACTOR5 = 1007667;
  static constexpr auto LOC_POS_ACTOR0 = 4323824;
  static constexpr auto LOC_POS_ACTOR1 = 4323827;
  static constexpr auto LOC_POS_ACTOR2 = 4323828;
  static constexpr auto LOC_POS_ACTOR3 = 4323829;
  static constexpr auto LOC_POS_ACTOR4 = 4323830;
  static constexpr auto LOC_ACTION1 = 587;
  static constexpr auto QIB_LOG_MESSAGE_01 = 3226;
  static constexpr auto DEF_ACTION_OVER_BOOST = 1286;
  static constexpr auto CUT_SCENE_01 = 255;
  static constexpr auto BGM_BATTLE = 76;

public:
  FoolMeTwice() : Sapphire::ScriptAPI::QuestBattleScript( 63 )
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
        p->setPosAndNotifyClient( -169.16, 13.66, -610.9, -0.441 );
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

EXPOSE_SCRIPT( FoolMeTwice );