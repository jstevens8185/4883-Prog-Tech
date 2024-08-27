#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int T;
    int a;
    int b;
    int sum = 0;
    cin >> T;
    while(T--){
        cin >> a;
        cin >> b;
        for (int i = a;  i <= b; i++){
            if(i % 2 != 0){
                sum += i;
            }
        }
        cout << "Case : " << sum << endl;
    }

    // ifstream fin;
    // fin.open("file");
    // int v;
    // while(!fin.eof()){
    //     fin>>v;
    // }
};
