//
//  Header.h
//  Stack_new
//
//  Created by Данила Дудин on 19.02.2020.
//  Copyright © 2020 Данила Дудин. All rights reserved.
//

#ifndef Header_h
#define Header_h

class Stack{
public:
    virtual int pop_back() = 0;
    virtual bool push_back(int d) = 0;
    virtual void clear() {};
};

#endif /* Header_h */
