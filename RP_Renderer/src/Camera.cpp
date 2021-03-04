#include "Camera.h"


Camera::Camera( int resolutionX, int resolutionY )
{
    float aspectRatio    = resolutionX / (float) resolutionY;
    float viewportHeight = 2.0f;
    float viewportWidth  = aspectRatio * viewportHeight;
    float focalLength    = 1.0f;

    m_Origin          = glm::vec3( 0.0f );
    m_Horizontal      = glm::vec3( viewportWidth, 0.0f, 0.0f );
    m_Vertical        = glm::vec3( 0.0f, viewportHeight, 0.0f );
    m_LowerLeftCorner = m_Origin - m_Horizontal / 2.0f - m_Vertical / 2.0f - glm::vec3( 0.0f, 0.0f, focalLength );
}


Camera::~Camera()
{}


Ray Camera::getRay( float u, float v ) const
{
    return Ray( m_Origin, m_LowerLeftCorner + u * m_Horizontal + v * m_Vertical - m_Origin );
}