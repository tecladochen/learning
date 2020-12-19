package com.Tecladochen;

public class Calculator{
    public static void main(String[] args){
        if(args.length != 3) {
            System.out.println(
                    "Usage: java Calculator operand1 operator operand2"
            );
            System.exit(1);
        }
        if(!isNumberic(args[0])){
            System.out.println("Wrong Input: " + args[0]);
        }
        if(!isNumberic(args[2])){
            System.out.println("Wrong Input: " + args[2]);
        }
        if(!isNumberic(args[0]) || !isNumberic(args[2])){
            System.exit(0);
        }
        int result = 0;
        switch (args[1].charAt(0)){
            case '+': result = Integer.parseInt(args[0]) + Integer.parseInt(args[2]);
                break;
            case '-': result = Integer.parseInt(args[0]) - Integer.parseInt(args[2]);
                break;
            case '.': result = Integer.parseInt(args[0]) * Integer.parseInt(args[2]);
                break;
            case '/': result = Integer.parseInt(args[0]) / Integer.parseInt(args[2]);
                break;
        }
        System.out.println(args[0] + ' ' + args[1] + ' ' + args[2]
                + " = " + result );

    }
    public static boolean isNumberic(String str){
        for(int i = 0; i < str.length(); i++){
            if(!Character.isDigit(str.charAt(i))){
                return false;
            }
        }
        return true;
    }
}