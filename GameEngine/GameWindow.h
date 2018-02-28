#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include "Clock.h"


class GameWindow
{
public:
	GameWindow();
	~GameWindow();
	void setCursorLocked(bool);
	void setCursorVisible(bool);
	void clear();
	void render();
	bool isOpen();
	void close();
	static bool keyPressed(int);//returns true on frame of press
	static bool keyReleased(int);//returns true on frame of release
	static bool keyHeld(int);//returns true when key held more than one frame

	static glm::dvec2 mousePos;
	static glm::dvec2 mouseDelta;
	static Clock clock;

	#pragma region keyDef
	static const int keyUnknown = -1;
	static const int keySpace = 32;
	static const int keyApostrophe = 39;
	static const int keyComma = 44;
	static const int keyMinus = 45;
	static const int keyPeriod = 46;
	static const int keyForwardslash = 47;
	static const int key0 = 48;
	static const int key1 = 49;
	static const int key2 = 50;
	static const int key3 = 51;
	static const int key4 = 52;
	static const int key5 = 53;
	static const int key6 = 54;
	static const int key7 = 55;
	static const int key8 = 56;
	static const int key9 = 57;
	static const int keySemicolon = 59;
	static const int keyEquals = 61;
	static const int keyA = 65;
	static const int keyB = 66;
	static const int keyC = 67;
	static const int keyD = 68;
	static const int keyE = 69;
	static const int keyF = 70;
	static const int keyG = 71;
	static const int keyH = 72;
	static const int keyI = 73;
	static const int keyJ = 74;
	static const int keyK = 75;
	static const int keyL = 76;
	static const int keyM = 77;
	static const int keyN = 78;
	static const int keyO = 79;
	static const int keyP = 80;
	static const int keyQ = 81;
	static const int keyR = 82;
	static const int keyS = 83;
	static const int keyT = 84;
	static const int keyU = 85;
	static const int keyV = 86;
	static const int keyW = 87;
	static const int keyX = 88;
	static const int keyY = 89;
	static const int keyZ = 90;
	static const int keyLBracket = 91;
	static const int keyBackslash = 92;
	static const int keyRBracket = 93;
	static const int keyGrave = 96;
	static const int keyEscape = 256;
	static const int keyEnter = 257;
	static const int keyTab = 258;
	static const int keyBackspace = 259;
	static const int keyInsert = 260;
	static const int keyDelete = 261;
	static const int keyRightArrow = 262;
	static const int keyLeftArrow = 263;
	static const int keyDownArrow = 264;
	static const int keyUpArrow = 265;
	static const int keyPageUp = 266;
	static const int keyPageDown = 267;
	static const int keyHome = 268;
	static const int keyEnd = 269;
	static const int keyCapsLock = 280;
	static const int keyScrollLock = 281;
	static const int keyNumLock = 282;
	static const int keyPrintScreen = 283;
	static const int keyPause = 284;
	static const int keyF1 = 290;
	static const int keyF2 = 291;
	static const int keyF3 = 292;
	static const int keyF4 = 293;
	static const int keyF5 = 294;
	static const int keyF6 = 295;
	static const int keyF7 = 296;
	static const int keyF8 = 297;
	static const int keyF9 = 298;
	static const int keyF10 = 299;
	static const int keyF11 = 300;
	static const int keyF12 = 301;
	static const int keyF13 = 302;
	static const int keyF14 = 303;
	static const int keyF15 = 304;
	static const int keyF16 = 305;
	static const int keyF17 = 306;
	static const int keyF18 = 307;
	static const int keyF19 = 308;
	static const int keyF20 = 309;
	static const int keyF21 = 310;
	static const int keyF22 = 311;
	static const int keyF23 = 312;
	static const int keyF24 = 313;
	static const int keyF25 = 314;
	static const int keypad0 = 320;
	static const int keypad1 = 321;
	static const int keypad2 = 322;
	static const int keypad3 = 323;
	static const int keypad4 = 324;
	static const int keypad5 = 325;
	static const int keypad6 = 326;
	static const int keypad7 = 327;
	static const int keypad8 = 328;
	static const int keypad9 = 329;
	static const int keypadPeriod = 330;
	static const int keypadForwardslash = 331;
	static const int keypadAsterisk = 332;
	static const int keypadSubtract = 333;
	static const int keypadPlus = 334;
	static const int keypadEnter = 335;
	static const int keypadEquals = 336;
	static const int keyLShift = 340;
	static const int keyLControl = 341;
	static const int keyLAlt = 342;
	static const int keyLSystem = 343;
	static const int keyRShift = 344;
	static const int keyRControl = 345;
	static const int keyRAlt = 346;
	static const int keyRSystem = 347;
	static const int keyMenu = 348;
	static const int mouseLeft = 0;
	static const int mouseRight = 1;
	static const int mouseWheel = 2;
	static const int mouseButton4 = 3;
	static const int mouseButton5 = 4;
	static const int mouseButton6 = 5;
	static const int mouseButton7 = 6;
	static const int mouseButton8 = 7;
	#pragma endregion
protected:
	static GLFWwindow * window;
	bool cursorLocked = false;
};