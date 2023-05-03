import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        
        ArrayList<Integer> lottoList = new ArrayList<>();
        ArrayList<Integer> winList = new ArrayList<>();
        for (int i = 0; i < 6; i++) {
            lottoList.add(lottos[i]);
            winList.add(win_nums[i]);
        }
        int count = 0;
        int zero = 0;
        for (int i = 0; i < 6; i++) {
            if (lottoList.get(i) == 0) {
                zero++;
            } else if (winList.contains(lottoList.get(i))) {
                count++;
            }
        }
        int upper = 7 - (count + zero);
        int lower = 7 - count;
        
        upper = upper > 6 ? 6 : upper;
        lower = lower > 6 ? 6 : lower;
        
        int[] answer = {upper, lower};
        
        return answer;
    }
}