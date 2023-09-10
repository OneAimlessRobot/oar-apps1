public class ColectionIterator {

    private Record[] internalArray;
    private int nextSlot,size;

    public ColectionIterator(int size,Record[] array){
        this.size=size;
        internalArray=array;
        nextSlot=0;
    }

    public boolean hasNext(){

        return this.nextSlot<size;
    }

    public Record next(){

        Record k=null;

        if(hasNext()){

        k=internalArray[nextSlot++];
        }
        return k;
    }
    
}
