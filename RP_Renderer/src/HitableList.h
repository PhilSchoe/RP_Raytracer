#pragma once
#include <memory>
#include <vector>

#include "Hitable.h"


class HitableList : public Hitable
{
public:
	HitableList();
	HitableList( std::shared_ptr<Hitable> hitable );
	~HitableList();

	void add( std::shared_ptr<Hitable> hitable );
	void clear();

	virtual bool hit( const Ray& ray, float tMin, float tMax, HitRecord& record ) const override;


private:
	std::vector<std::shared_ptr<Hitable>> m_Hitables;
};