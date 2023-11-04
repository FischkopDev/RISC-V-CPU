package de.home_skrobanek.risc;

import de.home_skrobanek.risc.file.FileHandler;
import de.home_skrobanek.risc.parser.Parser;

import java.io.File;

public class Compiler {

    private String content;

    public Compiler(String content){
        this.content = content;
    }

    public void compileToRAW(){
        FileHandler fl = new FileHandler(new File("showCase.op"));
        String executeableContent = "v2.0 raw\n";

        String[] line = content.split("\n");
        for(int i = 0; i < line.length; i++){
            if(line[i].contains(".asm")){

            }
            else{
                executeableContent += line[i] + " ";
            }
        }
        fl.write(executeableContent, false);
    }

    public static void main(String[]args){
        System.out.println("Compiler for RISC-V Assembly started");

       // Parser p = new Parser(new File("showCase.asm"));
        FileHandler fileHandler = new FileHandler(new File("showCase.asm"));

        Parser parser = new Parser(fileHandler);
        parser.parse();
    }
}
