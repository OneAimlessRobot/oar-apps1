public class Player {

    private char fromThisPlayer;
    private int id;

    public Player(char c, int id) {

        fromThisPlayer = c;
        this.id = id;
    }

    public char getPlayerChar() {

        return fromThisPlayer;
    }

    public int getId() {
        return this.id;
    }
}
