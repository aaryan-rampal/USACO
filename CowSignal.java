/*
Had to look at the tutorial again. I went way too complex (again). I tried to make
arrays that store the character and the number of times it repeats and then
make a for loop to print out that character K more times and then surround that
with a for loop that repeats K times.

Hmm, it StreamTokenizer is giving me a null string when the input starts with a period
like ".X.X.X.X.X..XXX.."

Use String Tokenizer.
 */

import java.io.*;
import java.util.*;

public class CowSignal {
	
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
		PrintWriter pw;
		public FastReader () throws IOException {
			br = new BufferedReader(new FileReader("cowsignal.in"));
			pw = new PrintWriter(new FileWriter("cowsignal.out"));
		}
		String next () {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt () {
			return Integer.parseInt(next());
		}
	}

	public static void main (String[] args) throws IOException {
		FastReader s = new FastReader();
		int M = s.nextInt();
		int N = s.nextInt();
		int K = s.nextInt();

		for (int i = 0; i < M; i++) {
			String str = s.next();

			// Prints out the sequence on K lines to expand vertically
			for (int g = 0; g < K; g++) {
				for (int j = 0; j < N; j++) {
					for (int m = 0; m < K; m++) {
						s.pw.print(str.charAt(j));
					}
				}
				s.pw.println();
			}
		}
		s.pw.close();
	}

}
