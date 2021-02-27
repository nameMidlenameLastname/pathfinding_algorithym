#include <iostream>
using namespace std;
// dimensões do grid
const int Y = 10;
const int X = 20;

// definindo grid
char grid[Y][X];

// põe os valores no grid
void set_grid(char grid[Y][X])
{
    for (int y = 0; y < 12; y++)
    {

        for (int x = 0; x < 20; x++)
        {
            grid[y][x] = 'o';
        }
    }
}
// imprime o grid
void print_grid(char grid[Y][X])
{
    for (int y = 0; y < 12; y++)
    {
        for (int z = 0; z < 20; z++)
        {
            if (y == 0 && z == 0)
            {
                cout << "       ";
            }

            if (y == 1)
            {
                if (z > 9)
                {
                    cout << z << " ";
                }
                else
                {
                    cout << z << "  ";
                }
            }
            if (y == 1 && z == 19)
            {
                cout << "\n";
                cout << "       ===========================================================";
            }
        }

        if (y > 1)
        {
            int w = y - 2;
            cout << "\n"
                 << w << "  ||";

            for (int x = 0; x < 20; x++)
            {
                cout << "  " << grid[w][x];
            }
        }
    }
    cout << "\n";
}

int main()
{
    set_grid(grid);
    print_grid(grid);
    system("PAUSE");
}