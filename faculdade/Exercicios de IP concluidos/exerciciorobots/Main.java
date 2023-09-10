import java.util.Scanner;

public class Main {
    private static final String MOVER = "MV";
    private static final String MUDARDIRECAO = "MD";
    private static final String PONTOINTERESSE = "PI";
    private static final String CURRENT = "LP";
    private static final String TOTAL = "LDT";
    private static final String DISTANCIAPONTOINTERESSE = "LDPI";
    private static final String LOCALIZACAOPONTOINTERESSE = "LPI";
    /*private static final String CURRENTHEADING = "CH";*/
    /*private static final String MENU = "MENU";*/
    private static final String COMPARARTOTAL = "DTMAX";
    /*
    private static final String DELTAR = "DR";
    private static final String COMPARARMV = "LMV";*/

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Robot r1 = CreateRobot(in);
        Robot r2 = CreateRobot(in);
        /*
        printmenu();*/
            menu(r1, r2, in);
            menu(r1, r2, in);
            menu(r1, r2, in);
            menu(r1, r2, in);
            menu(r1, r2, in);

    }

    private static Robot CreateRobot(Scanner in) {

        int a = in.nextInt();
        int b = in.nextInt();

        Robot r1 = new Robot(a, b);
        return r1;

    }

    private static void menu(Robot r1, Robot r2, Scanner in) {

        String option = in.next();

        switch (option.toUpperCase()) {

        case CURRENT:

        int id = in.nextInt();
            switch (id) {
            case 1:
                System.out.printf("%d %d\n", r1.getXPos(), r1.getYPos());
                break;
            case 2:
                System.out.printf("%d %d\n", r2.getXPos(), r2.getYPos());
                break;
            }
            break;
        case MOVER:

        id = in.nextInt();
            switch (id) {
            case 1:
                int a = in.nextInt();
                r1.move(a);
                break;
            case 2:
                int c = in.nextInt();

                r2.move(c);

            }

            break;
        case MUDARDIRECAO:

        id = in.nextInt();
            switch (id) {
            case 1:
                String b = in.next();

                r1.setHeading(b.toUpperCase());
                break;
            case 2:
                String d = in.next();

                r2.setHeading(d.toUpperCase());
                break;
            }

            break;
        case PONTOINTERESSE:

        id = in.nextInt();
            switch (id) {
            case 1:
                r1.mark();
                break;
            case 2:
                r2.mark();
                break;
            }

            break;
        case TOTAL:

        id = in.nextInt();
        switch(id){
            case 1:
            int j = r1.getTotalDistance();
            System.out.printf("%d\n", j);
            break;
            case 2:
            int k = r2.getTotalDistance();
            System.out.printf("%d\n", k);
            break;
        }

            break;
            
        case DISTANCIAPONTOINTERESSE:

        id = in.nextInt();
        switch(id){
            case 1:
            int f = r1.getPIDistance();
            System.out.printf("%d\n", f);
            break;
            case 2:
            int g = r2.getPIDistance();
            System.out.printf("%d\n", g);
            break;

        }

            break;
        case LOCALIZACAOPONTOINTERESSE:

        id = in.nextInt();
        switch(id){
            case 1:
            System.out.printf("\n%d %d\n", r1.getMarkedX(), r1.getMarkedY());

            break;
            case 2:
            System.out.printf("\n%d %d\n", r2.getMarkedX(), r2.getMarkedY());
            break;

        }
        break;/*
        case CURRENTHEADING:

        id = in.nextInt();
        switch(id){
            case 1:
            System.out.printf("\n%s\n", r1.GetHeading());
            break;
            case 2:
            System.out.printf("\n%s\n", r2.GetHeading());
            break;
        }

            break;
        case MENU:

            printmenu();

            break;*/
        case COMPARARTOTAL:

        int k=r1.CompareDistance(r2);
            if(k==0){

                System.out.printf("ROBOT 1\n");
            }
            else if(k==1){

                System.out.printf("ROBOT 2\n");
            }
            else if(k==2){

                System.out.printf("EMPATE\n");
            }
            else{

            }


            break;/*
            case DELTAR:
            System.out.printf("%d\n",r1.DistanceBetweenBots(r2));
            break;
            case COMPARARMV:
            k=r1.compareLargestDistance(r2);

            if(k==0){

                System.out.printf("ROBOT 1\n");
            }
            else if(k==1){

                System.out.printf("ROBOT 2\n");


            }
            else if(k==2){

                System.out.printf("EMPATE\n");


            }
            else{

            }
            break;*/

        }
    }
/*
    private static void printmenu() {

        System.out.printf(
                "MV-Mover robot\nMD-Mudar direcao de robot\nPI-Marcar ponto atual\nLP-Indicar localizacao atual de robot\nLDT-Indicar distancia total percorrida por robot\nLDPI-Indicar distancia ao ultimo ponto de interesse marcado\nLPI-Indicar a localizacao do ultimo ponto de interesse marcado\nDR-Distancia entre robots (arredondada)\nDTMAX-Qual deles percorreu maior distancia ate agora?\nLMV-Qual deles fez o maior movimento unico?\nMENU-Mostrar menu de novo\n");
    }

}*/
}