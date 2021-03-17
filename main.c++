#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

const int Y = 10;
const int X = 20;

int sr, sc, er, ec, enr, enc;

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

// encontra o ponto final
void find_end(char grid[10][20])
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
        if (cr > -1 && cr < 10 && cc > -1 && cc < 20)
        {

            *current = 'W';
        }

        // down-left
        while (repeats != 0)
        {
            cr++;
            cc--;
            current = &grid[cr][cc];
            if (*current == 'E' && cr > -1 && cr < 10 && cc > -1 && cc < 20)
            {
                enr = cr;
                enc = cc;
                break;
            }
            if (cr > -1 && cr < 10 && cc > -1 && cc < 20 && *current != 'E' && *current != 'S')
            {
                *current = 'W';
            }
            repeats--;
        }
        if (*current == 'E' && cr > -1 && cr < 10 && cc > -1 && cc < 20)
        {
            enr = cr;
            enc = cc;
            break;
        }

        repeats = count;

        //down-right
        while (repeats != 0)
        {
            cr++;
            cc++;
            current = &grid[cr][cc];
            if (*current == 'E' && cr > -1 && cr < 10 && cc > -1 && cc < 20)
            {
                enr = cr;
                enc = cc;
                break;
            }
            if (cr > -1 && cr < 10 && cc > -1 && cc < 20 && *current != 'E' && *current != 'S')
            {
                *current = 'W';
            }
            repeats--;
        }
        if (*current == 'E' && cr > -1 && cr < 10 && cc > -1 && cc < 20)
        {
            enr = cr;
            enc = cc;
            break;
        }

        repeats = count;

        //up-right
        while (repeats != 0)
        {
            cr--;
            cc++;
            current = &grid[cr][cc];
            if (*current == 'E' && cr > -1 && cr < 10 && cc > -1 && cc < 20)
            {
                enr = cr;
                enc = cc;
                break;
            }
            if (cr > -1 && cr < 10 && cc > -1 && cc < 20 && *current != 'E' && *current != 'S')
            {
                *current = 'W';
            }
            repeats--;
        }
        if (*current == 'E' && cr > -1 && cr < 10 && cc > -1 && cc < 20)
        {
            enr = cr;
            enc = cc;
            break;
        }

        repeats = count;

        //up-left
        while (repeats != 0)
        {
            cr--;
            cc--;
            current = &grid[cr][cc];
            if (*current == 'E' && cr > -1 && cr < 10 && cc > -1 && cc < 20)
            {
                enr = cr;
                enc = cc;
                break;
            }
            if (cr > -1 && cr < 10 && cc > -1 && cc < 20 && *current != 'E' && *current != 'S')
            {
                *current = 'W';
            }
            repeats--;
        }
        if (*current == 'E' && cr > -1 && cr < 10 && cc > -1 && cc < 20)
        {
            enr = cr;
            enc = cc;
            break;
        }

        count++;
        repeats = count;
    }
}
void find_path(char grid[10][20])
{
    int cr = sr, cc = sc;
    char *current = &grid[cr][cc];
    char *end_point = &grid[enr][enc];

    while (current != end_point)
    {
        if (enr - (cr - 1) < enr - (cr + 1) && cr != enr)
        {
            cr--;
            current = &grid[cr][cc];
            if (*current != 'E')
            {
                *current = 'z';
            }
        }
        if (enr - (cr + 1) < enr - (cr - 1) && cr != enr)
        {
            cr++;
            current = &grid[cr][cc];
            if (*current != 'E')
            {
                *current = 'z';
            }
        }
        if (enc - (cc - 1) < enc - (cc + 1) && cc != enc)
        {
            cc--;
            current = &grid[cr][cc];
            if (*current != 'E')
            {
                *current = 'z';
            }
        }
        if (enc - (cc + 1) < enc - (cc - 1) && cc != enc)
        {
            cc++;
            current = &grid[cr][cc];
            if (*current != 'E')
            {
                *current = 'z';
            }
        }
    }
}

int main()
{
    system("cls");
    fill_grid(grid);
    set_grid(grid);
    find_end(grid);
    find_path(grid);
    print_grid(grid);
}