#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 67180;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 2;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============


class FamiliarFaces : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto BNPC_COMPANION_ALPHINAUD = 5862338;
  static constexpr auto BNPC_COMPANION_BANUBANU = 5862336;
  static constexpr auto BNPC_CENTURIO_BOSS = 5862331;
  static constexpr auto BNPC_EMPIRE_SWORD_01_02 = 5862332;
  static constexpr auto BNPC_EMPIRE_SWORD_01_03 = 5862333;
  static constexpr auto BNPC_EMPIRE_SWORD_01_04 = 5862334;
  static constexpr auto BNPC_EMPIRE_MAGIC_01_05 = 5862335;
  static constexpr auto BNPC_EMPIRE_AIRSHIP_02_01 = 5864438;
  static constexpr auto BNPC_EMPIRE_SWORD_02_02 = 5864439;
  static constexpr auto BNPC_EMPIRE_SWORD_02_03 = 5864440;
  static constexpr auto BNPC_EMPIRE_SWORD_02_04 = 5864441;
  static constexpr auto BNPC_EMPIRE_MAGIC_02_05 = 5864442;
  static constexpr auto BNPC_EMPIRE_SWORD_03_01 = 5864443;
  static constexpr auto BNPC_EMPIRE_SWORD_03_02 = 5864444;
  static constexpr auto BNPC_COMPANION_PET_CARBUNCLE_RED = 5878644;
  static constexpr auto DEF_ACTION_SUMMON_PET_BNPC = 4785;
  static constexpr auto QIB_YELL_01 = 2650;
  static constexpr auto QIB_YELL_02 = 2651;
  static constexpr auto LOC_MAKER_BANUBANU = 5916636;
  static constexpr auto LOC_MAKER_ZAKO01 = 5916640;
  static constexpr auto LOC_MAKER_ZAKO02 = 5916644;
  static constexpr auto LOC_MAKER_AL = 5916653;
  static constexpr auto LOC_MAKER_PC = 5916656;
  static constexpr auto LOC_MAKER_ZAKO03 = 5916663;
  static constexpr auto LOC_MAKER_TAICHO = 5916664;
  static constexpr auto LOC_ACTOR_AL = 1011887;
  static constexpr auto LOC_ACTOR_RONUBANU = 1012482;
  static constexpr auto LOC_ACTOR_TAICHO = 1012483;
  static constexpr auto LOC_ACTOR_ZAKO01 = 1012484;
  static constexpr auto LOC_ACTOR_ZAKO02 = 1012485;
  static constexpr auto LOC_ACTOR_ZAKO03 = 1012486;
  static constexpr auto LOC_MAKER_START = 5917403;
  static constexpr auto LOC_ACTION0 = 985;
  static constexpr auto LOC_ACTION1 = 4194;
  static constexpr auto BNPCSTATE_SCARED = 123;

public:
  FamiliarFaces() : Sapphire::ScriptAPI::QuestBattleScript( 107 )
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
        p->setPosAndNotifyClient( -759.5, -36, 50.4, 2.43 );
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

EXPOSE_SCRIPT( FamiliarFaces );