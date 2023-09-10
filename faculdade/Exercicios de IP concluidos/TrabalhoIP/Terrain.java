public class Terrain {

    private static final int MAX_SIZE=100;
    private static final int NO_PRIZE = 0;
    private int currentSlot;
    private int availableSpace;
    private Slot[] terreno;

    public Terrain(int size){
        availableSpace=size+1;
        currentSlot=0;

        terreno = new Slot[availableSpace];
        terreno[currentSlot]=new Slot(NO_PRIZE);




    }

    public void addTreasureToSlot(int prize) {

        if (prize > 0) {

            terreno[currentSlot] = new Slot(prize);
            currentSlot++;
        } else {

            terreno[currentSlot] = new Slot(NO_PRIZE);
            currentSlot++;

        }

    }
    
}
