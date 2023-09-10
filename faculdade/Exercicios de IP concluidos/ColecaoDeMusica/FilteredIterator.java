public class FilteredIterator{

    private int size,nextSlot;
    private Record[] internalArray;
    private String comparand;

    public FilteredIterator(Record[] array,int size,String comparand){

        this.size=size;
        internalArray=array;
        this.comparand=comparand;
        nextSlot=0;
        skip();
    }

    public boolean hasNext(){

        return this.nextSlot<this.size;
    }

    public Record next(){

        Record k=null;

        if(hasNext()){

            k=internalArray[nextSlot++];
            skip();

        }
        return k;
    }

    public void skip(){

        while(hasNext()&& !criterion(internalArray[nextSlot])){
            nextSlot++;
        }

    }

    private boolean criterion(Record r){

        return r.getAuthor().equals(comparand);

    }




    
}
