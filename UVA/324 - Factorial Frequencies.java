import java.util.*;
import java.math.BigInteger;
public class Main {
	
	
	public static void main(String args[]){
        Scanner scanf=new Scanner(System.in);
    	BigInteger A=BigInteger.valueOf(1);
    	String[] factOf=new String[367];
    	for(int i=1;i<=366;i++){
    		BigInteger temp=BigInteger.valueOf(i);
    		A=A.multiply(temp);
    		factOf[i]=String.valueOf(A);
    	}
    	int n,len;
    	Scanner line = new Scanner(System.in);
    	while(line.hasNextLine()) {
    		String t=line.nextLine();
    		n=Integer.parseInt(t);
    		if(n==0)break;
	        len=factOf[n].length();
	        int[] freq = new int[10];
	        Arrays.fill(freq,0);
	        for(int i=0;i<len;i++) {
	        	int index=Integer.parseInt(String.valueOf(factOf[n].charAt(i)));
	        	freq[index]++;
	        }

	        //output section//
	        System.out.printf("%d! --\n",n);
	        for(int i=0;i<=9;i++) {
	        	if(i==0||i==5)System.out.print("   ");
	        	System.out.print("("+i+")"+"    ");
	        	System.out.print(freq[i]);
	        	if(i==4||i==9)System.out.print("\n");
	        	else System.out.print("    ");
	        }
    	}
    }
}