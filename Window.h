#pragma once
class Window{
public:
	static int sizeX;
	static int sizeY;
	static int posX ;
	static int posY ;
	const char* windowName = "Laba1";

	static int init(int argc, char** argv, void(*callback)());

};

