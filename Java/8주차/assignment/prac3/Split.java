import java.util.StringTokenizer;
import java.io.*;

public class Split {
    public static void main(String[] args) {
        InputStreamReader rd = new InputStreamReader(System.in);
        StringBuffer sb = new StringBuffer();
        StringTokenizer st;
        
        try {
            while(true) {
                int c = rd.read();

                // linux에서 ctrl + z 는 백그라운드 작업으로 들어감
                // z 는 122 return
                // 결과는 17번 코드를 활성화함으로 실행하였다.
                //if(c == 122) break;

                // ctrl + z 는 -1을 return
                if(c == -1) break;
                else sb.append((char)c);
            }
        }
        catch(IOException e) {
            System.out.println("입력 오류 발생");
        }

        st = new StringTokenizer(sb.toString(), " ");
        while(st.hasMoreTokens()) System.out.println(st.nextToken());
    }
}
