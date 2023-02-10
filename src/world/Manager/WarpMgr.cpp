#include <Service.h>

#include "WarpMgr.h"
#include "TerritoryMgr.h"
#include "Territory/Territory.h"
#include "Actor/Player.h"
#include <Service.h>

using namespace Sapphire::World::Manager;
using namespace Sapphire::World;
using namespace Sapphire;
using namespace Sapphire::Common;

void WarpMgr::requestMoveTerritory( Entity::Player& player, Common::WarpType warpType,
                                    uint32_t targetTerritoryId, Common::FFXIVARR_POSITION3 targetPos, float targetRot )
{
  player.forceZoneing( Common::Service< World::Manager::TerritoryMgr >::ref().getTerritoryByGuId( targetTerritoryId )->getTerritoryTypeId(), targetPos.x, targetPos.y, targetPos.z, targetRot, false );
}