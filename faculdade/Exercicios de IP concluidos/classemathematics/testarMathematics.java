import java.util.Scanner;


public class testarMathematics{

    private static final String FATORIALR = "FACR";
    private static final String FATORIALI = "FACI";
    private static final String SUMSQUARESIT = "SUMI";
    private static final String SUMSQUARESREC = "SUMR";
    private static final String PRIMO = "PRI";
    private static final String PERFECT = "PER";
    private static final String FIRSTNPERFECTS = "FNP";
    private static final String PERFECTSBEFOREN = "PBN";
    private static final String CHECKCOLLATZ = "COL";
    private static final String SAIR = "ESC";
    public static void main(String[] args){

        Scanner in=new Scanner(System.in);
        int a;
        String Escolha;
        

        do{
            printmenu();
            a=EscolherNumero(in);
            Escolha=Escolheropcao(in);
            opcao(a, in, Escolha);

        }while(Escolha.toUpperCase().equals(SAIR)==false);
        in.close();



    }
    private static int EscolherNumero(Scanner in){

        System.out.printf("Escolhe um numero\n:");
        int a=in.nextInt();
        return a;
    } 
    private static String Escolheropcao(Scanner in){

        System.out.printf("Escolhe uma opcao\n:");
        String a=in.next();
        return a;
    }

    private static void printmenu(){

        System.out.printf("FACR-verificar o fatorial do numero escolhido\nFACI-verificar o fatorial do numero escolhido\nPRI-verificar se o numero é primo\nPER-verificar se o numero é perfeito\nSUMI-Somar quadrados(iteração)\nFNP-primeiros n numeros perfeitos\nPBN-Quadrados perfeitos antes de n\nSUMR-Somar quadrados(recursão)\nCOL-Verificar a conjetura de collatz para um dado numero\nESC-Sair\n");
    }

    private static void opcao(int a,Scanner in,String Escolha){

        switch(Escolha.toUpperCase()){

            case FATORIALR:
            int b= Mathematics.FactorialRec(a);
            System.out.println(b);
            break;
            case FATORIALI:
            int c=Mathematics.FactorialIt(a);
            System.out.println(c);
            break;
            case PRIMO:
            boolean d=Mathematics.isPrime(a);
            System.out.println(d);
            break;
            case PERFECT:
            boolean e=Mathematics.isPerfectNumber(a);
            System.out.println(e);
            break;
            case SUMSQUARESIT:
            int f=Mathematics.SumSquaresIt(a);
            System.out.println(f);
            break;
            case SUMSQUARESREC:
            int g=Mathematics.SumSquaresRec(a);
            System.out.println(g);
            case FIRSTNPERFECTS:
            Mathematics.FirstNPerfectNumbers(a);
            break;
            case PERFECTSBEFOREN:
            Mathematics.PerfectNumbersBefore(a);
            break;
            case CHECKCOLLATZ:
            if(a<=0||a>=100000){
                System.out.printf("Numero inválido para esta operação. Escolhe um numero natural inferior a 100000, por favor\n");
            }
            else{
            int h = Mathematics.CollatzIt(a);
            System.out.println(a);
            System.out.println(h);
            }
            break;
            case SAIR:
            break;
            default:
            CommandoInvalido();
            break;

        }



    }
    private static void CommandoInvalido(){

        System.out.printf("Commando Desconhecido\n");
    }
}