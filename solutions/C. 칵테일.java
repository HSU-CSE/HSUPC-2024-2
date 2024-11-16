import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int K = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}

		boolean found = false;

		for (int mask = 1; mask < (1 << N); mask++) {
			int sum = 0;
			int count = 0;

			for (int j = 0; j < N; j++) {
				if( (mask & (1 << j)) != 0 ) {
					sum += A[j];
					count++;
				}
			}

			double raw = (double)sum / count;
			int avg = (int)Math.floor(raw + 0.5);

			if (avg == K) {
				found = true;
				break;
			}
		}

		if (found) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}
}
