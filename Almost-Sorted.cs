using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{
    static void Swap<T>(List<T> list, int i, int j)
    {
        T temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }    

    public static void almostSorted(List<int> arr)
    {
        int n = arr.Count;
        List<int> sortedArr = new List<int>(arr);
        sortedArr.Sort();

        if (arr.SequenceEqual(sortedArr))
        {
            Console.WriteLine("yes");
            return;
        }

        int l = 0, r = n - 1;
        while (l < n && arr[l] == sortedArr[l]) l++;
        while (r > l && arr[r] == sortedArr[r]) r--;

        Swap(arr, l, r);
        if (arr.SequenceEqual(sortedArr))
        {
            Console.WriteLine("yes");
            Console.WriteLine($"swap {l + 1} {r + 1}");
            return;
        }

        Swap(arr, l, r);
        arr.Reverse(l, r - l + 1);
        if (arr.SequenceEqual(sortedArr))
        {
            Console.WriteLine("yes");
            Console.WriteLine($"reverse {l + 1} {r + 1}");
            return;
        }

        Console.WriteLine("no");
    }
}


class Solution
{
    public static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

        Result.almostSorted(arr);
    }
}
