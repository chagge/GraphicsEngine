/*
 * PrimitiveEntityFactory.cpp
 *
 *  Created on: 28.04.2011
 *      Author: Norbert Nopper
 */

#include "../../layer4/model/Model.h"
#include "../../layer4/model/ModelFactory.h"
#include "../../layer5/modelentity/ModelEntity.h"

#include "PrimitiveEntityFactory.h"

using namespace std;

using namespace boost;

PrimitiveEntityFactory::PrimitiveEntityFactory()
{
}

PrimitiveEntityFactory::~PrimitiveEntityFactory()
{
}

ModelEntitySP PrimitiveEntityFactory::createCubePrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float halfExtend = 0.5f;

	glusCreateCubef(&shape, halfExtend);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(glusLengthf(halfExtend, halfExtend, halfExtend));

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Cube", boundingSphere, shape, surfaceMaterial), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createCubePrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial, const vector<AnimationStackSP>& allAnimStacks) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float halfExtend = 0.5f;

	glusCreateCubef(&shape, halfExtend);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(glusLengthf(halfExtend, halfExtend, halfExtend));

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Cube", boundingSphere, shape, surfaceMaterial, allAnimStacks), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createSpherePrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float radius = 0.5f;

	uint32_t numberSlices = 32;

	glusCreateSpheref(&shape, radius, numberSlices);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(radius);

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Sphere", boundingSphere, shape, surfaceMaterial), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createSpherePrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial, const vector<AnimationStackSP>& allAnimStacks) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float radius = 0.5f;

	uint32_t numberSlices = 32;

	glusCreateSpheref(&shape, radius, numberSlices);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(radius);

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Sphere", boundingSphere, shape, surfaceMaterial, allAnimStacks), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createDomePrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float radius = 0.5f;

	uint32_t numberSlices = 32;

	glusCreateDomef(&shape, radius, numberSlices);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(radius);

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Dome", boundingSphere, shape, surfaceMaterial), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createDomePrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial, const vector<AnimationStackSP>& allAnimStacks) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float radius = 0.5f;

	uint32_t numberSlices = 32;

	glusCreateDomef(&shape, radius, numberSlices);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(radius);

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Dome", boundingSphere, shape, surfaceMaterial, allAnimStacks), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createTorusPrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float innerRadius = 0.25f;
	float outerRadius = 0.5f;
	uint32_t numberSlices = 32;
	uint32_t numberStacks = 32;

	glusCreateTorusf(&shape, innerRadius, outerRadius, numberSlices, numberStacks);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(outerRadius);

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Torus", boundingSphere, shape, surfaceMaterial), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createTorusPrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial, const vector<AnimationStackSP>& allAnimStacks) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float innerRadius = 0.25f;
	float outerRadius = 0.5f;
	uint32_t numberSlices = 32;
	uint32_t numberStacks = 32;

	glusCreateTorusf(&shape, innerRadius, outerRadius, numberSlices, numberStacks);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(outerRadius);

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Torus", boundingSphere, shape, surfaceMaterial, allAnimStacks), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createConePrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float halfExtend = 0.5f;
	float radius = 0.5f;
	uint32_t numberSlices = 32;
	uint32_t numberStacks = 32;

	glusCreateConef(&shape, halfExtend, radius, numberSlices, numberStacks);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(glusLengthf(halfExtend, radius, 0.0f));

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Cone", boundingSphere, shape, surfaceMaterial), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createConePrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial, const vector<AnimationStackSP>& allAnimStacks) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float halfExtend = 0.5f;
	float radius = 0.5f;
	uint32_t numberSlices = 32;
	uint32_t numberStacks = 32;

	glusCreateConef(&shape, halfExtend, radius, numberSlices, numberStacks);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(glusLengthf(halfExtend, radius, 0.0f));

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Cone", boundingSphere, shape, surfaceMaterial, allAnimStacks), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createCylinderPrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float halfExtend = 0.5f;
	float radius = 0.5f;
	uint32_t numberSlices = 32;

	glusCreateCylinderf(&shape, halfExtend, radius, numberSlices);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(glusLengthf(halfExtend, radius, 0.0f));

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Cylinder", boundingSphere, shape, surfaceMaterial), scaleX, scaleY, scaleZ));
}

ModelEntitySP PrimitiveEntityFactory::createCylinderPrimitiveEntity(float scaleX, float scaleY, float scaleZ, const SurfaceMaterialSP& surfaceMaterial, const vector<AnimationStackSP>& allAnimStacks) const
{
	ModelFactory modelFactory;

	GLUSshape shape;

	float halfExtend = 0.5f;
	float radius = 0.5f;
	uint32_t numberSlices = 32;

	glusCreateCylinderf(&shape, halfExtend, radius, numberSlices);

	BoundingSphere boundingSphere;

	boundingSphere.setRadius(glusLengthf(halfExtend, radius, 0.0f));

	return ModelEntitySP(new ModelEntity(modelFactory.createModel("Cylinder", boundingSphere, shape, surfaceMaterial, allAnimStacks), scaleX, scaleY, scaleZ));
}
