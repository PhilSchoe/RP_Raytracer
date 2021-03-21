#pragma once
#include "Material.h"


class LambertMaterial : public Material
{
public:
    LambertMaterial( const glm::vec3& color );
    ~LambertMaterial();

    virtual bool scatter( const Ray& rayIn, const HitRecord& record, glm::vec3& attenuation, Ray& scattered 
                        ) const override;


private:
    glm::vec3 m_Albedo;
};