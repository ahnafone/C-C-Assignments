#include <iostream>
#include <vector>

using namespace std;
#include "WordCount.h"

int main()
{
    WordCount wc;
    std::string str;

    cout << "Enter line:" << endl;
    getline(cin, str);
    wc.breakString(str);

    wc.print();

    return 0;
}
