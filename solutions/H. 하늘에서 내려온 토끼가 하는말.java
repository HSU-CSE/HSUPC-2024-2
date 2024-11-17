import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Point {
    int y, x;

    public Point(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

public class Main {
    private static int[][] map;
    private static boolean[][] visited;
    private static int[] dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};
    private static int N, M;
    private static Queue<Point> waterQ = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        visited = new boolean[N][M];

        Point rabbit = null, carrot = null;

        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            for (int j = 0; j < M; j++) {
                if (input.charAt(j) == '*') {
                    map[i][j] = -1;
                }
                if (input.charAt(j) == 'B') {
                    rabbit = new Point(i, j);
                }
                if (input.charAt(j) == 'C') {
                    carrot = new Point(i, j);
                }
            }
        }

        initWaterQueue();

        int result = main.solve(rabbit, carrot);

        if (result != -1) {
            System.out.println(result);
        } else {
            System.out.println("Umchichi..Umchichi..");
        }
    }

    private int solve(Point rabbit, Point carrot) {
        Queue<Point> rabbitQueue = new LinkedList<>();
        rabbitQueue.offer(rabbit);
        int L = -1;
        while (!rabbitQueue.isEmpty()) {
            L++;
            fillWater();
            int len = rabbitQueue.size();
            for (int i = 0; i < len; i++) {
                Point curRabbit = rabbitQueue.poll();
                if (carrot.y == curRabbit.y && carrot.x == curRabbit.x) {
                    return L;
                }

                for (int j = 0; j < 4; j++) {
                    int ny = curRabbit.y + dy[j];
                    int nx = curRabbit.x + dx[j];
                    if (validateBound(ny, nx) && map[ny][nx] == 0 && !visited[ny][nx]) {
                        rabbitQueue.add(new Point(ny, nx));
                        visited[ny][nx] = true;
                    }
                }
            }
        }
        return -1;
    }

    public static void initWaterQueue() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == -1) {
                    waterQ.add(new Point(i, j));
                }
            }
        }
    }

    private boolean validateBound(int ny, int nx){
        return (ny >= 0 && ny < N && nx >= 0 && nx < M);
    }
    private void fillWater() {
        int len = waterQ.size();
        for (int j = 0; j < len; j++) {
            Point cur = waterQ.poll();
            for (int i = 0; i < 4; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (validateBound(ny, nx) && map[ny][nx] == 0) {
                    map[ny][nx] = -1;
                    waterQ.offer(new Point(ny, nx));
                }
            }
        }
    }
}


