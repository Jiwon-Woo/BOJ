import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = 0;
        int sum1 = 0;
        int sum2 = 0;
        
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        
        for (int i = 0; i < queue1.length; i++) {
            q1.add(queue1[i]);
            q2.add(queue2[i]);
            sum1 += queue1[i];
            sum2 += queue2[i];
        }
        
        if ((sum1 + sum2) % 2 == 1)
            return -1;
        
        int diff = sum1 - sum2;
        while (diff != 0 && (answer < queue1.length * 4)) {
            if (diff >  0) {
                sum1 -= q1.peek();
                sum2 += q1.peek();
                q2.add(q1.peek());
                q1.poll();
            } else {
                sum1 += q2.peek();
                sum2 -= q2.peek();
                q1.add(q2.peek());
                q2.poll();
            }
            diff = sum1 - sum2;
            answer++;
        }
        if (diff != 0)
            return -1;
        return answer;
    }
}