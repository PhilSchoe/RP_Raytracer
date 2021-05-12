#include "glm/geometric.hpp"

#include "MetalMaterial.h"
#include "Hitable.h"
#include "Vec3Util.h"


MetalMaterial::MetalMaterial( const glm::vec3& albedo, const float fuzz ) :
    m_Albedo( albedo ),
    m_Fuzz( fuzz < 1.0f ? fuzz : 1.0f )
{}


MetalMaterial::~MetalMaterial()
{}


bool MetalMaterial::scatter( const Ray& rayIn, const HitRecord& record, glm::vec3& attenuation, Ray& scattered ) const
{
    glm::vec3 reflected = glm::reflect( glm::normalize(rayIn.getDirection()), record.normal );

    scattered   = Ray( record.hitPosition, reflected + m_Fuzz * randomInUnitSphere() );
    attenuation = m_Albedo;

    return ( glm::dot(scattered.getDirection(), record.normal) > 0 );
}