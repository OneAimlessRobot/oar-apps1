public class Telepata {
    private int score, currentSlot,sizeOfSequence,numOfGuesses;
    private Slot[] estimatedSequence;

    public Telepata(int length){
        score=0;
        sizeOfSequence=length;
        currentSlot=0;
        numOfGuesses=0;
        estimatedSequence=new Slot[sizeOfSequence];
    }
    public void guessNumber(int gain){
        this.score+=gain;
        numOfGuesses++;
    }
    public int[] getScore(){
        int[] output=new int[2];
        output[0]=this.score;
        output[1]=this.numOfGuesses;
        return output;
    }
    public void imagineNewNumber(int a){

        estimatedSequence[currentSlot++]=new Slot(a);
    }
    public Iterator iterator(){
        Iterator memory=new Iterator(estimatedSequence,sizeOfSequence);
        return memory;
    }
    public int getImaginedNumberByIndex(int index){
        return estimatedSequence[index].getNumber();
    }



    
}
