#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

std::vector<unsigned> two_opt(
        std::vector<unsigned> vect,
        const int &i, const int &j) {

    std::vector<unsigned> newVect;
    newVect.insert(newVect.end(), vect.begin(), vect.begin() + (i ));

    std::vector<unsigned> middlePart(vect.begin() + i, vect.begin() + (j ));
    std::reverse(middlePart.begin(), middlePart.end());
    newVect.insert(newVect.end(), middlePart.begin(), middlePart.end());

    newVect.insert(newVect.end(), vect.begin() + j, vect.end());

    return newVect;
}

int main() {

    std::vector<unsigned> myVect;
    for(unsigned i =0 ; i<6;i++){
        myVect.push_back(i);
    }
    unsigned i = 1;
    unsigned j = myVect.size() - 1;

    auto newVecter = two_opt(myVect,3,4);
    for(unsigned i=0;i<newVecter.size();i++){
        std::cout<<newVecter[i]<<" "<<std::endl;
    }
    
//    std::cout<<std::thread::hardware_concurrency()<<std::endl;


    return 0;
}