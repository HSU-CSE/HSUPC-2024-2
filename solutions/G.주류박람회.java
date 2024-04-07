import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

class Dif implements Comparable<Dif> {
	int idx, dif;

	public Dif(int idx, int dif) {
		this.idx = idx;
		this.dif = dif;
	}

	@Override
	public int compareTo(Dif o) {
		return this.dif - o.dif;
	}
}

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()); // 사야하는 술 종류 수
		int P = Integer.parseInt(st.nextToken()); // 상상이가 구매하는 술 개수
		int Q = Integer.parseInt(st.nextToken()); // 부기가 구매하는 술 개수

		int[] costA = new int[N];
		int[] costB = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			costA[i] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			costB[i] = Integer.parseInt(st.nextToken());
		}

		ArrayList<Dif> difList = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			int dif = costA[i] - costB[i];
			difList.add(new Dif(i, dif));
		}

		Collections.sort(difList);
		long answer = 0;
		for (int i = 0; i < N; i++) {
			if (i < P) {
				answer += costA[difList.get(i).idx];
			} else {
				answer += costB[difList.get(i).idx];
			}
		}
		System.out.println(answer);
	}
}
