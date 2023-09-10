import java.util.Scanner;

public class Main {
    
    private static final String MOVER = "MV";
    private static final String MUDARDIRECAO = "MD";
    private static final String PONTOINTERESSE = "PI";
    private static final String CURRENT = "LP";
    private static final String TOTAL = "LDT";
    private static final String DISTANCIAPONTOINTERESSE = "LDPI";
    private static final String LOCALIZACAOPONTOINTERESSE = "LPI";
    private static final String CURRENTHEADING = "CH";
    private static final String MENU = "MENU";
    private static final String COMPARARTOTAL = "DTMAX";
    private static final String DELTAR = "DR";
    private static final String COMPARARMV = "LMV";
    private static final String SAIR = "S";
    private static final String CRIAR = "CR";
    private static final String SEEBOTS = "LOG";

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Scanner in2;

        Manager mgr=new Manager();

        int a=in.nextInt();
        int b=in.nextInt();
        int c=in.nextInt();
        int d=in.nextInt();

        mgr.CreateRobot(a,b);
        mgr.CreateRobot(c,d);

        String state;
        do{
            state=menu(in,mgr);

        }while(!state.equals(SAIR));

    }

   /* private static RobotII CreateBot(Manager mgr,Scanner in) {

        int a = in.nextInt();
        int b = in.nextInt();
        RobotII r1=mgr.CreateRobot(a,b);

        return r1;

    }*/

    private static String menu(Scanner in,Manager mgr) {

        String option=in.next();
        int target,target1,target2;

        switch(option){

            case MOVER:
            target=in.nextInt();
            int dist = in.nextInt();
            if(mgr.CountRobots()<1){
                System.out.printf("Ainda não criaste robots nenhuns!\n");
            }
            else if(target>mgr.CountRobots()){
    
                System.out.printf("Esse robot não existe\n");
            }
            else if(target<1){
                System.out.println("Robot inválido.");
            }
            else if(dist<1){
                System.out.printf("Distância inválida.");
            }
            else{
            mgr.moveRemote(target,dist);
            }
            break;
            case MUDARDIRECAO:
            target=in.nextInt();
            String a=mgr.GetHeadingRemote(target);
            if(mgr.CountRobots()<1){
                System.out.printf("Ainda não criaste robots nenhuns!\n");
            }
            else if(target>mgr.CountRobots()){
    
                System.out.printf("Esse robot não existe\n");
            }
            else if(target<1){
                System.out.println("Robot inválido.");
            }
            else{
            String heading=in.next();
            if(mgr.setHeadingRemote(heading, target)==1){
                System.out.printf("Direção inválida.\n");
                mgr.setHeadingRemote(a, target);
            }
            else{
                mgr.setHeadingRemote(heading, target);
            }
            }
            break;
            case PONTOINTERESSE:
            target=in.nextInt();
            if(mgr.CountRobots()<1){
                System.out.printf("Ainda não criaste robots nenhuns!\n");
            }
            else if(target>mgr.CountRobots()){
    
                System.out.printf("Esse robot não existe\n");
            }
            else{
            mgr.markRemote(target);
            }
            break;
            case CURRENT:
            target=in.nextInt();
            if(mgr.CountRobots()<1){
                System.out.printf("Ainda não criaste robots nenhuns!\n");
            }
            else if(target>mgr.CountRobots()){
    
                System.out.printf("Esse robot não existe\n");
            }
            else if(target<1){
                System.out.println("Robot inválido.");
            }
            else{
            System.out.printf("%d %d\n",mgr.getXPosRemote(target),mgr.getYPosRemote(target));
            }
            break;
            case TOTAL:
            target=in.nextInt();
            if(mgr.CountRobots()<1){
                System.out.printf("Ainda não criaste robots nenhuns!\n");
            }
            else if(target>mgr.CountRobots()){
    
                System.out.printf("Esse robot não existe\n");
            }
            else if(target<1){
                System.out.println("Robot inválido.");
            }
            else{
            System.out.printf("%d\n",mgr.getTotalDistanceRemote(target));
            }
            break;
            case DISTANCIAPONTOINTERESSE:
            target=in.nextInt();
            if(mgr.CountRobots()<1){
                System.out.printf("Ainda não criaste robots nenhuns!\n");
            }
            else if(target>mgr.CountRobots()){
    
                System.out.printf("Esse robot não existe\n");
            }
            else if(target<1){
                System.out.println("Robot inválido.");
            }
            else{
            System.out.printf("%d\n",mgr.getPIDistanceRemote(target));
            }
            break;
            case LOCALIZACAOPONTOINTERESSE:
            target=in.nextInt();
            if(mgr.CountRobots()<1){
                System.out.printf("Ainda não criaste robots nenhuns!\n");
            }
            else if(target>mgr.CountRobots()){
    
                System.out.printf("Esse robot não existe\n");
            }
            else if(target<1){
                System.out.println("Robot inválido.");
            }
            else{
            System.out.printf("%d %d\n",mgr.getMarkedXRemote(target),mgr.getMarkedYRemote(target));
            }
            break;
            case CURRENTHEADING:
            target=in.nextInt();
            if(mgr.CountRobots()<1){
                System.out.printf("Ainda não criaste robots nenhuns!\n");
            }
            else if(target>mgr.CountRobots()){
    
                System.out.printf("Esse robot não existe\n");
            }
            else if(target<1){
                System.out.println("Robot inválido.");
            }
            else{
            System.out.printf("%s\n",mgr.GetHeadingRemote(target));
            }
            break;/*
            case MENU:
            printmenu();
            break;
            */
            case COMPARARTOTAL:
            /*target1=in.nextInt();*/
            /*
            target2=in.nextInt();*/
            /*if(mgr.CountRobots()<2){
                System.out.printf("Precisas de criar pelo menos 2 robots para esta operacao\n");
            }*/
            /*if(target1>mgr.CountRobots())/*||target2>mgr.CountRobots()){

                System.out.printf("Um dos Robots não existe\n");
            }
            else if(target1>mgr.CountRobots())/*&&target2>mgr.CountRobots()){

                System.out.printf("Nenhum dos Robtos existe\n");
            }
            else{*/
                if(mgr.CompareDistanceRemote(1, 2)==0){
                    System.out.printf("EMPATE\n");
                }
                else{
                    System.out.printf("ROBOT %d\n",mgr.CompareDistanceRemote(1, 2));
                }

            
            break;
            case DELTAR:/*
            target1=in.nextInt();
            target2=in.nextInt();
            if(mgr.CountRobots()<2){
                System.out.printf("Precisas de criar pelo menos 2 robots para esta operacao\n");
            }
            if(target1>mgr.CountRobots()||target2>mgr.CountRobots()){

                System.out.printf("Um dos Robots não existe\n");
            }
            else if(target1>mgr.CountRobots()&&target2>mgr.CountRobots()){

                System.out.printf("Nenhum dos Robtos existe\n");
            }*/
                if(mgr.DistanceBetweenBotsRemote(1, 2)==0){
                    System.out.printf("EMPATE\n");
                }
                else{

            System.out.printf("ROBOT %d\n",mgr.DistanceBetweenBotsRemote(1, 2));
                }
            
            break;
            case COMPARARMV:/*
            target1=in.nextInt();
            target2=in.nextInt();
            if(mgr.CountRobots()<2){
                System.out.printf("Precisas de criar pelo menos 2 robots para esta operacao\n");
            }
            if(target1>mgr.CountRobots()||target2>mgr.CountRobots()){

                System.out.printf("Um dos Robots não existe\n");
            }
            else if(target1>mgr.CountRobots()&&target2>mgr.CountRobots()){

                System.out.printf("Nenhum dos Robtos existe\n");
            }*/
                if(mgr.compareLargestDistanceRemote(1, 2)==0){
                    System.out.printf("EMPATE\n");
                }
                else{

            System.out.printf("ROBOT %d\n",mgr.compareLargestDistanceRemote(1, 2));
                }
            
            break;
            case SAIR:
            break;
            /*
            case CRIAR:
            int xbot = in.nextInt();
            int ybot = in.nextInt();
            mgr.CreateRobot(xbot,ybot);
            break;
            
            case SEEBOTS:
            printbots(mgr);
            break;
            */
            default:
            System.out.printf("Comando inválido.\n");
            break;
        }
        return option/*.toUpperCase()*/;





       
    }
    /*
    private static void printmenu() {

        System.out.printf("CR- Parir um robot\nMV-Mover robot\nMD-Mudar direcao de robot\nPI-Marcar ponto atual\nLP-Indicar localizacao atual de robot\nLDT-Indicar distancia total percorrida por robot\nCH- Indica a direcao atual de robot\nLDPI-Indicar distancia ao ultimo ponto de interesse marcado\nLPI-Indicar a localizacao do ultimo ponto de interesse marcado\nDR-Distancia entre robots (arredondada)\nDTMAX-Qual deles percorreu maior distancia ate agora?\nLMV-Qual deles fez o maior movimento unico?\nLOG- Ver que robots criaste\nMENU-Mostrar menu de novo\n");
    }

  private static void printbots(Manager mgr){

        for(int i=0;i<mgr.CountRobots();i++){

            System.out.printf("O id deste robot é %d e está nas coordenadas (%d,%d) e tem orientação %s\n",i+1,mgr.getXPosRemote(i+1),mgr.getYPosRemote(i+1),mgr.GetHeadingRemote(i+1));
        }
    }*/

}
/*.toUpperCase() tenho de estruturar os menus de forma diferente. O mooshak vai inserir "MV" sem ser so em maiusculas e o meu programa vai pensar que e um comando e vai voltar ao inicio impriminto "comando invalido" depois vai ler o 3 e vai pensar que e outro comando e dizer "comando invalido" e ler o 5 e dizer "comando invalido"*/