#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include <map>
#include "Figures.h"

void ReadFromFile(std::vector<Figure*>& figure_array, const std::string& nameFile)
{
    std::string figure;
    int x;
    int y;
    std::ifstream koordinates(nameFile);
    if (!koordinates.is_open())
    {
        throw std::invalid_argument("File is not opened");
    }
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
}

int main()
{
    std::string nameFile = "Koordinates.txt";
    std::vector<Figure*> figure_array;
    try
    {
        ReadFromFile(figure_array, nameFile);
    }
    catch(std::invalid_argument& ex)
    {
        std::cout << ex.what() << std::endl;
        return 0;
    }
    for (int i = 0; i < figure_array.size(); i++)
    {
        for (int j = 0; j < figure_array.size(); j++)
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
    return 0;
}
