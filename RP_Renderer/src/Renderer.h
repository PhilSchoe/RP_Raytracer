#pragma once
#include <vector>

#include "glm/vec3.hpp"
#include "Ray.h"
#include "HitableList.h"


class Renderer
{
public:
	Renderer();
	~Renderer();

	void renderImage( int width, int height, int samplesPerPixel, float* outputImage );

private:
	glm::vec3 color( const Ray& ray, const Hitable& world, int depth );
	void      createWorld( HitableList* world );
};