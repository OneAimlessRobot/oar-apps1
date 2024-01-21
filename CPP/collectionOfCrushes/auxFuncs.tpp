
template<typename T>
T AuxFuncs::randItemFromList(std::set<T>& vec){

int pos=(int) getRandomFloat(0,vec.size()),counter=0;
typename std::set<T>::iterator it;
for(it=vec.begin();(counter++)!=pos;it++){



}
return (*it);




}
