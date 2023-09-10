public class BoardCalculator {

    private Board internalBoard;

    public BoardCalculator(Board b) {
        internalBoard = b;
    }

    public boolean playerWinsHorizontal(Player c, int n) {

        int count = 0;
        int max = Integer.MIN_VALUE;
        int numRows = internalBoard.getLength();
        int numCols = internalBoard.getWidth();
        for (int i = 0; i < numRows; i++) {

            for (int j = 0; j < numCols; j++) {

                if (internalBoard.getPieceAt(i, j) == c.getPlayerChar()) {

                    count++;
                }
                if (j < numCols - 1) {
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
                numRows = internalBoard.getLength(),
                numCols = internalBoard.getWidth();
        for (int i = 0; i < numCols; i++) {

            for (int j = 0; j < numRows; j++) {

                if (internalBoard.getPieceAt(j, i) == c.getPlayerChar()) {
                    count++;
                }
                if (j < numRows - 1) {
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

    public int checkOneDiagonal(int startingY, int startingX, char comparand, int n) {

        int count = 0, max = 0, y, x,
        numRows=internalBoard.getLength(),
        numCols=internalBoard.getWidth();
        for (y = startingY, x = startingX; !(y == numRows
                || x == numCols); y++, x++) {

            if (internalBoard.getPieceAt(y, x) == comparand) {

                count++;

            }
            if (y < numRows-1 && x < numCols-1) {
                if (internalBoard.getPieceAt(y + 1, x + 1) != comparand) {
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
        return max;

    }

    public int checkOneInvDiagonal(int startingY, int startingX, char comparand, int n) {

        int count = 0, max = 0, y, x, numRows = internalBoard.getLength();
        for (y = startingY, x = startingX; y < numRows && x > -1; y++, x--) {

            if (internalBoard.getPieceAt(y, x) == comparand) {
                count++;
            }
            if (y < numRows-1 && x > 1) {
                if (internalBoard.getPieceAt(y + 1, x - 1) != comparand) {
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
        return max;
    }

    public boolean playerWinsDiagonal(Player c, int n) {

        int 
        result = 0,
        max = 0,
        numRows=internalBoard.getLength(),
        bottomBound=internalBoard.getLength()-1,
        numCols=internalBoard.getWidth(),
        rightBound=internalBoard.getWidth()-1;
        for (int y = 0; y < numRows; y++) {
            result = checkOneDiagonal(y, 0, c.getPlayerChar(), n);
            if (result > max) {
                max = result;
            }
        }
        for (int x = 0; x < numCols; x++) {
            result = checkOneDiagonal(0, x, c.getPlayerChar(), n);
            if (result > max) {
                max = result;
            }
        }
        for (int y = bottomBound; y > -1; y--) {
            result = checkOneInvDiagonal(y, rightBound, c.getPlayerChar(), n);
            if (result > max) {
                max = result;
            }
        }
        for (int x = rightBound; x > -1; x--) {
            result = checkOneInvDiagonal(0, x, c.getPlayerChar(), n);
            if (result > max) {
                max = result;
            }
        }
        return max >= n;
    }

    public boolean playerWins(Player c, int n) {

        boolean res;

        if (playerWinsHorizontal(c, n) || playerWinsVertical(c, n)
                || playerWinsDiagonal(c, n)) {

            res = true;
        } else {
            res = false;
        }
        return res;

    }
}