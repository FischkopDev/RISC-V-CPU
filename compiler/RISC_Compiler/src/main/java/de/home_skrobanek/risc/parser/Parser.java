package de.home_skrobanek.risc.parser;

import de.home_skrobanek.risc.file.FileHandler;

import java.io.File;

public class Parser {

    FileHandler handler;

    public Parser(FileHandler handler) {
        this.handler = handler;
    }

    public void parse(){
        String content = handler.read();

        //remove comments
        content = handler.removeSubstringBetween(content, ";", "\n");//remove all comments
        content = handler.replace(";","",content);//remove the ; symbol
        content = handler.removeEmptyLines(content);//Remove all empty lines

        //replace instruction
        for(Instruction in : Instruction.values()){
            content = handler.replace(in.toString() + " ", in.getValue() + " ", content);
        }

        //replace register
        for(int x = 0; x < 9; x++){
            content = handler.replace("x"+x ,  "0"+x, content);
        }
        for(Register in : Register.values()){
            content = handler.replace(in.toString().toLowerCase() , in.getValue(), content);
        }

        //replace imidiate values
        content = handler.replace("#","",content);

        //replace routines
        content = replaceRoutines(content);
        content = handler.replace(" ", "", content);
        content = handler.replace(",", "", content);
        content = handler.replace("use", "", content);

        handler.write(content, false, new File("showCase1.bin"));
    }

    private String replaceRoutines(String content){

        return content;
    }
}
