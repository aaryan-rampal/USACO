/*
I had to look up the answer for this one however I was pretty close. I had almost all of the code but I couldn't figure out
how to go from bucket 3 to bucket 1. I first tried to set up an array of 100 integers which goes from 1 to 2 to 3 back to 1
and repeats (way too complicating). Then, I tried to find ways to forcibly overflow integers but didn't find any. I had the
mod 3 idea too but I used it to do some calculation with the array, I didn't realize I didn't need the array at all with mod 3.
*/

import java.io.*;

public class MixingMilk {
	static StreamTokenizer st; static PrintWriter pw;
	static {
		try {
			pw = new PrintWriter(new FileWriter("mixmilk.out"));
			st = new StreamTokenizer(new BufferedReader(new FileReader("mixmilk.in")));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	static int nextInt() throws IOException {
		st.nextToken();
		return (int)st.nval;
	}
	
	public static void main (String[] args) throws IOException {
		// c1, m1, c2, m2, c3, m3
		int[] capacity = new int[3]; int[] milk = new int[3];
		for (int i = 0; i < 3; i++) {
			capacity[i] = nextInt(); milk[i] = nextInt();
		}
		
		// How to have an int that oscillates between 1,2,3?
		for (int i = 0; i < 100; i++) {
			int temp = capacity[(i+1)%3] - milk[(i+1)%3];
			if (temp < milk[i%3]) {
				milk[i%3] -= temp;
				milk[(i+1)%3] += temp;
			} else {
				milk[(i+1)%3] += milk[i%3];
				milk[i%3] = 0;
			}
		}
		
		pw.println(milk[0]);
		pw.println(milk[1]);
		pw.println(milk[2]);
		pw.close();
	}
	
}
