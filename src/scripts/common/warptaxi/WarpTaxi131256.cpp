#include <ScriptObject.h>
#include <Actor/Player.h>

#include <Network/GamePacket.h>
#include <Network/PacketDef/Zone/ServerZoneDef.h>

using namespace Sapphire;
using namespace Sapphire::Network::Packets;
using namespace Sapphire::Network::Packets::Server;

class WarpTaxi131256 : public Sapphire::ScriptAPI::EventScript
{
public:
  WarpTaxi131256() :
    Sapphire::ScriptAPI::EventScript( 131256 )
  {
  }

  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    player.eventFinish( getId(), 1 );
    player.setPosAndNotifyClient( 676, 60, 465, 0 );
  }
};

EXPOSE_SCRIPT( WarpTaxi131256 );