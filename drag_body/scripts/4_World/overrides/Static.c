Object BBP_getObjectAtCrosshair(float distance = 5.0, float radius = 0, Object with = NULL)
{
	vector rayStart = GetGame().GetCurrentCameraPosition();
	vector rayEnd = rayStart + GetGame().GetCurrentCameraDirection() * distance;

	auto objs = BBP_GetObjectsAt2( rayStart, rayEnd, GetGame().GetPlayer(), radius, with );

	if ( objs.Count() > 0 )
	{
		return objs[ 0 ];
	}

	return NULL;
}

static set< Object > BBP_GetObjectsAt2( vector from, vector to, Object ignore = NULL, float radius = 0, Object with = NULL )
{
    vector contact_pos;
    vector contact_dir;
    int contact_component;

    set< Object > view = new set< Object >;

    DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, view, with, ignore, false, false, ObjIntersectView, radius );

    if ( view ) 
    {
        return view;
    }
    return NULL;
}

// BBP_BASE BBP_SNAPPING_OBJECT;
// BBP_BASE AUTO_BBP_SNAPPING_OBJECT;

// void BBP_SelectObject()
// {
// 	BBP_SNAPPING_OBJECT = BBP_BASE.Cast(SnappingWithOtherWall());	
// }

// Object SnappingWithOtherWall()
// {
// 	Object obj = BBP_getObjectAtCrosshair();
// 	if (obj && obj.IsInherited(BBP_BASE))
// 	{
// 		AUTO_BBP_SNAPPING_OBJECT = BBP_BASE.Cast(obj);
// 		return AUTO_BBP_SNAPPING_OBJECT;
// 	}
// 	else
// 	{
// 		AUTO_BBP_SNAPPING_OBJECT = null;
// 		return AUTO_BBP_SNAPPING_OBJECT;
// 	}
// }