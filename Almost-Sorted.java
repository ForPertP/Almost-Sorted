import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {
    
    private static void swap(List<Integer> list, int i, int j) {
        int temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    }    

    private static void reverse(List<Integer> list, int start, int end) {
        while (start < end) {
            swap(list, start, end);
            start++;
            end--;
        }
    }
    
    public static void almostSorted(List<Integer> arr) {
        int n = arr.size();
        List<Integer> sortedArr = new ArrayList<>(arr);
        Collections.sort(sortedArr);

        if (arr.equals(sortedArr)) {
            System.out.println("yes");
            return;
        }

        int l = 0, r = n - 1;
        while (l < n && arr.get(l).equals(sortedArr.get(l))) l++;
        while (r > l && arr.get(r).equals(sortedArr.get(r))) r--;

        swap(arr, l, r);
        if (arr.equals(sortedArr)) {
            System.out.println("yes");
            System.out.println("swap " + (l + 1) + " " + (r + 1));
            return;
        }

        swap(arr, l, r);
        reverse(arr, l, r);
        if (arr.equals(sortedArr)) {
            System.out.println("yes");
            System.out.println("reverse " + (l + 1) + " " + (r + 1));
            return;
        }

        System.out.println("no");
    }
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        Result.almostSorted(arr);

        bufferedReader.close();
    }
}
