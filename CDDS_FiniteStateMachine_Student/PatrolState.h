#pragma once
#include "State.h"
#include "Vector2D.h"
#include "GameDefs.h"
#include "GameObject.h"
#include <vector>

class PatrolState : public State
{ 
public:
	PatrolState(){}
	~PatrolState(){}
	void onUpdate(GameObject* object, float dt)
	{
		Vector2D target = m_waypoints[m_currentWaypoint];
		Vector2D pos = object->getPosition(); 
		Vector2D dist = { target.x - pos.x, target.y - pos.y };
		float mag = sqrt(dist.x * dist.x + dist.y * dist.y);
		if (mag < 50) 
		{ 
			m_currentWaypoint++; 
			if (m_currentWaypoint >= m_waypoints.size()) 
				m_currentWaypoint = 0; 
		} 
		Vector2D direction = { dist.x / mag, dist.y / mag }; 
		float speed = object->getSpeed(); 
		object->setPosition({ pos.x + (direction.x * speed * dt), pos.y + (direction.y * speed * dt) });
		float rot = atan2f(direction.y, direction.x); 
		object->setRotation(rot);
	}
	void addWaypoint(Vector2D pos) 
	{
		m_waypoints.push_back(pos);
	}
private:
	std::vector<Vector2D> m_waypoints;
	int m_currentWaypoint = 0;
};