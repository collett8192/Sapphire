#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 65620;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 4;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 5;
const uint32_t SCENE_LIST[] = { 642, 0 };
//===========THE_MOVIE end============

class AkhAfahAmphitheatreHard :
  public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  AkhAfahAmphitheatreHard() :
    Sapphire::ScriptAPI::InstanceContentScript( 20024 )
  { }

  void onInit( InstanceContent& instance ) override
  {
    instance.registerEObj( "unknown_0", 2004238, 4772738, 4, { -1.210436f, 0.000000f, -0.715586f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_r1fc_b0472", 2004239, 4797573, 4, { 1.181316f, -0.000000f, 1.563968f }, 1.000000f, 0.000000f ); 
    // States -> wind_def (id: 2) wind_def_anim (id: 3) wind_pop (id: 4) wind_pop_anim (id: 5) 
    instance.registerEObj( "sgvf_r1fc_b0471", 2004240, 4841629, 4, { 11.000000f, 0.000000f, -11.000000f }, 1.000000f, 0.793709f ); 
    // States -> magi_def (id: 2) magi_def_anim (id: 3) magi_pop (id: 4) magi_pop_anim (id: 5) 
    instance.registerEObj( "sgvf_r1fc_b0471_1", 2004349, 4841631, 4, { 12.811310f, -0.000000f, 9.376424f }, 1.000000f, 0.000000f ); 
    // States -> magi_def (id: 2) magi_def_anim (id: 3) magi_pop (id: 4) magi_pop_anim (id: 5) 
    instance.registerEObj( "sgvf_r1fc_b0471_2", 2004350, 4841632, 4, { -8.033875f, 0.000000f, 10.406790f }, 1.000000f, 0.000000f ); 
    // States -> magi_def (id: 2) magi_def_anim (id: 3) magi_pop (id: 4) magi_pop_anim (id: 5) 
    instance.registerEObj( "sgvf_r1fc_b0471_3", 2004351, 4841633, 4, { -8.319038f, -0.000001f, -10.997720f }, 1.000000f, 0.000000f ); 
    // States -> magi_def (id: 2) magi_def_anim (id: 3) magi_pop (id: 4) magi_pop_anim (id: 5) 
    instance.registerEObj( "Entrance", 2000182, 4738599, 5, { 9.717670f, 0.000000f, 14.522430f }, 1.000000f, 0.000000f ); 
    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.registerEObj( "Exit", 2000139, 0, 4, { 0.000000f, 0.000000f, -15.000000f }, 1.000000f, 0.000000f ); 

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

EXPOSE_SCRIPT( AkhAfahAmphitheatreHard );