#include "glm/geometric.hpp"
#include "glm/gtx/norm.hpp"
#include "Sphere.h"


Sphere::Sphere() :
    m_Center( glm::vec3(0.0f) ),
    m_Radius( 0.0f )
{}


Sphere::Sphere( const glm::vec3& center, float radius, std::shared_ptr<Material> p_material ) :
    m_Center( center ),
    m_Radius( radius ),
    m_p_Material( p_material )
{}


Sphere::~Sphere()
{}


bool Sphere::hit( const Ray& ray, float tMin, float tMax, HitRecord& record ) const
{
    // Basic sphere intersection: 
    // Calculate the discriminant. If larger 0, calculate the two solutions. Check if one is in the interval tMin < solution < tMax.
    // If yes, calculate the hit position and the normal.
    // Store solution, hit position and normal in hit record.

    // Discriminant < 0 --> No intersection.
    // Discriminant = 0 --> One solution.
    // Discriminant > 0 --> Two solutions

    glm::vec3 centerToOrigin = ray.getOrigin() - m_Center;

    float a      = glm::length2( ray.getDirection() );
    float half_b = glm::dot( centerToOrigin, ray.getDirection() );
    float c      = glm::length2( centerToOrigin ) - m_Radius * m_Radius;

    float discriminant = half_b * half_b - a * c;
    if( discriminant > 0.0f )
    {
        float sqrtDiscriminant = sqrt( discriminant );

        float tempSolution = ( -half_b - sqrtDiscriminant ) / a;
        if( tempSolution < tMax && tempSolution > tMin )
        {
            this->storeHitRecord( tempSolution, ray, record );
            
            return true;
        }
        
        tempSolution = ( -half_b + sqrtDiscriminant ) / a;
        if( tempSolution < tMax && tempSolution > tMin )
        {
            this->storeHitRecord( tempSolution, ray, record );

            return true;
        }
    }

    return false;
}


void Sphere::storeHitRecord( const float t, const Ray& ray, HitRecord& record ) const
{
    record.t           = t;
    record.hitPosition = ray.getPointAtParameter( record.t );

    glm::vec3 outwardNormal = ( record.hitPosition - m_Center ) / m_Radius;
    record.setFaceNormal( ray, outwardNormal );

    record.p_material = this->m_p_Material;
}