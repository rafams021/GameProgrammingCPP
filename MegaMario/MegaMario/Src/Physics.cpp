#include "Physics.h"
#include "Components.h"

Vec2 Physics::GetOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
{
	// TODO: return the overlap rectangle size of the counding boxes of entity a and b

	return Vec2(0, 0);
}

Vec2 Physiscs::GetPreviousOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
{
	// TODO: return the previous overlapp rectangle size of the bounding boxes of entity a and b
	//		 previous overlao uses the entity;s previous position

	return Vec2(0, 0);
}