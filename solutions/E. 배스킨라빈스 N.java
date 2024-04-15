import java.util.Scanner;

public class Main {
    public static boolean solve1(int n) {
        boolean[] dp = new boolean[n + 1];
        dp[1] = true;
        for (int i = 5; i <= n; i++) {
            dp[i] = !dp[i - 1];
            if (dp[i - 2]) dp[i] = false;
            if (dp[i - 3]) dp[i] = false;
        }
        return !dp[n];
    }
    public static boolean solve2(int n){
        return n%4 != 1;
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        String result="";
        if(solve2(n)) {
            result = "WIN";
        }else{
            result = "LOSE";
        }
        System.out.println(result);
    }
}
