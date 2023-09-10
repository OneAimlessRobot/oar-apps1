import java.util.*;
import java.io.*;

public class Tournament {

    private Game[] array;
    private int tournamentSize, currentSlot;

    public Tournament(String filename) throws FileNotFoundException {
        try {
            FileReader fread = new FileReader(filename);
            Scanner in = new Scanner(fread);

            currentSlot = 0;

            tournamentSize = in.nextInt();
            array = new Game[tournamentSize];

            GameIterator it = this.iterator();
            while (it.hasNext()) {
                Game r = it.next();
                int length = in.nextInt(), width = in.nextInt(), goal = in.nextInt();
                in.nextLine();

                r = new Game(length, width, goal, currentSlot+1);

                for (int y = 0; y < length; y++) {
                    String row = in.nextLine();
                    for (int x = 0; x < width; x++) {

                        char piece = row.charAt(x);

                        r.addPieceRemote(y, x, piece);
                    }
                }

                array[currentSlot++] = r;

            }
            in.close();
        } catch (FileNotFoundException e) {

            System.out.printf("Ficheiro nao encontrado\n");

        }
    }

    public GameIterator iterator() {
        return new GameIterator(tournamentSize, this.array);
    }

}
