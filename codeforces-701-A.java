/*
https://codeforces.com/contest/701/problem/A
*/

import java.util.Scanner;

public class Task701A {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int nCards = input.nextInt();
		int[] sums = new int[nCards];
		for (int i = 0; i < nCards; i++) {
			int card = input.nextInt();
			sums[i] = card;
		}
		int sum = 0;
		for (int a = 0; a < sums.length; a++) {
			sum += sums[a];
		}
		int player = 2 * sum / nCards;
		for (int n = 1; n < nCards + 1; n++) {
			for (int k = n + 1; k < nCards + 1; k++) {
				if (sums[n - 1] + sums[k - 1] == player) {
					System.out.println(n + " " + k);
					sums[k - 1] = -1000000;
					break;
				}
			}
		}
	}

}
