/*
Had to look at the solution for this one
*/

import java.io.*;
import java.util.*;

public class PromotionCounting {
	
	static Scanner scan;
	static PrintWriter pw;
	
	static {
		try {
			scan = new Scanner(new File("promote.in"));
			pw = new PrintWriter("promote.out");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public static void main (String[] args) {
		int[] beforeAndAfter = getInput();
		findPromotions(beforeAndAfter);
	}
	
	private static int[] getInput () {
//		Scanner scan = new Scanner(System.in);
		int[] beforeAndAfter = new int[8];
		int index = 0;
		
		for (int i = 0; i < 4; i++) {
			String str = scan.nextLine();
			String[] strArray = str.split(" ");
			beforeAndAfter[index] = Integer.parseInt(strArray[0]);
			beforeAndAfter[index + 1] = Integer.parseInt(strArray[1]);
			index += 2;
		}
		
		return beforeAndAfter;
	}
	
	private static void findPromotions (int[] beforeAndAfter) {
		int bronzeToSilver = 0, silverToGold = 0, goldToPlatinum = 0;
		
		goldToPlatinum += beforeAndAfter[7]-beforeAndAfter[6];
		silverToGold += beforeAndAfter[7]-beforeAndAfter[6]+beforeAndAfter[5]-beforeAndAfter[4];
		bronzeToSilver += beforeAndAfter[7]-beforeAndAfter[6]+beforeAndAfter[5]-beforeAndAfter[4]+beforeAndAfter[3]-beforeAndAfter[2];
		
		for (int i : new int[] {bronzeToSilver, silverToGold, goldToPlatinum}) {
			pw.println(i);
		}
		pw.close();
//		System.out.println(bronzeToSilver + " " + silverToGold + " " + goldToPlatinum);
	}
	
}
