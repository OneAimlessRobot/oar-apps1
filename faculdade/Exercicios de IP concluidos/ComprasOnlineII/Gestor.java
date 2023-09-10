public class Gestor {

    private int numOfItems;
    private Coupon k;
    private itemList list;

    public Gestor(int number){
        numOfItems=number;


        list=new itemList(numOfItems);
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
    public int[] buyItemsRemote(){

        int[] l=list.buyItems(k);
        list.LeBubbleSortOfItemes();
        return l;


    }
    public boolean checkStatusRemote(int index){

        return list.acessItemInMainListNo(index).isBought();

    }
    public int lookForMostExpensiveRemote(){
        return list.lookForMostExpensiveItem();
    }

    
    public int countBoughtItemsRemote(){
        return list.countBoughtItems();
    }

    public String printItemInReceitNo(int index){

        return list.acessBoughtItemNo(index).getItemLabel();
    }


    
}

