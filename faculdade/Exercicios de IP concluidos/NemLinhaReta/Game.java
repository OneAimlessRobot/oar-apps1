public class Game {
    private Board internalBoard;
    private BoardCalculator calc;
    private int numPlayers, goal, currentPlayerId, gameId;
    private Player[] competitors;

    public Game(int rows, int cols, int n, int gameId) {
        currentPlayerId = 1;
        internalBoard = new Board(rows, cols);
        calc = new BoardCalculator(internalBoard);
        this.numPlayers = 2;
        competitors = new Player[numPlayers];
        competitors[0] = new Player('o', currentPlayerId++);
        competitors[1] = new Player('x', currentPlayerId++);
        this.gameId = gameId;
        this.goal = n;

    }

    public void addPieceRemote(int y, int x, char piece) {

        internalBoard.addPiece(y, x, piece);
    }

    public int getLengthRemote() {
        return internalBoard.getLength();
    }

    public int getWidthRemote() {
        return internalBoard.getWidth();
    }

    public char getPieceAtRemote(int y, int x) {
        return internalBoard.getPieceAt(y, x);
    }

    public int countPiecesFromPlayer(Player r) {

        int sum = 0;
        for (int y = 0; y < internalBoard.getLength(); y++) {
            for (int x = 0; x < internalBoard.getWidth(); x++) {

                if (internalBoard.getPieceAt(y, x) == r.getPlayerChar()) {
                    sum++;
                }

            }
        }
        return sum;
    }

    public int playGame() {

        int result;
        if (calc.playerWins(competitors[0], goal)
                && calc.playerWins(competitors[1], goal)) {

            result = 0;
        } else if (!calc.playerWins(competitors[0], goal)
                && !calc.playerWins(competitors[1], goal)) {
            result = 0;
        } else if (!calc.playerWins(competitors[0], goal)
                && calc.playerWins(competitors[1], goal)) {
            result = 2;
        } else {
            result = 1;
        }

        return result;
    }

    public int getGameId() {
        return this.gameId;
    }

}
