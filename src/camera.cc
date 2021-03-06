#include "camera.hh"

Camera::Camera ()
  : px_ (0.f), py_ (0.f), pz_ (0.f),
    lx_ (0.f), ly_ (0.f), lz_ (0.f),
    rx_ (0.f), ry_ (0.f), rz_ (0.f),
    theta_ (0.f), phi_ (0.f),
    speed_ (1.f)
{
}

void Camera::look_at () const
{
  gluLookAt (px_, py_, pz_, lx_, ly_, lz_, rx_, ry_, rz_);
}

void Camera::set_perspective (int width, int height) const
{
  gluPerspective (70, (double)width/height, 1, 1000);
}

void Camera::update (float px, float py, float pz,
                     float rx, float ry, float rz,
                     float theta, float phi,
                     float speed)
{
  px_ = px;
  py_ = py;
  pz_ = pz;

  rx_ = rx;
  ry_ = ry;
  rz_ = rz;

  theta_ = theta;
  phi_ = phi;

  speed_ = speed;
}

void Camera::turn_left (float rad)
{
  theta_ += rad;

  lx_ = px_ + cos (theta_) * sin (phi_);
  ly_ = py_ + sin (theta_) * sin (phi_);
  lz_ = pz_ + cos (phi_);
}

void Camera::turn_right (float rad)
{
  theta_ -= rad;

  lx_ = px_ + cos (theta_) * sin (phi_);
  ly_ = py_ + sin (theta_) * sin (phi_);
  lz_ = pz_ + cos (phi_);
}

void Camera::move_forward (float d)
{
  float dx = speed_ * cos (theta_) * sin (phi_) * d;
  float dy = speed_ * sin (theta_) * sin (phi_) * d;
  float dz = speed_ * cos (phi_) * d;

  px_ += dx;
  py_ += dy;
  pz_ += dz;

  lx_ += dx;
  ly_ += dy;
  lz_ += dz;
}

void Camera::move_backward (float d)
{
  float dx = speed_ * cos (theta_) * sin (phi_) * d;
  float dy = speed_ * sin (theta_) * sin (phi_) * d;
  float dz = speed_ * cos (phi_) * d;

  px_ -= dx;
  py_ -= dy;
  pz_ -= dz;

  lx_ -= dx;
  ly_ -= dy;
  lz_ -= dz;
}

void Camera::turn_up (float rad)
{
  phi_ -= rad;
  if (phi_ < 0.01)
    phi_ = 0.01f;
  lx_ = px_ + cos (theta_) * sin (phi_);
  ly_ = py_ + sin (theta_) * sin (phi_);
  lz_ = pz_ + cos (phi_);
}

void Camera::turn_down (float rad)
{
  phi_ += rad;
  if (phi_ > M_PI - 0.01f)
    phi_ = M_PI - 0.01f;
  lx_ = px_ + cos (theta_) * sin (phi_);
  ly_ = py_ + sin (theta_) * sin (phi_);
  lz_ = pz_ + cos (phi_);
}

void Camera::translate (float x, float y, float z)
{
  px_ += x;
  py_ += y;
  pz_ += z;

  lx_ += x;
  ly_ += y;
  lz_ += z;
}

void Camera::move_to (float x, float y, float z)
{
  px_ = x;
  py_ = y;
  pz_ = z;

  lx_ = px_ + cos (theta_) * sin (phi_);
  ly_ = py_ + sin (theta_) * sin (phi_);
  lz_ = pz_ + cos (phi_);
}
