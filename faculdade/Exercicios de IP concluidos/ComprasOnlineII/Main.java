import java.util.Scanner;

public class Main {

    public static void main(String[] args){

        Scanner in=new Scanner(System.in);

        int numOfPurchases=in.nextInt();
       Gestor mgr=new Gestor(numOfPurchases);

       sendPurchaseRequest(in, mgr, numOfPurchases);
        int b=in.nextInt();
        mgr.putMoneyOnCoupon(b);
        int[] purchaseResults=mgr.buyItemsRemote();
        printItems(mgr);
        System.out.printf("%d %d\n",purchaseResults[0],purchaseResults[1]);

        
        in.close();

        
    }
    public static void printItems(Gestor mgr){

        for(int i=0;i<mgr.countBoughtItemsRemote();i++){

            System.out.printf("%s\n",mgr.printItemInReceitNo(i));
        }
    }

    public static void sendPurchaseRequest(Scanner in,Gestor mgr,int numOfPurchases){

        for(int i=0;i<numOfPurchases;i++){

            int costOfItem=in.nextInt();
            in.nextLine();
            String itemDescription=in.nextLine();
            mgr.addItemToListRemote(itemDescription,costOfItem);
            
        }
    }
    
}
