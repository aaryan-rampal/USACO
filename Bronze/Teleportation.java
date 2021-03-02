import java.io.*;
import java.util.*;

public class Teleportation {

	static BufferedReader br;
	static PrintWriter pw;
	static StringTokenizer st;
	static {
		try {
			br = new BufferedReader(new FileReader("teleport.in"));
			pw = new PrintWriter(new FileWriter("teleport.out"));
			st = new StringTokenizer(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main (String[] args) {
		int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), x =
				Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
		int ABmax = Math.max(b, a), ABmin = Math.min(b, a);
		int XYmax = Math.max(x, y), XYmin = Math.min(x, y);
		
		pw.print(Math.min(Math.abs(ABmax - XYmax) + Math.abs(ABmin - XYmin), (ABmax - ABmin)));
		pw.close();
	}
	
}