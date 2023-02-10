#pragma once

#include <cstdint>
#include <string>
#include <ForwardsZone.h>
#include <Util/Util.h>
#include <unordered_map>

namespace Sapphire::World::Manager
{
  class WarpMgr
  {
  public:
    WarpMgr() = default;
    void requestMoveTerritory( Entity::Player& player, Common::WarpType warpType, uint32_t targetTerritoryId, Common::FFXIVARR_POSITION3 targetPos, float targetRot );
  };

}
