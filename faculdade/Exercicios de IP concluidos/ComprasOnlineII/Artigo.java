public class Artigo {

    private String description;
    private int price;
    private boolean sold;

    public Artigo(String name, int cost){

        description=name;
        price=cost;
        sold=false;
    }

    public boolean getItemStatus(){
        return this.sold;
    }
    public void setToBought(){

        this.sold=true;
    }
    public boolean isBought(){

        return this.sold;
    }
    public String getItemLabel(){
        return this.description;
    }
    public int getCost(){
        return this.price;
    }
    public int CompareTo(Artigo anotha){
        return this.getCost()-anotha.getCost();
    }

    
    
}

