package com.Tecladochen;

import java.util.InputMismatchException;
import java.util.Scanner;

public class InputTwoNumbers {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("please enter two numbers: ");
        try {
            int x = input.nextInt();
            int y = input.nextInt();
            int z = x + y;
            System.out.println(x + " + " + y + " = " + z);
        }catch (InputMismatchException ex){
            System.out.println("please enter again!");
        }
    }
}
