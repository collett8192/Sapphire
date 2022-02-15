#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;
//===========THE_MOVIE start============
#include <Actor/Player.h>

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 65879;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 4;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 5;
const uint32_t SCENE_LIST[] = { 87, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//===========THE_MOVIE end============

class TheBowlofEmbers :
  public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  TheBowlofEmbers() :
    Sapphire::ScriptAPI::InstanceContentScript( 20001 )
  { }

  void onInit( InstanceContent& instance ) override
  {
    instance.registerEObj( "Entrance", 2000182, 4177874, 5, { -16.000000f, 0.000000f, 0.000000f }, 1.000000f, 0.000000f ); 
    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.registerEObj( "Exit", 2000139, 0, 4, { 16.000000f, 0.000000f, 0.000000f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_0", 2007452, 0, 4, { 0.000000f, 0.000000f, 0.000000f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "BladeofLight", 2007454, 0, 4, { 0.000000f, 0.000000f, 11.300000f }, 0.991760f, 0.000048f ); 

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
  bool the_movie_on_content_skipped( Sapphire::Entity::Player& player ) override
  {
    player.forceZoneing( 145, -371.3f, -57.0f, 142.2f, 0, false );
    return true;
  }
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

EXPOSE_SCRIPT( TheBowlofEmbers );