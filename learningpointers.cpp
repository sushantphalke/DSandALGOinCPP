#include <iostream>
using namespace std;

void increment(int pointVar){
   pointVar++;
};
int main() {
    int var = 5;
    int* pointVar = &var;
     

    // store address of var
    pointVar = &var;

    // print var
    cout << "var = " << var << endl;

    // print *pointVar
    cout << "*pointVar = " << *pointVar << endl
       << endl;

    cout << "Changing value of var to 7:" << endl;

    // change value of var to 7
    var = 7;

    // print var
    cout << "var = " << var << endl;

    // print *pointVar
    cout << "*pointVar = " << *pointVar << endl
         << endl;

    cout << "Changing value of *pointVar to 16:" << endl;

    // change value of var to 16
    *pointVar = 16;

    // print var
    cout << "var = " << var << endl;
    cout << "&var16 = " << &var << endl;

    cout << "*pointVar = " << *pointVar << endl;
    *pointVar = 34;

    cout << "var : " << var << endl;
    cout << "&var34 : " << &var << endl;
    cout << "*pointVar = "<< *pointVar << endl;
    cout << "*pointVar = "<< &*pointVar << endl;
    
    var =33;
     cout << "var : " << var << endl;
     cout << "*pointVar = "<< *pointVar << endl;
    cout << "*pointVar = "<< &*pointVar << endl;

    int s = 2 ;
    int*sptr = &s;
    cout << *sptr<<"this is the value for s"<<endl;
    cout << "pointer address to increment : "<< &*sptr<<endl;
    sptr++;
    cout <<" pointer address after increment : "<<&*sptr<<endl;

    pointVar--;
    cout << "*pointVar = "<< &pointVar << endl;
    cout <<" pointer address after increment : "<<*sptr<<endl;


    return 0;

   

}