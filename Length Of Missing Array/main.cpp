//  main.cpp
//  Length Of Missing Array
//
//  Created by Didier Lessage on 11/17/19.
//  Copyright © 2019 Didier Lessage. All rights reserved.
//
/*
 You get an array of arrays.
 If you sort the arrays by their length, you will see, that their length-values are consecutive.
 But one array is missing!


 You have to write a method, that return the length of the missing array.
 
 If the array of arrays is null/nil or empty, the method should return 0.

 When an array in the array is null or empty, the method should return 0 too!
 There will always be a missing element and its length will be always between the given arrays.

 Have fun coding it and please don't forget to vote and rank this kata! :-)

 I have created other katas. Have a look if you like coding and challenges.
 */

#include <iostream>
#include <vector>
#include <set>

template<class TYPE>
int getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays)
{
    //If passed in vector is empty, return 0
    if(arrayOfArrays.size() == 0)
        return 0;

    std::set<size_t> sizes;

    //Begin inserting elements of vector into a sorted container
    //(NOTE: A sort algorithm could also be used here, the question is inserting into
    //a set and having two containers less efficient than sorting one container
    //.....probably
    for (auto it : arrayOfArrays)
    {
        auto size = it.size();
        if(size == 0) //If any of the passed in vectors are empty/null, return 0
            return 0;
        
        sizes.insert(size);
    }
    
    //Start from smallest size, as this is guaranteed to be the lower bounds
    auto missingSize = (*sizes.begin());
    for(auto it : sizes)
    {
        if(it == missingSize)
            missingSize++;
        else
            break; //Break as soon as we reach a missing size when increasing
    }
    
    return missingSize;
}

int main(int argc, const char * argv[]) {
    std::cout << getLengthOfMissingArray(std::vector<std::vector<int>> { { 1, 2 }, { 4, 5, 1, 1 }, { 1 }, { 5, 6, 7, 8, 9 } }) << '\n';
    
    std::cout << getLengthOfMissingArray(std::vector<std::vector<int>> { { 5, 2, 9 }, { 4, 5, 1, 1 }, { 1 }, { 5, 6, 7, 8, 9 } }) << '\n';
    
    std::cout << getLengthOfMissingArray(std::vector<std::vector<char>> { { 'a', 'a', 'a' }, { 'a', 'a' }, { 'a', 'a', 'a', 'a' }, { 'a' }, { 'a', 'a', 'a', 'a', 'a', 'a' } }) << '\n';
    return 0;
}
