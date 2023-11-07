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
std::string King::GetName()
{
    return name;
}
bool King::Danger(int i, int j)
{
    if (abs(x - i) <= 1 && abs(y - j) <= 1)
    {
        return true;
    }
    return false;
}

int Queen::GetX()
{
    return x;
}

int Queen::GetY()
{
    return y;
}
std::string Queen::GetName()
{
    return name;
}
bool Queen::Danger(int i, int j)
{
    if (x == i || y == j || (x - y) == (i - j))
    {
        return true;
    }
    return false;
}

int Rook::GetX()
{
    return x;
}
int Rook::GetY()
{
    return y;
}
std::string Rook::GetName()
{
    return name;
}
bool Rook::Danger(int i, int j)
{
    if (x == i || y == j)
    {
        return true;
    }
    return false;
}

int Bishop::GetX() 
{
    return x;
}
int Bishop::GetY()
{
    return y;
}
std::string Bishop::GetName()
{ 
    return name;
}
bool Bishop::Danger(int i, int j)
{
    if ((x - y) == (i - j))
    {
        return true;
    }
    return false;
}

int Knight::GetX()
{
    return x;
}
int Knight::GetY()
{
    return y;
}
std::string Knight::GetName()
{
    return name;
}
bool Knight::Danger(int i, int j)
{
    if (((i - x == 1 || x - i == 1) && (j - y == 2 || y - j == 2)) || ((i - x == 2 || x - i == 2) && (j - y == 1 || y - j == 1)))
    {
        return true;
    }
    return false;
}