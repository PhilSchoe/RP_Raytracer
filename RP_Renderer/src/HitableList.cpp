#include "HitableList.h"


HitableList::HitableList()
{}


HitableList::HitableList( std::shared_ptr<Hitable> hitable )
{
    this->add( hitable );
}


HitableList::~HitableList()
{}


void HitableList::add( std::shared_ptr<Hitable> hitable )
{
    m_Hitables.push_back( hitable );
}


void HitableList::clear()
{
    m_Hitables.clear();
}


bool HitableList::hit( const Ray& ray, float tMin, float tMax, HitRecord& record ) const
{
    HitRecord tempRecord;
    bool hitAnything   = false;
    float closestSoFar = tMax;

    for( const auto& hitable : m_Hitables )
    {
        if( hitable->hit( ray, tMin, closestSoFar, tempRecord ) )
        {
            hitAnything  = true;
            closestSoFar = tempRecord.t;
            record       = tempRecord;
        }
    }

    return hitAnything;
}