public class BoardCalculator {

    private Board internalBoard;

    public BoardCalculator(Board b) {
        internalBoard = b;
    }

    public boolean playerWinsHorizontal(Player c, int n) {

        int count = 0;
        int max = Integer.MIN_VALUE;
        int limit = internalBoard.getLength();
        int limit2 = internalBoard.getWidth();
        for (int i = 0; i < limit; i++) {

            for (int j = 0; j < limit2; j++) {

                if (internalBoard.getPieceAt(i, j) == c.getPlayerChar()) {

                    count++;
                }
                if (j < limit2 - 1) {
                    if (internalBoard.getPieceAt(i, j + 1) != c.getPlayerChar()) {
                        if (count > max) {
                            max = count;
                        }
                        count = 0;
                    }
                }
                if (count > max) {
                    max = count;
                }

            }
            count = 0;
        }
        return max >= n;
    }

    public boolean playerWinsVertical(Player c, int n) {

        int count = 0,
                max = Integer.MIN_VALUE,
                limit = internalBoard.getLength(),
                limit2 = internalBoard.getWidth();
        for (int i = 0; i < limit2; i++) {

            for (int j = 0; j < limit; j++) {

                if (internalBoard.getPieceAt(j, i) == c.getPlayerChar()) {
                    count++;
                }
                if (j < limit - 1) {
                    if (internalBoard.getPieceAt(j + 1, i) != c.getPlayerChar()) {
                        if (count > max) {
                            max = count;
                        }
                        count = 0;
                    }
                }
                if (count > max) {
                    max = count;
                }
            }
            count = 0;
        }
        return max >= n;
    }
    public boolean playerWins(Player c, int n) {

        boolean res;

        if (playerWinsVertical(c, n)|| playerWinsHorizontal(c, n)) {

            res = true;
        } else {
            res = false;
        }
        return res;

    }
}