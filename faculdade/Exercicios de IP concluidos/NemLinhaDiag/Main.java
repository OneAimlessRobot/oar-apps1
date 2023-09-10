import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {

        Scanner in = new Scanner(System.in);

        String filename = in.nextLine();

        Tournament h = new Tournament(filename);
        GameIterator it = h.iterator();

        while (it.hasNext()) {
            Game r = it.next();
            int result = r.playGame();
            if (result == 1 || result == 2) {
                System.out.printf("Jogo %d: ganhou o jogador %d\n", r.getGameId(), result);
            } else {
                System.out.printf("Jogo %d: empate\n", r.getGameId());
            }
        }
        in.close();

    }
}