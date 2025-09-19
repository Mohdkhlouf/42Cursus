#include "easyfind.hpp"
#include <vector>
#include <queue>

void vector_test(){
    {
        std::cout<<"Int Vector case 1\n";
        std::vector<int> int_vec={1,2,3,4,5,6};
        std::cout<<"result: "<<*easyfind(int_vec, 5)<<std::endl;
        int_vec.push_back(10);
        std::cout<<"result: "<<*easyfind(int_vec, 10)<<std::endl;
    }

    {
        std::cout<<"Char Vector case 2\n";
        std::vector<char> char_vec={'a','b','c'};
        std::cout<<"Vector members:{";
        for (char c:char_vec){
            std::cout<<"'"<<c<<"'";
        }
        std::cout<<"}\n";
        std::cout<<"result when (b): "<<*easyfind(char_vec, 'b')<<std::endl;
        char_vec.push_back('d');
        std::cout<<"result wne (d): "<<*easyfind(char_vec, 'd')<<std::endl;
    }

    {
        std::cout<<"Char Vector case 3\n";
        const std::vector<char> char_vec={'a','b','c'};
        std::cout<<"Vector members:{";
        for (char c:char_vec){
            std::cout<<"'"<<c<<"'";
        }
        std::cout<<"}\n";
        std::cout<<"result when (b): "<<*easyfind(char_vec, 'b')<<std::endl;
        std::cout<<"result wne (d): "<<*easyfind(char_vec, 'd')<<std::endl;
    }


}


void queue_test(){
    std::queue<int> q;
    q.push(10);

}

int main(){
    try{
        vector_test();
        queue_test();
        return (0);
    }catch (const value_not_found &e){
        std::cout<<"Error: "<<e.what()<<std::endl;
    }


	return (0);
}
