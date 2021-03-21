#include "LambertMaterial.h"
#include "Hitable.h"
#include "Vec3Util.h"


LambertMaterial::LambertMaterial( const glm::vec3& color ) :
    m_Albedo( color )
{}


LambertMaterial::~LambertMaterial()
{}


bool LambertMaterial::scatter( const Ray& rayIn, const HitRecord& record, glm::vec3& attenuation, Ray& scattered ) const
{
    glm::vec3 scatterDirection = record.normal + randomUnitVector();

    if( nearZero( scatterDirection ) )
    {
        scatterDirection = record.normal;
    }

    scattered   = Ray( record.hitPosition, scatterDirection );
    attenuation = m_Albedo;

    return true;
}