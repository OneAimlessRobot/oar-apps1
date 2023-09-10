#include<iostream>
#include<math.h>
#include<time.h>
#include<string>
#include<vector>
#include<fstream>
#include "../headers/trimAString.h"
#include "../headers/bibliography.h"
#include"../headers/header1.h"

std::string func(phraseVector list,std::string msg);

int main(){

	phraseVector list=getValidLinesFromFile(std::string("videos"));

		std::string rolled=func(list,"prime n para uma categoria de videos aleatória");
		
		if(!(rolled==std::string("racecategories"))){
			return 0;
		}
		list=getValidLinesFromFile(std::string("videoTypes/raceTypes"));
		
		
		rolled= "videoTypes/racecategories/"+func(list,"prime n para uma categoria de corridas aleatória");
		phraseVector secondList=getValidLinesFromFile(rolled);
		
		func(secondList,"prime n para uma opção aleatória");


return 0;

}

std::string func(phraseVector list,std::string msg){


    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    srand((time_t)ts.tv_nsec);

		for(std::string str : list){
			std::cout<<trim(str)<<"\n";
		}
		char option;
		std::cout<<msg<<"\n";
		std::cin>>option;
		if(option=='n'){
		std::string brand=list[randNumBetZeroAnd(list.size() - 1)];

		std::cout<<trim(brand)<<"\n";
		return brand;

		}
		return std::string("");
}




