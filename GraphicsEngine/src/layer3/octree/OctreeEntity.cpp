/*
 * OctreeEntity.cpp
 *
 *  Created on: 23.04.2011
 *      Author: Norbert Nopper
 */

#include "../../UsedLibs.h"

#include "Octant.h"

#include "OctreeEntity.h"

OctreeEntity::OctreeEntity() :
	Entity(), previousVisitingOctant(0), visitingOctant(0)
{
}

OctreeEntity::~OctreeEntity()
{
	BOOST_ASSERT(visitingOctant == 0);
}

Octant* OctreeEntity::getPreviousVisitingOctant() const
{
	return previousVisitingOctant;
}

void OctreeEntity::setPreviousVisitingOctant(Octant *previousVisitingOctant)
{
	this->previousVisitingOctant = previousVisitingOctant;
}

Octant* OctreeEntity::getVisitingOctant() const
{
	return visitingOctant;
}

void OctreeEntity::setVisitingOctant(Octant *visitingOctant)
{
	this->previousVisitingOctant = this->visitingOctant;

	this->visitingOctant = visitingOctant;
}

bool OctreeEntity::operator <=(const OctreeEntity& other) const
{
	return distanceToCamera <= other.distanceToCamera;
}
bool OctreeEntity::operator >=(const OctreeEntity& other) const
{
	return distanceToCamera >= other.distanceToCamera;
}

bool OctreeEntity::insideVisitingOctant() const
{
	if (!visitingOctant)
	{
		return false;
	}

	return getBoundingSphere().inside(*visitingOctant);
}

