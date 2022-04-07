//
//  main.cpp
//  ambition
//
//  Created by Tae Keun Jeong on 19.05.21.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <thread>

void hello()
{
    std::cout << " Hello " << std::endl;
}

void world()
{
    std::cout << " World . " << std::endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...

    // create scope to execute multiple times
    // TODO: call with two new threads

    std::thread t1(hello);
    std::thread t2(world);
        
    t1.join();
    t2.join();

    // TODO: join the threads with the main thread
        
        return 0;
}
