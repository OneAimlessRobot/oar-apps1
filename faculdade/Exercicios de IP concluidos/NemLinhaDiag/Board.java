public class Board {

    private char[][] board;
    private int cols, rows;

    public Board(int rows, int cols) {

        this.rows = rows;
        this.cols = cols;
        this.board = new char[rows][cols];

    }

    public void addPiece(int y, int x, char piece) {

        board[y][x] = piece;
    }

    public int getWidth() {
        return this.cols;
    }

    public int getLength() {
        return this.rows;
    }

    public char getPieceAt(int y, int x) {
        return board[y][x];
    }

}