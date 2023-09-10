public class Ticket {

    private static final double CRIANCA = 0;
    private static final double FRESH = 16;
    private static final double BASE = 20;
    private static final int HIGHERAGEBOUND = 65;
    private static final int LOWERAGEBOUND = 5;
    private int ticketPrice;
    private static final double SENIORDISC = 0.5;
    private static final double PROMODISC = 0.5;
    private double age;
    private boolean isFirstYear;
    private int typeOfTicket;

    public Ticket(double idade, boolean primeiroAno) {

        isFirstYear = primeiroAno;
        age = idade;
    }

    public int getTypeOfTicket() {

        if (isFirstYear) {
            if (age <= LOWERAGEBOUND) {
                /* bilhete 0 e bilhete de criancas caloiras */
                typeOfTicket = 0;

            } else if ((age > LOWERAGEBOUND && age <= HIGHERAGEBOUND)) {
                /* bilhete tipo 1 e o bilhete para jovens caloiros */
                typeOfTicket = 1;
            } else if (age > HIGHERAGEBOUND) {
                typeOfTicket = 2;
            }
        } else {
            if (age <= LOWERAGEBOUND) {

                /* bilhete tipo 3 e o bilhete para criancas nao caloiras */
                typeOfTicket = 3;

            } else if ((age > LOWERAGEBOUND && age <= HIGHERAGEBOUND)) {
                /* bilhete tipo 4 e o bilhete para joves nao caloiros */
                typeOfTicket = 4;
            } else if (age > HIGHERAGEBOUND) {
                /* bilhete tipo 5 e o bilhete para idosos nao caloiros */
                typeOfTicket = 5;
            }
        }

        return typeOfTicket;
    }
    /*
     * public double GetPrice(){
     * 
     * if(this.getTypeOfTicket()==0){ ticketPrice=CRIANCA;
     * System.out.println("Criança caloira");
     * 
     * } else if(this.getTypeOfTicket()==1){ ticketPrice=FRESH;
     * 
     * System.out.println("Jovem caloiro"); } else if(this.getTypeOfTicket()==2){
     * ticketPrice=FRESH*SENIORDISC; System.out.println("idoso caloiro"); } else
     * if(this.getTypeOfTicket()==3){ ticketPrice=CRIANCA;
     * System.out.println("criança não caloira"); } else
     * if(this.getTypeOfTicket()==4){ ticketPrice=BASE;
     * System.out.println("Jovem não caloiro"); } else
     * if(this.getTypeOfTicket()==5){ ticketPrice=BASE*SENIORDISC;
     * System.out.println("idoso não caloiro"); } return ticketPrice;
     * 
     * }
     */

    public int getPriceWith(Ticket other) {

        if (this.getTypeOfTicket() == 0 && other.getTypeOfTicket() == 0) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 0 && other.getTypeOfTicket() == 1) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 0 && other.getTypeOfTicket() == 2) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 0 && other.getTypeOfTicket() == 3) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 0 && other.getTypeOfTicket() == 4) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 0 && other.getTypeOfTicket() == 5) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        /*fim das combinações de 0 com o resto*/
        else if (this.getTypeOfTicket() == 1 && other.getTypeOfTicket() == 0) {
            ticketPrice =(int) Math.round(FRESH);
        }
        else if (this.getTypeOfTicket() == 1 && other.getTypeOfTicket() == 1) {
            ticketPrice =(int) Math.round(FRESH);
        }
        else if (this.getTypeOfTicket() == 1 && other.getTypeOfTicket() == 2) {
            ticketPrice = (int) Math.round(FRESH * PROMODISC);
        }
        else if (this.getTypeOfTicket() == 1 && other.getTypeOfTicket() == 3) {
            ticketPrice =(int) Math.round(FRESH);
        }
        else if (this.getTypeOfTicket() == 1 && other.getTypeOfTicket() == 4) {
            ticketPrice =(int) Math.round(FRESH);
        }
        else if (this.getTypeOfTicket() == 1 && other.getTypeOfTicket() == 5) {
            ticketPrice =(int) Math.round(FRESH * PROMODISC);
        }
        /*fim das combinacoes de 1 com o resto*/
        else if (this.getTypeOfTicket() == 2 && other.getTypeOfTicket() == 0) {
            ticketPrice =(int) Math.round(FRESH * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 2 && other.getTypeOfTicket() == 1) {
            ticketPrice =(int) Math.round(FRESH * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 2 && other.getTypeOfTicket() == 2) {
            ticketPrice =(int) Math.round(FRESH * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 2 && other.getTypeOfTicket() == 3) {
            ticketPrice =(int) Math.round(FRESH * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 2 && other.getTypeOfTicket() == 4) {
            ticketPrice =(int) Math.round(FRESH * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 2 && other.getTypeOfTicket() == 5) {
            ticketPrice =(int) Math.round(FRESH * SENIORDISC);
        }
        /*fim das combinacoes de 2 com o resto*/
        else if (this.getTypeOfTicket() == 3 && other.getTypeOfTicket() == 0) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 3 && other.getTypeOfTicket() == 1) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 3 && other.getTypeOfTicket() == 2) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 3 && other.getTypeOfTicket() == 3) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 3 && other.getTypeOfTicket() == 4) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        else if (this.getTypeOfTicket() == 3 && other.getTypeOfTicket() == 5) {
            ticketPrice =(int) Math.round(CRIANCA);
        }
        /*fim das combinacoes de 3 com o resto*/
        else if (this.getTypeOfTicket() == 4 && other.getTypeOfTicket() == 0) {
            ticketPrice =(int) Math.round(BASE);
        }
        else if (this.getTypeOfTicket() == 4 && other.getTypeOfTicket() == 1) {
            ticketPrice =(int) Math.round(BASE);
        }
        else if (this.getTypeOfTicket() == 4 && other.getTypeOfTicket() == 2) {
            ticketPrice =(int) Math.round(BASE * PROMODISC);
        }
        else if (this.getTypeOfTicket() == 4 && other.getTypeOfTicket() == 3) {
            ticketPrice =(int) Math.round(BASE);
        }
        else if (this.getTypeOfTicket() == 4 && other.getTypeOfTicket() == 4) {
            ticketPrice =(int) Math.round(BASE);
        }
        else if (this.getTypeOfTicket() == 4 && other.getTypeOfTicket() == 5) {
            ticketPrice =(int) Math.round(BASE * PROMODISC);
        }
        /*fim das combinacoes de 4 com o resto*/
        else if (this.getTypeOfTicket() == 5 && other.getTypeOfTicket() == 0) {
            ticketPrice =(int) Math.round(BASE * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 5 && other.getTypeOfTicket() == 1) {
            ticketPrice =(int) Math.round(BASE * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 5 && other.getTypeOfTicket() == 2) {
            ticketPrice =(int) Math.round(BASE * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 5 && other.getTypeOfTicket() == 3) {
            ticketPrice =(int) Math.round(BASE * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 5 && other.getTypeOfTicket() == 4) {
            ticketPrice =(int) Math.round(BASE * SENIORDISC);
        }
        else if (this.getTypeOfTicket() == 5 && other.getTypeOfTicket() == 5) {
            ticketPrice =(int) Math.round(BASE * SENIORDISC);
        }
        /*fim das combinacoes de 5 com o resto*/

        return ticketPrice;

        /*Este tem de ser o codigo mais feio que eu escrevi na minha vida*/

    }

}