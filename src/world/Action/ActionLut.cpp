#include <cassert>
#include "ActionLut.h"

using namespace Sapphire::World::Action;

bool ActionLut::validEntryExists( uint16_t actionId )
{
  auto it = m_actionLut.find( actionId );

  if( it == m_actionLut.end() )
    return false;

  const auto& entry = it->second;

  // if all of these fields are 0, it's not 'valid' due to parse error or no useful data
  return entry.damagePotency != 0 || entry.healPotency != 0 || entry.selfStatus != 0 ||
    entry.targetStatus != 0 || entry.bonusEffect != 0;
}

const ActionEntry& ActionLut::getEntry( uint16_t actionId )
{
  auto it = m_actionLut.find( actionId );

  assert( it != m_actionLut.end() );

  return it->second;
}

bool ActionLut::validStatusEffectExists( uint16_t statusId )
{
  auto it = m_statusEffectTable.find( statusId );

  if( it == m_statusEffectTable.end() )
    return false;

  const auto& entry = it->second;

  return entry.getType() != StatusEffectType::Invalid;
}

const StatusEffectEntry& ActionLut::getStatusEffectEntry( uint16_t statusId )
{
  auto it = m_statusEffectTable.find( statusId );

  assert( it != m_statusEffectTable.end() );

  return it->second;
}

Sapphire::World::Action::StatusEffectEntry::StatusEffectEntry( uint32_t type, int32_t v1, int32_t v2, int32_t v3, int32_t v4 )
{
  init( static_cast< StatusEffectType >( type ), v1, v2, v3, v4 );
}

void Sapphire::World::Action::StatusEffectEntry::init( StatusEffectType type, int32_t v1, int32_t v2, int32_t v3, int32_t v4 )
{
  effectType = static_cast< uint32_t >( type );
  effectValue1 = v1;
  effectValue2 = v2;
  effectValue3 = v3;
  effectValue4 = v4;
}

StatusEffectType Sapphire::World::Action::StatusEffectEntry::getType() const
{
  return static_cast< StatusEffectType >( effectType );
}

ActionTypeFilter Sapphire::World::Action::StatusEffectEntry::getActionTypeFilter() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::Dot:
    case StatusEffectType::Hot:
    case StatusEffectType::DamageMultiplier:
    case StatusEffectType::CritDHRateBonus:
    case StatusEffectType::DamageDealtTrigger:
    case StatusEffectType::DamageReceiveTrigger:
      return static_cast< ActionTypeFilter >( effectValue1 );
    default:
      return ActionTypeFilter::Unknown;
  }
}

int32_t StatusEffectEntry::getMPRestoreTick() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::MPRestore:
      return effectValue1 * 10;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getDotHotPotency() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::Dot:
    case StatusEffectType::Hot:
      return effectValue2;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getOutgoingDamageMultiplier() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::DamageMultiplier:
      return effectValue2;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getIncomingDamageMultiplier() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::DamageReceiveMultiplier:
      return effectValue2;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getOutgoingHealMultiplier() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::HealCastMultiplier:
      return effectValue2;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getIncomingHealMultiplier() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::HealReceiveMultiplier:
      return effectValue2;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getPotencyMultiplier() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::PotencyMultiplier:
      return effectValue4;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getGCDBasedMPRestorePercentage() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::MPRestorePerGCD:
      return effectValue1;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getRemainingCharges() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::AlwaysCombo:
    case StatusEffectType::InstantCast:
    case StatusEffectType::PotencyMultiplier:
      return effectValue1;
    default:
      return -1;
  }
}

void Sapphire::World::Action::StatusEffectEntry::setRemainingCharges( int32_t charges )
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::AlwaysCombo:
    case StatusEffectType::InstantCast:
    case StatusEffectType::PotencyMultiplier:
      effectValue1 = charges;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getRemainingShield() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::Shield:
      return effectValue1;
    default:
      return 0;
  }
}

void Sapphire::World::Action::StatusEffectEntry::setRemainingShield( int32_t shield )
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::Shield:
      effectValue1 = shield;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getHasteBonus() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::Haste:
      return effectValue1;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getBlockRateBonus() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::BlockParryRateBonus:
      return effectValue2;
    case StatusEffectType::DamageReceiveMultiplier:
      return effectValue3;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getParryRateBonus() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::BlockParryRateBonus:
      return effectValue3;
    case StatusEffectType::DamageReceiveMultiplier:
      return effectValue4;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getCritRateBonus() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::CritDHRateBonus:
      return effectValue2;
    default:
      return 0;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getDirectHitRateBonus() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::CritDHRateBonus:
      return effectValue3;
    default:
      return 0;
  }
}

StatusEffectTriggerResult Sapphire::World::Action::StatusEffectEntry::getTriggerResult() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::DamageDealtTrigger:
    case StatusEffectType::DamageReceiveTrigger:
      return static_cast< StatusEffectTriggerResult >( effectValue3 );
    default:
      return StatusEffectTriggerResult::None;
  }
}

int32_t Sapphire::World::Action::StatusEffectEntry::getTriggerValue() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::DamageDealtTrigger:
    case StatusEffectType::DamageReceiveTrigger:
      return effectValue2;
    default:
      return 0;
  }
}

ActionTypeFilter Sapphire::World::Action::StatusEffectEntry::getTriggerDamageType() const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::DamageDealtTrigger:
    case StatusEffectType::DamageReceiveTrigger:
      if( effectValue4 == 0 ) // data missing in lut, default to physical
        return ActionTypeFilter::Physical;
      else
        return static_cast< ActionTypeFilter >( effectValue4 );
    default:
      return  ActionTypeFilter::Unknown;
  }
}

bool Sapphire::World::Action::StatusEffectEntry::canApplyToAction( uint32_t actionId, uint8_t actionCategory ) const
{
  switch( static_cast< StatusEffectType >( effectType ) )
  {
    case StatusEffectType::AlwaysCombo:
    case StatusEffectType::InstantCast:
    case StatusEffectType::PotencyMultiplier:
    case StatusEffectType::MPRestorePerGCD:
      if ( effectValue2 != 0 )
      {
        if( actionId != effectValue2 && actionId != effectValue3 && actionId != effectValue4 )
          return false;
      }
      else if ( effectValue3 != 0 )
      {
        uint8_t cat1 = static_cast< uint8_t >( effectValue3 );
        uint8_t cat2 = static_cast< uint8_t >( effectValue3 >> 8 );
        uint8_t cat3 = static_cast< uint8_t >( effectValue3 >> 16 );
        uint8_t cat4 = static_cast< uint8_t >( effectValue3 >> 24 );
        bool passed = false;
        if( cat1 != 0 && actionCategory == cat1 )
          passed = true;
        else if ( cat2 != 0 && actionCategory == cat2 )
          passed = true;
        else if ( cat3 != 0 && actionCategory == cat3 )
          passed = true;
        else if ( cat4 != 0 && actionCategory == cat4 )
          passed = true;
        if( !passed )
          return false;
      }
      return true;
    default:
      return true;
  }
}
