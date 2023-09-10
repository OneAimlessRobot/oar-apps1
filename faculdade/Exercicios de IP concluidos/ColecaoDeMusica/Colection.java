public class Colection {

    private static final int DEFAULT_SIZE=100;
    private Record[] collection;
    private int nextSlot,sizeOfCollection,recordCount;

    public Colection(){
        sizeOfCollection=DEFAULT_SIZE;
        nextSlot=0;
        recordCount=0;
        collection= new Record[sizeOfCollection];
    }

    public void addRecord(String author, String title, int year){

        if(isFull()){
            grow();
        }

        collection[nextSlot++]=new Record(author,title,year);
        recordCount++;
    }
    public boolean isFull(){

        return nextSlot==sizeOfCollection;
    }

    public void grow(){

        int oldsize=sizeOfCollection;

        Record[] auxList=new Record[sizeOfCollection*=2];

        for(int i=0;i<oldsize;i++){

            auxList[i]=collection[i];

        }

        collection=auxList;
    }
    public void sortThisList(){

        for(int i=0;i<recordCount-1;i++){

            for(int j=0;j<recordCount-i;j++){

                if(collection[j].compareRecords(collection[j+1])>0){

                    Record aux=collection[j];
                    collection[j]=collection[j+1];
                    collection[j+1]=aux;


                }
                else{

                }

            }
        }

    }

    public void sort(Record[] sample,int n){

        for(int i=0;i<n;i++){

            for(int j=0;j<n-i-1;j++){

                if(sample[j].compareRecords(sample[j+1])>0){

                    Record aux=sample[j];
                    sample[j]=sample[j+1];
                    sample[j+1]=aux;


                }
                else{

                }

            }
        }

    }
    public ColectionIterator iterator(){

        return new ColectionIterator(recordCount,collection);


    }
    public ColectionIterator sortedIterator(){

    Record[] aux= new Record[recordCount];

    for(int i=0;i<recordCount;i++){

        aux[i]=this.collection[i];


    }

    sort(aux,recordCount);
    return new ColectionIterator(recordCount,aux);
}



public FilteredIterator filteredIterator(String c){

    return new FilteredIterator(collection,recordCount,c);

}

public int searchForAlbum(String author,String title){

    int result=0;

    for(int i=0;i<recordCount;i++){

        if(collection[i].getAuthor().equals(author)&&collection[i].getTitle().equals(title)){

            result=1;
            
        }
        else{

        }
    }
    return result;
}

public int getCollectionSize(){
    return this.recordCount;
}

    
}
