// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: FesPdy502_03209
// Quest Name: One Short Day on Emerald Avenue
// Quest ID: 68745
// Start NPC: 1027151
// End NPC: 1027151

using namespace Sapphire;

class FesPdy502 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1027151;
//    static constexpr auto Eobject0 = 2009706;
//    static constexpr auto Eventaction0 = 12;
//    static constexpr auto Item0 = 2002506;
//    static constexpr auto LocAction0 = 4280;
//    static constexpr auto LocAction1 = 621;
//    static constexpr auto LocAction2 = 5596;
//    static constexpr auto LocActor0 = 1024748;
//    static constexpr auto LocActor1 = 1026375;
//    static constexpr auto LocActor10 = 1019822;
//    static constexpr auto LocActor11 = 1010432;
//    static constexpr auto LocActor12 = 1021000;
//    static constexpr auto LocActor13 = 1021166;
//    static constexpr auto LocActor14 = 1020117;
//    static constexpr auto LocActor15 = 1007163;
//    static constexpr auto LocActor16 = 1007164;
//    static constexpr auto LocActor17 = 1025347;
//    static constexpr auto LocActor18 = 1025348;
//    static constexpr auto LocActor19 = 1025349;
//    static constexpr auto LocActor2 = 1012125;
//    static constexpr auto LocActor3 = 1012492;
//    static constexpr auto LocActor4 = 1003871;
//    static constexpr auto LocActor5 = 1005139;
//    static constexpr auto LocActor6 = 1020991;
//    static constexpr auto LocActor7 = 1027635;
//    static constexpr auto LocActor8 = 1027636;
//    static constexpr auto LocActor9 = 1017834;
//    static constexpr auto LocBgm0 = 102;
//    static constexpr auto LocBgm1 = 520;
//    static constexpr auto LocItem0 = 24590;
//    static constexpr auto LocPosActor0 = 7795982;
//    static constexpr auto LocSe0 = 189;
//    static constexpr auto LocSeAlpha = 169;
//    static constexpr auto QuestFlagClsalc011 = 66111;
//    static constexpr auto QuestFlagClsalc680 = 67975;
//    static constexpr auto QuestFlagClsgld011 = 66144;
//    static constexpr auto QuestFlagClsmin500 = 66182;
//    static constexpr auto QuestFlagClspgl011 = 66068;
//    static constexpr auto QuestFlagClspgl020 = 66069;
//    static constexpr auto QuestFlagFespdy201 = 67757;
//    static constexpr auto QuestFlagFespdy301 = 67936;
//    static constexpr auto QuestFlagFespdy401 = 68620;
//    static constexpr auto QuestFlagGaiuse615 = 65963;
//    static constexpr auto QuestFlagHeavna330 = 67167;
//    static constexpr auto QuestFlagManwil005 = 66086;
//    static constexpr auto QuestFlagManwil009 = 66088;
//    static constexpr auto QuestFlagStmbdr304 = 68693;
//    static constexpr auto QuestFlagSubcts108 = 65632;

  public:
    FesPdy502() : Sapphire::ScriptAPI::EventScript( 68745 ){}; 
    ~FesPdy502() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player );
        break;
      }
      case 255:
      {
        Scene00005( player );
        break;
      }
    }
  }


  private:
  //////////////////////////////////////////////////////////////////////
  // Available Scenes in this quest, not necessarly all are used
  void Scene00000( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param2 == 1 )
        Scene00001( player );
    };

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };

    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };

    player.playScene( getId(), 5, NONE, callback );
  }

};

EXPOSE_SCRIPT( FesPdy502 );
