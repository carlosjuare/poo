#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    int num[30];
    int b=0;
    srand(time(nullptr));
    for (int i = 0; i < 30; ++i) {
        num[i] = rand() % 15 + 1;

    }
    do{
        cout<<num[b]<<endl;
        b++;
    }while(b < 30);

    return 0;
}
