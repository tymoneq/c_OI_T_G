#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ofstream w;
    w.open("daneC.txt");

    srand(time(NULL));

    int n = 10000;
    for(int i = 0; i < n; i++)
    {
        int a = rand() % 2000 - 1000;
        int b = rand() % 2000 - 1000;
        w << a << " " << b;
        w << '\n';
    }
    w.close();
return 0;
}
