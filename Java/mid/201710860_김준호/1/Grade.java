import java.util.Scanner;

public class Grade {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String grade;

        System.out.print("학점을 입력하세요: ");
        grade = cin.next();
        switch (grade) {
            case "A", "B", "C" : System.out.println("참 잘하였습니다."); break;
            case "D", "E"      : System.out.println("좀 더 노력하세요"); break;
            case "F"           : System.out.println("다음 학기에 다시 수강하세요."); break;
            default            : System.out.println("잘못된 입력입니다.");
        }

        cin.close();
    }    
}