#ifndef SCENE_PLAY_H
#define SCENE_PLAY_H

#include "Scene.h"
#include <map>
#include <memory>

#include "EntityManager.h"

class Scene_Play : public Scene
{
	struct PlayerConfig
	{
		float X, Y, CX, CY, SPPED, MAXSPPED, JUMP, GRAVITY;
		std::string WEAPON;
	};

protected:

	std::shared_ptr<Entity>		 m_player;
	std::string					 m_levelPath;
	PlayerConfig				 m_playerConfig;
	bool						 m_drawTextures = true;
	bool						 m_drawCollision = false;
	bool						 m_drawGrid = false;
	const Vec2					 m_girdSize = { 64, 64 };
	sf::Text					 m_gridText;

	void init(const std::string& levelPath);

	void loadLevel(const std::string& filename);
};

#endif // !SCENE_PLAY_H

