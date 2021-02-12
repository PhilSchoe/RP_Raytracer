#include "Ray.h"


Ray::Ray() :
    m_Origin( 0.0f ),
    m_Direction( 0.0f )
{}


Ray::Ray( const glm::vec3& origin, const glm::vec3& direction ) :
    m_Origin( origin ),
    m_Direction( direction )
{}


Ray::~Ray()
{}


glm::vec3 Ray::getOrigin() const
{
    return m_Origin;
}


glm::vec3 Ray::getDirection() const
{
    return m_Direction;
}


glm::vec3 Ray::getPointAtParameter( float t ) const
{
    return m_Origin + t * m_Direction;
}