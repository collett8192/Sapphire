#include "ForwardsZone.h"
#include "Territory/Zone.h"

namespace Sapphire::World::Territory::Housing
{
  class HousingInteriorTerritory : public Zone
  {
  public:
    HousingInteriorTerritory( uint64_t ident, uint16_t territoryTypeId,
                              uint32_t guId,
                              const std::string& internalName,
                              const std::string& contentName );

    virtual ~HousingInteriorTerritory();

    bool init() override;

    void onPlayerZoneIn( Entity::Player& player ) override;
    void onUpdate( uint32_t currTime ) override;

  private:
    uint64_t m_landIdent;
  };
}