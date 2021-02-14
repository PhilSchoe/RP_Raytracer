#pragma once
#include <vector>

#include "glm/vec3.hpp"
#include "Ray.h"


class Renderer
{
public:
	Renderer();
	~Renderer();

	void renderImage( int width, int height, float* outputImage );

private:
	glm::vec3 color( const Ray& ray );
	bool      hitSphere( const glm::vec3& sphereCenter, float sphereRadius, const Ray& ray );
};