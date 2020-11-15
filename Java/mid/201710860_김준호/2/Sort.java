import java.util.*;

public class Sort {
    public static void main(String[] args) {
        int[] numbers = new int[args.length];
        int leng = args.length;

        for(int i=0; i<leng; ++i) numbers[i] = Integer.parseInt(args[i]);
        Arrays.sort(numbers);
        for(int i=0; i<leng / 2; ++i) {
            int tmp = numbers[i];
            numbers[i] = numbers[leng-1 - i];
            numbers[leng-1 - i] = tmp; 
        }
        
        System.out.print("정렬결과는 다음과 같습니다.:");
        for (int i : numbers) System.out.printf(" %d", i);
        System.out.println();
    }   
}