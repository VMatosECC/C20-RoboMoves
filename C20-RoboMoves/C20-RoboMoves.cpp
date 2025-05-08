// C20-RoboMoves.cpp 

#include <iostream>
using namespace std;

int robotCounter(int r, int c, int TROW, int TCOL)
{
    //Base case
    if (r == TROW - 1 || c == TCOL - 1) {
        return 1;
    }

    //General recursion
    int horizontal = robotCounter(r, c + 1, TROW, TCOL);
    int vertical = robotCounter(r + 1, c, TROW, TCOL);
    return (horizontal + vertical);
}



void experiment01()
{
    int TROW = 2;
    int TCOL = 3;
    int count = robotCounter(0, 0, TROW, TCOL);
    cout << "Total number of paths is " << count << endl;
}
//----------------------------------------------------------------

void printPaths(int r, int c, int TROW, int TCOL, string path)
{
    //Base case
    if (r == TROW - 1 && c == TCOL - 1) {
        cout << path << endl;
        return;
    }

    //General recursion
    if (c < TCOL - 1)
        printPaths(r, c + 1, TROW, TCOL, path + "R");

    if (r < TROW - 1)
        printPaths(r + 1, c, TROW, TCOL, path + "D");

    if (r < TROW - 1 && c < TCOL - 1)
        printPaths(r + 1, c + 1, TROW, TCOL, path + "\\");

}


void experiment02()
{
    int TROW = 3;
    int TCOL = 3;
    string path = "";
    printPaths(0, 0, TROW, TCOL, path);
}



int main()
{
    //experiment01();     //count moves from source to destination
    experiment02();     //print the paths to destination
    cout << "\nAll done!\n";
}

