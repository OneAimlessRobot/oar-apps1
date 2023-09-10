public class Slot {
    /*Acrescentei isto para tornar o codigo um bocadinho mais claro.Nao e substancial mas ajuda (pelo menos a mim) */
    private static final int VALID=1;
    private static final int DUG=0;

    private int treasure, status,penaltyFactor;

    public Slot(int value){
        if(value>0){

            status=VALID;
            treasure=value;
            penaltyFactor=0;



        }
        else{

            status=DUG;
            treasure=0;
            penaltyFactor=0;
        }
    }

    public void addPenaltyFactor(){


        penaltyFactor++;





    }

    public boolean wasPreviouslyDug(){

        return penaltyFactor>0;
    }

    public int getPenaltyFactor(){
        return this.penaltyFactor;
    } 

    public int getSlotStatus(){
        return this.status;
    }
    public int getSlotTreasure(){
        return this.treasure;
    }
    public void removeTreasure(){

        this.treasure=0;
    }

    public void setToDug(){

        this.status=DUG;
    }
    
}
