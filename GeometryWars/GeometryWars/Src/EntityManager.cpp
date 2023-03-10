#include "EntityManager.h"

EntityManager::EntityManager() {

}

void EntityManager::update() {
	// TODO: add entities from m_entitiesToAdd to the proper location(s)
	//		 - add them to the vector of all entities
	//		 - add them to the vector inside the map, with the tag as key

	// remove dead entities from the vector of all entities
	removeDeadEntities(m_entities);

	// remove dead entities from each vector in the entity mao
	// C++ 17 way of iterating through [key,value] pairs in mao
	for (auto& [tag, entityVec] : m_entityMap) {
		removeDeadEntities(entityVec);
	}
}

void EntityManager::removeDeadEntities(EntityVec& vec) {
	// TODO: Remove all dead entities from the input vector
	//		 this is called by the update() function
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag) {
	
	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));

	m_entitiesToAdd.push_back(entity);

	return entity;
}

const EntityVec& EntityManager::getEntities() {
	
	return m_entities;

}

const EntityVec& EntityManager::getEntities(const std::string& tag) {
	// TODO: this is incorrect, return the correct vetor form the map
	return m_entities;
}