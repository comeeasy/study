public class Average {
    public static void main(String[] args) {
        int sum = 0;
        for(String num: args) sum += Integer.parseInt(num);
        System.out.println((double)sum / 3);
    }
}
