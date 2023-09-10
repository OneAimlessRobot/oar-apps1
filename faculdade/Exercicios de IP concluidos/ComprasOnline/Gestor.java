public class Gestor {

    private int numOfItems;
    private int valueOfCoupon;
    private Coupon k;
    private int countBought;
    ItemList list;

    public Gestor(int number){
        numOfItems=number;

        list=new ItemList(numOfItems);
    }

    public void putMoneyOnCoupon(int value){

        k=new Coupon(value);
    }
    public void addItemToListRemote(String label,int requiredMoney){

        list.addItemToList(label, requiredMoney);
    }
    public int getPriceFromItemRemote(int index){

        return list.getPriceFromItem(index);
    }
    public String getLabelFromItemRemote(int index){

        return list.getLabelFromItem(index);

    }
    public int getStatusFromItemRemote(int index){
        return list.getStatusFromItem(index);
    }
    public int[] buyItemsRemote(){

        int[] l=list.buyItems(k);
        return l;


    }
    public int lookForMostExpensiveRemote(){
        return list.lookForMostExpensive();
    }
    
}
