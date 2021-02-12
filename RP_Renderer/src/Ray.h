#pragma once
#include "glm/vec3.hpp"


class Ray
{
public:
	Ray();
	Ray( const glm::vec3& origin, const glm::vec3& direction );
	~Ray();

	glm::vec3 getOrigin()                    const;
	glm::vec3 getDirection()                 const;
	glm::vec3 getPointAtParameter( float t ) const;


private:
	glm::vec3 m_Origin;
	glm::vec3 m_Direction;
};