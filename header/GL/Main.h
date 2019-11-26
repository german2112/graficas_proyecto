#ifdef _MAIN_H
#define _MAIN_H
#endif
#pragma once



#include <windows.h>					// Header File For Windows
#include <gl\gl.h>						// Header File For The OpenGL32 Library
#include <gl\glu.h>						// Header File For The GLU32 Library	

#include <math.h>
#define CAMERASPEED	0.03f	

typedef struct tVector3
{
	tVector3() {}
	tVector3(float new_x, float new_y, float new_z) {
		x = new_x;
		y = new_y;
		z = new_z;
	}
	tVector3 operator+(tVector3 vVector) {
		return tVector3(vVector.x + x, vVector.y + y, vVector.z + z);
	}
	tVector3 operator-(tVector3 vVector) { 
		return tVector3(x - vVector.x, y - vVector.y, z - vVector.z); 
	}
	tVector3 operator*(float number) { 
		return tVector3(x * number, y * number, z * number); 
	}
	tVector3 operator/(float number) { 
		return tVector3(x / number, y / number, z / number); 
	}

	float x, y, z;
}tVector3;

class CCamera
{
	public:

		tVector3 mPos;
		tVector3 mView;
		tVector3 mUp;

		void Mouse_Move(int wndWidth, int wndHeight);

		void Move_Camera(float speed);
		void Rotate_View(float speed);
		void Position_Camera(float pos_x, float pos_y, float pos_z,
			float view_x, float view_y, float view_z,
			float up_x, float up_y, float up_z);
};

void Keyboard_Input();
void Draw_Grid();

