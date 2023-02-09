#ifndef SAPPHIRE_PLAYERMGR_H
#define SAPPHIRE_PLAYERMGR_H

#include "ForwardsZone.h"

namespace Sapphire::World::Manager
{
class PlayerMgr
  {
  public:
    PlayerMgr() = default;

    void movePlayerToLandDestination( Sapphire::Entity::Player& player, uint32_t landId, uint16_t param = 0 );

    static void sendServerNotice( Sapphire::Entity::Player& player, const std::string& message );
    template< typename... Args >
    static void sendServerNotice( Sapphire::Entity::Player& player, const std::string& message, const Args&... args )
    {
      sendServerNotice( player, fmt::format( message, args... ) );
    }

    static void sendUrgent( Sapphire::Entity::Player& player, const std::string& message );
    template< typename... Args >
    static void sendUrgent( Sapphire::Entity::Player& player, const std::string& message, const Args&... args )
    {
      sendUrgent( player, fmt::format( message, args... ) );
    }

    static void sendDebug( Sapphire::Entity::Player& player, const std::string& message );

    template< typename... Args >
    static void sendDebug( Sapphire::Entity::Player& player, const std::string& message, const Args&... args )
    {
      sendDebug( player, fmt::format( message, args... ) );
    }

    static void sendLogMessage( Sapphire::Entity::Player& player, uint32_t messageId, uint32_t param2 = 0, uint32_t param3 = 0,
      uint32_t param4 = 0, uint32_t param5 = 0, uint32_t param6 = 0 );

  };
}

#endif // SAPPHIRE_PLAYERMGR_H