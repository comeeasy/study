import java.util.Scanner;

public class RockScissorPaper {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String RSP[] = new String[]{"", "가위", "바위", "보"};
        
        while(true) {
            System.out.println("1: 가위, 2: 바위, 3: 보 셋 중에 입력해주세요.");
            String playerRSP = cin.next();
            long computerRSP  = Math.round(1+Math.random()*2);

            if(playerRSP.equals("1")) {
                System.out.printf("플레이어: 가위, 컴퓨터: %s\t", RSP[(int)computerRSP]);
                switch((int)computerRSP) {
                    case 1: System.out.println("비겼습니다.");           break;
                    case 2: System.out.println("컴퓨터가 이겼습니다.");   break;      
                    case 3: System.out.println("플레이어가 이겼습니다."); break;
                }
            }
            else if(playerRSP.equals("2")) {
                System.out.printf("플레이어: 바위, 컴퓨터: %s\t", RSP[(int)computerRSP]);
                switch((int)computerRSP) {
                    case 1: System.out.println("플레이어가 이겼습니다."); break;
                    case 2: System.out.println("비겼습니다.");           break;      
                    case 3: System.out.println("컴퓨터가 이겼습니다.");   break;
                }
            }
            else if(playerRSP.equals("3")) {
                System.out.printf("플레이어: 보  , 컴퓨터: %s\t", RSP[(int)computerRSP]);
                switch((int)computerRSP) {
                    case 1: System.out.println("컴퓨터가 이겼습니다.");    break;
                    case 2: System.out.println("플레이어가 이겼습니다.");  break;      
                    case 3: System.out.println("비겼습니다.");            break;
                }
            }
            else {
                System.out.println("잘못된 입력입니다. 다시 입력하세요");
            }
        }
    }
}
