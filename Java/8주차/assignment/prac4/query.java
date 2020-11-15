import java.util.StringTokenizer;

public class query {
    public static void main(String[] args) {
        String str = args[0];
        StringTokenizer st = new StringTokenizer(str, "&");
        while(st.hasMoreTokens()) {
            StringTokenizer st2 = new StringTokenizer(st.nextToken(), "=");
            System.out.print(st2.nextToken()+"\t");
            System.out.println(st2.nextToken());
        }
    }
}
