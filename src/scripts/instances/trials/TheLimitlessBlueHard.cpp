#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 67183;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 4;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 5;
const uint32_t SCENE_LIST[] = { 1015/*, 1022* = failed*/, 0 };
//===========THE_MOVIE end============

class TheLimitlessBlueHard :
  public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  TheLimitlessBlueHard() :
    Sapphire::ScriptAPI::InstanceContentScript( 20033 )
  { }

  void onInit( InstanceContent& instance ) override
  {
    instance.registerEObj( "Magitekfieldgenerator", 2005541, 0, 4, { -15.000000f, 0.000000f, 0.000000f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Dragonkiller", 2005544, 0, 4, { -13.000000f, 0.182584f, -17.700001f }, 1.000000f, 0.261799f ); 
    instance.registerEObj( "Dragonkiller_1", 2005545, 0, 4, { -14.150000f, 0.168036f, 19.500000f }, 1.000000f, -0.087266f ); 
    instance.registerEObj( "sgbg_a2fa_a1_bsid2", 2005847, 5865535, 4, { -5.185479f, 0.084680f, 0.234906f }, 1.000000f, 0.000000f ); 
    // States -> collision_on (id: 1) collision_off (id: 2) 
    instance.registerEObj( "sgbg_a2fa_a1_bare1", 2005958, 5898723, 4, { -3.398252f, 0.016719f, -0.449336f }, 1.000000f, 0.000000f ); 
    // States -> stage_ba_hide (id: 1) stage_ba_show (id: 2) stage_ba_anim1 (id: 3) stage_ba_anim2 (id: 4) 
    instance.registerEObj( "unknown_0", 2005965, 5874950, 4, { -14.475140f, 0.010675f, 5.614964f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Entrance", 2000182, 5778232, 5, { -26.139870f, 0.000001f, -0.197510f }, 1.000000f, 0.000000f ); 
    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.registerEObj( "Exit", 2000139, 0, 4, { -4.281307f, 0.000000f, 0.000000f }, 1.000000f, 0.000000f ); 

  }

  void onUpdate( InstanceContent& instance, uint64_t tickCount ) override
  {
    //===========THE_MOVIE start============
    while( instance.getCustomVar( 0 ) < instance.getCustomVar( 1 ) )
    {
      auto p = instance.getPlayer( instance.getCustomVar( 2 + instance.getCustomVar( 0 ) ) );

      if( p && p->getQuestSeq( FFXIV_THE_MOVIE_INSTANCE_QUEST_ID ) == FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED )
      {
        p->sendUrgent( "skipping dungeon..." );
        p->eventStart( p->getId(), instance.getDirectorId(), Event::EventHandler::EnterTerritory, 1, p->getZoneId() );
        p->playScene( instance.getDirectorId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, 0, 1, SCENE_LIST[ 0 ],
          std::bind( &ScriptObject::the_movie_callback, this, std::placeholders::_1, std::placeholders::_2, FFXIV_THE_MOVIE_INSTANCE_QUEST_ID, FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET, SCENE_LIST, 0 ) );
      }

      instance.setCustomVar( 0, instance.getCustomVar( 0 ) + 1 );
    }
    //===========THE_MOVIE end============

  }

  void onEnterTerritory( InstanceContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {
    //===========THE_MOVIE start============
    instance.setCustomVar( 2 + instance.getCustomVar( 1 ), player.getId() );
    instance.setCustomVar( 1, instance.getCustomVar( 1 ) + 1 );
    //===========THE_MOVIE end============

  }

};

EXPOSE_SCRIPT( TheLimitlessBlueHard );