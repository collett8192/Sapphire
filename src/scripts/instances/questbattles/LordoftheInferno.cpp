#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 65879;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 2;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 4;
const uint32_t SCENE_LIST[] = { 1, 7, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class LordoftheInferno : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto INIT_POP_BOSS = 4098741;
  static constexpr auto INIT_P_POP_A = 4098743;
  static constexpr auto INIT_P_POP_B = 4098744;
  static constexpr auto INIT_P_POP_C = 4098745;
  static constexpr auto INIT_P_POP_SER = 4098749;
  static constexpr auto INIT_POP_1ST_01 = 4098775;
  static constexpr auto INIT_POP_1ST_02 = 4098776;
  static constexpr auto INIT_POP_1ST_03 = 4098777;
  static constexpr auto INIT_POP_1ST_04 = 4098783;
  static constexpr auto INIT_POP_1ST_05 = 4098784;
  static constexpr auto INIT_POP_1ST_06 = 4098791;
  static constexpr auto INIT_POP_1ST_07 = 4098792;
  static constexpr auto INIT_POP_2ND_01 = 4098806;
  static constexpr auto INIT_POP_2ND_02 = 4098810;
  static constexpr auto INIT_POP_2ND_03 = 4098819;
  static constexpr auto INIT_POP_2ND_04 = 4098821;
  static constexpr auto INIT_POP_2ND_05 = 4098823;
  static constexpr auto INIT_POP_3RD_01 = 4098839;
  static constexpr auto INIT_POP_3RD_02 = 4098840;
  static constexpr auto INIT_POP_3RD_03 = 4098842;
  static constexpr auto INIT_POP_1ST_08 = 4098866;
  static constexpr auto INIT_POP_1ST_09 = 4098871;
  static constexpr auto INIT_POP_3RD_04 = 4098886;
  static constexpr auto INIT_POP_3RD_05 = 4098887;
  static constexpr auto INIT_POP_3RD_06 = 4098888;
  static constexpr auto INIT_POP_3RD_07 = 4098889;
  static constexpr auto INIT_ENPC_POP_01 = 4100860;
  static constexpr auto CUT_SCENE_01 = 84;
  static constexpr auto CUT_SCENE_02 = 85;
  static constexpr auto UNLOCK_IMAGE_DUNGEON = 77;

public:
  LordoftheInferno() : Sapphire::ScriptAPI::QuestBattleScript( 45 )
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
  bool the_movie_on_content_skipped( Sapphire::Entity::Player& player ) override
  {
    player.forceZoneing( 146, -53.45f, -24.09f, -567.49f, -0.55f, false );
    return true;
  }
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

EXPOSE_SCRIPT( LordoftheInferno );