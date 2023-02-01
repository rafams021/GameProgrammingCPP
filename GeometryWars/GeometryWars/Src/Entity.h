#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <string>
#include "Components.h"

class Entity
{
public:
	
	// component pointers
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CShape> cShape;
	std::shared_ptr<CCollision> cCollision;
	std::shared_ptr<CInput> cInput;
	std::shared_ptr<CScore> cScore;
	std::shared_ptr<CLifespan> cLifespan;

	// private member access functions
	bool isActive() const;
	const std::string& tag() const;
	const size_t id() const;
	void destroy();

private:
	friend class EntityManager;

	bool m_active = true;
	size_t m_id = 0;
	std::string m_tag = "default";

	// constructor and destructor
	Entity(const size_t id, const std::string& tag);
};


#endif // !ENTITY_H

