#include <iostream>

using namespace std;

struct element
{
    int row;
    int col;
    int dir;
};

element stack[256];

int EXIT_ROW = 0;
int EXIT_COL = 0;

int top = -1;

typedef struct
{
    int vert;
    int horiz;
} offsets;

offsets move[4];

int mark[9][9];
int maze[9][9] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 1, 0, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 1, 0},
        {1, 1, 1, 0, 1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 3, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1, 0}};

void path();
void add(int *, element);
element del(int *);
void stack_full();
element stack_empty();

int main()
{
    int i, j;

    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            if (maze[i][j] == 3)
            {
                EXIT_ROW = i;
                EXIT_COL = j;
            }
        }
    }

    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 8; j++)
            mark[i][j] = 0;

    move[0].vert = 1;
    move[0].horiz = 0;

    move[1].vert = -1;
    move[1].horiz = 0;

    move[2].vert = 0;
    move[2].horiz = 1;

    move[3].vert = 0;
    move[3].horiz = -1;

    path();

    return 0;
}

void path()
{
    int i, j, row, col, next_row, next_col, dir, found = 0;

    element position;

    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 8; j++)
            if (maze[i][j] == 2)
                mark[i][j] = 1;

    top = 0;

    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 0;

    while (top > -1 && !found)
    {
        position = del(&top);
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 4 && !found)
        {
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;

            if (next_row == EXIT_ROW && next_col == EXIT_COL)
                found = 1;

            else if (!maze[next_row][next_col] && !mark[next_row][next_col])
            {
                mark[next_row][next_col] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                add(&top, position);
                row = next_row;
                col = next_col;
                dir = 0;
            }

            else
                ++dir;
        }
    }

    if (found)
    {
        cout << "The path is:" << endl;
        cout << "  row col" << endl;
        for (int i = 0; i < top; i++)
        {
            cout << " (   " << stack[i].row << ",   " << stack[i].col << ") ";
            if ((i + 1) % 6 == 0)
                cout << endl;
        }
        cout << " (   " << row << ",   " << col << ") ";
        cout << " (   " << EXIT_ROW << ",   " << EXIT_COL << endl;
    }

    else
        cout << "The maze does not have a path" << endl;
}

void add(int* top, element item)
{
    if (*top >= 255)
    {
        stack_full();
        return;
    }

    stack[++(*top)] = item;
}

element del(int* top)
{
    if (*top == -1)
        return stack_empty();
    return stack[(*top)--];
}

void stack_full()
{
    fprintf(stderr, "Stack is full\n");
}

element stack_empty()
{
    element item;
    item.col = -1;
    item.dir = -1;
    item.row = -1;
    fprintf(stderr, "Stack is empty\n");

    return item;
}
