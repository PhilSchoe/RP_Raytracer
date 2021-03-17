#pragma once
#include "Hitable.h"


class Sphere : public Hitable
{
public:
    Sphere();
    Sphere( const glm::vec3& center, float radius, std::shared_ptr<Material> p_material );
    ~Sphere();

    virtual bool hit( const Ray& ray, float tMin, float tMax, HitRecord& record ) const override;


private:
    void storeHitRecord( const float t, const Ray& ray, HitRecord& record ) const; 

    glm::vec3 m_Center;
    float     m_Radius;

    std::shared_ptr<Material> m_p_Material;
};