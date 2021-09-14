using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    public abstract class ActiveEventObject
    {
        public static ActiveEventObject CreateActiveObjectByName(string name)
        {
            if (name.StartsWith("ACTOR"))
            {
                return new ActiveActor(name);
            }
            else if (name.StartsWith("EOBJECT"))
            {
                return new ActiveEObject(name);
            }
            else if (name.StartsWith("ENEMY"))
            {
                return new ActiveEnemy(name);
            }
            else if (name.StartsWith("EVENTRANGE"))
            {
                return new ActiveRange(name);
            }
            else if (name.StartsWith("BASE_ID_TERRITORY"))
            {
                return new ActiveTerritory(name);
            }
            else if (name.StartsWith("AETHERYTE"))
            {
                return new ActiveEObject(name);
            }

            throw new Exception($"[ActiveEventObject]Unknown object name: {name}");
        }
        public abstract ObjectType Type { get; }
        public string Name { get; private set; }
        public abstract bool CanHaveIdentity(string id);
        public abstract bool CanExistWithoutScene { get; }
        public abstract bool CanAssignSceneGroup(Sequence.SceneGroup group);
        public virtual bool IsPrefferedGroup(Sequence.SceneGroup group) { return false; }
        public ActiveEventObject(string name)
        {
            this.Name = name;
        }

        public enum ObjectType
        {
            Unknown = 0,
            Actor = 1,
            EObject = 2,
            Enemy = 3,
            Range = 4,
            Player = 5,
            Territory = 6,
        }

        public override string ToString()
        {
            return $"{Name}";
        }
    }

    public class ActiveActor : ActiveEventObject
    {
        public ActiveActor(string name) : base(name)
        {
        }

        public override ObjectType Type => ObjectType.Actor;

        public override bool CanExistWithoutScene => false;

        public override bool CanAssignSceneGroup(Sequence.SceneGroup group)
        {
            return true;
        }

        public override bool CanHaveIdentity(string id)
        {
            return true;
        }
    }

    public class ActiveEObject : ActiveEventObject
    {
        public ActiveEObject(string name) : base(name)
        {
        }

        public override ObjectType Type => ObjectType.EObject;

        public override bool CanExistWithoutScene => false;

        public override bool CanAssignSceneGroup(Sequence.SceneGroup group)
        {
            foreach (var s in group.SceneList)
            {
                if ((s.Element & LuaScene.SceneElement.TargetCanMove) > 0 && s.Identity != "unknown" && !s.Identity.StartsWith("dummy"))
                {
                    return false;
                }
                if ((s.Element & LuaScene.SceneElement.Dismount) > 0)
                {
                    return false;
                }
            }
            return true;
        }

        public override bool IsPrefferedGroup(Sequence.SceneGroup group)
        {
            if (!CanHaveIdentity(group.Identity))
                return false;
            if (group.SceneList.Count == 1 && (group.SceneList[0].Element & LuaScene.SceneElement.PopBNpc) > 0)
            {
                return true;
            }
            if (group.SceneList.Count == 1 && group.SceneList[0].Element == LuaScene.SceneElement.None)
            {
                return true;
            }
            if (group.SceneList.Count == 1 && (group.SceneList[0].Element & LuaScene.SceneElement.QuestGimmickReaction) > 0)
            {
                return true;
            }
            if (group.SceneList.Count == 1 && (group.SceneList[0].Element & LuaScene.SceneElement.SystemTalk) > 0)
            {
                return true;
            }
            return base.IsPrefferedGroup(group);
        }

        public override bool CanHaveIdentity(string id)
        {
            return id == "unknown" || id.StartsWith("dummy");
        }
    }

    public class ActiveEnemy : ActiveEventObject
    {
        public ActiveEnemy(string name) : base(name)
        {
        }

        public override ObjectType Type => ObjectType.Enemy;

        public override bool CanExistWithoutScene => true;

        public override bool CanAssignSceneGroup(Sequence.SceneGroup group)
        {
            if (!CanHaveIdentity(group.Identity))
                return false;
            if (group.SceneList.Count == 1 && group.SceneList[0].Element == LuaScene.SceneElement.None)
                return true;
            if (group.SceneList.Count == 1 && (group.SceneList[0].Element & ~(LuaScene.SceneElement.Message | LuaScene.SceneElement.PopBNpc)) == LuaScene.SceneElement.None)
                return true;
            return false;
        }
        
        public override bool CanHaveIdentity(string id)
        {
            return id == "unknown" || id.StartsWith("dummy");
        }

        public override bool IsPrefferedGroup(Sequence.SceneGroup group)
        {
            return false;
        }
    }

    public class ActiveRange : ActiveEventObject
    {
        public ActiveRange(string name) : base(name)
        {
        }

        public override ObjectType Type => ObjectType.Range;

        public override bool CanExistWithoutScene => false;

        public override bool CanAssignSceneGroup(Sequence.SceneGroup group)
        {
            foreach (var s in group.SceneList)
            {
                if ((s.Element & LuaScene.SceneElement.TargetCanMove) > 0 && s.Identity != "unknown")
                {
                    return false;
                }
            }
            return true;
        }

        public override bool CanHaveIdentity(string id)
        {
            return true;
        }

        public override bool IsPrefferedGroup(Sequence.SceneGroup group)
        {
            if (group.SceneList.Count == 1 && (group.SceneList[0].Element & LuaScene.SceneElement.PopBNpc) > 0)
            {
                return true;
            }
            if (group.SceneList.Count == 1 && (group.SceneList[0].Element & LuaScene.SceneElement.Dismount) > 0)
            {
                return true;
            }
            if (group.SceneList.Count == 1 && (group.SceneList[0].Element & LuaScene.SceneElement.QuestGimmickReaction) > 0)
            {
                return true;
            }
            return base.IsPrefferedGroup(group);
        }
    }

    public class ActiveTerritory : ActiveEventObject
    {
        public ActiveTerritory(string name) : base(name)
        {
        }

        public override ObjectType Type => ObjectType.Territory;

        public override bool CanExistWithoutScene => false;

        public override bool CanAssignSceneGroup(Sequence.SceneGroup group)
        {
            foreach (var s in group.SceneList)
            {
                if ((s.Element & LuaScene.SceneElement.TargetCanMove) > 0 && s.Identity != "unknown" && !s.Identity.StartsWith("dummy"))
                {
                    return false;
                }
            }
            return true;
        }

        public override bool CanHaveIdentity(string id)
        {
            return id == "unknown" || id.StartsWith("dummy");
        }
    }
}
