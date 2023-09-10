import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);

        int a=in.nextInt();
        Manager mgr= new Manager(a);
        askForSequence(mgr,a,in);
        registerMagicianGuessAttempts(mgr, a, in);
        int[] b=mgr.playGame();
        System.out.printf("%d\n%d\n",b[1],b[0]);


    }

    public static void askForSequence(Manager mgr,int a,Scanner in){

        for (int i=0;i<a;i++) {

            int b=in.nextInt();
            mgr.addNumberToSequenceRemote(b);

            
        }
    }
    public static void registerMagicianGuessAttempts(Manager mgr,int a,Scanner in){
        for(int i=0;i<a;i++){
            int b=in.nextInt();
            mgr.imagineNewNumberRemote(b);
        }
    }
    
}
