public class Slot {
    private int numberToGuess;
    private boolean guessed=true;

    public Slot(int number){

        numberToGuess=number;
        guessed=false;


    } 
    public int getNumber(){
        return this.numberToGuess;
    }
    public void setToGuessed(){
        this.guessed=true;
    }
    public boolean isGuessed(){

        return guessed;
    }
}
