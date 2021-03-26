#include "glm/geometric.hpp"

#include "MetalMaterial.h"
#include "Hitable.h"


MetalMaterial::MetalMaterial( const glm::vec3& albedo ) :
    m_Albedo( albedo )
{}


MetalMaterial::~MetalMaterial()
{}


bool MetalMaterial::scatter( const Ray& rayIn, const HitRecord& record, glm::vec3& attenuation, Ray& scattered ) const
{
    glm::vec3 reflected = glm::reflect( glm::normalize(rayIn.getDirection()), record.normal );

    scattered   = Ray( record.hitPosition, reflected );
    attenuation = m_Albedo;

    return ( glm::dot(scattered.getDirection(), record.normal) > 0 );
}