// NOT FINISHED

import java.util.*;
import java.io.*;

public class BucketBrigade {

	static BufferedReader br;
	static PrintWriter pw;
	static {
		try {
			br = new BufferedReader(new FileReader("buckets.in"));
			pw = new PrintWriter(new FileWriter("buckets.out"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
//	static Scanner scan = new Scanner(System.in);
//	static PrintWriter pw = new PrintWriter(System.out);
	
	public static void main (String[] args) throws IOException {
		// Index 0 and 1 is x and y of the barn, 2 and 3 is x and y of the lake, 4 and 6 is x and y of the rock
		int[] coordinatesArray = new int[6];
		
		for (int i = 0; i < 10; i++) {
			String str = br.readLine();
			if (str.contains("B")) {
				coordinatesArray[0] = str.indexOf("B");
				coordinatesArray[1] = i;
			} else if (str.contains("L")) {
				coordinatesArray[2] = str.indexOf("L");
				coordinatesArray[3] = i;
			} else if (str.contains("R")) {
				coordinatesArray[4] = str.indexOf("R");
				coordinatesArray[5] = i;
			}
		}
		
		// If the x values or the y values of the barn and lake are the same, add 2 to the path
		int x = (Math.abs(coordinatesArray[0] - coordinatesArray[2])) + (Math.abs(coordinatesArray[1] - coordinatesArray[3])) - 1;
		if (coordinatesArray[0] == coordinatesArray[2] && coordinatesArray[0] == coordinatesArray[4] || coordinatesArray[1] == coordinatesArray[3] && coordinatesArray[1] == coordinatesArray[5]) {
			x += 2;
		}
		pw.print(x);
		pw.close();
	}
}
