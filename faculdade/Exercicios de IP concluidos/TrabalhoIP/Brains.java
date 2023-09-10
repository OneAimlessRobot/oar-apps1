public class Brains {

    private static final int MAX_PLAYERS = 2;
    private static final int PENALTY_CONSTANT = 10;
    private static final int STARTING_MERIT = 0;
    private static final int STARTING_POINT = 0;

    private static Arqueologo[] playersList = new Arqueologo[MAX_PLAYERS];
    private int currentSlot;
    private int availableSpace;
    private Slot[] terreno;

    /*
     * Esta é a classe com a qual a main vai comunicar. Só e somente com esta. E
     * esta comunica com o resto.
     */

    public Brains(String nome1, String nome2, int terrainSize) {
        currentSlot=0;
        playersList[0] = new Arqueologo(nome1, STARTING_MERIT, STARTING_POINT);
        playersList[1] = new Arqueologo(nome2, STARTING_MERIT, STARTING_POINT);
        availableSpace = terrainSize + 1;
        terreno = new Slot[availableSpace];
        terreno[currentSlot] = new Slot(0);
        currentSlot++;

    }
    /* Este método é só para teste e vai devolver o nome do arqueologo */

    public String getNameRemote(int target) {

        return playersList[target - 1].getPlayerName();

    }

    public int getMeritRemote(int target) {

        return playersList[target - 1].getPlayerMerit();

    }

    public void addTreasureToSlot(int prize) {

        if (prize > 0) {

            terreno[currentSlot] = new Slot(prize);
            currentSlot++;
        } else {

            terreno[currentSlot] = new Slot(0);
            currentSlot++;

        }

    }

    public int getSlotStatusRemote(int slot) {

        return terreno[slot].getSlotStatus();
    }

    public int getAvailableSpace() {

        return this.availableSpace;
    }

    public int getSlotTreasureRemote(int slot) {
        return terreno[slot].getSlotTreasure();

    }

    public int getTotalTreasure() {

        int sum = 0;
        for (int i = 0; i < availableSpace; i++) {
            if (terreno[i].getSlotStatus() == 1) {
                sum += terreno[i].getSlotTreasure();

            } else {

            }

        }
        return sum;

    }

    public int dig(String identificacao, int jumpLength) {
        int i;
        int logstatus;
        int exists=0;

        for (i = 0, logstatus = 313232;i < MAX_PLAYERS; i++) {
            if(identificacao.equals(playersList[i].getPlayerName())){
                exists++;
                if (!playersList[i].isKicked()) {
                    if (jumpIsWithinBounds(playersList[i], jumpLength)) {

                        if (jumpLength == 0) {

                            logstatus = 0;
                        } 
                        else {

                            playersList[i].movePlayer(jumpLength);

                            if (!terreno[playersList[i].getPlayerPos()].wasPreviouslyDug()) {
                                collectPrize(playersList[i], terreno[playersList[i].getPlayerPos()]);
                            } 
                            else {
                                applyPenalty(playersList[i], terreno[playersList[i].getPlayerPos()]);
                            }
                        }
                    } 
                    else {

                        playersList[i].kickPlayer();
                        logstatus = -1;
                    }
                } else {

                    logstatus = -2;
                }
            }
        }
        if(exists==0){
            logstatus=-3;
        }
        return logstatus;
    }

    public int getMeritRemote(String alias) {
        int value = 0;
        int exists=0;
        for (int i = 0;i < MAX_PLAYERS; i++) {
            if(alias.equals(playersList[i].getPlayerName())){
                exists++;
                if (!playersList[i].isKicked()) {
                    value = playersList[i].getPlayerMerit();
                } else {
                    value = -1;
                }
            }
        }
        if(exists==0){
            value=-3;
        }
        return value;
    }

    public int countKickedPlayers() {
        int sum = 0;
        for (int i = 0; i < MAX_PLAYERS; i++) {

            if (playersList[i].isKicked()) {
                sum++;
            } else {

            }
        }
        return sum;
    }

    public int getPlayerPosRemote(String reference) {
        int pos = 0;
        int exists=0;
        for (int i = 0;i < MAX_PLAYERS; i++) {
            if(reference.equals(playersList[i].getPlayerName())){
                exists++;
                if (!playersList[i].isKicked()) {
                    pos = playersList[i].getPlayerPos();
                } else {
                    pos = -1;
                }
            }
        }
        if(exists==0){
            pos=-3;
        }
        return pos;
    }

    public boolean jumpIsWithinBounds(Arqueologo jose, int dist) {

        return jose.getPlayerPos() + dist > STARTING_POINT && jose.getPlayerPos() + dist <= this.getAvailableSpace();
    }
    /*
     * Este metodo roda sempre 2. Why? No ***ing idea... Pelo menos ja sei que salta
     * para os slots certos. UPDATE!!! NAO E DESTE METODO. E DO METODO DIG!!!!
     */

    public void collectPrize(Arqueologo maria, Slot hole) {
        maria.addMerit(hole.getSlotTreasure());
        hole.removeTreasure();
        hole.setToDug();
        hole.addPenaltyFactor();

    }

    public void applyPenalty(Arqueologo eva, Slot covaDaIria) {

            eva.addMerit(-1*PENALTY_CONSTANT * covaDaIria.getPenaltyFactor());
            covaDaIria.addPenaltyFactor();
        

    }


    public int getPenaltyFactorRemote(int i) {

        return terreno[i].getPenaltyFactor();
    }
    public int getMaxPlayers(){
        return MAX_PLAYERS;
    }
}

/*
 * Ok, Agora o proximo passo e fazer com que um slot "memorize" o arqueologo que
 * o escavou para que, quando esse arqueologo voltar a tentar escavar esse slot,
 * que o slot o castigue por o tentar escavar. Todos os talhoes funcionam de
 * forma igual.
 */
