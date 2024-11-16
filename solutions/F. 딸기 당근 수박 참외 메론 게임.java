package org.example;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int N;
    static char[] selected;
    static char[] fruits = {'C', 'K', 'M', 'S', 'W'};

    // 과일 선택 하기
    static void dfs(int i) {
        // N개의 과일을 골랐다면 게임 종료
        if (i == N) {
            System.out.println(String.join(" ", new String(selected).split("")));
            return;
        }
        // 아직 N개의 과일을 다 고르지 못했다면 재귀적으로 선택
        for (char currFruit : fruits) {
            if (i == 0 || selected[i - 1] != currFruit) { // 이전에 고른 과일은 선택할 수 없음
                selected[i] = currFruit;
                dfs(i + 1);
                selected[i] = 'N'; // 백트래킹
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        selected = new char[N];
        Arrays.fill(selected, 'N'); // 선택되지 않은 상태를 'N'으로 초기화
        dfs(0);
    }
}
