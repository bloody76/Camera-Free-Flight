#ifndef CAMERA_HH_
# define CAMERA_HH_

# include  <GL/glu.h>
# include <cmath>

/** \brief Camera Freeflight
 **
 ** List of Attributes and Methods. */

class Camera
{
  /** \name Constructor.
   ** \{ */
  public:
    /** \brief Construct a Camera.
     */
    Camera ();
    /** \} */

  /** \name Methods which interface with glu.
   ** \{ */
  public:
    /// Call the LookAt of Glu.
    void look_at () const;
    /// Call the SetPerspective of Glu.
    void set_perspective (int width, int height) const;
  /** \} */

  /** \name Manipulators of the Camera.
   ** \{ */
  public:
    /// Update funtion so as to set all the attributes in one time.
    void update (float px, float py, float pz,
                 float lx, float ly, float lz,
                 float rx, float ry, float rz,
                 float theta, float phi,
                 float distance);
    /// Turn up the camera with an angle of rad radians.
    void turn_up (float rad);
    /// Turn down the camera with an angle of rad radians.
    void turn_down (float rad);
    /// Turn left the camera with an angle of rad radians.
    void turn_left (float rad);
    /// Turn right the camera with an angle of rad radians.
    void turn_right (float rad);
    /// Move forward the camera with a distance d.
    void move_forward (float d);
    /// Move backward the camera with a distance d.
    void move_backward (float d);
  /** \} */

  /** \name Accessors.
   ** \{ */
  public:
    /// Return the position x of the eye.
    float px_get () const;
    /// Return the position x of the eye.
    float px_get ();
    /// Set the position x of the eye.
    void px_set (float);
    /// Return the position y of the eye.
    float py_get () const;
    /// Return the position y of the eye.
    float py_get ();
    /// Set the position y of the eye.
    void py_set (float);
    /// Return the position z of the eye.
    float pz_get () const;
    /// Return the position z of the eye.
    float pz_get ();
    /// Set the position z of the eye.
    void pz_set (float);
    /// Return the position x of the looking point.
    float lx_get () const;
    /// Return the position x of the looking point.
    float lx_get ();
    /// Set the position x of the looking point.
    void lx_set (float);
    /// Return the position y of the looking point.
    float ly_get () const;
    /// Return the position y of the looking point.
    float ly_get ();
    /// Set the position y of the looking point.
    void ly_set (float);
    /// Return the position z of the looking point.
    float lz_get () const;
    /// Return the position z of the looking point.
    float lz_get ();
    /// Set the position z of the looking point.
    void lz_set (float);
    /// Return the rotation x.
    float rx_get () const;
    /// Return the rotation x.
    float rx_get ();
    /// Set the rotation x.
    void rx_set (float);
    /// Return the rotation y.
    float ry_get () const;
    /// Return the rotation y.
    float ry_get ();
    /// Set the rotation y.
    void ry_set (float);
    /// Return the rotation z.
    float rz_get () const;
    /// Return the rotation z.
    float rz_get ();
    /// Set the rotation z.
    void rz_set (float);
    /// Return the angle theta.
    float theta_get () const;
    /// Return the angle theta.
    float theta_get ();
    /// Set the angle theta.
    void theta_set (float);
    /// Return the angle phi.
    float phi_get () const;
    /// Return the angle phi.
    float phi_get ();
    /// Set the angle y.
    void phi_set (float);
    /// Return the distance.
    float distance_get () const;
    /// Return the distance.
    float distance_get ();
    /// Set the distance.
    void distance_set (float);
    /** \} */

  private:
    /// The position of the camera.
    float px_;
    float py_;
    float pz_;
    /// The position where the camera is looking at.
    float lx_;
    float ly_;
    float lz_;
    /// The rotation of the camera.
    float rx_;
    float ry_;
    float rz_;
    /// The angle of the camera.
    float theta_;
    float phi_;
    /// The distance between the eye and the point it is looking at.
    float distance_;
};

# include "camera.hxx"

#endif /* !CAMERA_HH_ */
