
public class Manager {

    public static final String NORTH = "N";
    public static final String SOUTH = "S";
    public static final String EAST = "E";
    public static final String WEST = "O";

    private RobotII[] lista;
    private static final int SIZE = 100;
    private int numslots;

    public Manager() {

        numslots = 0;

        lista = new RobotII[SIZE];

    }

    public void CreateRobot(int InX, int InY) {

        lista[numslots] = new RobotII(InX, InY, numslots);
        numslots++;

    }

    public int CountRobots() {

        return numslots;

    }

    public boolean CallRobot(int id) {
        boolean present = false;

        for (int i = 0; i < numslots; i++) {

            if (lista[i].getId() == id) {

                present = true;
            } else {

            }
        }
        return present;
    }

    public int setHeadingRemote(String heading, int id) {

        lista[id - 1].setHeading(heading.toUpperCase());

        if(!heading.toUpperCase().equals(NORTH)&&!heading.toUpperCase().equals(SOUTH)&&!heading.toUpperCase().equals(EAST)&&!heading.toUpperCase().equals(WEST)){
            return 1;
        }
        else{
            return 0;
        }

    }

    public String GetHeadingRemote(int id) {

        return lista[id - 1].GetHeading();
    }

    public int DistanceBetweenBotsRemote(int id1, int id2) {
        /*
         * return(int)Math.round(Math.sqrt(Math.pow((this.getXPos()-r1.getXPos()),2)+
         * Math.pow((this.getYPos()-r1.getYPos()),2)));
         */
        return Math.abs(lista[id1 - 1].getXPos() - lista[id2 - 1].getXPos())
                + Math.abs(lista[id1 - 1].getYPos() - lista[id2 - 1].getYPos());

    }

    public int compareLargestDistanceRemote(int id1, int id2) {

        if (lista[id1 - 1].getLargestDistance() > lista[id2 - 1].getLargestDistance()) {

            return id1;
        } else if (lista[id1 - 1].getLargestDistance() < lista[id2 - 1].getLargestDistance()) {

            return id2;
        } else {

            return 0;
        }

    }

    public int getLargestDistanceRemote(int id) {
        return lista[id - 1].getLargestDistance();

    }

    public int getPIDistanceRemote(int id) {
        /*
         * return(int)Math.round(Math.sqrt(Math.pow((this.getXPos()-markedX),2)+Math.pow
         * ((this.getYPos()-markedY),2)));
         */
        return Math.abs(lista[id - 1].getXPos() - lista[id - 1].getMarkedX())
                + Math.abs(lista[id - 1].getYPos() - lista[id - 1].getMarkedY());
    }

    /*
     * public void moveRemote(int distance,int id){
     * 
     * lista[id-1].move(distance);
     * 
     * }
     */

    public void markRemote(int id) {

        lista[id - 1].mark();
    }

    public int getXPosRemote(int id) {

        return lista[id - 1].getXPos();
    }

    public int getYPosRemote(int id) {

        return lista[id - 1].getYPos();
    }

    public int getTotalDistanceRemote(int id) {
        return lista[id - 1].getTotalDistance();
    }

    public int getMarkedXRemote(int id) {

        return lista[id - 1].getMarkedX();
    }

    public int getMarkedYRemote(int id) {

        return lista[id - 1].getMarkedY();
    }

    public int CompareDistanceRemote(int id1, int id2) {

        if (lista[id1 - 1].getTotalDistance() > lista[id2 - 1].getTotalDistance()) {

            return id1;
        } else if (lista[id1 - 1].getTotalDistance() < lista[id2 - 1].getTotalDistance()) {

            return id2;
        } else {

            return 0;
        }

    }

    public void moveRemote(int id, int distance) {

        switch (lista[id - 1].GetHeading()) {
        case NORTH:
            lista[id - 1].SetY(distance);
            lista[id - 1].setTotalDistance(distance);
            if (distance > lista[id - 1].getLargestDistance()) {
                lista[id - 1].setLargestDistance(distance);
            } else {

            }
            break;
        case SOUTH:

            lista[id - 1].SetY(-distance);
            lista[id - 1].setTotalDistance(distance);
            if (distance > lista[id - 1].getLargestDistance()) {
                lista[id - 1].setLargestDistance(distance);
            } else {

            }
            break;
        case WEST:

            lista[id - 1].SetX(-distance);
            lista[id - 1].setTotalDistance(distance);
            if (distance > lista[id - 1].getLargestDistance()) {
                lista[id - 1].setLargestDistance(distance);
            } else {

            }
            break;
        case EAST:

            lista[id - 1].SetY(distance);
            lista[id - 1].setTotalDistance(distance);
            if (distance > lista[id - 1].getLargestDistance()) {
                lista[id - 1].setLargestDistance(distance);
            } else {

            }
            break;
        }
    }

}
