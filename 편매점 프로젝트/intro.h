#ifndef INTRO_H
#define INTRO_H

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // ฟฃลอ
using namespace std;

void gotoxy(int x, int y);
void box2();
void Rectangle(int width, int height);
void Rectangle(int x, int y, int width, int height);
class TextColor {};
class Rectangle {};
#endif