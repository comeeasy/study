public class Add {
    public static void main(String[] args) {
        int sum=0;
        for(int i=0; i<args.length; ++i) {
            try {
                sum += Integer.parseInt(args[i]);   
            }
            // 정수가 아닌 str이 인자로 들어가면 Exception이 
            // 발생하고 무시
            catch(NumberFormatException e) {continue;}
        }
        
        System.out.println(sum);
    }
}
