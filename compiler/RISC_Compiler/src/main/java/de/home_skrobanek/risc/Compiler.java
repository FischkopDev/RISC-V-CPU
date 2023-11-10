package de.home_skrobanek.risc;

import de.home_skrobanek.risc.file.FileHandler;
import de.home_skrobanek.risc.parser.Parser;

import java.io.File;
import java.util.HashMap;

/*
    This class compiles the bin formatted file into the runnable
    RAW file.
 */
public class Compiler {

    private String content;
    private HashMap<String, String> routines;
    private int programCounter = 0;

    public Compiler(String content){
        this.content = content;

        routines = new HashMap<>();
    }

    public void compileToRAW(){
        FileHandler fl = new FileHandler(new File("showCase.op"));
        String executeableContent = "v2.0 raw\n";

        System.out.println("Compiling routines");
        System.out.println();
        String[] line = content.split("\n");
        for(int i = 0; i < line.length; i++){
            if(!line[i].contains(".asm")) {
                if (lineIsRoutine(line[i]) && !line[i].contains("10")) {
                    System.out.println("Address: " +Integer.toHexString(programCounter+1) + " "+ line[i]);
                    routines.put(line[i], Integer.toHexString(programCounter+1));
                }
                programCounter++;
            }
        }
        System.out.println();

        programCounter = 0;

        System.out.println("Compiling executable code");
        for(int i = 0; i < line.length; i++){
            if(!line[i].contains(".asm")){
                if(line[i].startsWith("_")){
                    executeableContent += "0 ";
                }
                else if(line[i].startsWith("10")){
                    executeableContent += "10"+ refillWithDigits(routines.get(line[i].split("10")[1]+":")) + " ";
                }
                else
                    executeableContent += line[i] + " ";
                programCounter++;

            }
        }

        System.out.println(executeableContent);
        fl.write(executeableContent, false);
    }

    private boolean lineIsRoutine(String line){
        return line.contains("_") && line.contains(":");
    }

    private String refillWithDigits(String line){
        if(line.length() == 1){
            line = "00000"+line;
        }
        else if(line.length() == 2){
            line = "0000"+line;
        }
        else if(line.length() == 3){
            line = "000" + line;
        }
        else if(line.length() == 4){
            line = "00" +line;
        }
        else if(line.length() == 5){
            line = "0" + line;
        }

        return line;
    }

    public static void main(String[]args){
        System.out.println("Compiler for RISC-V Assembly started");

       // Parser p = new Parser(new File("showCase.asm"));
        FileHandler fileHandler = new FileHandler(new File("showCase.asm"));

        Parser parser = new Parser(fileHandler);
        Compiler com = new Compiler(parser.parse());
        com.compileToRAW();
    }
}
