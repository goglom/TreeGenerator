#include "cameraview.hpp"
#include <cmath>
#include <algorithm>

void CameraView::updateVectors()
{
    front_.setX(std::cos(yaw_) * std::cos(pitch_));
    front_.setY(-std::sin(pitch_));
    front_.setZ(std::sin(yaw_) * std::cos(pitch_));
    front_.normalize();
    right_ = QVector3D::crossProduct(front_, worldUp_).normalized();
    up_ = QVector3D::crossProduct(right_, front_).normalized();
}

CameraView::CameraView(
        const QVector3D& eye_pos,
        const QVector3D& front,
        const QVector3D& up
        )
    : eye_pos_(eye_pos),
      front_(front),
      worldUp_(up)
{
    updateVectors();
}


QMatrix4x4 const& CameraView::getViewMatrix()
{
    view_.setToIdentity();
    view_.lookAt(eye_pos_, eye_pos_ + front_, up_);
    return view_;
}

const QMatrix4x4& CameraView::getProjectionMatrix()
{
    projection_.setToIdentity();
    projection_.perspective(fov_, aspectRatio_, zNear_, zFar_);
    return projection_;
}

const QMatrix4x4& CameraView::getProjViewMatrix()
{
    projView_ = getProjectionMatrix() * getViewMatrix();
    return projView_;
}

const QVector3D& CameraView::cameraPosition() const
{
    return eye_pos_;
}

void CameraView::setProjection(float fov, float aspectRatio, float zNear, float zFar)
{
    setFOV(fov);
    setAspectRatio(aspectRatio);
    setZNear(zNear);
    setZFar(zFar);
}

void CameraView::setFOV(float fov)
{
    fov_ = fov;
}

void CameraView::setAspectRatio(float ratio)
{
    aspectRatio_ = ratio;
}

void CameraView::setZNear(float zNear)
{
    zNear_ = zNear;
}

void CameraView::setZFar(float zFar)
{
    zFar_ = zFar;
}

void CameraView::offsetMove(const QVector3D& offset)
{
    eye_pos_ += front_ * offset.z();
    eye_pos_ += up_  * offset.y();
    eye_pos_ += right_ * offset.x();
}

void CameraView::moveTo(const QVector3D& position)
{
    eye_pos_ = position;
}

//void CameraView::move(CameraView::directions direction, float length)
//{
//    switch (direction) {
//    case directions::forward :
//        eye_pos_ += front_ * length;
//        break;
//    case directions::backward:
//        eye_pos_ -= front_ * length;
//        break;
//    case directions::right:
//        eye_pos_ += right_ * length;
//        break;
//    case directions::left:
//        eye_pos_ -= right_ * length;
//        break;
//    case directions::up:
//        eye_pos_ += up_ * length;
//        break;
//    case directions::down:
//        eye_pos_ -= up_ * length;
//        break;
//    }
//}

void CameraView::rotate(float yaw, float pitch)
{
    yaw_ += yaw;
    pitch_ += pitch;

    if constexpr (constrainPitch){
        pitch_ = std::clamp(pitch_, -static_cast<float>(M_PI) / 2.2f, static_cast<float>(M_PI) / 2.2f);
    }
    updateVectors();
}
