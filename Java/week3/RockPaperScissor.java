import java.util.*;

public class RockPaperScissor {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Random r = new Random();
        String[] RPS = {"바위", "보", "가위"};

        System.out.println("컴퓨터와 가위 바위 보 게임을 합니다.");
        while(true) {
            System.out.print("가위 바위 보!>> ");

            String my = cin.next();
            if(my.equals("그만")) break;

            // 0: Rock, 1: Paper, 2: Scissor
            int com = r.nextInt(3);

            // 내가 바위를 냈을 때
            if(my.equals("바위")) {
                if(RPS[com].equals("바위")) {
                    System.out.println("사용자 = "+my+", 컴퓨터 = 바위, 비겼습니다.");
                } else if(RPS[com].equals("가위")) {
                    System.out.println("사용자 = "+my+", 컴퓨터 = 가위, 이겼습니다.");
                } else {
                    System.out.println("사용자 = "+my+", 컴퓨터 = 보, 졌습니다.");
                }
            }
            else if(my.equals("보")) {
                if(RPS[com].equals("바위")) {
                    System.out.println("사용자 = "+my+", 컴퓨터 = 바위, 이겼습니다.");
                } else if(RPS[com].equals("가위")) {
                    System.out.println("사용자 = "+my+", 컴퓨터 = 가위, 졌습니다.");
                } else {
                    System.out.println("사용자 = "+my+", 컴퓨터 = 보, 비겼습니다.");
                }
            }
            else if(my.equals("가위")) {
                if(RPS[com].equals("바위")) {
                    System.out.println("사용자 = "+my+", 컴퓨터 = 바위, 졌습니다.");
                } else if(RPS[com].equals("가위")) {
                    System.out.println("사용자 = "+my+", 컴퓨터 = 가위, 비겼습니다.");
                } else {
                    System.out.println("사용자 = "+my+", 컴퓨터 = 보, 이겼습니다.");
                }
            }
            else {
                System.out.println("입력이 올바르지 않습니다.");
            }

        }
        cin.close();
    }
}