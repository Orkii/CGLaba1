#include <GL/glew.h>
#include <glm/glm.hpp>
#pragma once
class Drawable{
public:
	GLuint VBO;
	virtual void paint() = 0;
	virtual void update() = 0;
};

class Point : public Drawable {
public:

	Point(glm::vec3 v);

	virtual void paint() override;
	virtual void update() override;
};

