// practice4.cpp : This file contains the 'main' function.
#include <string>
#include <vector>

using namespace std;

// assume flashlight F sits at 0,0 on an x,y axis
// point F in the direction given as = U, D, L, or R
// light fans out at 45 degrees from origin in direction specififed                                                                                                                                                                                                              es on either side of axis (y-axis for U/D, y for L/R

int solution(string &direction, int radius, vector<int> &X, vector<int> &Y) {
    // write your code in C++14 (g++ 6.2.0)

    int e = 0;
    for (unsigned int i = 0; i < X.size(); ++i) {
        if (direction == "U") {
            if (Y[i] < 0 || Y[i] > radius ||
                X[i] > radius || X[i] < -radius) {
                continue;
            }

            int rmax = ceil(radius / 2); 
            if (X[i] <= rmax && X[i] >= -rmax)
            {
                if (Y[i] <= rmax) {
                    e++;
                    continue;
                }
                double dist = sqrt((X[i] * X[i]) + (Y[i] * Y[i]));
                if (dist < radius) {
                    e++;
                }
            }
        }
        else if (direction == "D") {
            if (Y[i] > 0 || Y[i] < -radius ||
                X[i] > radius || X[i] < -radius) {
                continue;
            }
            int rmax = ceil(radius / 2);
            if (X[i] <= rmax && X[i] >= -rmax)
            {
                if (Y[i] <= -rmax) {
                    e++;
                    continue;
                }
                double dist = sqrt((X[i] * X[i]) + (Y[i] * Y[i]));
                if (dist < radius) {
                    e++;
                }
            }
        }
        else if (direction == "L") {
            if (X[i] < 0 || X[i] < -radius ||
                Y[i] > radius || Y[i] < -radius) {
                continue;
            }
            int rmax = ceil(radius / 2);
            if (Y[i] <= rmax && Y[i] >= -rmax)
            {
                if (X[i] <= -rmax) {
                    e++;
                    continue;
                }
                double dist = sqrt((X[i] * X[i]) + (Y[i] * Y[i]));
                if (dist < radius) {
                    e++;
                }
            }
        }
        else if (direction == "R") {
            if (X[i] > 0 || X[i] > radius ||
                Y[i] > radius || Y[i] < -radius) {
                continue;
            }
            int rmax = ceil(radius / 2);
            if (Y[i] <= rmax && Y[i] >= -rmax)
            {
                if (X[i] <= rmax) {
                    e++;
                    continue;
                }
                double dist = sqrt((X[i] * X[i]) + (Y[i] * Y[i]));
                if (dist < radius) {
                    e++;
                }
            }
        }
    }

    return e;
}

int main()
{
    vector<int> v1 = { -2, 3 };
    vector<int> v2 = { 0, 1 };
    string d = "R";

    int n = solution(d, 3, v1, v2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
