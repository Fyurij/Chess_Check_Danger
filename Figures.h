#pragma once
#include <string>
class Figure
{
public:
    virtual int GetX() = 0;
    virtual int GetY() = 0;
    virtual std::string GetName() = 0;
    virtual bool Danger(int i, int j) = 0;
};

class King : public Figure
{
private:
    int x;
    int y;
    std::string name;
public:
    King(int x_, int y_, std::string name_)
        :x(x_)
        , y(y_)
        , name(name_)
    {}
    int GetX() override;
    int GetY() override;
    std::string GetName() override;
    bool Danger(int i, int j) override;
};

class Queen : public Figure
{
private:
    int x;
    int y;
    std::string name;
public:
    Queen(int x_, int y_, std::string name_)
        :x(x_)
        , y(y_)
        , name(name_)
    {}
    int GetX() override;
    int GetY() override;
    std::string GetName() override;
    bool Danger(int i, int j) override;
};

class Rook : public Figure
{
private:
    int x;
    int y;
    std::string name;
public:
    Rook(int x_, int y_, std::string name_)
        :x(x_)
        , y(y_)
        , name(name_)
    {}
    int GetX() override;
    int GetY() override;
    std::string GetName() override;
    bool Danger(int i, int j) override;
};

class Bishop : public Figure
{
private:
    int x;
    int y;
    std::string name;
public:
    Bishop(int x_, int y_, std::string name_)
        :x(x_)
        , y(y_)
        , name(name_)
    {}
    int GetX() override;
    int GetY() override;
    std::string GetName() override;
    bool Danger(int i, int j) override;
};

class Knight : public Figure
{
private:
    int x;
    int y;
    std::string name;
public:
    Knight(int x_, int y_, std::string name_)
        :x(x_)
        , y(y_)
        , name(name_)
    {}
    int GetX() override;
    int GetY() override;
    std::string GetName() override;
    bool Danger(int i, int j) override;
};