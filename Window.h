#pragma once
#include <list>
#include "Drawable.h"



using namespace std;
static class Window{
public:
	static int sizeX;
	static int sizeY;
	static int posX;
	static int posY;
	static list<Drawable*> *objs;
	const char* windowName = "Laba1";

	static int init(int argc, char** argv, void(*callback)());

	static void add(Drawable* obj);

	static void paint();

};

