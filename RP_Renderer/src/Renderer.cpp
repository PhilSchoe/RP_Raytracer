#include "glm/geometric.hpp"
#include "Renderer.h"
#include "Sphere.h"
#include "RP_Constants.h"


Renderer::Renderer()
{}


Renderer::~Renderer()
{}


void Renderer::renderImage( int width, int height, float* outputImage )
{
    // Camera

    glm::vec3 lowerLeftCorner( -2.0f, -1.0f, -1.0f );
    glm::vec3 horizontal( 4.0f, 0.0f, 0.0f );
    glm::vec3 vertical( 0.0f, 2.0f, 0.0f );
    glm::vec3 origin( 0.0f );

    // World
    HitableList world;
    this->createWorld( &world );

    // Image

    const int size   = width * height * 3;
    const int stride = width * 3;

    // Render

    for( int j = height - 1; j >= 0; j-- )
    {
        for( int i = 0; i < stride; i += 3 )
        {
            float u = float( i / 3.0f ) / float( width );
            float v = float( j ) / float( height );

            Ray ray( origin, lowerLeftCorner + u * horizontal + v * vertical );
            glm::vec3 col = color( ray, world );
            
            int index = i + j * stride;

            outputImage[index]     = col.r;
            outputImage[index + 1] = col.g;
            outputImage[index + 2] = col.b;
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