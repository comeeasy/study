public class StringEx {
    public static void main(String[] args) {
        String a = new String(" abcd");
        String b = new String(",efg");

        String c = a.concat(b);
        System.out.println(c);

        String d = c.trim();
        System.out.println(d);

        String e = d.replace("ab", "12");
        System.out.println(e);

        String f[] = e.split(",");
        for(int i=0; i<f.length; i++) {
            System.out.printf("분리된 %d번 문자열: %s\n", i, f[i]);
        }

        String g = d.substring(3);
        System.out.println(g);

        char h = d.charAt(2);
        System.out.println(h);
    }
}
