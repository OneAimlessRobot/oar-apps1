#include<iostream>
#include<limits>
#include<string>


std::string func(){
std::string name;
        while(!(std::cin>>name)){

            std::cout<<"falhei\n";
            std::cin.ignore(1000000000,'\n');
        }

        return name;

}
int main(){

        int a,b,c,d;
        std::cout<<"mete a\n";
        std::cin>>a;
        std::cout<<"mete b\n";
        std::cin>>b;
        std::cout<<"mete c\n";
        std::cin>>c;
        std::cout<<"mete d\n";
        std::cin>>d;

        std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<" \n";


        for(int i=0;i<4;i++){

            std::cout<<"success\n";
        }



        std::cout<<func()<<" \n";

        return 0;


}
