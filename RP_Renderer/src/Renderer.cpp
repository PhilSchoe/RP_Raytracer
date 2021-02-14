#include "glm/geometric.hpp"
#include "Renderer.h"


Renderer::Renderer()
{}


Renderer::~Renderer()
{}


void Renderer::renderImage( int width, int height, float* outputImage )
{
    glm::vec3 lowerLeftCorner( -2.0f, -1.0f, -1.0f );
    glm::vec3 horizontal( 4.0f, 0.0f, 0.0f );
    glm::vec3 vertical( 0.0f, 2.0f, 0.0f );
    glm::vec3 origin( 0.0f );

    const int size   = width * height * 3;
    const int stride = width * 3;

    for( int j = height - 1; j >= 0; j-- )
    {
        for( int i = 0; i < stride; i += 3 )
        {
            float u = float( i / 3.0f ) / float( width );
            float v = float( j ) / float( height );

            Ray ray( origin, lowerLeftCorner + u * horizontal + v * vertical );
            glm::vec3 col = color( ray );
            
            int index = i + j * stride;

            outputImage[index]     = col.r;
            outputImage[index + 1] = col.g;
            outputImage[index + 2] = col.b;
        }
    }
}


glm::vec3 Renderer::color( const Ray& ray )
{
    if( hitSphere( glm::vec3( 0.0f, 0.0f, -1.0f ), 0.5f, ray ) )
    {
        return glm::vec3( 1.0f, 0.0f, 0.0f );
    }

    glm::vec3 unitDirection = glm::normalize( ray.getDirection() );
    float t = 0.5f * ( unitDirection.y + 1.0f );

    return ( 1.0f - t ) * glm::vec3( 1.0f ) + t * glm::vec3( 0.5f, 0.7f, 1.0f );
}


bool Renderer::hitSphere( const glm::vec3& sphereCenter, const float sphereRadius, const Ray& ray )
{
    // Basic sphere intersection: Calculate the discriminant and check if larger 0 --> at least one intersection
    glm::vec3 centerToOrigin = ray.getOrigin() - sphereCenter;

    float a = glm::dot( ray.getDirection(), ray.getDirection() );
    float b = 2.0f * glm::dot( centerToOrigin, ray.getDirection() );
    float c = glm::dot( centerToOrigin, centerToOrigin ) - sphereRadius * sphereRadius;

    float discriminant = b * b - 4.0f * a * c;
    
    return (discriminant > 0.0f);
}