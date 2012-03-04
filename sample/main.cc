#include <SDL/SDL.h>
#include <GL/gl.h>
#include <cstdlib>
#include <vector>
#include "camera.hh"

#define WIDTH_SCREEN 640
#define HEIGHT_SCREEN 480

void Draw (std::vector<int>&, Camera&);

int main (int argc, char *argv[])
{
    SDL_Event event;

    SDL_Init (SDL_INIT_VIDEO);
    atexit (SDL_Quit);

    SDL_WM_SetCaption ("Camera sample", NULL);
    SDL_SetVideoMode (WIDTH_SCREEN, HEIGHT_SCREEN, 32, SDL_OPENGL);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    /// Here we setup the camera.
    Camera camera;
    /// Set the perspective of Glu.
    camera.set_perspective (WIDTH_SCREEN, HEIGHT_SCREEN);
    /// Update one time all the values of the camera.
    camera.update (50.f, 0.f, 2.f,
                  -10.f, 0.f, 2.f,
                   0.f, 0.f, 1.f,
                   0.f, 3.14159265f / 2,
                   1.f);

    SDL_EnableKeyRepeat (10, 10);

    /// Let's start a vector of Quads
    std::vector<int> quads;
    for (int i = 0; i < 100; i++)
      quads.push_back (i);

    Draw (quads, camera);

    while (SDL_WaitEvent (&event))
    {
        switch (event.type)
        {
          case SDL_QUIT:
            exit (0);
          break;
          case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_a:
                  /// Turn down the camera of 0.04 radians.
                  camera.turn_down (0.04f);
                break;
                case SDLK_b:
                  /// Turn up the camera of 0.04 radians.
                  camera.turn_up (0.04f);
                break;
                case SDLK_UP:
                  /// Move forward the camera with a distance of 2.
                  camera.move_forward (2);
                break;
                case SDLK_DOWN:
                  /// Move backward the camera with a distance of 2.
                  camera.move_backward (2);
                break;
                case SDLK_LEFT:
                  /// Turn left the camera of 0.04 radians.
                  camera.turn_left (0.04f);
                break;
                case SDLK_RIGHT:
                  /// Turn right the camera of 0.04 radians.
                  camera.turn_right (0.04f);
                break;
            }
          break;
        }
        Draw (quads, camera);
    }

    return 0;
}

/// A basic function to draw rectangles.
void draw_rectangle (double width, double height)
{
    glBegin(GL_QUADS);
    glVertex2d(0, -height / 2);
    glVertex2d(0, height / 2);
    glVertex2d(width, height / 2);
    glVertex2d(width, -height / 2);
    glEnd();
}

void Draw (std::vector<int>& memory, Camera& camera)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();

    /// We set the lookAt of Glu with the values of the camera.
    camera.look_at ();

    /// The array 'c' contains 2 colors so as to alternate between the quads.
    int c[2] = {127, 254};
    int i = 0;
    /// Let's draw something.
    for (std::vector<int>::iterator itr = memory.begin ();
        itr != memory.end (); i++, itr++)
    {
      glTranslated (-5, 0, 0);
      glColor3ub (c[i % 2], c[i % 2], c[i % 2]);
      draw_rectangle (5, 5);
    }

    glFlush ();
    SDL_GL_SwapBuffers ();
}
