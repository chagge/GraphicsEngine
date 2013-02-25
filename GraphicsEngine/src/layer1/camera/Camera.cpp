/*
 * Camera.cpp
 *
 *  Created on: 23.04.2011
 *      Author: Norbert Nopper
 */

#include "../../layer0/shader/Variables.h"

#include "Camera.h"

Camera::Camera() :
	eye(0.0f, 0.0f, 5.0f), center(0.0f, 0.0f, 0.0f), up(0.0f, 1.0f, 0.0f), direction(), viewport(), zNear(0.1f), zFar(1000.0f), viewFrustum()
{
	lookAt(eye, center, up);
}

Camera::Camera(const Camera& other) :
	eye(other.eye), center(other.center), up(other.up), viewport(other.viewport), zNear(other.zNear), zFar(other.zFar), viewFrustum(other.viewFrustum)
{
	viewMatrix = other.viewMatrix;
	projectionMatrix = other.projectionMatrix;
}

Camera::~Camera()
{
}

void Camera::updateViewFrustum()
{
	Matrix4x4 transposedViewProjectionMatrix = projectionMatrix * viewMatrix;
	transposedViewProjectionMatrix.transpose();
	viewFrustum.transformToWorldSpace(transposedViewProjectionMatrix);
}

void Camera::setPosition(const Point4& position)
{
	this->eye = position;
	this->center = position + direction;

	lookAt(eye, center, up);
}

void Camera::setRotation(float angleZ, float angleY, float angleX)
{
	Matrix4x4 rotationMatrix;
	Vector3 direction(0.0f, 0.0f, -1.0f);
	Vector3 up(0.0f, 1.0f, 0.0f);

	rotationMatrix.rotateRzRyRx(angleZ, angleY, angleX);

	this->center = this->eye + rotationMatrix * direction;
	this->up = rotationMatrix * up;

	lookAt(eye, center, up);
}

void Camera::setRotation(Quaternion& rotation)
{
	Vector3 direction(0.0f, 0.0f, -1.0f);
	Vector3 up(0.0f, 1.0f, 0.0f);

	this->center = this->eye + rotation.getRotationMatrix4x4() * direction;
	this->up = rotation.getRotationMatrix4x4() * up;

	lookAt(eye, center, up);
}

void Camera::lookAt(const Point4& eye, const Point4& center, const Vector3& up)
{
	float result[16];

	this->eye = eye;
	this->center = center;
	this->up = up;
	this->direction = (center - eye).normalize();

	glusLookAtf(result, eye.getX(), eye.getY(), eye.getZ(), center.getX(), center.getY(), center.getZ(), up.getX(), up.getY(), up.getZ());

	viewMatrix.setM(result);

	updateViewFrustum();
}

void Camera::updateViewport( const Viewport& viewport)
{
	this->viewport = viewport;

	updateProjectionMatrix();
}

const Point4& Camera::getEye() const
{
	return eye;
}

const Matrix4x4& Camera::getViewMatrix() const
{
	return viewMatrix;
}

const Matrix4x4& Camera::getProjectionMatrix() const
{
	return projectionMatrix;
}

const ViewFrustum& Camera::getViewFrustum() const
{
	return viewFrustum;
}

float Camera::distanceToCamera(const BoundingSphere& boundingSphere) const
{
	return (boundingSphere.getCenter() - eye).dot(direction);
}

void Camera::setCameraProperties(const ProgramSP& program) const
{
	glUniformMatrix4fv(program->getUniformLocation(u_projectionMatrix), 1, GL_FALSE, projectionMatrix.getM());

	glUniformMatrix4fv(program->getUniformLocation(u_viewMatrix), 1, GL_FALSE, viewMatrix.getM());

	glUniform4fv(program->getUniformLocation(u_eyePosition), 1, eye.getP());
}