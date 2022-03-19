#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#pragma once





class Drawable{
public:
	GLuint VBO;
	virtual void paint() = 0;
	virtual void update() = 0;
};

class Point : public Drawable {
public:

	Point(glm::vec3 &v);

	virtual void paint() override;
	virtual void update() override;
};

class Smth : public Drawable {

public:
	int drawType;
	int pointNum;
	Smth(std::vector<glm::vec3> &v, int drawType_ = GL_TRIANGLE_FAN);

	virtual void paint() override;
	virtual void update() override;
};

