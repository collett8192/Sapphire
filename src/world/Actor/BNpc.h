#ifndef _BNPC_H_
#define _BNPC_H_

#include <Common.h>

#include "Forwards.h"
#include "Chara.h"
#include "Npc.h"
#include <set>
#include <map>
#include <queue>

namespace Sapphire::Entity
{

  typedef struct
  {
    uint32_t m_hateAmount;
    ActorPtr m_pActor;
  } HateListEntry;

  enum class BNpcState
  {
    Idle,
    Combat,
    Retreat,
    JustDied,
    Dead,
  };

  /*!
  \class BNpc
  \brief Base class for all BNpcs

  */
  class BNpc : public Npc
  {

  public:
    BNpc( FrameworkPtr pFw );
    BNpc( uint32_t id, BNpcTemplatePtr pTemplate, float posX, float posY, float posZ, float rot,
          uint8_t level, uint32_t maxHp, ZonePtr pZone,FrameworkPtr pFw );

    virtual ~BNpc() override;

    void spawn( PlayerPtr pTarget ) override;

    uint16_t getModelChara() const;
    uint8_t getLevel() const override;

    uint32_t getBNpcBaseId() const;
    uint32_t getBNpcNameId() const;

    uint8_t getEnemyType() const;

    uint64_t getWeaponMain() const;
    uint64_t getWeaponSub() const;

    uint8_t getAggressionMode() const;

    // return true if it reached the position
    bool moveTo( const Common::FFXIVARR_POSITION3& pos );

    void sendPositionUpdate();

    BNpcState getState() const;
    void setState( BNpcState state );

    void hateListClear();
    ActorPtr hateListGetHighest();
    void hateListAdd( ActorPtr pActor, int32_t hateAmount );
    void hateListUpdate( ActorPtr pActor, int32_t hateAmount );
    void hateListRemove( ActorPtr pActor );
    bool hateListHasActor( ActorPtr pActor );

    void aggro( ActorPtr pActor );
    void deaggro( ActorPtr pActor );

    void update( int64_t currTime ) override;

  private:
    uint32_t m_bNpcBaseId;
    uint32_t m_bNpcNameId;
    uint64_t m_weaponMain;
    uint64_t m_weaponSub;
    uint8_t m_aggressionMode;
    uint8_t m_enemyType;
    uint8_t m_onlineStatus;
    uint8_t m_pose;
    uint16_t m_modelChara;
    uint32_t m_displayFlags;
    uint8_t m_level;

    Common::FFXIVARR_POSITION3 m_spawnPos;

    BNpcState m_state;
    std::set< std::shared_ptr< HateListEntry > > m_hateList;

  };

}
#endif
