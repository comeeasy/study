import java.util.*;

public class ArrayListEx {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        ArrayList<String> list = new ArrayList<String>();


        for (int i = 0; i < 4; i++) {
            System.out.print("이름을 입력하세요: ");
            list.add(cin.next());
        }

        int idx = 0;
        int max = 0;
        for (int i = 0; i < list.size(); i++) {
            String name = list.get(i);

            if(name.length() > max) {
                max = name.length();
                idx = i;
            }

            System.out.println(name+" ");
        }
        System.out.println();
        System.out.println("가장 긴 이름은: "+list.get(idx));

        cin.close();
    }
}
