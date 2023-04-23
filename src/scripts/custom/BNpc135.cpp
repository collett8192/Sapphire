#include <ScriptObject.h>
#include <Actor/BNpc.h>
#include <Actor/Player.h>
#include <Util/UtilMath.h>
#include <Manager/ActionMgr.h>
#include <Service.h>

using namespace Sapphire;
using namespace Sapphire::Common;
using namespace Sapphire::Entity;
using namespace World::Manager;

class BNpc135 :
  public Sapphire::ScriptAPI::BattleNpcScript
{
public:
  BNpc135() :
    Sapphire::ScriptAPI::BattleNpcScript( 135 )
  { }
  /*
  void onDeath( Entity::BNpc& bnpc )
  {
    if( auto player = bnpc.hateListGetHighest()->getAsPlayer() )
    {
      player->addCurrency( CurrencyType::Gil, 10000, true );
    }
  }

  void onUpdate( BNpc& bnpc, uint64_t tickCount ) override
  {
    if( bnpc.getState() == BNpcState::Combat )
    {
      if( tickCount - bnpc.getCustomVar( 1 ) > 8000 )
      {
        auto pHatedActor = bnpc.hateListGetHighest();
        if( pHatedActor && pHatedActor->isAlive() )
        {
          auto distance = Util::distance( bnpc.getPos().x, bnpc.getPos().y, bnpc.getPos().z, pHatedActor->getPos().x, pHatedActor->getPos().y, pHatedActor->getPos().z );
          if( distance < ( bnpc.getRadius() + pHatedActor->getRadius() + 10.f ) )
          {
            bnpc.stopMoving();
            bnpc.setCustomVar( 1, tickCount );
            Service< ActionMgr >::ref().handleTargetedAction( bnpc, 144, nullptr, pHatedActor->getId(), 0 );
            return;
          }
        }
      }

      if( tickCount - bnpc.getCustomVar( 1 ) > 4500 )
      {
        bnpc.doDefaultBNpcUpdate( tickCount );
      }
    }
    else
    {
      bnpc.doDefaultBNpcUpdate( tickCount );
    }
  }
  */
};

EXPOSE_SCRIPT( BNpc135 );