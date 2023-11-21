#include <iostream>
#include <string>
#include "Figures.h"

int King::GetX()
{
    return x;
}
int King::GetY()
{
    return y;
}
std::string& King::GetName()
{
    return name;
}
char King::GetSymbol()
{
    return 'K';
}
bool King::Danger(int i, int j)
{
    return (abs(x - i) <= 1 && abs(y - j) <= 1);
}

int Queen::GetX()
{
    return x;
}
int Queen::GetY()
{
    return y;
}
std::string& Queen::GetName()
{
    return name;
}
char Queen::GetSymbol()
{
    return 'Q';
}
bool Queen::Danger(int i, int j)
{
    return (x == i || y == j || (x - y) == (i - j));
}

int Rook::GetX()
{
    return x;
}
int Rook::GetY()
{
    return y;
}
std::string& Rook::GetName()
{
    return name;
}
char Rook::GetSymbol()
{
    return 'R';
}
bool Rook::Danger(int i, int j)
{
    return (x == i || y == j);
}

int Bishop::GetX() 
{
    return x;
}
int Bishop::GetY()
{
    return y;
}
std::string& Bishop::GetName()
{ 
    return name;
}
char Bishop::GetSymbol()
{
    return 'B';
}
bool Bishop::Danger(int i, int j)
{
    return ((x - y) == (i - j));
}

int Knight::GetX()
{
    return x;
}
int Knight::GetY()
{
    return y;
}
std::string& Knight::GetName()
{
    return name;
}
char Knight::GetSymbol()
{
    return 'k';
}
bool Knight::Danger(int i, int j)
{
    return (((i - x == 1 || x - i == 1) && (j - y == 2 || y - j == 2)) || ((i - x == 2 || x - i == 2) && (j - y == 1 || y - j == 1)));
}