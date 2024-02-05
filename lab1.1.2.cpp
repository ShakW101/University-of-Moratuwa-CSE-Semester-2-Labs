#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int data[2];
    for(int i = 0; i <2; i++){
        cin >> data[i];
    }

    for(int i = data[0]; i <= data[1]; i++){
        if(i >= 1 and i <= 9){
            //a switch case will be easier than a long line of if else if statements
            switch(i){
                case 1:
                    cout<<"one"<<endl;
                    break;
                case 2:
                    cout<<"two"<<endl;
                    break;
                case 3:
                    cout<<"three"<<endl;
                    break;
                case 4:
                    cout<<"four"<<endl;
                    break;
                case 5:
                    cout<<"five"<<endl;
                    break;
                case 6:
                    cout<<"six"<<endl;
                    break;
                case 7:
                    cout<<"seven"<<endl;
                    break;
                case 8:
                    cout<<"eight"<<endl;
                    break;
                case 9:
                    cout<<"nine"<<endl;
                    break;
                
            }
        
        }else if(i %2 == 0){
            cout << "even" << endl;
        }else{
            cout << "odd" << endl;
        }
    }

    return 0;
}
