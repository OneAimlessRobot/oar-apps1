import java.util.Scanner;

public class Main {

    private static final int NO_TREASURE = 0;
    private static final String TREASURE_SONAR = "riqueza";
    private static final String TERRAIN_SONAR = "terreno";
    private static final String JUMP = "escavacao";
    private static final String EXIT = "sair";
    private static final String GET_MERIT = "merito";
    private static final String GET_POS = "posicao";
    private static final String PLAYER_KICKED_ANNOUNCEMENT = "perdeu a licenca de escavacao";
    private static final String PLAYER_KICKED_EXEPTION = "Arqueologo desclassificado";
    private static final String INVALID_JUMP = "Salto invalido";
    private static final String NO_SUCH_PLAYER = "Arqueologo inexistente";
    private static final String BOTH_KICKED = "Correu mal! Foram ambos desclassificados.";
    private static final String TREASURE_REMAINING = "Ainda havia tesouros por descobrir...";
    private static final String TREASURE_IS_GONE = "Todos os tesouros foram descobertos!";

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        String exitCheck;
        String nome1 = in.nextLine();

        String nome2;
        do {
            nome2 = in.nextLine();
            if (nome2.equals(nome1)) {
                System.out.printf("Escolhe um nome diferente do primeiro\n");
            }
        } while (nome2.equals(nome1));
        int size = in.nextInt();

        Brains sys = new Brains(nome1, nome2, size);

        for (int i = 0; i < size; i++) {
            int a = in.nextInt();
            sys.addTreasureToSlot(a);
        }
        do {

            exitCheck = menu(sys, in);

        } while (!exitCheck.equals(EXIT));
        in.close();
    }

    private static String menu(Brains sysaux, Scanner in) {
        String state = "";
        String option = in.next();

        if (option.equals(TERRAIN_SONAR)) {

            printTerrainStatus(sysaux);

        } else if (option.equals(TREASURE_SONAR)) {

            System.out.printf("Riqueza enterrada: %d\n", sysaux.getTotalTreasure());

        } else if (option.equals(JUMP)) {
            String Nome = in.next();
            int distance = in.nextInt();
            int log = sysaux.dig(Nome, distance);
            if (log == 0) {
                System.out.printf("%s\n", INVALID_JUMP);
            } else if (log == -1) {
                System.out.printf("%s\n", PLAYER_KICKED_ANNOUNCEMENT);
            } else if (log == -2) {
                System.out.printf("%s\n", PLAYER_KICKED_EXEPTION);
            } else if (log == -3) {
                System.out.printf("%s\n", NO_SUCH_PLAYER);
            } else {

            }
        } else if (option.equals(EXIT)) {

            if (sysaux.countKickedPlayers() < 2) {
                if (sysaux.getTotalTreasure() == 0) {
                    System.out.printf("%s\n", TREASURE_IS_GONE);

                } else {
                    System.out.printf("%s\n", TREASURE_REMAINING);
                }
            } else {

                System.out.printf("%s\n", BOTH_KICKED);

            }

            state = EXIT;

        } else if (option.equals(GET_MERIT)) {
            String nome = in.next();
            int merit = sysaux.getMeritRemote(nome);
            if (merit == -3) {
                System.out.printf("%s\n", NO_SUCH_PLAYER);
            } else if (merit == -1) {
                System.out.printf("%s\n", PLAYER_KICKED_EXEPTION);
            } else {
                System.out.printf("Merito de %s: %d\n", nome, merit);
            }

        } else if (option.equals(GET_POS)) {
            String nome = in.next();
            int position = sysaux.getPlayerPosRemote(nome);
            if (position < 0) {
                if (position == -3) {
                    System.out.printf("%s\n", NO_SUCH_PLAYER);
                } else {
                    System.out.printf("%s\n", PLAYER_KICKED_EXEPTION);
                }
            } else {
                System.out.printf("Posicao de %s: %d\n", nome, position);
            }
        }

        else {
            System.out.printf("Comando inválido.\n");
        }
        return state;
    }

    private static void printTerrainStatus(Brains sys) {

        for (int i = 1; i < sys.getAvailableSpace(); i++) {

            if (sys.getSlotStatusRemote(i) == NO_TREASURE) {
                System.out.printf("-");
            } else {

                System.out.printf("*");
            }
        }
        System.out.printf("\n");

    }

    /*
     * private static void printmenu() {
     * 
     * System.out.printf(
     * "Commandos:\nriqueza - Ver quanta riqueza há ainda por descobrir\nterreno - Fazer um raio x do terreno\nescavacao - Forcar um arqueologo a fazer uma escavacao\nmerito - ver o merito atual de um arqueologo\nposicao - ver a posicao atual de um arqueologo\nsair - Sair\n"
     * ); }
     */

}
