import java.io.*;

public class ShellGame {
	
	static StreamTokenizer st;
	static int nextInt () throws IOException {
		st.nextToken();
		return (int) st.nval;
	}
	
	public static void main (String[] args) throws Exception {
		st = new StreamTokenizer(new BufferedReader(new FileReader(
				"shell.in")));
		PrintWriter pw = new PrintWriter(new FileWriter("shell.out"));
		
			int N = nextInt();
			int[] shells = {1,2,3};
			int a, b, g;
			int counterone, countertwo, counterthree; counterone =
				countertwo = counterthree = 0;
			for (int i = 0; i < N; i++) {
				a = nextInt(); b = nextInt(); g = nextInt();
				int temp = shells[a-1];
				shells[a-1] = shells[b-1];
				shells[b-1] = temp;

				switch(shells[g-1]){
					case 1:
						counterone++;
						break;
					case 2:
						countertwo++;
						break;
					default:
						counterthree++;
						break;
				}
			}
			pw.println(Math.max(counterone, Math.max(countertwo,
				counterthree)));
			pw.close();
	}
	
}