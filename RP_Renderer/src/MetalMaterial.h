#pragma once
#include "Material.h"


class MetalMaterial : public Material
{
public:
    MetalMaterial( const glm::vec3& albedo );
    ~MetalMaterial();

    virtual bool scatter( const Ray& rayIn, const HitRecord& record, glm::vec3& attenuation, Ray& scattered 
                         ) const override;


private:
    glm::vec3 m_Albedo;
};