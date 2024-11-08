import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.close();

        int n = 1;
        int m = 1;

        while (n * m < N) {
            if (n > m) {
                m++;
            } else {
                n++;
            }
        }

        System.out.println(n + m);
    }
}
