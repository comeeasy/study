public class ArrayUtility {
    static int[] concat(int[] s1, int[] s2) {
        int[] newArr = new int[s1.length + s2.length];

        for(int i=0; i<s1.length; ++i) newArr[i] = s1[i];
        for(int i=0; i<s2.length; ++i) newArr[s1.length + i] = s2[i];

        return newArr;
    }   
    
    static int[] remove(int[] s1, int[] s2) {
        boolean[] rmIdx = new boolean[s1.length];
        for(int i=0; i<s1.length; ++i) rmIdx[i] = false;

        for(int rm : s2) {
            for(int i=0; i<s1.length; ++i) 
                if(s1[i] == rm) rmIdx[i] = true;
        }

        int cnt = 0;
        for(int i=0; i<s1.length; ++i) if(!rmIdx[i]) ++cnt;
        
        int[] newArr = new int[cnt];
        int idx = 0;
        for(int i=0; i<s1.length; ++i) {
            if(!rmIdx[i]) newArr[idx++] = s1[i];   
        }

        return newArr;
    }
}