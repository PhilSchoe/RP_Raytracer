#pragma once
#include "glm/vec3.hpp"
#include "glm/gtx/norm.hpp"
#include "RP_Utility.h"


inline static glm::vec3 randomVec3()
{
    // Returns a random vector3 with coordinates in [0; 1)
    return glm::vec3( randomFloat(), randomFloat(), randomFloat() );
}


inline static glm::vec3 randomVec3( float min, float max )
{
    // Returns a random vector3 with coordinates in [min; max)
    return glm::vec3( randomFloat(min, max), randomFloat(min, max), randomFloat(min, max) );
}


inline glm::vec3 randomInUnitSphere()
{
    while( true )
    {
        glm::vec3 position = randomVec3( -1.0f, 1.0f );
        if( glm::length2( position ) >= 1.0f )
        {
            continue;
        }

        return position;
    }
}


inline glm::vec3 randomUnitVector()
{
    return glm::normalize( randomInUnitSphere() );
}


inline bool nearZero( const glm::vec3& vector )
{
    // Return true if the vector is close to zero in all dimensions.
    const auto s = 1e-8;
    return( fabs(vector.x) < s && fabs(vector.y) < s && fabs(vector.z) < s );
}