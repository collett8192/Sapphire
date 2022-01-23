#include "EventHandler.h"

using namespace Sapphire::Event;

uint32_t SceneResult::getResult( uint32_t index ) const
{
  switch( index )
  {
    case 0:
      return param2;
    case 1:
      return param3;
    case 2:
      return param4;
    default:
      return 0;
  }
}