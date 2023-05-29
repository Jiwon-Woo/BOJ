import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[] step, dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        step = new int[N + 1];
        dp = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            step[i] = Integer.parseInt(st.nextToken());
        }

        dp[1] = step[1];
        if (N == 1) {
            System.out.println(dp[1]);
            return;
        }
        dp[2] = step[1] + step[2];
        if (N == 2) {
            System.out.println(dp[2]);
            return;
        }
        dp[3] = Math.max(step[2] + step[3], step[1] + step[3]);
        for (int i = 4; i <= N; i++) {
            dp[i] = Math.max(dp[i - 2], dp[i - 3] + step[i - 1]) + step[i];
        }
        System.out.println(dp[N]);
    }
}
