public class Mathematics {

    public static int FactorialIt(int n) {

        int result = 1;
        for (int i = 1; i <= n; i++) {

            result *= i;
        }
        return result;
    }

    public static int FactorialRec(int n) {

        if (n == 0) {
            return 1;
        }
        return n * FactorialRec(n - 1);
    }

    public static boolean isPrime(int n) {

        int i = 2;
        if (n > 1) {
            while (n % i != 0) {

                i++;

            }
        }
        return (i == n);
    }

    public static boolean isPerfectNumber(int n) {
        int i;
        int result = 0;

        for (i = 1; i < n; i++) {

            if (n % i == 0) {

                result += i;
            }
        }
        return (result == n);
    }

    public static int SumSquaresRec(int n) {

        if (n <= 1) {

            return 1;
        }
        return (int) Math.pow((double) n, 2) + SumSquaresRec(n - 1);
    }

    public static int SumSquaresIt(int n) {

        int result = 0;
        int i;
        for (i = 1; i <= n; i++) {

            result += Math.pow(i, 2);

        }
        return result;
    }

    public static void PerfectNumbersBefore(int n) {

        if (n < 1) {
            return;
        } else {
            for (int i = 1; i <= n; i++) {

                if (Mathematics.isPerfectNumber(i)) {

                    System.out.printf("%d\n", i);
                } else {

                }
            }
        }
    }

    public static void FirstNPerfectNumbers(int n) {
        for (int i = 1, j = 0; j < n; i++) {

            if (isPerfectNumber(i)) {

                System.out.printf("%d\n", i);
                j++;
            } else {
            }

        }
    }

    public static int CollatzIt(int n) {

        int steps = 0;
        if (n == 1) {
            return 1;
        } else {
            while (n != 1) {
                if (n % 2 == 0) {

                    n = (int) n / 2;
                    steps++;
                } else if (n % 2 != 0) {
                    n = (int) (3 * n + 1);
                    steps++;
                }
            }
            return steps;

        }

    }
}
