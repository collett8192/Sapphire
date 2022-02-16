#ifndef _EVENTHELPER_H
#define _EVENTHELPER_H

#include <cstdint>
#include <string>
#include "Actor/Player.h"

namespace Sapphire::World::Manager
{

  class EventMgr
  {
  public:
    EventMgr() = default;

    std::string getEventName( uint32_t eventId );

    uint32_t mapEventActorToRealActor( uint32_t eventActorId );

    World::Quest getPlayerQuestDataFromEventId( Entity::Player& player, uint32_t eventId );
    void playQuestScene( Entity::Player& player, uint32_t eventId, uint32_t scene, uint32_t flags,
      Event::EventHandler::QuestSceneReturnCallback eventReturnCallback = nullptr );
    void eventFinish( Entity::Player& player, uint32_t eventId, uint32_t freePlayer );
    void sendEventNotice( Entity::Player& player, uint32_t questId, int8_t noticeId, uint8_t numOfArgs, uint32_t var1, uint32_t var2 );
    void eventActionStart( Entity::Player& player, uint32_t eventId, uint32_t action, World::Action::ActionCallback finishCallback, World::Action::ActionCallback interruptCallback, uint64_t additional );
  };

}

#endif
