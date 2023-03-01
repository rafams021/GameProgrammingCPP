#ifndef ENTITYMANAGEER_H
#define ENTITYMANAGER_H

#include "Entity.h"

#include <vector>
#include <map>

typedef std::vector<std::shared_ptr<Entity>> EntityVec;

class EntityManager
{
public:
	EntityManager();

	void update();

private:
	EntityVec							m_entities;				// all entities
	EntityVec							m_entitiesToAdd;		// entities to add next update
	std::map<std::string, EntityVec>	m_entityMap;			// map from entity tag to vectors
	size_t								m_totalEntities = 0;	// total entities created

	// helper function to avoid repeated code
	void removeDeadEntities(EntityVec& vec);
};

#endif // !ENTITYMANAGEER_H

