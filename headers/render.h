#ifndef CAMERA_H
#define CAMERA_H

#include "vec.h"


class Render
{

public:
	Render();

	float map();

private:

	void raycast();

	void render();

};


#endif // !CAMERA_H
