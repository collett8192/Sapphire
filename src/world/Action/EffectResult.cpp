#include "EffectResult.h"

#include <Util/Util.h>

#include "Actor/Chara.h"
#include "Actor/Player.h"

using namespace Sapphire;
using namespace Sapphire::World::Action;


EffectResult::EffectResult( Entity::CharaPtr target, Entity::CharaPtr source, uint64_t runAfter ) :
  m_target( std::move( target ) ),
  m_source( std::move( source ) ),
  m_delayMs( runAfter ),
  m_type( Common::ActionEffectType::Nothing ),
  m_value( 0 ),
  m_statusDuration( 0 ),
  m_param0( 0 ),
  m_param1( 0 ),
  m_param2( 0 ),
  m_flag( Common::ActionEffectResultFlag::None ),
  m_pPreBuiltStatusEffect( nullptr ),
  m_statusShouldReuse( true )
{

}

EffectResult::EffectResult( Entity::CharaPtr target, uint64_t delayMs ) :
  EffectResult::EffectResult( std::move( target ), nullptr, delayMs )
{
}

Entity::CharaPtr EffectResult::getSource() const
{
  return m_source;
}

Entity::CharaPtr EffectResult::getTarget() const
{
  return m_target;
}

uint32_t EffectResult::getValue() const
{
  return m_value;
}

Common::ActionEffectType Sapphire::World::Action::EffectResult::getType() const
{
  return m_type;
}

uint64_t EffectResult::getDelay()
{
  return m_delayMs;
}

void EffectResult::dodge( Common::ActionEffectResultFlag flag )
{
  m_flag = flag;

  m_type = Common::ActionEffectType::Miss;
}

void EffectResult::damage( uint32_t amount, Common::ActionHitSeverityType severity, uint8_t attackType, Common::ActionEffectResultFlag flag )
{
  m_param0 = static_cast< uint8_t >( severity );
  m_param1 = attackType;
  m_value = amount;
  m_flag = flag;

  m_type = Common::ActionEffectType::Damage;
}

void EffectResult::blockedDamage( uint32_t amount, uint16_t rate, uint8_t attackType, Common::ActionEffectResultFlag flag )
{
  m_value = amount;
  m_flag = flag;
  m_param1 = attackType;
  m_param2 = rate;

  m_type = Common::ActionEffectType::BlockedDamage;
}

void EffectResult::parriedDamage( uint32_t amount, uint16_t rate, uint8_t attackType, Common::ActionEffectResultFlag flag )
{
  m_value = amount;
  m_flag = flag;
  m_param1 = attackType;
  m_param2 = rate;

  m_type = Common::ActionEffectType::ParriedDamage;
}

void EffectResult::heal( uint32_t amount, Common::ActionHitSeverityType severity, Common::ActionEffectResultFlag flag )
{
  m_param1 = static_cast< uint8_t >( severity );
  m_value = amount;
  m_flag = flag;

  m_type = Common::ActionEffectType::Heal;
}

void EffectResult::restoreMP( uint32_t amount, Common::ActionEffectResultFlag flag )
{
  m_value = amount;
  m_flag = flag;

  m_type = Common::ActionEffectType::MpGain;
}

void EffectResult::startCombo( uint16_t actionId )
{
  m_value = actionId;
  m_flag = Common::ActionEffectResultFlag::EffectOnSource;

  m_type = Common::ActionEffectType::StartActionCombo;
}

void EffectResult::comboSucceed()
{
  // no EffectOnSource flag on this
  m_type = Common::ActionEffectType::ComboSucceed;
}

void EffectResult::applyStatusEffect( uint16_t statusId, uint32_t duration, uint16_t param, bool statusToSource, bool shouldReuse )
{
  m_value = statusId;
  m_statusDuration = duration;
  m_param2 = param;
  m_flag = statusToSource ? Common::ActionEffectResultFlag::EffectOnSource : Common::ActionEffectResultFlag::None;
  m_statusShouldReuse = shouldReuse;
  m_type = statusToSource ? Common::ActionEffectType::ApplyStatusEffectSource : Common::ActionEffectType::ApplyStatusEffectTarget;
}

void EffectResult::applyStatusEffect( StatusEffect::StatusEffectPtr pStatusEffect, bool statusToSource, bool shouldReuse )
{
  m_value = pStatusEffect->getId();
  m_param2 = pStatusEffect->getParam();
  m_pPreBuiltStatusEffect = std::move( pStatusEffect );
  m_flag = statusToSource ? Common::ActionEffectResultFlag::EffectOnSource : Common::ActionEffectResultFlag::None;
  m_statusShouldReuse = shouldReuse;
  m_type = statusToSource ? Common::ActionEffectType::ApplyStatusEffectSource : Common::ActionEffectType::ApplyStatusEffectTarget;
}

void EffectResult::statusNoEffect( uint16_t statusId )
{
  m_value = statusId;

  m_type = Common::ActionEffectType::StatusNoEffect;
}

void EffectResult::mount( uint16_t mountId )
{
  m_value = mountId;
  m_param0 = 1;

  m_type = Common::ActionEffectType::Mount;
}

void Sapphire::World::Action::EffectResult::provoke()
{
  m_type = Common::ActionEffectType::Provoke;
}

void Sapphire::World::Action::EffectResult::invulnerable( uint16_t status )
{
  m_value = status;

  m_type = Common::ActionEffectType::Invulnerable;
}

Common::EffectEntry EffectResult::buildEffectEntry() const
{
  Common::EffectEntry entry{};
  entry.effectType = m_type;
  if( m_value > 0x0000FFFF )
  {
    entry.value = static_cast< uint16_t >( m_value & 0x0000FFFF );
    entry.extendedValueHighestByte = static_cast< uint8_t >( m_value >> 16 );
    entry.flags = static_cast< uint8_t >( m_flag ) + static_cast< uint8_t >( Common::ActionEffectResultFlag::ExtendedValue );
  }
  else
  {
    entry.value = static_cast< uint16_t >( m_value );
    entry.flags = static_cast< uint8_t >( m_flag );
  }
  entry.param0 = m_param0;
  entry.param1 = m_param1;
  entry.param2 = static_cast< uint8_t >( m_param2 );

  return entry;
}

void EffectResult::execute()
{
  switch( m_type )
  {
    case Common::ActionEffectType::Damage:
    case Common::ActionEffectType::BlockedDamage:
    case Common::ActionEffectType::ParriedDamage:
    {
      m_target->takeDamage( m_value );
      break;
    }

    case Common::ActionEffectType::Heal:
    {
      m_target->heal( m_value );
      break;
    }

    case Common::ActionEffectType::MpGain:
    {
      m_target->restoreMP( m_value );
      break;
    }

    case Common::ActionEffectType::ApplyStatusEffectTarget:
    case Common::ActionEffectType::ApplyStatusEffectSource:
    {
      auto applyTarget = m_type == Common::ActionEffectType::ApplyStatusEffectTarget ? m_target : m_source;
      //refreshing old buff
      for( auto const& entry : applyTarget->getStatusEffectMap() )
      {
        auto statusEffect = entry.second;
        if( statusEffect->getId() == m_value && m_statusShouldReuse )
        {
          if( m_pPreBuiltStatusEffect )
          {
            statusEffect->refresh( m_pPreBuiltStatusEffect->getEffectEntry() );
          }
          else
          {
            statusEffect->refresh( m_statusDuration );
          }
          applyTarget->sendStatusEffectUpdate();
          return;
        }
      }

      if( m_pPreBuiltStatusEffect )
      {
        applyTarget->addStatusEffect( m_pPreBuiltStatusEffect );
      }
      else
        applyTarget->addStatusEffectById( m_value, m_statusDuration, *m_source, m_param2 );

      break;
    }

    case Common::ActionEffectType::Mount:
    {
      auto pPlayer = m_target->getAsPlayer();
      pPlayer->mount( m_value );
      break;
    }

    default:
      break;
  }
}