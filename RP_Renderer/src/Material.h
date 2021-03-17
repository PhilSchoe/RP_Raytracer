#pragma once
#include "Ray.h"

struct HitRecord;


class Material
{
public:
    virtual bool scatter( const Ray& rayIn, const HitRecord& record, glm::vec3& attenuation, Ray& scattered 
                        ) const = 0 ;
};