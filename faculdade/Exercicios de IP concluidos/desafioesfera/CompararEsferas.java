import java.util.Scanner;

public class CompararEsferas {
    private static final String VOLUME = "V";
    private static final String SURFACEAREA = "S";
    private static final String LOCATION = "LP";
    private static final String SPHERELOCATION = "LS";
    private static final String EXIT= "ESC";
    private static final int CLOSE = 999999999;
    private static int i;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        for(int j=0;j<4;j++){
        Sphere s1 = CreateSphere(input);
        Sphere s2 = CreateSphere(input);
        Point p1 = CreatePoint(input);
        input.nextLine();
        PrintMenu();
        String s = Option(input);
        j=Menu(s,s1,p1,s2);
        }

        input.close();

    }

    private static Sphere CreateSphere(Scanner in) {

        System.out.printf("Insere aqui 4 numeros: o x, o y e o z do centro e o raio da esfera\n(neste formato:\"x y z raio\"(sem aspas))\n:");
        double a = in.nextDouble();
        double b = in.nextDouble();
        double c = in.nextDouble();
        double d = in.nextDouble();
        if(d<=0){

            System.out.printf("O raio não pode ser 0 nem menor que 0. A definir valor default para o raio que é 1.\n");
            d=1;
            
        }
        Sphere s1 = new Sphere(a, b, c, d);
        System.out.printf("Esfera criada. Tem raio %f e o centro tem coordenadas (%f,%f,%f)\n", d, a, b, c);
        return s1;
    }

    private static Point CreatePoint(Scanner in) {

        double a = in.nextDouble();
        double b = in.nextDouble();
       double c = in.nextDouble();
        Point p1 = new Point(a, b, c);
        System.out.printf("Ponto Criado. Tem coordenadas (%f,%f,%f)", a, b, c);
        return p1;
    }

    private static String Option(Scanner input) {

        String s=input.next();
        String S=s.toUpperCase();
        return S;

    }

    private static int Menu(String s, Sphere s1, Point p1,Sphere s2) {

        switch(s){
            case VOLUME:
            {
                PrintVolume(s1);
                break;
            }
            case SURFACEAREA:{
                PrintSurfaceArea(s1);
                break;
            }
            case LOCATION:{

                PrintPointLocation(s1, p1);
                break;
            }
            case SPHERELOCATION:{

                PrintSphereLocation(s1, s2);
                break;
            }
            case EXIT:{

                i= CLOSE;
            }
            default:{
                break;
            }

        }
        return i;
    }

    private static void PrintMenu() {

        System.out.printf("\n%s - Volume da esfera\n%s - Àrea de superficie da esfera\n%s - Localização do ponto em relação á esfera\n%s - Localização de outra esfera em relação a esta\n%s - Sair\n",VOLUME,SURFACEAREA,LOCATION,SPHERELOCATION,EXIT);
    }

    private static void PrintVolume(Sphere s1) {

        double v = s1.GetVolume();
        System.out.println(v);
    }

    private static void PrintSurfaceArea(Sphere s1) {

        double SArea = s1.GetSurfaceArea();
        System.out.println(SArea);
    }

    private static void PrintPointLocation(Sphere s1, Point p1) {

        boolean location = s1.GetPointLocation(p1);
        if(location){
            System.out.println("\n"+location +"\n"+ "(Ou seja, o ponto pertence)");
        }
        else{
        System.out.println("\n"+location +"\n"+ "(Ou seja, algures fora da esfera)");
        }
    }
    private static void PrintSphereLocation(Sphere s1, Sphere s2) {

        int location = s1.GetSphereLocation(s2);
        if(location==1){
            System.out.println("As esferas intersetam-se");
        }
        else if(location==2){
        System.out.println("A primeira esfera contem a segunda");
        }
        else if(location==3){
        System.out.println("A segunda esfera contem a primeira");
        }

        else if(location==4){
            System.out.println("As esferas nem se intersetam");
            }
    }

}