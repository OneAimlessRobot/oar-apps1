public class Manager {
    private RightSequence numbersToGuess;
    private Telepata infj;
    private int lengthOfNumberList;

    public Manager(int a) {
        lengthOfNumberList = a;

        infj = new Telepata(lengthOfNumberList);
        numbersToGuess = new RightSequence(lengthOfNumberList);

    }

    public Iterator normalPersonSequenceIterator() {

        Iterator remoteCursor = numbersToGuess.iterator();
        return remoteCursor;
    }

    public Iterator telepathSequenceIterator() {
        Iterator memoryOfTelepath = infj.iterator();
        return memoryOfTelepath;
    }

    public void addNumberToSequenceRemote(int a) {
        numbersToGuess.addNumberToSequence(a);
    }

    public void checkGuesses() {
        for (int i = 0; i < lengthOfNumberList; i++) {
            if (infj.getImaginedNumberByIndex(i) == numbersToGuess.getNumberByIndex(i)) {
                numbersToGuess.setNumberToGuessed(i);
            } else {

            }
        }
    }

    public int[] giveScoreToPlayer() {

        for (int i = 0; i < lengthOfNumberList; i++) {

            if (i < lengthOfNumberList - 1 && i > 0) {
                if (numbersToGuess.acessSlotByIndex(i).isGuessed()) {
                    if (numbersToGuess.acessSlotByIndex(i + 1).isGuessed()
                            || numbersToGuess.acessSlotByIndex(i - 1).isGuessed()) {
                        infj.guessNumber(3);
                    } else {
                        infj.guessNumber(1);
                    }
                }
            } else if (i == 0) {
                if (numbersToGuess.acessSlotByIndex(i).isGuessed()) {
                    if (numbersToGuess.acessSlotByIndex(i + 1).isGuessed()) {
                        infj.guessNumber(3);
                    } else {
                        infj.guessNumber(1);
                    }
                }
            } else {
                if (numbersToGuess.acessSlotByIndex(i).isGuessed()) {
                    if (numbersToGuess.acessSlotByIndex(i - 1).isGuessed()) {
                        infj.guessNumber(3);
                    } else {
                        infj.guessNumber(1);
                    }
                }

            }
        }
        return infj.getScore();
    }

    public int[] playGame() {
        this.checkGuesses();
        return this.giveScoreToPlayer();
    }

    public void imagineNewNumberRemote(int a) {

        infj.imagineNewNumber(a);

    }

}
