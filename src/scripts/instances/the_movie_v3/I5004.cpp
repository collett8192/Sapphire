#include <ScriptObject.h>
#include <Territory/InstanceContent.h>
#include <Actor/Player.h>

using namespace Sapphire;

const uint32_t FFXIV_THE_MOVIE_INSTANCE_QUEST_ID = 67894;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED = 1;
const uint8_t FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET = 2;
const uint32_t SCENE_LIST[] = { 1309, 0 };

class I5004 :
  public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  I5004() :
    Sapphire::ScriptAPI::InstanceContentScript( 5004 )
  {
  }
  
  void onInit( InstanceContent& instance ) override
  {
  }
  
  void onUpdate( InstanceContent& instance, uint64_t tickCount ) override
  {
    while( instance.getCustomVar( 0 ) < instance.getCustomVar( 1 ) )
    {
      auto p = instance.getPlayer( instance.getCustomVar( 2 + instance.getCustomVar( 0 ) ) );

      if( p && p->getQuestSeq( FFXIV_THE_MOVIE_INSTANCE_QUEST_ID ) == FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_REQUIRED )
      {
        p->sendUrgent( "skipping battle..." );
        p->eventStart( p->getId(), instance.getDirectorId(), Event::EventHandler::EnterTerritory, 1, p->getZoneId() );
        p->playScene( instance.getDirectorId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, 0, 1, SCENE_LIST[ 0 ],
          std::bind( &ScriptObject::the_movie_callback, this, std::placeholders::_1, std::placeholders::_2, FFXIV_THE_MOVIE_INSTANCE_QUEST_ID, FFXIV_THE_MOVIE_INSTANCE_QUEST_SEQ_TARGET, SCENE_LIST, 0 ) );
      }

      instance.setCustomVar( 0, instance.getCustomVar( 0 ) + 1 );
    }
  }

  void onEnterTerritory( InstanceContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
    uint16_t param2 ) override
  {
    instance.setCustomVar( 2 + instance.getCustomVar( 1 ), player.getId() );
    instance.setCustomVar( 1, instance.getCustomVar( 1 ) + 1 );
  }

  bool the_movie_on_content_skipped( Sapphire::Entity::Player& player ) override
  {
    player.enterPredefinedPrivateInstance( 636 );
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
  
};

EXPOSE_SCRIPT( I5004 );