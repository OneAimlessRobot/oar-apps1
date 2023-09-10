import java.util.Scanner;

public class Main {

    public static void main(String[] args){

        Scanner in=new Scanner(System.in);

        int a=in.nextInt();
       Gestor mgr=new Gestor(a);
        for(int i=0;i<a;i++){

            int costOfItem=in.nextInt();
            in.nextLine();
            String c=in.nextLine();
            mgr.addItemToListRemote(c,costOfItem);
            
        }
        int b=in.nextInt();
        mgr.putMoneyOnCoupon(b);
        int[] resultsOfPurchase=mgr.buyItemsRemote();

        int maior=mgr.lookForMostExpensiveRemote();
        if(resultsOfPurchase[2]!=0){
        System.out.printf("%s\n%d %d\n",mgr.getLabelFromItemRemote(maior),resultsOfPurchase[0],resultsOfPurchase[1]);
        }
        else{
        System.out.printf("%d %d\n",resultsOfPurchase[0],resultsOfPurchase[1]);
        }

        
        in.close();

        
    }
    
}
