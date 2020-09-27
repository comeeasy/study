public class MainParameter {
    public static void main(String[] args) {
        double sum = 0.0;
        
        for(String num: args) sum += Double.parseDouble(num);
        double avg = sum / args.length;

        System.out.println("합계 :"+sum);
        System.out.println("평균 :"+avg);
    }
}
