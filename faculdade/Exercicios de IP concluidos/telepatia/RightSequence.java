public class RightSequence{

    private int numberOfDigits;
    private Slot[] digits;
    private int currentSlot;
    public RightSequence(int lengthOfSequence){

        numberOfDigits=lengthOfSequence;
        currentSlot=0;
        digits= new Slot[numberOfDigits];
    }

    public Iterator iterator(){

        Iterator cursor=new Iterator(digits,numberOfDigits);
        return cursor;
    }

    public void addNumberToSequence(int a){

        digits[currentSlot++]=new Slot(a);

    }
    public int getNumberByIndex(int index){
        return this.digits[index].getNumber();
    }
    public void setNumberToGuessed(int index){
        digits[index].setToGuessed();
    }
    public Slot acessSlotByIndex(int index){
        return this.digits[index];
    }




}
