#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

const int Y = 10;
const int X = 20;

int sr, sc, er, ec;

char grid[10][20];

//imprime o grid
void print_grid(char grid[10][20])
{
    for (int y = 0; y < Y; y++)
    {
        cout << "\n";
        for (int x = 0; x < X; x++)
        {
            cout << grid[y][x] << ' ';
        }
    }
}

// põe os valores no grid
void fill_grid(char grid[10][20])
{
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            grid[y][x] = 'o';
        }
    }
}

//põe o começo e o fim no grid
void set_grid(char grid[10][20])
{
    print_grid(grid);

    cout << "\nfileira do ponto inicial: ";
    cin >> sr;
    cout << "\ncoluna do ponto inicial: ";
    cin >> sc;
    sr--;
    sc--;
    grid[sr][sc] = 'S';
    system("cls");
    print_grid(grid);
    do
    {
        cout << "\nfileira do ponto final: ";
        cin >> er;
        cout << "\ncoluna do ponto final: ";
        cin >> ec;
        if (sr != er || sc != ec)
        {
            er--;
            ec--;
            grid[er][ec] = 'E';
        }
        system("cls");
        print_grid(grid);
        if (sr == er && sc == ec)
        {
            cout << "\nsame spot try again\n";
            sleep(1);
        }
    } while (sr == er && sc == ec);
}

// encontrar o ponto final e definir uma area que se possa andar
void walk_area(char grid[10][20])
{
    int cr = sr, cc = sc;
    char *current = &grid[cr][cc];
    int count = 1;
    int repeats;

    while (*current != 'E')
    {
        repeats = count;
        cr--;
        current = &grid[cr][cc];
        *current = 'W';

        while (repeats != 0)
        {
            cr++;
            cc--;
            current = &grid[cr][cc];
            *current = 'W';
            repeats--;
        }

        repeats = count;

        while (repeats != 0)
        {
            cr++;
            cc++;
            current = &grid[cr][cc];
            *current = 'W';
            repeats--;
        }

        repeats = count;

        while (repeats != 0)
        {
            cr--;
            cc++;
            current = &grid[cr][cc];
            *current = 'W';
            repeats--;
        }

        repeats = count;

        while (repeats != 0)
        {
            cr--;
            cc--;
            current = &grid[cr][cc];
            *current = 'W';
            repeats--;
        }

        count++;
        
        print_grid(grid);
        system("PAUSE");
    }
}
int main()
{
    system("cls");
    fill_grid(grid);
    set_grid(grid);
    walk_area(grid);
    print_grid(grid);
}