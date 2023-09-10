public class Iterator {
    private int nextSlot;
    private int numOfSlots;
    private Slot[] internalArray;
    public Iterator(Slot array[],int size){

        this.nextSlot=0;
        this.numOfSlots=size;
        internalArray=array;

        
    }
    public boolean hasNext(){

        return this.nextSlot<this.numOfSlots;
    }
    public Slot next(){

        return internalArray[nextSlot++];



    }
}
