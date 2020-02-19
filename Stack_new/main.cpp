//
//  main.cpp
//  Stack_new
//
//  Created by Данила Дудин on 19.02.2020.
//  Copyright © 2020 Данила Дудин. All rights reserved.
//

#include "subforwardlist.hpp"
#include "subforwardlist.cpp"
#include "Header.h"
#include "subvector.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World! It is a test of subforwardlist"<< endl;
    
    subforwardlist<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_front(446);
    lst.push_front(99999);
    
    /*int number;
    cin>>number;
    for (int i = 0; i < number; i++){
        lst.push_back(rand()%100);
    }*/
    
    lst.removeAt(2);
    
    for (int i = 0; i < lst.get_size(); i++){
        cout<< lst[i] <<endl;
    }
    /*lst.clear();
    
    cout<< lst.get_size() << endl;*/
    
    cout<< "Now lets try subvector" << endl;
    
    subvector Vector1;

    int a;
    for (int i = 0; i < 10; i++){
        cout << "Write to add"<< endl;
        cin>>a;
        if (Vector1.push_back(a)) cout << "push_back True" << endl;
        else {
            cout << "push_back failed" << endl;
            return 0;
        }
    }
    Vector1.Printer();
    cout<<endl;


    cout << "write to delete n members of subvector"<< endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        if (Vector1.pop_back()) cout << "pop_back True" << endl;
        else {
            cout << "pop_back failed" << endl;
            return 0;
        }
    }
    
    Vector1.Printer();
    cout<<endl;


    cout << "Write to resize"<< endl;
    cin >> n;
    if (Vector1.resize(n)) {
        cout << "resize True" << endl;
        Vector1.Printer();
        cout<<endl;
        cout<<"top = "<<Vector1.get_top()<<"\t capacity = "<<Vector1.get_capacity()<<endl;
        }
        else {
            cout << "resize failed" << endl;
            return 0;
        }
    n=0;
    cout << "Write a number that is not equal to 0 to shrink_to_fit"<< endl;
    cin >> n;
    if (n!=0)
    {
        Vector1.shrink_to_fit();
        Vector1.Printer();
    }
    cout<<"top = "<<Vector1.get_top()<<"\t capacity = "<<Vector1.get_capacity()<<endl;

    n=0;
    cout << "Write a number that is not equal to 0 to clear"<< endl;
    cin >> n;
    if (n!=0)
    {
        Vector1.clear();
        Vector1.Printer();
    }
    
    cout<<"top = "<<Vector1.get_top()<<"\t capacity = "<<Vector1.get_capacity()<<endl;

    n=0;
    Vector1.Printer();
    
    Vector1.push_back(999);
    Vector1.Printer();
    
    return 0;
}
