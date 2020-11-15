import java.util.*;

public class DicManager {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        
        System.out.println("한영 단어 프로그램 입니다.");
        while(true) {
            System.out.print("한글 단어? ");

            String word = cin.next();
            if(word.equals("그만")) break;

            if(Dictionary.kor2Eng(word) != "") 
                System.out.printf("%s은 %s\n", word, Dictionary.kor2Eng(word));
            else 
                System.out.printf("%s는 저의 사전에 없습니다.\n", word);
        }

        cin.close();
    }
}
