#include <iostream>
#include <vector>
#include "PointSorter.h"

using namespace std;

int main()
{
    int n;
    double x, y, a, b;
    PointSorter ps;

    cout << "Please enter the number of coordinates to be entered: ";
    cin >> n;
    cout << "Enter the numbers..." << endl;
    cin >> a >> b;  //First numbers
    for (int i = 1; i < n; i++) {   //loop n-1 times
        cin >> x >> y;
        ps.add_point(x, y);
    }
    cout << endl << "Output:" << endl;
    ps.print_sorted_closest_to(a, b);

    return 0;
}
