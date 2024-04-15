import java.util.Scanner;

public class Main {
    static class Game {
        int left;
        int right;
        Game(){
            left = -1;
            right = -1;
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int k = s.nextInt();

        Game[] graph = new Game[n+1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new Game();
            graph[i].left = s.nextInt();
            graph[i].right = s.nextInt();
        }

        int[] visited = new int[32];
        int remain = n;
        int now = k;

        while (remain != 1){
            int next = -1;
            if(visited[now] == 0){
                next = graph[now].left;
            }else{
                remain--;
                next = graph[now].right;
            }
            visited[now]++;
            now = next;
        }

        int result = -1;
        for(int i=1;i<=n;i++){
            if(visited[i] != 2){
                result = i;
                break;
            }
        }
        System.out.println(result);
    }
}
