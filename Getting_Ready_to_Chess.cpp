#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include <map>

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
    int GetX() override
    {
        return x;
    }
    int GetY() override
    {
        return y;
    }
    std::string GetName()
    {
        return name;
    }
    bool Danger(int i, int j) override
    {
        if (abs(x - i) <= 1 && abs(y - j) <= 1)
        {
            return true;
        }
        return false;
    }
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
    int GetX() override
    {
        return x;
    }
    int GetY() override
    {
        return y;
    }
    std::string GetName()
    {
        return name;
    }
    bool Danger(int i, int j) override
    {
        if (x == i || y == j || (x - y) == (i - j))
        {
            return true;
        }
        return false;
    }
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
    int GetX() override
    {
        return x;
    }
    int GetY() override
    {
        return y;
    }
    std::string GetName()
    {
        return name;
    }
    bool Danger(int i, int j) override
    {
        if (x == i || y == j)
        {
            return true;
        }
        return false;
    }
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
    int GetX() override
    {
        return x;
    }
    int GetY() override
    {
        return y;
    }
    std::string GetName()
    {
        return name;
    }
    bool Danger(int i, int j) override
    {
        if ((x - y) == (i - j))
        {
            return true;
        }
        return false;
    }
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
    int GetX() override
    {
        return x;
    }
    int GetY() override
    {
        return y;
    }
    std::string GetName()
    {
        return name;
    }
    bool Danger(int i, int j) override
    {
        if (((i - x == 1 || x - i == 1) && (j - y == 2 || y - j == 2)) || ((i - x == 2 || x - i == 2) && (j - y == 1 || y - j == 1)))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    std::ifstream koordinates("Koordinates.txt");
    if (!koordinates.is_open())
    {
        std::cout << "File is not opened" << std::endl;
        return 0;
    }
    std::string figure;
    int x;
    int y;
    std::vector<Figure*> figure_array;
    while (!koordinates.eof())
    {
        koordinates >> figure >> x >> y;
        
        if (figure == "king")
        {
            Figure* character = new King(x, y, figure);
            figure_array.push_back(character);
        }
        else if (figure == "queen")
        {
            Figure* character = new Queen(x, y, figure);
            figure_array.push_back(character);
        }
        else if (figure == "rook")
        {
            Figure* character = new Rook(x, y, figure);
            figure_array.push_back(character);
        }
        else if (figure == "bishop")
        {
            Figure* character = new Bishop(x, y, figure);
            figure_array.push_back(character);
        }
        else if (figure == "knight")
        {
            Figure* character = new Knight(x, y, figure);
            figure_array.push_back(character);
        }
        else
        {
            std::cout << "Invalid argument" << std::endl;
        }
        std::cout << figure << " " << x << " " << y << std::endl;
    }
    for (int i = 0; i < figure_array.size() ; i++)
    {
        for (int j = 0; j < figure_array.size() ; j++)
        {
            if (i != j)
            {
                bool check = figure_array[i]->Danger(figure_array[j]->GetX(), figure_array[j]->GetY());
                if (check)
                {
                    std::cout << figure_array[i]->GetName() << " -> " << figure_array[j]->GetName() << std::endl;
                }
            }
        }
    }
}
