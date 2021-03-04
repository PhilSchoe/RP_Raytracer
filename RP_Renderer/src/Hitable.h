#pragma once
#include "glm/vec3.hpp"
#include "glm/geometric.hpp"
#include "Ray.h"


struct HitRecord
{
    float t;
    glm::vec3 hitPosition;
    glm::vec3 normal;
    bool frontFace;

    inline void setFaceNormal( const Ray& ray, const glm::vec3& outwardNormal )
    {
        // If ray and normal face in the same direction, ray is inside the object -> positive dot product.
        frontFace = glm::dot( ray.getDirection(), outwardNormal ) < 0.0f;
        normal    = frontFace ? outwardNormal : -outwardNormal;
    }
};


class Hitable
{
public:
    virtual bool hit( const Ray& ray, float tMin, float tMax, HitRecord& record ) const = 0;
};