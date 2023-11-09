#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 68025;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 2;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 3;
const uint32_t SCENE_LIST[] = { 1570, 0 };
//===========THE_MOVIE end============

class ThePoolofTribute :
  public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  ThePoolofTribute() :
    Sapphire::ScriptAPI::InstanceContentScript( 20046 )
  { }

  void onInit( InstanceContent& instance ) override
  {
    instance.registerEObj( "Bladesshadow", 2008185, 6849163, 4, { -0.015320f, 0.206439f, -5.020264f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_0", 2008184, 6843593, 4, { -4.501404f, 0.200000f, 8.957031f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "Entrance", 2000182, 6847132, 5, { -3.489120f, 0.200000f, 16.024530f }, 1.000000f, 0.000000f ); 
    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.registerEObj( "Exit", 2000139, 0, 4, { 0.357571f, 0.200000f, -11.800290f }, 1.000000f, 0.000000f ); 

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

EXPOSE_SCRIPT( ThePoolofTribute );