#pragma once
#include "Ray.h"


class Camera
{
public:
	Camera( int resolutionX, int resolutionY );
	~Camera();

	Ray getRay( float u, float v ) const;


private:
	glm::vec3 m_Origin;
	glm::vec3 m_LowerLeftCorner;
	glm::vec3 m_Horizontal;
	glm::vec3 m_Vertical;
};