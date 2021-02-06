import java.util.*;

public class DoYouKnowYourABCs {
	
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		String str = scan.nextLine();
		String[] array = str.split(" ");
		int[] numArray = new int [array.length];
		
		int smallestNum = 0, secondSmallestNum = 1000000001, maximumNum = 0;
		for (int i = 0; i < array.length; i++) {
			numArray[i] = Integer.parseInt(array[i]);
		}
		
		Arrays.sort(numArray);
		
		int x = numArray[numArray.length-1]-numArray[0]-numArray[1];
		System.out.println(numArray[0] + " " + numArray[1] + " " + x);
	}
}