import java.util.*;

public class Pair {
    public static void main(String[] args) {
        String course[] = {"java", "C++", "HTML5", "컴퓨터구조", "안드로이드"};
        int score[]     = { 95, 88, 76, 62, 55};
        Scanner cin = new Scanner(System.in);

        while(true) { 
            String sub = cin.next();
            if (sub.equals("그만")) break;

            // search
            int idx = -1;
            for(int i=0; i<5; ++i) {

                if(sub.equals(course[i])) {
                    idx = i;
                    break;
                }
            }

            // 없다면 다시 돌아감
            if(idx == -1) {
                System.out.println("없는 과목입니다.");
                continue;
            }
            System.out.println(course[idx]+"의 점수는 "+score[idx]);
        } 

        cin.close();
    }
}