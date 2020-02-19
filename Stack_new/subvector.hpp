//
//  subvector.hpp
//  Stack_new
//
//  Created by Данила Дудин on 19.02.2020.
//  Copyright © 2020 Данила Дудин. All rights reserved.
//

#ifndef subvector_hpp
#define subvector_hpp

#include "Header.h"
#include <stdio.h>

class subvector : public Stack {
private:
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:
    subvector();
    ~subvector();
    bool push_back(int d);
    int pop_back();
    bool resize (unsigned int new_capacity);
    void shrink_to_fit ();
    void clear ();
    void Printer();
    int get_top();
    int get_capacity();
};

#endif /* subvector_hpp */
