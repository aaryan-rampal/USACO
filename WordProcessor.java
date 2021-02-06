/*
I don't know what is wrong with this code. The sample input is:

10 7
hello my name is Bessie and this is my essay

and the sample output is:

hello my
name is
Bessie
and this
is my
essay

However, "Bessie and" can fit on the same line. Bessie is 6 character while and is 3. 6+3=9<10. Even if spaces counted
(which they don't), it would still be equal to 10 and not over the character limit. I legit don't know what's going on.
 */

import java.io.*;
import java.util.*;

public class WordProcessor {
	
	public static void main (String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		int[] KAndN = inputNAndK(scan);
		int N = KAndN[0], K = KAndN[1];
		
		String textInput = scan.nextLine();
		String[] textInputWords = textInput.split(" ");
		insertNewLines(textInputWords, N);
	}
	
	public static int[] inputNAndK (Scanner scan) {
		String str = scan.nextLine();
		String[] strArray = str.split(" ");
		return new int[] {Integer.parseInt(strArray[0]), Integer.parseInt(strArray[1])};
	}
	
	public static void insertNewLines (String[] textInputWords, int N) throws FileNotFoundException {
		int index = 0;
		int charLimit = 0;
		
		do {
			// The '+ 1' is there for the space between words
			if (charLimit + textInputWords[index].length() < N || charLimit == 0) {
				// I don't want a space if it's the very first word on the line
				if (charLimit == 0) {
					System.out.print(textInputWords[index]);
				} else {
					System.out.print(" " + textInputWords[index]);
				}
				charLimit += textInputWords[index].length();
				index++;
			} else {
				System.out.println("");
				charLimit = 0;
			}
		} while(index != N);
	}
	
}
