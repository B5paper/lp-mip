#include <iostream>
#include <vector>
#include "linopt.h"
using namespace std;

int main()
{
    // max. z = x_1 + 14 x_2 + 6 x_3
    // s.t.
    // x_1 + x_2 + x_3 <= 4
    // x_1 <= 2
    // x_3 <= 3
    // 3 x_2 + x_3 <= 6
    // x_1, x_2, x_3 >= 0

    vector<vector<float>> A({{1, 1, 1}, {1, 0, 0}, {0, 0, 1}, {0, 3, 1}});
    vector<float> b({4, 2, 3, 6});
    vector<float> c({1, 14, 6});
    LP lp(A, b, c);
    linpro(lp);
    if (lp.feasible)
    {
        cout << "max obj: " << lp.max_val << endl;
        cout << "vars: ";
        for (auto &x: lp.x)
            cout << x << "  ";
        cout << endl;
    }
    else
    {
        cout << "unfeasible" << endl;
    }

    cout << endl;

    // max. z = x + y + 2z
    // s.t.
    // 7x + 2y + 3z <= 36
    // 5x + 4y + 7z <= 42
    // 2x + 3y + 5z <= 28
    // x, y, z >= 0
    A.clear();
    b.clear();
    c.clear();
    A = {{7, 2, 3}, {5, 4, 7}, {2, 3, 5}};
    b = {36, 42, 28};
    c = {1, 1, 2};
    float max_val;
    vector<int> solu = branch_and_cut_max(A, b, c, max_val, INT32_MAX);
    if (!solu.empty())
    {
        cout << "max obj: " << max_val << endl;
        cout << "vars: ";
        for (auto &x: solu)
            cout << x << "  ";
        cout << endl;
    }
    
    return 0;
}