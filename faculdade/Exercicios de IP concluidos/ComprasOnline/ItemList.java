public class ItemList {

    private static final int MAX_SIZE= 100;
    private int size;
    private int currentSlot;
    private Artigo[] items;

    public ItemList(int numOfItems){

    size=numOfItems;
    currentSlot=0;
    items=new Artigo[size];
    }

    public int getPriceFromItem(int index){

        return items[index].price;
    }

    public void addItemToList(String name,int price){

        items[currentSlot]=new Artigo(name,price);
        currentSlot++;

    }
    public String getLabelFromItem(int index)
    {
        return items[index].description;
    }
    public int getItemCostByIndex(int index){
        return items[index].getCost();
    }
    public int registerBuy(int index){
        return 1;
    }
    public Artigo acessItemFromIndex(){
        return items[currentSlot];
    }
    public int lookForMostExpensive(){

        
        int i,maxValue,emBranco;
        for(i=0,maxValue=0,emBranco=0;i<size;i++){
            if(items[i].isBought()){
            if(items[i].getCost()>maxValue){


                maxValue=items[i].getCost();
                emBranco=i;
            }
            else{

            }
        }
        else{

        }

        }
        return emBranco;
    }
    public int getStatusFromItem(int index){

        return items[index].getItemStatus();
    }
    public int[] buyItems(Coupon vale){

        int[] output= new int[3];
        int sum=0;
        int howMany=0;
        for(int i=0;i<size;i++){

            if(items[i].getCost()<=vale.getCouponValue()){

                vale.deductValue(items[i].getCost());
                sum+=items[i].getCost();
                howMany++;
                items[i].setToBought();
            }
            else{

            }
        }
        output[0]=sum;
        output[1]=vale.getCouponValue();
        output[2]=howMany;
        return output;
    }
}
