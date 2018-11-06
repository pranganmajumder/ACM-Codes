import java.util.*;
import java.math.BigInteger;
public class Main {
    
    public static void main(String args[]){
        Scanner scanf=new Scanner(System.in);
        BigInteger A=BigInteger.valueOf(1);
        String[] factOf=new String[1002];
        for(int i=1;i<=1000;i++){
            BigInteger temp=BigInteger.valueOf(i);
            A=A.multiply(temp);
            factOf[i]=String.valueOf(A);
        }
        int n,len;
        Scanner line = new Scanner(System.in);
        while(line.hasNextLine()) {
            String t=line.nextLine();
            n=Integer.parseInt(t);
            System.out.printf("%d!\n",n);
            if(n!=0)System.out.println(factOf[n]);
            else System.out.println(1);
        }
    }
}