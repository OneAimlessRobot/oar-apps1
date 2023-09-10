public class Ticket {

    private static final double CRIANCA = 0;
    private static final double FRESH = 16;
    private static final double BASE = 20;
    private static final int HIGHERAGEBOUND = 65;
    private static final int LOWERAGEBOUND = 5;
    private int ticketPrice;
    private static final double SENIORDISC = 0.5;
    private int age;
    private boolean isFirstYear;

    public Ticket(int idade, boolean primeiroAno) {

        age=idade ;
        isFirstYear= primeiroAno ;
    }

    public int getPrice() {

        if (isFirstYear) {

            if (age < LOWERAGEBOUND) {

                ticketPrice =  (int) Math.round(CRIANCA);

            } else if (age > HIGHERAGEBOUND) {

                ticketPrice = (int) Math.round(FRESH * SENIORDISC);
            } else {
                ticketPrice =(int) Math.round(FRESH);
            }

        } else {
            if (age < LOWERAGEBOUND) {

                ticketPrice =  (int) Math.round(CRIANCA);

            } else if (age > HIGHERAGEBOUND) {

                ticketPrice = (int) Math.round(BASE * SENIORDISC);
            } else {
                ticketPrice =(int) Math.round(BASE);
            }
        }

        return ticketPrice;
    }
}
