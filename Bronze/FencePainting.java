import java.io.*;
import java.util.*;

public class FencePainting {
	
	static BufferedReader br;
	static PrintWriter pw;
	static StringTokenizer st;
	static {
		try {
			br = new BufferedReader(new FileReader("paint.in"));
			pw = new PrintWriter(new FileWriter("paint.out"));
			st = new StringTokenizer(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main (String[] args) throws IOException {
		int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int x =	Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
		int min = Math.min(a, x), max = Math.max(b, y);
		int minMax = Math.max(a, x), maxMin = Math.min(b, y);
		
		if (y < a || x > b) {
			pw.print((b-a)+(y-x));
		} else {
			pw.print(max-min);
		}
		pw.close();
	}
	
}
