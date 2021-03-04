#pragma once
#include <limits>
#include <cstdlib>


// Constants

const float RP_INFINITY = std::numeric_limits<float>::infinity();
const float RP_PI       = 3.1415926535897932385f;

// Utility Functions

inline float randomFloat()
{
    // Returns a random real in [0; 1)
    return rand() / ( RAND_MAX + 1.0f );
}

inline float randomFloat( float min, float max )
{
    // Returns a random real in [min; max)
    return min + ( max - min ) * randomFloat();
}