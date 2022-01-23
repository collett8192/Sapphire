#include "PlayerMgr.h"

#include <Exd/ExdDataGenerated.h>

#include <Manager/TerritoryMgr.h>
#include <Territory/ZonePosition.h>
#include <Territory/Territory.h>

#include <Manager/HousingMgr.h>

#include <Actor/Player.h>
#include <Service.h>

using namespace Sapphire::World::Manager;

void Sapphire::World::Manager::PlayerMgr::movePlayerToLandDestination( Sapphire::Entity::Player& player, uint32_t landId, uint16_t param )
{
  // check if we have one in the db first
  auto& terriMgr = Common::Service< TerritoryMgr >::ref();

  Sapphire::TerritoryPtr destinationZone;

  auto terriPos = terriMgr.getTerritoryPosition( landId );
  if( terriPos )
  {
    // check if its a housing zone, zoning is different here
    if( terriMgr.isHousingTerritory( terriPos->getTargetZoneId() ) )
    {
      auto& housingMgr = Common::Service< HousingMgr >::ref();
      auto landSetId = housingMgr.toLandSetId( terriPos->getTargetZoneId(), param );

      auto housingZone = housingMgr.getHousingZoneByLandSetId( landSetId );

      if( !housingZone )
        return;

      destinationZone = housingZone;
    }
    else if( terriMgr.isInstanceContentTerritory( terriPos->getTargetZoneId() ) )
    {
      // todo: instance dungeon handling
      // will need to use setInstance so old pos gets set
      return;
    }
    else
    {
      // normal zones
      destinationZone = terriMgr.getZoneByTerritoryTypeId( terriPos->getTargetZoneId() );
    }
  }
  else
  {
    // todo: lookup land.exd and see if it's in there if its not in our db
    return;
  }

  if( !destinationZone )
  {
    player.sendDebug( "Unable to find applicable territory for Warp#{0}. "
                      "Check that it exists inside zonepositions table.",
                      landId );
    return;
  }

  player.setPos( terriPos->getTargetPosition() );
  player.setRot( terriPos->getTargetRotation() );

  terriMgr.movePlayer( destinationZone, player.getAsPlayer() );
}

void PlayerMgr::sendServerNotice( Sapphire::Entity::Player& player, const std::string& message ) //Purple Text
{
  player.sendNotice( message );
}

void PlayerMgr::sendUrgent( Sapphire::Entity::Player& player, const std::string& message ) //Red Text
{
  player.sendUrgent( message );
}

void PlayerMgr::sendDebug( Sapphire::Entity::Player& player, const std::string& message ) //Grey Text
{
  player.sendDebug( message );
}

void PlayerMgr::sendLogMessage( Sapphire::Entity::Player& player, uint32_t messageId, uint32_t param2, uint32_t param3,
  uint32_t param4, uint32_t param5, uint32_t param6 )
{
  player.sendLogMessage( messageId, param2, param3, param4, param5, param6 );
}