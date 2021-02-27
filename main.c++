#include <iostream>
#include <unistd.h>
using namespace std;
// dimensões do grid
const int Y = 10;
const int X = 20;

// definindo grid
char grid[Y][X];
int sc;
int sr;
int ec;
int er;

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
    print_grid(grid);

    cout << "\nwhich column for starting point?\n";
    cin >> sc;

    cout << "\nwhich row for starting point?\n";
    cin >> sr;

    grid[sr][sc] = 'S';

    print_grid(grid);

    do
    {
        if (sc == ec && sr == er)
        {
            cout << "\nsame spot try again\n";
            sleep(1);
            print_grid(grid);
        }
        cout << "\nwhich column for final point?\n";
        cin >> ec;

        cout << "\nwhich row for final point?\n";
        cin >> er;
        if (sc != ec || sr != er)
        {
            grid[er][ec] = 'E';
        }
    } while (sc == ec && sr == er);

    print_grid(grid);
}

int main()
{
    set_grid(grid);
}