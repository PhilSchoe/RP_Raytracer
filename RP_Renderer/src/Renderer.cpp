#include "glm/geometric.hpp"
#include "Renderer.h"
#include "Camera.h"
#include "Sphere.h"
#include "RP_Utility.h"


Renderer::Renderer()
{}


Renderer::~Renderer()
{}


void Renderer::renderImage( int width, int height, int samplesPerPixel, float* outputImage )
{
    // Camera

    Camera camera( width, height );

    // World

    HitableList world;
    this->createWorld( &world );

    // Image

    const int size   = width * height * 3;
    const int stride = width * 3;

    // Render

    for( int j = height - 1; j >= 0; j-- )
    {
        for( int i = 0; i < stride / 3; i++ )
        {
            glm::vec3 pixelColor( 0.0f );
            for( int s = 0; s < samplesPerPixel; s++ )
            {
                float u = ( i + randomFloat() ) / float( width  - 1 );
                float v = ( j + randomFloat() ) / float( height - 1 );

                Ray ray     = camera.getRay( u, v );
                pixelColor += color( ray, world );
            }
            pixelColor /= samplesPerPixel;

            int index = i * 3 + j * stride;

            outputImage[index]     = pixelColor.r;
            outputImage[index + 1] = pixelColor.g;
            outputImage[index + 2] = pixelColor.b;
        }
    }
}


glm::vec3 Renderer::color( const Ray& ray, const Hitable& world )
{
    HitRecord record;
    if( world.hit( ray, 0.0f, RP_INFINITY, record ) )
    {
        // Ray hit something in the world
        return 0.5f * ( record.normal + glm::vec3(1.0f) );
    }

    // Ray does not hit anything (background)
    glm::vec3 unitDirection = glm::normalize( ray.getDirection() );
    float t = 0.5f * ( unitDirection.y + 1.0f );

    return ( 1.0f - t ) * glm::vec3( 1.0f ) + t * glm::vec3( 0.5f, 0.7f, 1.0f );
}


void Renderer::createWorld( HitableList* world )
{
    world->add( std::make_shared<Sphere>( glm::vec3( 0.0f, 0.0f, -1.0f ), 0.5f ) );
    world->add( std::make_shared<Sphere>( glm::vec3( 0.0f, -100.5f, -1.0f ), 100.0f ) );
}