class taskIterator{
    task* internalArray;
    int sizeOfArray,nextSlot;

public:
    taskIterator(int size,task *array){
        sizeOfArray=size;
        internalArray=array;
        nextSlot=0;
    }
    task next(){

        task s;

        if(hasNext()){
            s=internalArray[nextSlot];
            nextSlot++;
        }
        return s;


    }
    bool hasNext(){
        return nextSlot<sizeOfArray;
    }
    int getSlot(){
        return nextSlot;
    }

};