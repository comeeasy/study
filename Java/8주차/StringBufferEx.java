public class StringBufferEx {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("This");
        
        System.out.println(sb.hashCode());

        // 문자열 덧붙이기
        sb.append(" is pencil");
        System.out.println(sb);

        // 문자열  my 삽입
        sb.insert(7, " my");
        System.out.println(sb);

        // 문자열 "my"를 "your"로 대치
        sb.replace(8, 10, "your");
        System.out.println(sb);

        // 스트링 버퍼 내 문자열 길이 설정
        sb.setLength(5);

        System.out.println(sb);
        System.out.println(sb.hashCode());
    }
}
