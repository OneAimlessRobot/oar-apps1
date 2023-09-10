#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

int main(){
    std::vector<int> vec={1,2,3,4,5,6,7};
    for(int i:vec){
        std::cout<<i<<std::endl;
    }
    std::ifstream stream("Ola.txt")
}