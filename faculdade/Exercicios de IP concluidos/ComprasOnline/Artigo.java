public class Artigo {

    public String description;
    public int price;
    public int status;
    private static final int BOUGHT=1;

    public Artigo(String name, int cost){

        description=name;
        price=cost;
        status=0;
    }

    public int getItemStatus(){
        return this.status;
    }
    public void setToBought(){

        this.status=BOUGHT;
    }
    public boolean isBought(){

        return this.status==BOUGHT;
    }
    public String getItemLabel(){
        return this.description;
    }
    public int getCost(){
        return this.price;
    }

    
    
}
