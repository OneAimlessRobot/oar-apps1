public class Main{

    public static void main(String[] args){
    Lamp lamp1=new Lamp();
    Lamp lamp2=new Lamp();

    lamp1.TurnOn();
    System.out.println(lamp1.IsOn());
    System.out.println(lamp2.IsOn());
    lamp2.TurnOn();
    System.out.println(lamp2.IsOn());


    }
}