package com.Tecladochen;

import java.util.Random;
import java.util.Scanner;

public class OutofBounds {
    public static void main(String[] args) {
        Random random = new Random();
        Scanner input = new Scanner(System.in);
        int[] num = new int[100];
        for(int i = 0; i < 100; i++){
            num[i] = random.nextInt();
        }
        System.out.print("please enter a index (0-99): ");
        int index = input.nextInt();
        try {
            System.out.println("the value of the index is: " + num[index]);
        }catch (ArrayIndexOutOfBoundsException ex){
            System.out.println("Out of Bounds");
        }
    }
}
