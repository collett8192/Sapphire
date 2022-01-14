#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 66897;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 1;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 255;
const uint32_t SCENE_LIST[] = { 525, 0 };
//===========THE_MOVIE end============

class TheWhorleaterHard :
  public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  TheWhorleaterHard() :
    Sapphire::ScriptAPI::InstanceContentScript( 20017 )
  { }

  void onInit( InstanceContent& instance ) override
  {
    instance.registerEObj( "unknown_0", 2003496, 4600311, 4, { 4.240293f, 0.025694f, 2.306607f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_1", 2003497, 4600310, 4, { 0.072974f, 0.025694f, 3.729535f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Elementalconverter", 2003498, 4600308, 4, { -0.068011f, 0.025694f, 18.829760f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_2", 2003499, 4600477, 4, { -0.427824f, 0.025694f, -1.602400f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_3", 2003503, 4536477, 4, { -4.721506f, 0.025694f, -0.558033f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Entrance", 2000182, 4600244, 5, { 2.559847f, 0.025694f, 16.605810f }, 1.000000f, 0.000000f ); 
    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.registerEObj( "Exit", 2000139, 0, 4, { 0.000000f, 0.025694f, -15.000000f }, 1.000000f, 0.000000f ); 

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
  //===========THE_MOVIE start============
  void onDebug( Entity::Player& player, uint32_t param ) override
  {
    auto instance = player.getCurrentInstance();
    if( !instance || instance->getDirectorId() != getId() )
      return;

    player.eventStart( player.getId(), instance->getDirectorId(), Event::EventHandler::EnterTerritory, 1, player.getZoneId() );
    player.playScene( instance->getDirectorId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, 0, 1, param, nullptr );
  }
  //===========THE_MOVIE end============

};

EXPOSE_SCRIPT( TheWhorleaterHard );