public class GameIterator {

    private Game[] internalArray;
    private int size, currentSlot;

    public GameIterator(int size, Game[] array) {

        currentSlot = 0;
        this.internalArray = array;
        this.size = size;
    }

    public boolean hasNext() {

        return this.currentSlot < this.size;

    }

    public Game next() {
        Game r = null;
        if (this.hasNext()) {
            r = internalArray[currentSlot++];
        }
        return r;
    }

}
